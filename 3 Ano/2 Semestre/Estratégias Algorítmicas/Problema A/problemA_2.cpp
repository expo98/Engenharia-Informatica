#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Constants for directions: Up, Right, Down, Left
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

// Function to check if a position is valid
bool isValid(int r, int c, int rows, int cols) {
    return r >= 0 && r < rows && c >= 0 && c < cols;
}

// Recursive backtracking function to solve the problem
bool solvePiltover(
    vector<vector<char>>& grid, 
    int rows, int cols,
    vector<vector<bool>>& hasTurret,
    vector<vector<int>>& coverage,
    int r, int c,
    int& turretCount,
    int& minTurrets
) {
    // Base case: If we've processed all cells
    if (r >= rows) {
        // Check if all empty cells are covered
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '.' && coverage[i][j] == 0) {
                    return false; // An empty cell is not covered
                }
            }
        }
        
        // Check if all outposts have exactly their required turrets
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] >= '0' && grid[i][j] <= '4') {
                    int requirement = grid[i][j] - '0';
                    int adjacentTurrets = 0;
                    
                    // Count adjacent turrets
                    for (int dir = 0; dir < 4; dir++) {
                        int nr = i + dx[dir];
                        int nc = j + dy[dir];
                        
                        if (isValid(nr, nc, rows, cols) && hasTurret[nr][nc]) {
                            adjacentTurrets++;
                        }
                    }
                    
                    if (adjacentTurrets != requirement) {
                        return false; // Outpost requirement not met
                    }
                }
            }
        }
        
        // Update the minimum turret count
        minTurrets = min(minTurrets, turretCount);
        return true;
    }
    
    // Move to the next cell
    int nextR = r;
    int nextC = c + 1;
    if (nextC >= cols) {
        nextR++;
        nextC = 0;
    }
    
    // Skip if the current cell is not empty
    if (grid[r][c] != '.') {
        return solvePiltover(grid, rows, cols, hasTurret, coverage, nextR, nextC, turretCount, minTurrets);
    }
    
    // Prune if we already have more turrets than the best solution
    if (turretCount >= minTurrets) {
        return false;
    }
    
    // Option 1: Don't place a turret here
    bool foundSolution = solvePiltover(grid, rows, cols, hasTurret, coverage, nextR, nextC, turretCount, minTurrets);
    
    // Option 2: Try to place a turret here
    // First check if it's valid to place a turret
    bool canPlace = true;
    
    // Check if we can see another turret in any direction
    for (int dir = 0; dir < 4; dir++) {
        int nr = r + dx[dir];
        int nc = c + dy[dir];
        
        while (isValid(nr, nc, rows, cols)) {
            if (hasTurret[nr][nc]) {
                canPlace = false;
                break;
            }
            
            // Stop at walls and outposts
            if (grid[nr][nc] == '#' || (grid[nr][nc] >= '0' && grid[nr][nc] <= '4')) {
                break;
            }
            
            nr += dx[dir];
            nc += dy[dir];
        }
        
        if (!canPlace) break;
    }
    
    if (canPlace) {
        // Place the turret
        hasTurret[r][c] = true;
        turretCount++;
        
        // Update coverage
        coverage[r][c]++;
        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dx[dir];
            int nc = c + dy[dir];
            
            while (isValid(nr, nc, rows, cols)) {
                coverage[nr][nc]++;
                
                // Stop at walls and outposts
                if (grid[nr][nc] == '#' || (grid[nr][nc] >= '0' && grid[nr][nc] <= '4')) {
                    break;
                }
                
                nr += dx[dir];
                nc += dy[dir];
            }
        }
        
        // Continue solving
        if (solvePiltover(grid, rows, cols, hasTurret, coverage, nextR, nextC, turretCount, minTurrets)) {
            foundSolution = true;
        }
        
        // Backtrack - remove the turret
        hasTurret[r][c] = false;
        turretCount--;
        
        // Update coverage
        coverage[r][c]--;
        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dx[dir];
            int nc = c + dy[dir];
            
            while (isValid(nr, nc, rows, cols)) {
                coverage[nr][nc]--;
                
                // Stop at walls and outposts
                if (grid[nr][nc] == '#' || (grid[nr][nc] >= '0' && grid[nr][nc] <= '4')) {
                    break;
                }
                
                nr += dx[dir];
                nc += dy[dir];
            }
        }
    }
    
    return foundSolution;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int R, C;
        cin >> R >> C;
        
        vector<vector<char>> grid(R, vector<char>(C));
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                cin >> grid[r][c];
            }
        }
        
        vector<vector<bool>> hasTurret(R, vector<bool>(C, false));
        vector<vector<int>> coverage(R, vector<int>(C, 0));
        
        int turretCount = 0;
        int minTurrets = INT_MAX;
        
        bool hasSolution = solvePiltover(grid, R, C, hasTurret, coverage, 0, 0, turretCount, minTurrets);
        
        if (hasSolution) {
            cout << minTurrets << endl;
        } else {
            cout << "noxus will rise!" << endl;
        }
    }
    
    return 0;
}
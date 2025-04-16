#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

// Direction arrays for up, right, down, left
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

class TurretSolver {
private:
    int rows, cols;
    vector<string> grid;
    vector<vector<bool>> isCovered;
    vector<vector<bool>> isTurret;
    vector<pair<int,int>> candidateCells;
    int minTurrets;
    
    // Check if position is valid
    bool isValid(int x, int y) {
        return x >= 0 && x < rows && y >= 0 && y < cols;
    }
    
    // Check if a turret can be placed at (x,y)
    bool canPlaceTurret(int x, int y) {
        if (grid[x][y] != '.') return false;
        if (isTurret[x][y]) return false;
        
        // Check all four directions
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            
            while (isValid(nx, ny)) {
                if (grid[nx][ny] == '#' || isdigit(grid[nx][ny])) {
                    // Hit a wall or outpost
                    break;
                }
                if (isTurret[nx][ny]) {
                    return false; // Found another turret
                }
                nx += dx[d];
                ny += dy[d];
            }
        }
        return true;
    }
    
    // Get coverage value of a cell (higher is better)
    int getCoverageValue(int x, int y) {
        if (!canPlaceTurret(x, y)) return -1;
        
        int coveredCount = 0;
        // Count uncovered cells that would be covered
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            
            while (isValid(nx, ny)) {
                if (grid[nx][ny] == '#' || isdigit(grid[nx][ny])) break;
                if (!isCovered[nx][ny]) coveredCount++;
                nx += dx[d];
                ny += dy[d];
            }
        }
        if (!isCovered[x][y]) coveredCount++; // Count self
        
        return coveredCount;
    }
    
    // Update coverage when placing a turret
    void updateCoverage(int x, int y, bool coverOrUncover) {
        isCovered[x][y] = coverOrUncover;
        
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            
            while (isValid(nx, ny)) {
                if (grid[nx][ny] == '#' || isdigit(grid[nx][ny])) break;
                isCovered[nx][ny] = coverOrUncover;
                nx += dx[d];
                ny += dy[d];
            }
        }
    }
    
    // Check outpost constraints
    bool checkOutpostConstraints() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (isdigit(grid[i][j])) {
                    int required = grid[i][j] - '0';
                    int count = 0;
                    
                    for (int d = 0; d < 4; d++) {
                        int nx = i + dx[d];
                        int ny = j + dy[d];
                        if (isValid(nx, ny) && isTurret[nx][ny]) {
                            count++;
                        }
                    }
                    
                    if (count != required) return false;
                }
            }
        }
        return true;
    }
    
    // Check if all cells are covered
    bool allCovered() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '.' && !isCovered[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    // Heuristic placement to find initial solution
    int heuristicSolution() {
        vector<vector<bool>> tempTurret(rows, vector<bool>(cols, false));
        vector<vector<bool>> tempCovered(rows, vector<bool>(cols, false));
        int turretCount = 0;
        
        // Keep placing turrets until all cells are covered
        while (true) {
            int bestCoverage = -1;
            pair<int, int> bestPos = {-1, -1};
            
            // Find cell with best coverage
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (grid[i][j] == '.' && !tempTurret[i][j]) {
                        // Check if turret can be placed
                        bool canPlace = true;
                        for (int d = 0; d < 4; d++) {
                            int nx = i + dx[d];
                            int ny = j + dy[d];
                            
                            while (isValid(nx, ny)) {
                                if (grid[nx][ny] == '#' || isdigit(grid[nx][ny])) {
                                    break;
                                }
                                if (tempTurret[nx][ny]) {
                                    canPlace = false;
                                    break;
                                }
                                nx += dx[d];
                                ny += dy[d];
                            }
                            if (!canPlace) break;
                        }
                        
                        if (canPlace) {
                            // Count uncovered cells
                            int coverage = 0;
                            if (!tempCovered[i][j]) coverage++;
                            
                            for (int d = 0; d < 4; d++) {
                                int nx = i + dx[d];
                                int ny = j + dy[d];
                                
                                while (isValid(nx, ny)) {
                                    if (grid[nx][ny] == '#' || isdigit(grid[nx][ny])) {
                                        break;
                                    }
                                    if (!tempCovered[nx][ny]) {
                                        coverage++;
                                    }
                                    nx += dx[d];
                                    ny += dy[d];
                                }
                            }
                            
                            if (coverage > bestCoverage) {
                                bestCoverage = coverage;
                                bestPos = {i, j};
                            }
                        }
                    }
                }
            }
            
            if (bestCoverage <= 0) break; // No more cells to cover or no valid placements
            
            // Place turret at best position
            int x = bestPos.first;
            int y = bestPos.second;
            tempTurret[x][y] = true;
            turretCount++;
            
            // Update coverage
            tempCovered[x][y] = true;
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                
                while (isValid(nx, ny)) {
                    if (grid[nx][ny] == '#' || isdigit(grid[nx][ny])) {
                        break;
                    }
                    tempCovered[nx][ny] = true;
                    nx += dx[d];
                    ny += dy[d];
                }
            }
            
            // Check if all cells are covered
            bool allDone = true;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (grid[i][j] == '.' && !tempCovered[i][j]) {
                        allDone = false;
                        break;
                    }
                }
                if (!allDone) break;
            }
            
            if (allDone) break;
        }
        
        // Check outpost constraints
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (isdigit(grid[i][j])) {
                    int required = grid[i][j] - '0';
                    int count = 0;
                    
                    for (int d = 0; d < 4; d++) {
                        int nx = i + dx[d];
                        int ny = j + dy[d];
                        if (isValid(nx, ny) && tempTurret[nx][ny]) {
                            count++;
                        }
                    }
                    
                    if (count != required) return INT_MAX; // Invalid
                }
            }
        }
        
        return turretCount;
    }
    
    // Fast backtracking with optimizations
    void backtrack(int idx, int turretCount, int uncoveredCount) {
        // Early termination conditions
        if (turretCount >= minTurrets) return;
        if (idx >= candidateCells.size()) return;
        
        // Solution found
        if (uncoveredCount == 0) {
            if (checkOutpostConstraints() && turretCount < minTurrets) {
                minTurrets = turretCount;
            }
            return;
        }
        
        // Skip this cell
        backtrack(idx + 1, turretCount, uncoveredCount);
        
        // Try to place a turret here
        int x = candidateCells[idx].first;
        int y = candidateCells[idx].second;
        
        if (canPlaceTurret(x, y)) {
            // Count newly covered cells
            int newlyCovered = 0;
            if (!isCovered[x][y]) newlyCovered++;
            
            vector<pair<int, int>> coveredCells;
            coveredCells.push_back({x, y});
            
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                
                while (isValid(nx, ny)) {
                    if (grid[nx][ny] == '#' || isdigit(grid[nx][ny])) break;
                    if (!isCovered[nx][ny]) {
                        newlyCovered++;
                        coveredCells.push_back({nx, ny});
                    }
                    nx += dx[d];
                    ny += dy[d];
                }
            }
            
            // Place turret
            isTurret[x][y] = true;
            
            // Update coverage
            for (auto& cell : coveredCells) {
                isCovered[cell.first][cell.second] = true;
            }
            
            // Recursive call
            backtrack(idx + 1, turretCount + 1, uncoveredCount - newlyCovered);
            
            // Backtrack
            isTurret[x][y] = false;
            
            // Restore coverage
            for (auto& cell : coveredCells) {
                // Need to check if cell is still covered by other turrets
                bool stillCovered = false;
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        if (isTurret[i][j]) {
                            // Check if this turret covers the cell
                            bool covers = false;
                            if (i == cell.first && j == cell.second) {
                                covers = true;
                            } else {
                                // Check if in line of sight
                                for (int d = 0; d < 4; d++) {
                                    int nx = i + dx[d];
                                    int ny = j + dy[d];
                                    
                                    while (isValid(nx, ny)) {
                                        if (nx == cell.first && ny == cell.second) {
                                            covers = true;
                                            break;
                                        }
                                        if (grid[nx][ny] == '#' || isdigit(grid[nx][ny])) break;
                                        nx += dx[d];
                                        ny += dy[d];
                                    }
                                    if (covers) break;
                                }
                            }
                            
                            if (covers) {
                                stillCovered = true;
                                break;
                            }
                        }
                    }
                    if (stillCovered) break;
                }
                
                isCovered[cell.first][cell.second] = stillCovered;
            }
        }
    }
    
public:
    TurretSolver(vector<string>& cityMap) {
        rows = cityMap.size();
        cols = cityMap[0].size();
        grid = cityMap;
        isCovered.resize(rows, vector<bool>(cols, false));
        isTurret.resize(rows, vector<bool>(cols, false));
        minTurrets = INT_MAX;
        
        // Find candidate cells (empty cells)
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '.') {
                    candidateCells.push_back({i, j});
                }
            }
        }
        
        // Sort candidate cells by potential coverage
        sort(candidateCells.begin(), candidateCells.end(), [this](const pair<int,int>& a, const pair<int,int>& b) {
            return getCoverageValue(a.first, a.second) > getCoverageValue(b.first, b.second);
        });
    }
    
    string solve() {
        // Start with a heuristic solution
        int heuristicResult = heuristicSolution();
        if (heuristicResult != INT_MAX) {
            minTurrets = heuristicResult;
        }
        
        // Count initial uncovered cells
        int uncoveredCount = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '.') {
                    uncoveredCount++;
                }
            }
        }
        
        // Only use backtracking for small grids or if no heuristic solution
        if (rows * cols <= 225 && uncoveredCount <= 100) {
            // Reset state
            isCovered.assign(rows, vector<bool>(cols, false));
            isTurret.assign(rows, vector<bool>(cols, false));
            
            backtrack(0, 0, uncoveredCount);
        }
        
        if (minTurrets == INT_MAX) {
            return "noxus will rise!";
        } else {
            return to_string(minTurrets);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    for (int tc = 1; tc <= T; tc++) {
        int R, C;
        cin >> R >> C;
        
        vector<string> grid(R);
        for (int i = 0; i < R; i++) {
            cin >> grid[i];
        }
        
        TurretSolver solver(grid);
        cout << solver.solve() << endl;
    }
    
    return 0;
}
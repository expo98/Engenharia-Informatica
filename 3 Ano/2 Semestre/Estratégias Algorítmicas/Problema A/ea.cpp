#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

// Directions: up, right, down, left
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

// Structure to represent a position on the grid
struct Pos {
    int row, col;
};

int rows, cols;
vector<string> grid;
vector<vector<bool>> turrets; // Turret placements
vector<Pos> outposts;        // Stores outposts (characters '0'-'4')
vector<Pos> emptyCells;      // Empty cells where we can place turrets
int bestSolution;            // Best solution found so far

// For each outpost, store the indices (in 'emptyCells' order)
// of adjacent cells (distance 1)
vector<vector<int>> outpostAdjacent;

// Check if a position is valid
inline bool isValid(int x, int y) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

// Check if a position is empty
inline bool isEmpty(int x, int y) {
    return isValid(x, y) && grid[x][y] == '.';
}

// Check if a position is an outpost
inline bool isOutpost(int x, int y) {
    return isValid(x, y) && grid[x][y] >= '0' && grid[x][y] <= '4';
}

// Check if a position is a wall
inline bool isWall(int x, int y) {
    return isValid(x, y) && grid[x][y] == '#';
}

// Check if it's safe to place a turret at (r, c)
// i.e., no other turret in line of sight
bool safeToPlace(int r, int c) {
    for (int d = 0; d < 4; d++) {
        int nr = r + dx[d], nc = c + dy[d];
        while (isValid(nr, nc)) {
            if (turrets[nr][nc])
                return false; // Already a turret in line of sight
            if (isWall(nr, nc) || isOutpost(nr, nc))
                break;
            nr += dx[d];
            nc += dy[d];
        }
    }
    return true;
}

// Check if a cell is covered by any turret
bool isCovered(int r, int c) {
    // Check if the cell itself has a turret
    if (turrets[r][c])
        return true;
        
    // Check each direction
    for (int d = 0; d < 4; d++) {
        int nr = r + dx[d], nc = c + dy[d];
        while (isValid(nr, nc)) {
            if (turrets[nr][nc])
                return true; // Covered by a turret in this direction
            if (isWall(nr, nc) || isOutpost(nr, nc))
                break; // Blocked
            nr += dx[d];
            nc += dy[d];
        }
    }
    return false;
}

// Check if all empty cells are covered by at least one turret
bool checkCoverage() {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (isEmpty(r, c) && !isCovered(r, c))
                return false;
        }
    }
    return true;
}

// Count turrets adjacent to an outpost
int countAdjacentTurrets(int x, int y) {
    int count = 0;
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (isValid(nx, ny) && turrets[nx][ny]) {
            count++;
        }
    }
    return count;
}

// Check if all outposts have exactly the required number of adjacent turrets
bool checkOutposts() {
    for (const Pos& op : outposts) {
        int required = grid[op.row][op.col] - '0';
        int count = countAdjacentTurrets(op.row, op.col);
        if (count != required)
            return false;
    }
    return true;
}

// Count the total number of turrets placed
int countTurrets() {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (turrets[i][j]) {
                count++;
            }
        }
    }
    return count;
}

// Backtracking function
// index: current position in 'emptyCells' vector
// count: number of turrets placed so far
// outCount: number of turrets already adjacent to each outpost
void backtrack(int index, int count, vector<int>& outCount) {
    // If we've already used more turrets than the best solution, abort
    if (count >= bestSolution)
        return;
    
    // Incremental pruning: for each outpost, check if the solution is viable
    for (int i = 0; i < outposts.size(); i++) {
        int required = grid[outposts[i].row][outposts[i].col] - '0';
        if (outCount[i] > required)
            return; // Already exceeded the required number
        
        int available = 0;
        // Count how many undecided adjacent cells can contribute to this outpost
        for (int idx : outpostAdjacent[i]) {
            if (idx >= index)
                available++;
        }
        if (outCount[i] + available < required)
            return; // Even using all remaining cells, won't reach the requirement
    }
    
    // If all cells have been processed, check if the solution is valid
    if (index == emptyCells.size()) {
        if (checkOutposts() && checkCoverage())
            bestSolution = min(bestSolution, count);
        return;
    }
    
    int r = emptyCells[index].row, c = emptyCells[index].col;
    
    // Option 1: Don't place a turret at this cell
    backtrack(index + 1, count, outCount);
    
    // Option 2: Try to place a turret, if it's safe
    if (safeToPlace(r, c)) {
        turrets[r][c] = true;
        vector<int> modified;
        
        // Update the counter for adjacent outposts
        for (int i = 0; i < outposts.size(); i++) {
            if (abs(r - outposts[i].row) + abs(c - outposts[i].col) == 1) {
                outCount[i]++;
                modified.push_back(i);
            }
        }
        
        backtrack(index + 1, count + 1, outCount);
        
        // Backtrack: revert changes
        for (int i : modified)
            outCount[i]--;
        turrets[r][c] = false;
    }
}

int solveTurretPlacement() {
    outposts.clear();
    emptyCells.clear();
    bestSolution = INT_MAX;
    
    // Collect outposts and empty cells
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (isEmpty(i, j))
                emptyCells.push_back({i, j});
            else if (isOutpost(i, j))
                outposts.push_back({i, j});
        }
    }
    
    // Sort empty cells to prioritize those closest to outposts
    sort(emptyCells.begin(), emptyCells.end(), [&](const Pos& a, const Pos& b) {
        int minA = INT_MAX, minB = INT_MAX;
        for (const Pos& op : outposts) {
            minA = min(minA, abs(a.row - op.row) + abs(a.col - op.col));
            minB = min(minB, abs(b.row - op.row) + abs(b.col - op.col));
        }
        return minA < minB;
    });
    
    // For each outpost, record the indices of adjacent empty cells
    outpostAdjacent.clear();
    outpostAdjacent.resize(outposts.size());
    
    for (int i = 0; i < emptyCells.size(); i++) {
        int r = emptyCells[i].row, c = emptyCells[i].col;
        for (int j = 0; j < outposts.size(); j++) {
            if (abs(r - outposts[j].row) + abs(c - outposts[j].col) == 1)
                outpostAdjacent[j].push_back(i);
        }
    }
    
    // Quick check for infeasible outpost requirements
    for (int i = 0; i < outposts.size(); i++) {
        int required = grid[outposts[i].row][outposts[i].col] - '0';
        if (required > outpostAdjacent[i].size())
            return -1; // Impossible to satisfy
    }
    
    vector<int> outCount(outposts.size(), 0);
    backtrack(0, 0, outCount);
    
    return (bestSolution == INT_MAX) ? -1 : bestSolution;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int testCases;
    cin >> testCases;

    while (testCases--) {
        cin >> rows >> cols;

        grid.resize(rows);
        for (int i = 0; i < rows; i++) {
            cin >> grid[i];
        }

        // Initialize turrets grid
        turrets = vector<vector<bool>>(rows, vector<bool>(cols, false));

        int result = solveTurretPlacement();

        if (result == -1) {
            cout << "noxus will rise!" << endl;
        } else {
            cout << result << endl;
        }
    }

    return 0;
}
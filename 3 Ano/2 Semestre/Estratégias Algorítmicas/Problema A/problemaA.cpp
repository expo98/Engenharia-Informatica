#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <limits>
#include <functional>

using namespace std;

// Function to solve the Battle for Piltover problem
string solvePiltover(const vector<string>& grid, int rows, int cols) {
    // STEP 1: Parse the grid and initialize data structures
    map<pair<int, int>, int> outposts;  // (row, col) -> required turrets
    set<pair<int, int>> walls;          // Set of wall positions
    set<pair<int, int>> emptyCells;     // Set of empty cell positions
    
    // Parse each cell in the grid
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == '#') {
                walls.insert({r, c});
            } else if (grid[r][c] >= '0' && grid[r][c] <= '4') {
                outposts[{r, c}] = grid[r][c] - '0';
            } else { // Empty cell
                emptyCells.insert({r, c});
            }
        }
    }
    
    // STEP 2: Pre-compute useful information
    vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // Up, Right, Down, Left
    
    // For each outpost, find which cells are adjacent to it
    map<pair<int, int>, vector<pair<int, int>>> outpostAdjacencies;
    for (const auto& [pos, required] : outposts) {
        int r = pos.first;
        int c = pos.second;
        vector<pair<int, int>> adjacent;
        
        for (const auto& [dr, dc] : directions) {
            int nr = r + dr;
            int nc = c + dc;
            
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && 
                walls.find({nr, nc}) == walls.end() && 
                outposts.find({nr, nc}) == outposts.end()) {
                adjacent.push_back({nr, nc});
            }
        }
        
        outpostAdjacencies[pos] = adjacent;
        
        // Early check: if an outpost requires more turrets than there are adjacent positions
        if (adjacent.size() < required) {
            return "noxus will rise!";
        }
    }
    
    // For each empty cell, find which outposts it's adjacent to
    map<pair<int, int>, vector<pair<int, int>>> cellToOutposts;
    for (const auto& cell : emptyCells) {
        int r = cell.first;
        int c = cell.second;
        vector<pair<int, int>> adjacentOutposts;
        
        for (const auto& [dr, dc] : directions) {
            int nr = r + dr;
            int nc = c + dc;
            
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                outposts.find({nr, nc}) != outposts.end()) {
                adjacentOutposts.push_back({nr, nc});
            }
        }
        
        cellToOutposts[cell] = adjacentOutposts;
    }
    
    // Pre-compute visibility from each cell
    map<pair<int, int>, vector<pair<int, int>>> visibility;
    for (const auto& cell : emptyCells) {
        int r = cell.first;
        int c = cell.second;
        vector<pair<int, int>> visible;
        
        for (const auto& [dr, dc] : directions) {
            int nr = r + dr;
            int nc = c + dc;
            
            while (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                // Stop at walls and outposts
                if (walls.find({nr, nc}) != walls.end() || 
                    outposts.find({nr, nc}) != outposts.end()) {
                    break;
                }
                
                if (emptyCells.find({nr, nc}) != emptyCells.end()) {
                    visible.push_back({nr, nc});
                }
                
                nr += dr;
                nc += dc;
            }
        }
        
        visibility[cell] = visible;
    }
    
    // STEP 3: Set up tracking variables for our current state
    set<pair<int, int>> placedTurrets;                  // Positions where turrets are placed
    map<pair<int, int>, int> outpostCoverage;           // Outpost -> number of adjacent turrets
    set<pair<int, int>> coveredCells;                   // Cells covered by at least one turret
    
    // Initialize outpost coverage
    for (const auto& [pos, required] : outposts) {
        outpostCoverage[pos] = 0;
    }
    
    // STEP 4: Define helper functions for updating state
    
    // Function to check if placing a turret at (r,c) would conflict with existing turrets
    auto conflictsWithExisting = [&](int r, int c) -> bool {
        for (const auto& turret : placedTurrets) {
            int tr = turret.first;
            int tc = turret.second;
            
            // Check if they're in the same row or column
            if (tr == r || tc == c) {
                // If they're in the same row or column, check for blockages
                bool blocked = false;
                
                if (tr == r) {  // Same row
                    int startC = min(c, tc);
                    int endC = max(c, tc);
                    for (int col = startC + 1; col < endC; col++) {
                        if (walls.find({r, col}) != walls.end() || 
                            outposts.find({r, col}) != outposts.end()) {
                            blocked = true;
                            break;
                        }
                    }
                }
                else {  // Same column
                    int startR = min(r, tr);
                    int endR = max(r, tr);
                    for (int row = startR + 1; row < endR; row++) {
                        if (walls.find({row, c}) != walls.end() || 
                            outposts.find({row, c}) != outposts.end()) {
                            blocked = true;
                            break;
                        }
                    }
                }
                
                // If not blocked, there's a conflict
                if (!blocked) {
                    return true;
                }
            }
        }
        
        // No conflicts found
        return false;
    };
    
    // Function to update coverage when a turret is placed
    auto updateCoverage = [&](int r, int c, bool add) {
        if (add) {
            // The turret's position is covered
            coveredCells.insert({r, c});
            
            // Check all four directions
            for (const auto& [dr, dc] : directions) {
                int nr = r + dr;
                int nc = c + dc;
                
                while (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    if (walls.find({nr, nc}) != walls.end() || 
                        outposts.find({nr, nc}) != outposts.end()) {
                        break;  // Blocked by wall or outpost
                    }
                    
                    // Mark this cell as covered
                    coveredCells.insert({nr, nc});
                    
                    nr += dr;
                    nc += dc;
                }
            }
        }
        else {
            // When removing a turret, we need to recalculate all coverage
            coveredCells.clear();
            
            // Recalculate coverage from all remaining turrets
            for (const auto& turret : placedTurrets) {
                int tr = turret.first;
                int tc = turret.second;
                
                // The turret's position is covered
                coveredCells.insert({tr, tc});
                
                // Check all four directions
                for (const auto& [dr, dc] : directions) {
                    int nr = tr + dr;
                    int nc = tc + dc;
                    
                    while (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                        if (walls.find({nr, nc}) != walls.end() || 
                            outposts.find({nr, nc}) != outposts.end()) {
                            break;  // Blocked by wall or outpost
                        }
                        
                        // Mark this cell as covered
                        coveredCells.insert({nr, nc});
                        
                        nr += dr;
                        nc += dc;
                    }
                }
            }
        }
    };
    
    // STEP 5: Implement the backtracking algorithm
    
    int minTurrets = numeric_limits<int>::max();  // Track the minimum number of turrets needed
    
    // Helper function to calculate cell priority
    auto cellPriority = [&](const pair<int, int>& cell) -> int {
        int r = cell.first;
        int c = cell.second;
        int priority = 0;
        
        // Higher priority for cells adjacent to outposts with unmet requirements
        for (const auto& outpostPos : cellToOutposts[cell]) {
            int req = outposts[outpostPos];
            int cur = outpostCoverage[outpostPos];
            if (cur < req) {
                priority += 100 * (req - cur);
            }
        }
        
        // Higher priority for cells that cover more uncovered cells
        for (const auto& [dr, dc] : directions) {
            int nr = r + dr;
            int nc = c + dc;
            
            while (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                if (walls.find({nr, nc}) != walls.end() || 
                    outposts.find({nr, nc}) != outposts.end()) {
                    break;
                }
                
                if (coveredCells.find({nr, nc}) == coveredCells.end()) {
                    priority += 1;
                }
                
                nr += dr;
                nc += dc;
            }
        }
        
        return priority;
    };
    
    // Recursive backtracking function
    function<void(vector<pair<int, int>>, int)> backtrack = [&](vector<pair<int, int>> remainingCells, int numTurrets) {
        // If we've already found a better solution, stop exploring this branch
        if (numTurrets >= minTurrets) {
            return;
        }
        
        // Check if all empty cells are covered
        if (coveredCells.size() >= emptyCells.size()) {
            // Check if all outpost requirements are met
            bool allOutpostsOk = true;
            for (const auto& [pos, required] : outposts) {
                if (outpostCoverage[pos] != required) {
                    allOutpostsOk = false;
                    break;
                }
            }
            
            if (allOutpostsOk) {
                minTurrets = numTurrets;
            }
            return;
        }
        
        // If there are no more cells to try, stop
        if (remainingCells.empty()) {
            return;
        }
        
        // Sort remaining cells by priority
        sort(remainingCells.begin(), remainingCells.end(), [&](const auto& a, const auto& b) {
            return cellPriority(a) > cellPriority(b);
        });
        
        // Get the highest-priority cell
        auto [r, c] = remainingCells[0];
        vector<pair<int, int>> newRemaining(remainingCells.begin() + 1, remainingCells.end());
        
        // OPTION 1: Try NOT placing a turret at this cell
        backtrack(newRemaining, numTurrets);
        
        // OPTION 2: Try placing a turret at this cell
        if (!conflictsWithExisting(r, c)) {
            // Place the turret
            placedTurrets.insert({r, c});
            
            // Update outpost coverage
            bool outpostViolated = false;
            for (const auto& outpostPos : cellToOutposts[{r, c}]) {
                outpostCoverage[outpostPos]++;
                
                // If we've exceeded an outpost's requirement, backtrack immediately
                if (outpostCoverage[outpostPos] > outposts[outpostPos]) {
                    outpostViolated = true;
                    break;
                }
            }
            
            if (!outpostViolated) {
                // Update coverage
                updateCoverage(r, c, true);
                
                // Continue backtracking
                backtrack(newRemaining, numTurrets + 1);
                
                // Update coverage for removal
                updateCoverage(r, c, false);
            }
            
            // Backtrack: remove the turret
            placedTurrets.erase({r, c});
            for (const auto& outpostPos : cellToOutposts[{r, c}]) {
                outpostCoverage[outpostPos]--;
            }
        }
    };
    
    // STEP 6: Start the backtracking process
    vector<pair<int, int>> allCells;
    for (const auto& cell : emptyCells) {
        allCells.push_back(cell);
    }
    
    backtrack(allCells, 0);
    
    // STEP 7: Return the result
    if (minTurrets == numeric_limits<int>::max()) {
        return "noxus will rise!";
    } else {
        return to_string(minTurrets);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;  // Number of test cases
    
    for (int i = 0; i < t; i++) {
        int r, c;
        cin >> r >> c;
        
        vector<string> grid(r);
        for (int j = 0; j < r; j++) {
            cin >> grid[j];
        }
        
        string result = solvePiltover(grid, r, c);
        cout << result << endl;
    }
    
    return 0;
}
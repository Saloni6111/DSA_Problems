#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();       // Number of rows in the grid
    int n = grid[0].size();    // Number of columns in the grid 

    int fresh = 0;             // Number of fresh oranges
    queue <pair <int, int>> rotten;       // Queue to store the rotten oranges

    // Traverse the grid to count fresh oranges and store rotten oranges in the queue
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (grid[i][j] == 1){
                fresh ++;
            }

            if (grid[i][j] == 2){
                rotten.push({i,j});
            }
        }
    }

    // If there are no fresh oranges, return 0 as no time is needed
    if (fresh == 0){
        return 0;
    }

    int ind_search = rotten.size();      // Number of oranges to be searched in the current minute 
    int minutes = 0;            // Minimum time taken for all the oranges to rot

    // Start the BFS-like process to rot neighboring fresh oranges
    while (rotten.empty() == 0){
        int x = rotten.front().first;      // Get the x-coordinate of the current rotten orange
        int y = rotten.front().second;     // Get the y-coordinate of the current rotten orange
        rotten.pop();

        //Now, we check for fresh oranges in all 4 neighboring directions and rot them if present

        if (y != 0 && grid[x][y-1] == 1){            // Check for fresh orange in the left direction
            grid[x][y-1] = 2;
            rotten.push({x,y-1});
            fresh --;
        }

        if (y != n-1 && grid[x][y+1] == 1){         // Check for fresh orange in the right direction
            grid[x][y+1] = 2;
            rotten.push({x,y+1});
            fresh --;
        }

        if (x != 0 && grid[x-1][y] == 1){          // Check for fresh orange in the up direction
            grid[x-1][y] = 2;
            rotten.push({x-1,y});
            fresh --;
        }

        if (x != m-1 && grid[x+1][y] == 1){        // Check for fresh orange in the down direction
            grid[x+1][y] = 2;
            rotten.push({x+1,y});
            fresh --;
        }

        ind_search --;          // Decrement the counter for this minute's processing
        if (ind_search == 0){
            minutes ++;         // Increment the time after processing all rotten oranges for this minute
            ind_search = rotten.size();    // Update the number of oranges to be searched in the next minute
        }
        
    }

    // If all fresh oranges have rotted, return the time taken (minus one as it overcounts the last minute)
    if (fresh == 0){
        return (minutes - 1);
    }

    // If there are still fresh oranges left, return -1 (impossible to rot all oranges)
    return -1;
}




int main()
{
    // Input handling: first, take the grid dimensions from the user
    int m;
    cout << "Enter the number of rows in the grid: ";
    cin >> m;
    
    int n; 
    cout << "Enter the number of columns in the grid: ";
    cin >> n;

    // Assumed constraints: 1 <= m, n

    // Create a 2D vector to represent the grid and take the grid elements as input
    vector<vector<int>> grid(m, vector<int>(n));
    cout << "Enter the elements of the grid: \n";
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];           // Input the state of each cell (0 for empty, 1 for fresh, 2 for rotten)
        }
    }

    // Call the function and print the result
    int result = orangesRotting(grid);
    cout << "The time taken for all the oranges to rot is: " << result;

    return 0;
}



// SAMPLE TEST CASES
//Test Case 1: (General Case)
// Input:
// [2, 1, 1]
// [1, 1, 0]
// [0, 1, 1]
// Expected output: 4

// Test Case 2: (All oranges are already rotten)
// Input:
// [2, 2, 2]
// [2, 2, 2]
// [2, 2, 2]
// Expected output: 0

// Test Case 3: (All oranges are fresh)
// Input:
// [1, 1, 1]
// [1, 1, 1]
// [1, 1, 1]
// Expected output: -1

// Test Case 4: (Impossible case - fresh oranges cannot rot)
// Input:
// [2, 1, 1]
// [0, 1, 0]
// [1, 0, 1]
// Expected output: -1

// Test Case 5: (Only one fresh orange surrounded by rotten ones)
// Input:
// [2, 2, 2]
// [2, 1, 2]
// [2, 2, 2]
// Expected output: 1

// Test Case 6: (No fresh oranges and no rotten oranges)
// Input:
// [0, 0, 0]
// [0, 0, 0]
// [0, 0, 0]
// Expected output: 0

// Test Case 7: (Empty grid)
// Input: []
// Expected output: 0


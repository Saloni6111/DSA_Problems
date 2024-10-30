class Solution {
public:
    bool search(vector<vector<char>>& board, int rMove, int cMove, char g_color, int i, int j)
    {
        rMove += i;
        cMove += j;
        int turn = 1;


       // Loop over the path until either condition is certain
       while(rMove < 8 && cMove < 8 && rMove >= 0 && cMove >= 0
       && board[rMove][cMove] != '.')
       {
        if(turn > 1 && board[rMove][cMove] == g_color) {return true;}
        else if(board[rMove][cMove] == g_color) return false;
        turn++;
        rMove += i;
        cMove += j;
       }

       return false;
    }
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        // A problem about searching the cells around and checking conditions
        // Eight different moving patterns that needs to be checked
        // For each pattern we need to ensure that the first next two celles are the
        // opposite color. After this, we need to find a same color.
        // If no such exist (either boundary conditions or ".") then return false
        // OR the results together and return
        
        // Early termination:
        if(board[rMove][cMove] != '.')
        {
            return false;
        }
        

        // Loop over all possible combinations of row and column traversal
        for(int i = -1; i <= 1; i++)
        {
            for(int j = -1; j <= 1; j++)
            {
                if(search(board,  rMove,  cMove, color, i, j))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ships = 0;
        int row = board.size();
        int col = board[0].size();

        for (int i=0; i<row; i++){
            for (int j=0; j<col; j++){
                if (board[i][j]!='X') continue;
                if (i>0 && board[i-1][j] == 'X') continue;//rowwise same ship
                if (j>0 && board[i][j-1] == 'X') continue;
                //column wise same ship

                ships++;
            }
        }


        return ships;
    }
};
bool exist(vector<vector<char>>& board, string word) {
        for(int i =0;i<board.size();++i){
            for(int j = 0; j<board[i].size();++j)
            {
                if(board[i][j] == word[0] and dfs(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string word, int i, int j,int cnt){
        if(cnt == word.size()){return true;}

        //if it cross the board boundry no need to continue searching
        if(i <0 || i >= board.size() || j <0 || j>=board[i].size()){
            return false;
        }

        //found a mismatched char, so no need to coninue search
        if(board[i][j] !=word[cnt]){
            return false;
        } 

        //preserve the char and keep searching in all dir
        auto ch = board[i][j];

        //remove the char from current search path to avoid duplication
        board[i][j] = ' ';

        bool found = ( dfs(board,word,i+1,j,cnt+1)||
                       dfs(board,word,i-1,j,cnt+1)||
                       dfs(board,word,i,j+1,cnt+1)||
                       dfs(board,word,i,j-1,cnt+1) );

        //putting back the char for the future search
        board[i][j] = ch;
        return found;
    }
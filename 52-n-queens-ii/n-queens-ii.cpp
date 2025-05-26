class Solution {
private:
    bool isValid(int row, int col, vector<bool>& upDiag, vector<bool>& left, vector<bool>& lowDiag, int n){
        if(col==0) return true;
        return !upDiag[row+col] && !left[row] && !lowDiag[(n-1)+(col-row)];
    }

    void generate(int col, vector<string>& chess, int& cnt, int n,
                vector<bool>& upDiag, vector<bool>& left, vector<bool>& lowDiag){
        
        if(col==n){
            cnt++;
        }

        for(int row=0;row<n;row++){
            if(isValid(row,col,upDiag,left,lowDiag,n)){
                chess[row][col] = 'Q';
                upDiag[row+col] = 1;
                
                left[row] = 1;
                lowDiag[(n-1)+(col-row)] = 1;
                
                generate(col+1,chess,cnt,n,upDiag,left,lowDiag);
                
                upDiag[row+col] = 0;
                left[row] = 0;
                lowDiag[(n-1)+(col-row)] = 0;

                chess[row][col] = '.';
            }
        }

        return;
    }

public:
    int totalNQueens(int n) {
        vector<bool> upDiag(2*n-1,0);
        vector<bool> left(n,0);
        vector<bool> lowDiag(2*n-1,0);

        vector<string> chess(n,string(n,'.'));
        int cnt = 0;

        generate(0,chess,cnt,n,upDiag,left,lowDiag);

        return cnt;
    }
};
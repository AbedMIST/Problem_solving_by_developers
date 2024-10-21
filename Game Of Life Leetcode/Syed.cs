public class Solution {

    int GetNeighboringSum(int [][] board,int curRow, int curCol, int row, int col)
    {
        int sum=0,i,j;

        for(i=-1;i<=1;i++)
        {
            for(j=-1;j<=1;j++)
            {
                if(i==0 && j==0)
                  continue;

                if(curRow+i>=row || curRow+i<0 || curCol+j>=col || curCol+j<0)
                  continue;
                sum+=board[curRow+i][curCol+j];
            }
        }

        return sum;

    }

    public void GameOfLife(int[][] board) {
         int row=board.Length;

         int col=board[0].Length,i,j,nsum=0;
         int[,] nextBoard = new int[row, col];
         for(i=0;i<row;i++)
         {
            for(j=0;j<col;j++)
             {
                 nsum=GetNeighboringSum(board,i, j, row,  col);
               
                 if(board[i][j]==1 && (nsum<2 || nsum>3))
                 {
                    nextBoard[i,j]=0;
                 }

                 else if(board[i][j]==1 && nsum==2)
                 {
                    nextBoard[i,j]=1;
                 }

                 else if( nsum==3)
                 {
                    nextBoard[i,j]=1;
                 }
                 
             }
            
         }
          for ( i = 0; i < row; i++) {
            for ( j = 0; j < col; j++) {
                board[i][j] = nextBoard[i,j];
            }
        }
        nextBoard=null;
        

    }
}
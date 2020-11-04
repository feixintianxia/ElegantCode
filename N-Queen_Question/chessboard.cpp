#include "chessboard.h"


RunMode runMode; //运行模式
int nSolu = 0;  //总解数
int nCheck = 0; //尝试的总次数
int nQueen = 8; //棋盘大小

//N皇后问题
void n_queen_question(int N) {
    Stack<Queen> solu;
    Queen q(0, 0);                      // 从原点出发试探
    while( !(q.x == 0 && q.y >= N) ) {  // 试探结束条件 q.x == 0 && q.y >= N
        //判断是否已出边界
        if ( N <= solu.size() || q.y >= N) {
            q = solu.pop();
            q.y++;     // 此时可能会出现q.x = 0 && q.y >= N 情况，故需要再次判断是否满足第一个while条件
        } else {
            while( (q.y < N) && (0 <= solu.find(q)) ) {
                q.y++;
                nCheck++;
            }
            if (q.y < N) {
                solu.push(q);
                if (N <= solu.size()) {
                    nSolu++;
                    //打印该次输出结果
                    displayProgress ( solu, N );
                }

                q.x++;
                q.y = 0;
            }
        }

        if ( Step == runMode ) {
            displayProgress ( solu, N );
        }
    }
}

int N = 0; // 棋盘大小
void displayRow( Queen& q ) { //打印当前皇后（放置于col列）所在行
   printf ( "%2d: ", q.x );
   int i = 0;
   while ( i++ < q.y ) printf ( "[ ]\t" );
   printf ( "[█]\t" );
   while ( i++ < N ) printf ( "[ ]\t" );
   printf ( "%2d\n", q.y );
}

void displayProgress( Stack<Queen>& S, int nQueen ) { //在棋盘上显示搜查的进展
   //system ( "clear" );
   N = nQueen; S.traverse ( displayRow );
   if ( nQueen <= S.size() )
      cout  << nSolu << " solution(s) found after " << nCheck << " check(s)\a" << endl;
   //getchar();
}
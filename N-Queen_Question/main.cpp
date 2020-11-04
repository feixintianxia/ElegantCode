#include "chessboard.h"
#define QUEEN_MAX 20 //皇后最大数量


int main ( int argc, char* argv[] ) {
   for ( int i = 1; i < argc - 1; i++ ) //检查参数
      if ( !strcmp ( "-step", argv[i] ) ) runMode = Step; //设定为单步演示模式
   int nQueen = atoi ( argv[argc-1] ); //棋盘大小 = 皇后总数
   if ( QUEEN_MAX < nQueen || 1 > nQueen ) { //检查参数
      fprintf ( stderr, "\nUsage: %s [-step] <nQueen(%d)>\n", argv[0], QUEEN_MAX );
      return -1;
   }
   n_queen_question ( nQueen ); //启动查找
   std::cout  << nSolu << " solution(s) found after "
         << nCheck << " check(s) for "
         << nQueen << " queen(s)\n"; //输出解的总数
   return 0;
}
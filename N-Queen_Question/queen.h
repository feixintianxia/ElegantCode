#pragma once
/*
--------------->y
│
│
│
│
↓
x
*/
//皇后类
class Queen {
public:
    int x, y;     //皇后在棋盘上的位置坐标
public:
    Queen(int tmpx = 0, int tmpy = 0) : x(tmpx), y(tmpy) {
    }
    Queen(Queen const& tmpQ) : x(tmpQ.x), y(tmpQ.y) {
    }
    bool operator== (Queen const& q) const {
        if ( (x == q.x)  //列冲突
        || (y == q.y)    //行冲突
        || (x + y == q.x + q.y) //对角线
        || (x - y == q.x - q.y) ) {
            return true;
        }
        return false;
    }

    bool operator!= (Queen const& q) const {
        return !(*this == q);
    }
};
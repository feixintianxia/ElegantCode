#pragma once

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#include "stack.h"
#include "queen.h"


typedef enum {Continuous, Step} RunMode;

extern RunMode runMode; //运行模式
extern int nSolu;       //解的总数
extern int nCheck;      //尝试的总次数

void n_queen_question(int N);
void displayRow( Queen& q );
void displayProgress( Stack<Queen>& S, int nQueen );
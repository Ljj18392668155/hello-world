
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned short  uint16;
typedef   signed short  sint16;

// 棋盘的最大行列数目
#define MAX_X   100
#define MAX_Y   100
#define MAX_Z   100

// 尝试的最大可能性 只有5种
#define MAX_SCH 5

// 最大的棋盘的数据结构   二位数组
uint16 chessboard[MAX_Z][MAX_Y][MAX_X];

void out_chessboard(void) {     // 打印出棋盘
    sint16 x,y,z;
    uint16 sum;

    for (z=0;z<MAX_Z;z++) {
        printf("plane %d:\n\r",z+1);

        printf("    ");
        for (x=0;x<MAX_X;x++) {
            printf("%4d",(x+1)%10);
        }
        printf("\n\r");             // 打印横坐标
        sum=0;
        for (y=0;y<MAX_Y;y++) {
            printf("%2d: ",y+1);    // 打印纵坐标
            for (x=0;x<MAX_X;x++) {
                printf("%4d",chessboard[z][y][x]);
                if (chessboard[z][y][x]) {
                    sum++;
                }
            }
            if (y==MAX_Y-1) {
                printf("    removed in this plane = %d",sum);
            }
            printf("\n\r");
        }
    }
}

uint16 exe_chessboard(sint16 sch) {     // 从棋盘取子
    sint16 x0;
    sint16 x,y,z;
    uint16 sum;

    sum=0;                      // 去除棋子的计数器

    for (z=0;z<MAX_Z;z++) {
        x0=sch-5-3*z;
        for (y=0;y<MAX_Y;y++) {
            for (x=x0;x<MAX_X;x+=5) {
                if ((x>=0)&&(y>=0)&&(z>=0)) {
                    chessboard[z][y][x]=1;
                    sum++;      // 去除棋子的计数器加一
                }
            }
            x0 -= 3;
        }
    }
    return sum;                 // 去除棋子的个数
}
uint16 chk_chessboard(void) {
    sint16 x,y,z,i;
    uint16 sum;

    // 单独的 x平面 y平面 z平面的 检查略掉  仅仅检查斜线对角的情况

    for (z=0;z<MAX_Z;z++) for (y=0;y<MAX_Y;y++) for (x=0;x<MAX_X;x++) {

        // x+ y+ z+方向 包括 x- y- z-
        sum=0;
        for (i=0;i<5;i++) {
            if ((z+i<MAX_Z)&&(y+i<MAX_Y)&&(x+i<MAX_X)) {
                sum += 1-chessboard[z+i][y+i][x+i];
            } else {
                sum=0;
            }
        }
        if (sum>=5) {   // 有五连珠 则返回失败
            for (i=0;i<5;i++) {
                printf("(%d,%d,%d),",x+i,y+i,z+i);
            }
            chessboard[z+2][y+2][x+2]=1;
            printf("\n\r");
            return 0;
        }

        // x+ y+ z-方向 包括 x- y- z+
        sum=0;
        for (i=0;i<5;i++) {
            if ((z-i<MAX_Z)&&(z-i>=0)&&(y+i<MAX_Y)&&(x+i<MAX_X)) {
                sum += 1-chessboard[z-i][y+i][x+i];
            } else {
                sum=0;
            }
        }
        if (sum>=5) {   // 有五连珠 则返回失败
            for (i=0;i<5;i++) {
                printf("(%d,%d,%d),",x+i,y+i,z-i);
            }
            chessboard[z-2][y+2][x+2]=1;
            printf("\n\r");
            return 0;
        }

        // x+ y- z+方向
        sum=0;
        for (i=0;i<5;i++) {
            if ((z+i<MAX_Z)&&(y-i<MAX_Y)&&(y-i>=0)&&(x+i<MAX_X)) {
                sum += 1-chessboard[z+i][y-i][x+i];
            } else {
                sum=0;
            }
        }
        if (sum>=5) {   // 有五连珠 则返回失败
            for (i=0;i<5;i++) {
                printf("(%d,%d,%d),",x+i,y-i,z+i);
            }
            chessboard[z+2][y-2][x+2]=1;
            printf("\n\r");
            return 0;
        }

        // x- y+ z+方向
        sum=0;
        for (i=0;i<5;i++) {
            if ((z+i<MAX_Z)&&(y+i<MAX_Y)&&(x-i<MAX_X)&&(x-i>=0)) {
                sum += 1-chessboard[z+i][y+i][x-i];
            } else {
                sum=0;
            }
        }
        if (sum>=5) {   // 有五连珠 则返回失败
            for (i=0;i<5;i++) {
                printf("(%d,%d,%d),",x-i,y+i,z+i);
            }
            chessboard[z+2][y+2][x-2]=1;
            printf("\n\r");
            return 0;
        }
    }

    return 1;                   // 无五连珠
}


void main(void) {
    uint16 sum;
    uint16 sch;                 // 取出的棋子的位置  只能为 (0,0,0) (1,0,0) (2,0,0) (3,0,0) (4,0,0)  5种可能
                                // y和z的关系 与 x和z的关系 一样 所以不用考虑 y平面上的平移


    for (sch=0;sch<MAX_SCH;sch++) {
        // 将棋盘全部放上棋子 以0表示棋子
        memset(chessboard,0,sizeof(chessboard));
        // 去除棋子
        sum=exe_chessboard(sch);

        printf(" [sch=%2d]\n\r", sch);


        // 检查棋盘 如果不合格（发现五连珠）返回0     如果发现5连珠 则将中间的棋子去除 再次检查
        while (chk_chessboard()==0) {
            sum++;
            printf("check fail\n\r");
        }

        //打印棋盘布局示意图
        out_chessboard();

        //报告去除棋子的数目
        printf("removed piece sum=%d\n\r",sum);
    }

}


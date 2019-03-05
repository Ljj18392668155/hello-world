
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned short  uint16;
typedef   signed short  sint16;

// ���̵����������Ŀ
#define MAX_X   100
#define MAX_Y   100
#define MAX_Z   100

// ���Ե��������� ֻ��5��
#define MAX_SCH 5

// �������̵����ݽṹ   ��λ����
uint16 chessboard[MAX_Z][MAX_Y][MAX_X];

void out_chessboard(void) {     // ��ӡ������
    sint16 x,y,z;
    uint16 sum;

    for (z=0;z<MAX_Z;z++) {
        printf("plane %d:\n\r",z+1);

        printf("    ");
        for (x=0;x<MAX_X;x++) {
            printf("%4d",(x+1)%10);
        }
        printf("\n\r");             // ��ӡ������
        sum=0;
        for (y=0;y<MAX_Y;y++) {
            printf("%2d: ",y+1);    // ��ӡ������
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

uint16 exe_chessboard(sint16 sch) {     // ������ȡ��
    sint16 x0;
    sint16 x,y,z;
    uint16 sum;

    sum=0;                      // ȥ�����ӵļ�����

    for (z=0;z<MAX_Z;z++) {
        x0=sch-5-3*z;
        for (y=0;y<MAX_Y;y++) {
            for (x=x0;x<MAX_X;x+=5) {
                if ((x>=0)&&(y>=0)&&(z>=0)) {
                    chessboard[z][y][x]=1;
                    sum++;      // ȥ�����ӵļ�������һ
                }
            }
            x0 -= 3;
        }
    }
    return sum;                 // ȥ�����ӵĸ���
}
uint16 chk_chessboard(void) {
    sint16 x,y,z,i;
    uint16 sum;

    // ������ xƽ�� yƽ�� zƽ��� ����Ե�  �������б�߶Խǵ����

    for (z=0;z<MAX_Z;z++) for (y=0;y<MAX_Y;y++) for (x=0;x<MAX_X;x++) {

        // x+ y+ z+���� ���� x- y- z-
        sum=0;
        for (i=0;i<5;i++) {
            if ((z+i<MAX_Z)&&(y+i<MAX_Y)&&(x+i<MAX_X)) {
                sum += 1-chessboard[z+i][y+i][x+i];
            } else {
                sum=0;
            }
        }
        if (sum>=5) {   // �������� �򷵻�ʧ��
            for (i=0;i<5;i++) {
                printf("(%d,%d,%d),",x+i,y+i,z+i);
            }
            chessboard[z+2][y+2][x+2]=1;
            printf("\n\r");
            return 0;
        }

        // x+ y+ z-���� ���� x- y- z+
        sum=0;
        for (i=0;i<5;i++) {
            if ((z-i<MAX_Z)&&(z-i>=0)&&(y+i<MAX_Y)&&(x+i<MAX_X)) {
                sum += 1-chessboard[z-i][y+i][x+i];
            } else {
                sum=0;
            }
        }
        if (sum>=5) {   // �������� �򷵻�ʧ��
            for (i=0;i<5;i++) {
                printf("(%d,%d,%d),",x+i,y+i,z-i);
            }
            chessboard[z-2][y+2][x+2]=1;
            printf("\n\r");
            return 0;
        }

        // x+ y- z+����
        sum=0;
        for (i=0;i<5;i++) {
            if ((z+i<MAX_Z)&&(y-i<MAX_Y)&&(y-i>=0)&&(x+i<MAX_X)) {
                sum += 1-chessboard[z+i][y-i][x+i];
            } else {
                sum=0;
            }
        }
        if (sum>=5) {   // �������� �򷵻�ʧ��
            for (i=0;i<5;i++) {
                printf("(%d,%d,%d),",x+i,y-i,z+i);
            }
            chessboard[z+2][y-2][x+2]=1;
            printf("\n\r");
            return 0;
        }

        // x- y+ z+����
        sum=0;
        for (i=0;i<5;i++) {
            if ((z+i<MAX_Z)&&(y+i<MAX_Y)&&(x-i<MAX_X)&&(x-i>=0)) {
                sum += 1-chessboard[z+i][y+i][x-i];
            } else {
                sum=0;
            }
        }
        if (sum>=5) {   // �������� �򷵻�ʧ��
            for (i=0;i<5;i++) {
                printf("(%d,%d,%d),",x-i,y+i,z+i);
            }
            chessboard[z+2][y+2][x-2]=1;
            printf("\n\r");
            return 0;
        }
    }

    return 1;                   // ��������
}


void main(void) {
    uint16 sum;
    uint16 sch;                 // ȡ�������ӵ�λ��  ֻ��Ϊ (0,0,0) (1,0,0) (2,0,0) (3,0,0) (4,0,0)  5�ֿ���
                                // y��z�Ĺ�ϵ �� x��z�Ĺ�ϵ һ�� ���Բ��ÿ��� yƽ���ϵ�ƽ��


    for (sch=0;sch<MAX_SCH;sch++) {
        // ������ȫ���������� ��0��ʾ����
        memset(chessboard,0,sizeof(chessboard));
        // ȥ������
        sum=exe_chessboard(sch);

        printf(" [sch=%2d]\n\r", sch);


        // ������� ������ϸ񣨷��������飩����0     �������5���� ���м������ȥ�� �ٴμ��
        while (chk_chessboard()==0) {
            sum++;
            printf("check fail\n\r");
        }

        //��ӡ���̲���ʾ��ͼ
        out_chessboard();

        //����ȥ�����ӵ���Ŀ
        printf("removed piece sum=%d\n\r",sum);
    }

}


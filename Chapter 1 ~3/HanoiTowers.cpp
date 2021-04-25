#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;



int main()
{
    void HanoiTowers(int n, int fromPeg, int toPeg);
    int n = 5;
    HanoiTowers(n, 1 ,3);

    return 0;
}

/*
算法1：递归调用
1.将上面n-1个圆盘移动到过渡位置
2.将最下面的圆盘移动到目标位置
3.将剩下n-1个圆盘移动到目标位置

参数
n: 圆盘个数
fromPeg: 开始位置(这里取1)
toPeg: 结束位置(这里取3)
*/
void HanoiTowers(int n, int fromPeg, int toPeg)
{
    if(n == 1){  //只有一个圆盘，直接输出
        printf("将圆盘从 %d 搬到 %d\n", fromPeg, toPeg);
        return;
    }
    int unusedPeg = 6 - fromPeg - toPeg;

    HanoiTowers(n-1, fromPeg, unusedPeg);   //把上面n-1个圆盘移到过渡位置
    printf("将圆盘从 %d 搬到 %d\n", fromPeg, toPeg);  //把最下面的圆盘搬到目标位置
    HanoiTowers(n-1, unusedPeg, toPeg);     //把剩下的n-1个圆盘搬到目标位置
    return;
}

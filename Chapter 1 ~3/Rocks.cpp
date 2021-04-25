#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;


int main()
{
    char Rocks(int m, int n);
    char tmp = Rocks(7, 7);
    //printf("%s", tmp);
    cout<<"Result is:"<<tmp<<endl;
    return 0;
}

/*
算法: 动态规划

参数:
m: 第一堆石头个数
n: 第二堆石头个数
*/

char Rocks(int m, int n)
{
    vector<vector<char>> R(m, vector<char>(n));
    R[0][0] = 'L';

    //只有一堆石头的情况
    for(int i = 1; i < m; i++){
        if (R[i-1][0] == 'W')
            R[i][0] = 'L';
        else
            R[i][0] = 'W';
    }
    for(int j = 1; j < n; j++){
        if(R[0][j-1] == 'W')
            R[0][j] = 'L';
        else
            R[0][j] = 'W';
    }

    //两堆都有石头
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(R[i-1][j-1] == 'W' && R[i-1][j] == 'W' && R[i][j-1] == 'W')
                R[i][j] = 'L';
            else
                R[i][j] = 'W';
        }
    }

    //输出
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            //printf("%s", R[i][j]);
            //printf("\t");
            cout<<R[i][j]<<'\t';
        }
        //printf("\n");
        cout<<endl;
    }

    return  R[m-1][n-1];

}
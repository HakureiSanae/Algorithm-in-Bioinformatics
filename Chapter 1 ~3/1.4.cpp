#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;


int main()
{
    int Defect_Number(int n, int nums[]);
    int n = 10;
    int nums[9] = {1,10,3,4,5,6,7,8,9};
    int ans = Defect_Number(n, nums);
    cout<<"The defected number is: "<<ans<<endl;
    return ans;
}

/*
1.问题简述
    已知从n-1个数字数组,其中元素都是1到n中不同的整数,写出一个寻找缺失整数的线性-时间算法


2.算法核心
(1)对n个数字进行求和
(2)依次减掉数组中的每个元素，最后剩余的元素即为所缺失的实数

3.时间复杂度计算

*/

int Defect_Number(int n, int nums[])
{
    int i = 0, sum = 0;
    while (i < n){
        sum = sum + i - nums[i];
        i++;
    }
    sum += n;
    return sum;
}



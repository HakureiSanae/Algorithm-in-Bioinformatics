#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

#define inf 100000000
typedef long long ll;

int main()
{
    void Max_And_Min(ll nums[], ll n, ll &Max, ll &Min);
    //ll Min = inf, Max = -inf;
    ll nums[10] = {1,3,2,9,10,5,4,6,8,7};
    ll Min = nums[0], Max = nums[0];
    Max_And_Min(nums, 10, Max, Min);
    cout<<"max = "<<Max<<'\t'<<"min = "<<Min<<endl;
    return 0;
}

/*
1.算法核心:
每次取2个进行比较

2.时间复杂度计算
一共n/2次选取, 每次比较3次，一共比较3n/2次

*/

void Max_And_Min(ll * nums, ll n, ll &Max, ll &Min)
{
    int numOfcmp = 0;
    int tmp1, tmp2; //tmp1为较大者, tmp2为较小者
    int i = 0;
    //如果为奇数,第一个数字不参加比较
    if(n % 2)
        i++;

    for(; i < n; i = i + 2){
        numOfcmp++;
        //选出较大者
        if(nums[i] > nums[i+1]){
            tmp1 = nums[i];
            tmp2 = nums[i+1];
        }
        else{
            tmp1 = nums[i+1];
            tmp2 = nums[i];
        }
        //比较最小者
        numOfcmp++;
        if(tmp1 > Max){
            Max = tmp1;
        }
        //选出最小者
        numOfcmp++;
        if (tmp2 < Min){
            Min = tmp2;
        }
        //cout<<"max = "<<Max<<'\t'<<"min = "<<Min<<endl;
    }
    cout<<"Number of Compare is: "<<numOfcmp<<endl;
    return;
}

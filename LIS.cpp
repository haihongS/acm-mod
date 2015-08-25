#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

const int MAXN=1e3;

long long store[MAXN];  // 存储待处理序列
long long dp[MAXN]; // 处理

long long  binSearch(long long b,long long e,long long num);  // 二分搜索下界
long long output(long long loca,long long num);

int main()
{
	int len;
	scanf("%d",&len); // 输入序列长度
	for(int i=1;i<=len;i++)
		scanf("%lld",&store[i]); // 读入序列
	dp[1]=store[1]; // 第一个值付给dp
	int maxr=1; // LIS最长长度
	for(int i=2;i<=len;i++)
	{
		if(store[i]>dp[maxr])
			dp[++maxr]=store[i];
		else
		{
			long long loca=binSearch(1,maxr,store[i]);
			dp[loca]=store[i];
		}
	}
	printf("%d\n",maxr); // 输出LIS最长长度
	output(len,dp[maxr]); // 输出LIS一个序列
	return 0;
}

long long  binSearch(long long b,long long e,long long num)
{
	while(b<e)
	{
		long long mid=b+(e-b)/2;
		if(dp[mid]>=num)
			e=mid;
		else
			b=mid+1;
	}
	return b;
}

long long output(long long loca,long long num)
{
	if(loca==0)
		return 0;
	if(store[loca]>num)
		output(loca-1,num);
	else
	{
		output(loca-1,store[loca]);
		printf("%lld ",store[loca]);
	}
	return 0;
}

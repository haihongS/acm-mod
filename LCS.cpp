#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int MAXN=1e3;

int dp[MAXN][MAXN]; 
char record[MAXN][MAXN];
string pri,tocmp;//pri 串1, tocmp 串2

void output(int i,int j); // 输出公共子序列

int main()
{
	cin>>pri>>tocmp;
	int plen=pri.length();
	int tlen=tocmp.length();
    //初始化，pri串或tocmp串长度为0时，dp值为0
	for(int i=0;i<MAXN;i++)
		dp[i][0]=dp[0][i]=0;

	for(int i=0;i<plen;i++)
	{
		for(int j=0;j<tlen;j++)
		{
			if(pri[i]==tocmp[j]) // 
			{
				dp[i][j]=dp[i-1][j-1]+1;
				record[i][j]='x';
			}
			else if(dp[i-1][j]>dp[i][j-1])
			{
				dp[i][j]=dp[i-1][j];
				record[i][j]='u';
			}
			else
			{
				dp[i][j]=dp[i][j-1];
				record[i][j]='l';
			}
		}
	}
	// 输出LCS长度
	cout<<dp[plen-1][tlen-1]<<endl;
	//输出LCS
	output(plen-1,tlen-1);
	cout<<endl;


	return 0;
}

void output(int i,int j)
{
	if(i<0 || j<0)
		return;
	if(record[i][j]=='x')
	{
		output(i-1,j-1);
		cout<<pri[i];
	}
	else if(record[i][j]=='u')
		output(i-1,j);
	else
		output(i,j-1);
	return;
}

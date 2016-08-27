/*
O(nlogn)，求得凸包上的点
num保存n个点
首先先对点排
gramham函数传入顶点个数，返回凸包点的个数
go存储凸包的点
索引从0开始
*/

struct II
{
	int x,y;
}num[maxn],go[maxn];

int graham(int n)
{
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		while(cnt>1 &&  cross(go[cnt-2],go[cnt-1],num[i])<=0)
			cnt--;
		go[cnt++]=num[i];
	}
	int tmp=cnt;
	for(int i=n-2;i>=0;i--)
	{
		while(cnt>tmp && cross(go[cnt-2],go[cnt-1],num[i])<=0)
			cnt--;
		go[cnt++]=num[i];
	}
	return cnt;
}

int cross(II a,II b,II c)
{
	II v1,v2;
	v1.x=b.x-a.x;
	v1.y=b.y-a.y;
	v2.x=c.x-b.x;
	v2.y=c.y-b.y;
	return v1.x*v2.y-v1.y*v2.x;
}

int cmp(II a,II b)
{
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}

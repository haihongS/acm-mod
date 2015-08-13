//容斥原理 模板
// n 个数 ; storeit[]存储每个数具体的值
//函数类型按具体所需修改
const int MAX=1000;
int n,ans=0;
int storeit[MAX]; // 数据从0开始计数，到n-1结束。

for(int i=1;i<(1<<n);i++) // 从选1个开始，到全选(二进制全为1)
{
	int cnt=0; //选的个数
	int summ=0; //选cnt个元素的并
	for(int j=0;j<n;j++)
	{
		if(i&(1<<j)) 
		{
			cnt++;
			summ+=storeit[j];
		}
	}
	if(cnt&1) //如果包含元素是奇数个，加上summ
		ans+=summ;
	else//偶数个，减去summ
		ans-=summ;
}


//函数封装

//辗转相除法
int gcd(int x,int y)
{
	if(x<y)
		return gcd(y,x);
	return (y==0?x:gcd(y,x%y));
}

// 若 a|x && a|y ，则 a|(x-y)
int gcd(int x,int y)
{
	if(x<y)
		return gcd(y,x);
	if(y==0)
		return x;
	return gcd(x-y,y);
}

// 针对大数进行优化，O(log2(max(x,y)));
long long gcd(long long x,long long y)
{
	if(x<y)
		return gcd(y,x);
	if(y==0)
		return x;
	if(x&1)
	{
		if(y&1)
			return gcd(x-y,y);
		else
			return gcd(x,y>>1);
	}
	else
	{
		if(y&1)
			return gcd(x>>1,y);
		else
			return gcd(x>>1,y>>1)<<1;
	}
}

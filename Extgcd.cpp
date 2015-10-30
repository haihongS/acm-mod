/*
扩展欧几里得算法
对于不完全为 0 的非负整数 a，b
存在x,y使 a*x+b*y=gcd(a,b)
x,y传值引用
函数返回值为gcd(a,b)
*/
int Extgcd(int a,int b,int & x,int & y)
{
    if(b==0)
    {
        x=1;y=0;
        return a;
    }
    else
    {
        int ans=Extgcd(b,a%b,x,y);
        int t=x;
        x=y;
        y=t-(a/b)*y;
        return ans;
    }
}

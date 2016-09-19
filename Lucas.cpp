/*
计算大组合数取模
先调init初始化
*/

//(2)
const int N = 1000005;

ll fac[N];

void init()//预处理阶乘
{
    fac[0]=1;
    for(int i=1;i<=N;i++)
        fac[i]=i*fac[i-1]%mod;
}
ll pow_mod(ll a,ll b)
{
    ll s=1;
    a=a%mod;
    while(b)
    {
        if(b&1)
            s=s*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return s;
}
ll C(int n,int m)
{
    if(m>n)
        return 0;
    return  fac[n]*pow_mod(fac[m]*fac[n-m]%mod,mod-2)%mod;
}
ll Lucas(int n,int m)
{
    if(m==0)
        return 1;
    return C(n%mod,m%mod)*Lucas(n/mod,m/mod)%mod;
}


// (1)
const ll MOD=110119;
ll f[MOD+10],all[MOD+10];

ll C(ll n, ll m)
{
    if(m > n) return 0;
    if (m==0) return 1;
    if (m<0) return 0;
    return f[n]*all[f[m]]%MOD*all[f[n-m]]%MOD;
}

ll Lucas(ll n, ll m)
{
    if(m == 0) return 1;
    return C(n % MOD, m % MOD) * Lucas(n / MOD, m / MOD) % MOD;
}

void init()
{
    f[1]=f[0]=all[1]=1;
    for(int i=2; i<=MOD; ++i)
        f[i]=f[i-1]*i%MOD,all[i]=all[MOD%i]*(MOD-MOD/i)%MOD;
}

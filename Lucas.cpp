/*
计算大组合数取模
先调init初始化
*/

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

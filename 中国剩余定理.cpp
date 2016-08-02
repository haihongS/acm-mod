// x=b mod a
// tot 方程总数，0~tot-1
ll a[maxn],b[maxn];
int tot;

void egcd(ll a, ll b, ll&d, ll&x, ll&y)
{
    if (!b) { d = a, x = 1, y = 0; }
    else
    {
        egcd(b, a%b, d, y, x);
        y -= x*(a / b);
    }
}

// x=b mod a
ll lmes() {
    ll M = a[0], R = b[0], x, y, d;
    for (int i = 1; i < tot; i++) {
        egcd(M, a[i], d, x, y);
        if ((b[i] - R) % d) return -1;
        x = (b[i] - R) / d*x % (a[i] / d);
        R += x*M;
        M = M / d*a[i];
        R %= M;
    }
    R = (R + M) % M - M;
    return R;
}





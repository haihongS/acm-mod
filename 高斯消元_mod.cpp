/*
先调用 void Gauss_init() 初始化
Gauss(int n,int m) 
n个方程，m个未知数
*/


const int mod = 3;
int exgcd(int a,int b,int &x,int &y){
    if(!b){x = 1; y = 0; return a;}
    else{
        int r = exgcd(b,a%b,y,x);
        y -= x * (a/b);
        return r;
    }
}
int lcm(int a,int b){
    int x = 0, y =0;
    return a / exgcd(a,b,x,y) * b;
}
const int MAXN=1000;

int A[MAXN][MAXN],free_x[MAXN],x[MAXN];
void Gauss(int n,int m){
    int r,c;
    for(r=0,c=0;r<n && c<m;c++){
        int maxr = r;
        for(int i=r+1;i<n;i++) if(abs(A[i][c]) > abs(A[maxr][c])) maxr = i;
        if(maxr != r) for(int i=c;i<=m;i++) swap(A[r][i],A[maxr][i]);
        if(!A[r][c]) continue;
        for(int i=r+1;i<n;i++) if(A[i][c]){
            int d = lcm(A[i][c],A[r][c]);
            int t1 = d / A[i][c], t2 = d / A[r][c];
            for(int j=c;j<=m;j++)
                A[i][j] = ((A[i][j] * t1 - A[r][j] * t2) % mod + mod) % mod;
        }
        r++;
    }
    for(int i=r;i<n;i++) if(A[i][m]) return ;
    for(int i=r-1;i>=0;i--){
        x[i] = A[i][m];
        for(int j=i+1;j<m;j++){
            x[i] = ((x[i] - A[i][j] * x[j]) % mod + mod) % mod;
        }
        int x1 = 0,y1 = 0;
        int d = exgcd(A[i][i],mod,x1,y1);
        x1 = ((x1 % mod) + mod) % mod;
        x[i] = x[i] * x1 % mod;
    }
}
void Gauss_init(){
    memset(A,0,sizeof A); memset(free_x,0,sizeof free_x); memset(x,0,sizeof x);
}

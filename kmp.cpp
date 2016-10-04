/*
S 主串
T 模式串
slen,tlen 串的长

*/

int nx[maxn];
char S[maxn], T[maxn];
int slen, tlen;
int flag; // 是否找到子串

void get_next()
{
    int j=-1,i=0; nx[0]=-1;
    while(i<tlen)
    {
        if(j==-1||T[i]==T[j]) i++, j++, nx[i]=j;
        else j=nx[j];
    }
}

void kmp(){
    get_next();
    int i=0,j=0;
    while(i<slen){
        if(j==-1||S[i]==T[j])
		i++ ,j++;
        else j=nx[j];
        if(j==tlen)
            flag=1;
    }
}

/*
plan b
*/
char S[maxn],T[maxn];
int NEXT[maxn];///NEXT[i]表示既是模式串前i个字母的前缀又是又是模式串前i个字母的后缀的串的最长长度

/**串S中T出现的次数，S叫做主串，T叫做模式串**/
void getNext(char *T)///求模式串的NEXT
{
    int j = 0;
    int k = -1;
    NEXT[0] = -1;
    int tlen = strlen(T);
    while(j < tlen)
        if(k == -1 || T[j] == T[k])
            NEXT[++j] = ++k;
        else
            k = NEXT[k];
}
/**
返回模式串T在主串S中首次出现的位置，返回的位置是从0开始的。
**/
int KMP_Index(char *S,char *T)
{
    int i = 0, j = 0;
    int tlen = strlen(T);
    int slen = strlen(S);
    getNext(T);
    while(i < slen && j < tlen)
    {
        if(j == -1 || S[i] == T[j])
        {
            i++; j++;
        }
        else
            j = NEXT[j];
    }
    if(j == tlen)
        return i - tlen;
    else
        return -1;
}

/**
返回模式串T在主串S中出现的次数
**/
int KMP_Count(char *S,char *T)
{
    int ans = 0;
    int i, j = 0;
    int tlen = strlen(T);
    int slen = strlen(S);
    if(slen == 1 && tlen == 1)
    {
        if(S[0] == T[0])
            return 1;
        else
            return 0;
    }
    getNext(T);
    for(i = 0; i < slen; i++)
    {
        while(j > 0 && S[i] != T[j])
            j = NEXT[j];
        if(S[i] == T[j])
            j++;
        if(j == tlen)
        {
            ans++;
            j = NEXT[j];
        }
    }
    return ans;
}


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

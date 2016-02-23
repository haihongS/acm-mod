/* ***********************************************
Author        :shootPlane
Created Time  :2016/2/22 22:05:23
File Name     :S:\01\main.cpp
Blog          :http://haihongblog.com
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <stack>
using namespace std;
typedef long long LL;
const int maxn=1e5+9;
const int inf=2e9+9;
const double pi=acos(-1);


LL tree[4*maxn];

int query(int L,int R,int l,int r,int node);
int update(LL v,int loca,int l,int r,int node);

int main()
{
    return 0;
}

//find(L,R) from (l,r)
int query(int L,int R,int l,int r,int node)
{
	if(L<=l && r<=R)
	{
		//maxx=max(maxx,tree[node]);
		//find the max or min value
		return 0;
	}
	int mid=l+(r-l)/2;
	if(L<=mid)
		query(L,R,l,mid,2*node);
	if(R>mid)
		query(L,R,mid+1,r,2*node+1);
	tree[node]=max(tree[node*2],tree[node*2+1]);
	return 0;
}

// change loca value to v
int update(LL v,int loca,int l,int r,int node)
{
	if(l==r)
	{
		tree[node]=v;
		return 0;
	}
	int mid=l+(r-l)/2;
	if(loca<=mid)
		update(v,loca,l,mid,2*node);
	else
		update(v,loca,mid+1,r,2*node+1);
	tree[node]=max(tree[node*2],tree[node*2+1]);
	return 0;
}


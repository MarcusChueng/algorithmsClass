#include<bits/stdc++.h>
using namespace std;
int n,c,ans,nowValue,nowWeight;
struct NNN{
	int wi;
	int vi;
}node[99999];
int vis[99999];

bool cmp(NNN a,NNN b)
{
	return (a.vi*1.0 / a.wi) > (b.vi*1.0 / b.wi);
}

double bound(int i){
	int cleft = c - nowWeight;
	int b = nowValue;
	while(i<=n&&node[i].wi<=cleft){
		b+=node[i].vi;
		cleft -= node[i].wi;
		i++;
	}
	if(i<=n){
		b+=1.0*node[i].vi*cleft/node[i].wi;
	}
	return b;
}

void back(int i)
{
	if(nowWeight > c)
		return ;
		
	if(i>=n)
	{
		ans = max(ans,nowValue);
		return ;
	}
	
	if(nowWeight + node[i].wi <= c)
	{
		vis[i] = 1;
		nowWeight += node[i].wi;
		nowValue += node[i].vi;
		back(i+1);
	
		nowWeight -= node[i].wi;
		nowValue -= node[i].vi;
	}
	
	
//	vis[i] = 0;
	if(bound(i+1)>ans){
		back(i+1);
	}
}

int main()
{
	cin>>n>>c;
	for(int i = 0;i<n;i++)
		cin>>node[i].wi>>node[i].vi;
		
	sort(node,node+n,cmp);
//	cout<<endl;
//	for(int i=0;i<n;i++){
//		cout<<node[i].wi<<" "<<node[i].vi<<" ";
//		cout<<node[i].vi/node[i].wi<<endl;
//	}
	
	back(0);
	
	cout<<ans;
	return 0;
 } 

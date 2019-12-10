#include<iostream>
using namespace std;
#define MAXLENGTH 1005
int workNum;
int costList[MAXLENGTH][MAXLENGTH];
int vis[MAXLENGTH];
int tmpCost;
int ans = 99999999;
void backtrack(int t){
	if(tmpCost > ans)
		return;
	if(t>workNum){
		if(tmpCost<ans){
			ans = tmpCost;
		}
		return;
	}
	else
	{
		for(int k=1;k<=workNum;k++)
		{
			if(!vis[k])
			{
				tmpCost += costList[t][k];
				vis[k] = 1;
				backtrack(t+1);
				tmpCost -= costList[t][k];
				vis[k] = 0;
			}

		}
	}
}

int main(){
	cin>>workNum;
	for(int i=1;i<=workNum;i++){
		for(int j=1;j<=workNum;j++){
			cin>>costList[i][j];
		}
	}
	backtrack(1);
	cout<<ans<<endl;
	return 0;
}

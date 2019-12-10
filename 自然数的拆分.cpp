#include<iostream>
using namespace std;
int n,sum;
int arr[2000] = {1};
void output(int t){
	sum++;
	cout<<n<<"=";
	for(int i=1;i<=t;i++){
		if(i==t){
			cout<<arr[i];
			cout<<endl;
		}
		else{
			cout<<arr[i]<<"+";
		}
	}
}
void backtrack(int targetNum,int t){
	int i;
	for(i=arr[t-1];i<=targetNum;i++){
		if(i<n){
			arr[t]=i;
			targetNum-=i;
			if(targetNum==0){
				output(t);
			}else{
				backtrack(targetNum,t+1);
			}
			targetNum+=i;
		}
	}
//	return 0;
}
int main(){
	cin>>n;
	backtrack(n,1);
	return 0;
}

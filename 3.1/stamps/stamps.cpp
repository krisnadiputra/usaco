/*
ID: krisnad1
PROG: stamps
LANG: C++
*/

#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int K, N, los[50], chain, maxchain;
short int dp[2000001], temp;

int main(){
	freopen("stamps.in","r",stdin);
    freopen("stamps.out","w",stdout);	
	
	cin>>K>>N;
	for(int i=0;i<N;i++){
		cin>>los[i];	
	}
	
	memset(dp, 0, sizeof(dp));
	
	for(int i=0;i<N;i++){
		dp[los[i]]=1;	
	}
	
	chain=0;
	maxchain=0;
	
	for(int i=1;i<=(K*10000);i++){
		if(dp[i]==0){
			temp=201;
			for(int j=0;j<N;j++){
				if((i-los[j]>0)&&(dp[i-los[j]]!=0)&&(temp>(dp[i-los[j]]+1))&&(dp[i-los[j]]+1<=K)){
					temp=dp[i-los[j]]+1;
					dp[i]=temp;				
				}			
			}		
		}
		if(dp[i]!=0){
			chain++;
			if(chain>maxchain)
				maxchain=chain;
		}
		else chain=0;	
	}
	
	/*for(int i=0;i<20;i++)
		cout<<dp[i]<<" ";
	cout<<endl;*/	
	
	cout<<maxchain<<endl;
	
	fclose(stdin);
    fclose(stdout);	
	
	return 0;
}
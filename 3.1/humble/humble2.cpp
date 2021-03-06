/*
ID: krisnad1
PROG: humble
LANG: C++
*/

#include<iostream>
#include<stdio.h>
#include<utility>
#include<queue>

using namespace std;

int main(){
	int K,N,flag,pos;
	int p[100],m[100];
	long long H[100001],temp,prev,cur_dat;	
	
	freopen("humble.in","r",stdin);
    freopen("humble.out","w",stdout);
	cin>>K>>N;
	for(int i=0;i<K;i++)
	{
		cin>>p[i];
		m[i]=0;
	}
	H[0]=1;
	flag=0;
	prev=1;
	
	while(flag<N){
		temp=-1;
		pos=0;
		for(int i=0;i<K;i++){ 
			while(p[i] * H[m[i]]<=prev){
				m[i]++;			
			}
			if(temp==-1)temp=p[i] * H[m[i]];
			cur_dat=p[i] * H[m[i]];
			if(cur_dat<temp){
				temp=cur_dat;
				pos=i;			
			}
		}
		H[++flag]=temp;
		m[pos]++;
		prev=temp;
		//cout<<temp<<endl;
	}	
	
	cout<<H[N]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
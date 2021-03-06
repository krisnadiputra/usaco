/*
ID: krisnad1
PROG : combo
LANG : C++
*/

#include<stdio.h>
#include<iostream>

using namespace std;

int	N,lock1[3],lock2[3];

int cek(int x)
{
	if(x>N)return x-N;
	else if(x<1)return N+x;
	else return x;
}

int ovl(int n)
{
	int ctr;
	bool area[101];
	
	ctr=0;
	for(int i=0;i<101;i++)
		area[i]=0;
	for(int i=-2;i<3;i++)
		area[cek(lock1[n]+i)]=1;
	for(int i=-2;i<3;i++)
		if(area[cek(lock2[n]+i)])ctr++;
		
	return ctr;
}

int main()
{
	freopen("combo.in","r",stdin);
	freopen("combo.out","w",stdout);
	
	cin>>N;
	cin>>lock1[0]>>lock1[1]>>lock1[2];
	cin>>lock2[0]>>lock2[1]>>lock2[2];
	
	if(N>5)
	{ 
		cout<<250-(ovl(0)*ovl(1)*ovl(2))<<endl;
		//cout<<ovl(0)<<endl;
		//cout<<ovl(1)<<endl;
		//cout<<ovl(2)<<endl;
	}
	else 
		cout<<(N*N*N)<<endl;
	
	fclose(stdin);
	fclose(stdout);				
	return 0;
}
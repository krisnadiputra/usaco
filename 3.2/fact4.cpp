/*
ID: krisnad1
PROG: fact4
LANG: C++
*/

#include<cstdio>
#include<iostream>

using namespace std;
int n, cur=1, b=100000;

int main(){
	freopen("fact4.in","r",stdin);
    freopen("fact4.out","w",stdout);	
	cin>>n;
	for(int i=2;i<=n;i++){
		cur*=i;
		while(cur%10==0)cur/=10;
		cur%=b;
	}
	cout<<cur%10<<endl;
	
	fclose(stdin);
    fclose(stdout);	
	return 0;
}
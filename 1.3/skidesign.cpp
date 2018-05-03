/*
ID: krisnad1
PROG : skidesign
LANG : C++
*/

#include<iostream>
#include<stdio.h>

using namespace std;

int n,h[1000],temp,mins;

int main(){
	freopen("skidesign.in","r",stdin);
	freopen("skidesign.out","w",stdout);
	cin>>n;
	for (int i=0;i<n;i++){
		scanf("%d",&h[i]);
	}
	mins=10000000;
	for(int i=0;i<84;i++){
		temp=0;
		for(int j=0;j<n;j++){
			if(h[j]<i){
				temp+=((i-h[j])*(i-h[j]));			
			}
			else if(h[j]>(i+17)){
				temp+=((h[j]-(i+17))*(h[j]-(i+17)));
			}		
		}
		if(mins>temp)mins=temp;
	}
	cout<<mins<<endl;	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
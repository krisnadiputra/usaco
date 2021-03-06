/*
ID: krisnad1
PROG : wormhole
LANG : C++
*/

#include<iostream>
#include<stdio.h>

using namespace std;

typedef struct {
	int x;
	int y;
} dot;

dot lod[12];
bool flag[12], cycle_map[12][12];
int ct,N,seq[12],map[12];

int next(int cd){
	int nd;
	nd=-1;
	for(int i=0;i<N;i++){
		if((lod[cd].y==lod[i].y)&&(lod[cd].x<lod[i].x))	{
			if(nd==-1) nd=i;
			else if(lod[nd].x>lod[i].x)nd=i;		
		}
	}
	return nd;
}

bool check_loop(){
	int pos;
	for(int i=0;i<(N/2);i++){
		map[seq[2*i]]=seq[2*i+1];
		map[seq[2*i+1]]=seq[2*i];
	}
	
	/*for(int i=0;i<N;i++){
		cout<<"map["<<i<<"]="<<map[i]<<" "<<"next("<<i<<")="<<next(i)<<endl;	
	}*/
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<N;k++)
				cycle_map[j][k]=0;	
		}
		pos=i;
		while(next(map[pos])!=-1){
			if(!cycle_map[pos][map[pos]]){
				cycle_map[pos][map[pos]]=1;
				pos=	next(map[pos]);
			}
			else 
			{
				//cout<<i<<endl;
				return 1;
			}	
		}
	}
	return 0;	
}

void pair_generator(int r, int cur){
	if(r==0){
		/*for(int i=0;i<N;i++)
				cout<<seq[i]<<" ";
		cout<<endl;*/
		if(check_loop()){
			ct+=1;
			//cout<<"plus one"<<endl;
		}
	}
	else{
		flag[cur]=0;
		for(int i=cur+1;i<N;i++){
			if(flag[i]){
				seq[N-r]=cur;
				seq[N-r+1]=i;
				flag[i]=0;
				if(r>2){
					for(int j=0;j<N;j++){
						if(flag[j]){
							pair_generator(r-2,j);
							break;
						}				
					}
				}
				else pair_generator(0,-1);
				flag[i]=1;			
			}
		}
		flag[cur]=1;
	}
}

int main(){
	freopen("wormhole.in","r",stdin);
	freopen("wormhole.out","w",stdout);
	
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>lod[i].x>>lod[i].y;
	for(int i=0;i<N;i++){
		flag[i]=1;	
	}
	ct=0;
	pair_generator(N,0);
	cout<<ct<<endl;
	
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
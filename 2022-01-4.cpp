/*
[Q]
[]
*/

/*include*/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>

/*using namespace*/
using namespace std;

/*define type*/
#define ulli unsigned long long int
#define lli long long int
#define INT int
#define UINT unsigned INT
#define pii pair<INT,INT>

/*struct*/

/*num*/
UINT n,k,h[200001],w[5001];
UINT minheigh,maxheigh;
/*fn*/
UINT listfinder(UINT i){
	UINT dow=0,up=k,p;
	while(up-dow-1){
		p=(up+dow+1)/2;
		if(w[p]>i){
			up=p;
		}else{
			dow=p;
		}
	}
	return p;
}
bool solver(UINT p){
	UINT now=0,currcount=0;
	map<UINT,bool> currlist;
	for(int i=0;i<n;i++){
		if(h[i]>=p){
			now++;
		}else{
			UINT f=listfinder(now);
			while(!(currlist[f]) && f){
				f--;
			}
			if(f>=0){
				currlist[f]=true;
				currcount++;
			}
			now=0;
		}
		if(!(currcount-k)){
		    break;
		}
	}
	if(currcount-k){
		return false;
	}else{
		return true;
	}
}
/*main*/
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	{/*CIN*/
		cin>>n>>k;
		for(UINT i=0;i<n;i++){
			cin>>h[i];
			if(i){
				minheigh=min(h[i],minheigh);
				maxheigh=max(h[i],maxheigh);
			}else{
				minheigh=h[i];
				maxheigh=h[i];
			}
		}
		for(UINT i=0;i<k;i++){
			cin>>w[i];
		}
		sort(&(w[0]),&(w[k]));
	}
	maxheigh++;
	{/*solve*/
		while(maxheigh-minheigh-1){
		    cout<<maxheigh<<","<<minheigh<<"\n";
			if(solver((maxheigh+minheigh+1)/2)){
				minheigh=(maxheigh+minheigh+1)/2;
			}else{
				maxheigh=(maxheigh+minheigh+1)/2;
			}
		}
	}
	cout<<minheigh;
	return 0;
}

/*
[I1]
5 1
6 3 7 5 1
3
[O1]
3
[I2]
10 3
5 3 7 5 1 7 5 3 8 4
2 2 1
[O2]
5
*/

/*think*/
/*
使用二分搜進行搜尋
如果這一排不合格，將其設為新的頂部
如果這一排合格，將其設為新的底部
找到最後的倖存者
*/

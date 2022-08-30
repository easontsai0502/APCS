/*
[Q]https://zerojudge.tw/ShowProblem?problemid=h084
[AC]
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
bool solver(UINT p){
	UINT now=0,thisk=0;
	for(int i=0;i<n;i++){
		if(h[i]>=p){
			now++;
			if(now>=w[thisk]){
				now-=w[thisk];
				if(thisk+1==k){
					return true;
					break;
				}
				thisk++;
			}
		}else{
			now=0;
		}
	}
	return false;
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
	}
	maxheigh++;
	{/*solve*/
		while(maxheigh-minheigh>1){
			UINT now=(maxheigh+minheigh+1)/2;
			//cout<<maxheigh<<","<<minheigh<<","<<now;
			if(solver(now)){
				minheigh=now;
				//cout<<",t\n";
			}else{
				maxheigh=now;
				//cout<<",f\n";
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

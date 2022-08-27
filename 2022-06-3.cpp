/*
[Q]https://zerojudge.tw/ShowProblem?problemid=i401
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
#define pii pair<INT,INT>
#define INT int
#define UINT unsigned INT

/*struct*/

/*num*/
const maxx=30000
UINT n;
vector<pii> px[maxx+5],py[maxx*2+10];
INT minx,miny,bigx,bigy;

/*fn*/
/*
定義角度
0=上面
1=右邊
2=下面
3=左邊
*/
INT arr(INT fromarr,INT mirarr){
	if(mirarr){
		return (fromarr-1+4)%4;
	}else{
		return (fromarr+1)%4;
	}
}
INT finder(INT arr,INT x,INT y){/*找出距離最近的鏡子*/
	switch(arr){
		{case 0:
			INT it=0;
			INT maxcango=px[x].size();
			while((maxcango-it) && (px[x][it]).first<=y)it++;
			if(maxcango-it){
				return maxcango;
			}else{
				return px[x].size();
			}
		break;}

		{case 1:
			INT it=0;
			INT maxcango=py[y].size();
			while((maxcango-it) && (py[y][it]).first<=x)it++;
			if(maxcango-it){
				return maxcango;
			}else{
				return py[y].size();
			}
		break;}

		{case 2:
			INT maxcango=px[x].size()-1;
			while((maxcango+1) && (px[x][maxcango]).first>=y)maxcango--;
			if(maxcango+1){
				return maxcango;
			}else{
				return px[x].size();
			}
		break;}

		{case 3:
			INT maxcango=py[y].size()-1;
			while((maxcango+1) && (py[y][maxcango]).first>=x)maxcango--;
			if(maxcango+1){
				return maxcango;
			}else{
				return py[y].size();
			}
		break;}
	}
}

/*main*/
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n;
	for(UINT i=0;i<n;i++){
		INT x,y,t;
		cin>>x>>y>>t;
		y+=maxx;
		(px[x]).push_back({y,t});
		(py[y]).push_back({x,t});
		if(i){
			minx=min(x,minx);
			miny=min(y,miny);
			bigx=max(x,bigx);
			bigy=max(y,bigy);
		}
	}
	for(INT i=minx;i<=bigx;i++){
		sort((px[i]).begin(),(px[i]).end());
	}
	for{INT i=miny;i<=bigy;i++}{
		sort((py[i]).begin(),(py[i]).end());
	}
	INT nowx=0,nowy=0,nowarr=1,ans=0;
	while(true){

	}
	return 0;
}

/*
[I1]
10
2 0 1
2 -1 1
7 -1 0
7 2 1
4 2 0
4 1 0
3 1 1
3 2 0
1 -1 1
1 4 0
[O1]
4
2 1 0
5 -3 1
4 2 1
6 -2 0
*/

/*think*/
/*

*/

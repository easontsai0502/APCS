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
#define plli pair<lli,lli>
#define pulli pair<ulli,ulli>
#define INT lli
#define UINT unsigned INT
#define pii pair<INT,INT>

/*struct*/

/*num*/
const INT maxx=30000;
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

/*main*/
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	
	{/*處理輸入*/
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
			}else{
				minx=x;
				miny=y;
				bigx=x;
				bigy=y;
			}
		}
		for(INT i=minx;i<=bigx;i++){
			sort((px[i]).begin(),(px[i]).end());
		}
		for(INT i=miny;i<=bigy;i++){
			sort((py[i]).begin(),(py[i]).end());
		}
	}
	/*solve*/
	INT nowx=0,nowy=maxx,nowarr=1,ans=0;
	while(true){
		switch(nowarr){
			{case 0:
				auto it=upper_bound((px[nowx]).begin(),(px[nowx]).end(),{nowy,1});
				if(it=px[nowx].end()) break;
				nowy=(*it).first;
				if((*it).second)nowarr=3;
				else nowarr=1;
			break;}
			{case 1:
				auto it=upper_bound((py[nowy]).begin(),(py[nowy]).end(),{nowx,1});
				if(it=py[nowy].end()) break;
				nowx=(*it).first;
				if((*it).second)nowarr=2;
				else nowarr=0;
			break;}
			{case 2:
				auto it=lower_bound((px[nowx]).begin(),(px[nowx]).end(),{nowy,0});
				if(it=px[nowx].begin()) break;
				nowy=(*it).first;
				if((*it).second)nowarr=1;
				else nowarr=3;
			break;}
			{case 3:
				auto it=lower_bound((py[nowy]).begin(),(py[nowy]).end(),{nowx,0});
				if(it=py[nowy].begin()) break;
				nowx=(*it).first;
				if((*it).second)nowarr=0;
				else nowarr=2;
			break;}
		}
	}
	cout<<ans;
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
9
*/

/*think*/
/*

*/

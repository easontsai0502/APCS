/*
[Q]https://zerojudge.tw/ShowProblem?problemid=i402
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
#define INT lli
#define UINT unsigned INT
#define pii pair<INT,INT>

/*struct*/

/*num*/
const UINT maxnm=1000;
UINT n,m;
INT a[maxnm+1],b[maxnm+1],br[maxnm+1],ans;
/*fn*/
void solver(INT x,INT y){
	INT now=0;
	while(x<n && y<m){
		now+=a[x]*b[y];
		ans=max(now,ans);
		now=max((INT)0,now);
		x++;
		y++;
	}
}
void solverbr(INT x,INT y){
	INT now=0;
	while(x<n && y<m){
		now+=a[x]*br[y];
		ans=max(now,ans);
		now=max((INT)0,now);
		x++;
		y++;
	}
}

/*main*/
int main(){
	{/*IO 加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	{/*CIN*/
		cin>>n>>m;
		for(INT i=0;i<n;i++){
			cin>>a[i];
		}
		for(INT i=0;i<m;i++){
			cin>>b[i];
			br[m-i-1]=b[i];
		}
	}
	ans=a[0]*b[0];//ans初始化
	{/*solve*/
		for(INT i=0;i<n;i++){
			solver(i,(INT)0);
			solverbr(i,(INT)0);
		}
		for(INT i=0;i<m;i++){
			solver((INT)0,i);
			solverbr((INT)0,i);
		}
	}
	cout<<ans;
	return 0;
}

/*
[I1]
5 5
-3 -3 3 3 -3
2 2 2 2 2
[O1]
12
[I2]
5 5
-3 -3 -3 5 -5
-5 5 -3 -3 -3
[O2]
77
[I3]
4 3
1 2 3 4
-1 -2 -3
[O3]
-1
*/

/*think*/
/*

*/

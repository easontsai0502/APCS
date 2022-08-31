/*
[Q]https://zerojudge.tw/ShowProblem?problemid=g597
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
#define ULLI unsigned long long int
#define LLI long long int
#define INT LLI
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>

/*struct*/

/*num*/
const UINT nmmax=200000;
INT n,m;
INT w[nmmax+1],t[nmmax+1],l[nmmax+1],r[nmmax+1];
INT addlist[nmmax+2];
INT worklist[nmmax+1];
INT rmax,lmin;
//n為機器數
//m為任務數
//t為機器i的cd時間 [1~m]
//l為工作的l [1~m]
//r為工作的r [1~m]
//w為該任務所需資料數 [1~m]
//addlist為數的增減表 [1~m+1]
//worklist為該座標的任務數 [1~n]

/*fn*/
bool stob(INT a,INT b){
	return a<b;
}
bool btos(INT a,INT b){
	return a>b;
}

/*main*/
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	{/*CIN*/
		cin>>n>>m;
		for(INT i=1;i<=m;i++){
			cin>>l[i]>>r[i]>>w[i];
			addlist[l[i]]+=w[i];
			addlist[r[i]+1]-=w[i];
			rmax=max(rmax,r[i]);
		}
		INT now=0;
		for(INT i=1;i<=rmax;i++){
			now+=addlist[i];
			worklist[i]=now;
		}
		sort(worklist+1,worklist+rmax+1,btos);
		for(INT i=1;i<=n;i++){
			cin>>t[i];
		}
		sort(t+1,t+n+1,stob);
	}
	INT ans=0;
	{/*solve*/
		for(int i=1;i<=rmax;i++){
			ans+=worklist[i]*t[i];
		}
	}
	cout<<ans;
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

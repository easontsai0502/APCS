/*
[Q]https://zerojudge.tw/ShowProblem?problemid=f608
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
#define INT int
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>

/*struct*/

/*fn宣告*/

/*num*/
const UINT maxn=2e5;
const UINT maxxy=1e7;
UINT n;
UINT x[maxn+1],y[maxn+1],a[maxn+1];
/*fn定義*/
bool cc(UINT a,UINT b){
	if(x[a]!=x[b])return x[a]<x[b];//優先往右走
	return y[a]<y[b];
}

/*main*/
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	{/*CIN*/
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>x[i]>>y[i];
			a[i]=i;
		}
	}
	{/*solve*/
		sort(a,a+n,cc);
		vector<UINT> yvec;
		for(UINT i=0;i<n;i++){
			UINT nowy=y[a[i]];
			if(yvec.empty() || nowy>=yvec.back())yvec.push_back(nowy);
			else{
				vector<UINT>::iterator it=upper_bound(yvec.begin(),yvec.end(),nowy);//找尋比他大的數字(若有n個數字比他大，則找這其中最小的)，並替換成此數
				yvec[it-yvec.begin()]=nowy;
			}
		}
		cout<<yvec.size();
	}
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*
a[]為排序後的順序
排序規則為：
先排x的，x座標一樣在排y
所以能得到
(0,0)
(1,0)
(0,1)
(1,1)
*/

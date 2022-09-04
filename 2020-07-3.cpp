/*
[Q]https://zerojudge.tw/ShowProblem?problemid=f581
[09/20]AC
[11/20]WA
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

/*fn宣告*/

/*num*/
const UINT maxn=200000;
const UINT maxm=20000;
UINT n,m;
UINT p[maxn*2+1],q[maxm+1];
UINT ptt[maxn+1];
UINT now;
/*fn定義*/

/*main*/
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	{/*CIN*/
		cin>>n>>m;
		for(UINT i=1;i<=n;i++){
			cin>>p[i];
			p[i+n]=p[i];
			ptt[i]=ptt[i-1]+p[i];
		}
		for(UINT i=1;i<=n;i++){
			ptt[i+n]=ptt[i+n-1]+p[i];
		}
		for(UINT i=1;i<=m;i++){
			cin>>q[i];
			q[i]=q[i]%ptt[n];
		}
	}
	{/*solve*/
		now=1;
		for(UINT i=1;i<=m;i++){
			UINT l=now-1,r=now+n;
			while(r-l>1){
				UINT lr2=(l+r)/2;
				if(ptt[lr2]-ptt[now-1]>q[i]){
					r=lr2;
				}else if(ptt[lr2]-ptt[now-1]==q[i]){
					r=lr2;
					break;
				}else{
					l=lr2;
				}
			}
			now=r+1;
			while(now>n)now-=n;
		}
	}
	cout<<now-1;
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

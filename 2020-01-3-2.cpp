/*
[Q]https://judge.tcirc.tw/ShowProblem?problemid=d030
[AC]
[Q]https://zerojudge.tw/ShowProblem?problemid=h028
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
#include<stack>

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
const UINT nmax=1e5;
UINT N,L;
INT C[nmax+5];
INT H[nmax+5];
//資料結構如下
//{座標,高度}
/*fn定義*/

/*main*/
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	{/*CIN*/
		cin>>N>>L;
		for(UINT i=1;i<=N;i++){
			cin>>C[i];
		}
		for(UINT i=1;i<=N;i++){
			cin>>H[i];
	}
	}
	C[0]=0;
	H[0]=2e9;
	C[N+1]=L;
	H[N+1]=2e9;
	stack<UINT> stk;
	stk.push(0);
	INT ans=0,mx=0;
	{
		for(UINT i=1;i<=N;i++){
			while(C[stk.top()]+H[stk.top()]<=C[i]){//part a 清理i左方的樹
				//看i左邊的樹會不會壓倒i，壓不倒就把那棵樹砍了
				//假如有這些樹(i=5)
				//***.*
				//假設3砍倒不會壓到5
				//那就把3砍倒，讓5往左砍的時候有更多空間
				//
				ans++;
				mx=max(mx,H[stk.top()]);
				stk.pop();
			}
			if(C[stk.top()]<=C[i]-H[i] || C[i]+H[i]<=C[i+1]){//i樹能倒的話就倒
				//向左倒                                      向右倒
				ans++;
				mx=max(mx,H[i]);
			}else{//倒不了的話就加入worklist
				stk.push(i);
				//代表這棵樹無法倒下，加入名單
				//worklist為記錄第i棵樹左邊的樹(尚未倒的樹)
			}
		}
		while(C[stk.top()]+H[stk.top()]<L){
			//part a 清理邊界左方的樹
			ans++;
			mx=max(mx,H[stk.top()]);
			stk.pop();
		}
	}
	cout<<ans<<"\n";
	cout<<mx;
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

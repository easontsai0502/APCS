/*
[Q]https://zerojudge.tw/ShowProblem?problemid=f581
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

/*fn宣告*/

/*num*/
const UINT maxn=200000;
const UINT maxm=20000;
INT n,m;
INT p[maxn+5];
vector<INT> pre;
INT total;
INT now;
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
		for(UINT i=0;i<n;i++){
			cin>>p[i];
			total+=p[i];
			pre.push_back(total);
		}
	}
	{/*solve*/
		for(UINT i=0;i<m;i++){
			INT q;
			cin>>q;
			if(now){
				q+=pre[now-1];
			}
			/*概念說明
			假設現在不在原點
			---[-]----
			而數字會這樣走
			--- = ==...
			所以我們把前面的補起來
			就會變成這樣
			=== = ==...
			希望這樣你們看得懂
			雖然好像只有我在看
			*/
			while(q>pre[n-1]) q-=pre[n-1];
			now=(int)(lower_bound(pre.begin(),pre.end(),q)-pre.begin())+1;
			/*概念說明
			這就是在找第一個大於q的傢伙的位置(R)，最後再-L+1(取距離公式)
			*/
			now%=n;
		}
	}	
	cout<<now;
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

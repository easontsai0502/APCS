/*
[Q]https://judge.tcirc.tw/ShowProblem?problemid=d075
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
#include<stack>
#include<cstring>
#include<unordered_map>

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
INT m;
INT n;
INT s;
INT f[105];
INT dp[105];
/*fn定義*/
bool sorter(INT a,INT b){
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
		cin>>n>>m>>s;
		INT lass=m;
		for(INT i=1;i<=n;i++){
			cin>>f[i];
			lass-=f[i];
		}
		sort(f+1,f+n+1,sorter);
		s-=lass;
	}
	{/*solve*/
		for(int i=1;i<=n;i++){
			if(dp[i-1]+f[i]>s){//叫他滾，會產生無用空格，就不叫他滾
				dp[i]=dp[i-1];
			}else if(dp[i-1]+f[i]==s){
				cout<<s;
				return 0;
				break;
			}else{//如果叫他滾，位子還不夠
				dp[i]=dp[i-1]+f[i];
			}
		}
		cout<<dp[n]+f[n];
	}
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

/*
[Q]https://zerojudge.tw/ShowProblem?problemid=f314
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
const UINT maxm=50;
const UINT maxn=1e4;
INT ma[maxm+5][maxn+5];
INT dp[maxm+5][maxn+5];
INT n,m;

INT nowline[maxn+5];
//往下走
//從上面走到現在這格

INT goright[maxn+5];
//往右走
//從左邊走到這格

INT goleft[maxn+5];
//往左走
//從右邊走到這格
/*fn定義*/

/*main*/
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	{/*CIN*/
		cin>>m>>n;
		for(INT i=1;i<=m;i++){
			for(INT j=1;j<=n;j++){
				cin>>ma[i][j];
			}
		}
	}
	INT ans=0;
	{/*solve*/
		for(INT i=1;i<=m;i++){
			//go down
			for(int j=1;j<=n;j++){
					nowline[j]=dp[i-1][j]+ma[i][j];
			}
			//go right
			for(int j=1;j<=n;j++){
				goright[j]=max(nowline[j],goright[j-1]+ma[i][j]);
			}
			//go left
			for(int j=n;j>=0;j--){
				goleft[j]=max(nowline[j],goleft[j+1]+ma[i][j]);
			}
			//find ans
			//將答案加入dp
			for(int j=1;j<=n;j++){
				dp[i][j]=max(nowline[j],max(goright[j],goleft[j]));
			}
			//清空
			for(int j=1;j<=n;j++){
				nowline[j]=goright[j]=goleft[j]=0;
			}
		}
		//尋找答案
		for(int j=1;j<=n;j++){
			ans=max(ans,dp[m][j]);
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

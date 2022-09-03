/*
[Q]https://zerojudge.tw/ShowProblem?problemid=g278
[10/20]AC
[10/20]RE
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
const INT maxn=1e6;
INT n,k;
//n為攤位數
//k為人數
INT a[maxn+1];
//a為攤位的食物
INT maxlef[maxn+1];
//maxlef為在i攤位最多可以連續往左吃到哪
//例如maxlef[3]=1代表官員可以連續從1吃到3

/*fn定義*/

/*main*/
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	INT canl=0;
	{/*CIN*/
		cin>>n>>k;
		for(INT i=0;i<n;i++){
			cin>>a[i];
			while(canl<i && count(a+canl,a+i-1,a[i]))canl++;
			maxlef[i]=canl;
		}
	}
	INT dp[k][n];
	INT ans=0;
	{/*solve*/
		for(INT i=0;i<k;i++){//人的for迴圈
			for(INT j=0;j<n;j++){//食物的for迴圈
				INT nowmax=0;
				for(INT nowl=maxlef[j];nowl<=j;nowl++){
					INT thi=j-nowl+1;
					if(i-1>=0 && nowl-1>=0){
						thi+=dp[i-1][nowl-1];
					}
					nowmax=max(thi,nowmax);
				}
				dp[i][j]=nowmax;
				if(j-1>0){
					dp[i][j]=max(nowmax,dp[i][j-1]);
				}
				ans=max(nowmax,ans);
			}
		}
	}
	cout<<ans;
	return 0;
}

/*
[I1]
5 1
1 2 1 3 1
[O1]
3
[I2]
10 3
1 7 1 3 1 4 4 2 7 4
[O2]
8
*/

/*think*/
/*
10 3
1 7 1 3 1 4 4 2 7 4
1 2 2 3 2 3 1 2 3 3
1 2 2 3 3 3 3 3 3 3
1 2 3 4 4 5 5 5 6 6
1 2 3 4 5 6 6 7 8 8

*/

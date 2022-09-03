/*
[Q]https://zerojudge.tw/ShowProblem?problemid=f314
[14/20]AC
[06/20]WA
[00]AC
[01]AC
[02]AC
[03]AC
[04]  WA
[05]  WA
[06]  WA
[07]AC
[08]  WA
[09]  WA
[10]AC
[11]AC
[12]AC
[13]AC
[14]AC
[15]AC
[16]  WA
[17]AC
[18]AC
[19]AC
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
INT goright[maxn+5];
INT goleft[maxn+5];
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
		for(INT i=0;i<m;i++){
			for(INT j=0;j<n;j++){
				cin>>ma[i][j];
			}
		}
	}
	INT ans=0;
	{/*solve*/
		for(INT i=0;i<m;i++){
			//go down
			if(i==0){
				for(int j=0;j<n;j++){
					nowline[j]=ma[i][j];
				}
			}else{
				for(int j=0;j<n;j++){
					nowline[j]=dp[i-1][j]+ma[i][j];
				}
			}
			//go right
			for(int j=1;j<n;j++){
				if(j==1){
					goright[j]=max(nowline[j],nowline[j-1]+ma[i][j]);
				}else{
					goright[j]=max(nowline[j],goright[j-1]+ma[i][j]);
				}
			}
			//go left
			for(int j=n-1;j>0;j--){
				if(j==n-1){
					goleft[j]=max(nowline[j],nowline[j+1]+ma[i][j]);
				}else{
					goleft[j]=max(nowline[j],goleft[j+1]+ma[i][j]);
				}
			}
			//find ans
			for(int j=0;j<n;j++){
				dp[i][j]=max(nowline[j],max(goright[j],goleft[j]));
			}
		}
		for(int j=0;j<n;j++){
			nowline[j]=goright[j]=goleft[j]=0;
		}
		for(int j=0;j<n;j++){
			if(j==0)ans=dp[m-1][j];
			else ans=max(ans,dp[m-1][j]);
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

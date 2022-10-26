/*
[Q]https://zerojudge.tw/ShowProblem?problemid=j125
[AC]
*/

/*include*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O1")
#pragma GCC optimize("O3")
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
#define what_the_fuck cin.tie(0);cout.tie(0);ios::sync_with_stdio(false)
#define ULLI unsigned long long int
#define LLI long long int
#define INT int
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
#define endl "\n"
#define wassomething() empty()==false

/*struct*/
/*fn宣告*/
/*num*/
bool debug=false;
bool iofast=true;
/*fn定義*/
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast)what_the_fuck;
	/*CIN*/
	INT n;
	cin>>n;
	INT mp[n+1][n+1];
	PII dp[n+1][n+1];
	bool dpdo[n+1][n+1];
	for(INT i=0;i<=n;i++){
		for(INT j=0;j<=n;j++){
			dp[i][j]={0,0};
			dpdo[i][j]=false;
			mp[i][j]=0;
			if(i&&j)cin>>mp[i][j];
		}
	}
	/*solve*/
	INT mx[]={0,1,0,-1};
	INT my[]={1,0,-1,0};
	deque<PII> bls;
	bls.push_back({1,1});
	while(bls.wassomething()){
		PII np=bls.front();
		bls.pop_front();
		INT &x=np.first;
		INT &y=np.second;
		PII &nowdp=dp[x][y];
		if(debug)cout<<x<<","<<y<<endl;
		for(INT i=0;i<4;i++){
			INT nx=x+mx[i];
			INT ny=y+my[i];
			if(debug)cout<<" "<<nx<<","<<ny<<endl;
			if(nx<=0||ny<=0||nx>n||ny>n)continue;
			INT fr=max(abs(mp[x][y]-mp[nx][ny]),nowdp.first);
			PII nextdp={fr,nowdp.second+1};
			if(!dpdo[nx][ny]||dp[nx][ny]>nextdp){
				dpdo[nx][ny]=true;
				dp[nx][ny]=nextdp;
				bls.push_back({nx,ny});
			}
		}
	}
	if(debug){
		cout<<endl;
		for(INT i=0;i<=n;i++){
			for(INT j=0;j<=n;j++){
				cout<<dp[i][j].first<<","<<dp[i][j].second<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	cout<<dp[n][n].first<<endl<<dp[n][n].second<<endl;
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

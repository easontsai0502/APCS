/*
[Q]https://zerojudge.tw/ShowProblem?problemid=g278
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
INT dp[2][1000000+1];
INT n,k;
bool debug=false;
//n攤位數
//k人數
INT a[1000000+1];
//a攤位項目
bool waseat[100000+1];
INT caneat[1000000+1];
/*fn定義*/
INT getmaxline(INT n){
	INT i=0;
	for(INT j=1;j<=n;j++){
		while(waseat[a[j]] && i+1<j){
			i++;
			waseat[a[i]]=false;
		}
		waseat[a[j]]=true;
		caneat[j]=j-i;
	}
	return 0;
}
INT solve(INT n,INT k){
	getmaxline(n);
	for(INT i=1;i<=k;i++){
		for(INT j=1;j<=n;j++){
			dp[i%2][j]=max(dp[(i+1)%2][j-caneat[j]]+caneat[j],dp[i%2][j-1]);
		}
	}
	return dp[k%2][n];
}
void debugger(INT n,INT k){
	for(INT i=1;i<=n;i++){
		cout<<caneat[i]<<",";
	}
	cout<<"\n";
	cout<<"\n";
	for(INT i=1;i<=k;i++){
		for(INT j=1;j<=n;j++){
			cout<<dp[i][j]<<",";
		}
		cout<<"\n";
	}
	cout<<"\n";
}
/*main*/
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	/*CIN*/
	cin>>n>>k;
	for(INT i=1;i<=n;i++){
		cin>>a[i];
	}
	/*solve*/
	cout<<solve(n,k)<<"\n";
	if(debug)debugger(n,k);
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

*/

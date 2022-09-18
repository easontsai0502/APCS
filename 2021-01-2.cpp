/*
[Q]https://zerojudge.tw/ShowProblem?problemid=f606
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
int pay(int n){
	if(n<=1000){
		return 3*n;
	}else{
		return 1000+2*n;
	}
}
/*fn定義*/

/*main*/
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	int n,m,k;
	cin>>n>>m>>k;
	int q[n][m];
	int datato[m][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>q[i][j];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			datato[i][j]=0;
		}
	}
	int ans=0;
	for(int doo=0;doo<k;doo++){
		int severp[n];
		for(int i=0;i<n;i++){
			cin>>severp[i];
			for(int j=0;j<m;j++){
				datato[severp[i]][j]+=q[i][j];
			}
		}
		int now=0;
		for(int i=0;i<m;i++){
			for(int j=0;j<m;j++){
				if(i==j){
					now+=datato[i][j];
				}else{
					now+=pay(datato[i][j]);
				}
				//cout<<datato[i][j]<<" ";//debug
				datato[i][j]=0;
			}
			//cout<<"\n";//debug
		}
		if(doo){
			ans=min(now,ans);
		}else{
			ans=now;
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

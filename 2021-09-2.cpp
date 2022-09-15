/*
[Q]https://zerojudge.tw/ShowProblem?problemid=g276
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
int ma[105][105];
bool boom[105][105];
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
	int r[k];
	int c[k];
	int s[k];
	int t[k];
	bool dieking[k];
	for(int i=0;i<k;i++){
		cin>>r[i];
		cin>>c[i];
		cin>>s[i];
		cin>>t[i];
		dieking[i]=false;
	}
	int kleft=k;
	while(kleft){
		for(int i=0;i<k;i++){
			if(dieking[i]==false){
				//install boomber
				ma[r[i]][c[i]]++;
			}
		}
		for(int i=0;i<k;i++){
			if(dieking[i]==false){
				//move
				r[i]+=s[i];
				c[i]+=t[i];
				if(r[i]>=n || c[i]>=m || r[i]<0 || c[i]<0){
					//kill if he walk out map
					kleft--;
					dieking[i]=true;
				}else if(ma[r[i]][c[i]]){
					//kill if he touch boomber
					dieking[i]=true;
					kleft--;
					boom[r[i]][c[i]]=true;
				}
			}
		}
		//boom the boomer
		for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++){
				if(boom[i][j]){
					ma[i][j]=0;
					boom[i][j]=false;
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			ans+=(ma[i][j]>0);
		}
	}
	cout<<ans;
	return 0;
}

/*
[I1]
1 6 3
0 0 0 0
0 2 0 -1
0 4 0 2
[O1]
4
[I2]
5 5 2
0 0 3 2
0 0 2 3
[O2]
3
*/

/*think*/
/*

*/

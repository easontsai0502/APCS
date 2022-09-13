/*
[Q]https://zerojudge.tw/ShowProblem?problemid=h081
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

/*fn定義*/

/*main*/
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	int n,d;
	cin>>n>>d;
	int coinlist[n];
	for(int i=0;i<n;i++){
		cin>>coinlist[i];
	}
	LLI ans=0;
	int nowhave=coinlist[0];
	bool have=true;
	for(int i=1;i<n;i++){
		if(have){
			if(coinlist[i]>=nowhave+d){
				ans+=coinlist[i]-nowhave;
				nowhave=coinlist[i];
				have=false;
			}
		}else{
			if(coinlist[i]<=nowhave-d){
				nowhave=coinlist[i];
				have=true;
			}
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

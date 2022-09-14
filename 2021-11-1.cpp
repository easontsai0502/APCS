/*
[Q]https://zerojudge.tw/ShowProblem?problemid=g595
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
	int n;
	cin>>n;
	int alist[n+1];
	alist[0]=10000;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>alist[i];
		if(alist[i-1]==0){
			ans+=min(alist[i-2],alist[i]);
		}
	}
	if(alist[n]==0){
		ans+=alist[n-1];
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

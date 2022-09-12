/*
[Q]https://zerojudge.tw/ShowProblem?problemid=i399
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
	int a[4];
	for(int i=0;i<3;i++){
		cin>>a[i];
	}
	a[3]=87;
	sort(a,a+3);
	int cc=1;
	if(a[0]==a[1] || a[1]==a[2])cc=2;
	if(a[0]==a[1] && a[1]==a[2])cc=3;
	cout<<cc<<" ";
	for(int i=2;i>=0;i--){
		if(a[i]==a[i+1])continue;
		else cout<<a[i]<<" ";
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

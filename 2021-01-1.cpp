/*
[Q]https://zerojudge.tw/ShowProblem?problemid=f605
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
	int counter=0;
	int ans=0;
	while(n--){
		int a,b,c;
		cin>>a>>b>>c;
		if(max(a,max(b,c))-min(a,min(b,c))>=d){
			ans+=(a+b+c)/3;
			counter++;
		}
	}
	cout<<counter<<" "<<ans;
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

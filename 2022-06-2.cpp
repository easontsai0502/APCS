/*
[Q]https://zerojudge.tw/ShowProblem?problemid=i400
[WA]
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
INT m,n;
INT tf[105][105];
bool doswap[105];
/*fn定義*/

/*main*/
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	cin>>n>>m;
	for(INT i=0;i<n;i++){
		string str;
		cin>>str;
		INT cou=0;
		for(int j=0;j<m;j++){
			cou+=str[j]-'0';
			tf[i][j]=str[j]-'0';
		}
		doswap[i]=(cou%2==1);
	}
	string S="",T="";
	cin>>T;
	for(int i=n-1;i>=0;i--){
		S="";
		for(int j=n-1;j>=0;j--){
			if(tf[i][j]){
				S+=S+T[j];
			}else{
				S+=T[j]+S;
			}
		}
		if(doswap[i]){
			if(m%2){
				S=S.substr(m/2+1,m/2)+S.substr(m/2,1)+S.substr(0,m/2);
			}else{
				S=S.substr(m/2,m/2)+S.substr(0,m/2);
			}
		}
		T=S;
	}
	cout<<T;
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

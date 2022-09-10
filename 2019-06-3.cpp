/*
[Q]https://zerojudge.tw/ShowProblem?problemid=e288
[]
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

/*using namespace*/
using namespace std;

/*define type*/
#define ULLI unsigned long long int
#define LLI long long int
#define INT int
#define INT1 LLI
#define INT2 int
#define UINT unsigned int
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>

/*struct*/

/*fn宣告*/

/*num*/
INT m, n, l, a[38], ans;
long long mask, tmp;
string s;
map <INT1, INT> mp;
/*fn定義*/
INT flag(char c){
	if(c<='Z')return c-'A';
	else return c-'a'+26;
}
INT1 buildstr(string str){
	bool findlist[38]={false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false};
	for(INT i=0;i<str.size();i++){
		findlist[flag(str[i])]=true;
	}
	INT1 re=0;
	for(INT i=0;i<38;i++){
		if(findlist[i]){
			re+=1<<i;
		}
	}
}
/*main*/
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	while(cin>>m>>n){
		{/*CIN*/
			mp.clear();
			ans=0;
			mask=0;
			for(INT1 i=0;i<m;i++){
				mask|=(1LL<<i);//1LL=1(type=long long)
			}
		}
		{/*solve*/

		}
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

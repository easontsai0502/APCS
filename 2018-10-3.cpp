/*
[Q]
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
string s;
INT n;
INT p;
/*fn定義*/
INT solve(INT x){
	INT re=0;
	if(s[p]=='2'){
		p++;
		int runtime=4;
		while(runtime--){
			re+=solve(x/2);
		}
		return re;
	}else{
		if(s[p]=='1'){
			p++;
			return x*x;
		}
	}
	p++;
	return 0;
}
/*main*/
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	{/*CIN*/
		cin>>s;
		cin>>n;
	}
	{/*solve*/
		cout<<solve(n);
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

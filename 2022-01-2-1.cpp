/*
[Q]https://zerojudge.tw/ShowProblem?problemid=h082
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
#define INT LLI
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
	INT n,m;
	cin>>n>>m;
	INT s[n];
	INT t[n];
	INT live[n];
	vector<INT> v,win,los;
	v.clear();
	win.clear();
	los.clear();
	for(INT i=0;i<n;i++){
		cin>>s[i];
		live[i]=m;
	}
	for(INT i=0;i<n;i++){
		cin>>t[i];
	}
	INT idx;
	for(INT i=0;i<n;i++){
		cin>>idx;
		idx--;
		v.push_back(idx);
	}
	while(v.size()>1){
		for(INT i=0;i<=v.size()-2;i+=2){
			INT x=v[i],y=v[i+1];
			INT a=s[x];
			INT b=t[x];
			INT c=s[y];
			INT d=t[y];
			if(a*b>=c*d){
				s[x] = a + c*d/(2*b);
				t[x] = b + c*d/(2*a);
				s[y] = c + c/2;
				t[y] = d + d/2;
				win.push_back(x);
				live[y]--;
				if(live[y]>0)los.push_back(y);
			}else{
				s[y]=c+a*b/(2*d);
				t[y]=d+a*b/(2*c);
				s[x]=a+a/2;
				t[x]=b+b/2;
				win.push_back(y);
				live[x]--;
				if(live[x]>0)los.push_back(x);
			}
		}
		if(v.size()%2){win.push_back(v.back());}
		v=win;
		for(INT i:los)v.push_back(i);
		win.clear();
		los.clear();
	}
	cout<<v[0]+1;
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

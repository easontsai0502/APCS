/*
[Q]
[]
*/

/*include*/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<sstream>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<stack>

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
const INT maxn=1e6;
INT n,p,l,r;
INT s[maxn+1];
INT step[maxn+1];
deque<INT> todo;
//n為節點數(節點編號0~(n-1))
//p為目的地
//l為一次左移幾格
//r為一次右移幾格

//
/*fn定義*/

/*main*/
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	{/*CIN*/
		cin>>n>>p>>l>>r;
		for(int i=0;i<n;i++){
			cin>>s[i];
			if(s[i]<0 || s[i]>=n)s[i]=n;
		}
	}
	todo.push_back(0);
	memset(step, -1, sizeof(step));
	step[0]=0;
	{/*solve*/
		while(todo.size()){
			INT i=todo.front();
			todo.pop_front();
			INT nxt;
			nxt=i-l;
			if(0<=nxt && s[nxt]!=n && step[s[nxt]]==-1){
				step[s[nxt]]=step[i]+1;
				todo.push_back(s[nxt]);
			}
			nxt=i+r;
			if(nxt<n && s[nxt]!=n && step[s[nxt]]==-1){
				step[s[nxt]]=step[i]+1;
				todo.push_back(s[nxt]);
			}
		}
	}
	cout<<step[p];
	return 0;
}

/*
[I1]
5 3 1 2
0 3 2 3 5
[O1]
2
[I2]
10 8 2 3
0 5 2 3 4 5 6 6 8 9
[O2]
3
*/

/*think*/
/*

*/

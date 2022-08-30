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

/*num*/
const UINT nmmax=20000;
const UINT pmax=10000;
UINT n,m,p,k;
//n,m,p,k為題目給的變數
//n為人數
//m為pair數
//p為調查員人數
//k為調查員查到的pair數
vector<PUIUI> mainlist,otherlist[pmax+1];
//mainlist為組長傭有的pair
//otherlist[i]為調查員i所提供的pair
int flag[nmmax+1];
//flag為每個人的旗子
vector<UINT> now[nmmax+1];
//now為每個人的連結(就是樹)

/*fn*/
bool dfs(UINT n,UINT las){
	for(UINT i:now[n]){
		if(i==las){continue;}
		if(!flag[i]){//若此人未分組，幫她分組
			flag[i]=3-flag[n];//若a在1，將b分到2，反之...
			if(!dfs(i,n))return false;
		}else{//若這個人被分過組
			if(flag[i]==flag[n]){//檢測是否同組
				return false;
			}
		}
	}
}
bool checker(UINT n){
	for(int i=0;i<n;i++){//初始化變數
		now[i].clear();
		flag[i]=0;
	}
	for(auto i:mainlist){//將mainlist的資訊存入now(圖)
		now[i.first].push_back(i.second);
		now[i.second].push_back(i.first);
	}
	for(int i=0;i<n;i++){
		
	}
}

/*main*/
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	{/*CIN*/
		cin>>n>>m;
		for(UINT i=0;i<m;i++){
			UINT pa,pb;
			cin>>pa>>pb;
			mainlist.push_back({pa,pb});
		}
		cin>>p>>k;
		for(int i=0;i<p;i++){
			for(int j=0;j<k;j++){
				UINT pa,pb;
				cin>>pa>>pb;
				otherlist[i].push_back({pa,pb});
			}
		}
	}
	{/*solve*/
		UINT l=0,r=p;
		for(int i=0;i<3;i++){//題目說1~3個，所以找3次就好了
			while(r-l>1){//使用二分搜找出有問題的那幾個
				UINT nowp=(r+l)/2;
			}
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

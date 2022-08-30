/*
[Q]https://zerojudge.tw/ShowProblem?problemid=g598
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
bool dfs(UINT x,UINT las){
	for(UINT i:now[x]){
		if(i==las){continue;}
		if(!flag[i]){//若此人未分組，幫她分組
			flag[i]=3-flag[x];//若a在1，將b分到2，反之...
			if(!dfs(i,x))return false;
		}else{//若這個人被分過組
			if(flag[i]==flag[x]){//檢測是否同組
				return false;
			}
		}
	}
	return true;//偌多通過，回傳true
}
bool checker(UINT x){
	for(int i=0;i<n;i++){//初始化變數
		now[i].clear();
		flag[i]=0;
	}
	for(auto i:mainlist){//將mainlist的資訊存入now(圖)
		now[i.first].push_back(i.second);
		now[i.second].push_back(i.first);
	}
	for(int i=1;i<=x;i++){//將1~x的資料存入now(池化快塞)
		for(auto j:otherlist[i]){
			now[j.first].push_back(j.second);
			now[j.second].push_back(j.first);
		}
	}
	for(int i=0;i<n;i++){//dfs
		if(!flag[i]){//若他還沒分組，就讓她分
			flag[i]=1;
			if(!dfs(i,i))return false;//若該結果產生矛盾，回傳false
		}
	}
	return true;//若都通過，回傳true
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
		for(int i=1;i<=p;i++){
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
				if(checker(nowp)) l=nowp;//沒問題就往右找
				else r=nowp;//有問題就往左找
			}//因為如果是正確的data會是原data，所以所有正確的data丟進去都不會矛盾
			cout<<r<<"\n";
			otherlist[r].clear();//清除錯誤
			l=r;//從錯誤處開始往右找
			r=p;
			if(checker(p))break;//如果錯誤都清掉了就可以離開了
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

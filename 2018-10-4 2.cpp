/*
[Q]https://judge.tcirc.tw/ShowProblem?problemid=d075
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
INT m;
//m為格子數
INT n;
//n為客戶數
INT s;
//s為自己需要用的數量
INT x;
//x為該客戶的需求
INT dp[2][200005];
/*fn定義*/
/*main*/
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	cin>>n>>m>>s;
	INT lass=m;
	INT sum=0,idx=0;
	for(INT i=0;i<n;i++){
		cin>>x;
		sum+=x;//sum代表所有客戶的需求
		idx=i%2;
		for(int j=0;j<=m-s;j++){//m-s代表自己先把自己要的格子幹走
			//j為客戶可利用的格子數(dp)
			if(j<x){//如果該客戶需求過大
				dp[idx^1][j]=dp[idx][j];//那就不讓你用
				//idx^1為目前的dp列，idx為上一個的dp列
				//idx=1 idx^1=0
			}else{
				dp[idx^1][j]=max(dp[idx][j],dp[idx][j-x]+x);
				//dp[idx][j-x]+x為將該客戶的東西塞進去
			}
		}
		//則sum-dp就是損失(dp為客戶存進去的格子(收益))
		//該dp為計算老闆把他要的格子用完後，剩下的格子有幾格能被幹走
	}
	cout<<sum-dp[idx^1][m-s];
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

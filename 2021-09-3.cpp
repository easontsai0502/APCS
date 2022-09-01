/*
[Q]https://zerojudge.tw/ShowProblem?problemid=g277
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
const UINT nmax=3e5;
UINT n,a[nmax+1];
//n為a的數量
//a為輸入數值 [1~n]
UINT att[nmax+1];
//att[i]為a[i]之前(含i)的所有數的總和 [1~n]
UINT L,R;
//L和R就是題目裡的L,R
vector<PUIUI> se;
//se為一清單，由小到大
//格式如下
//{num,address}

/*fn定義*/
bool stobpui(PUIUI a,PUIUI b){
	return a.first>b.first;
}

/*main*/
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	{/*CIN*/
		cin>>n;
		for(UINT i=1;i<=n;i++){
			cin>>a[i];
			att[i]=att[i-1]+a[i];
			se.push_back({a[i],i});
		}
		R=n;
		L=1;
	}
	sort(se.begin(),se.end(),stobpui);
	{/*solve*/
		while(L!=R){
			while((se.back()).second<L || (se.back()).second>R)se.pop_back();
			UINT center=(se.back()).second;
			if(center==L){
				L++;
			}else if(center==R){
				R--;
			}else{
				UINT LL=L,LR=center-1,RL=center+1,RR=R;
				UINT LTT,RTT;
				LTT=att[LR]-att[LL-1];
				RTT=att[RR]-att[RL-1];
				if(LTT>RTT){
					L=LL;
					R=LR;
				}else{
					L=RL;
					R=RR;
				}
			}
		}
	}
	cout<<a[L];
	return 0;
}

/*
[I1]
5
4 2 3 1 5
[O1]
4
[I2]
8
3 9 4 5 1 6 2 8
[O2]
9
*/

/*think*/
/*

*/

/*
[Q]https://zerojudge.tw/ShowProblem?problemid=g596
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

/*control*/
bool debug_mod=false;
/*num*/
const int maxn=105;
int ma[maxn][maxn];
int m,n;
int movex[]={0,1,0,-1};//上右下左
int movey[]={1,0,-1,0};//上右下左
/*fn定義*/
void debugger(string str){
	if(debug_mod){
		cout<<str<<"\n";
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(ma[i][j]==-1){cout<<"#";continue;}
				cout<<ma[i][j];
			}
			cout<<"\n";
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
	int h;
	cin>>m>>n>>h;
	debugger("original");
	int r,c,t;
	int mx=0;
	int now=0;
	while(h--){
		cin>>r>>c>>t;
		//拆線先
		for(int i=0;i<4;i++){
			int nowx=r+movex[i];
			int nowy=c+movey[i];
			bool isfind=false;
			while(nowx>=0 && nowx<m && nowy>=0 && nowy<0){
				if(ma[nowx][nowy]==0){
					//沒線
					break;
				}
				if(ma[nowx][nowy]==-1){
					//找到柱子
					isfind=true;
					break;
				}
				nowx+=movex[i];
				nowy+=movey[i];
			}
			if(isfind){
				//拆x軸
				for(int j=min(r,nowx)+1;j<max(r,nowx);j++){
					ma[j][nowy]--;
				}
				//拆y軸
				for(int j=min(c,nowy)+1;j<max(c,nowy);j++){
					ma[nowx][j]--;
				}
			}
		}
		//拆完後再組裝
		if(t==0){//add
			ma[r][c]=-1;
			//組線
			for(int i=0;i<4;i++){
				int nowx=r+movex[i];
				int nowy=c+movey[i];
				bool isfind=false;
				while(nowx>=0 && nowx<m && nowy>=0 && nowy<0){
					if(ma[nowx][nowy]==-1){
						//找到柱子
						isfind=true;
						break;
					}
					nowx+=movex[i];
					nowy+=movey[i];
				}
				if(isfind){
					//組裝x軸
					for(int j=min(r,nowx)+1;j<max(r,nowx);j++){
						ma[j][nowy]++;
					}
					//組裝y軸
					for(int j=min(c,nowy)+1;j<max(c,nowy);j++){
						ma[nowx][j]++;
					}
				}
			}
			debugger("remove");
		}else{
			ma[r][c]=0;
			debugger("remove");
		}

		now=0;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
					now+=(ma[i][j]!=0);
			}
		}
		mx=max(mx,now);
	}
	cout<<mx<<"\n";
	cout<<now<<"\n";
	return 0;
}

/*
[I1]
3 5 6
0 0 0
0 2 0
2 2 0
2 0 0
2 4 0
2 2 1
[O1]
10
6
[I2]
5 5 7
2 2 0
2 4 0
4 4 0
4 0 0
0 3 0
4 3 0
4 3 1
[O2]
12
7
*/

/*think*/
/*

*/

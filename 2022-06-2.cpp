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
	string str;
	cin>>str;
	for(int i=0;i<n;i++){
		deque<char> de;
		for(int j=m-1;j>=0;j--){
			if(tf[i][j]){
				de.push_back(str[j]);
			}else{
				de.push_front(str[j]);
			}
		}
		for(int j=0;j<n;j++){
			str[j]=de.front();
			de.pop_front();
		}
		if(doswap[i]){
			int adda=m%2;
			int he=m/2;
			for(int j=0;j<he;j++){
				swap(str[j],str[j+he+adda]);
			}
		}
	}
	cout<<str;
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

/*
[Q]https://zerojudge.tw/ShowProblem?problemid=g275
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
#define INT int
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>

/*struct*/

/*fn宣告*/

/*num*/

/*fn定義*/

/*main*/
int main() {
	{/*IO加速*/
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	}
	int n;
	cin>>n;
	while (n--) {
		int l[2][7];
		bool waserr=false;
		bool aerr=false;
		bool berr=false;
		bool cerr=false;
		for (int i=0;i<2;i++) {
			for (int j=0;j<7;j++) {
				cin>>l[i][j];
				}
			}
		int& a=l[0][1], & b=l[0][3], & c=l[0][5], & d=l[1][1], & e=l[1][3], & f=l[1][5];
		if (a==b||b==c||d==e||e==f){
			aerr=true;
			waserr=true;
		}
		if (l[0][6]!=1||l[1][6]!=0){
			berr=true;
			waserr=true;
		}
		if (a==d||b==e||c==f) {
			cerr=true;
			waserr=true;
		}
		if(waserr){
			if(aerr){
				cout<<"A";
			}
			if(berr){
				cout<<"B";
			}
			if(cerr){
				cout<<"C";
			}
		}else{
			cout<<"None";
		}
		cout<<"\n";
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

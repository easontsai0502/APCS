/*
[Q]https://zerojudge.tw/ShowProblem?problemid=i401
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
#define ulli unsigned long long int
#define lli long long int
#define pii pair<int,int>
#define plli pair<lli,lli>
#define pulli pair<ulli,ulli>
#define INT int
#define UINT unsigned INT

/*struct*/

/*num*/
UINT n;

/*fn*/
/*
定義角度
0=上面
1=右邊
2=下面
3=左邊
*/
int arr(int fromarr,int mirarr){
	if(mirarr){
		return (fromarr-1+4)%4;
	}else{
		return (fromarr+1)%4;
	}
}

/*main*/
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
		cin>>n;
	return 0;
}

/*
[I1]
10
2 0 1
2 -1 1
7 -1 0
7 2 1
4 2 0
4 1 0
3 1 1
3 2 0
1 -1 1
1 4 0
[O1]
4
2 1 0
5 -3 1
4 2 1
6 -2 0
*/

/*think*/
/*

*/

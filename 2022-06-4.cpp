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
#define ulli unsigned long long int
#define lli long long int
#define INT int
#define UINT unsigned INT
#define pii pair<INT,INT>

/*struct*/

/*num*/
const UINT maxnm=1000;
UINT n,m;
INT a[maxnm+1],b[maxnm+1],br[maxnm+1],ans;
/*fn*/
void solver(INT x,INT y){

}

void solverbr(INT x,INT y){

}

/*main*/
int main(){
	{/*IO 加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	{/*CIN*/
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<m;i++){
			cin>>b[i];
			br[i]=b[m-i-1];
		}
	}
	ans=a[0]*b[0];
	{/*solve*/
		for(int i=0;i<n;i++){
			solver(i,0);
			solverbr(i,0);
		}
		for(int i=0;i<m;i++){
			solver(0,i);
			solverbr(0,i);
		}
	}
	cout<<ans;
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

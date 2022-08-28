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
UINT m;
set<string> st;
map<UINT,string> slist;
/*fn*/

/*main*/
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	{/*CIN*/
		cin>>m;
		for(int i=0;i<m;i++){
			cin>>slist[i];
			st.insert(slist[i]);
		}
	}
	UINT ans=0;
	{/*solve*/
		for(int i=0;i<m;i++){
			int l=slist[i].length();
			if(l<3)continue;
			for(int j=1;j<=l/2;j++){
				/*
				string.substr(開始位置(int),長度(int)):複製字串
				*/
				string frontastr=(slist[i]).substr(0,j);
				string backastr=(slist[i]).substr(l-j,j);
				if(frontastr==backastr){
					string bstr=(slist[i]).substr(j,l-j-j);
					if(st.count(bstr)){
						ans++;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

/*
[I1]
3
a
aba
aaa
[O1]
1
[I2]
5
abyyyab
y
yy
yyy
yyyy
[O2]
3
*/

/*think*/
/*

*/

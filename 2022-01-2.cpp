/*
[Q]https://zerojudge.tw/ShowProblem?problemid=h082
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

/*num*/

/*fn定義*/

/*main*/
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	int n,m;
	cin>>n>>m;
	int s[n];
	int t[n];
	int idx[n];
	int live[n];
	for(int i=0;i<n;i++){
		cin>>s[i];
		live[i]=m;
	}
	for(int i=0;i<n;i++){
		cin>>t[i];
	}
	for(int i=0;i<n;i++){
		cin>>idx[i];
		idx[i]--;
	}
	vector<PII> ssort;
	vector<PII> tsort;
	vector<int> playerline;
	for(int i=0;i<n;i++){
		PII a;
		a.first=idx[i];
		a.second=s[i];
		ssort.push_back(a);
		
		a.second=t[i];
		tsort.push_back(a);
		playerline.push_back(i);
	}
	sort(ssort.begin(),ssort.end());
	sort(tsort.begin(),tsort.end());
	while(playerline.size()>1){
		vector<int> winner,loser;
		int i=0;
		while(playerline.size()>=2){
			int a=ssort[playerline[i]].second;
			int b=tsort[playerline[i]].second;
			int c=ssort[playerline[i+1]].second;
			int d=tsort[playerline[i+1]].second;
			if(a*b>=c*d){
				ssort[playerline[i]].second=a+c*d/(2*b);
				tsort[playerline[i]].second=b+c*d/(2*a);
				ssort[playerline[i+1]].second=c+c/2;
				tsort[playerline[i+1]].second=d+d/2;
				live[playerline[i+1]]--;
				winner.push_back(playerline[i]);
				if(live[playerline[i+1]]){
					loser.push_back(playerline[i+1]);
				}
			}else{
				ssort[playerline[i]].second=a+a/2;
				tsort[playerline[i]].second=b+b/2;
				ssort[playerline[i+1]].second=c+a*b/(2*d);
				tsort[playerline[i+1]].second=d+a*b/(2*c);
				live[playerline[i]]--;
				winner.push_back(playerline[i+1]);
				if(live[playerline[i]]){
					loser.push_back(playerline[i]);
				}
			}
			playerline.erase(playerline.begin());
			playerline.erase(playerline.begin());
		}
		playerline.insert(playerline.begin(),winner.begin(),winner.end());
		playerline.insert(playerline.end(),loser.begin(),loser.end());
	}
	cout<<playerline[0]+1;
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

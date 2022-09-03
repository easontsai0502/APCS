/*
[Q]https://zerojudge.tw/ShowProblem?problemid=f607
[AC]
*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
using namespace std;
#define ulli unsigned long long int
int main(){
	ulli n,l;
	cin>>n>>l;
	map<ulli,ulli> cutlist;
	for(ulli i=0;i<n;i++){
		ulli x,ii;
		cin>>x>>ii;
		cutlist[ii]=x;
	}
	set<ulli> loglist;
	loglist.insert(0);
	loglist.insert(l);
	ulli prize=0;
	for(ulli i=1;i<=n;i++){
		loglist.insert(cutlist[i]);
		set<ulli>::iterator it=loglist.lower_bound(cutlist[i]);
		prize+=*next(it)-*prev(it);
		
	}
	cout<<prize;
	return 0;
}


/*
[I1]
3 7
2 2
3 1
5 3
[O1]
14
*/
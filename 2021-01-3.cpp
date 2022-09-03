/*
[Q]https://zerojudge.tw/ShowProblem?problemid=f607
[AC]
*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int main(){
	int n,l;
	cin>>n>>l;
	map<int,int> cutlist;
	for(int i=0;i<n;i++){
		int x,ii;
		cin>>x>>ii;
		cutlist[ii]=x;
	}
	vector<int> loglist;
	loglist.push_back(0);
	loglist.push_back(l);
	int prize=0;
	for(int i=1;i<=n;i++){
		int lef=0,rig=0;
		vector<int>::iterator it;
		for(int j=0;j<i;j++){
			if(loglist[j]<cutlist[i]){
				lef=loglist[j];
				rig=loglist[j+1];
				it=loglist.begin()+j+1;
			}else{break;}
		}
		prize+=rig-lef;
		loglist.insert(it,cutlist[i]);
		
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
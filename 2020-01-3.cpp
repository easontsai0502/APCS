/*
[Q]https://judge.tcirc.tw/ShowProblem?problemid=d030
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

/*fn宣告*/

/*num*/
const UINT nmax=1e5;
UINT n,l;
UINT treep[nmax+1];
UINT treeh[nmax+1];
//資料結構如下
//{座標,高度}
/*fn定義*/

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
			cin>>treep[i];
		}
		for(UINT i=1;i<=n;i++){
			cin>>treeh[i];
		}
	}
	treep[0]=0;
	treeh[0]=2e9;
	treep[n+1]=l;
	treeh[n+1]=2e9;
	deque<UINT> worklist;
	worklist.push_back(0);
	UINT anscount=0,anshigh=0;
	{/*solve*/
		/*for(UINT i=1;i<=n;i++){
			UINT lair=treep[i]-treep[i-1];
			UINT rair=treep[i+1]-treep[i];
			if(treeh[i]==0)continue;
			if(lair>=treeh[i] || rair>=treeh[i]){
				anscount++;
				anshigh=max(anshigh,treeh[i]);
				treeh[i]=0;
				//將左邊的樹木加入worklist
				UINT addl=i-1;
				while(treeh[addl]==0 && addl>0){
					addl--;
				}
				if(addl>0){
					worklist.push_back(addl);
				}
				//將右邊的樹木加入worklist
				UINT addr=i+1;
				while(treeh[addr]==0 && addr<=n){
					addr++;
				}
				if(addr<=n){
					worklist.push_back(addr);
				}
			}
		}
		while(worklist.size()){
			UINT i=worklist.front();
			worklist.pop_front();
			UINT lair=treep[i]-treep[i-1];
			UINT rair=treep[i+1]-treep[i];
			if(treeh[i]==0)continue;
			if(lair>=treeh[i] || rair>=treeh[i]){
				anscount++;
				anshigh=max(anshigh,treeh[i]);
				treeh[i]=0;
				//將左邊的樹木加入worklist
				UINT addl=i-1;
				while(treeh[addl]==0 && addl>0){
					addl--;
				}
				if(addl>0){
					worklist.push_back(addl);
				}
				//將右邊的樹木加入worklist
				UINT addr=i+1;
				while(treeh[addr]==0 && addr<=n){
					addr++;
				}
				if(addr<=n){
					worklist.push_back(addr);
				}
			}
		}*/
		for(UINT i=1;i<=n;i++){
			while(treep[worklist.back()]+treeh[worklist.back()]<=treep[i]){//part a 清理i左方的樹
				//看i左邊的樹會不會壓倒i，壓不倒就把那棵樹砍了
				//假如有這些樹(i=5)
				//***.*
				//假設3砍倒不會壓到5
				//那就把3砍倒，讓5往左砍的時候有更多空間
				//
				anscount++;
				anshigh=max(anshigh,treeh[worklist.back()]);
				worklist.pop_front();
			}
			if(treep[worklist.back()]<=treep[i]-treeh[i] || treep[i]+treeh[i]<=treep[i+1]){//i樹能倒的話就倒
				//向左倒                                      向右倒
				anscount++;
				anshigh=max(anshigh,treeh[i]);
			}else{//倒不了的話就加入worklist
				worklist.push_back(i);
				//代表這棵樹無法倒下，加入名單
				//worklist為記錄第i棵樹左邊的樹(尚未倒的樹)
			}
		}
		while(treep[worklist.back()]+treeh[worklist.back()]<l){
			//part a 清理邊界左方的樹
			anscount++;
			anshigh=max(anshigh,treeh[worklist.back()]);
			worklist.pop_front();
		}
	}
	cout<<anscount<<"\n";
	cout<<anshigh;
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

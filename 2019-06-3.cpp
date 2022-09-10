/* 
[Q]https://zerojudge.tw/ShowProblem?problemid=e288 
[17/20]AC
[1/20]TLE
[2/20]Unknow
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
 
/*using namespace*/ 
using namespace std; 
 
/*define type*/ 
#define ULLI unsigned long long int 
#define LLI long long int 
#define INT int 
#define INT1 LLI 
#define INT2 int 
#define UINT unsigned int 
#define PII pair<INT,INT> 
#define PUIUI pair<UINT,UINT> 
 
/*struct*/ 
 
/*fn宣告*/ 
 
/*num*/ 
INT m, n, l, ans; 
long long mask, tmp; 
string s; 
map <INT1, INT> mp; 
/*fn定義*/ 
INT flag(char c){//將文字轉譯成數字
	if(c<='Z')return c-'A'; 
	else return c-'a'+26; 
} 
INT1 buildstr(string str){//將手中卡牌轉換成一個編號
//編號為二進制
//假如第1位是1代表該代碼傭有第一張牌
	bool findlist[38]={false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false}; 
	for(INT i=0;i<str.size();i++){ 
		findlist[flag(str[i])]=true; 
	} 
	INT1 re=0; 
	for(INT i=0;i<38;i++){ 
		if(findlist[i]){ 
			re+=1LL<<i; 
		} 
	}
	return re;
} 
/*main*/ 
int main(){ 
	{/*IO加速*/ 
		cin.tie(0); 
		cout.tie(0); 
		ios::sync_with_stdio(false); 
	} 
	while(cin>>m>>n){
		//歸0
		mp.clear(); 
		ans=0; 
		mask=0; 
		for(INT1 i=0;i<m;i++){ 
			mask|=(1LL<<i);//1LL=1(type=long long) 
		}
		//ans
		for(int i=0;i<n;i++){
			cin>>s;
			INT1 nowfind=buildstr(s);//獲取傭有卡片代碼
			if(mp.count(nowfind^mask))ans+=mp[nowfind^mask];//如果有人和她可以互補，ans++
			mp[nowfind]++;//將自己加入map中
		}
		cout<<ans<<"\n";
	} 
	return 0; 
} 
 
/* 
[I1] 
[O1] 
*/ 
 
/*think*/ 
/* 
這裡整理一下題目的意思
有一群人，那群人有一堆排
而一個set的定義為
	兩個人的牌都不一樣
	兩個人的牌湊起來後剛好能收集到所有牌
這個就是xor的概念
如果兩值不同，代表只有一方是1，代表只有一個人有該張卡，記1
如果兩值相同，代表兩個人都有卡，獲大家都沒該卡，記0
而一個set要所有牌都只有一張
(我知道你想說甚麼，一個人裡面，AAAAA，我們也算他只有一張A)
假如這次只有五張牌
那我們就是要讓兩個人的xor的值如下
card abcde
     11111
而我們要盡可能找出越多組11111
雖然這上傳到zj不會過，但是如果是APCS的化是能過的
*/
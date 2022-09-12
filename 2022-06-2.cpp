/*
[Q]https://zerojudge.tw/ShowProblem?problemid=i400
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
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	int n,m;
	cin>>n>>m;
	string e[n];
	for(INT i=0;i<n;i++){
		cin>>e[i];
	}
	string S="",T="";
	cin>>T;
	for(int i=n-1;i>=0;i--){
		INT cnt=0;
		S="";
		for(int j=m-1;j>=0;j--){
			if(e[i][j]=='1'){
				S=S+T[j];
				cnt=1-cnt;
			}else{
				S=T[j]+S;
			}
		}
		//cout<<S<<"\n";
		if(cnt){
			if(m%2){
				S=S.substr(m/2+1,m/2)+S.substr(m/2,1)+S.substr(0,m/2);
			}else{
				S=S.substr(m/2,m/2)+S.substr(0,m/2);
			}
		}
		T=S;
		//cout<<S<<"\n";
	}
	cout<<T;
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*
注意一下
題目要你解密，非加密
上面的表格是加密過程
我們要倒者走
給提示把
<~~據透警告~~>



<~~提示開始~~>
e=1
在加密時，代表把S最後一個字加到T最後面
解密則相反，把T最後面的字移到S後面
e=0
解密時，把T最後面的字移到S前面

甚麼，還要提示
凡內
<~~據透警告~~>



<~~提示開始~~>
使用string

假設
a="a"
b="def"
c=a+b
則c="a"+"def"="adef"
這樣就可以把"a"插入到b的後面了
阿，好**(布渴椅瑟澀)

蝦，WA？
好吧，再給提示
<~~據透警告~~>



<~~提示開始~~>
加密時是由上往下加密
那解密則是由下往上
所以for迴圈要寫相反歐
*/

#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 30000;
// vx[i]: x 座標為 i 的鏡子，依照 y 座標排序。
// vy[i]: y 座標為 i 的鏡子，依照 x 座標排序。
vector <pair<int, int> > vx[maxn+5], vy[maxn*2+5];
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0, x, y, t; i < n; i++){
        cin >> x >> y >> t;
        y += maxn;
        vx[x].push_back({y, t});
        vy[y].push_back({x, t});
    }
    for (int i = 1; i <= maxn; i++) sort(vx[i].begin(), vx[i].end());
    for (int i = 0; i <= maxn*2; i++) sort(vy[i].begin(), vy[i].end());
 
    int x = 0, y = maxn, d = 1;
    int cnt = 0;
    while (1){
        if (d == 0){
            auto it = upper_bound(vx[x].begin(), vx[x].end(), make_pair(y, 1));
            if (it == vx[x].end()) break;
            y = (*it).first;
            if ((*it).second == 1) d = 3;
            else d = 1;
        }
        if (d == 1){
            auto it = upper_bound(vy[y].begin(), vy[y].end(), make_pair(x, 1));
            if (it == vy[y].end()) break;
            x = (*it).first;
            if ((*it).second == 1) d = 2;
            else d = 0;
        }
        if (d == 2){
            auto it = lower_bound(vx[x].begin(), vx[x].end(), make_pair(y, 0));
            if (it == vx[x].begin()) break;
            it--;
            y = (*it).first;
            if ((*it).second == 1) d = 1;
            else d = 3;
        }
        if (d == 3){
            auto it = lower_bound(vy[y].begin(), vy[y].end(), make_pair(x, 0));
            if (it == vy[y].begin()) break;
            it--;
            x = (*it).first;
            if ((*it).second == 1) d = 0;
            else d = 2;
        }
        cnt++;
    }
    cout << cnt << "\n";
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
9
*/

/*think*/
/*

*/


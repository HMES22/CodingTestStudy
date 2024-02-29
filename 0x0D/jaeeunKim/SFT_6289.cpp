#include<iostream>
#include<vector>
using namespace std;
/*
        SFT Lv3 "우물 안 개구리"
        https://softeer.ai/practice/6289
*/

int n,m;
vector<int> arr;
vector<bool> chk;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    chk.assign(n+1, true);
    arr.assign(n+1, 0);
    for(int i = 1; i<=n; i++){
        cin >>arr[i];
    }
    int t1 ,t2;
    for(int i = 0; i< m; i++){
        cin >> t1 >> t2;
        auto res = (arr[t1] > arr[t2]);
        auto res1 = (arr[t1] < arr[t2]);
        chk[t1] = chk[t1] && res;
        chk[t2] = chk[t2] && res1;
    }
    int ans = 0;
    for(int i = 1; i<=n; i++)
        if(chk[i]) ans++;
    cout << ans;
        
   return 0;
}
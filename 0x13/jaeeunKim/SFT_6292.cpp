#include <iostream>
using namespace std;
/*
        SFT Lv3 "수퍼 바이러스"
        https://softeer.ai/practice/6292
*/
using ll = long long;
ll n, p ,k;
ll d = 1'000'000'007;
ll ans = 1;

ll solve(ll tn){
    if(tn == 1) return p%d;
    ll num = solve(tn/2);
    num = (((num % d) * (num % d)) % d);
    if(tn % 2 == 0){
        return (num % d);
    }
    else return ( ((num % d) * (p % d))  % d);
}
int main(int argc, char** argv)
{
    cin >> k >> p >> n;
    cout << ((k % d) * (solve(10*n) % d) % d);
   return 0;
}
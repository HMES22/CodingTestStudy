#include <iostream>
#include <algorithm>
using namespace std;
/*
    BOJ 2750 수 정렬하기
    https://www.acmicpc.net/problem/2750
*/
int n;
int arr[1001];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i< n; i++)
        cin >> arr[i];
    sort(arr, arr+n);
    for(int i = 0; i<n; i++)
        cout << arr[i] << '\n';
	return 0;
}
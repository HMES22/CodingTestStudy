#include <iostream>
using namespace std;
/*
    BOJ 11728 배열 합치기
    https://www.acmicpc.net/problem/11728
    Mergeeeeeeeeeeeee
*/
int n, m;
int arr1[1'000'001];
int arr2[1'000'001];
int res[2'000'002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    for (int i = 0; i < m; i++)
        cin >> arr2[i];
    int aidx = 0, bidx = 0, ridx = 0;
    while (1) {
        if (ridx == n + m) break;
        if (aidx == n) res[ridx++] = arr2[bidx++];
        else if (bidx == m) res[ridx++] = arr1[aidx++];
        else if (arr1[aidx] < arr2[bidx]) res[ridx++] = arr1[aidx++];
        else res[ridx++] = arr2[bidx++];
    }
    for (int i = 0; i < n + m; i++)
        cout << res[i] << ' ';
}
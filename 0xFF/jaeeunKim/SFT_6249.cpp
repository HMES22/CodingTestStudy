#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

/*
        SFT Lv3 "좋은 염기서열"
        https://softeer.ai/practice/6249
*/
int n, m;
string arr[21];
string sDNA[65537];
int ans[65537];

string merge(string str1,string str2){
    string res(m,'.');
    if(str1.length() == 0 || str2.length() == 0){
        return string();
    }
    for(int i = 0; i < m; i++){
        if(str1[i] == '.')
            res[i] = str2[i];
        else if(str2[i] == '.')
            res[i] = str1[i];
        else if(str1[i] == str2[i])
            res[i] = str1[i];           
        else 
            return string();
    }
    return res;
}

void genSuperDNA(int index){
    int loc = 0;
    int tidx = index;
    while(tidx % 2 == 0){
        loc++;
        tidx = tidx / 2;
    }
    sDNA[index] = merge(arr[loc], sDNA[index-(1<<loc)]);
}

int genAnswer(int index){
    if(ans[index] < n+1){ // 이미 최소값 갱신이 되었다면 return
        return ans[index];
    }
    vector<int> bits;
    int tidx = index;
    for(int i = 0; i< n; i++){
        if(tidx % 2 == 1)
            bits.push_back(i);
        tidx /= 2;
    }
    int num, temp;
    int blen = bits.size();
    for(int i = 1; i<1<<(blen-1); i++){
        int ti = i;
        num = 0;
        for(int j = 0; j < blen; j++){
            num += (1 << bits[j]) * (ti % 2);
            ti /= 2;
        }
        temp = genAnswer(num) + genAnswer(index-num);
        if(temp < ans[index])
            ans[index] = temp;
    }
    return ans[index];
}
int main(int argc, char** argv)
{
    cin >> n >> m;
    for(int i = 0; i< n; i++)
        cin >> arr[i];
    sDNA[0] = string(m, '.');
    for(int i = 1; i< (1 << n); i++)
        genSuperDNA(i);
    fill(ans, ans + (1<<n), n+1); // 최대 n개 생기니까 최대값 n+1 로 초기화
    ans[0] = 0;
    for(int i = 1; i<(1<<n); i++){
        if(sDNA[i].length() > 0)
            ans[i] = 1;
        else
            genAnswer(i);
    }
    cout << '\n' << ans[(1<<n)-1];
    return 0;
}
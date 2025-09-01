#include <bits/stdc++.h>
using namespace std;

bool func2(int arr[], int N){
    int occur[101] = {};
    for(int i=0; i<N; ++i){
        if(occur[100-arr[i]]==1) return 1;
        occur[arr[i]] = 1;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[N]={...};
    cout << func2(arr[], N);

    return 0;
}
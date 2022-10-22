#include<iostream>
#include<vector>
using namespace std;


int main(){
    int N;
    cin >> N;

    vector<long long> A(N+1);
    for(int i=1;i<=N;i++){
        cin >> A[i];
    }

    vector<vector<long long>> dp(N+1,vector<long long>(2,0));

    for(int i=1;i<=N;i++){
        dp[i][0]= dp[i-1][1]+A[i];
        dp[i][1]= max(dp[i-1][0],dp[i-1][1]);
    }

    cout << max(dp[N][0],dp[N][1]) << endl;
}
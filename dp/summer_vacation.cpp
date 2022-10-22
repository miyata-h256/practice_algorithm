#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<vector<int>> abc(N+1,vector<int>(3));

    for(int i=1;i<=N;i++) cin >> abc[i][0] >> abc[i][1] >> abc[i][2];

    vector<vector<int>> dp(N+1,vector<int>(3,0));
    for(int i=1;i<=N;i++){
        
        dp[i][0] = max(dp[i-1][1],dp[i-1][2])+abc[i][0];
        dp[i][1] = max(dp[i-1][0],dp[i-1][2])+abc[i][1];
        dp[i][2] = max(dp[i-1][0],dp[i-1][1])+abc[i][2];
    }

    cout << max(dp[N][2],max(dp[N][0],dp[N][1])) << endl;
    return 0;    
}
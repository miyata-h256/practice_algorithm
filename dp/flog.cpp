#include<iostream>
using namespace std;

const int INF = 1 << 29;

int main(){
    int N;
    cin >> N;
    int h[N];
    for(int i=0;i<N;i++) cin >> h[i];

    int dp[N] = {INF};


    dp[0] = 0;
    for(int i=1;i<N;i++){
        if(i==1){
            dp[i] = abs(h[i]-h[i-1]);
        }else{
            dp[i] = min(dp[i-1]+abs(h[i]-h[i-1]),dp[i-2]+abs(h[i]-h[i-2]));
        }
    }

    cout << dp[N-1] << endl;

    return 0;
}

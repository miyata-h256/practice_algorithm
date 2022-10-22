#include<iostream>
#include<vector>
using namespace std;

const long long INF = 1LL << 29;

template<class T> void chmin(T& a,T b){
    if(a>b) a=b;
}

int main(){
    int N;
    cin >> N;
    vector<vector<long long>> c(N+1,vector<long long>(N+1));

    for(int i=0;i<N+1;i++){
        for(int j=0;j<N+1;j++){
            cin >> c[i][j];
        }
    }

    vector<long long> memo(N+1,INF);

    memo[0] = 0;

    for(int i=0;i<=N;i++){
        for(int j=0;j<i;j++){
            chmin(memo[i],memo[j]+c[j][i]);
        }
    }

    cout << memo[N] << endl;
    return 0;
}
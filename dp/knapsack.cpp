#include<iostream>
#include<vector>
using namespace std;

template<class T> void chmax(T& a,T b){
    if(a < b){
        a = b;
    }
}

int main(){
    int N,W;
    cin >> N >> W;

    long long weight[N];
    long long value[N];

    for(int i=0;i<N;i++){
        cin >> weight[i] >> value[i];
    }

    long long memo[N+1][W+1] = {};

    for(int i=0;i<N;i++){
        for(int j=0;j<=W;j++){
            if(j-weight[i] >= 0){
                chmax(memo[i+1][j],memo[i][j-weight[i]]+value[i]);
            }
            
            chmax(memo[i+1][j],memo[i][j]);
               
        }
    }

    for(int i=0;i<N+1;i++){
        for(int j=0;j<W+1;j++){
            printf("%3d",memo[i][j]);
        }
        putchar('\n');
    }

    cout << memo[N][W] << endl;
    return 0;
}

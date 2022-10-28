#include<iostream>
#include<vector>
using namespace std;

template<class T> void chmax(T& a,T b){
    if(a<b){
        a = b;
    }
}

int main(){
    int N;long long W;
    cin >> N >> W;
    long long value[N];
    long long weight[N];
    for(int i=0;i<N;i++) cin >> weight[i] >> value[i];

    vector<vector<long long>> map(N+1,vector<long long>(W+1,0));

    for(int i=0;i<N;i++){
        for(int w=0;w<=W;w++){
            if(w-weight[i] >=0){
                chmax(map[i+1][w],map[i][w-weight[i]]+value[i]);
            }

            chmax(map[i+1][w],map[i][w]);
        }
    }

    cout << map[N][W] << endl;
    return 0;
}
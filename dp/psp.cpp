#include<iostream>
using namespace std;

int main(){
    int N,W;
    cin >> N >> W;
    
    int a[N];
    for(int i=0;i<N;i++) cin >> a[i];

    bool memo[N+1][W+1]={false};

    for(int i=0;i<N;i++) memo[i][0] = true;

    for(int i=0;i<=N;i++){
        for(int w=1;w<=W;w++){
            if(w - a[i] >= 0){
                memo[i+1][w] = memo[i+1][w] | memo[i+1][w-a[i]];
            }

            memo[i+1][w] = memo[i+1][w] | memo[i][w];

        }
    }

    if(memo[N][W]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
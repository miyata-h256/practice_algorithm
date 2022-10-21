#include<iostream>
#include<vector>

using namespace std;

const int INF = 1<<29;

template<class T> void chmin(T& a,T b){
    if(a > b){
        a = b;
    }
}

int main(){
    string S,T;
    cin >> S >> T;

    vector<vector<int>> memo(S.size()+1,vector<int>(T.size()+1,INF));

    //init condition
    memo[0][0] = 0;

    for(int i=0;i<=S.size();i++){
        for(int j=0;j<=T.size();j++){
            if(i>0 && j>0){
                if(S[i-1]==T[j-1]){
                    chmin(memo[i][j],memo[i-1][j-1]);
                }else{
                    chmin(memo[i][j],memo[i-1][j-1]+1);
                }
            }
            if(i>0){
                chmin(memo[i][j],memo[i-1][j]+1);
            }
            if(j>0){
                chmin(memo[i][j],memo[i][j-1]+1);
            }
        }
    }

    cout << memo[S.size()][T.size()] << endl;

    return 0;
}
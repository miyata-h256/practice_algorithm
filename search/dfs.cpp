#include<iostream>
#include<vector>
using namespace std;
using Graph = vector<vector<int>>;

//DFS(Depth First Search)
vector<bool> seen;
void dfs(const Graph &G,int v){
    seen[v] = true;//vを訪問済みにする

    //vから行ける各頂点v_nextについて
    for(auto next_v :G[v]){
        if(seen[next_v]) continue;//探索済みならば探索しない

        dfs(G,next_v);//再帰的に探索
    }
}

int main(){
    //頂点数と辺数
    int V,E;
    cin >> V >> E;

    //グラフ入力受け取り(ここでは有向グラフを想定)
    Graph G(V);
    for(int i=0;i<E;i++){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    seen.assign(V,false);
    for(int v=0;v<V;v++){
        if(seen[v]) continue;
        dfs(G,v);
    }
}
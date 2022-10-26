#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using Graph = vector<vector<int>>;

//入力:グラフGと、探索の始点s
//出力:sから各頂点への最短路長を表す配列
vector<int> BFS(const Graph &G,int s){
    int N = (int) G.size();//頂点数
    vector<int> dist(N,-1);
    queue<int> que;

    //初期条件(頂点0を初期頂点とする)
    dist[s] = 0;
    que.push(s);

    //BFS開始(キューが空になるまで探索を行う)
    while(!que.empty()){
        int v = que.front();//キューから先頭頂点を取り出す
        que.pop();

        //vからたどれる頂点をすべて調べる
        for(int x:G[v]){
            if(dist[x]!=-1) continue;

            dist[x] = dist[v]+1;//未開拓の点xについて距離情報を更新してキューに挿入
            que.push(x);
        }
    }

    return dist;
}

int main(){
    int N,M;
    cin >> N >> M;

    //グラフ入力受け取り(ここでは無向グラフを想定)
    Graph G(N);
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    //頂点0を始点としたBFS
    vector<int> dist = BFS(G,0);

    for(int v=0;v<N;v++) cout << v << ":" << dist[v] << endl;
}
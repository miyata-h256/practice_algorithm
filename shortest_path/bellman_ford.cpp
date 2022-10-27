#include<iostream>
#include<vector>
using namespace std;

const long long INF = 1LL << 60;

struct Edge{
    int to;//隣接頂点番号
    long long w;//辺の重み
    Edge(int to,long long w) :to(to) , w(w){}
};

using Graph =vector<vector<Edge>>;

template<class T> bool chmin(T& a,T b){
    if(a>b){
        a = b;
        return true;
    }else{
        return false;
    }
}


int main(){
    int N,M,s;
    cin >> N >> M >> s;

    //グラフ作成部分
    Graph G(N);
    for(int i=0;i<M;i++){
        int a,b,w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b,w));
    }

    //Bellman-Ford法
    bool exist_negative_cycle = false;//負閉路の有無
    vector<long long> dist(N,INF);
    dist[s] = 0;
    for(int iter=0;iter<N;iter++){
        bool update = false;//更新が発生したかどうか
        for(int v=0;v<N;v++){
            //dist[v]=INFのときは頂点vからの緩和を行わない
            if(dist[v]==INF) continue;

            for(auto e : G[v]){
                if(chmin(dist[e.to],dist[v]+e.w)){
                    update=true;
                }
            }
        }

        //更新が行われなかったらすでに最短路が求められている
        if(!update) break;

        //N回目の反復で更新が行われたならば、負閉路を持つ
        if(iter == N-1 && update) exist_negative_cycle = true;
    }

    if(exist_negative_cycle) cout << "NEGATIVE CYCLE" << endl;
    else{
        for(int v=0;v<N;v++){
            if(dist[v] < INF) cout << dist[v] << endl;
            else cout << "INF" << endl;
        }
    }
}
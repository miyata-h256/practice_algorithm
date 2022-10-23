#include<iostream>
#include<vector>
using namespace std;

struct UnionFind{

    //par:各頂点の親頂点の番号,siz:各頂点の属する根付き木の頂点数
    vector<int> par,siz;

    UnionFind(int n) : par(n,-1),siz(n,1){}

    int root(int x){
        if(par[x] == -1) return x;
        else return par[x] = root(par[x]);//xの親par[x]を根に設定する
    }

    bool issame(int x,int y){
        return root(x) == root(y);
    }

    bool unite(int x,int y){
        x = root(x);y = root(y);

        if(x == y) return false;//すでに同じグループの時は何もしない

        //union by size(y側のサイズが小さくなるようにする)
        if(siz[x] < siz[y]) swap(x,y);

        //yをxの子にする
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    //xを含むグループのサイズ
    int size(int x){
        return siz[root(x)];
    }

};
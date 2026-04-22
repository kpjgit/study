#include <iostream>
#include <algorithm>

int N, M;

int par[1000001];

int find(int x) {
    if(par[x] < 0) return x;
    return par[x] = find(par[x]);
}

bool uni(int u, int v) {
    u = find(u);
    v = find(v);
    
    if(u == v) return false;
    
    if(par[u] > par[v]) std::swap(u, v);
    if(par[u] == par[v]) par[u]--;
    par[v] = u;
    
    return true;
}

int main(void) {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    
    std::cin >> N >> M;
    std::fill(par, par + N + 1, -1);
    bool op;
    int a, b;
    for(int i = 0; i < M; i++) {
        std::cin >> op >> a >> b;
        
        if(op) {
            if(find(a) == find(b)) std::cout << "YES\n";
            else std::cout << "NO\n";
        } else {
            uni(a, b);
        }
    }
}
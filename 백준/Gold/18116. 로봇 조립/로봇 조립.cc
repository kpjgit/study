#include <iostream>
#include <algorithm>

int N;

int p[1000'001];
int val[1000'001];

int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u);
    v = find(v);
    
    if(u == v) return false;
    
    if(p[v] < p[u]) std::swap(u, v);
    if(p[u] == p[v]) p[u]--;
    val[u] += val[v];
    p[v] = u;
    
    return true;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::fill(p, p + 1000001, -1);
    std::fill(val, val + 1000001, 1);
    std::cin >> N;
    char op;
    int a, b;
    for(int num = 0; num < N; num++) {
        std::cin >> op;
        if(op == 'I') {
            std::cin >> a >> b;
            uni(a, b);
        } else {
            std::cin >> a;
            std::cout << val[find(a)] << '\n';
        }
    }
}
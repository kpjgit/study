//15681
#include <bits/stdc++.h>

int N, R, Q;
int U, V;
std::vector<int> adj_list[100001];

int tree_size[100001];

int func(int cur, int par) {
    tree_size[cur] = 1;
    for(int dir : adj_list[cur]) {
        if(dir == par) continue;
        tree_size[cur] += func(dir, cur);
    }

    return tree_size[cur];
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> R >> Q;
    for(int i = 0; i < N - 1; i++) {
        std::cin >> U >> V;
        adj_list[U].push_back(V);
        adj_list[V].push_back(U);
    }

    func(R, 0);

    int input;
    for(int i = 0; i < Q; i++) {
        std::cin >> input;
        std::cout << tree_size[input] <<'\n';
    }
}
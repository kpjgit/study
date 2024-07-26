//-1
#include <bits/stdc++.h>

int lc[9] = {0, 2, 4, 6, 0, 0, 0, 0, 0};
int rc[9] = {0, 3, 5, 7, 0, 8, 0, 0, 0};

void bfs_level_order() {
    std::queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        std::cout << cur << ' ';
        if(lc[cur]) q.push(lc[cur]);
        if(rc[cur]) q.push(rc[cur]);
    }
}

void preorder(int cur) {
    std::cout << cur << ' ';
    if(lc[cur]) preorder(lc[cur]);
    if(rc[cur]) preorder(rc[cur]);
}

void inorder(int cur) {
    if(lc[cur]) inorder(lc[cur]);
    std::cout << cur << ' ';
    if(rc[cur]) inorder(rc[cur]);
}

void postorder(int cur) {
    if(lc[cur]) postorder(lc[cur]);
    if(rc[cur]) postorder(rc[cur]);
    std::cout << cur << ' ';
}

int main(void) {
    bfs_level_order();
    std::cout << '\n';
    preorder(1);
    std::cout << '\n';
    inorder(1);
    std::cout << '\n';
    postorder(1);
    std::cout << '\n';
}
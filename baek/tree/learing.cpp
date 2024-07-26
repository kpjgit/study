//-1
#include <bits/stdc++.h>

std::vector<int> adj[10];
int par[10];
int depth[10];

void bfs_fill_parent(int root) {
    std::queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        std::cout << cur << ' ';
        for(auto next : adj[cur]) {
            if(par[cur] == next) continue;
            q.push(next);
            par[next] = cur;
        }
    }
}

void bfs_fill_parent_depth(int root) {
    std::queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        std::cout << cur << ' ';
        for(auto next : adj[cur]) {
            if(par[cur] == next) continue;
            q.push(next);
            par[next] = cur;
            depth[next] = depth[cur] + 1;
        }
    }
}

void dfs_fill_parent_depth(int root) {
    std::stack<int> q;
    q.push(root);
    while(!q.empty()) {
        int cur = q.top();
        q.pop();
        std::cout << cur << ' ';
        for(auto next : adj[cur]) {
            if(par[cur] == next) continue;
            q.push(next);
            par[next] = cur;
            depth[next] = depth[cur] + 1;
        }
    }
}

void dfs_fill_parent_depth_recursion(int cur) {
    std::cout << cur << ' ';
    for(int next : adj[cur]) {
        if(par[cur] == next) continue;
        par[next] = cur;
        depth[next] = depth[cur] + 1;
        dfs_fill_parent_depth_recursion(next);
    }
}

void dfs(int cur, int par) {
    std::cout << cur << ' ';
    for(int next : adj[cur]) {
        if(par == next) continue;
        dfs(next, cur);
    }
}

int main(void) {

}
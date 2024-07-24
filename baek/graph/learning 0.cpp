//-1
#include <bits/stdc++.h>

std::vector<int> adj[10];
bool vis[10];
int dist[10];
int num;

void bfs_vis() {
    std::queue<int> q;
    q.push(0);
    vis[0] = true;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        std::cout << cur << ' ';
        for(auto e : adj[cur]) {
            if(vis[e] == true) continue;
            q.push(e);
            vis[e] = true;
        }
    }
}

void bfs_dist() {
    std::fill(dist, dist + 10, -1);
    std::queue<int> q;
    q.push(0);
    dist[0] = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto e : adj[cur]) {
            if(dist[e] > -1) continue;
            q.push(e);
            dist[e] = dist[cur] + 1;
        }
    }
}

void bfs_vis_not_connected() {
    std::queue<int> q;
    for(int i = 0; i < num; i++) {
        if(vis[i] == 1) continue;
        q.push(i);
        vis[i] = true;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            std::cout << cur << ' ';
            for(auto e : adj[cur]) {
                if(dist[e] == true) continue;
                q.push(e);
                vis[e] = true;
            }
        }
    }
}

void dfs_pseudo() {
    std::stack<int> s;
    s.push(0);
    vis[0] = true;
    while(!s.empty()) {
        int cur = s.top();
        s.pop();
        std::cout << cur << ' ';
        for(auto e : adj[cur]) {
            if(vis[e] == true) continue;
            s.push(e);
            vis[e] = true;
        }
    }
}

void dfs_recursion(int cur) {
    vis[cur] = true;
    std::cout << cur << ' ';
    for(auto e : adj[cur]) {
        if(vis[e] == true) continue;
        dfs_recursion(e);
    }
}

void dfs_not_recursion() {
    std::stack<int> s;
    s.push(0);
    while(!s.empty()) {
        int cur = s.top();
        s.pop();
        if(vis[cur] == true) continue;
        vis[cur] = true;
        std::cout << cur << ' ';
        for(auto e : adj[cur]) {
            if(vis[e] = true) continue;
            s.push(e);
        }
    }
}

int main(void) {
    
}
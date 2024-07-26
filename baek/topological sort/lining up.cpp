//2252
#include <bits/stdc++.h>

int n, m;
std::vector<int> adj[32001]; //A B 입력 A -> B 그래프
int indegree[32001];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int st, en;
        std::cin >> st >> en;
        adj[st].push_back(en);
        indegree[en]++;
    }

    std::queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        std::cout << cur << ' ';
        for(auto e : adj[cur]) {
            indegree[e]--;
            if(indegree[e] == 0) q.push(e);
        }
    }
    
   /*
    std::stack<int> s;
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) s.push(i);
    }
    while(!s.empty()) {
        int cur = s.top();
        s.pop();
        std::cout << cur << ' ';
        for(auto e : adj[cur]) {
            indegree[e]--;
            if(indegree[e] == 0) s.push(e);
        }
    }
    */
}
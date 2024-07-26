//-1
#include <bits/stdc++.h>

int n;
std::vector<int> adj[10];
int indegree[10];

void topological_sort() {
    for(int i = 0; i < n; i++) {
        for(int e : adj[i]) {
            indegree[e]++;
        }
    }

    std::vector<int> ans;
    std::queue<int> q;
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        for(int e : adj[cur]) {
            indegree[e]--;
            if(indegree[e] == 0) q.push(e);
        }
    }

    if(ans.size() != n) std::cout << "cycle exists\n";
    else {
        for(int e : ans) std::cout << e << ' ';
    }
}

int main(void) {

}
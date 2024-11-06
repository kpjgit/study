//2660
#include <bits/stdc++.h>

int N;
std::vector<int> adj_list[51];

int dist[51];
int point[51];
int ans[50];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> N;
    int u, v;
    while(true) {
        std::cin >> u >> v;
        if(u == -1 && v == -1) break;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for(int i = 1; i <= N; i++) {
        std::fill(dist + 1, dist + N + 1, -1);
        
        int temp = 0;
        std::queue<int> q;
        dist[i] = 0;
        q.push(i);
        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            for(int dir : adj_list[cur]) {
                if(dist[dir] >= 0) continue;

                dist[dir] = dist[cur] + 1;
                q.push(dir);
                temp = std::max(temp, dist[dir]);
            }
            point[i] = temp;
        }
    }

    int idx = 0;
    int mn = 51;
    for(int i = 1; i <= N; i++) {
        int cur = point[i];

        if(cur < mn) {
            mn = cur;
            ans[0] = i;
            idx = 1;
        } else if(cur == mn) {
            ans[idx] = i;
            idx++;
        }
    }

    std::cout << mn << ' ' << idx << '\n';
    for(int i = 0; i < idx; i++) std::cout << ans[i] << ' ';
}
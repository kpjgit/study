//1368
#include <bits/stdc++.h>

int N;
std::vector<std::pair<int, int>> adj_list[301]; //비용, 노드

bool vis[301];
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    int cost;
    for(int i = 1; i <= N; i++) { //새 우물을 파는건 0번째 우물에서 물을 끌어오는 것으로 간주한다
        std::cin >> cost;
        adj_list[0].push_back({cost, i});
        adj_list[i].push_back({cost, 0});
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            std::cin >> cost;
            if(i >= j) continue;

            adj_list[i].push_back({cost, j});
            adj_list[j].push_back({cost, i});
        }
    }

    vis[0] = true;
    for(auto& p : adj_list[0]) pq.push(p);
    int cnt = 0;
    int ans = 0;
    while(!pq.empty()) {
        std::pair<int, int> cur = pq.top();
        pq.pop();
        if(vis[cur.second]) continue;

        vis[cur.second] = true;
        cnt++;
        ans += cur.first;
        if(cnt == N) break; //0번째 우물을 포함하므로 간선의 갯수는 N

        for(auto& p : adj_list[cur.second]) if(!vis[p.second]) pq.push(p);
    }

    std::cout << ans;
}
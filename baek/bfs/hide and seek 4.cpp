//13913
#include <bits/stdc++.h>

int N, K;

int dist[100001];
int route[100001];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> K;
    std::fill(dist, dist + 100001, -1);

    std::queue<int> q;
    q.push(N);
    dist[N] = 0;
    route[N] = -1;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        int dir[3] = {cur - 1, cur + 1, cur * 2};
        for(int nxt : dir) {
            if(nxt < 0 || nxt > 100000) continue;
            if(dist[nxt] != -1) continue;

            dist[nxt] = dist[cur] + 1;
            route[nxt] = cur;
            q.push(nxt);
        }
    }

    std::cout << dist[K] << '\n';

    std::vector<int> ans;
    int cursor = K;
    while(cursor != -1) {
        ans.push_back(cursor);
        cursor = route[cursor];
    }

    for(auto i = ans.rbegin(); i != ans.rend(); i++) std::cout << *i << ' ';
}
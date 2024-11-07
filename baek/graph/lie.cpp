//1043
#include <bits/stdc++.h>

int N, M, T, K;
bool know[51];
std::vector<int> party[50];
std::vector<int> people[51];

void bfs() {
    std::queue<int> q;

    for(int i = 1; i <= N; i++) if(know[i]) q.push(i);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(int dir : people[cur]) {
            if(know[dir]) continue;

            know[dir] = true;
            q.push(dir);
        }
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M >> T;
    int temp;
    for(int i = 0; i < T; i++) {
        std::cin >> temp;
        know[temp] = true;
    }

    for(int num = 0; num < M; num++) {
        std::cin >> K;
        int prev, next;
        std::cin >> prev;
        party[num].push_back(prev);
        for(int i = 1; i < K; i++) {
            std::cin >> next;
            party[num].push_back(next);
            people[prev].push_back(next);
            people[next].push_back(prev);
            prev = next;
        }
    }

    bfs();
    
    int ans = 0;
    for(int i = 0; i < M; i++) {
        bool can = true;
        for(int i : party[i]) {
            if(know[i]) {
                can = false;
                break;
            }
        }

        if(can) ans++;
    }

    std::cout << ans;
}
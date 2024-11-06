//11403
#include <bits/stdc++.h>

int N;
bool arr[100][100];

bool vis[100];

bool bfs(int st, int en) {
    std::fill(vis, vis + N, false);
    
    std::queue<int> q;
    vis[st] = true;
    q.push(st);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int dir = 0; dir < N; dir++) {
            if(arr[cur][dir] == false) continue;
            if(dir == en) return true;
            else if(vis[dir] == true) continue;

            vis[dir] = true;
            q.push(dir);
        }
    }

    return false;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) std::cin >> arr[i][j];
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cout << bfs(i, j) << ' ';
        }
        std::cout <<'\n';
    }
}
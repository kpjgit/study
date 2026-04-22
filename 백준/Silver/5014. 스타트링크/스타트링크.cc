#include <iostream>
#include <algorithm>
#include <queue>

int F, S, G, U, D;

int dist[1000001];
int dx[2];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> F >> S >> G >> U >> D;
    dx[0] = U;
    dx[1] = -D;
    
    std::fill(dist + 1, dist + F + 1, -1);
    std::queue<int> q;
    dist[S] = 0;
    q.push(S);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(int dir = 0; dir < 2; dir++) {
            int nx = cur + dx[dir];
            if(nx < 1 || nx > F) continue;
            if(dist[nx] != -1) continue;
            
            dist[nx] = dist[cur] + 1;
            q.push(nx);
            
            if(dist[G] != -1) {
                std::cout << dist[G];
                return 0;
            }
        }
    }
    
    std::cout << "use the stairs";
}
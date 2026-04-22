#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N;
int req_time[10001];
std::vector<int> adj[10001];

int inbound[10001];
int acc_time[10001];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> N;
    int cnt, prev;
    for(int i = 1; i <= N; i++) {
        std::cin >> req_time[i] >> cnt;
        for(int j = 0; j < cnt; j++) {
            std::cin >> prev;
            adj[prev].push_back(i);
            inbound[i]++;
        }
    }
    
    std::queue<int> q;
    for(int i = 1; i <= N; i++) {
        if(inbound[i] == 0) {
            q.push(i);
        }
    }
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        //큐에 들어간 순간 선행 작업은 모두 끝났으므로 시간 갱신
        req_time[cur] += acc_time[cur];
        
        for(int nxt : adj[cur]) {
            inbound[nxt]--;
            //선행 작업 중 가장 큰 시간
            acc_time[nxt] = std::max(acc_time[nxt], req_time[cur]);
            if(inbound[nxt] == 0) q.push(nxt);
        }
    }
    
    int ans = -1;
    for(int i = 1; i <= N; i++) ans = std::max(ans, req_time[i]);
    std::cout << ans;
}
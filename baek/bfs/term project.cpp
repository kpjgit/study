//9466
#include <bits/stdc++.h>

int T;
int n;
int students[100001];
int vis[100001]; //0 not visited, -1 cycle

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> T;
    for(int num = 0; num < T; num++) {
        std::cin >> n;
        for(int i = 1; i <= n; i++) std::cin >> students[i];
        std::fill(vis + 1, vis + 1 + n, 0);

        for(int i = 1; i <= n; i++) {
            if(vis[i] == 0) {
                int cur = i;
                while(true) {
                    vis[cur] = i;
                    cur = students[cur];

                    if(vis[cur] == i) { //탐색하다 시작점 i와 같을 경우 사이클이 있음
                        while(vis[cur] != -1) {
                            vis[cur] = -1;
                            cur = students[cur];
                        }
                        break;
                    } else if(vis[cur] != 0) break;
                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(vis[i] != -1) ans++;
        }
        std::cout << ans << '\n';
    }
}
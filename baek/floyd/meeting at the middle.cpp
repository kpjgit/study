//21940
#include <bits/stdc++.h>

int N, M, K;
int arr[201][201];
std::vector<int> friends;

const int inf = 200001;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        std::fill(arr[i] + 1, arr[i] + N + 1, inf);
        arr[i][i] = 0;
    }

    int u, v, cost;
    for(int i = 0; i < M; i++) {
        std::cin >> u >> v >> cost;
        if(arr[u][v] > cost) arr[u][v] = cost; 
    }

    std::cin >> K;
    for(int i = 0; i < K; i++) {
        std::cin >> u;
        friends.push_back(u);
    }

    for(int route = 1; route <= N; route++) {
        for(int st = 1; st <= N; st++) {
            for(int en = 1; en <= N; en++) {
                arr[st][en] = std::min(arr[st][en], arr[st][route] + arr[route][en]);
            }
        }
    }

    int mx = inf * 2; //왕복해야하므로 inf의 두배
    std::vector<int> ans;
    for(int dest = 1; dest <= N; dest++) {
        int temp_mx = 0; //왕복시간의 최대
        bool cannot_reach = false;

        for(int st : friends) {
            if(arr[st][dest] == inf || arr[dest][st] == inf) {
                cannot_reach = true;
                break;
            }

            temp_mx = std::max(temp_mx, arr[st][dest] + arr[dest][st]);
        }

        if(cannot_reach) continue;

        if(mx > temp_mx) {
            mx = temp_mx;
            ans.clear();
            ans.push_back(dest);
        } else if(mx == temp_mx) ans.push_back(dest);
    }

    std::sort(ans.begin(), ans.end());
    for(int i : ans) std::cout << i << ' ';
}
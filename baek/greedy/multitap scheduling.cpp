//1700
#include <bits/stdc++.h>

int N, K;
int arr[100];

bool used[101];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> K;
    for(int i = 0; i < K; i++) std::cin >> arr[i];

    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < K; i++) {
        int cur = arr[i];
        if(used[cur] == true) continue;

        if(cnt < N) {
            used[cur] = true;
            cnt++;
        } else {
            std::vector<std::pair<int, int>> v; //순서, 이름, 가장 늦게 나오는 전기용품을 뽑음
            for(int idx = 1; idx <= K; idx++) { //이름
                if(used[idx] == false) continue;

                bool vis = false;
                for(int order = i + 1; order < K; order++) { //순서
                    if(arr[order] == idx) {
                        v.push_back({order, idx});
                        vis = true;
                        break;
                    }
                }
                if(vis == false) v.push_back({K + 1, idx}); //더 이상 사용하지 않을 경우 가장 늦게 나오는 취급
            }
            std::sort(v.begin(), v.end(), std::greater<std::pair<int, int>>());
            
            used[(*v.begin()).second] = false;
            ans++;
            used[cur] = true;
        }
    }

    std::cout << ans;
}
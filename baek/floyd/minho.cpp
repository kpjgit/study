//1507
#include <bits/stdc++.h>

int N;
int arr[21][21];

bool chk[21][21];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            std::cin >> arr[i][j];
        }
    }

    for(int st = 1; st <= N; st++) {
        for(int en = 1; en <= N; en++) {
            bool direct = true;

            for(int route = 1; route <= N; route++) {
                if(st == route || en == route) continue;

                int temp = arr[st][route] + arr[route][en]; //st에서 en으로 가는데 route를 거쳐가는 비용
                if(arr[st][en] > temp) { //arr은 최소 비용 행렬인데 temp보다 arr[st][en]이 클 경우 모순이 생긴다
                    std::cout << -1;
                    return 0;
                }

                if(arr[st][en] == temp) direct = false; //arr[st][en]와 route를 경유한 비용이 같을 경우 st, en을 직접 연결하는 도로는 없어도 된다
            }

            if(direct) chk[st][en] = true;
        }
    }
    
    int ans = 0;
    for(int i = 1; i <= N; i++) { //A에서 B로 가는 시간과 B에서 A로 가는 시간은 동일하므로 양방향 도로이다, 행렬의 절반만 고려함
        for(int j = i + 1; j <= N; j++) {
            if(chk[i][j]) ans += arr[i][j];
        }
    }

    std::cout << ans;
}
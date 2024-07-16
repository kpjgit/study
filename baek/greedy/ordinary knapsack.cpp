//12865 그리디 아님 dp로 풀이
#include <bits/stdc++.h>

int n, k;
std::pair<int, int> stuffs[101];//무게, 가치
int arr[101][100001];//a[i][j], i번째 물건에 대해 j만큼의 무게 제한일 때 최대 만족치
int arr1[101];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> n >> k;
    for(int i = 0; i < n; i++) {
        std::cin >> stuffs[i].first >> stuffs[i].second;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            if(j >= stuffs[i].first) {
                arr[i][j] = std::max(arr[i - 1][j], arr[i - 1][j - stuffs[i].first] + stuffs[i].second);
            } else {
                arr[i][j] = arr[i - 1][j];
            }
        }
    }

    /*
    for(int i = 1; i <= N; i++) {
        for(int j = k; j >= 1; j--) {
            if(stuffs[i].first <= j) {
                arr1[j] = std::max(arr1[j], arr1[j - stuffs[i].first] + stuffs[i].second);
            }
        }
    }
    std::cout << arr1[k];
    */

    std::cout << arr[n][k];
}
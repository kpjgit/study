//2295
#include <bits/stdc++.h>

int N;
int arr[1000];

std::vector<int> two;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) std::cin >> arr[i];
    std::sort(arr, arr + N);

    for(int i = 0; i < N; i++) {
        for(int j = i; j < N; j++) two.push_back(arr[i] + arr[j]);
    }
    std::sort(two.begin(), two.end());

    for(int i = N - 1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if(std::binary_search(two.begin(), two.end(), arr[i] - arr[j])) { //std::binary_search(arr, arr + N, two[i] + arr[j]) 가장 먼저 나온 수가 최대값이라는 보장이 없음
                std::cout << arr[i];
                return 0;
            }
        }
    }
}
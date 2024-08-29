//10807
#include <bits/stdc++.h>

int N, v;
int arr[100];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int ans = 0;
    std::cin >> N;
    for(int i = 0; i < N; i++) std::cin >> arr[i];
    std::cin >> v;

    for(int i = 0; i < N; i++) if(arr[i] == v) ans++;

    std::cout << ans;
}
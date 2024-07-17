//2295
#include <bits/stdc++.h>

int n;
int arr[1001];
std::vector<int> twos;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    for(int i = 0; i < n; i++) std::cin >> arr[i];
    std::sort(arr, arr + n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            twos.push_back(arr[i] + arr[j]);
        }
    }
    std::sort(twos.begin(), twos.end());

    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < i; j++) {
            if(std::binary_search(twos.begin(), twos.end(), arr[i] - arr[j])) {
                std::cout << arr[i];
                return 0;
            }
        }
    }
}
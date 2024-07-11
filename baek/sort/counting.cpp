//15688
#include <bits/stdc++.h>

int n;
int arr[1000005];
int count[2000005];
int mid = 1000000;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int st = 0;
    int en = 0;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
        count[mid + arr[i]]++;
        st = std::min(st, arr[i]);
        en = std::max(en, arr[i]);
    }

    int idx = 0;
    for(int i = st; i <= en; i++) {
        int num = count[mid + i];
        for(int j = 0; j < num; j++) {
            arr[idx++] = i;
        }
    }

    for(int i = 0; i < n; i++) std::cout << arr[i] << '\n';
}
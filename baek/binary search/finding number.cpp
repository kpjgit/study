//1920
#include <bits/stdc++.h>

int n, m;
int arr[100001];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    for(int i = 0; i < n; i++) std::cin >> arr[i];
    std::sort(arr, arr + n);

    std::cin >> m;
    for(int i = 0; i < m; i++) {
        int x;
        std::cin >> x;

        int st = 0;
        int en = n - 1;
        while(st <= en) {
            int mid = (st + en) / 2;

            if(arr[mid] < x) {
                st = mid + 1;
            } else if(arr[mid] > x) {
                en = mid - 1;
            } else {
                std::cout << 1 << '\n';
                break;
            }
        }

        if(st > en) std::cout << 0 << '\n';

        //std::cout << std::binary_search(arr, arr + n, x);
    }
}
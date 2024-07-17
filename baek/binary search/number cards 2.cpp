//10816
#include <bits/stdc++.h>

int n, m;
int arr[500001];

int lower(int x, int len) {
    int st = 0;
    int en = len;

    while(st < en) {
        int mid = (st + en) / 2;
        if(arr[mid] >= x) en = mid;
        else st = mid + 1;
    }
    return st;
}

int upper(int x, int len) {
    int st = 0;
    int en = len;

    while(st < en) {
        int mid = (st + en) / 2;
        if(arr[mid] > x) en = mid;
        else st = mid + 1;
    }
    return st;
}

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

        std::cout << upper(x, n) - lower(x, n) << '\n';
        //std::cout << std::upper_bound(arr, arr + n, x) - std::lower_bound(arr, arr + n, x) << '\n';
        //std::cout << std::equal_range(arr, arr + n, x).second - std::equal_range(arr, arr + n, x).first << '\n';
    }
}
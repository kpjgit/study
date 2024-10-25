//10816
#include <bits/stdc++.h>

int N, M;
int arr[500000];

int search(int input) {
    int st = 0;
    int en = N - 1;

    while(st <= en) {
        int mid = (st + en) / 2;

        if(arr[mid] == input) return mid;
        else if(arr[mid] > input) en = mid - 1;
        else st = mid + 1;
    }

    return -1;
}

int search_right(int loc) {
    const int target = arr[loc];
    int st = loc;
    int en = N - 1;
    while(st <= en) {
        int mid = (st + en) / 2;

        if(arr[mid] != target && arr[mid - 1] == target) return mid - 1;
        else if(arr[mid] == target) st = mid + 1;
        else en = mid - 1;
    }

    return N - 1;
}

int search_left(int loc) {
    const int target = arr[loc];
    int st = 0;
    int en = loc;
    while(st <= en) {
        int mid = (st + en) / 2;

        if(arr[mid] != target && arr[mid + 1] == target) return mid + 1;
        else if(arr[mid] == target) en = mid - 1;
        else st = mid + 1;
    }

    return 0;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) std::cin >> arr[i];
    std::sort(arr, arr + N);

    std::cin >> M;
    for(int num = 0; num < M; num++) {
        int input;
        std::cin >> input;
        
        int loc = search(input);
        if(loc == -1) {
            std::cout << 0 << ' ';
            continue;
        }

        int l; //static_cast<int>(std::lower_bound(arr, arr + N, input) - arr);
        int r; //
        if(loc == 0) {
            l = 0;
            r = search_right(loc);
        } else if(loc == N - 1) {
            r = N - 1;
            l = search_left(loc);
        } else {
            l = search_left(loc);
            r = search_right(loc);
        }

        std::cout << r - l + 1 << ' ';
    }
}
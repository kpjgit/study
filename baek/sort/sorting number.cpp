//2751
#include <bits/stdc++.h>

int N;

int arr[10000000];
int temp[10000000];

void merge(int st, int en) {
    int mid = (st + en) / 2;
    int idx_l = st;
    int idx_r = mid;

    for(int i = st; i < en; i++) {
        if(idx_l == mid) temp[i] = arr[idx_r++];
        else if(idx_r == en) temp[i] = arr[idx_l++];
        else if(arr[idx_l] <= arr[idx_r]) temp[i] = arr[idx_l++];
        else temp[i] = arr[idx_r++];
    }

    for(int i = st; i < en; i++) arr[i] = temp[i];
}

void merge_sort(int st, int en) {
    if(st + 1 == en) return;
    int mid = (st + en) / 2;

    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st, en);
}


int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) std::cin >> arr[i];

    merge_sort(0, N);
    for(int i = 0; i < N; i++) std::cout << arr[i] << '\n';
}
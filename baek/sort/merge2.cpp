//2751
#include <bits/stdc++.h>

int arr[1000001] = {15, 25, 22, 357, 16, 23, -53, 12, 46, 3};
int temp[1000001];
int n;

void merge(int st, int en) {
    int mid = (st + en) / 2;
    int idxl = st;
    int idxr = mid;

    for(int i = st; i < en; i++) {
        if(idxl == mid ) temp[i] = arr[idxr++];
        else if(idxr == en) temp[i] = arr[idxl++];
        else if(arr[idxl] >= arr[idxr]) temp[i] = arr[idxr++];
        else temp[i] = arr[idxl++];
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
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    merge_sort(0, n);
    for(int i = 0; i < n; i++) std::cout << arr[i] << '\n';
}
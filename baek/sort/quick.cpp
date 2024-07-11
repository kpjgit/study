//-1
#include <bits/stdc++.h>

int n = 10;
int arr[1000001] = {15, 25, 22, 357, 16, 23, -53, 12, 46, 3};

void quick_sort(int st, int en) {
    if(en <= st + 1) return;

    int pivot = arr[st];
    int idxl = st + 1;
    int idxr = en - 1;

    while(1) {
        while(idxl <= idxr && arr[idxl] <= pivot) idxl++;
        while(idxl <= idxr && arr[idxr] >= pivot) idxr--;

        if(idxl > idxr) break;
        std::swap(arr[idxl], arr[idxr]);
    }
    std::swap(arr[st], arr[idxr]);

    quick_sort(st, idxr);
    quick_sort(idxr + 1, en);
}

int main(void) {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    quick_sort(0, n);
    for(int i = 0; i < n; i++) std::cout << arr[i] << ' ';
}
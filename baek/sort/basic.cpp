//-1
#include <bits/stdc++.h>

int main(void) {
    //select
    int arr[10] = {3, 2, 7, 116, 62, 235, 1, 23, 55, 77};
    int n = 10;

    for(int i = n - 1; i > 0; i--) {
        int idx = 0;
        for(int j = 0; j <= i; j++) {
            if(arr[idx] < arr[j]) idx = j;
        }
        std::swap(arr[i], arr[idx]);
    }
    for(int i = 0; i < n; i++) std::cout << arr[i] << ' ';
    std::cout << '\n';

    int arr0[10] = {3, 2, 7, 116, 62, 235, 1, 23, 55, 77};
    for(int i = n - 1; i > 0; i--) {
        std::swap(*std::max_element(arr0, arr0 + i + 1), arr0[i]);
    }
    for(int i = 0; i < n; i++) std::cout << arr[i] << ' ';
    std::cout << '\n';

    //bubble
    int arr1[10] = {3, 2, 7, 116, 62, 235, 1, 23, 55, 77};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr1[j] > arr1[j + 1]) std::swap(arr1[j], arr1[j + 1]);
        }
    }
    for(int i = 0; i < n; i++) std::cout << arr[i] << ' ';
    std::cout << '\n';
}
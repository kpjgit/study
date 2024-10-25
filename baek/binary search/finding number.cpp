//1920
#include <bits/stdc++.h>

int N, M;
int arr[100000];

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

        int st = 0;
        int en = N - 1;
        bool ans = false;
        
        while(st <= en) {
            int mid = (st + en) / 2;

            if(arr[mid] == input) {
                ans = true;
                break;
            } else if(arr[mid] > input) en = mid - 1;
            else st = mid + 1; //arr[mid] < input
        }
        std::cout << ans << '\n';
        //std::cout << std::binary_search(a, arr + N, input);
    }
}
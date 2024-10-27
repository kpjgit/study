//2467
#include <bits/stdc++.h>

int N;
int arr[100000];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) std::cin >> arr[i];

    int ans0 = 1000000000;
    int ans1 = 1000000000;
    for(int i = 0; i < N; i++) { //lower_bound는 인자보다 크거나 같은 첫번째 수를 반환
        int idx = std::lower_bound(arr, arr + N, -arr[i]) - arr; //arr[i]에 더해 0이되는 수는 -arr[i]
                                                                 //따라서 idx의 -1~1 주변 값은 arr[i]와 더해 0과 가장 가까운 값이 될 수 있음
        if(idx + 1 < N && idx + 1 != i && std::abs(arr[idx + 1] + arr[i]) < std::abs(ans0 + ans1)) {
            ans0 = arr[i];
            ans1 = arr[idx + 1];
        }

        if(idx < N && idx != i && std::abs(arr[idx] + arr[i]) < std::abs(ans0 + ans1)) {
            ans0 = arr[i];
            ans1 = arr[idx];
        }

        if(idx - 1 >= 0 && idx - 1 != i && std::abs(arr[idx - 1] + arr[i]) < std::abs(ans0 + ans1)) {
            ans0 = arr[i];
            ans1 = arr[idx - 1];
        }
    }

    if(ans0 < ans1) std::cout << ans0 << ' ' << ans1;
    else std::cout << ans1 << ' ' << ans0;
}
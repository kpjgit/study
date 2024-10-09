//5648
#include <bits/stdc++.h>

int n;
long long arr[1000000];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    //std::string s;
    for(int i = 0; i < n; i++) {
        long long input;
        std::cin >> input;
        long long temp = 0;

        while(input > 0) {
            temp = temp * 10 + (input % 10);
            input /= 10;
        }

        arr[i] = temp;

        /*
        std::cin >> s;
        std::reverse(s.begin(), s.end());

        arr[i] = std::stoi(s);
        */
    }

    std::sort(arr, arr + n);
    for(int i = 0; i < n; i++) std::cout << arr[i] << '\n';
}
//11328
#include <bits/stdc++.h>

int N;
std::string base, comp;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) {
        int arr[26] = {};
        std::cin >> base >> comp;

        for(char c : base) arr[c - 'a']++;
        for(char c : comp) arr[c - 'a']--;

        bool is_strfry = true;
        for(int i : arr) {
            if(i != 0) {
                is_strfry = false;
                break;
            }
        }

        if(is_strfry) std::cout << "Possible\n";
        else std::cout << "Impossible\n";
    }
}
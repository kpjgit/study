//10808
#include <bits/stdc++.h>

std::string S;
int alphabet[26];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> S;
    for(int i = 0; i < S.size(); i++) {
        alphabet[S[i] - 'a']++;
    }

    for(int i = 0; i < 26; i++) {
        std::cout << alphabet[i] << ' ';
    }
}
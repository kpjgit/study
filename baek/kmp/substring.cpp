//16916
#include <bits/stdc++.h>

std::string s, pat;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> s >> pat;

    std::vector<int> failure(pat.size());
    int j = 0;
    for(int i = 1; i < pat.size(); i++) {
        while(j > 0 && pat[i] != pat[j]) j = failure[j - 1];
        if(pat[i] == pat[j]) failure[i] = ++j;
    }

    bool ans = false;
    j = 0;
    for(int i = 0; i < s.size(); i++) {
        while(j > 0 && s[i] != pat[j]) j = failure[j - 1];

        if(s[i] == pat[j]) j++;

        if(j == pat.size()) {
            ans = true;
            j = failure[j - 1];
        }
    }

    std::cout << ans;
}
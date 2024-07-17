//18870
#include <bits/stdc++.h>

int n;
int arr[1000001];
std::vector<int> temp, uniq;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
        temp.push_back(arr[i]);
    }
    std::sort(temp.begin(), temp.end());
    for(int i = 0; i < n; i++) {
        if(i == 0 || temp[i - 1] != temp[i]) uniq.push_back(temp[i]);
    }

    for(int i = 0; i < n; i++) {
        std::cout << std::lower_bound(uniq.begin(), uniq.end(), arr[i]) - uniq.begin() << ' ';
    }

    //std::erase(std::unique(temp.begin(), temp.end()), temp.end());
}
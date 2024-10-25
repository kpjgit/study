//18870
#include <bits/stdc++.h>

int N;
int arr[1000000];

std::vector<int> table;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    std::vector<int> temp;
    for(int i = 0; i < N; i++) {
        std::cin >> arr[i];
        temp.push_back(arr[i]);
    }
    std::sort(temp.begin(), temp.end());

    table.push_back(*temp.begin());
    for(auto i : temp) {
        if(table.back() == i) continue;

        table.push_back(i);
    } //table.erase(std::unique(table.begin(), table.end()), table.end());

    for(int i = 0; i < N; i++) std::cout << std::lower_bound(table.begin(), table.end(), arr[i]) - table.begin() << ' ';
}
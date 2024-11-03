//19700
#include <bits/stdc++.h>

int N;
std::pair<int, int> arr[500000]; //키, 등수, 정렬되므로 i번째 학생의 키는 먼저 들어간 학생의 최소 등수 제한에 영향을 주지 않는다

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) std::cin >> arr[i].first >> arr[i].second;
    std::sort(arr, arr + N);

    std::multiset<int> ms; //팀원의 수 집합
    for(int i = N - 1; i >= 0; i--) { //만족하는 모든 집합에 들어갈 수 있지만 최소한의 팀 개수를 원하기 때문에 최대한 한 곳에 학생을 몰아 배정해야 한다
        auto iter = ms.lower_bound(-arr[i].second + 1); //i의 k-1보다 작거나 같은 최대 값을 원하므로 마이너스를 붙인다
        if(iter == ms.end()) {
            ms.insert(-1);
        } else {
            int temp = *iter;
            ms.erase(iter);
            ms.insert(temp - 1);
        }
    }

    std::cout << ms.size();
}
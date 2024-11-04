//1655
#include <bits/stdc++.h>

int N;
std::priority_queue<int> maxHeap; //왼쪽
std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; //오른쪽

std::multiset<int> s;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    int val;
    for(int i = 0; i < N; i++) {
        std::cin >> val;

        if(maxHeap.size() == minHeap.size()) maxHeap.push(val); //항상 최대힙에 먼저 들어감
        else minHeap.push(val);

        if(!minHeap.empty() && minHeap.top() < maxHeap.top()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        std::cout << maxHeap.top() << '\n';
    }
}
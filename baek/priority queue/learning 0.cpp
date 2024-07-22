//-1
#include <bits/stdc++.h>

int main(void) {
    std::priority_queue<int> pq; //최대 힙
    //std::priority_quque<int, std::vector<int>, std::greater<int>> 최소 힙
    pq.push(10); pq.push(2); pq.push(5); pq.push(9);
    std::cout << pq.top() << '\n';
    pq.pop();
    std::cout << pq.size() << '\n';
    if(pq.empty()) std::cout << "pq is empty\n";
    else std::cout << "pq is not empty\n";
    pq.pop();
    std::cout << pq.top() << '\n';
    pq.push(15); pq.push(5);
    std::cout << pq.top() << '\n';
}
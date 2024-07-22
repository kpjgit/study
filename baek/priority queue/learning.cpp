//-1
#include <bits/stdc++.h>

int heap[100005];
int sz = 0;

void push(int x) {
    sz++;
    heap[sz] = x;
    int cur = sz;
    while(cur != 1) {
        int par = cur / 2;
        if(heap[par] <= heap[cur]) break;
        std::swap(heap[par], heap[cur]);
        cur = par;
    }
    return;
}

int top() {
    if(sz != 0) return heap[1];
    else return -1;
}

void pop() {
    heap[1] = heap[sz];
    sz--;

    int cur = 1;
    while(2 * cur <= sz) {
        int left = 2 * cur;
        int right = 2 * cur + 1;
        int temp = left;
        if(right <= sz && heap[right] < heap[left]) {
            temp = right;
        }

        if(heap[cur] <= heap[temp]) break;
        std::swap(heap[cur], heap[temp]);
        cur = temp;
    }
    return;
}

void test(){
    push(10); push(2); push(5); push(9); // {10, 2, 5, 9}
    std::cout << top() << '\n'; // 2
    pop(); // {10, 5, 9}
    pop(); // {10, 9}
    std::cout << top() << '\n'; // 9
    push(5); push(15); // {10, 9, 5, 15}
    std::cout << top() << '\n'; // 5
    pop(); // {10, 9, 15}
    std::cout << top() << '\n'; // 9
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    test();
}
#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_map>

int A, B;

//idx, cost
std::unordered_map<long long, int> dist;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> A >> B;    
    
    std::queue<long long> q;
    dist[A] = 0;
    q.push(A);
    while(!q.empty()) {
        long long cur = q.front();
        q.pop();
        
        if(cur == B) break;
        
        long long temp;
        
        temp = cur * 2;
        if(temp <= B && dist.find(temp) == dist.end()) {
            dist[temp] = dist[cur] + 1;
            q.push(temp);
        }
        
        temp = cur * 10 + 1;
        if(temp <= B && dist.find(temp) == dist.end()) {
            dist[temp] = dist[cur] + 1;
            q.push(temp);
        }
    }
    
    if(dist.find(B) == dist.end()) std::cout << -1;
    else std::cout << dist [B] + 1;
}
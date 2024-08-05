//-1
#include <bits/stdc++.h>

std::vector<std::pair<int, int>> adj[10001]; //비용, 번호
int max = 0x3f3f3f3f;
bool fix[10001];
int table[10001];
int v = 10;

void dijkstra(int st) {
    std::fill(table, table + v + 1, max);
    
    table[st] = 0;
    while(true) {
        int idx = -1;
        for(int i = 0; i <= v; i++) {
            if(fix[i]) continue;
            if(idx == -1) idx = i;
            else if(table[i] < table[idx]) idx = i;
        }

        if(idx == -1 || table[idx] == max) break;
        fix[idx] = true;
        for(auto next : adj[idx]) {
            table[next.second] = std::min(table[next.second], table[idx] + next.first);
        }
    }   
}

int main(void) {

}
#include <bits/stdc++.h>

int N, M, K;
int arr[4000001];

int nxt[4000001];

int find(int x) {
    if(nxt[x] == x) return x;
    //자기 자신을 가리킬 경우 어떤 그룹에 속한 것이 아니고 아직 사용한 카드가 아니다
    
    return nxt[x] = find(nxt[x]);
}

void uni(int current, int next) {
    current = find(current);
    next = find(next);
    
    nxt[current] = next;
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);


	std::cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		std::cin >> arr[i];
		nxt[i] = i;
	}
	nxt[M] = M;
	
	std::sort(arr, arr + M);
	int card;
	for (int i = 0; i < K; i++) {
		std::cin >> card;
		
		int idx = find(std::upper_bound(arr, arr + M, card) - arr);
		uni(idx, idx + 1);
		
		std::cout << arr[idx] << '\n';
	}
}
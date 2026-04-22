#include <bits/stdc++.h>

int N, Q;
std::tuple<int, int, int> input[100000]; // st, en, idx

int table[100000];

int main(void) {
	std::ios::sync_with_stdio(false);

	std::cin.tie(nullptr);

	std::cin >> N >> Q;
	int st, en, ignore;
	for (int i = 0; i < N; i++) {
		int st, en;
		std::cin >> st >> en >> ignore;

		input[i] = {st, en, i};
	}
	std::sort(input, input + N);

	int table_num = 0;
	table[0] = table_num;
	int idx;
	std::tie(st, en, idx) = input[0];
	for (int i = 1; i < N; i++) {
		int nxt_st, nxt_en, nxt_idx;
		std::tie(nxt_st, nxt_en, nxt_idx) = input[i];

		if (en >= nxt_st) {
			en = std::max(en, nxt_en);
			table[nxt_idx] = table_num;
		}
		else {
			st = nxt_st;
			en = nxt_en;
			table_num++;
			table[nxt_idx] = table_num;
		}
	}

	int st_idx, en_idx;
	for (int i = 0; i < Q; i++) {
		std::cin >> st_idx >> en_idx;
		st_idx--;
		en_idx--;

		if (table[st_idx] == table[en_idx]) {
			std::cout << "1\n";
		}
		else std::cout << "0\n";
	}
}
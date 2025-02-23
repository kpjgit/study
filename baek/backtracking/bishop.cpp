//1799
#include <iostream>

int N;
bool board[10][10];

bool used_dia[10 * 2 - 1]; //n-i+j-1
bool used_dia_r[10 * 2 - 1]; //i+j

void func(int cnt, int x, int y, int& ans) {
	if (y >= N) {
		x++;
		y = (y + 1) % 2;
	}

	if (x >= N) {
		ans = std::max(ans, cnt);
		return;
	}

	if (!used_dia[N - x + y - 1] && !used_dia_r[x + y] && board[x][y]) {
		used_dia[N - x + y - 1] = true;
		used_dia_r[x + y] = true;
		func(cnt + 1, x, y + 2, ans);
		used_dia[N - x + y - 1] = false;
		used_dia_r[x + y] = false;
	}
	func(cnt, x, y + 2, ans);
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> board[i][j];
		}
	}

	int even = 0; //서로 간섭하지 않으므로 각각에서 최대를 구해 더할 수 있다
	int odd = 0;
	func(0, 0, 0, odd);
	func(0, 0, 1, even);

	std::cout << even + odd;
}
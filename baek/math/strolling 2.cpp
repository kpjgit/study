//12850
#include <bits/stdc++.h>

int D;

//정보과학관, 전산관, 미래관, 신양관, 한경직기념관, 진리관, 형남공학관, 학생회관 순서
//서로 연결된 노드, 행렬곱의 횟수를 D라 한다면 arr[i][j]는 D번 안에 i에서 j로 가는 경우의 수
std::vector<std::vector<long long>> arr = {
	{0, 1, 1, 0, 0, 0, 0, 0},
	{1, 0, 1, 1, 0, 0, 0, 0},
	{1, 1, 0, 1, 1, 0, 0, 0},
	{0, 1, 1, 0, 1, 1, 0, 0},
	{0, 0, 1, 1, 0, 1, 1, 0},
	{0, 0, 0, 1, 1, 0, 0, 1},
	{0, 0, 0, 0, 1, 0, 0, 1},
	{0, 0, 0, 0, 0, 1, 1, 0}
};

std::vector<std::vector<long long>> mult(const std::vector<std::vector<long long>>& a, const std::vector < std::vector<long long>>& b) {
	std::vector<std::vector<long long>> ret(8, std::vector<long long>(8));

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8;j++) {
			for (int k = 0; k < 8; k++) {
				ret[i][j] += a[i][k] * b[k][j];
				ret[i][j] %= 1'000'000'007;
			}
		}
	}

	//return std::move(ret); //c++17 이전
	return ret;
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::cin >> D;
	
	std::vector<std::vector<long long>> ans(8, std::vector<long long>(8));
	for (int i = 0; i < 8; i++) ans[i][i] = 1;

	auto temp = arr;
	while (D > 0) {
		if (D % 2 == 1) ans = mult(ans, temp); //홀수일 경우 ans에 한번 곱함, 종료 직전에는 D는 항상 1이 됨

		temp = mult(temp, temp);
		D /= 2;
	}

	std::cout << ans[0][0];
}
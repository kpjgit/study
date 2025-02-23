//1533
#include <bits/stdc++.h>

int N, S, E, T;

std::vector<std::vector<long long>> mult(const std::vector<std::vector<long long>>& a, const std::vector < std::vector<long long>>& b) {
	std::vector<std::vector<long long>> ret(5 * N, std::vector<long long>(5 * N));

	for (int i = 0; i < 5 * N; i++) {
		for (int j = 0; j < 5 * N;j++) {
			for (int k = 0; k < 5 * N; k++) {
				ret[i][j] += a[i][k] * b[k][j];
				ret[i][j] %= 1'000'003;
			}
		}
	}

	return ret;
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::cin >> N >> S >> E >> T;

    std::vector<std::vector<long long>> arr(5 * N, std::vector<long long>(5 * N));
    //arr[i][j]는 i에서 j까지 T시간에 갈 수 있는 방법의 수
    //하지만 i에서 j로 가는 시간이 1~5이므로 i와 i+1 정점 사이를 i1, i2, i3, i4, i5로 나누어 생각한다
    //i에서 j로 가는데 드는 시간이 1일 경우 i와 j1을 연결하고 3일 경우 i와 j3를 연결한다
    
    std::string str;
    for(int i = 0; i < N; i++){
        std::cin >> str;

        for(int j = 0; j < N; j++) {
            if(str[j] - '0' != 0) {
                arr[i * 5][j * 5 + str[j] - '0' - 1] = 1;
            }
        }

        for(int j = 1; j < 5; j++) {
            arr[i * 5 + j][i * 5 + j - 1] = 1;
        }
    }

    std::vector<std::vector<long long>> ans(5 * N, std::vector<long long>(5 * N));
    for(int i = 0; i < 5 * N; i++) ans[i][i] = 1;

	auto temp = arr;
	while (T > 0) {
		if (T % 2 == 1) ans = mult(ans, temp);

		temp = mult(temp, temp);
		T /= 2;
	}

	std::cout << ans[5 * (S - 1)][5 * (E - 1)];
}
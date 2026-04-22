#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int C, N, Q;

//trie
const int ROOT = 1;
int unused = 2;
const int MX = 5000 * 2000;
bool chk[MX];
int nxt[MX][26];

void insert(const std::string& str) {
	int cur = ROOT;

	for (char c : str) {
		if (nxt[cur][c - 'a'] == 0) {
			nxt[cur][c - 'a'] = unused++;
		}

		cur = nxt[cur][c - 'a'];
	}
	chk[cur] = true;
}

std::vector<int> find(const std::string& str) {//팀명에 대해 trie를 탐색, true를 만날 경우 해당 idx를 등록
	std::vector<int> ans;
	int idx = 0;
	int cur = ROOT;

	for (char c : str) {
		if (nxt[cur][c - 'a'] == 0) return ans;

		cur = nxt[cur][c - 'a'];
		if (chk[cur]) ans.push_back(idx);

		idx++;
	}

	return ans;
}

/*void erase(const std::string& str) {
	int cur = ROOT;

	for (char c : str) {
		if (nxt[cur][c - 'a'] == 0) {
			return;
		}

		cur = nxt[cur][c - 'a'];
	}

	chk[cur] = false;
}*/
//삭제 연산 필요 없음
//trie

//hash
std::unordered_map<std::string, int> um;
int um_idx;

int main(void) {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::cin >> C >> N;

	std::string str;
	for (int i = 0; i < C; i++) {
		std::cin >> str;
		insert(str);
	}

	for (int i = 0; i < N; i++) {
		std::cin >> str;
		um[str] = um_idx++;
	}

	std::cin >> Q;
	for (int i = 0; i < Q; i++) {
		std::cin >> str;

		std::vector<int> indices = find(str);
		bool valid = false;
		for (int index : indices) {
			if (index + 1 >= str.size()) continue;
			
			std::string nickname = str.substr(index + 1);
			if (um.find(nickname) != um.end()) {
				valid = true;
				break;
			}
		}

		if (valid) std::cout << "Yes\n";
		else std::cout << "No\n";
	}
}
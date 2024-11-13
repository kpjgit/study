//21276
#include <bits/stdc++.h>

int N, M;
std::string i_name[1001];
std::unordered_map<std::string, int> name_i;
std::vector<int> adj_list[1001]; //adj_list[i]의 i는 벡터에 포함된 사람의 조상

int indegree[1001];
std::vector<int> root;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 1; i <= N; i++) std::cin >> i_name[i];
    std::sort(i_name + 1, i_name + N + 1);

    for(int i = 1; i <= N; i++) name_i[i_name[i]] = i;

    std::cin >> M;
    std::string u, v;
    for(int i = 0; i < M; i++) {
        std::cin >> u >> v;
        adj_list[name_i[v]].push_back(name_i[u]);
        indegree[name_i[u]]++;
    }

    for(int i = 1; i <= N; i++) {
        if(indegree[i] == 0) root.push_back(i);
    }

    std::cout << root.size() <<'\n';
    for(int i : root) std::cout << i_name[i] << ' ';
    std::cout << '\n';

    for(int i = 1; i <= N; i++) {
        std::vector<int> temp;
        for(int dir : adj_list[i]) {
            if(indegree[dir] - indegree[i] == 1) temp.push_back(dir); //조상은 자손보다 진입차수가 낮으며 자식과 1 차이가 남
        }
        std::sort(temp.begin(), temp.end());

        std::cout << i_name[i] << ' ' << temp.size() << ' ';
        for(int i : temp) std::cout << i_name[i] <<' ';
        std::cout << '\n';
    }
}
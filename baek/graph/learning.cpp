//-1
#include <bits/stdc++.h>

int adj_matrix[10][10];
std::vector<int> adj_list[10];

void directed_graph_adj_matrix() {
    int n;
    std:: cin >> n;
    for(int i = 0; i < n; i++) {
        int st, en;
        std::cin >> st >> en;
        adj_matrix[st][en] = 1;
    }

    for(int i = 0; i < 10; i++) {
        for(auto e : adj_matrix[i]) {
            std::cout << e << ' ';
        }
        std::cout << '\n';
    }
}

void undirected_graph_adj_matrix() {
    int n;
    std:: cin >> n;
    for(int i = 0; i < n; i++) {
        int st, en;
        std::cin >> st >> en;
        adj_matrix[st][en] = 1;
        adj_matrix[en][st] = 1;
    }

    for(int i = 0; i < 10; i++) {
        for(auto e : adj_matrix[i]) {
            std::cout << e << ' ';
        }
        std::cout << '\n';
    }
}

void directed_graph_adj_list() {
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        int st, en;
        std::cin >> st >> en;
        adj_list[st].push_back(en);
    }

    for(int i = 0; i < 10; i++) {
        std:: cout << i <<": ";
        for(auto e : adj_list[i]) {
            std::cout << e << ' ';
        }
        std::cout << '\n';
    }
}

void undirected_graph_adj_list() {
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        int st, en;
        std::cin >> st >> en;
        adj_list[st].push_back(en);
        adj_list[en].push_back(st);
    }

    for(int i = 0; i < 10; i++) {
        std:: cout << i <<": ";
        for(auto e : adj_list[i]) {
            std::cout << e << ' ';
        }
        std::cout << '\n';
    }
}

void directed_graph_adj_list_without_stl() {
    int input[10][2];
    int deg[10] = {0};
    int *adj_list[10];
    int index[10] = {0};

    int v, e;
    std::cin >> v >> e;
    for(int i = 0; i < e; i++) {
        std::cin >> input[i][0] >> input[i][1];
        deg[input[i][0]]++;
    }

    for(int i = 0; i < v; i++) {
        adj_list[i] = new int[deg[i]];
    }
    for(int i = 0; i < e; i++) {
        adj_list[input[i][0]][index[input[i][0]]] = input[i][1];
        index[input[i][0]]++;
    }
    
    for(int i = 0; i < v; i++) {
        std::cout << i << ": ";
        for(int j = 0; j < deg[i]; j++) {
            std::cout << adj_list[i][j] << ' ';
        }
        std::cout << '\n';
    }

    for(int i = 0; i < v; i++) delete[] adj_list[i];
}

void undirected_graph_adj_list_without_stl() {
    int input[10][2];
    int deg[10] = {0};
    int *adj_list[10];
    int index[10] = {0};

    int v, e;
    std::cin >> v >> e;
    for(int i = 0; i < e; i++) {
        std::cin >> input[i][0] >> input[i][1];
        deg[input[i][0]]++;
    }

    for(int i = 0; i < v; i++) {
        adj_list[i] = new int[deg[i]];
    }
    for(int i = 0; i < e; i++) {
        adj_list[input[i][0]][index[input[i][0]]] = input[i][1];
        index[input[i][0]]++;
        adj_list[input[i][1]][index[input[i][1]]] = input[i][0];
        index[input[i][1]]++;
    }
    
    for(int i = 0; i < v; i++) {
        std::cout << i << ": ";
        for(int j = 0; j < deg[i]; j++) {
            std::cout << adj_list[i][j] << ' ';
        }
        std::cout << '\n';
    }

    for(int i = 0; i < v; i++) delete[] adj_list[i];
}

int main(void) {
    //directed_graph_adj_list_without_stl();
}
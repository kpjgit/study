#include <iostream>
#include <queue>
#include <tuple>

int N, M, P;
int player_move[9];
char board[1000][1000];

std::queue<std::pair<int, int>> prev[9];
int ans[9];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int bfs(int player, std::queue<std::pair<int, int>>& prev) {
    int cnt = 0;
    
    //x, y, 누적 거리
    std::queue<std::tuple<int, int, int>> q;
    while(!prev.empty()) {
        int x, y;
        std::tie(x, y) = prev.front();
        q.push({x, y, 0});
        prev.pop();
    }
    
    //여기에 bfs, 누적 거리가 player_move와 같아지면 prev에 push
    while(!q.empty()) {
        int x, y, len;
        std::tie(x, y, len) = q.front();
        q.pop();
        
        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
                
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(board[nx][ny] != '.') continue;
            
            board[nx][ny] = player + '1';
            int nxt_len = len + 1;
            cnt++;
            if(nxt_len < player_move[player]) {
               q.push({nx, ny, nxt_len}); 
            } else {
                prev.push({nx, ny});
            }
        }
    }
    
    return cnt;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> N >> M >> P;
    for(int i = 0; i < P; i++) {
        std::cin >> player_move[i];
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> board[i][j];
            
            //1000 * 1000 분기 예측 중 최대 실패 대략 20번, 성능 문제 없을듯
            if(board[i][j] != '.' && board[i][j] != '#') {
                int player = board[i][j] - '1';
                prev[player].push({i, j});
                ans[player]++;
            }
        }
    }
    
    bool is_final = false;
    while(!is_final) {
        int deadlock_cnt = 0;
        
        for(int i = 0; i < P; i++) {
            int cnt = bfs(i, prev[i]);
            ans[i] += cnt;
            if(cnt == 0) deadlock_cnt++;
        }
        
        if(deadlock_cnt == P) is_final = true;
    }
    
    for(int i = 0; i < P; i++ ) {
        std::cout << ans[i] << ' ';
    }
}
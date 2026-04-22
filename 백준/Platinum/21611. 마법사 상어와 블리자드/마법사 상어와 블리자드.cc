#include <iostream>
#include <algorithm>

int N, M;
int board[49][49];

int mid;
int table[49][49];
int arr[49 * 49];
int arr_temp[49 * 49];
int ans_cnt[4];
int len;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int find(int r, int c) {
    return table[r][c];
}

bool explosion() {
    int st = 0;
    bool ret = false;
    while(st < len && arr[st] != 0) {
        int en = st;
        while(en < len && arr[en] == arr[st]) en++;
        
        int cnt = en - st;
        if(cnt >= 4) {
            ret = true;
            for(int i = st; i < en; i++) {
                ans_cnt[arr[i]]++;
                arr[i] = 0;
            }
        }
        
        st = en;
    }
    
    return ret;
}

void clean() {
    std::fill(arr_temp, arr_temp + len, 0);
    int cur = 0;
    for(int i = 0; i < len; i++) {
        if(arr[i] == 0) continue;
        arr_temp[cur++] = arr[i];
    }
    
    for(int i = 0; i < len; i++) arr[i] = arr_temp[i];
}

void split() {
    std::fill(arr_temp, arr_temp + len, 0);
    int cur = 0;
    int st = 0;
    while(st < len && arr[st] != 0 && cur < len) {
        int en = st;
        while(en < len && arr[en] == arr[st]) en++;
        
        int cnt = en - st;
        if(cur < len) arr_temp[cur++] = cnt;
        if(cur < len) arr_temp[cur++] = arr[st];
        
        st = en;
    }
    
    
    for(int i = 0; i < len; i++) arr[i] = arr_temp[i];
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> board[i][j];
        }
    }
    mid = N / 2;
    len = N * N - 1;
    
    table[mid][mid] = -1;
    int cur_r = mid;
    int cur_c = mid;
    int dx_spiral[] = {0, 1, 0, -1};
    int dy_spiral[] = {-1, 0, 1, 0};
    int idx = 0;
    int step = 1;
    bool state = false;
    int dir = 0;
    while(idx < len) {
        for(int i = 0; i < step; i++) {
            cur_r += dx_spiral[dir];
            cur_c += dy_spiral[dir];
            
            table[cur_r][cur_c] = idx++;
            arr[table[cur_r][cur_c]] = board[cur_r][cur_c];
        }
        
        if(state) {
            step++;
            state = false;
        } else {
            state = true;
        }
        dir = (dir + 1) % 4;
    } //생각해보니 밖에서부터 채우는게 더 쉬운듯
    
    int d, s;
    for(int i = 0; i < M; i++) {
        std::cin >> d >> s;
        int r = mid;
        int c = mid;
        d--;
        for(int num = 0; num < s; num++) {
            r += dx[d];
            c += dy[d];
            
            int idx = find(r, c);
            arr[idx] = 0;
        }
        
        clean();
        while(explosion()) {
            clean();
        }
        
        split();
    }
    
    std::cout << ans_cnt[1] + 2 * ans_cnt[2] + 3 * ans_cnt[3];
}
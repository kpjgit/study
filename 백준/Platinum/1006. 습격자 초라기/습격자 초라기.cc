#include <bits/stdc++.h>

#define INF 20000

int T;
int N, W;
int arr[10000][2];

int dp[10001][3];
//dp[i][state]
//dp[i][0]: i-1 열까지 모두 채우고 i열은 비어있을 때 최소 소대수
//dp[i][1]: i-1 열까지 모두 채우고 i의 1행이 채워져있을 때 최소 소대수
//dp[i][2]: i-1 열까지 모두 채우고 i의 2행이 채워져있을 때 최소 소대수

int ans;
void func(int st) {
    for (int i = st; i < N; i++) {
        dp[i + 1][0] = std::min(dp[i][1] + 1, dp[i][2] + 1);
        if (arr[i][0] + arr[i][1] <= W) {
            dp[i + 1][0] = std::min(dp[i + 1][0], dp[i][0] + 1);
        }
        if (i > 0 && arr[i][0] + arr[i - 1][0] <= W && arr[i][1] + arr[i - 1][1] <= W) {
            //i-2까지 채우고 각 행에서 i-1~i를 동시에 커바할 경우 두개를 건너뛸 수 있다.
            dp[i + 1][0] = std::min(dp[i + 1][0], dp[i - 1][0] + 2);
        }
        //state가 0일 때 계산

        if (i < N - 1) {
            dp[i + 1][1] = dp[i + 1][0] + 1;
            if (arr[i][0] + arr[i + 1][0] <= W) {
                //i열까지 2행이 채워진 상태에서 가능하다
                dp[i + 1][1] = std::min(dp[i + 1][1], dp[i][2] + 1);
            }

            dp[i + 1][2] = dp[i + 1][0] + 1;
            if (arr[i][1] + arr[i + 1][1] <= W) {
                //마찬가지로 i열까지의 1행이 채워진 상태에서 전이된다
                dp[i + 1][2] = std::min(dp[i + 1][2], dp[i][1] + 1);
            }
        }
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> T;
    for (int tc = 0; tc < T; tc++) {
        std::cin >> N >> W;
        for (int i = 0; i < N; i++) std::cin >> arr[i][0];
        for (int i = 0; i < N; i++) std::cin >> arr[i][1];

        if (N == 1) {
            if (arr[0][0] + arr[0][1] > W) std::cout << "2\n";
            else std::cout << "1\n";
            continue;
        }

        //0과 N-1이 연결이 가능하므로 이를 반영한다
        ans = INF;
        //1, 2행 모두 N-1과 연결되지 않았을 때
        dp[0][0] = 0;
        dp[0][1] = 1;
        dp[0][2] = 1;
        func(0);
        ans = std::min(ans, dp[N][0]); //state가 0일때는 는 i-1까지 채워져 있으므로 이를 주의한다, N까지 계산을 해야함

        //1행이 N-1과 연결되었을 때
        if (arr[0][0] + arr[N - 1][0] <= W) {
            dp[1][0] = 1;
            dp[1][1] = 2;
            if (arr[0][1] + arr[1][1] <= W) dp[1][2] = 1;
            else dp[1][2] = 2;

            func(1); //i가 0일때는 이미 채워져있는 상태이고 i가 1부터 시작
            ans = std::min(ans, dp[N - 1][2] + 1);
        }
        
        //2행이 N-1과 연결되었을 때
        //여기부터는 i->i+1 상태로 전이하는 것을 반영하므로 N-1과 0열이 연결된 분대수는 처음에는 반영하지 않고 마지막에 더한다
        if (arr[0][1] + arr[N - 1][1] <= W) {
            dp[1][0] = 1;
            dp[1][2] = 2;
            if (arr[0][0] + arr[1][0] <= W) dp[1][1] = 1;
            else dp[1][1] = 2;

            func(1);
            ans = std::min(ans, dp[N - 1][1] + 1);
        }

        //1, 2행이 N-1과 연결되었을 때
        if (arr[0][0] + arr[N - 1][0] <= W && arr[0][1] + arr[N - 1][1] <= W) {
            dp[1][0] = 0;
            dp[1][1] = 1;
            dp[1][2] = 1;

            func(1);
            ans = std::min(ans, dp[N - 1][0] + 2);
        }

        std::cout << ans << '\n';
    }
}
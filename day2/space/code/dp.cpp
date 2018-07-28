#include <cstdio>

#include <vector>

using namespace std;

typedef long long ll;

const int P = 1000000007;

int main() {
	int k, n;
	scanf("%d%d", &k, &n);
	vector<vector<int> > dp(k + 1, vector<int>(n + 1));
	dp[0] = vector<int>(n + 1, 1);
	for (int i = 1; i <= k; ++i) {
		dp[i][0] = 1;
		for (int j = 1; j <= n; ++j)
			if ((dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1]) >= P)
				dp[i][j] -= P;
	}
	printf("%d\n", dp[k][n]);
	return 0;
}

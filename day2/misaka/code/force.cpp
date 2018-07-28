#include <cstdio>
#include <cstring>

#include <vector>

using namespace std;

typedef long long ll;

const int N = 2010;

int n;
ll cur;
int w[N], sub[N];
ll ans[N];

vector<int> adj[N];

void dfs(int u);

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &w[i]);
	for (int rep = 1; rep < n; ++rep) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int u = 1; u <= n; ++u) {
		memset(sub, 0, sizeof(sub));
		cur = 0;
		dfs(u);
		if (u == n)
			printf("%lld\n", cur);
		else
			printf("%lld ", cur);
	}
	return 0;
}

void dfs(int u) {
	sub[u] = 1;
	for (int i = 0; i < adj[u].size(); ++i)
		if (!sub[adj[u][i]]) {
			dfs(adj[u][i]);
			cur += sub[u] * (ll)sub[adj[u][i]] * w[u];
			sub[u] += sub[adj[u][i]];
		}
}

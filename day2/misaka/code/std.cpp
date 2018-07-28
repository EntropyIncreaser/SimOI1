#include <cstdio>
#include <cstring>

#include <vector>

using namespace std;

typedef long long ll;

const int N = 500010;

int n;
ll cur;
int w[N], sub[N];
ll ans[N];
bool vis[N];

vector<int> adj[N];

void dfs(int u);
void tour(int u);

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
	dfs(1);
	tour(1);
	for (int i = 1; i < n; ++i)
		printf("%lld ", ans[i]);
	printf("%lld\n", ans[n]);
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

void tour(int u) {
	ans[u] = cur;
	vis[u] = true;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (!vis[v]) {
			cur += sub[v] * (ll)(n - sub[v]) * (w[v] - w[u]);
			tour(v);
			cur -= sub[v] * (ll)(n - sub[v]) * (w[v] - w[u]);
		}
	}
}

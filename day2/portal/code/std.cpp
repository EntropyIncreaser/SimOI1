#include <cstdio>
#include <cstring>

#include <algorithm>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

struct Node {
	int u, step;

	Node() {}

	Node(int u, int step) : u(u), step(step) {}

	bool operator>(const Node& rhs) const { return step > rhs.step; }
};

const int N = 10010, M = 100010, LGN = 14, V = N * LGN * 2;

int n, m, s;
int cnt;

int lgt[N];
int sti[N][LGN], sto[N][LGN];

int dis[V];

vector<pair<int, int> > adj[V];

void adde(int u, int v, int w) {
	printf("w(%d, %d) = %d\n", u, v, w);
	adj[u].push_back(make_pair(v, w));
}

void link(int u, int v, int x, int y, int t) {
	int l1 = lgt[v - u + 1], l2 = lgt[y - x + 1];
	adde(sto[v][l1], sti[y][l2], t);
	adde(sto[v][l1], sti[x + (1 << l2) - 1][l2], t);
	adde(sto[u + (1 << l1) - 1][l1], sti[y][l2], t);
	adde(sto[u + (1 << l1) - 1][l1], sti[x + (1 << l2) - 1][l2], t);
}

int main() {
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 2; i <= n; ++i)
		lgt[i] = lgt[i >> 1] + 1;
	for (int i = 1; i <= n; ++i) {
		sti[i][0] = ++cnt;
		for (int j = 1; (1 << j) <= i; ++j) {
			sti[i][j] = ++cnt;
			adde(cnt, sti[i][j - 1], 0);
			adde(cnt, sti[i - (1 << (j - 1))][j - 1], 0);
		}
	}
	for (int i = 1; i <= n; ++i) {
		sto[i][0] = sti[i][0];
		for (int j = 1; (1 << j) <= i; ++j) {
			sto[i][j] = ++cnt;
			adde(sto[i][j - 1], cnt, 0);
			adde(sto[i - (1 << (j - 1))][j - 1], cnt, 0);
		}
	}
	while (m--) {
		int u, v, x, y, t;
		scanf("%d%d%d%d%d", &u, &v, &x, &y, &t);
		if (u > v)
			swap(u, v);
		if (x > y)
			swap(x, y);
		link(u, v, x, y, t);
		link(x, y, u, v, t);
	}

	priority_queue<Node, vector<Node>, greater<Node> > q;
	memset(dis, -1, sizeof(dis));
	q.push(Node(sti[s][0], dis[sti[s][0]] = 0));
	while (!q.empty()) {
		Node tmp = q.top();
		q.pop();
		if (tmp.step != dis[tmp.u])
			continue;
		for (int i = 0; i < adj[tmp.u].size(); ++i) {
			int v = adj[tmp.u][i].first, w = adj[tmp.u][i].second;
			if (dis[v] == -1 || dis[v] > tmp.step + w)
				q.push(Node(v, dis[v] = tmp.step + w));
		}
	}
	for (int i = 1; i < n; ++i)
		printf("%d ", dis[sti[i][0]]);
	printf("%d\n", dis[sti[n][0]]);
	return 0;
}

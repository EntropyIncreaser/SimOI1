#include <cstring>

#include "testlib.h"

const int N = 1e5 + 10;

int goal[N], p[N];
bool vis[N];

int main(int argc, char** argv) {
	registerTestlibCmd(argc, argv);

	int n = inf.readInt(1, 100000), k = inf.readInt(1, 200000);
	for (int i = 1; i <= n; ++i)
		goal[i] = inf.readInt(1, n);
	for (int i = 1; i <= n; ++i) {
		quitif(vis[goal[i]], _fail, "Wrong input: No two spirits should stay at the same place.");
		vis[goal[i]] = true;
	}

	memset(vis, 0, sizeof(vis));

	for (int i = 1; i <= n; ++i) {
		p[i] = ouf.readInt(1, n);
		quitif(vis[p[i]], _wa, "No two place should have the same destination.");
		vis[p[i]] = true;
	}

	for (int i = 1; i <= n; ++i) {
		if (!vis[i])
			continue;
		int x = i, cyc = 0;
		while (vis[x]) {
			vis[x] = false;
			++cyc;
			x = p[x];
		}
		int delt = k % cyc;
		x = i;
		int y = i;
		while (delt--)
			y = p[y];
		while (cyc--) {
			quitif(y != goal[x], _wa, "The %dth spirit go to the wrong place, expected = %d, found = %d", x, goal[x], y);
			x = p[x];
			y = p[y];
		}
	}

	quit(_ok, "The answer is correct.");
}

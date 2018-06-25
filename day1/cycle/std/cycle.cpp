#include <cstdio>
#include <cassert>

#include <vector>

using namespace std;

typedef long long ll;

const int N = 100010;

int n, k;
int g[N], p[N];
bool f[N];

vector<vector<int> > cyc[N];

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
//	freopen("cycle.in", "r", stdin);
//	freopen("cycle.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &g[i]);
	for (int i = 1; i <= n; ++i) {
		if (f[i])
			continue;
		vector<int> c;
		int x = i;
		while (!f[x]) {
			c.push_back(x);
			f[x] = true;
			x = g[x];
		}
		cyc[c.size()].push_back(c);
	}
	for (int d = 1; d <= n; ++d) {
		if (cyc[d].empty())
			continue;
		vector<vector<int> >& cycd = cyc[d];
		int g = gcd(cycd.size(), k);
		int j = k / g, a = 1;
		// assert(gcd(d, j) == 1);
		while (a * (ll)j % d != 1 % d)
			++a;
		for (int ii = 0; ii < cyc[d].size(); ii += g) {
			for (int ij = 0; ij < g; ++ij) {
				int ci = ii + ij;
				for (int i = 0; i < d; ++i)
					::g[cycd[ci][i]] = cycd[ci][(i + a) % d];
				int x = cycd[ci][0];
				for (int i = 0; i < d; ++i) {
					cycd[ci][i] = x;
					x = ::g[x];
				}
			}
			int lst = cycd[ii + g - 1][d - 1];
			for (int i = 0; i < d; ++i) {
				for (int ij = 0; ij < g; ++ij) {
					int ci = ii + ij;
					p[lst] = cycd[ci][i];
					lst = cycd[ci][i];
				}
			}
			p[lst] = cycd[ii][0];
		}
	}
	for (int i = 1; i < n; ++i)
		printf("%d ", p[i]);
	printf("%d\n", p[n]);
	return 0;
}

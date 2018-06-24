#include <cstdio>
#include <cstring>

#include <map>

using namespace std;

typedef long long ll;

const int N = 10, C = 132;
const int P = 1e9 + 7;

int k, c;

struct Mat {
	int g[C][C];

	Mat() { memset(g, 0, sizeof(g)); }
	Mat(const Mat& x) { memcpy(g, x.g, sizeof(g)); }

	const int* operator[](int k) const { return g[k]; }
	int* operator[](int k) { return g[k]; }

	Mat operator*(const Mat& rhs) const {
		Mat ret = Mat();
		for (int i = 0; i < c; ++i)
			for (int j = 0; j < c; ++j)
				for (int k = 0; k < c; ++k)
					ret[i][j] = (ret[i][j] + (ll) g[i][k] * rhs[k][j]) % P;
		return ret;
	}
};

Mat rowt, colt;
int ans[C];
int cur[N], tmp[N], fl[N];
map<int, int> difcc;

int* operator*=(int* vec, const Mat& rhs);

int find(int* f, int x) { return f[x] == x ? x : f[x] = find(f, f[x]); }

void pre(int id);
int toid(int* cc);
void tocc(int x, int* cc);

int main() {
//	freopen("road.in", "r", stdin);
//	freopen("road.out", "w", stdout);

	int n;
	scanf("%d%d", &k, &n);
	--n;
	pre(0);

	for (map<int, int>::iterator it = difcc.begin(); it != difcc.end(); ++it) {
		int key = it->first, u = it->second;
		for (int s = 0; s < (1 << (k - 1)); ++s) {
			tocc(key, cur);
			bool flag = false;
			for (int i = 1; i < k; ++i)
				if ((s >> (i - 1)) & 1) {
					int x = find(cur, i - 1), y = find(cur, i);
					if (x == y) {
						flag = true;
						break;
					} else {
						if (x > y)
							swap(x, y);
						cur[y] = x;
					}
				}
			if (flag)
				continue;
			++rowt[u][difcc[toid(cur)]];
		}
	}

	for (map<int, int>::iterator it = difcc.begin(); it != difcc.end(); ++it) {
		int key = it->first, u = it->second;
		tocc(key, cur);
		for (int s = 0; s < (1 << k); ++s) {
			memset(tmp, -1, sizeof(int) * k);
			for (int i = 0; i < k; ++i)
				if ((s >> i) & 1) {
					if (tmp[cur[i]] == -1)
						tmp[cur[i]] = i;
					fl[i] = tmp[cur[i]];
				} else
					fl[i] = i;
			bool flag = false;
			for (int i = 0; i < k; ++i)
				if (tmp[cur[i]] == -1) {
					flag = true;
					break;
				}
			if (!flag)
				++colt[u][difcc[toid(fl)]];
		}
	}

	ans[c - 1] = 1;
	ans *= rowt;
	Mat m = colt * rowt;
	while (n) {
		if (n & 1)
			ans *= m;
		m = m * m;
		n >>= 1;
	}
	printf("%d\n", ans[0]);
	return 0;
}

void tocc(int x, int* cc) {
	for (int i = k - 1; i >= 0; --i) {
		cc[i] = x % k;
		x /= k;
	}
}

void pre(int id) {
	static int p[N];
	if (id == k) {
		difcc.insert(make_pair(toid(p), c++));
		return;
	}
	for (p[id] = 0; p[id] <= id; ++p[id]) {
		if (p[p[id]] != p[id])
			continue;
		bool flag = false;
		for (int i = p[id] + 1; i < id; ++i)
			if (p[i] < p[id]) {
				flag = true;
				break;
			}
		if (!flag)
			pre(id + 1);
	}
}

int toid(int* cc) {
	int cur[N];
	memcpy(cur, cc, sizeof(int) * k);
	int x = 0;
	for (int i = 0; i < k; ++i) {
		cur[i] = cur[cur[i]];
		x = x * k + cur[i];
	}
	return x;
}

int* operator*=(int* vec, const Mat& rhs) {
	int tmp[C];
	memset(tmp, 0, sizeof(int) * c);
	for (int i = 0; i < c; ++i)
		for (int j = 0; j < c; ++j)
			tmp[j] = (tmp[j] + (ll) vec[i] * rhs[i][j]) % P;
	memcpy(vec, tmp, sizeof(int) * c);
	return vec;
}

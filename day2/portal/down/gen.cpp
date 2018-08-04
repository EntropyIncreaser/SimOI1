#include <algorithm>
#include <vector>
#include <iostream>
#include <random>

using namespace std;

struct Ed {
	int u, v, x, y, t;

	Ed() {}

	Ed(int u, int v, int x, int y, int t) : u(u), v(v), x(x), y(y), t(t) {}
};

typedef void(*Shuff)(vector<Ed>&);
typedef int(*Rng)();
typedef vector<Ed>(*Gen)(int, const Rng&);

random_device rd;
mt19937 mt(rd());

void testcase(int n, const Rng& rng, const Gen& gen, const Shuff& shuff, int caseid);

int wt() { return mt() % 100001; }
int w0() { return 0; }
int w1() { return 1; }

void simp(vector<Ed>& ed);
void evil(vector<Ed>& ed);

vector<Ed> grid(int n, const Rng& rng);
vector<Ed> rnd(int n, const Rng& rng);
vector<Ed> spec(int n, const Rng& rng);
vector<Ed> limm(int n, const Rng& rng);
vector<Ed> lit(int n, const Rng& rng);

int main() {
	testcase(200, wt, rnd, simp, 2);
	testcase(1000, w0, lit, simp, 3);
	testcase(1000, wt, rnd, simp, 4);
	return 0;
}

vector<Ed> lit(int n, const Rng& rng) {
	vector<Ed> ret;
	for (int rep = 1; rep <= n / 3 * 2; ++rep) {
		int u = mt() % n + 1, v = mt() % n + 1;
		ret.emplace_back(u, u, v, v, rng());
	}
	for (int rep = 1; rep <= n / 10; ++rep) {
		int a = mt() % n + 1, b = mt() % n + 1, x = mt() % n + 1, y = mt() % n + 1;
		if (b < a)
			swap(a, b);
		if (y < x)
			swap(x, y);
		b = min(b, a + 10);
		y = min(y, x + 10);
		ret.emplace_back(a, b, x, y, rng());
	}
	return ret;
}

vector<Ed> limm(int n, const Rng& rng) {
	int l = sqrt(n) / 2, r = sqrt(n) * 2;
	int x = mt() % (r - l + 2) + l;
	vector<Ed> ret;
	for (int i = 1; i < n; i += 2)
		ret.emplace_back(i, i + 1, i + 2, i + 3, rng());
	for (int i = 1; i + x + 5 <= n; i += 10)
		ret.emplace_back(i, i + 5, i + x, i + x + 5, rng());
	return ret;
}

vector<Ed> grid(int n, const Rng& rng) {
	int l = sqrt(n) / 2, r = sqrt(n) * 2;
	int x = mt() % (r - l + 2) + l;
	vector<Ed> ret;
	for (int i = 1; i < n; ++i)
		ret.emplace_back(i, i, i + 1, i + 1, rng());
	for (int i = 1; i + x <= n; ++i)
		ret.emplace_back(i, i, i + x, i + x, rng());
	return ret;
}

vector<Ed> rnd(int n, const Rng& rng) {
	vector<Ed> ret = grid(n, rng);
	int l = sqrt(n) / 2, r = sqrt(n) * 2;
	for (int rep = 0; rep < n * 4; ++rep) {
		int u = mt() % n + 1, x = mt() % n + 1;
		int v = min(n, int(u + (mt() % 10) + 1)), y = min(n, int(x + (mt() % 10) + 1));
		ret.emplace_back(u, v, x, y, rng());
	}
	return ret;
}

vector<Ed> spec(int n, const Rng& rng) {
	vector<Ed> ret = grid(n, rng);
	int l = sqrt(n) / 2, r = sqrt(n) * 2;
	for (int rep = 0; rep < n * 4; ++rep) {
		int u = mt() % n + 1, x = mt() % n + 1;
		int v = min(n, int(u + (mt() % 10) + 1)), y = x;
		ret.emplace_back(u, v, x, y, rng());
	}
	return ret;
}

void simp(vector<Ed>& ed) {
	shuffle(ed.begin(), ed.end(), mt);
}

void evil(vector<Ed>& ed) {
	simp(ed);
	for (auto& e : ed) {
		if (mt() & 1)
			swap(e.u, e.v);
		if (mt() & 1)
			swap(e.x, e.y);
	}
}

void testcase(int n, const Rng& rng, const Gen& gen, const Shuff& shuff, int caseid) {
	string filename = to_string(caseid) + ".in";
	freopen(filename.c_str(), "w", stdout);
	cerr << "Generating test \"" << filename << '\"' << endl;
	vector<Ed> ed = gen(n, rng);
	int m = 1;
	for (int rep = 0; rep < 10; ++rep)
		m = max(m, int(mt() % n + 1));
	if (n <= 1000 && m < ed.size())
		ed.resize(m);
	shuff(ed);
	int l = ed[0].u, r = ed[0].v;
	if (l > r)
		swap(l, r);
	cout << n << ' ' << ed.size() << ' ' << (mt() % (r - l + 2) + l) << endl;
	for (Ed e : ed)
		cout << e.u << ' ' << e.v << ' ' << e.x << ' ' << e.y << ' ' << e.t << endl;
	fclose(stdout);
	cerr << "Finished test \"" << filename << '\"' << endl;
}

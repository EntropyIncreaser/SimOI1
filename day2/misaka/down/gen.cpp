#include <vector>
#include <iostream>
#include <random>

using namespace std;

typedef vector<pair<int, int> > EdgeV;
typedef EdgeV(*Generator)(int);

const int W = 100000;

random_device rd;
mt19937 mt(rd());

void testcase(int n, const Generator& generator, int caseid);

EdgeV simple(int n);
EdgeV bin(int n);
EdgeV chain(int n);
EdgeV flower(int n);
EdgeV hard(int n);

int main() {
	testcase(3, simple, 1);
	testcase(500, simple, 2);
	testcase(50000, bin, 3);
	testcase(500000, simple, 4);
	return 0;
}

EdgeV simple(int n) {
	EdgeV ret;
	for (int i = 2; i <= n; ++i)
		ret.emplace_back(i, mt() % (i - 1) + 1);
	return ret;
}

EdgeV bin(int n) {
	EdgeV ret;
	for (int i = 2; i <= n; ++i)
		ret.emplace_back(i, i / 2);
	return ret;
}

EdgeV chain(int n) {
	EdgeV ret;
	for (int i = 2; i <= n; ++i)
		ret.emplace_back(i, i - 1);
	return ret;
}

EdgeV flower(int n) {
	EdgeV ret;
	for (int i = 2; i <= n; ++i)
		ret.emplace_back(i, 1);
	return ret;
}

EdgeV hard(int n) {
	EdgeV ret;
	for (int i = 2; i <= n; ++i) {
		int l = max(1, i - 20), r = i - 1;
		ret.emplace_back(i, mt() % (r - l + 1) + l);
	}
	return ret;
}

void testcase(int n, const Generator& generator, int caseid) {
	string filename = to_string(caseid) + ".in";
	freopen(filename.c_str(), "w", stdout);
	cerr << "Generating test \"" << filename << '\"' << endl;
	cout << n << endl;
	for (int i = 1; i < n; ++i)
		cout << (mt() % W + 1) << ' ';
	cout << (mt() % W + 1) << endl;
	EdgeV edges = generator(n);
	shuffle(edges.begin(), edges.end(), mt);
	for (auto&& e : edges) {
		if (mt() & 1)
			swap(e.first, e.second);
		cout << e.first << ' ' << e.second << endl;
	}
	fclose(stdout);
	cerr << "Finished test \"" << filename << '\"' << endl;
}

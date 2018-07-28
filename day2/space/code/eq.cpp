#include <cstdio>

using namespace std;

typedef long long ll;

const int P = 1000000007;

int main() {
	int k, n;
	scanf("%d%d", &k, &n);
	int ans = 1, pw = 2;
	while (n) {
		if (n & 1)
			ans = ans * (ll)pw % P;
		pw = pw * (ll)pw % P;
		n >>= 1;
	}
	printf("%d\n", ans);
	return 0;
}

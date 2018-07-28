#include <cstdio>

using namespace std;

typedef long long ll;

const int N = 1000010;
const int P = 1000000007;

int fac[N], inv[N], ifac[N];

int main() {
	int k, n;
	scanf("%d%d", &k, &n);
	fac[0] = 1;
	for (int i = 1; i <= n; ++i)
		fac[i] = fac[i - 1] * (ll)i % P;
	inv[1] = 1;
	for (int i = 2; i <= n; ++i)
		inv[i] = (-(P / i) * (ll)inv[P % i] % P) + P;
	ifac[0] = 1;
	for (int i = 1; i <= n; ++i)
		ifac[i] = ifac[i - 1] * (ll)inv[i] % P;
	int ans = 0;
	for (int i = 0; i <= k && i <= n; ++i)
		ans = (ans + fac[n] * (ll)ifac[i] % P * ifac[n - i]) % P;
	printf("%d\n", ans);
	return 0;
}

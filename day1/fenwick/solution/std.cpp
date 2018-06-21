#include <cstdio>

using namespace std;

typedef long long ll;

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int ans = 0;
		ll x, y;
		scanf("%lld%lld", &x, &y);
		while (x != y) {
			++ans;
			if (x > y)
				y += y & -y;
			else
				x += x & -x;
		}
		printf("%d\n", ans);
	}
	return 0;
}

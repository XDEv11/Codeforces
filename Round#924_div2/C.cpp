//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int p, n;
	cin >> p >> n;

	// q = p % (2k - 2)
	// q = n | q <= k
	// q = 2k - n | q > k
	int ans{};

	int x{p - n};
	for (int i{1}; i * i <= x; ++i) {
		if (x % i) continue;
		ans += (i % 2 == 0 && n <= (i + 2) / 2);
		int j{x / i};
		ans += (j != i && j % 2 == 0 && n <= (j + 2) / 2);
	}

	if (n >= 2) {
		int y{p + (n - 2)};
		for (int i{1}; i * i <= y; ++i) {
			if (y % i) continue;
			ans += (i % 2 == 0 && i - (n - 2) > (i + 2) / 2);
			int j{y / i};
			ans += (j != i && j % 2 == 0 && j - (n - 2) > (j + 2) / 2);
		}
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

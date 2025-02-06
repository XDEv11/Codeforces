//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> v(m);
	for (auto& x : v) cin >> x, --x;

	sort(v.begin(), v.end());

	int ans{m - 2};

	vector<int> t{};
	for (int i{0}; i < m; ++i) {
		int x{(v[i] + 1) % n}, y{v[(i + 1) % m]};
		int d{(y - x + n) % n};
		if (d == 1) ++ans;
		else if (d) t.push_back(d);
	}

	sort(t.begin(), t.end(),
		[](int a, int b) {
			if (a % 2 == b % 2) return a < b;
			else return a % 2 > b % 2;
		}
	);
	for (auto& x : t) {
		if (x % 2 && k >= x / 2) ans += 2 * (x / 2) + 1, k -= x / 2;
		else {
			int tt{min(x / 2, k)};
			ans += 2 * tt, k -= tt;
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

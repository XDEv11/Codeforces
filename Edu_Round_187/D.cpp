//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <numeric>

#include <cstdint>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n, m;
		cin >> n >> m;
		ll l{1};
		vector<uint8_t> a(n + m + 1);
		for (int i{0}; i < n; ++i) {
			int x;
			cin >> x;
			a[x] = true;
			if (l <= n + m) l = lcm(l, x);
		}
		vector<int> b(m);
		for (auto& x : b) cin >> x;

		for (int j{1}; j <= n + m; ++j) {
			if (a[j] != 1) continue;
			for (int k{j * 2}; k <= n + m; k += j) a[k] = 2;
		}

		int c{}, d{};
		for (auto& x : b) {
			if (x % l == 0) ++c;
			else if (!a[x]) --c;
			else ++d;
		}
		c += (d & 1);

		cout << (c > 0 ? "Alice\n" : "Bob\n");
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		vector<int> c(n + 1);
		for (auto& x : v) ++c[x];

		int ans{};
		for (int i{0}; i <= n; ++i) {
			if (!c[i] || c[i] == i) continue;
			if (c[i] < i) ans += c[i];
			else ans += c[i] - i;
		}

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

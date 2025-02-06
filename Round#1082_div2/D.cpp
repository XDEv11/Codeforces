//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n, m;
		cin >> n >> m;
		if (clamp(m, n, n * 2 - 1) != m) return cout << "NO\n", []{}();

		vector<int> ans{};
		while (m < n * 2 - 1) {
			ans.push_back(n), ans.push_back(n);
			--n, --m;
		}
		if (n >= 2) {
			ans.push_back(1), ans.push_back(2);
			for (int k{3}; k <= n; ++k) ans.push_back(k), ans.push_back(k - 2);
			ans.push_back(n - 1), ans.push_back(n);
		} else ans.push_back(1), ans.push_back(1);

		cout << "YES\n";
		for (auto& x : ans) cout << x << ' ';
		cout << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

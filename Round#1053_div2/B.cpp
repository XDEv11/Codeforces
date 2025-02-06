//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	void solve() {
		int n, m;
		cin >> n >> m;
		vector<char> a(n);
		vector<int> b(m);
		for (auto& x : a) cin >> x;
		for (auto& x : b) cin >> x;

		vector<int> ans{};
		int j{0}, k{1};
		if (b[0] == 1) ans.push_back(1), j = 1;
		for (int i{0}; i < n; ++i) {
			if (i && a[i - 1] == 'B') {
				while (j < m && b[j] == k + 1) ans.push_back(++k), ++j;
				++k;
			}
			if (a[i] == 'A') {
				ans.push_back(++k);
				if (j < m && b[j] == k) ++j;
			} else {
				while (j < m && b[j] == k + 1) ans.push_back(++k), ++j;
				ans.push_back(++k);
			}
		}
		while (j < m) ans.push_back(b[j++]);

		cout << ans.size() << '\n';
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

//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n - 1);
		for (auto& x : v) cin >> x;

		vector<int> ans{};
		ans.push_back(v[0]);
		for (int i{0}; i + 1 < n - 1; ++i) ans.push_back(v[i] | v[i + 1]);
		ans.push_back(v[n - 2]);

		for (int i{0}; i < n - 1; ++i) {
			if ((ans[i] & ans[i + 1]) != v[i]) return cout << "-1\n", []{}();
		}

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

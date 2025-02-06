//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		auto s{v};
		sort(s.begin(), s.end());

		bool f{true};
		int ans{s.back() - s.front()};
		for (int i{0}; i < n; ++i) {
			if (v[i] == s[i]) continue;
			f = false,
			ans = min(ans, max(v[i] - s.front(), s.back() - v[i]));
		}
		if (f) return void(cout << "-1\n");

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

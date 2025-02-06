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

		vector<int> cnt(n + 1);
		for (auto& x : v) ++cnt[x];

		int ans{}, l, r;
		for (int i{0}, j{0}; i < n; ++i) {
			if (cnt[v[i]] == 1) {
				if (i - j + 1 > ans) ans = i - j + 1, l = j, r = i;
			} else j = i + 1;
		}

		if (!ans) cout << "0\n";
		else cout << (l + 1) << ' ' << (r + 1) << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

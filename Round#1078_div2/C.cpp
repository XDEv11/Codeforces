//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	void solve() {
		int n, m;
		cin >> n >> m;
		vector<int> v(n);
		while (m--) {
			for (int i{0}; i < n; ++i) {
				char c;
				cin >> c;
				v[i] |= (1 << (c - 'a'));
			}
		}

		for (int k{1}; k <= n; ++k) {
			if (n % k) continue;
			vector<int> t(k, ~0);
			for (int i{0}; i < n; ++i) t[i % k] &= v[i];

			bool f{true};
			for (auto& x : t) f = f && x;
			if (!f) continue;

			vector<char> ans(k);
			for (int i{0}; i < k; ++i) {
				int b{1}; char c{'a'};
				while (!(b & t[i])) b <<= 1, ++c;
				ans[i] = c;
			}

			for (int i{0}; i < n; ++i) cout << ans[i % k];
			cout << '\n';
			return ;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

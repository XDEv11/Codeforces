//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>

using namespace std;

namespace {
	void solve() {
		int n, q;
		cin >> n >> q;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		vector<int> ps(n + 1);
		for (int i{0}; i < n; ++i) ps[i + 1] = ps[i] ^ v[i];

		vector<array<int, 30>> p(n + 1);
		p[0].fill(-1);
		for (int i{0}; i < n; ++i) {
			int k{29};
			while (!(v[i] & (1 << k))) --k;
			for (int j{29}; j > k; --j) p[i + 1][j] = p[i][j];
			for (int j{k}; j >= 0; --j) p[i + 1][j] = i;
		}

		while (q--) {
			int x;
			cin >> x;

			int ans{}, i{n - 1};
			while (i >= 0 && x) {
				int k{29};
				while (!(x & (1 << k))) --k;

				int j{p[i + 1][k]};
				ans += i - j;
				x ^= (ps[i + 1] ^ ps[j + 1]);
				if (j != -1 && x >= v[j]) {
					++ans;
					x ^= v[j];
					i = j - 1;
				} else break;
			}

			cout << ans << ' ';
		}
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

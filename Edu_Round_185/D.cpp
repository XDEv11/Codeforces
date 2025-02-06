//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n, m;
		cin >> n >> m;
		vector<char> v(n);
		for (auto& x : v) cin >> x;

		int s{}, q{}, qb{}, qg{}, qd{}, qq{};
		for (int i{n - 1}, f{false}; i >= 0; --i) {
			if (v[i] != '?') f = false;
			switch (v[i]) {
				break; case 'X': s += 10;
				break; case 'V': s += 5, v[i] = 'X';
				break; case 'I': s += ((i + 1 < n && v[i + 1] == 'X') ? -1 : 1);
				break; case '?':
					++q;
					bool fb{i && v[i - 1] == 'I'}, fg{i + 1 < n && v[i + 1] == 'X'};
					if (fb && fg) ++qd;
					else if (fb) ++qb;
					else if (fg) ++qg;
					else if (f) ++qq, f = false;
					else f = true;
			}
		}

		while (m--) {
			array<int, 3> a;
			for (auto& x : a) cin >> x;

			if (a[2] >= q) a[0] = a[1] = 0, a[2] = q;
			else if (a[1] + a[2] >= q) a[0] = 0, a[1] = q - a[2];
			else a[0] = q - (a[1] + a[2]);

			int ans{[&, s, qd] mutable {
				s += 10 * a[0] + 5 * a[1] + 1 * a[2];

				a[1] += a[0];
				int t{min(qb, a[1])};
				a[1] -= t, s -= 2 * t;
				
				t = min(qg, a[2]);
				a[2] -= t, s -= 2 * t;

				if (a[1] >= a[2]) {
					t = min(qd, a[1] - a[2]);
					a[1] -= t, qd -= t, s -= 2 * t;
				} else {
					t = min(qd, a[2] - a[1]);
					a[2] -= t, qd -= t, s -= 2 * t;
				}
				t = min(qd, a[1] + a[2]);
				a[1] -= t / 2, a[2] -= (t + 1) / 2, s -= 2 * t;

				t = min({qq, a[1], a[2]});
				s -= 2 * t;

				return s;
			}()};

			cout << ans << '\n';
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

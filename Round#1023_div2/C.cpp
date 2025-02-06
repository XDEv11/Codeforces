//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n; ll m;
		cin >> n >> m;
		vector<char> a(n);
		vector<ll> b(n);
		for (auto& x : a) cin >> x;
		for (auto& x : b) cin >> x;

		if (count(a.begin(), a.end(), '1') == n) {
			ll mx{b[0]}, c{0};
			for (auto& x : b) mx = max(mx, c = max(0ll, c) + x);
			if (mx == m) {
				cout << "Yes\n";
				for (auto& x : b) cout << x << ' ';
				cout << '\n';
			} else cout << "No\n";
			return ;
		}

		for (int i{0}; i < n; ++i) {
			if (a[i] == '0') continue;
			int j{i};
			ll mx{b[j]}, c{0};
			for (; j < n && a[j] == '1'; ++j) mx = max(mx, c = max(0ll, c) + b[j]);
			if (mx > m) return cout << "No\n", []{}();
			i = j;
		}

		for (int i{0}; i < n; ++i) {
			if (a[i] == '1') continue;
			int j{i - 1};
			ll mx1{0}, s1{0};
			for (; j >= 0 && a[j] == '1'; --j) mx1 = max(mx1, s1 += b[j]);
			int k{i + 1};
			ll mx2{0}, s2{0};
			for (; k < n && a[k] == '1'; ++k) mx2 = max(mx2, s2 += b[k]);
			b[i] = m - mx1 - mx2;

			ll mx{b[j + 1]}, c{0};
			for (int ii{j + 1}; ii < k; ++ii) mx = max(mx, c = max(0ll, c) + b[ii]);
			if (mx == m) {
				cout << "Yes\n";
				for (int ii{0}; ii < n; ++ii) {
					if (ii != i && a[ii] == '0') cout << -1000000000000000000ll;
					else cout << b[ii];
					cout << ' ';
				}
				cout << '\n';
				return ;
			}
		}
		cout << "No\n";
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

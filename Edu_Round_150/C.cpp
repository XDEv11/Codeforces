//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	string s{};
	cin >> s;
	int n{s.size()};

	vector<int> v(n);
	for (int i{0}; i < n; ++i) v[i] = (s[n - 1 - i] - 'A');
	array<ll, 5> w{1, 10, 100, 1000, 10000};

	ll ans;
	{
		ll cnt{};
		int mx{0};
		for (int i{0}; i < n; ++i) {
			cnt += (mx > v[i] ? -1 : 1) * w[v[i]];
			mx = max(mx, v[i]);
		}
		ans = cnt;
	}
	array<int, 5> fi; fi.fill(-1);
	for (int i{n - 1}; i >= 0; --i) fi[v[i]] = i;
	for (int j{0}; j < 5; ++j) {
		for (int k{0}; k < j; ++k) {
			ll cnt{};
			int mx{0};
			for (int i{0}; i < n; ++i) {
				if (fi[j] == i) v[i] = k;
				cnt += (mx > v[i] ? -1 : 1) * w[v[i]];
				mx = max(mx, v[i]);
				if (fi[j] == i) v[i] = j;
			}
			ans = max(ans, cnt);
		}
	}
	array<int, 5> la; la.fill(-1);
	for (int i{0}; i < n; ++i) la[v[i]] = i;
	for (int j{0}; j < 5; ++j) {
		for (int k{j + 1}; k < 5; ++k) {
			ll cnt{};
			int mx{0};
			for (int i{0}; i < n; ++i) {
				if (la[j] == i) v[i] = k;
				cnt += (mx > v[i] ? -1 : 1) * w[v[i]];
				mx = max(mx, v[i]);
				if (la[j] == i) v[i] = j;
			}
			ans = max(ans, cnt);
		}
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

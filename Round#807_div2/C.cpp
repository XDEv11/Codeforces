//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second

using namespace std;
using ll = long long;

void solve() {
	int n, c, q;
	cin >> n >> c >> q;
	vector<char> s(n);
	for (auto& x : s) cin >> x;
	vector<pair<ll, ll>> v(c);
	for (auto& [l, r] : v) cin >> l >> r, --l;

	ll tot{n};
	for (auto& [l, r] : v) tot += r - l;

	while (q--) {
		ll p;
		cin >> p, --p;
		auto len{tot};
		for (int i{c - 1}; i >= 0; --i) {
			auto& [l, r]{v[i]};
			auto len_next{len - (r - l)};
			if (p >= len_next) p = l + p - len_next;
			len = len_next;
		}
		cout << s[p] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

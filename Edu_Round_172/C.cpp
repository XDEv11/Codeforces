//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n; ll k;
		cin >> n >> k;
		vector<char> v(n);
		for (auto& x : v) cin >> x;

		vector<ll> t(n);
		for (int i{n - 1}, d{}; i >= 1; --i) t[i] = (v[i] == '1' ? ++d : --d);

		sort(t.rbegin(), t.rend());
		ll s{};
		for (int i{0}; i < n; ++i) {
			s += t[i];
			if (s >= k) return cout << (1 + i + 1) << '\n', []{}();
		}
		cout << "-1\n";
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

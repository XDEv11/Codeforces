//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n;
		ll m;
		cin >> n >> m;
		vector<ll> v(n);
		for (auto& x : v) cin >> x;

		sort(v.rbegin(), v.rend());
		ll t{accumulate(v.begin(), v.end(), 0ll) / m};

		ll a1{}, s{};
		vector<ll> a2{};
		for (int i{0}, j{t}; i < t || j < n; ) {
			if (i == t || (j < n && s / m == (s + v[j]) / m)) s += v[j], a2.push_back(v[j++]);
			else s += v[i], a1 += v[i], a2.push_back(v[i++]);
		}

		cout << a1 << '\n';
		for (auto& x : a2) cout << x << ' ';
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

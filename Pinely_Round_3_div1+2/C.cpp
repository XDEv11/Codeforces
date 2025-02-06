//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;
	int n;
	cin >> n;
	vector<int> l(n), r(n), c(n);
	for (auto& x : l) cin >> x;
	for (auto& x : r) cin >> x;
	for (auto& x : c) cin >> x;

	sort(l.begin(), l.end());
	set<int> st{};
	for (auto& x : r) st.insert(x);
	sort(c.begin(), c.end());

	vector<int> v(n);
	for (int i{n - 1}; i >= 0; --i) {
		auto it{st.lower_bound(l[i])};
		v[i] = *it - l[i];
		st.erase(it);
	}

	ll ans{};
	sort(v.rbegin(), v.rend());
	for (int i{0}; i < n; ++i) ans += ll(c[i]) * v[i];

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

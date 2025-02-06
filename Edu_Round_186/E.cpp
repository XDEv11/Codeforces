//#pragma GCC optimize ("O3")

#include <iostream>
#include <utility>
#define fi first
#define se second
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n, m; ll c;
		cin >> n >> m >> c;
		multiset<int> st{};
		for (int _{0}; _ < m; ++_) {
			int x;
			cin >> x;
			st.insert(x);
		}

		vector<pair<ll, int>> v(n);
		for (int i{0}; i < n; ++i) {
			ll x, y, z;
			cin >> x >> y >> z;
			c -= y, v[i] = {z - y, x};
		}
		sort(v.rbegin(), v.rend());

		int ans{};

		vector<ll> t{};
		for (int i{0}; i < n; ++i) {
			auto it{st.lower_bound(v[i].se)};
			if (it != st.end()) ++ans, st.erase(it);
			else t.push_back(v[i].fi);
		}
		reverse(t.begin(), t.end());

		for (auto& x : t) {
			if (x <= c) ++ans, c -= x;
			else break;
		}

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

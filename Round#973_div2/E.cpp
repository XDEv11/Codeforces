//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <set>
#include <numeric>

using namespace std;

namespace {
	void solve() {
		using ll = long long;

		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		set<int> st{};
		for (auto& x : v) st.insert(x);

		ll ans{};
		int x;
		for (int i{0}; i < n; ++i) {
			if (st.empty()) {
				ans += ll(n - i) * x;
				break;
			}
			x = *st.begin(); st.erase(st.begin());
			ans += x;

			set<int> ns{};
			for (auto& y : st) ns.insert(gcd(x, y));
			st = ns;
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

//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <set>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n;
		cin >> n;
		vector<ll> v(n);
		for (auto& x : v) cin >> x;

		ll ans{}, cnt{};
		set<ll> st{};
		for (auto& x : v) {
			if (st.count(x)) ans += x * 2, cnt += 2, st.erase(x);
			else st.insert(x);
		}
		if (!cnt) return cout << "0\n", []{}();

		while (!st.empty()) {
			if (st.size() >= 2) {
				auto it1{prev(st.end())}, it2{prev(it1)};
				if (*it1 - *it2 < ans) {
					ans += *it1 + *it2, cnt += 2;
					break;
				} else st.erase(it1);
			} else {
				if (*st.begin() < ans) ans += *st.begin(), cnt += 1;
				break;
			}
		}
		if (cnt < 3) return cout << "0\n", []{}();

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

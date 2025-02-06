//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <map>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		ll n, k;
		cin >> n >> k;
		vector<ll> v(n);
		for (auto& x : v) cin >> x;

		map<ll, bool> mp{};
		for (auto& x : v) mp[x] = false;

		vector<int> ans{};
		for (auto& [x, t] : mp) {
			if (t) continue;
			ans.push_back(x);
			for (ll i{2}; ; ++i) {
				ll m{x * i};
				if (m > k) break;
				auto it{mp.find(m)};
				if (it == mp.end()) return void(cout << "-1\n");
				it->second = true;
			}
		}

		cout << ans.size() << '\n';
		for (auto& x : ans) cout << x << ' ';
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

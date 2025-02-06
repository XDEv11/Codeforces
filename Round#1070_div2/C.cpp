//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n;
		cin >> n;
		vector<ll> v(n);
		for (auto& x : v) cin >> x;

		vector<ll> vo{}, ve{};
		for (auto& x : v) (x & 1 ? vo : ve).push_back(x);
		if (vo.empty()) {
			for (int i{0}; i < n; ++i) cout << "0 ";
			cout << '\n';
			return ;
		}

		ll mx{*max_element(vo.begin(), vo.end())};
		int m{ve.size()};
		sort(ve.rbegin(), ve.rend()), ve.insert(ve.begin(), 0);
		for (int i{1}; i <= m; ++i) ve[i] += ve[i - 1];

		for (int i{0}; i < n; ++i) {
			if (!m) cout << (i & 1 ? 0 : mx) << ' ';
			else if (i == n - 1 && vo.size() % 2 == 0) cout << "0 ";
			else {
				int t{i};
				if (t > m) t -= (t - m + 1) / 2 * 2;
				cout << (mx + ve[t]) << ' ';
			}
		}
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

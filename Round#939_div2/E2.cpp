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
		v.resize(n + 3);

LOOP:
		{
			v[n] = v[0];
			for (int i{0}; i < n; ++i) v[i + 1] = max(0ll, v[i + 1] - v[i]);
			v[0] = v[n];

			v[n + 1] = v[1], v[n + 2] = v[2];
			for (int i{0}; i < n; ++i) if (v[i] && v[i + 1] && v[i + 2] && v[i + 3]) {
				goto LOOP;
			}
		}
		for (int i{0}; i < n && v[i]; ++i) v[i + 1] = max(0ll, v[i + 1] - v[i]); // finish the round of consecutive ones

		vector<int> ans{};
		for (int i{0}; i < n; ++i) {
			if (!v[i]) continue;
			int j{(i - 1 + n) % n}, k{(j - 1 + n) % n};
			if (v[j]) {
				if (v[k]) {
					ll t{v[j] / v[k]};
					if (t * (v[j] - v[k] + v[j] - v[k] * t) / 2 < v[i]) ans.push_back(i);
				}
			} else ans.push_back(i);
		}

		cout << ans.size() << '\n';
		for (auto& x : ans) cout << (x + 1) << ' ';
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

//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n, k;
		cin >> n >> k;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		vector<int> cnt(2 * k);
		for (auto& x : v) ++cnt[x % (2 * k)];

		vector<bool> ck(2 * k);
		int s{};
		for (int i{k}; i < 2 * k; ++i) s += cnt[i];
		for (int i{0}; i < 2 * k; ++i) {
			s -= cnt[(i - k + 2 * k) % (2 * k)];
			s += cnt[i];
			ck[i] = (s == n);
		}

		int j{*max_element(v.begin(), v.end())};
		for (int i{j}; i < j + 2 * k; ++i) {
			if (!ck[i % (2 * k)]) continue;
			return cout << i << '\n', []{}();
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

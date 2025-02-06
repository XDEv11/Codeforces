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

		sort(v.rbegin(), v.rend());

		int s{};
		for (int i{0}; i < n && s + v[i] <= k; ++i) s += v[i];

		cout << (k - s) << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

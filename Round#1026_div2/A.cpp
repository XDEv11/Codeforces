//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		sort(v.begin(), v.end());

		int ans1{}, ans2{};
		for (int i{0}; i < n && v[i] % 2 != 0; ++i) ++ans1;
		for (int i{n - 1}; i >= 0 && v[i] % 2 != 0; --i) ++ans1;
		for (int i{0}; i < n && v[i] % 2 == 0; ++i) ++ans2;
		for (int i{n - 1}; i >= 0 && v[i] % 2 == 0; --i) ++ans2;

		cout << min(ans1, ans2) << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

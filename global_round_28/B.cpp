//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	void solve() {
		int n, k;
		cin >> n >> k;

		vector<int> ans(n);
		for (int i{0}, a1{0}, a2{n - 1}; i < n; ++i) {
			if (i % k == k - 1) ans[i] = a1++;
			else ans[i] = a2--;
		}

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

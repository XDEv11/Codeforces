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

		int ans{};
		for (int i{0}; i < n; ) {
			int j{i + 1};
			while (j < n && clamp(v[j], v[i] + 1, v[j - 1] + 1) == v[j]) ++j;
			++ans, i = j;
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

//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n, k;
		cin >> n >> k;
		vector<char> v(n);
		for (auto& x : v) cin >> x;

		int ans{}, t{};
		for (auto& x : v) {
			if (x == '1') t = k;
			else if (t) --t;
			else ++ans;
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

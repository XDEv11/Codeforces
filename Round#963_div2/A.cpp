//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<char> v(4 * n);
		for (auto& x : v) cin >> x;

		int ans{4 * n};
		ans -= max(0, n - int(count(v.begin(), v.end(), 'A')));
		ans -= max(0, n - int(count(v.begin(), v.end(), 'B')));
		ans -= max(0, n - int(count(v.begin(), v.end(), 'C')));
		ans -= max(0, n - int(count(v.begin(), v.end(), 'D')));

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

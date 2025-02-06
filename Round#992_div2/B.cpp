//#pragma GCC optimize ("O3")

#include <iostream>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;

		int ans{1}, t{1};
		while (t < n) t = (t + 1) * 2, ++ans;

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

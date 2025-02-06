//#pragma GCC optimize ("O3")

#include <iostream>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;

		if (n == 1) return void(cout << "1\n");
		else if (n == 2) return void(cout << "9\n");

		int ans{n * n * 4 - n - 4};
		ans = max(ans, (n * n - n - 1) * 5);

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

//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	void solve() {
		int n, k;
		cin >> n >> k;

		int ans{};
		if (n & 1) n -= k, ++ans;
		k -= 1;
		ans += (n + k - 1) / k;

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

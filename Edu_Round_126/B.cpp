//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int myctz(unsigned int x) {
	if (!x) return 15;
	return __builtin_ctz(x);
}

void solve() {
	int n;
	cin >> n;

	int ans{15};
	for (int i{0}; i < 15; ++i) ans = min(ans, i + 15 - myctz(n + i));
	cout << ans << ' ';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
	cout << '\n';
}

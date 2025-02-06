//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;

	int ans{0};
	while (n) {
		ans += min(n, 9);
		n /= 10;
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

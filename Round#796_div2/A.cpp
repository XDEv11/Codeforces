//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>

using namespace std;

void solve() {
	int n;
	cin >> n;

	int c1{__builtin_ctz(n)}, c2{__builtin_popcount(n)};
	int ans{1 << c1};
	if (c2 == 1) ans += c1 ? 1 : 2;
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

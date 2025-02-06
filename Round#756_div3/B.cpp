#pragma GCC optimize ("O3")

#include <iostream>

using namespace std;

void solve() {
	long long a, b;
	cin >> a >> b;
	if (a < b) swap(a, b);

	if (a / 3 > b) cout << b << '\n';
	else cout << (a + b) / 4 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

#pragma GCC optimize ("O3")

#include <iostream>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;

	if (n == 1 && m == 1) cout << "0\n"s;
	else if (n == 1 || m == 1) cout << "1\n"s;
	else cout << "2\n"s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

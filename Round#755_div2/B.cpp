#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;

	int ans{0};
	ans += n / 3 * m, n %= 3;
	ans += m / 3 * n, m %= 3;
	if (n * m == 1 || n * m == 2) ans += 1;
	else if (n * m == 4) ans += 2;

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

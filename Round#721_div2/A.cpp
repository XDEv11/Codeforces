#include <iostream>

using namespace std;

void solve() {
	int n;
	cin >> n;

	int ans{1};
	while (ans * 2 <= n) ans *= 2;
	ans -= 1;

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

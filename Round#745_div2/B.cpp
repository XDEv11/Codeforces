#include <iostream>
#include <string>

using namespace std;

void solve() {
	long long n, m, k;
	cin >> n >> m >> k, --k;

	if (m < n - 1 || m > n * (n - 1) / 2) return cout << "NO\n"s, []{}();

	if (n == 1) cout << (k > 0 ? "YES\n"s : "NO\n"s);
	else if (m == n * (n - 1) / 2) cout << (k > 1 ? "YES\n"s : "NO\n"s);
	else cout << (k > 2 ? "YES\n"s : "NO\n"s);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

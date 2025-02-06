#include <iostream>

using namespace std;

void solve() {
	int n;
	cin >> n;

	for (int b{0}; b < 11 && b * 111 <= n; ++b) {
		if ((n - b * 111) % 11 == 0)
			return cout << "YES\n"s, []{}();
	}
	cout << "NO\n"s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

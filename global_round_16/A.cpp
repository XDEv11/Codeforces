#include <iostream>

using namespace std;

void solve() {
	int n, s;
	cin >> n >> s;

	cout << s / (n / 2 + 1) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

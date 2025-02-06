#include <iostream>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;

	cout << (n + k - 1) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t{1};
	cin >> t;
	while (t--) solve();
}

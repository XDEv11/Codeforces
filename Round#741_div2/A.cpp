#include <iostream>

using namespace std;

void solve() {
	int l, r;
	cin >> l >> r;

	int a{r}, b{max(r / 2 + 1, l)};
	cout << a % b << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

#include <iostream>

using namespace std;

void solve() {
	int s;
	cin >> s;

	int a{1}, ans{0};
	while (s >= a) s -= a, a += 2, ++ans;

	cout << ans + (s != 0) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

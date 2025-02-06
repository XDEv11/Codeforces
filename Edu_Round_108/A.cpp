#include <iostream>

using namespace std;

void solve() {
	long long r, b, d;
	cin >> r >> b >> d;

	if (r < b) swap(r, b);

	cout << (r <= b * (1 + d) ? "YES\n"s : "NO\n"s);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

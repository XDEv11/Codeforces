#include <iostream>
#include <string>

using namespace std;

void solve() {
	int n, m, x, y;
	cin >> n >> m >> x >> y;

	cout << "1 1 "s << n << ' ' << m << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

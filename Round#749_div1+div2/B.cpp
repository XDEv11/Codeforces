#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;

	vector<bool> ck(n + 1, false);
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		ck[b] = true;
	}

	int c;
	for (int i{1}; i <= n; ++i)
		if (!ck[i]) c = i;

	for (int i{1}; i <= n; ++i)
		if (i != c) cout << c << ' ' << i << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

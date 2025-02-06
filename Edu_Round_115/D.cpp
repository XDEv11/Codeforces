#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (auto& [a, b] : v) cin >> a >> b;

	vector<int> cnta(n + 1, 0), cntb(n + 1, 0);
	for (auto& [a, b] : v) ++cnta[a], ++cntb[b];

	long long ans{0};
	for (auto& [a, b] : v) ans += static_cast<long long>(cnta[a] - 1) * (cntb[b] - 1);

	cout << static_cast<long long>(n) * (n - 1) * (n - 2) / 6 - ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

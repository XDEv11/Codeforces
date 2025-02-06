#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

void solve() {
	array<int, 3> a;
	for (auto& x : a) cin >> x;
	int m;
	cin >> m;

	int mx{a[0] + a[1] + a[2] - 3};

	sort(a.rbegin(), a.rend());
	int mn{max(0, a[0] - a[1] - a[2] - 1)};

	if (m > mx || m < mn) cout << "NO\n"s;
	else cout << "YES\n"s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

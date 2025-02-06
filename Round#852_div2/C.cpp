//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int l{0}, r{n - 1}, mn{1}, mx{n};
	while (l < r) {
		bool lmn{v[l] == mn}, lmx{v[l] == mx}, rmn{v[r] == mn}, rmx{v[r] == mx};
		if (!(lmn || lmx || rmn || rmx)) break;
		if (lmn || lmx) ++l;
		if (rmn || rmx) --r;
		if (lmn || rmn) ++mn;
		if (lmx || rmx) --mx;
	}

	if (l < r) cout << l + 1 << ' ' << r + 1 << '\n';
	else cout << "-1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

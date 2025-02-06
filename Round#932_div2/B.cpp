//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int ml{0}, mr{0};
	map<int, int> mpl{}, mpr{};
	for (auto& x : v) {
		++mpr[x];
		while (mpr[mr]) ++mr;
	}
	for (int i{0}; i + 1 < n; ++i) {
		++mpl[v[i]];
		while (mpl[ml]) ++ml;
		if (!--mpr[v[i]] && v[i] < mr) mr = v[i];

		if (ml == mr) {
			cout << "2\n";
			cout << "1 " << (i + 1) << '\n';
			cout << (i + 2) << ' ' << n << '\n';
			return ;
		}
	}
	cout << "-1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> ve((n + 1) / 2), vo(n / 2);
	for (int i{0}; i < n; ++i) cin >> (i & 1 ? vo[i / 2] : ve[i / 2]);

	vector<int> v(n);
	sort(ve.begin(), ve.end());
	sort(vo.begin(), vo.end());
	for (int i{0}; i < n; ++i) v[i] = (i & 1 ? vo[i / 2] : ve[i / 2]);

	cout << (is_sorted(v.begin(), v.end()) ? "YES\n" : "NO\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

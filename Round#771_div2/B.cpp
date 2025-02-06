//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<int> vo{}, ve{};
	for (auto& x : v)
		if (x & 1) vo.push_back(x);
		else ve.push_back(x);

	cout << (is_sorted(vo.begin(), vo.end()) && is_sorted(ve.begin(), ve.end()) ? "YES\n" : "NO\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

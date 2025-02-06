#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

#define fi first
#define se second

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<pair<pair<int, int>, int> v(n);
	for (int i{0}; i < n; ++i) cin >> v[i].fi.fi >> v[i].fi.se >> v[i].se;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

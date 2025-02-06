#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, char>> v(n);
	for (auto& [x, d] : v) cin >> x;
	for (auto& [x, d] : v) cin >> d;


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

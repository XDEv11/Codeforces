#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> x(n), y(m);
	vector<pair<int, int>> p(k);
	for (auto& e : x) cin >> e;
	for (auto& e : y) cin >> e;
	for (auto& [e1, e2] : p) cin >> e1 >> e2;


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

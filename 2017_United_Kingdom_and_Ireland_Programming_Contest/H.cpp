//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#define fi first
#define se second

using namespace std;

bool solve() {
	int b;
	if (!(cin >> b)) return false;
	int n;
	cin >> n;
	vector<int> p(n);
	for (auto& x : p) cin >> x;
	int m;
	cin >> m;
	vector<array<int, 3>> v(m);
	for (int i{0}; i < m; ++i) cin >> v[i][1] >> v[i][0], --v[i][0], v[i][2] = i;

	while (!v.empty() && v.back()[0] == n - 1) v.pop_back();

	vector<int> ans{};
	for (int i{0}; !v.empty(); ) {
		if (i + 1 < v.size() && p[v[i + 1][0]] - p[v[i][0] + 1] < max(v[i][1], v[i + 1][1])) {
			++i;
			continue;
		}
		ans.push_back(v[i][2]), ++v[i][0];
		if (i - 1 >= 0 && p[v[i][0]] - p[v[i - 1][0]] > b) return cout << "impossible\n", true;
		if (v[i][0] == n - 1) v.pop_back();
		if (i) --i;
	}

	for (auto& x : ans) cout << x + 1 << ' ';
	cout << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}

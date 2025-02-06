#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>
#include <iomanip>

using namespace std;

bool solve() {
	int n;
	if (!(cin >> n)) return false;
	vector<double> v(n);
	for (auto& x : v) cin >> x;

	vector<pair<double, int>> t(n - 1);
	for (int i{1}; i < n; ++i) t[i - 1] = {v[i], i};
	sort(t.rbegin(), t.rend());

	int m{1};
	while (m * 2 <= n) m *= 2;

	vector<vector<pair<int, double>>> gm{};
	for (int i{0}; i + 1 < 2 * (n - m); i += 2) {
		int j{t[i].se}, k{t[i + 1].se};
		double pj{v[j] / (v[j] + v[k])}, pk{v[k] / (v[j] + v[k])};
		gm.push_back({{j, pj}, {k, pk}});
	}
	for (int i{2 * (n - m)}; i < n - 1; ++i) gm.push_back({{t[i].se, 1}});
	gm.push_back({{0, 1}});
	while (gm.size() > 1) {
		vector<vector<pair<int, double>>> ng{};
		for (int i{0}; i + 1 < gm.size(); i += 2) {
			ng.emplace_back();
			for (auto& [j, pj] : gm[i]) {
				double p{};
				for (auto& [k, pk] : gm[i + 1]) p += pk * v[j] / (v[j] + v[k]);
				ng.back().emplace_back(j, pj * p);
			}
			for (auto& [j, pj] : gm[i + 1]) {
				double p{};
				for (auto& [k, pk] : gm[i]) p += pk * v[j] / (v[j] + v[k]);
				ng.back().emplace_back(j, pj * p);
			}
		}
		gm = ng;
	}

	cout << gm[0][n - 1].se << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed << setprecision(6);

	while (solve()) ;
}

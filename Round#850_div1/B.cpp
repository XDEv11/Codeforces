//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <array>
#include <utility>
#define fi first
#define se second

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<array<int, 3>> v(n);
	for (auto& x : v)
		for (int j{0}; j < 3; ++j) {
			char c;
			cin >> c;
			if (c == 'w') ++x[0];
			else if (c == 'i') ++x[1];
			else if (c == 'n') ++x[2];
		}

	array<vector<int>, 6> t{}; // 0->1, 0->2, 1->2, 1->0, 2->0, 2->1
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < 3; ++j) {
			if (v[i][j] == 0) {
				if (v[i][(j + 1) % 3] > 1) {
					t[2 * j].push_back(i);
					--v[i][(j + 1) % 3], v[i][j] = 1;
				} else if (v[i][(j + 2) % 3] > 1) {
					t[2 * j + 1].push_back(i);
					--v[i][(j + 2) % 3], v[i][j] = 1;
				}
			}
		}

	vector<array<pair<int, char>, 2>> ans{};
	for (int j{0}; j < 3; ++j) {
		while (!t[j].empty() && !t[3 + j].empty()) {
			int x{t[j].back()}, y{t[3 + j].back()}; t[j].pop_back(), t[3 + j].pop_back();
			array<pair<int, char>, 2> a{make_pair(x, j == 0 ? 'i' : 'n'), make_pair(y, j == 2 ? 'i' : 'w')};
			ans.push_back(a);
		}
	}
	while (!t[0].empty()) {
		int x{t[0].back()}, y{t[2].back()}, z{t[4].back()}; t[0].pop_back(), t[2].pop_back(), t[4].pop_back();
		array<pair<int, char>, 2> a1{make_pair(x, 'i'), make_pair(y, 'n')};
		array<pair<int, char>, 2> a2{make_pair(x, 'n'), make_pair(z, 'w')};
		ans.push_back(a1);
		ans.push_back(a2);
	}
	while (!t[1].empty()) {
		int x{t[1].back()}, y{t[3].back()}, z{t[5].back()}; t[1].pop_back(), t[3].pop_back(), t[5].pop_back();
		array<pair<int, char>, 2> a1{make_pair(x, 'n'), make_pair(y, 'w')};
		array<pair<int, char>, 2> a2{make_pair(y, 'n'), make_pair(z, 'i')};
		ans.push_back(a1);
		ans.push_back(a2);
	}

	cout << ans.size() << '\n';
	for (auto& a : ans) {
		for (auto& [i, c] : a) cout << i + 1 << ' ' << c << ' ';
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

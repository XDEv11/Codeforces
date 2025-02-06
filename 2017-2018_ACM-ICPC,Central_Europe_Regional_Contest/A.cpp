//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <algorithm>

using namespace std;

bool solve() {
	int r, n;
	if (!(cin >> r >> n)) return false;
	vector<array<char, 11>> m(r + 3);
	for (auto& v : m)
		for (auto& x : v) cin >> x;

	for (int k{0}; k < n; ++k) {
		vector<int> v{};
		for (auto& x : m[1]) {
			if (x == '-') {
				v.push_back(1);
				break;
			}
		}
		for (auto& x : m[r / 2 + 2]) {
			if (x == '-') {
				v.push_back(r / 2 + 2);
				break;
			}
		}
		if (v.empty()) {
			for (int i{0}; i < r + 3; ++i)
				for (auto& x : m[i]) {
					if (x == '-') {
						v.push_back(i);
						break;
					}
				}
		}

		int s{};
		array<int, 3> mx{};
		for (auto& i : v) {
			int c{};
			for (auto& x : m[i]) c += (x == '-');
			int d{min({i - 0, abs(r / 2 + 1 - i), r + 2 - i})};
			if (mx < array<int, 3>{c, -d, -i}) s = i, mx = {c, -d, -i};
		}

		int cl{}, cr{};
		for (int i{0}; i < r + 3; ++i) {
			for (int j{0}; j < 5; ++j) cl += (m[i][j] != '-');
			for (int j{6}; j < 11; ++j) cr += (m[i][j] != '-');
		}

		if (m[s][4] == '-' || m[s][6] == '-') {
			(m[s][4] == '-' && (m[s][6] != '-' || cl <= cr) ? m[s][4] : m[s][6]) = 'a' + k;
		} else if (m[s][2] == '-' || m[s][8] == '-') {
			(m[s][2] == '-' && (m[s][8] != '-' || cl <= cr) ? m[s][2] : m[s][8]) = 'a' + k;
		} else if (m[s][0] == '-' || m[s][10] == '-') {
			(m[s][0] == '-' && (m[s][10] != '-' || cl <= cr) ? m[s][0] : m[s][10]) = 'a' + k;
		} else if (m[s][5] == '-') m[s][5] = 'a' + k;
		else (m[s][1] == '-' && (m[s][9] != '-' || cl <= cr) ? m[s][1] : m[s][9]) = 'a' + k;
	}

	for (auto& v : m) {
		for (auto& x : v) cout << x;
		cout << '\n';
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}

//#pragma GCC optimize ("O3")

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

void solve(ifstream& fin) {
	int n;
	fin >> n;
	vector<char> v(n);
	for (auto& x : v) fin >> x;

	vector<int> idx{};
	for (int i{0}; i < n; ++i) {
		if (v[i] == '+') idx.push_back(i);
	}
	int m{idx.size()};
	if (m == 1) return cout << n / 2 << '\n', []{}();

	int fl{idx[0]}, bl{n - 1 - idx[m - 1]};
	multiset<int> ms{};
	for (int i{0}; i + 1 < m; ++i) ms.insert(idx[i + 1] - 1 - idx[i]);

	int ans{n};
	for (int i{0}; i < m; ++i) {
		if (i == 0) {
			int t{idx[1] - 1 - idx[0]};
			fl += t + 1, ms.erase(ms.find(t));
		} else if (i == m - 1) {
			int t{idx[m - 1] - 1 - idx[m - 2]};
			bl += t + 1, ms.erase(ms.find(t));
		} else {
			int t1{idx[i] - 1 - idx[i - 1]}, t2{idx[i + 1] - 1 - idx[i]};
			ms.erase(ms.find(t1)), ms.erase(ms.find(t2)), ms.insert(t1 + t2 + 1);
		}

		ans = min(ans, max({(fl - 1 + 2) / 3, bl, m == 2 ? 0 : (*ms.rbegin() + 1) / 2}));
		ans = min(ans, max({fl, (bl - 1 + 2) / 3, m == 2 ? 0 : (*ms.rbegin() + 1) / 2}));
		ans = min(ans, max({fl, bl, m == 2 ? 0 : (*ms.rbegin() / 2 + 1) / 2, m <= 3 ? 0 : (*next(ms.rbegin()) + 1) / 2}));

		if (i == 0) {
			int t{idx[1] - 1 - idx[0]};
			fl -= t + 1, ms.insert(t);
		} else if (i == m - 1) {
			int t{idx[m - 1] - 1 - idx[m - 2]};
			bl -= t + 1, ms.insert(t);
		} else {
			int t1{idx[i] - 1 - idx[i - 1]}, t2{idx[i + 1] - 1 - idx[i]};
			ms.erase(ms.find(t1 + t2 + 1)), ms.insert(t1), ms.insert(t2);
		}
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ifstream fin{"stations.in"};
	
	int t{1};
	fin >> t;
	while (t--) solve(fin);
}

//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#define fi first
#define se second

using namespace std;

bool solve() {
	string a{};
	if (!(cin >> a)) return false;
	int n{a.size()};

	auto b{a};
	sort(b.begin(), b.end());

	vector<pair<int, int>> ans{};
	for (int i{0}; i < n; ++i) {
		if (b[i] == a[i]) continue;
		int j{i};
		while (b[j] != a[i]) ++j;
		if (b[i] > b[j]) ans.emplace_back(i, j);
		else ans.emplace_back(j, i);
		swap(b[i], b[j]);
	}

	for (auto& [i, j] : ans) cout << (i + 1) << ' ' << (j + 1) << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}

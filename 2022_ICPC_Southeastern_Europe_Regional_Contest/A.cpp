//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

bool solve() {
	string a{}, b{};
	if (!(cin >> a >> b)) return false;

	array<vector<int>, 26> idx{};
	for (int i{0}; i < a.size(); ++i) idx[a[i] - 'a'].push_back(i);

	int ans{1};
	for (int i{-1}, j{0}; j < b.size(); ++j) {
		auto& v{idx[b[j] - 'a']};
		auto it{upper_bound(v.begin(), v.end(), i)};
		if (it == v.end()) ++ans, it = v.begin();
		i = *it;
	}

	cout << ans << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}

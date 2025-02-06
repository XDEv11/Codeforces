//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

// longest increasing subsequence
int LIS(const vector<int>& s) {
// use binary search to update the smallest element
// that ends in a subsequence of length d
    vector<int> v{};
    v.push_back(s[0]);
    for (int i{1}; i < s.size(); ++i)
        if (s[i] > v.back()) v.push_back(s[i]);
        else *lower_bound(v.begin(), v.end(), s[i]) = s[i];
    return v.size();
}

bool solve() {
	int tx, ty;
	if (!(cin >> tx >> ty)) return false;
	int n;
	cin >> n;
	vector<array<int, 3>> t(n);
	for (auto& [x, y, h] : t) cin >> x >> y >> h;

	auto cmp{[&tx, &ty](const array<int, 3>& a, array<int, 3>& b) {
		if (a[0] != b[0]) return abs(a[0] - tx) < abs(b[0] - tx);
		else return abs(a[1] - ty) < abs(b[1] - ty);
	}};
	sort(t.begin(), t.end(), cmp);

	map<array<int, 2>, vector<int>> mp{};
	for (auto& [x, y, h] : t) {
		int dx{x - tx}, dy{y - ty}, g{gcd(dx, dy)};
		mp[{dx / g, dy / g}].push_back(h);
	}

	int ans{};
	for (auto& [k, v] : mp) ans += LIS(v);

	return cout << ans << '\n', true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}

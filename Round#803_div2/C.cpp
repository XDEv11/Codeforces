//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<long long> v(n);
	for (auto& x : v) cin >> x;

	bool has0{false};
	vector<long long> pos{}, neg{};
	for (auto& x : v) {
		if (x > 0) pos.push_back(x);
		else if (x < 0) neg.push_back(x);
		else has0 = true;
	}
	if (pos.size() >= 3 || neg.size() >= 3) return cout << "NO\n", []{}(); // 0 + 2 pos(neg) isn't okay, but we'll check later

	v.clear();
	if (has0) v.push_back(0);
	for (auto& x : pos) v.push_back(x);
	for (auto& x : neg) v.push_back(x);
	n = v.size();
	set<long long> s{};
	for (auto& x : v) s.insert(x);

	for (int i{0}; i < n; ++i)
		for (int j{i + 1}; j < n; ++j)
			for (int k{j + 1}; k < n; ++k)
				if (s.count(v[i] + v[j] + v[k]) == 0) return cout << "NO\n", []{}();
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

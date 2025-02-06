//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <numeric>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	int i{0};
	while (i < n && v[i] == '0') ++i;
	if (i == n) return cout << "0\n", []{}();

	int j{i + 1};
	while (j < n && v[j] == '1') ++j;
	if (j == n) {
		for (; i < n; ++i) cout << '1';
		cout << '\n';
		return ;
	}

	list<int> lst(j - i); iota(lst.begin(), lst.end(), i);
	int k{0};
	for (; j + k < n; ++k) {
		if (lst.size() > 1 && v[j + k] == '0') {
			auto it{lst.begin()};
			while (it != lst.end()) {
				if (lst.size() == 1) break;
				auto nit{next(it)};
				if (v[*it + k] == '0') lst.erase(it);
				it = nit;
			}
		}
	}

	vector<char> ans{v.begin() + i, v.end()};
	i = ans.size() - 1;
	j = lst.front() - 1 + k;
	while (i >= 0 && j >= 0) {
		if (v[j] == '1') ans[i] = '1';
		--i, --j;
	}

	for (auto& x : ans) cout << x;
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}

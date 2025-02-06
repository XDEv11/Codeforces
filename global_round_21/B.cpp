//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	if (count(v.begin(), v.end(), 0) == n) cout << "0\n";
	else {
		int fi{0}, la{n - 1};
		while (v[fi] == 0) ++fi;
		while (v[la] == 0) --la;
		for (int i{fi}; i <= la; ++i)
			if (v[i] == 0) return cout << "2\n", []{}();
		cout << "1\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

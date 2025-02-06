//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int Ask(int i) {
	cout << "? "s << i << endl;
	int r;
	return cin >> r, r;
}

void Ans(const vector<int>& p) {
	cout << "! "s;
	for (auto& x : p) cout << x << ' ';
	cout << endl;
}

void solve() {
	int n;
	cin >> n;

	int cnt{0};

	vector<int> p(n, 0);
	for (int i{1}; i <= n; ++i) {
		if (p[i - 1]) continue;

		++cnt; int r{Ask(i)};
		vector<int> v{r};
		while ((++cnt, r = Ask(i)) != v[0]) v.push_back(r);
		int s{(v.size() - ((cnt - v.size() - 1) % v.size()) + 1) % v.size()}, j{s}, x{i};
		do {
			p[x - 1] = v[j], x = v[j];
			j = (j + 1) % v.size();
		} while (j != s);
	}

	Ans(p);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

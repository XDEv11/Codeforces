//#pragma GCC optimize ("O3")

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void solve(ifstream& fin) {
	int n;
	fin >> n;
	vector<int> v(n);
	for (auto& x : v) fin >> x;

	int ans{};
	const int maxval{1000000};
	vector<bool> c(maxval + 1);
	for (int i{0}; i < n; ++i) {
		int cnt{};
		for (int j{i}; j < n; ++j) {
			if (c[v[j]]) c[v[j]] = false, --cnt;
			else c[v[j]] = true, ++cnt;
			ans += (cnt == 1);
		}
		for (int j{i}; j < n; ++j) c[v[j]] = false;
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ifstream fin{"cases.in"};
	
	int t{1};
	fin >> t;
	while (t--) solve(fin);
}

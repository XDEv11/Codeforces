//#pragma GCC optimize ("O3")

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(ifstream& fin) {
	int n;
	fin >> n;
	vector<int> v(n);
	for (auto& x : v) fin >> x;

	sort(v.begin(), v.end());

	int ans{};
	int i{0};
	while (i + 5 < n) {
		while (i + 5 < n && v[i + 5] - v[i] > 1000) ++i;
		if (i + 5 == n) break;
		++ans, i += 6;
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ifstream fin{"overcode.in"};
	
	int t{1};
	fin >> t;
	while (t--) solve(fin);
}

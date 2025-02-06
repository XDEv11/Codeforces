#include <iostream>
#include <vector>
#include <array>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> b(n, vector<char>(m));
	vector<vector<char>> a(n - 1, vector<char>(m));
	for (auto& s : b)
		for (auto& c : s) cin >> c;
	for (auto& s : a)
		for (auto& c : s) cin >> c;

	vector<array<int, 26>> bc(m), ac(m);
	for (int j{0}; j < m; ++j) 
		for (int k{0}; k < 26; ++k) bc[j][k] = ac[j][k] = 0;
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < m; ++j) ++bc[j][b[i][j] - 'a'];
	for (int i{0}; i < n - 1; ++i)
		for (int j{0}; j < m; ++j) ++ac[j][a[i][j] - 'a'];

	for (int i{0}; i < n; ++i) {
		bool flag{true};
		for (int j{0}; j < m; ++j)
			if (bc[j][b[i][j] - 'a'] == ac[j][b[i][j] - 'a']) flag = false;

		if (flag) {
			for (auto& c : b[i]) cout << c;
			cout << endl;
			return ;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	vector<int> len{};
	int c{1};
	for (int i{0}; i < n; ++i) {
		if (i + 1 == n || v[i] != v[i + 1]) len.push_back(c), c = 1;
		else ++c;
	}

	int ans{0};
	for (int i{0}; i < len.size(); ++i) {
		if (!(len[i] & 1)) continue;
		len[i] -= 1, len[i + 1] += 1;
		++ans;
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

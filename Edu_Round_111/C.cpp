#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int ans{0};
	for (int i{0}; i < n; ++i)
		for (int j{i}; j < n; ++j) {
			bool check{true};
			for (int p{i}; p < j; ++p)
				for (int q{p + 1}; q < j; ++q) {
					if (v[p] <= v[q] && v[q] <= v[j]) check = false;
					if (v[p] >= v[q] && v[q] >= v[j]) check = false;
				}
			if (!check) break;

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

	return 0;
}

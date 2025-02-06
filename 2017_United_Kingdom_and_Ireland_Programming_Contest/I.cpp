//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

bool solve() {
	int n;
	if (!(cin >> n)) return false;
	vector<int> v(n);
	for (auto& x : v) cin >> x;
	int h;
	cin >> h;

	int ans1{h}, ans2{};
	for (int i{0}; i < n; ++i) {
		if (h % v[i] < ans1) ans1 = h % v[i], ans2 = v[i];
	}

	return cout << ans2 << '\n', true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}

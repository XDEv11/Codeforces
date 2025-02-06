//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

vector<int> ask(int l, int r) {
	cout << "? " << l << " " << r << endl;
	vector<int> res(r - l + 1);
	for (auto& x : res) cin >> x;
	return res;
}

void ans(int p) {
	cout << "! " << p << endl;
}

void solve() {
	int n;
	cin >> n;

	int l{1}, r{n + 1};
	while (r - l > 1) {
		int m{(l + r) / 2};
		auto v{ask(l, m - 1)};
		int cnt{0};
		for (auto& x : v) if (l <= x && x <= m - 1) ++cnt;
		if (cnt & 1) r = m;
		else l = m;
	}
	ans(l);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

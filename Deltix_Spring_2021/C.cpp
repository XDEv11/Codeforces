#include <iostream>
#include <vector>

using namespace std;

void solve() {
	static constexpr auto print = [](vector<int> vt) {
		for (int i{0}; i < vt.size(); ++i)
			cout << vt[i] << ".\n"[i == vt.size() - 1];
	};

	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<int> s{};
	for (int i{0}; i < n; ++i) {
		if (v[i] != 1) {
			while (s.back() != v[i] - 1) s.pop_back();
			s.pop_back();
		}
		s.push_back(v[i]);

		print(s);
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

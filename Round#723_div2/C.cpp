#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<long long> v(n);
	for (auto& x : v) cin >> x;

	int ans{n};
	long long ps{0};
	priority_queue<long long, vector<long long>, greater<long long>> pq{};
	for (auto& x : v) {
		ps += x, pq.push(x);
		while (ps < 0) {
			ps -= pq.top(), pq.pop();
			--ans;
		}
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}

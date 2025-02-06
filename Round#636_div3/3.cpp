#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int n;
		long long ans = 0;
		cin >> n;
		int last_a;
		cin >> last_a;
		for (int i = 1; i < n; ++i) {
			int a;
			cin >> a;
			if ((a > 0) == (last_a > 0)) {
				last_a = max(last_a, a);
			} else {
				ans += last_a;
				last_a = a;
			}
		}
		ans += last_a;
		cout << ans << endl;
	}
	return 0;
}

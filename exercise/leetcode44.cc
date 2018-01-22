#include "common.h"

class Solution {
public:
	bool isMatch(string s, string p) {

		
		int n = s.size(), m = p.size();
		if (n == 0) {
			if (m == 0) return true;
			for (auto ch : p) {
				if (ch != '*') return false;
			}
			return true;
		}
		vector<vector<int>> f(n+1, vector<int>(m+1));
		f[0][0] = 1;
		for (int i = 1; i <= m; i++)
			if (p[i - 1] != '*') break;
			else f[0][i] = 1;
		for (int i=1; i<=n; i++)
			for (int j = 1; j <= m; j++) {
				char si = s[i - 1], pj = p[j - 1];
				if (si == pj) {
					f[i][j] = f[i - 1][j - 1];
				}
				if (pj == '?') {
					f[i][j] = f[i - 1][j - 1];
				}
				if (pj == '*') {
					f[i][j] = f[i - 1][j] | f[i][j - 1] | f[i - 1][j - 1];
				}
			}
		return f[n][m];
	}
};
//
//int main() {
//	cout << Solution().isMatch("1", "*?*") << endl;
//	system("pause");
//	return 0;
//}
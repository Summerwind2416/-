#include<iostream>
#include<vector>
using namespace std;
	void dfs(int i, vector<string>& strs, vector<bool>& q, vector<bool>& d, vector<bool>& ud, vector<vector<string>>& ans, int n) {
		if (i == n) {
			ans.push_back(strs);
			return;
		}
		//ѡ��һ��λ�ý��з���
		for (int j = 0; j < n; j++) {
			if (!q[j] && !d[i + j] && !ud[n - i + j]) {
				q[j] = d[i + j] = ud[n - i + j] = true;
				strs[i][j] = 'Q';
				dfs(i + 1, strs, q, d, ud, ans, n);
				strs[i][j] = '.';
				q[j] = d[i + j] = ud[n - i + j] = false;
			}
		}
	}
	vector<vector<string>> solveNQueens(int n) {
		vector<bool> cols(n), d(25), ud(25);
		vector<vector<string>> ans;
		vector<string> strs(n, string(n, '.'));
		dfs(0, strs, cols, d, ud, ans, n);
		return ans;
	}
int main() {
	int n;
	cout << "������ʺ�����" << endl;
	cin >> n;
	vector<vector<string>> solve=solveNQueens(n);
	cout << "һ��" << solve.size() << "�ֽⷨ��" << endl;
	for (int i = 0; i < solve.size(); i++)
	{
		cout << "��" << i + 1 << "�֣�" << endl;
		for (int j = 0; j < solve[i].size(); j++) {
			cout << solve[i][j].c_str() << endl;
		}
		cout << endl;
	}
	return 0;
}
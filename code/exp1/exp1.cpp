#include<iostream>
#include<stack>
#define max 100
using namespace std;
int main()
{
	int V,n,v[max];
	bool found = false;
	cout << "�����뱳����С��";
	cin >> V;
	cout << "��������Ʒ������";
	cin >> n;
	cout << "������ÿ����Ʒ�Ĵ�С��";
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int rem = V,i=0;
	stack<int> s;
	while (1)
	{
		if (rem == v[i] || (rem > v[i] && i < n)) {
			s.push(i);
			rem -= v[i];
		}
		if (rem == 0) {
			found = true;

			stack<int> p;
			while (!s.empty())
			{
				p.push(s.top());
				s.pop();
			}
			cout << "(";
			while (!p.empty())
			{
				cout << v[p.top()] << ",";
				s.push(p.top());
				p.pop();
			}
			cout << ")" << endl;
		
			if (s.size() == 1) {
				rem += v[s.top()];
				s.pop();
				i++;
				if (i == n) break;
			}
			else if (i == n - 1)
			{
				rem += v[s.top()];
				s.pop();
				i = s.top() + 1;
				rem += v[s.top()];
				s.pop();
			}
			else {
				i = s.top() + 1;
				rem += v[s.top()];
				s.pop();
			}
		}
		else {
			if (i == n - 1) {
				if (s.size() == 1 && s.top() == n - 1) {
					break;
				}
				else {
					if (i == s.top()) {
						rem += v[s.top()];
						s.pop();
						i = s.top() + 1;
						rem += v[s.top()];
						s.pop();
					}
					else {
						i = s.top() + 1;
						rem += v[s.top()];
						s.pop();
					}
				}
			}
			else {
				i++;
			}
		}
	}
	if (found == false) cout << "�޷�װ������" << endl;
	system("pause");
	return 0;
}
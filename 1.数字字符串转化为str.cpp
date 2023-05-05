#include<iostream>
// https://www.nowcoder.com/questionTerminal/6a5d7615332c49eb810c374dd6f37857
using namespace std;
int process(int i,string s) {
	if (i == s.size())
		return 1;
	if (s[i] == '0')
		return 0;
	if (s[i] == '1') {
		int res = process(i + 1,s);
		if (i + 1 < s.size()) {
			res += process(i + 2,s);
		}
		return res;
	}
	if (s[i] == '2') {
		int res = process(i + 1,s);
		if (i + 1 < s.size() && (s[i + 1] >= '0' && s[i + 1] <= '6'))
			res += process(i + 2, s);
		return res;
	}
	return process(i + 1,s);
}
int main() {
	string s = "1111";
	int res = process(0,s);
	cout << res << endl;
	return 0;
}                                 

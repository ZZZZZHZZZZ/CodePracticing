//url:https://www.nowcoder.com/test/question/c27561e5b7e0441493adb9a54071888d?pid=21283868&tid=34546253
//和四则运算一种方法，还是用栈来解决
#include<iostream>
#include<stack>
using namespace std;
int main() {
	string str;
	cin >> str;
	string resstr;
	stack<string> strStack;
	stack<int> numStack;
	deque<int> tempNumStack;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] <= '9' && str[i]>='0') {
			tempNumStack.push_back(str[i] - '0');
		}
		else if (str[i]=='|') {
			int temp = 0;
			while (!tempNumStack.empty()) {
				int num = tempNumStack.front();
				tempNumStack.pop_front();
				temp = temp*10 + num;
			}
			numStack.push(temp);
		}
		else if (str[i] <= 'Z' && str[i] >= 'A') {
			string temp = string(1, str[i]);
			strStack.push(temp);
		}
		else if (str[i]=='[') {
			string temp = string(1,str[i]);
			strStack.push(temp);
		}
		else if (str[i] == ']') {
			int number = numStack.top();
			numStack.pop();
			string tempstr;
			while (strStack.top() != "[") {
				string temp=strStack.top();
				strStack.pop();
				tempstr = temp + tempstr;
			}
			strStack.pop();
			while (number > 0) {
				number--;
				strStack.push(tempstr);
			}
		}
	}
	while (!strStack.empty()) {
		resstr = strStack.top()+resstr;
		strStack.pop();
	}
	cout << resstr<<endl;
}

//url:https://www.nowcoder.com/question/next?pid=21283868&qid=830860&tid=34551836
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> highVec(n,0);
	for (int i = 0; i < n; ++i) {
		int num = 0;
		cin >> num;
		highVec[i]=num;
	}
	stack<int> frontStack;
	vector<int> frontLookVec(n,0);
	for (int i = n - 1; i>= 0; --i) {
		frontLookVec[i] = frontStack.size();
		while (!frontStack.empty()&&highVec[i] >= frontStack.top()) {
			frontStack.pop();
		}
		frontStack.push(highVec[i]);
	}
	stack<int> backStack;
	vector<int> backLookVec(n, 0);
	for (int i = 0; i <n; ++i) {
		backLookVec[i] = backStack.size();
		while (!backStack.empty() && highVec[i] >= backStack.top()) {
			backStack.pop();
		}
		backStack.push(highVec[i]);
	}
	for (int i = 0; i < n;++i) {
		cout << backLookVec[i]+ frontLookVec[i] +1<< " ";
	}
}
//6
//5 3 8 3 2 5

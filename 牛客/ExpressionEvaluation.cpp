//url:https://www.nowcoder.com/practice/9566499a2e1546c0a257e885dfdbf30d?tpId=37&&tqId=21277&rp=1&ru=/ta/huawei&qru=/ta/huawei/question-ranking
//url:https://www.nowcoder.com/practice/9999764a61484d819056f807d2a91f1e?tpId=37&&tqId=21273&rp=1&ru=/ta/huawei&qru=/ta/huawei/question-ranking
#include<iostream>
#include<stack>
using namespace std;
//-1000+20*30-(-40+60)/20
bool ispro(string s1, string s2);
int main() {
    string caclustr = "";
    cin >> caclustr;
    if (caclustr[0] == '-') {
        caclustr = '0' + caclustr;
    }
    stack<int> numbers;
    stack<string> operators;
    int num = 0;
    while(true) {
        if (caclustr[0] == '+' || caclustr[0] == '-' || caclustr[0] == '*' || caclustr[0] == '/') {
            string temp = string(1, caclustr[0]);
            if (!operators.empty()) {
                string oper = operators.top();
                while(!ispro(temp, oper)) {
                    operators.pop();
                    int num2 = numbers.top();
                    numbers.pop();
                    int num1 = numbers.top();
                    numbers.pop();
                    if (oper == "*") {
                        numbers.push(num1 * num2);
                    }
                    else if (oper == "/") {
                        numbers.push(num1 / num2);
                    }
                    else if (oper == "-") {
                        numbers.push(num1 - num2);
                    }
                    if (operators.empty()) {
                        break;
                    }
                    oper= operators.top();
                }
                operators.push(temp);
            }
            else {
                operators.push(temp);
            }
            caclustr = caclustr.substr(1);
        }
        else if (caclustr[0] == '(') {
            string temp = string(1, caclustr[0]);
            operators.push(temp);
            caclustr = caclustr.substr(1);
            if (caclustr[0] == '-') {
                caclustr = '0' + caclustr;
            }
        }
        else if (caclustr[0] == ')') {
            while (operators.top() != "(") {
                string oper = operators.top();
                operators.pop();
                int num2 = numbers.top();
                numbers.pop();
                int num1 = numbers.top();
                numbers.pop();
                if (oper == "+") {
                    numbers.push(num1 + num2);
                }
                else if (oper == "-") {
                    numbers.push(num1 - num2);
                }
                if (oper == "*") {
                    numbers.push(num1 * num2);
                }
                else if (oper == "/") {
                    numbers.push(num1 / num2);
                }
            }
            operators.pop();
            caclustr = caclustr.substr(1);
        }
        else if (caclustr[0] == '{') {
            string temp = string(1, caclustr[0]);
            operators.push(temp);
            caclustr = caclustr.substr(1);
            if (caclustr[0] == '-') {
                caclustr = '0' + caclustr;
            }
        }
        else if (caclustr[0] == '}') {
            while (operators.top() != "{") {
                string oper = operators.top();
                operators.pop();
                int num2 = numbers.top();
                numbers.pop();
                int num1 = numbers.top();
                numbers.pop();
                if (oper == "+") {
                    numbers.push(num1 + num2);
                }
                else if (oper == "-") {
                    numbers.push(num1 - num2);
                }
                if (oper == "*") {
                    numbers.push(num1 * num2);
                }
                else if (oper == "/") {
                    numbers.push(num1 / num2);
                }
            }
            operators.pop();
            caclustr = caclustr.substr(1);
        }
        else if (caclustr[0] == '[') {
            string temp = string(1, caclustr[0]);
            operators.push(temp);
            caclustr = caclustr.substr(1);
            if (caclustr[0] == '-') {
                caclustr = '0' + caclustr;
            }
        }
        else if (caclustr[0] == ']') {
            while (operators.top() != "[") {
                string oper = operators.top();
                operators.pop();
                int num2 = numbers.top();
                numbers.pop();
                int num1 = numbers.top();
                numbers.pop();
                if (oper == "+") {
                    numbers.push(num1 + num2);
                }
                else if (oper == "-") {
                    numbers.push(num1 - num2);
                }
                if (oper == "*") {
                    numbers.push(num1 * num2);
                }
                else if (oper == "/") {
                    numbers.push(num1 / num2);
                }
            }
            operators.pop();
            caclustr = caclustr.substr(1);
        }
        else {
            num = num * 10 + (caclustr[0] - '0');
            if (caclustr[1] != '+' && caclustr[1] != '-' && caclustr[1] != '*' && caclustr[1] != '/' && caclustr[1] != '(' && caclustr[1] != ')' && caclustr[1] != '{' && caclustr[1] != '}' && caclustr[1] != '[' && caclustr[1] != ']') {
            }
            else {
                numbers.push(num);
                num = 0;
            }
            caclustr = caclustr.substr(1);
        }
        if (caclustr == "") {
            break;
        }
        if (caclustr.find('+') == caclustr.npos&& caclustr.find('-') == caclustr.npos&& caclustr.find('*') == caclustr.npos&& caclustr.find('/') == caclustr.npos&& caclustr.find('(') == caclustr.npos&& caclustr.find(')') == caclustr.npos && caclustr.find('{') == caclustr.npos && caclustr.find('}') == caclustr.npos && caclustr.find('[') == caclustr.npos && caclustr.find(']') == caclustr.npos) {
            break;
        }
    }
    if (caclustr != "") {
        numbers.push(atoi(caclustr.c_str()));
    }
    while (numbers.size() >= 2 && !operators.empty()) {
        string oper = operators.top();
        operators.pop();
        int num2 = numbers.top();
        numbers.pop();
        int num1 = numbers.top();
        numbers.pop();
        if (oper == "+") {
            numbers.push(num1 + num2);
        }
        else if (oper == "-") {
            numbers.push(num1 - num2);
        }
        if (oper == "*") {
            numbers.push(num1 * num2);
        }
        else if (oper == "/") {
            numbers.push(num1 / num2);
        }
    }
    cout << numbers.top();
    return 0;
}
bool ispro(string s1, string s2) {
    if (s1 == "+") {
        if (s2 == "*" || s2 == "/"||s2=="-") {
            return false;
        }
    }
    if (s1 == "-") {
        if (s2 == "*" || s2 == "/" || s2 == "-") {
            return false;
        }
    }
    return true;
}

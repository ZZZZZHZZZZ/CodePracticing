//url:https://ac.nowcoder.com/acm/problem/16492
//解法：
//要求y - x = z - y, 且x, z节点颜色相同, 则是要求x, z节点同一奇偶性，同一颜色
//使用struct保存当前节点的序号，数字，颜色，序号奇偶性
//使用vector保存输入的所有节点
//对节点排序，排序规则为首先按照颜色序号排序，在同一颜色中序号为偶数的排在最前面，同一奇偶性的按照序号大小排列
//这样就将这组节点按照同一颜色的奇偶性排列完成。
//同一颜色同一奇偶的一组即为一组解，设这组解的数量为n
//求分数的表达式按照(n - 2)* (这组解中所有序号* 数字的和) + (这组解中所有序号的和) * (这组解中所有数字的和)
//表达式推导过程url:https://ac.nowcoder.com/acm/problem/blogs/16492
#include<iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <iomanip>
using namespace std;
struct Paper {
    int order;
    int number;
    int color;
    int flag;
};
bool cmp(Paper p1, Paper p2) {
    if (p1.color < p2.color) {
        return true;
    }
    else if (p1.color == p2.color) {
        if (p1.flag == 0 && p2.flag == 0) {
            if (p1.order < p2.order) {
                return true;
            }
            else {
                return false;
            }
        }
        else if (p1.flag == 1 && p2.flag == 1) {
            if (p1.order < p2.order) {
                return true;
            }
            else {
                return false;
            }
        }
        else if (p1.flag == 0 && p2.flag == 1) {
            return true;
        }
        return false;
    }
    return false;
}
int main() {
    vector<Paper> paper;
    int n, m;
    cin >> n >> m;
    paper.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        paper[i].order = i;
        cin >> paper[i].number;
        paper[i].flag = i % 2;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> paper[i].color;
    }
    sort(paper.begin(), paper.end(), cmp);
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        int count = -1;
        int temp1 = (paper[i].order%10007)*(paper[i].number%10007);
        temp1 %= 10007;
        int temp2 = paper[i].order % 10007;
        int temp3 = paper[i].number % 10007;
        for (int j = i + 1; j <= n; ++j) {
            if (paper[j].color != paper[i].color||paper[j].flag!=paper[i].flag) {
                i = j-1;
                break;
            }
            temp1 += (paper[j].order % 10007) * (paper[j].number % 10007);
            temp1 %= 10007;
            temp2 += paper[j].order % 10007;
            temp2 %= 10007;
            temp3 += paper[j].number % 10007;
            temp3 %= 10007;
            ++count;
            if (j == n) {
                res += (count * temp1) % 10007 + (temp2 * temp3) % 10007;
                res = res % 10007;
                cout << res << endl;
                return 0;
            }
        }
        if (count != -1) {
            res += (count * temp1)%10007 + (temp2 * temp3)%10007;
            res = res % 10007;
        }
       
    }
    cout << res << endl;
    return 0;
}

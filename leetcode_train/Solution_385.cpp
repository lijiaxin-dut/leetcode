#include<string>
#include<vector>
using namespace std;





// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
   public:
    // Constructor initializes an empty nested list.
     NestedInteger();

     // Constructor initializes a single integer.
     NestedInteger(int value);

     // Return true if this NestedInteger holds a single integer, rather than a nested list.
     bool isInteger() const;

     // Return the single integer that this NestedInteger holds, if it holds a single integer
     // The result is undefined if this NestedInteger holds a nested list
     int getInteger() const;

     // Set this NestedInteger to hold a single integer.
     void setInteger(int value);

     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
     void add(const NestedInteger &ni);

     // Return the nested list that this NestedInteger holds, if it holds a nested list
     // The result is undefined if this NestedInteger holds a single integer
     const vector<NestedInteger> &getList() const;
 };

//s��Ϊ�յĻ������ַ��Ƿ�Ϊ��[�������ǵĻ�˵��sΪһ������������ֱ�ӷ��ؽ����

//���s�����ַ��ǡ�[������s����С�ڵ���2��˵��û�����ݣ�ֱ�ӷ��ؽ��������[����[]����

//���s���ȴ���2�����Ǵ�i = 1��ʼ������������Ҫһ������start����¼ĳһ�����ʵλ�ã�
//��cnt����¼����ʵλ���Ƿ�Ϊͬһ��ȣ�cnt = 0��ʾͬһ��ȣ�
//�����м�ÿ�ζ����ɶ��Ÿ��������Ե������жϵ�cntΪ0���ҵ�ǰ�ַ��Ƕ��Ż����Ѿ����ַ���ĩβ�ˣ�
//���ǰ�start����ǰλ��֮����ַ���ȡ�����ݹ���ú�����
//�ѷ��ؽ������res�У�Ȼ��start����Ϊi + 1�����������[����������cnt����1����������]����������cnt�Լ�1��

class Solution {
public:
	NestedInteger deserialize(string s) {

		if (s.empty()) {
			return NestedInteger();
		}
		if (s[0] != '[') {
			return NestedInteger(stoi(s));
		}
		if (s.size() <= 2) {
			return NestedInteger();
		}
		NestedInteger res;
		int start = 1, cnt = 0;
		for (int i = 1; i<s.size(); i++) {
			if (cnt == 0 && (s[i] == ',') || i == s.size() - 1) {
				string sub = s.substr(start, i - start);
				res.add(deserialize(sub));
				start = i + 1;
			}
			else if (s[i] == '[') {
				cnt++;
			}
			else if (s[i] == ']') {
				cnt--;
			}
		}
		return res;
	}
};
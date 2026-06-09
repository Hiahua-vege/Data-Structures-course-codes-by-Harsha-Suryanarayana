#include<iostream>
#include<stack>
#include<cstring>
#include<string>
using namespace std;

//栈
// class Stack {
// private:
//     char A[101];
//     int top;
// public:
//     void Push(int x);
//     void Pop();
//     int Top();
//     bool IsEmpty();    
// };

//--------------基于数组的实现----------------
void Reverse(char* C, int n) {
    stack<char> S;
    //loop for push
    for (int i = 0; i < n; i++) {
        S.push(C[i]);
    }
    //loop for pop
    for (int i = 0; i < n; i++) {
        C[i] = S.top();
        S.pop();
    }
}//时间复杂度为O(n)

int main() {
    char C[51];
    cout << "Enter a string" << endl;
    cin >> C;
    //getline(cin, C);
    Reverse(C, strlen(C));
    cout << "Output = " << C << endl;
}

//---------------基于链表的实现----------------

struct Node {
    int data;
    Node* next;
};

Node* Reverse(Node* head) {
    if (head == nullptr) return;
    stack<struct Node*> S;
    Node* temp = head;
    //压栈
    while (temp != nullptr) {
        S.push(temp);
        temp = temp->next;
    }
    //更新头节点
    Node* newHead = S.top();
    S.pop();
    temp = newHead;
    //重连（反向连接）
    while (!S.empty()) {
        temp->next = S.top();
        S.pop();
        temp = temp->next;
    }
    temp->next = nullptr;
}


//---------------补充（双指针法）-----------------
//核心思路：用左指针指向字符串头部，右指针指向字符串尾部，
//交换两个指针指向的字符，然后左指针右移、右指针左移，直到两指针相遇，完成反转。
//时间复杂度：O(n)（仅遍历一半字符）
//空间复杂度：O(1)（原地修改，无额外内存）

#include <iostream>
#include <string>
using namespace std;
void reverseString(string& s) {
    int left = 0;
    int right = s.size() - 1;
    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }
}

int main() {
    string str = "hello world";
    cout << "原字符串：" << str << endl;
    reverseString(str);
    cout << "反转后：" << str << endl;
    return 0;
}
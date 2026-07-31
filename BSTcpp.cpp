//BST是一种平衡二叉树，所有左子树中节点的值小于根节点的值。所有右子树中右节点的值大于根节点的值（联系二分查找）
//最常见的是基于链表的实现

#include<iostream>
using namespace std;

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

//在堆内存创建新节点
BstNode* GetNewNode(int data) {
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//插入新节点，返回根节点
BstNode* Insert(BstNode* root, int data) {
    if (root == NULL) {
        root = GetNewNode(data);
    } else if (data <= root->data) {
        root->left = Insert(root->left, data);
    } else {
        root->right = Insert(root->right, data);
    }
    return root;
}

//搜索节点，如找到则返回true
bool Search(BstNode* root, int data) {
    if (root == NULL) {
        return false;
    } else if (root->data == data) {
        return true;
    } else if (data <= root->data) {
        return Search(root->left, data);
    } else {
        return Search(root->right, data);
    }
}

int main() {
	BstNode* root = NULL;  //创建空树、根节点为空
	/*Code to test the logic*/
	root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
	// Ask user to enter a number.  
	int number;
	cout<<"Enter number be searched\n";
	cin>>number;
	//If number is found, print "FOUND"
	if(Search(root,number) == true) cout<<"Found\n";
	else cout<<"Not Found\n";
}

//寻找最小值
int FindMin(BstNode* root) {
    if (root == NULL) {
        cout << "Error: Tree is empty\n";
        return -1;
    }
    BstNode* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current->data;
}

int FindMin(BstNode* root) {
    if (root == NULL) {
        cout << "Error: Tree is empty\n";
        return -1;
    }
    else if (root->left == NULL) {
        return root->data;
    }
    return FindMin(root->left);
}//遍历做法

//寻找最大值类似，区别为遍历右子树

//二叉树高度
int FindHeight (BstNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = FindHeight(root->left);
    int rightHeight = FindHeight(root->right);
    return max(leftHeight, rightHeight) + 1; 
}
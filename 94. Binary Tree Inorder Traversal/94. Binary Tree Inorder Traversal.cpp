//94. Binary Tree Inorder Traversal
//Given a binary tree, return the inorder traversal of its nodes' values.
//
//For example :
//Given binary tree[1, null, 2, 3],
//
//        1
//          \
//          2
//         /
//        3
//
//return[1, 3, 2]
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

//�������Ľṹ��
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/


/****************************************************
ʱ�䣺2016��6��22��   10��01��50��
ע�ͣ�Myself  ���������������
***************************************************/
struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
//�ݹ�ʵ�ֶ��������������
void inOrderTraversal(TreeNode *root) {
	if (root==NULL)
	{
		return;
	}
	inOrderTraversal(root->left);//�ݹ���ã��������������  
    cout << root->val << "_&_";//�������  
	inOrderTraversal(root->right); //�ݹ���ã��������������  
}

//�ǵݹ�ʵ�ֶ����������������
void inOrder_NoRecursive(TreeNode *root) {
     if (root==NULL)
     {
		 return;
     }
	 stack<TreeNode*>  s;
	 TreeNode *temp = root;
	 while (temp||!s.empty())
	 {
		 if (temp)
		 {
			 s.push(temp);
			 temp = temp->left;
		 }
		 else {
			 temp = s.top();
			 cout << temp->val << "_@_";
			 s.pop();
			 temp = temp->right;

		 }
	 }

}





//�ǵݹ�ʵ��
vector<int> inorderTraversal(TreeNode* root) {
	vector<int> vals;
	stack<TreeNode*> s;
	if (!root)
	{
		return vals;
	}
	TreeNode *temp = root;
	while (temp||s.empty())
	{
		if (temp)
		{
			s.push(temp);
			temp = temp->left;
		}
		else {
			temp = s.top();
			vals.push_back(temp->val);
			s.pop();
			temp = temp->right;
		}
	}
	return vals;
}
int main() {
	//Given binary tree{ 1,#,2,3 },	
	TreeNode  aa(1);
	TreeNode  bb(2);
	TreeNode  cc(3);

	aa.right = &bb;
	bb.left = &cc;

	inOrderTraversal(&aa);
	inOrder_NoRecursive(&aa);

	auto res = inorderTraversal(&aa);
	for (auto r : res)
	{
		cout << r << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
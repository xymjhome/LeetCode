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

//二叉树的结构体
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
时间：2016年6月22日   10点01分50秒
注释：Myself  二叉树的中序遍历
***************************************************/
struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
//递归实现二叉树的中序遍历
void inOrderTraversal(TreeNode *root) {
	if (root==NULL)
	{
		return;
	}
	inOrderTraversal(root->left);//递归调用，中序遍历左子树  
    cout << root->val << "_&_";//输出数据  
	inOrderTraversal(root->right); //递归调用，中序遍历右子树  
}

//非递归实现二叉树放入中序遍历
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





//非递归实现
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
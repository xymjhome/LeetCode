//144. Binary Tree Preorder Traversal
//
//Given a binary tree, return the preorder traversal of its nodes' values.
//
//For example :
//Given binary tree{ 1,#,2,3 },
//
//        1
//          \
//            2
//           /
//          3
//
//return[1, 2, 3].
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
ʱ�䣺2016��6��20��   22��13��19��
ע�ͣ�Myself  ���������������
***************************************************/
struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};


//Internet   ������������������ķ���
//1������������������ĵݹ���ʽ
//�ݹ������(�ݹ��������ջ�洢����һ�����Ƚ����)
//˼�룺��������Ϊ�գ����ء�����   1���������ڵ㣻2�����������������3���������������
void preOrder(TreeNode *root) {
	if (!root)
	{
		return;
	}
	cout << root->val << "***"; //�������  
	preOrder(root->left); //�ݹ���ã��������������  
	preOrder(root->right);//�ݹ���ã��������������  
	
	
}
//2���ǵݹ����
//˼�룺�������ķǵݹ�����������������˼�룺���ø���ջ��ֻҪջ��Ϊ�գ��Ϳ��������������� ÿ�ε���һ����㣬�ǵð��������ҽ�㶼��ջ���ǵ��������Ƚ�ջ���������Ա�֤��������ջ���ܴ��������������档
void PreOrder_Nonrecursive(TreeNode *root)     //��������ķǵݹ�    
{
	if (!root)
	{
		return;
	}
	stack<TreeNode*> s;
	s.push(root);
	while (!s.empty())
	{
		TreeNode *temp = s.top();
		cout << temp->val << "_&_";
		s.pop();
		if (temp->right)
		{
			s.push(temp->right);
		}
		if (temp->left)
		{
			s.push(temp->left);
		}
	}
}


//����һ�ַǵݹ��������������ķ������� �������ϵĽڵ�ȫ��ѹ�뵽ջ�У�Ȼ�����ε���������������������������������������������ٰ����е���������վ�������γ�վִ�С�
void PreOrder_Nonrecursive2(TreeNode *root) {
	if (!root) return;
	stack<TreeNode*> s;
	while (root) {    // // �������ϵĽڵ�ȫ��ѹ�뵽ջ��  
		s.push(root);
		cout << root->val << "_*_";
		root = root->left;
	}
	while (!s.empty())
	{
		TreeNode *temp = s.top()->right;// ջ��Ԫ�ص������� 
		s.pop();   // ����ջ��Ԫ��  
		while (temp)
		{
			s.push(temp);
			cout << temp->val << "+@+";
			temp = temp->left;

		}
	}
}

void  PreOrder_NonRecursive3(TreeNode *root) {
	if (!root)
		return;
	stack<TreeNode*> s;
	TreeNode *temp = root;
	while (temp || !s.empty())
	{
		if (temp)
		{
			cout << temp->val << "_***_";
			s.push(temp);
			temp = temp->left;
		}
		else
		{
			temp = s.top()->right;
			s.pop();
			if (temp)
			{
				s.push(temp);
				cout << temp->val << "_****_";
				temp = temp->left;
			}
		}
	}
}


/*********************************************************************************************************/




//�����������������⣬�ݹ�洢����̬vals�еı�����������  ���󣡣�������������������
//vector<int> preorderTraversal(TreeNode* root) {
//	static vector<int> vals;
//	if (root == NULL) 
//		//vals.push_back(root->val);
//		return vals;
//	}
//	if (root!=NULL)
//	{
//		vals.push_back(root->val);
//	}
//	if (root->left)
//	{
//		preorderTraversal(root->left);
//	}
//	if (root->right)
//	{
//		preorderTraversal(root->right);
//	}
//
//	return vals;
//}

//1�����÷ǵݹ�����������������������ڵ�ֵ���������ڵ�ʱ���Ƚ�ջ��������ͬʱ��ջ
//You are here!  Your runtime beats 21.35% of cppsubmissions.
vector<int> preorderTraversal1(TreeNode* root) {
	vector<int> vals;
	if (!root)
	{
		return vals;
	}
	stack<TreeNode*> s;
	s.push(root);
	while (!s.empty())
	{
		TreeNode *temp = s.top();
		vals.push_back(temp->val);
		s.pop();
		if (temp->right)
		{
			s.push(temp->right);
		}
		if (temp->left)
		{
			s.push(temp->left);
		}
	}
	return vals;
}
//2�����÷ǵݹ�Ӹ��ڵ�������������ջ��Ȼ�����γ�ջ�����������ݳ�ջ����������������������������ٸ���������������ջ�����������������������α������У�ֻҪմ��Ϊ��
//You are here! Your runtime beats 21.35% of cppsubmissions.
vector<int> preorderTraversal2(TreeNode* root) {
	vector<int> vals;
	if (!root)
	{
		return vals;
	}
	stack<TreeNode*> s;
	while (root)
	{
		vals.push_back(root->val);
		s.push(root);
		root = root->left;
	}
	while (!s.empty())
	{
		TreeNode *temp = s.top()->right;
		s.pop();
		while (temp)
		{
			vals.push_back(temp->val);
			s.push(temp);
			temp = temp->left;
		}
	}
	return vals;
}
//3�����õݹ��������������
//�ݹ����(1)
//You are here!  Your runtime beats 21.35% of cppsubmissions.
vector<int>  resVals;
void preOrderRecursive(TreeNode *root) {
	if (!root)
	{
		return;
	}
	resVals.push_back(root->val);
	preOrderRecursive(root->left);
	preOrderRecursive(root->right);
}
vector<int> preorderTraversal3(TreeNode* root) {
	vector<int> vals;
	if (!root)
	{
		return vals;
	}
	preOrderRecursive(root);
	return resVals;
}
//�ݹ����(2)
//You are here!  Your runtime beats 0.20% of cppsubmissions.    Ч�ʲ��ߣ�����������������������
vector<int> preorderTraversal4(TreeNode* root) {
	vector<int> vals;
	if (!root)
	{
		return vals;
	}
	vals.push_back(root->val);
	auto vl = preorderTraversal4(root->left);
	vals.insert(vals.end(), vl.begin(), vl.end());//insert����������ָ��λ�ò���һ�����䣬��push_backֻ�ܲ���һ��ֵ��ĩβ��
	auto v2 = preorderTraversal4(root->right);
	vals.insert(vals.end(), v2.begin(), v2.end());

	return vals;
}
int main() {
	//Given binary tree{ 1,#,2,3 },	
	TreeNode  aa(1);
	TreeNode  bb(2);
	TreeNode  cc(3);

	aa.right = &bb;
	bb.left = &cc;

	PreOrder_NonRecursive3(&aa);
	//���õݹ���������
	//preOrder(&aa);
	////���÷ǵݹ�Ķ�ջʵ�ֵĶ�ջ�������
	//PreOrder_Nonrecursive(&aa);
	////���÷ǵݹ�Ķ�ջʵ�ֵĶ�ջ�������2
	//PreOrder_Nonrecursive2(&aa);



	auto res = preorderTraversal1(&aa);
	for (auto r:res)
	{
		cout << r << " ";
	}
	cout << endl;
	auto res2 = preorderTraversal2(&aa);
	for (auto r2 : res2)
	{
		cout << r2 << " ";
	}
	cout << endl;
	auto res3 = preorderTraversal3(&aa);
	for (auto r3 : res3)
	{
		cout << r3 << " ";
	}
	cout << endl;
	auto res4 = preorderTraversal4(&aa);
	for (auto r4 : res4)
	{
		cout << r4 << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
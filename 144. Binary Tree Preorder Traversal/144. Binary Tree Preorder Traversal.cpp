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
时间：2016年6月20日   22点13分19秒
注释：Myself  二叉树的先序遍历
***************************************************/
struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};


//Internet   两种现需遍历二叉树的方法
//1、二叉树的先序遍历的递归形式
//递归操作：(递归操作就像栈存储数据一样，先进后出)
//思想：若二叉树为空，返回。否则   1）遍历根节点；2）先序遍历左子树；3）先序遍历右子树
void preOrder(TreeNode *root) {
	if (!root)
	{
		return;
	}
	cout << root->val << "***"; //输出数据  
	preOrder(root->left); //递归调用，先序遍历左子树  
	preOrder(root->right);//递归调用，先序遍历右子树  
	
	
}
//2、非递归操作
//思想：二叉树的非递归先序遍历，先序遍历思想：先让根进栈，只要栈不为空，就可以做弹出操作， 每次弹出一个结点，记得把它的左右结点都进栈，记得右子树先进栈，这样可以保证右子树在栈中总处于左子树的下面。
void PreOrder_Nonrecursive(TreeNode *root)     //先序遍历的非递归    
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


//另外一种非递归二叉树现需遍历的方法是先 左子树上的节点全部压入到栈中，然后依次弹出左子树，访问右子树（如果右子树具有左子树，再把所有的左子树入站），依次出站执行。
void PreOrder_Nonrecursive2(TreeNode *root) {
	if (!root) return;
	stack<TreeNode*> s;
	while (root) {    // // 左子树上的节点全部压入到栈中  
		s.push(root);
		cout << root->val << "_*_";
		root = root->left;
	}
	while (!s.empty())
	{
		TreeNode *temp = s.top()->right;// 栈顶元素的右子树 
		s.pop();   // 弹出栈顶元素  
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




//这个方法结果存在问题，递归存储到静态vals中的变量存在问题  错误！！！！！！！！！！！
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

//1、利用非递归左子树和右子树（输出根节点值，弹出根节点时，先进栈右子树）同时进栈
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
//2、利用非递归从根节点起左子树都进栈，然后依次出栈左子树，根据出栈的左子树查找其自身的右子树，再根据右子树遍历进栈右子树的所有左子树，依次遍历进行，只要沾不为空
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
//3、利用递归先序遍历二叉树
//递归遍历(1)
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
//递归遍历(2)
//You are here!  Your runtime beats 0.20% of cppsubmissions.    效率不高！！！！！！！！！！！！
vector<int> preorderTraversal4(TreeNode* root) {
	vector<int> vals;
	if (!root)
	{
		return vals;
	}
	vals.push_back(root->val);
	auto vl = preorderTraversal4(root->left);
	vals.insert(vals.end(), vl.begin(), vl.end());//insert方法可以在指定位置插入一个区间，而push_back只能插入一个值在末尾。
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
	//调用递归的先序遍历
	//preOrder(&aa);
	////调用非递归的堆栈实现的堆栈先序遍历
	//PreOrder_Nonrecursive(&aa);
	////调用非递归的堆栈实现的堆栈先序遍历2
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
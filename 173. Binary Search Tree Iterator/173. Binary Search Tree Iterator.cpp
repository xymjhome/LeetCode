//173. Binary Search Tree Iterator
//Implement an iterator over a binary search tree(BST).Your iterator will be initialized with the root node of a BST.
//
//Calling next() will return the next smallest number in the BST.
//
//Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
#include <stack>
#include <vector>

#include <iostream>
using namespace std;


/***时间：2016年6月27日   16点51分39秒***/
/**You are here!  Your runtime beats 76.58% of cppsubmissions.*/
/**
* Definition for binary tree
**/
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
       bstRoot = root; 
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
       return (bstRoot ||!s.empty());
	}

	/** @return the next smallest number */
	int next() {
      int res = 0;
      while(bstRoot){
        s.push(bstRoot);
        bstRoot = bstRoot->left;
		}
        TreeNode *temp = s.top();
        //cout << temp->val << endl;
        res = temp->val;
        s.pop();
        bstRoot = temp->right;
        return res;
	}
private:
    stack<TreeNode*> s;
    TreeNode *bstRoot;
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/

int main() {
	
	TreeNode root(6);
    TreeNode aa(5);
    TreeNode bb(2);
    TreeNode cc(5);
    TreeNode dd(7);
    TreeNode ee(8);

    root.left = &aa;
    root.right = &dd;
    aa.left = &bb;
    aa.right = &cc;
    dd.right = &ee;

	BSTIterator i = BSTIterator(&root);
	while (i.hasNext()) 
		cout << i.next()<<"  ";
 
	system("pause");
	return 0;
}

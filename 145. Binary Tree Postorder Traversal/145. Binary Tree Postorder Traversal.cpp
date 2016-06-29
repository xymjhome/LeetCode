//145. Binary Tree Postorder Traversal
//Given a binary tree, return the postorder traversal of its nodes' values.
//
//For example :
//Given binary tree{ 1,#,2,3 },
//
//             1
//               \
//               2
//              /
//             3
//
//return[3, 2, 1].
#include <iostream>

#include <vector>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

/****************************************************
时间：2016年6月23日   15点04分50秒
注释：Myself  
***************************************************/
//二叉树的后续遍历的递归形式
void postOrder(TreeNode *root){
   if(root==NULL)
     return ;
   postOrder(root->left);
   postOrder(root->right);
   cout<<root->val<<"_@_";
    
}


//void PostOrder_Nonrecursive(BiTree  T)  // 后序遍历的非递归    
//{
//	stack<BiTree> S;
//	BiTree curr = T;           // 指向当前要检查的节点  
//	BiTree previsited = NULL;    // 指向前一个被访问的节点  
//	while (curr != NULL || !S.empty())  // 栈空时结束    
//	{
//		while (curr != NULL)            // 一直向左走直到为空  
//		{
//			S.push(curr);
//			curr = curr->lchild;
//		}
//		curr = S.top();
//		// 当前节点的右孩子如果为空或者已经被访问，则访问当前节点  
//		if (curr->rchild == NULL || curr->rchild == previsited)
//		{
//			cout << curr->data << "  ";
//			previsited = curr;
//			S.pop();
//			curr = NULL;
//		}
//		else
//			curr = curr->rchild;      // 否则访问右孩子  
//	}
//}


//二叉树的后续遍历的fei递归形式
void  postOrder_NoRecursive(TreeNode *root){
    if(root==NULL)
      return;
    TreeNode *temp = root;
    stack<TreeNode*> s;
	TreeNode *preVisited = NULL;// 指向前一个被访问的节点  ;
    while(temp || !s.empty() )
    {
        if(temp)
        {
           s.push(temp); 
           temp = temp->left;
        }
        else{
           temp = s.top();
           if(!temp->right||temp->right == preVisited)// 当前节点的右孩子如果为空或者已经被访问，则访问当前节点  
           {
             cout<<s.top()->val<<"_#_";
             preVisited = temp;//
             s.pop();
             temp=NULL;
           }
           else
             temp = temp->right;
        }
    }
} 

//二叉树的后续遍历的fei递归形式2,利用两个栈进行二叉树的非递归形式的后续遍历
void postOrder_TwoStack(TreeNode *root){
    if(!root) return;
    stack<TreeNode*> s1,s2;
    s1.push(root);
    while(!s1.empty()){
        TreeNode *temp = s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left)
          s1.push(temp->left);
        if(temp->right)
          s1.push(temp->right);
    }
    while(!s2.empty())
    {
        cout<<s2.top()->val<<"_two_";
        s2.pop();
    }
}



/****************************************************
时间：2016年6月23日   16点53分48秒
***************************************************/
vector<int> postorderTraversal(TreeNode* root) {
	vector<int> vals;
	if (!root)
		return vals;
    stack<TreeNode*> s;
    TreeNode *temp = root;
    TreeNode *preVisited = NULL;
    while(temp || !s.empty())
    {
        if(temp){
            s.push(temp);
            temp = temp -> left;
        }
        else{
            temp = s.top();
            if(temp->right==NULL || temp->right == preVisited){
                vals.push_back(temp->val);
                preVisited = temp;
                s.pop();
                temp = NULL;
            }
            else
              temp = temp ->right;
        }
    }
    return vals;
}
int main(){
    TreeNode aa(1);
    TreeNode bb(2);
    TreeNode cc(3);

    aa.right = &bb;
    bb.left = &cc;

    postOrder(&aa);
	postOrder_NoRecursive(&aa);
	postOrder_TwoStack(&aa);

    auto res = postorderTraversal(&aa);
    for(auto r : res)
      cout<<r<<endl;


    system("pause");
    return 0;


}

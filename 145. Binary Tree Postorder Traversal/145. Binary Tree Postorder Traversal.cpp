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
ʱ�䣺2016��6��23��   15��04��50��
ע�ͣ�Myself  
***************************************************/
//�������ĺ��������ĵݹ���ʽ
void postOrder(TreeNode *root){
   if(root==NULL)
     return ;
   postOrder(root->left);
   postOrder(root->right);
   cout<<root->val<<"_@_";
    
}


//void PostOrder_Nonrecursive(BiTree  T)  // ��������ķǵݹ�    
//{
//	stack<BiTree> S;
//	BiTree curr = T;           // ָ��ǰҪ���Ľڵ�  
//	BiTree previsited = NULL;    // ָ��ǰһ�������ʵĽڵ�  
//	while (curr != NULL || !S.empty())  // ջ��ʱ����    
//	{
//		while (curr != NULL)            // һֱ������ֱ��Ϊ��  
//		{
//			S.push(curr);
//			curr = curr->lchild;
//		}
//		curr = S.top();
//		// ��ǰ�ڵ���Һ������Ϊ�ջ����Ѿ������ʣ�����ʵ�ǰ�ڵ�  
//		if (curr->rchild == NULL || curr->rchild == previsited)
//		{
//			cout << curr->data << "  ";
//			previsited = curr;
//			S.pop();
//			curr = NULL;
//		}
//		else
//			curr = curr->rchild;      // ��������Һ���  
//	}
//}


//�������ĺ���������fei�ݹ���ʽ
void  postOrder_NoRecursive(TreeNode *root){
    if(root==NULL)
      return;
    TreeNode *temp = root;
    stack<TreeNode*> s;
	TreeNode *preVisited = NULL;// ָ��ǰһ�������ʵĽڵ�  ;
    while(temp || !s.empty() )
    {
        if(temp)
        {
           s.push(temp); 
           temp = temp->left;
        }
        else{
           temp = s.top();
           if(!temp->right||temp->right == preVisited)// ��ǰ�ڵ���Һ������Ϊ�ջ����Ѿ������ʣ�����ʵ�ǰ�ڵ�  
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

//�������ĺ���������fei�ݹ���ʽ2,��������ջ���ж������ķǵݹ���ʽ�ĺ�������
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
ʱ�䣺2016��6��23��   16��53��48��
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

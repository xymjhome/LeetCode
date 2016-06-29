//42. Trapping Rain Water
//Given n non - negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
//
//For example,
//Given[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1], return 6.
//
//The above elevation map is represented by array[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1].In this case, 6 units of rain water(blue section) are being trapped.Thanks Marcos for contributing this image!

#include <stack>
#include <vector>
#include <iostream>
using namespace std;



/****************************************
时间：2016年6月29日   10点49分28秒
注释：Internet + Myself
deque 即双端队列。
   （deque，全名double-ended queue）是一种具有队列和栈的性质的数据结构。双端队列中的元素可以从两端弹出，其限定插入和删除操作在表的两端进行。
     双端队列是限定插入和删除操作在表的两端进行的线性表。这两端分别称做端点1和端点2。也可像栈一样，可以用一个铁道转轨网络来比喻双端队列。在实际使用中，还可以有输出受限的双端队列（即一个端点允许插入和删除，另一个端点只允许插入的双端队列）和输入受限的双端队列（即一个端点允许插入和删除，另一个端点只允许删除的双端队列）。而如果限定双端队列从某个端点插入的元素只能从该端点删除，则该双端队列就蜕变为两个栈底相邻的栈了。

int trap(int A[], int n) {
	if (n <= 2)
		return 0;

	deque<int> queue;          //双端队列
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (queue.empty() || A[i] < queue[0]) {
			queue.push_back(A[i]);
		}
		else { // 容器的另一半
			while (!queue.empty()) {
				sum += queue[0] - queue.back();
				queue.pop_back();
			}
			queue.push_back(A[i]);
		}
	}
	// reverse last part
	deque<int> stack;

	for (int i = queue.size() - 1; i >= 0; i--) {
		if (stack.empty() || queue[i] < stack[0]) {
			stack.push_back(queue[i]);
		}
		else {
			while (!stack.empty()) {
				sum += stack[0] - stack.back();
				stack.pop_back();
			}
			stack.push_back(queue[i]);
		}
	}
	return sum;
}

****************************************/
int trap(vector<int>& height) {
	if (height.size()<=2)
	{
		return 0;
	}
    vector<int> preHeightVal;
    int sum = 0;
    for(int i = 0; i<height.size();i++){
       if(preHeightVal.empty() || height[i]<preHeightVal[0]){
             preHeightVal.push_back(height[i]); 
        }
	   else {
		   while (!preHeightVal.empty())
		   {
			   sum += (preHeightVal[0] - preHeightVal.back());
			   preHeightVal.erase(preHeightVal.end() - 1);
		   }
		   preHeightVal.push_back(height[i]);

	   }
    }
    vector<int> lastHeightVal;
    for(int i = preHeightVal.size()-1;i>=0;i--)
    {
        if(lastHeightVal.empty() || preHeightVal[i]<lastHeightVal[0]){
             lastHeightVal.push_back(preHeightVal[i]);
        }
		else{
			while(!lastHeightVal.empty())
			{
				 sum +=  (lastHeightVal[0] - lastHeightVal.back());
				 lastHeightVal.erase(lastHeightVal.end()-1);  
			} 
			lastHeightVal.push_back(preHeightVal[i]);
		}

    }
	return sum;
}
int main() {
	vector<int> vals = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	cout<<trap(vals)<<endl;



	system("pause");
	return 0;

}

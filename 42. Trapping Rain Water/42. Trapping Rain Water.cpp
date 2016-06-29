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
ʱ�䣺2016��6��29��   10��49��28��
ע�ͣ�Internet + Myself
deque ��˫�˶��С�
   ��deque��ȫ��double-ended queue����һ�־��ж��к�ջ�����ʵ����ݽṹ��˫�˶����е�Ԫ�ؿ��Դ����˵��������޶������ɾ�������ڱ�����˽��С�
     ˫�˶������޶������ɾ�������ڱ�����˽��е����Ա������˷ֱ�����˵�1�Ͷ˵�2��Ҳ����ջһ����������һ������ת������������˫�˶��С���ʵ��ʹ���У���������������޵�˫�˶��У���һ���˵���������ɾ������һ���˵�ֻ��������˫�˶��У����������޵�˫�˶��У���һ���˵���������ɾ������һ���˵�ֻ����ɾ����˫�˶��У���������޶�˫�˶��д�ĳ���˵�����Ԫ��ֻ�ܴӸö˵�ɾ�������˫�˶��о��ɱ�Ϊ����ջ�����ڵ�ջ�ˡ�

int trap(int A[], int n) {
	if (n <= 2)
		return 0;

	deque<int> queue;          //˫�˶���
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (queue.empty() || A[i] < queue[0]) {
			queue.push_back(A[i]);
		}
		else { // ��������һ��
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

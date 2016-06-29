//Implement the following operations of a queue using stacks.
//
//push(x) --Push element x to the back of queue.
//pop() --Removes the element from in front of queue.
//peek() --Get the front element.
//empty() --Return whether the queue is empty.
//
//Notes:
//
//You must use only standard operations of a stack -- which means only push to top, peek / pop from top, size, and is empty operations are valid.
//Depending on your language, stack may not be supported natively.You may simulate a stack by using a list or deque(double - ended queue), as long as you use only standard operations of a stack.
//You may assume that all operations are valid(for example, no pop or peek operations will be called on an empty queue).

#include <stack>
#include <iostream>
using namespace std;


/***
ʱ�䣺2016��6��28��   16��10��48��
Myself
You are here! Your runtime beats 11.69% of cppsubmissions
***/
class Queue {
public:
	// Push element x to the back of queue.
	void push(int x) {
		while (!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
		s1.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void) {
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
		s2.pop();
	}

	// Get the front element.
	int peek(void) {
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
		return s2.top();
	}

	// Return whether the queue is empty.
	bool empty(void) {
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
		return s2.empty();
	}
private:
	stack<int> s1;
	stack<int> s2;
};

/****************************************
ʱ�䣺2016��6��28��   16��17��27��
ע�ͣ�Internet  +  Myself  ˼·����������ջ
��ĿҪ��ͨ��ջ��ģ����е���Ϊ���������㷨���۵�ʮ�µ�һ���⡣�㷨���£�
��ջa��b��a������ӣ�b����
��1���ж��������a����b��Ϊ�գ������
��2���жӿգ����a��b��Ϊ�գ���ӿ�
��3����ӣ������ж�����
���Ӳ�������1��ջa����������ֱ��ѹ��ջa
		   (2)��a������a�е�����Ԫ�ص�����ջb�У�Ȼ���ٽ�Ԫ����ջa
��4�����ӣ�(1)��b�վͽ�a�е�����Ԫ�ص�����ջb�У�Ȼ���ջ
          ��2��b���վ�ֱ�Ӵ�b�е���Ԫ��
You are here!  Your runtime beats 11.69% of cppsubmissions.
****************************************/
class Queue2 {
public:
	stack<int> in;
	stack<int> out;
	// Push element x to the back of queue.
	void push(int x) {
		in.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void) {
		if(out.empty()) {
          while(!in.empty())
          {
			out.push(in.top());
			in.pop();
          }
		}
        out.pop();
	}

	// Get the front element.
	int peek(void) {
      if(out.empty())
      {
	      while(!in.empty())
          {
			out.push(in.top());
			in.pop();
          }
      }
      return out.top();
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return in.empty()&&out.empty();
	}
};

int main() {

	Queue2 que;
	/*for (int i=0;i<10;i++)
	{
		que.push(i);
	}
	while (!que.empty())
	{
		cout << que.peek() << "  ";
		que.pop();
	}*/

	que.push(1);
	que.push(2);
	cout<<que.peek()<<endl;
	que.push(3);
	cout<<que.peek()<<endl;


	system("pause");
	return 0;

}

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
时间：2016年6月28日   16点10分48秒
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
时间：2016年6月28日   16点17分27秒
注释：Internet  +  Myself  思路：利用两个栈
题目要求通过栈来模拟队列的行为。此题是算法导论第十章的一道题。算法如下：
堆栈a和b，a用作入队，b出队
（1）判队满：如果a满且b不为空，则队满
（2）判队空：如果a和b都为空，则队空
（3）入队：首先判队满。
若队不满：（1）栈a若不满，则直接压入栈a
		   (2)若a满，则将a中的所有元素弹出到栈b中，然后再将元素入栈a
（4）出队：(1)若b空就将a中的所有元素弹出到栈b中，然后出栈
          （2）b不空就直接从b中弹出元素
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

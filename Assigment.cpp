
#include <stack>
#include <iostream>
#include <ctype.h>
using namespace std;
char ch;

int Postfix(string exp)
{
	stack<int> stack;

	// " .size  "is to indicate the size of expression to loop on it
	for (int i = 0; i < exp.size(); ++i) {

		// isdigit function is to check  if the passed character is a digit or not

		if (isdigit(exp[i]))
			stack.push(exp[i] - '0');

		// If the scanned character is an operator we enter this block;
		else {
			int val1 = stack.top();
			stack.pop();
			int val2 = stack.top();
			stack.pop();
			switch (exp[i]) {
			case '+':
				stack.push(val2 + val1);
				break;
			case '-':
				stack.push(val2 - val1);
				break;
			case '*':
				stack.push(val2 * val1);
				break;
			case '/':
				stack.push(val2 / val1);
				break;
			case '^': 
				stack.push(pow(val2, val1));
				break;
			}
		}
	}
	return stack.top();
}

int main()
{
	do
	{
		cout << "enter a postfix  " << endl;;
		string exp;
		cin >> exp;
		cout << "postfix evaluation: " << Postfix(exp) << endl;
		cout << "do you want to continue (Y/N)" << endl;
				cin >> ch;
	} while (ch != 'n');
}









///////////////////////////////////////
 /*
 void push(int val)
 {
 top++
 stack[top]=val;
 }


void pop()
{
if(top<=-1)
cout<<"stack underflow"<<endl;
else{
cout<<"the popped element is"<<stack[top]<<endl;
top--;}
}*/






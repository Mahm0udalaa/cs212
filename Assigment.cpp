
#include <stack>
#include <iostream>
#include <ctype.h>
using namespace std;

int evaluatePostfix(string exp)
{
	// Create a stack named stack
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
			}
		}
	}
	return stack.top();
}

int main()
{
	string exp;
	cin >> exp;
	cout << "postfix evaluation: " << evaluatePostfix(exp);
	return 0;
}


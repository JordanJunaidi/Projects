#include <iostream>
#include <string>
#include <stack>


using namespace std;

bool solve(string expression) {
	stack<char> brackets;


	for (unsigned int i = 0; i < expression.size(); i++) {
		brackets.push(expression[i]);
		if (brackets.top() == '{' || brackets.top() == '(' || brackets.top() == '[') {
			continue;
		}
		else {
			if (brackets.top() == '}') {
				brackets.pop();
				if (brackets.top() == '{') {
					brackets.pop();
				}
				else {
					cout << "NO" << endl;
					return false;
				}
			}
			else if (brackets.top() == ')') {
				brackets.pop();
				if (brackets.top() == '(') {
					brackets.pop();
				}
				else {
					cout << "NO" << endl;
					return false;
				}
			}
			else if (brackets.top() == ']') {
				brackets.pop();
				if (brackets.top() == '[') {
					brackets.pop();
				}
				else {
					cout << "NO" << endl;
					return false;
				}
			}
		}
	}

	cout << "YES" << endl;
	return true;

	
}

void test() {
  string one = "{[()]}";
  string two = "{[(])}";
  string three = "{{[[(())]]}}";
  cout << "Test case 1: " << one << endl;
  cout << boolalpha << solve(one) << endl;
  cout << "Expected: YES" << endl;
  cout << "Test case 2: " << two << endl;
  cout << boolalpha << solve(two) << endl;
  cout << "Expected: NO" << endl;
  cout << "Test case 3: " << three << endl;
  cout << boolalpha << solve(three) << endl;
  cout << "Expected: YES" << endl;
}

int main(void) {
  test();
}

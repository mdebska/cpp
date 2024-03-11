#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
	stack<int> numbers;
	stack<char> operators;
	char token;

	while (cin >> token) {

		// tworzenie stosow operatorow i liczb
		if (token >= '0' && token <= '9') {
			int value = token - '0';
			numbers.push(value);
		}
		else if (token == '/' || token == '*' || token == '-' || token == '+') {
			operators.push(token);
		}

		else if (token == '(') {
			continue;
		}

		// wykonywanie odpowiednich operacji
		else if (token == ')') {
			char operation = operators.top();
			operators.pop();
			int value2 = numbers.top();
			numbers.pop();
			int value1 = numbers.top();
			numbers.pop();
			if (operation == '+') {
				numbers.push(value1 + value2);
			}
			else if (operation == '-') {
				numbers.push(value1 - value2);
			}
			else if (operation == '*') {
				numbers.push(value1 * value2);
			}
			else if (operation == '/') {

				// wyj¹tek - dzielenie przez zero
				if (value2 == 0) {
					cout << "NaN";
					return 0;
				}
				numbers.push(value1 / value2);
			}
		}
		if (cin.get() == '\n') {
		break;
		}
	}
	cout << numbers.top();
	return 0;
}

// kolejka priorytetowa liczb
priority_queue<int> numbers;

#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

double evaluate(string expression)
{
    stack<double> numbers;
    stack<char> operators;

    for (int i = 0; i < expression.length(); i++)
    {
        if (isdigit(expression[i]))
        {
            double number = 0;
            while (i < expression.length() && isdigit(expression[i]))
            {
                number = number * 10 + (expression[i] - '0');
                i++;  
            }
            i--;

            numbers.push(number);
        }
        else if (expression[i] == '(')
        {
            operators.push('(');
        }
        else if (expression[i] == ')')
        {
            while (operators.top() != '(')
            {
                double operand2 = numbers.top();
                numbers.pop();
                double operand1 = numbers.top();
                numbers.pop();

                char op = operators.top();
                operators.pop();

                double result = 0;
                if (op == '+')
                {
                    result = operand1 + operand2;
                }
                else if (op == '-')
                {
                    result = operand1 - operand2;
                }
                else if (op == '*')
                {
                    result = operand1 * operand2;
                }
                else if (op == '/')
                {
                    result = operand1 / operand2;
                }
                else if (op == '^')
                {
                    result = pow(operand1, operand2);
                }

                numbers.push(result);
            }

            operators.pop();
        }
        else
        {
            if (expression[i] == '^')
            {
                operators.push(expression[i]);
            }
            else
            {
                while (!operators.empty() && (operators.top() == '^' || (operators.top() == '*' || operators.top() == '/') && (expression[i] == '+' || expression[i] == '-')))
                {
                    double operand2 = numbers.top();
                    numbers.pop();
                    double operand1 = numbers.top();
                    numbers.pop();

                    char op = operators.top();
                    operators.pop();

                    double result = 0;
                    if (op == '+')
                    {
                        result = operand1 + operand2;
                    }
                    else if (op == '-')
                    {
                        result = operand1 - operand2;
                    }
                    else if (op == '*')
                    {
                        result = operand1 * operand2;
                    }
                    else if (op == '/')
                    {
                        result = operand1 / operand2;
                    }
                    else if (op == '^')
                    {
                        result = pow(operand1, operand2);
                    }

                    numbers.push(result);
                }

                operators.push(expression[i]);
            }
        }
    }

    while (!operators.empty())
    {
        double operand2 = numbers.top();
        numbers.pop();
        double operand1 = numbers.top();
        numbers.pop();

        char op = operators.top();
        operators.pop();

        double result = 0;
        if (op == '+')
        {
            result = operand1 + operand2;
        }
        else if (op == '-')
        {
            result = operand1 - operand2;
        }
        else if (op == '*')
        {
            result = operand1 * operand2;
        }
        else if (op == '/')
        {
            result = operand1 / operand2;
        }
        else if (op == '^')
        {
            result = pow(operand1, operand2);
        }

        numbers.push(result);
    }

    return numbers.top();
}

int main()
{
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);

    cout << "Result: " << evaluate(expression) << endl;

    return 0;
}
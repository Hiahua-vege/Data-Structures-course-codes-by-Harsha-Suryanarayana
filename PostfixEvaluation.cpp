// C++后缀表达式（逆波兰表达式）求值

#include<iostream>
#include<stack>
#include<string>

using namespace std;

// 计算后缀表达式并返回最后结果的函数
int EvaluatePostfix(string expression);
// 进行单次四则运算并返回结果的函数
int PerformOperation(char operation, int operand1, int operand2);
// 判断一个字符是否为运算符
bool IsOperator(char C);
// 判断一个字符是否为数字
bool IsNumericDigit(char C);

int main() 
{
	string expression; 
	cout<<"Enter Postfix Expression \n";
	getline(cin,expression);
	int result = EvaluatePostfix(expression);
	cout<<"Output = "<<result<<"\n";
}

int EvaluatePostfix(string expression) {
    stack<int> S;
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ' || expression[i] == ',') continue;
        else if (IsOperator(expression[i])) {
            int operand2 = S.top(); S.pop();
            int operand1 = S.top(); S.pop();
            int result = PerformOperation(expression[i], operand1, operand2);
            S.push(result);
        }
        else if (IsNumericDigit(expression[i])) {
            int operand = 0;
            while (i < expression.length() && IsNumericDigit(expression[i])) {
                operand = (operand * 10) + (expression[i] - '0');
                i++;
            }// 读取多位数字的情形
            i--;
            S.push(operand);
        }
    }
    return S.top();
}

// 检查输入字符是否为数字
bool IsNumericDigit(char C)
{
    if(C >= '0' && C <= '9') return true;
    return false;
}

// 检查输入字符是否为运算符
bool IsOperator(char C)
{
    if(C == '+' || C == '-' || C == '*' || C == '/')
        return true;
    return false;
}

int PerformOperation(char operation, int operand1, int operand2)
{
	if(operation == '+') return operand1 +operand2;
	else if(operation == '-') return operand1 - operand2;
	else if(operation == '*') return operand1 * operand2;
	else if(operation == '/') return operand1 / operand2;

	else cout<<"Unexpected Error \n";
	return -1; 
}
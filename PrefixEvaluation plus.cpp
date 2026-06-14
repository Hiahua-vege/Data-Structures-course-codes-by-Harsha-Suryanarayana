// C++前缀表达式（波兰表达式）求值
#include<iostream>
#include<stack>
#include<string>

using namespace std;

// 计算前缀表达式并返回最后结果的函数
int EvaluatePrefix(string expression);
// 进行单次四则运算并返回结果的函数
int PerformOperation(char operation, int operand1, int operand2);
// 判断一个字符是否为运算符
bool IsOperator(char C);
// 判断一个字符是否为数字
bool IsNumericDigit(char C);

int main() 
{
	string expression; 
	cout<<"Enter Prefix Expression \n";
	getline(cin,expression);

    // 拦截空输入
    if (expression.empty())
    {
        cout << "输入不能为空！" << endl;
        return 0;
    }

	int result = EvaluatePrefix(expression);
	cout<<"Output = "<<result<<"\n";
    return 0;
}

int EvaluatePrefix(string expression) {
    stack<int> S;
    for (int i = expression.length() - 1; i >= 0; i--) {
        if (expression[i] == ' ' || expression[i] == ',') 
            continue;

        else if (IsOperator(expression[i])) {
            int operand2 = S.top(); S.pop();
            int operand1 = S.top(); S.pop();
            int result = PerformOperation(expression[i], operand1, operand2);
            S.push(result);
        }
        else if (IsNumericDigit(expression[i])) {
            int operand = 0;
            int power = 1; // 数位权重：个位、十位、百位......
            while (i >= 0 && IsNumericDigit(expression[i])) {
                operand += (expression[i] - '0') * power;
                power *= 10;
                i--;
            }
            S.push(operand);
        }
        else
        {
            // 非法字符
            cout << "表达式包含非法字符！" << endl;
            return 0;
        }
    }

    // 校验栈是否合法
    if (S.empty())
    {
        cout << "表达式格式错误！" << endl;
        return 0;
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
	if(operation == '+') 
        return operand1 + operand2;
	else if(operation == '-') 
        return operand1 - operand2;
	else if(operation == '*') 
        return operand1 * operand2;
	else if(operation == '/') 
	{
        if (operand2 == 0)
        {
            cout << "错误：除数不能为0！" << endl;
            return 0;
        }
        return operand1 / operand2;
    }

	cout<<"Unexpected Error \n";
	return -1; 
}
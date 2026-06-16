/*
    对于任意给定的一串中缀表达式，视为字符串进行遍历
    若遇到数字则归入后缀表达式字符串末尾

    若遇到运算符则压入空栈、后续运算符与栈顶运算符进行优先级比较--
    如果该运算符优先级低于栈顶运算符，则弹出栈顶运算符归入后缀表达式字符串末尾
    反复执行直到栈顶运算符优先级低于该运算符优先级

    特殊情况：两运算符优先级相等，则判断栈顶元素是否为右结合（如幂运算符$）
    若为右结合则不弹出栈顶、新元素直接入栈，若为左结合则弹出栈顶、再将新元素入栈

    遍历到括号()情况：左括号'('直接压入栈，后续运算符正常压入与比较。直到遇到右括号')'时
    右括号直到前一个左括号中间所包括的运算符全部按顺序弹出、归入后缀表达式中
    括号直接丢弃（前后缀表达式均不存在括号）
*/

/*
  C++ 实现中缀表达式转后缀表达式
  输入要求：操作数与运算符均为单字符
  支持运算符：+、-、*、/、$（幂运算，右结合）
*/
#include<iostream>
#include<stack>
#include<string>

using namespace std;

// 中缀表达式转后缀表达式
string InfixToPostfix(string expression);

// 判断栈顶运算符是否优先级更高（决定是否弹出栈顶）
int HasHigherPrecedence(char operator1, char operator2);

// 判断字符是否为运算符
bool IsOperator(char C);

// 判断字符是否为操作数（字母或数字）
bool IsOperand(char C);

int main() 
{
	string expression; 
	cout << "输入中缀表达式：\n";
	getline(cin, expression);
	string postfix = InfixToPostfix(expression);
	cout << "后缀表达式结果 = " << postfix << "\n";
}

// 中缀转后缀核心实现
string InfixToPostfix(string expression)
{
	stack<char> S;          // 运算符栈
	string postfix = "";    // 存储最终后缀表达式
	for(int i = 0; i < expression.length(); i++) {

		// 跳过分隔符（空格、逗号）
		if(expression[i] == ' ' || expression[i] == ',') continue; 

		// 当前字符为运算符：处理栈顶优先级后入栈
		else if(IsOperator(expression[i])) 
		{
			while(!S.empty() && S.top() != '(' && HasHigherPrecedence(S.top(), expression[i]))
			{
				postfix += S.top();
				S.pop();
			}
			S.push(expression[i]);
		}
		// 当前字符为操作数：直接追加到后缀表达式
		else if(IsOperand(expression[i]))
		{
			postfix += expression[i];
		}

		// 左括号：直接入栈
		else if (expression[i] == '(') 
		{
			S.push(expression[i]);
		}

		// 右括号：弹出到左括号为止
		else if(expression[i] == ')') 
		{
			while(!S.empty() && S.top() != '(') {
				postfix += S.top();
				S.pop();
			}
			S.pop(); // 弹出左括号，不加入后缀表达式
		}
	}

	// 遍历结束，弹出栈中剩余所有运算符
	while(!S.empty()) {
		postfix += S.top();
		S.pop();
	}

	return postfix;
}

// 判断是否为操作数（数字、大小写字母）
bool IsOperand(char C) 
{
	if(C >= '0' && C <= '9') return true;
	if(C >= 'a' && C <= 'z') return true;
	if(C >= 'A' && C <= 'Z') return true;
	return false;
}

// 判断是否为运算符
bool IsOperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/' || C == '$')
		return true;
	return false;
}

// 判断运算符是否为右结合
int IsRightAssociative(char op)
{
	if(op == '$') return true;
	return false;
}

// 获取运算符优先级权重，数值越大优先级越高
int GetOperatorWeight(char op)
{
	int weight = -1; 
	switch(op)
	{
	case '+':
	case '-':
		weight = 1;
	case '*':
	case '/':
		weight = 2;
	case '$':
		weight = 3;
	}
	return weight;
}

// 判断 op1（栈顶）是否优先级更高，决定是否弹出栈顶
int HasHigherPrecedence(char op1, char op2)
{
	int op1Weight = GetOperatorWeight(op1);
	int op2Weight = GetOperatorWeight(op2);

	// 优先级相等时，左结合返回true（弹出），右结合返回false（不弹出）
	if(op1Weight == op2Weight)
	{
		if(IsRightAssociative(op1)) return false;
		else return true;
	}
	return op1Weight > op2Weight ? true : false;
}
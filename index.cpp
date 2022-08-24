#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>

using namespace std;

#define MAX 200
template<class T>                   // we used template class to make it easier to use any data type for the stack
class Stack {
	int top;           
	T arr[MAX];
public:
	Stack() {
		top = -1;
	}
	void push(T val) {                       ///push function is used yo push elments to stack
		if (isFull()) {
			cout << "stack is overFlow\n";
			return;
		}
		arr[++top] = val;
	}
	T pop() {
		if (isEmpty()) {
			cout << "stack is under flow\n";
			system("pause");                     ///pop function is used to remove from stack it 
			exit(1);
		}
	T val = arr[top--];
		return val;
	}
	T peak() {
		if (isEmpty()) {
			cout << "stack is under flow\n";
	 		system("pause");                    /// peak funcrion is used to retuen the top elment of the stack
			exit(1);
		}
		return arr[top];
	}
	bool isEmpty() {
		return top == -1;
	}
	bool isFull() {
		return top == MAX - 1;
	}
	void display() {
		cout << "display \n";
		for (int i = top; i >= 0; i--)
			cout << arr[i] << " ";
		cout << endl;
	}


};
///////////////////////////////////////////////////////
int perc(char ch) {
	if (ch == '(')
		return -1;
	if (ch == '+' || ch == '-')
		return 1;                               //mathmitcal precdence function it will return -1 to remove the pranthess
											   //we add to the postfix , and it will return 1 if the operator is + or - because + and -
											   // have same precdence and it will return 2 if the operator is /, * or % becuase  
											  //they have the same precdence and will return 3 if the operator is ^  
	if (ch == '*' || ch == '/' || ch == '%')   //     becuase it have the highr precdence the return type of it is int
		return 2;                              // becuase it always return integar number and it accepts a char which is the operator 
	if (ch == '^')
		return 3;
}
//////////////////////////////////////////////////////
bool isOperator(char ch) {
	return ch == '+' || ch == '-' ||
		ch == '*' || ch == '/' || ch == '%' ||   //isoperator function mission is to check wether the inbut is operator or not
		ch == '^' || ch == ')' || ch == '(';     // if the input is operator it will return 1 if its not it will return 0
}

//////////////////////////////////////////////////////
bool isOperand(char ch) {
	return ('0' <= ch && ch <= '9') ||            //isoperand function mission is to check wether the inbut is operand or not
		('a' <= ch && ch <= 'z') ||               // if the operand is number or letter it will return 1 otherwise it will return 0
		('A' <= ch && ch <= 'Z');
}
//////////////////////////////////////////////////////

int check_str(string express)
{

  	//this function is used to determine wether the expression contians letters or not
	//if the expression contians letters it will return 1
	//we used a built in function called isalpha to help us 
	for (int i = 0; i < express.length(); i++)
	{
		if (isalpha(express[i]))
		{
			return 1;
		}
	}
	return 0;
}
int non_vaild(string test)
{
	int len = test.length();
	                                   //function to check vaildtion of the code 
                                 	//it works by using ascii code if the operator is duplicated or if we devide on zero it will return 1
	if ((test[len - 1] >= 42 && test[len - 1] <= 47))
	{                            
		return 1;                      //first case if the user used operator at the end of the stack
	}
	else if ((test[0] >= 42 && test[0] <= 47))
	{
		return 1;                    // second case if the user used operator at the end of the stack
	}
	for (int i = 1; i < len - 1; i++)
	{
		if ((test[i] >= 42 && test[i] <= 47) && (test[i + 1] >= 42 && test[i + 1] <= 47)) {
			return 1;                           // third case if the operator is dubliucated
		}
		else if (test[i] == '/' && test[i + 1] == '0')
		{
			return 1; //fourth case if the user divide on zero
		}
		else if (test[i] == '%' && test[i + 1] == '%')
		{
			return 1; // special case for the % because its out of mathmtical opertions ascii code
		}
		else if (test[i] >= 33 && test[i ] <= 39 && test[i]!='%')
		{
			return 1;     // sixth case if the user enterd a special charchter like $ or@ but the % is not included with them
		}
		else if ((test[i]== '(' && test[i+1] != ')')&&(test[i]!='('&&test[i+1]==')'))
		{
			return 1;
		}
	}

	return 0;
}

string Removal(string str, char c);
bool valedToEvaluation(string s);
int MathOperation(int op1, int op2, char operat);
void evaluation(string s);
void main_code(string expression);
int main() {
	while (true)
	{
		
		string infix1;
		cout << "enter the expression" << endl;
		cin>>infix1;
		main_code(infix1);
		char again;

		cout << "do you want to make another operation if you want answer with y or n";
		cin >> again;
		if (again == 'N' || again == 'n')
		{


			cout << "*********thank you for using our code***********";
			return 0;
		}
		
	}
}

     

////////////////////////////////////////////////////

float MathOperation(float op1, float op2, char operat) {
	if (operat == '+') {
		return op1 + op2;
	}
	else if (operat == '-') {    ///math operations function is used to make it easier at evaluting
		return op1 - op2;        /// it is accepting two floats and the operation between them
	}                           /// it return the value of the operation
	else if (operat == '*') {
		return op1 * op2;
	}
	else if (operat == '/') {
		return op1 / op2;
	}
	else
		return 0.0;
}
////////////////////////////////////////////////////
void evaluation(string s)
{                                                // evalution function at first it use the check_str function to make 
	float result = 0.0;                         // to make sure that the expression operands are all numbers
	int result2=0;                             //next it will check if the input is operand it will add it to string*s1*
	string s1 = "";                           //if its operand it will use stof function to convert it from string to float 
	Stack<float>evaluate;                    //we use the ";" sign to make sure that the multi digits numbers are converted 
	if (check_str(s)==1) {                  //in the right way because when it ; tahts meaning this is the end of a number
		cout << "can not evaluate " << endl; // and then we push it to the stack
	}
	else {
		for (int i = 0; i < s.length(); i++)
		{
			if (isOperand(s[i])) {
				s1 += s[i];
			
			}
			else if (s[i]==';') {
				
				float n;
				if(s1!=""){ // special case becuase of the '(' operators we have to make sure that we push a non empty string the
				n = stof(s1);
				
				evaluate.push(n);
				
				s1 = "";
				}
			}
			else if (isOperator(s[i])) {
				float op2=evaluate.pop(),op1=evaluate.pop();
				
				switch (s[i]) {
				case '+': result = op2 + op1; evaluate.push(result); break;
				case '*': result =  MathOperation(op1,op2,'*'); evaluate.push(result); break;
				case '-': result =  MathOperation(op1,op2,'-'); evaluate.push(result); break;
				case '%': result2 = (int)op1 % (int)op2; evaluate.push(result2); break;
				case '^': result = pow(op1,op2); evaluate.push(result); break;
				case '/': result = MathOperation(op1,op2,'/'); evaluate.push(result); break;
				}
				
			
			}
		}
	
	}


	cout << "value is " << evaluate.peak() << endl;
}
string Removal(string str, char c)
{
	string postfix;
	for (size_t i = 0; i < str.size(); i++)
	{
		char currentChar = str[i];
		if (currentChar != c)
			postfix += currentChar;
	}
	return postfix;
}
void main_code(string expression)
{
	Stack<int> operandSt;
	Stack<char> operatorSt;
	string infix, postfix = "";
	
	infix = expression;

	string templ = infix;
	infix += ')'; // adding a ')' to the end of the expression
	operatorSt.push('(');// pushing a '(' to the stack start that make it work as the algorithm
	for (int i = 0; i < infix.length(); i++) {
		// 1 space
		if (infix[i] == ' ') {
			continue; // if the user entered a space between the operands the program will continue and ignore it
		}
		// 2 opereand
		if (isOperand(infix[i])) {

			postfix += infix[i]; // check if the input is a number or a letter save it at the postfix
								// if it is not ignore it
		}
		// 3 operator
		else if (isOperator(infix[i])) {
			if (infix[i] != '(')
				postfix += ';';


			// 1 (
			if (infix[i] == '(')    // if the operator is '(' pop from the stack untill you find a ')'
				operatorSt.push('(');
			else if (infix[i] == ')') {
				while (operatorSt.peak() != '(') {
					postfix += operatorSt.pop(); //if its ')' pop everything before it
				}
				operatorSt.pop();
			}
			// + * / %
			else {
				while (perc(infix[i]) <= perc(operatorSt.peak())) {
					postfix += operatorSt.pop();
				}
				operatorSt.push(infix[i]);
			}

		}

	}

	if (non_vaild(templ) == 1)
	{
		cout << "error, please enter a vaild expression";
	}
	else

	{
		cout << "postfix " << Removal(postfix, ';') << endl;

		if (check_str(templ) == 1)
		{
			cout << "expression can't be evaluated";

		}
		else if (non_vaild(templ) != 1)
		{
			evaluation(postfix);
		}


	}


}
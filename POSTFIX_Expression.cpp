#include<iostream>
#include<math.h>
#include<stack>
using namespace std;

float scanNum(char ch) {
int value;
value = ch;
return float(value-'0'); //return float from character
}
int isOperator(char ch) {
if(ch == '+'|| ch == '-'|| ch == '*'|| ch == '/' || ch == '^')
return 1;
return -1;
}
int isOperand(char ch) {
if(ch >= '0' && ch <= '9')
return 1;
return -1;
}
float operation(int a, int b, char op) {

if(op == '+')
return b+a;
else if(op == '-')
return b-a;
else if(op == '*')
return b*a;
else if(op == '/')
return b/a;
else if(op == '^')
return pow(b,a);
else
return -1;
}
float postfixEval(string postfix) {
int a, b;
stack<float> stk;
string::iterator it;
for(it=postfix.begin(); it!=postfix.end(); it++) {

if(isOperator(*it) != -1) {
a = stk.top();
stk.pop();
b = stk.top();
stk.pop();
stk.push(operation(a, b, *it));
}else if(isOperand(*it) > 0) {
stk.push(scanNum(*it));
}
}
return stk.top();
}
int main() {
char ch='y';
while(ch=='y'||ch=='Y'){
string post;
cout << "\nEnter the expression : ";
cin >> post;
cout << "The result is: " << postfixEval(post) << '\n';
cout << "\nDo you want to continue?(y/n) : ";
cin >> ch;
}
return 0;
}

/*
#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

int postfixEvaluation(string s)
{
	stack<int> st;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			st.push(s[i]-'0');
		}
		else
		{
			int op2=st.top();
			st.pop();
			int op1=st.top();
			st.pop();

			switch(s[i])
			{
				case'+':st.push(op1+op2);
					    break;
				case'-':st.push(op1-op2);
					    break;
				case'*':st.push(op1*op2);
					    break;
				case'/':st.push(op1/op2);
					    break;
				case'^':st.push(pow(op1,op2));
					    break;

				default: cout<<"!!please enter a valid operation!!"	<<endl;
				          break;

			}
		}
	}
	return st.top();
}
int main()
{
	string s=" ";
	cout<<"Enter postfix expression:"<<endl;
	cin>>s;
	cout<<"\nPOSTFIX EVALUATED RESULT:"<<postfixEvaluation(s);;
	return 0;
}*/

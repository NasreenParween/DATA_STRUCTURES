#include <iostream>
using namespace std;
int main()
{
int n,sum=0,temp,reverse;
cout<<"Please enter the Number :"<<endl;
cin>>n;
temp=n;
while(n>0)
{
reverse=n%10;
sum=(sum*10)+reverse;
n=n/10;
}
if(temp==sum)
cout<<"The number is Palindrome.";
else
cout<<"The number is not Palindrome.";
return 0;
}

#include<iostream>
#include <cstring>
using namespace std;
main()
{
    int in=0,out=0,p=0,len1,maxInd=0,max=0;
    char sub_str[100][100]={0};
    string str;
    cout<<"Enter your String:";
    getline(cin,str);

    //splitting Input String into sub string
    while(str[p]!='\0')
    {
        out=0;
        while(str[p]!=' '&&str[p]!='\0')
        {
            sub_str[in][out]=str[p];
            p++;
            out++;
        }
        sub_str[in][out]='\0';
        in++;
        if(str[p]!='\0')
        {
            p++;
        }
    }
    int len=in;
    max=strlen(sub_str[0]);
    //finding max length of Substring from splitting string length
        for(in=0;in<len;in++)
        {
            len1=strlen(sub_str[in]);
            if(len1>max)
            {
                max=len1;
                maxInd=in;
            }
        }
        cout<<"Longest Substring(Word) is "<<sub_str[maxInd]<<"\n";
}

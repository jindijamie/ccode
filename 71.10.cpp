// a program counting the vowels, consonants, whitespaces, numbers and others
// in a sentence end with '.'
#include<iostream>
#include<ctype.h>
using namespace std;
int main()
{
    char word,flag=' ';
    int yuanyin=0,fuyin=0,kongge=0,shuzi=0,qita=0,n=0;
    while (word!='.')
    {
          word=tolower(cin.get());
          if (word=='a'||word=='i'||word=='o'||word=='u'||word=='e')
          {
              yuanyin++;
              continue;
          }
          if (word>='a' && word<='z')
          {
              fuyin++;
              continue;
          }
          if (word==' ')
          {
              kongge++;
              continue;
          }
          if (word>='0' && word<='9')
          {
              shuzi++;continue;
          }
    }
    qita++;
    cout<<"元音:"<<yuanyin<<endl<<"辅音:"<<fuyin<<endl<<"数字:"<<shuzi<<endl<<"空格:"<<kongge<<endl<<"其他:"<<qita<<endl; 
}

           

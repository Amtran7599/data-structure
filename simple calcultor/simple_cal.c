//此代码关键的是关于输入输出的用法，需要熟练掌握scanf
//四则运算优先级相同，因此可以一边输入一遍计算，不需要考虑优先级。
#include<stdio.h>
int main()
{
    int a,b,flag=0;
    char c;
    scanf("%d",&a);
    while(1)
    {
        scanf("%c",&c);
        if(c == '=') break;
        scanf("%d",&b);
        switch(c)
        {
            case '+': a += b;break;
            case '-': a -= b;break;
            case '*': a = a*b;break;
            case '/': if(b == 0) flag =1;
                        else a = a/b;break;
            default :flag =1;
        }
        if(flag)
        {
            break;
        }
    }
    if(flag)
    {
        printf("ERROR");
    }
    else printf("%d",a);
    return 0;
}
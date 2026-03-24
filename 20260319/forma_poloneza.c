#include <stdio.h>
#include <string.h>

int main()
{
    char E[256];
    fgets(E, 256 , stdin);
    int EC = 0; // <- E counter

    char fp[256] = {""}; // <- temp storage
    int fpC = 0; // <- fp Counter
    char st[256]; // <- final storage
    int stC = 0; // <= stack Counter

    /*

    ,     prioritate 0
    * /   prioritate 1
    + -   prioritate 2


    (a+b)-(b-c) -> ab+bc--

    */

    while (E[EC] != '\0' && E[EC] != '\n')
    {
        //printf("%c " , E[EC]);
        if(E[EC] > 96 && E[EC] < 123)
        {
            fp[fpC++] = E[EC++];
            continue;
        }
        if (strchr(",*/+-" , E[EC]) != NULL)
        {
            //printf("\n operator : %c" , E[EC]);
            st[stC++] = E[EC++];
            continue;
        }
        if (E[EC] == ')')
        {
            while (stC > 0 && st[stC - 1] != '(')
            {
                fp[fpC++] = st[--stC];
            }
            stC--; // remove '('
            EC++;
            continue;
        }
        if(E[EC] == '(')
        {
            st[stC++] = E[EC++];
            continue;
        }
        EC++;
    }

    while (stC > 0)
    {
        fp[fpC++] = st[--stC];
    }

    fp[fpC] = '\0';
    printf("%s" , fp);
    return 0;
}
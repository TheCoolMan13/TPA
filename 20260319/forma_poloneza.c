#include <stdio.h>
#include <string.h>

int prioritate(char op)
{
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

int main()
{
    char E[256];
    fgets(E, 256, stdin);
    int EC = 0; // <- E counter

    char fp[256] = {""}; // <- temp storage
    int fpC = 0;         // <- fp Counter
    char st[256];        // <- final storage
    int stC = 0;         // <= stack Counter

    /*

    ,     prioritate 0
    * /   prioritate 1
    + -   prioritate 2


    (a+b)-(b-c) -> ab+bc--


    Intrebare -> se asuma ca toti operanzii sunt in ordine alfabetica??
    -> asumam ca da, daca nu se poate schimba codul


    INPUT
    (a*(b+c))
    2
    3
    1

    OUTPUT
    8
    */

    int v[27] = {0};
    int vC = 0;
    while (scanf("%d", &v[vC]) == 1)
    {
        vC++;
    }
    // printf("VC EST : %d \n", vC);
    //  for (int i = 0; i < vC; i++)
    //  {
    //      printf("%d ", v[i]);
    //  }

    while (E[EC] != '\0' && E[EC] != '\n')
    {
        // printf("%c " , E[EC]);
        if (E[EC] > 96 && E[EC] < 123)
        {
            fp[fpC++] = E[EC++];
            continue;
        }
        if (strchr(",*/+-", E[EC]) != NULL)
        {
            // printf("\n operator : %c" , E[EC]);
            while (stC > 0 && prioritate(st[stC - 1]) >= prioritate(E[EC]))
            {
                fp[fpC++] = st[--stC];
            }
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
        if (E[EC] == '(')
        {
            st[stC++] = E[EC++];
            continue;
        }
        EC++;
    }

    // Dump la stiva
    while (stC > 0)
    {
        fp[fpC++] = st[--stC];
    }

    fp[fpC] = '\0';
    // printf("%s", fp);

    int valSt[256]; // <- St pt val
    int valStC = 0; // <- Ct pt st de val

    for (int i = 0; fp[i] != '\0'; i++)
    {
        char curent = fp[i];

        if (curent >= 'a' && curent <= 'z')
        {

            valSt[valStC++] = v[curent - 'a'];
        }
        else if (strchr("+ - * /", curent) != NULL && curent != ' ')
        {
            int val_dreapta = valSt[--valStC];
            int val_stanga = valSt[--valStC];
            int rezultat = 0;

            switch (curent)
            {
            case '+':
                rezultat = val_stanga + val_dreapta;
                break;
            case '-':
                rezultat = val_stanga - val_dreapta;
                break;
            case '*':
                rezultat = val_stanga * val_dreapta;
                break;
            case '/':
                if (val_dreapta != 0)
                {
                    rezultat = val_stanga / val_dreapta;
                }
                else
                {
                    printf("impartire la zero");
                    return 1;
                }
                break;
            }

            // push rezultat pe stiva
            valSt[valStC++] = rezultat;
        }
    }

    printf("\n%d\n", valSt[0]);

    // fp[fpC] = '\0';
    // printf("%s", fp);
    return 0;
}
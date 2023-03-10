// 210229017 Rumeysa YASAR
#include <stdio.h>
#include <time.h>

typedef struct veri
{
    int k, v;
} v;
v a[100];

int division(int x)
{
    return x % 100;
}

int linear_probing(v data)
{
    for (int i = data.k; i < 100; i++)
    {
        if (a[i].k == -1)
        {
            a[i].v = data.v;
            a[i].k = i;
            break;
        }
        if (i == 99)//donus
        {
            i = 0;
        }
    }
    return 0;
}

int quadratic_probing(v data)
{
    int l = 0;
    for (int i = 0; i < 100; i++)
    {
        int n;
        n = division(data.k + (i * i));
        if (a[n].k == -1)
        {
            a[n].v = data.v;
            a[n].k = n;
            break;
        }
        while (l == 1)//1 kere donus yapsin 
        {
            if (i == 99)
            {
                i = 0;
            }
        }
    }
    return 0;
}

int put(v data)
{
    if (a[division(data.k)].k == -1)
    {
        a[division(data.k)] = data;
    }

    else
    {
        linear_probing(data);
    }

    // else
    // {
    //     quadratic_probing(data);
    // }

    return 0;
}

int bastir()
{
    for (int i = 0; i < 100; i++)
    {
        printf("k:%d v:%d \n", a[i].k, a[i].v);
    }
    printf("\n");
}

int main()
{
    int l;
    srand(time(NULL));
    for (int i = 0; i < 100; i++)
    {
        a[i].k = -1;
    }
    v data;
    for (int i = 0; i < 100; i++)
    {
        l = rand() + 1;
        data.k = division(l);
        data.v = l;
        put(data);
    }

    bastir();
}
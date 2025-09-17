
#include<stdlib.h>
#include<stdio.h>
#define interval 5
void vivod(int array[],int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}
void normal(int min, int max, int n, int array[], int size_massiv)
{
    int i,c;
    c = min;
    int shag = (max - min) / n;
    for (i = 0; i < size_massiv;i++)
    {
        array[i] = c;
        c += shag;
    }
}
void unnormal(int min, int max, int n, int array[], int size_massiv)
{
    int i, c;
    c = max;
    int shag = (max - min) / n;
    for (i = 0; i < size_massiv; i++)
    {
        array[i] = c;
        c -= shag;
    }
}
void random(int min, int max, int n, int array[], int size_massiv)
{
    int i, c;
    c = rand() % (max - min) + min;
    for (i = 0; i < size_massiv; i++)
    {
        array[i] = c;
        c = rand() % (max - min) + min;
    }
}
void saw(int min, int max, int n, int array[], int size_massiv)
{
    int k, shag, i;
    k = (max - min) / interval;
    shag = (max - min) / k;
    for (i = 0; i < size_massiv; i++)
    {
        array[i] = min + shag * (i%k);
    }
}
void steirs(int min, int max, int n, int array[], int size_massiv)
{
    int k,i,h;
    int c = 0;
    k = (size_massiv / interval);
    h = (max - min) / k;
    for (i = 0; i < size_massiv; i++)
    {
        if (i % interval == 0)
        {
            c++;
        }
        array[i] = min + (h * c);
    }

}
void sinus(int min, int max, int n, int array[], int size_massiv)
{
    int k,i,h,c;
    k = (size_massiv / interval);
    h = (max - min) / k;
    c = h;
    for (i = 0; i < size_massiv; i++)
    {
        c--;
        if(i % h == 0){
            c = h;
        }
        array[i] = min + (h * c);        
    }
}
void mix(int min, int max, int n, int array[], int size_massiv)
{
    int k,i,h,c,g,r;
    k = (size_massiv / interval);
    h = (max - min) / k;
    c = 0;
    g = interval;
    for (i = 0; i < size_massiv; i++)
    {
        if (i % interval == 0)
        {
            c++;
        }
        g--;
        if(i % h == 0){
            g = h;
        } 
        array[i] = min + (g * k) + (h * c);
    } 
}
int main()
{
    int a, b, n, i;
    a = -50;
    b = 50;
    n = 50;
    int massiv[50] = { 0 };
    normal(a, b, n, massiv, 50);
    printf("\nvozrostanie\n");
    vivod(massiv, 50);
    unnormal(a, b, n, massiv, 50);
    printf("\nubivanie\n");
    vivod(massiv, 50);
    random(a, b, n, massiv, 50);
    printf("\nrandom\n");
    vivod(massiv, 50);
    printf("\nsaw\n");
    saw(a, b, n, massiv, 50);
    vivod(massiv, 50);
    printf("\nsteirs\n");
    steirs(a, b, n, massiv, 50);
    vivod(massiv, 50);
    sinus(a, b, n, massiv, 50);
    printf("\nsinus\n");
    vivod(massiv, 50);
    printf("\nmix\n");
    mix(a, b, n, massiv, 50);
    vivod(massiv, 50);
    system("pause");
    return 0;
}
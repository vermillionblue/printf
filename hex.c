#include <stdlib.h>
#include <stdio.h>
int ft_numlen(unsigned long n)
{
    int i;

    i = 0;
    while(n >= 1)
    {
        n = n / 16;
        i++;
    }
    return (i);
}

char *ft_itoa(int n)
{
    char *p;
    int temp;
    int k;
    int i;
    int x;
    
    i = 0;
    k = ft_numlen(n);
    if(n < 0)
    {
        n *= -1;
        x = -1;
    }
    p = malloc(k);
    if(n == 0)
    {
        *p = '0';
        return(p);
    }
    if(p == NULL) 
        return(NULL);

    while(k > 0)
    {
 
        temp = '0' + (n % 10);
        n = n / 10;
        if(x < 0)
        {
            p[k] = temp;
            p[0] = '-';
        }
        else
        {
            p[k - 1] = temp;
        }
        k--;
        i++;
    }
    
    p[i + 1] = '\0';
    return (p);
}

char * ft_tohex(unsigned long n)
{
    int k;
    int rem;
    char * hex;

    k = ft_numlen(n);
    int s=k;
    hex = malloc(k + 1);
    if (hex == NULL)
        return(NULL);
    while(k > 0)
    {
        rem = n % 16;
        n = n / 16;
        if(rem >= 0 && rem <= 9)
        {
            hex[k - 1] = *ft_itoa(rem);
        }
        if (rem == 10)
        {
            hex[k - 1] = 'a'; 
        }
        if (rem == 11)
        {
            hex[k - 1] = 'b'; 
        }
        if (rem == 12)
        {
            hex[k - 1] = 'c'; 
        }
        if (rem == 13)
        {
            hex[k - 1] = 'd';  
        }
        if (rem == 14)
        {
            hex[k - 1] = 'e';  
        }
        if (rem == 15)
        {
            hex[k - 1] = 'f'; 
        }
        k--;
    }
    hex[s] = '\0';
    return(hex);
}

int main()
{
    printf("%s", ft_tohex(140732784740284));
}
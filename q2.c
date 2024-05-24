#include<stdio.h>
#include <stdlib.h>
#include<math.h>

int max(int num1, int num2)

{

return (num1 > num2 ) ? num1 : num2;

}

int digits(int x)

{

int count = 0;

while (x != 0)

{

x /= 10;

++count;

}

return count;

}

long int karatsuba(long int x,long int y)

{

int n,a,b,c,d,i1,i2,half;

long int ac,bd,ad_plus_bc,fin;

if(x<10 || y<10)

{

return x*y;

}

else

{

n = max(digits(x),digits(y));

half = floor(n / 2) ;

i1 = (pow(10,half));

i2 = (pow(10,(2*half)));

a = floor(x / i1);

b = (x % i1);

c = floor(y / i1);

d = (y % i1);

ac = karatsuba(a,c);

bd = karatsuba(b,d);

ad_plus_bc = karatsuba(a+b,c+d)-ac-bd;

fin = ac * i2 + (ad_plus_bc * i1) + bd;

return fin;

}

}

int main()

{

char a[100000];
char b[100000];
scanf("%s",a);
scanf("%s",b);
long int x = atoi(a);
long int y = atoi(b);
long int i;
i = karatsuba(x,y);
printf("%ld \n",i);

return 0;

}
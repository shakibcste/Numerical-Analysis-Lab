// Numerical Analysis Program to find the real root of a function using Bisection Method.
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define p 50

float function(float x)
{
    float y=(x*x*x-2*x-5);
    return y;
}


int main(){
    int i=0;
    float ya,yb,y=0,x=0,z=0,a=1,b=2;

    for(i=0;i<p;i++)
    {
         ya=function(a);
         yb=function(b);

        if(ya<0 && yb<0)
        {
            a++;
            b++;
        }
        else if(ya>0 && yb>0)
        {
            a--;
            b--;
        }

        if(ya<0 && yb>0)
        break;
    }
    printf(" SL.\t a\t    b\t       x\t  y\t");
    printf("\n");

    for(i=1;i<p;i++)
    {
        x=(a+b)/2;
        y=function(x);
        printf("%2d %10.5f %10.5f %10.5f %10.5f",i,a,b,x,y);
        printf("\n");
        {
           if((b-a)<0.001)
               break;
           if(y>0)
               b=x;
           else if(y<0)
               a=x;
           else 
              break;
        }
    }
    printf("\n\nBecause Diff. is %f less than 0.001 so, approximate root is %.5f :) :)",(b-a),x);
    getch();
}


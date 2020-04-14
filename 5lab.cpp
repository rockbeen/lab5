#include <iostream>
#include <cmath>
# include <locale.h>
# include <fstream>
using namespace std;
 
//интегрируемая функции 
double func(const double &x)
{ double y;
	
	y=(4*pow(x,0.5)*x)/(pow(x,2)+1);
	
	
return y;
}

//функция для вычисления интеграла методом средних прямоугольников 
double integr(const int &n,const double &a,const double &b)
{
double sum=0;
double step=(b-a)/n;
for(double i=a;i<b;i=i+step)
    sum+=func(i+step/2);
return sum*step;
}
//функция для вычисления интеграла методом Симпсона 
double integr2(const int &n,const double &a,const double &b)
{
double sum=0;
double step=(b-a)/(2*n);
double i=a;
sum+=(step*func(i))/3.;
i=i+step;
for(int j=1;i<b-step;i=i+step,j++)
{
	if (j%2==0)
    sum+=(2.*step*func(i))/3.;
    else
    sum+=(4.*step*func(i))/3.;
    
}
sum+=(step*func(i))/3.;
return sum;
}

 
int main()
{
setlocale(LC_CTYPE, "Russian");
ofstream fout,fout2;
fout.open("ans1.dat");
double e=0.0001,a=0, b=1;
int n=1000000;


cout<<"The integral method of rectangles: "<<2*log(2)-integr(n,a,b)<<endl;
fout <<2*log(2)-integr(n,e,b)<<" погрешность 10^-4(метод прямоугольников)";
fout.close(); 
fout2.open("ans2.dat");
cout<<"The integral method of Simpson's : "<<2*log(2)-integr2(n,a,b)<<endl;
fout2 <<2*log(2)-integr2(n,e,b)<<" погрешность 10^-4(метод Симпсона)";
fout2.close(); 
return 0;
}

#include <iostream>
#include <cmath>
# include <locale.h>
# include <fstream>
using namespace std;
 
//интегрируемая функция 
double func(const double &x)
{ double y;
	y=log(pow(x,2)+1)/pow(x,0.5);
	
	
	
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
  double integr_e(const int &n,const double &a,const double &b)
{
double sum=0;
double step=(b-a)/n;
for(double i=a;i<b;i=i+step)
    sum+=(pow(i+step/2,2)-0.0001);
return sum*step;
}
 
int main()
{
setlocale(LC_CTYPE, "Russian");
ofstream fout;
fout.open("ans1.dat");
double e=0.0001,a=0, b=1;
int n=10000;


cout<<"Integral equal: "<<integr(n,e,b)+ integr_e(n,a,e)<<endl;
fout <<integr(n,e,b)+integr_e(n,e,a)<<" погрешность 10^-4";
fout.close(); 
return 0;
}

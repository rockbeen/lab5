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

 
int main()
{
setlocale(LC_CTYPE, "Russian");
ofstream fout;
fout.open("ans1.dat");
double e=0.0001,a=0, b=1;
int n=1000000;


cout<<"Integral equal: "<<2*log(2)-integr(n,a,b)<<endl;
fout <<2*log(2)-integr(n,e,b)<<" погрешность 10^-4";
fout.close(); 
return 0;
}

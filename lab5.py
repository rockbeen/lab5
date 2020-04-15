from math import log
def work(f, a, b, n):
    h = (b-a)/n
    total = sum([f((a + (k*h))) for k in range(0, n)])
    result = h * total
    return result

def f(x):
    return (4*pow(x,0.5)*x)/(pow(x,2)+1);

print("Используем формулу левых прямоугольников")
print("Точность: 0.0001")
n = 100000
print("Ответ:", 2*log(2)-work(f, 0, 1, n), )

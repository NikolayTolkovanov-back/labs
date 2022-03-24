from datetime import datetime
import math
import matplotlib.pyplot as plt

step = 0.1                         # шаг для нахождения интервалов

x_array = []                       # массивы с координатами
y_array = []

intervals = []                     # интервалы, где есть корни
start_interval = end_interval = 0

a = b = func_a = func_b = 0        # точки интервалов
x = func_x = 0                     # среднее значение a и b
eps = 0.01                        # епсилент - минимальная погрешность
iterations = 0                     # количество шагов для нахождение результата

def my_function(x):
    return 4 * (1 + pow(x, 0.5)) * math.log(x) - 1

### Заполняем массивы x и y
counter = 0.01
while counter < 11:
    x_array.append(counter)
    y_array.append(my_function(counter))
    counter += 0.01

# Находим интервалы, где есть корни
start_time = datetime.now()

for item in range(1, len(y_array)):
    # от нижней точки к верхней и от верхней точки к нижней
    if y_array[item - 1] * y_array[item] < 0:
        start_interval = x_array[item - 1]
        end_interval = x_array[item]
        intervals.append([start_interval, end_interval])

# Находим приближенные корни
for interval in intervals:
    a = interval[0]
    b = interval[1]

    a_func = my_function(a)
    b_func = my_function(b)

    if a_func * b_func < 0:
        while (b - a) > abs(eps):
            iterations += 1
            x = (a + b) / 2
            func_x = my_function(x)
            
            if func_x == 0:
                print("f(x) - корень")
                break

            else:
                if func_a * func_x > 0:
                    a = x

                else:
                    b = x

        x = (a + b) / 2
        print("x:", x, "eps:", eps, "steps:", iterations)

    # Исключения с корнями
    elif a_func * b_func == 0:
        if func_a == 0:
            print("f(A) - корень")

            if func_b == 0:
                print("f(B) - корень")
                break
            break

        else:
            if func_b == 0:
                print("f(B) - корень")
                break

    else:
        print("Координаты Y интервалов либо больше 0, либо меньше")

print("time:", datetime.now() - start_time)

plt.title('Графики функций')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.plot(x_array, y_array, label="1")
plt.legend()
plt.show()

import matplotlib.pyplot as plt
import numpy as np

with open('output.txt', 'r') as file:
    y_values = list(map(float, file.read().split()))

x_values = np.linspace(0.01, 5, 500)

if len(y_values) != len(x_values):
    print("Количество значений y в файле не соответствует количеству значений x.")
else:
    # Строим график
    plt.plot(x_values, y_values)
    plt.title('Отфильтрованный график')
    plt.xlabel('x')
    plt.ylabel('y(x)')
    plt.grid(True)
    plt.show()

import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(0.01, 5, 500)

y_clean = 2 * np.exp(1 - x) * np.sin(10 * x)

np.random.seed(0)
noise = np.random.normal(0, 0.1, y_clean.shape)  # Среднее 0, стандартное отклонение 0.1
y_noisy = y_clean + noise


plt.figure(figsize=(12, 6))

plt.subplot(1, 2, 1)
plt.plot(x, y_clean)
plt.title('График без шума')
plt.xlabel('x')
plt.ylabel('y(x)')
plt.grid(True)

plt.subplot(1, 2, 2)
plt.plot(x, y_noisy)
plt.title('График с шумом')
plt.xlabel('x')
plt.ylabel('y(x)')
plt.grid(True)

plt.tight_layout()
plt.show()

with open('clearSig.txt', 'w') as file:
    for value in y_clean:
        file.write(f"{value:.4f}\n")

with open('input.txt', 'w') as file:
    for value in y_noisy:
        file.write(f"{value:.4f}\n")


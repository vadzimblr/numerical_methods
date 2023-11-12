#pip install matplotlib
#pip install numpy
import numpy as np
import matplotlib.pyplot as plt

def read_vectors_from_file(filename):
    try:
        with open(filename, 'r') as file:
            lines = file.readlines()
            return lines
    except FileNotFoundError:
        print(f"Файл {filename} не найден.")
        return None
    except Exception as e:
        print(f"Произошла ошибка при чтении файла: {e}")
        return None

def plot_polynomial(X,Y,A):
    A = A[::-1]
    polynomial = np.poly1d(A)
    x_polynom = np.linspace(min(X),max(X),100)
    y_polynom = polynomial(x_polynom)
    plt.scatter(X, Y, label='Исходные точки') 
    plt.plot(x_polynom, y_polynom, label=f'Аппроксимация: y = {A[0]}x^2 + {A[1]}x + {A[2]}', color='red')  
    plt.xlabel('X')
    plt.ylabel('Y')
    plt.title('Полиномиальная аппроксимация')
    plt.legend()
    plt.grid(True)
    plt.show()

def main():
    filename = "laba4/Data.txt"  
    result = read_vectors_from_file(filename)
    if result is None: 
        exit(1)
    X = list(int(num) for num in result[0].split())
    Y = list(int(num) for num in result[1].split())
    A = list(float(num) for num in result[2].split())
    print("Вектор 1:", X)
    print("Вектор 2:", A)
    print("Вектор 3:", Y)
    plot_polynomial(X,Y,A)

if __name__ == '__main__':
    main()
    
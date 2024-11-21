#ifndef SIGNAL_H
#define SIGNAL_H

#include <iostream>
#include <fstream>
#include <vector>

class Signal {
public:
    // Конструктор по умолчанию
    Signal();

    // Конструктор с параметром
    Signal(const std::vector<double>& values);

    // Перегрузка оператора + для сложения сигналов
    Signal operator+(const Signal& other) const;

    // Перегрузка оператора * для умножения сигнала на действительное число
    Signal operator*(double scalar) const;

    friend Signal operator*(double scalar, const Signal& M);

    // Метод для конкатенации сигналов
    Signal concatenate(const Signal& other) const;

    void input(std::istream& is);

    // Метод для вывода сигнала
    void output(std::ostream& os) const;

    // Метод для получения значений сигнала
    std::vector<double> getValues() const;

private:
    std::vector<double> values;
};

#endif  // SIGNAL_H
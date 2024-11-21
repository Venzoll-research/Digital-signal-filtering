#include "signal.h"

// Конструктор по умолчанию
Signal::Signal() {}

// Конструктор с параметром
Signal::Signal(const std::vector<double>& values) : values(values) {}

// Перегрузка оператора + для сложения сигналов
Signal Signal::operator+(const Signal& other) const {
    size_t maxSize = std::max(values.size(), other.values.size());
    std::vector<double> result(maxSize, 0.0);

    for (size_t i = 0; i < maxSize; ++i) {
        if (i < values.size()) {
            result[i] += values[i];
        }
        if (i < other.values.size()) {
            result[i] += other.values[i];
        }
    }

    return Signal(result);
}

// Перегрузка оператора * для умножения сигнала на действительное число
Signal Signal::operator*(double scalar) const {
    std::vector<double> result(values.size());
    for (size_t i = 0; i < values.size(); ++i) {
        result[i] = values[i] * scalar;
    }
    return Signal(result);
}

Signal operator*(double scalar, const Signal& M) {
    return M * scalar;  // Вызов уже перегруженного оператора внутри класса
}

// Метод для конкатенации сигналов
Signal Signal::concatenate(const Signal& other) const {
    std::vector<double> result = values;
    result.insert(result.end(), other.values.begin(), other.values.end());
    return Signal(result);
}

// Метод для вывода значений в поток
void Signal::output(std::ostream& os) const {
    for (const auto& value : values) {
        os << value << " ";
    }
    os << std::endl;
}

// метод для ввода: signal.input(std::cin);
// или std::ifstream inputFile("data.txt");
//     signal.input(inputFile);
void Signal::input(std::istream& is) {
    values.clear();
    double value;
    while (is >> value) {
        values.push_back(value);
    }
}

// Метод для получения значений сигнала
std::vector<double> Signal::getValues() const {
    return values;
}
#ifndef FILTERBASE_H
#define FILTERBASE_H

#include <string>
#include <vector>

#include "Signal.h"

// Базовый класс для фильтров
class FilterBase {
public:
    // Конструктор
    FilterBase(const std::string& name) : name(name) {}
    // Виртуальный деструктор
    virtual ~FilterBase() = default;

    // Чисто виртуальная функция для применения фильтра к сигналу
    virtual Signal Filter(const Signal& inputSignal) = 0;
    // Чисто виртуальная функция для применения фильтра к одному значению
    virtual double operator()(double x_t) = 0;
    // Функция для получения имени фильтра
    std::string getName() const {
        return name;
    }

protected:
    std::string name;  // Имя фильтра
};

#endif  // FILTERBASE_H
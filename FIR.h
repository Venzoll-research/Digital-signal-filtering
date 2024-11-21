#ifndef FIR_H
#define FIR_H

#include <string>
#include <vector>
#include "signal.h"

class FIR {
public:
    // Конструктор
    FIR(const std::string& name, const std::vector<double>& coefficients);

    // Метод для применения фильтра к сигналу
    Signal Filter(const Signal& inputSignal) const;

    // Метод для получения имени фильтра
    std::string getName() const;

private:
    std::string name;
    std::vector<double> coefficients;
};

#endif  // FIR_H
#include "FIR.h"

// Конструктор
FIR::FIR(const std::string& name, const std::vector<double>& coefficients)
    : name(name), coefficients(coefficients) {}

// Метод для применения фильтра к сигналу
Signal FIR::Filter(const Signal& inputSignal) const {
    std::vector<double> inputValues = inputSignal.getValues();
    std::vector<double> outputValues(inputValues.size(), 0.0);
    std::vector<double> input_buffer(coefficients.size(), 0.0);

    for (size_t t = 0; t < inputValues.size(); ++t) {
        // Сдвигаем буфер влево и добавляем новое значение
        // по сути тот же сигнал
        for (size_t i = 1; i < coefficients.size(); ++i) {
            input_buffer[i - 1] = input_buffer[i];
        }
        input_buffer.back() = inputValues[t];

        // Вычисляем выходное значение фильтра
        double y_t = 0.0;
        for (size_t i = 0; i < coefficients.size(); ++i) {
            y_t += coefficients[coefficients.size() - i - 1] * input_buffer[i];
        }
        outputValues[t] = y_t;
    }

    return Signal(outputValues);
}

// Метод для получения имени фильтра
std::string FIR::getName() const {
    return name;
}
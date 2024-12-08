#include "SignalProcessor.h"

// Конструктор
SignalProcessor::SignalProcessor() {}

// Деструктор
SignalProcessor::~SignalProcessor() {
    // Удаляем все фильтры
    for (auto& pair : filters) {
        delete pair.second;
    }

    // Удаляем все сумматоры
    for (auto& pair : summators) {
        delete pair.second;
    }
}

// Метод для добавления фильтра
void SignalProcessor::addFilter(const std::string& name, FilterBase* filter) {
    filters[name] = filter;
}

// Метод для добавления сумматора
void SignalProcessor::addSummator(const std::string& name, Summator* summator) {
    summators[name] = summator;
}

// Метод для добавления связи между блоками
void SignalProcessor::addConnection(const std::string& outputName, const std::string& inputName) {
    connections[outputName].push_back(inputName);
}

// Метод для расчета выходов всех фильтров для данного входного сигнала
std::map<std::string, Signal> SignalProcessor::processSignal(const Signal& inputSignal) {
    std::map<std::string, Signal> outputs;

    // Сначала обрабатываем все фильтры
    for (const auto& pair : filters) {
        const std::string& name = pair.first;
        FilterBase* filter = pair.second;
        outputs[name] = filter->Filter(inputSignal);
    }

    // Затем обрабатываем все сумматоры
    for (const auto& pair : summators) {
        const std::string& name = pair.first;
        Summator* summator = pair.second;

        // Получаем входные значения для сумматора
        const auto& inputNames = connections[name];
        if (inputNames.size() != 2) {
            throw std::runtime_error("Summator must have exactly two inputs");
        }

        const Signal& inputSignal1 = outputs[inputNames[0]];
        const Signal& inputSignal2 = outputs[inputNames[1]];

        // Вычисляем выходное значение сумматора
        outputs[name] = (*summator)(inputSignal1, inputSignal2);
    }

    return outputs;
}

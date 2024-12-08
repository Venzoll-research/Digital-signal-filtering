#ifndef SIGNALPROCESSOR_H
#define SIGNALPROCESSOR_H

#include <map>
#include <vector>
#include <string>
#include <stdexcept>
#include "FilterBase.h"
#include "FIR.h"
#include "IIR.h"
#include "Summator.h"

// Класс для обработки сигнала
class SignalProcessor {
public:
    // Конструктор
    SignalProcessor();
    // Деструктор
    ~SignalProcessor();

    // Метод для добавления фильтра
    void addFilter(const std::string& name, FilterBase* filter);
    // Метод для добавления сумматора
    void addSummator(const std::string& name, Summator* summator);
    // Метод для добавления связи между блоками
    void addConnection(const std::string& outputName, const std::string& inputName);
    // Метод для расчета выходов всех фильтров для данного входного сигнала
    std::map<std::string, Signal> processSignal(const Signal& inputSignal);

private:
    std::map<std::string, FilterBase*> filters; // Ассоциативный массив фильтров
    std::map<std::string, Summator*> summators; // Ассоциативный массив сумматоров
    std::map<std::string, std::vector<std::string>> connections; // Контейнер связей между блоками
};

#endif // SIGNALPROCESSOR_H


//умные указатели
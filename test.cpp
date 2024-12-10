#include <iostream>

#include "SignalProcessor.h"

int main() {
    // Создаем фильтры
    std::vector<double> fir_coefficients = {0.2, 0.2, 0.2, 0.2, 0.2};
    std::vector<double> iir_b_coefficients = {0.2, 0.2, 0.2, 0.2, 0.2};
    std::vector<double> iir_a_coefficients = {1.0, -0.5};

    auto fir1 = std::make_unique<FIR>("FIR1", fir_coefficients);
    auto iir2 = std::make_unique<IIR>("IIR2", iir_b_coefficients, iir_a_coefficients);

    // Создаем сумматор
    auto summator = std::make_unique<Summator>("SUM1", 1.0, 1.0);

    // Создаем процессор сигналов
    SignalProcessor processor;

    // Добавляем фильтры и сумматор в процессор
    processor.addFilter("FIR1", std::move(fir1));
    processor.addFilter("IIR2", std::move(iir2));
    processor.addSummator("SUM1", std::move(summator));

    // Устанавливаем входные сигналы
    Signal inputSignal1({1.0, 2.0, 3.0, 4.0, 5.0});
    Signal inputSignal2({5.0, 4.0, 3.0, 2.0, 1.0});
    processor.setInputSignal("FIR1", inputSignal1);
    processor.setInputSignal("IIR2", inputSignal2);

    // Добавляем связи между блоками
    processor.addConnection("SUM1", "FIR1");
    processor.addConnection("SUM1", "IIR2");

    // Обрабатываем сигнал
    auto outputs = processor.processSignal();

    // Выводим результаты
    for (const auto& pair : outputs) {
        std::cout << pair.first << " Output: ";
        for (double value : pair.second.getValues()) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    SignalProcessor processor2;
    processor2 = processor;

    auto outputs2 = processor2.processSignal();

    for (const auto& pair : outputs2) {
        std::cout << pair.first << " Output: ";
        for (double value : pair.second.getValues()) {    
            std::cout << value << " ";            
        }
        std::cout << std::endl;            
    }



    return 0;
}

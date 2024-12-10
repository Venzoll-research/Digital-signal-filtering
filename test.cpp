// #include "FIR.h"
// #include "signal.h"
// #include "summator.h"

#include "SignalProcessor.h"

// int main() {
//  std::vector<double> values1 = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
//  std::vector<double> values3 = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};

// std::vector<double> coefficients = {0.25, 0.25, 0.25, 0.25};

// std::ifstream inputFile("input.txt");
// std::ofstream outputFile("output.txt");
// std::ifstream inputFile2("clearSig.txt");

// Signal signal1(values1);
// Signal signal3(values3);

// Signal signal2;
// signal2.input(inputFile);
// Signal clearsig;
// clearsig.input(inputFile2);
// FIR Fir_filter("FIR_average", coefficients);

// Signal sumSignal = signal1 + signal3;
// Signal scaledSignal = 2.0 * signal1;
// Signal concatenatedSignal = signal1.concatenate(signal3);

// std::cout << "Signal 1: ";
// signal1.output(std::cout);

// std::cout << "Signal 3: ";
// signal3.output(std::cout);

// std::cout << "Sum Signal: ";
// sumSignal.output(std::cout);

// std::cout << "Scaled Signal: ";
// scaledSignal.output(std::cout);

// std::cout << "Concatenated Signal: ";
// concatenatedSignal.output(std::cout);

// // Signal outSignal1 = Fir_filter.Filter(signal1);
// Signal outSignal2 = Fir_filter.Filter(signal2);

// std::cout << "Filter Name: " << Fir_filter.getName() << std::endl;
// // std::cout << "Input Signal: ";
// // signal1.output(std::cout);
// // std::cout << "Output Signal: ";
// // outSignal1.output(std::cout);

// // outSignal1.output(outputFile);

// outSignal2.output(outputFile);

// Signal comp;
// comp.compareSignals(clearsig, outSignal2);

// return 0;
//}

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

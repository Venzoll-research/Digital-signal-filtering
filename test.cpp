#include "FIR.h"
#include "signal.h"

int main() {
    std::vector<double> values1 = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    std::vector<double> coefficients = {0.45, 0.3, 0.15, 0.05};

    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    Signal signal1(values1);
    Signal signal2;
    signal2.input(inputFile);
    FIR Fir_filter("FIR_average", coefficients);

    Signal sumSignal = signal1 + signal2;
    Signal scaledSignal = 2.0 * signal1;
    Signal concatenatedSignal = signal1.concatenate(signal2);

    std::cout << "Signal 1: ";
    signal1.output(std::cout);

    std::cout << "Signal 2: ";
    signal2.output(std::cout);

    std::cout << "Sum Signal: ";
    sumSignal.output(std::cout);

    std::cout << "Scaled Signal: ";
    scaledSignal.output(std::cout);

    std::cout << "Concatenated Signal: ";
    concatenatedSignal.output(std::cout);

    Signal outSignal1 = Fir_filter.Filter(signal1);
    Signal outSignal2 = Fir_filter.Filter(signal2);

    std::cout << "Filter Name: " << Fir_filter.getName() << std::endl;
    std::cout << "Input Signal: ";
    signal1.output(std::cout);
    std::cout << "Output Signal: ";
    outSignal1.output(std::cout);

    outSignal2.output(outputFile);
    return 0;
}

#include <iostream>
#include <chrono> // Бібліотека для вимірювання часу
#include <cmath>

double regularCalc(double a, double b) {
    return a * sin(b) + b * cos(a);
}

inline double inlineCalc(double a, double b) {
    return a * sin(b) + b * cos(a);
}

int main() {
    const int ITERATIONS = 100000000;
    double result = 0.0;

    std::cout << "Starting calculations...\n\n";

    auto startRegular = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < ITERATIONS; i++) {
        result += regularCalc(1.5, 2.5);
    }

    auto endRegular = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationRegular = endRegular - startRegular;

    std::cout << "Regular function time: " << durationRegular.count() << " seconds.\n";


    result = 0.0;

    auto startInline = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < ITERATIONS; i++) {
        result += inlineCalc(1.5, 2.5);
    }

    auto endInline = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationInline = endInline - startInline;

    std::cout << "Inline function time:  " << durationInline.count() << " seconds.\n";

    return 0;
}

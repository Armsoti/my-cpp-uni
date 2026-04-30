#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <string>
#include <windows.h>

//Завдання 2: Структура даних
struct SensorReading {
    int zoneId;
    double temperature;
    double humidity;    
};


// Завдання 1: Чисті функції для агрономічних розрахунків

// Чиста функція: залежить тільки від параменнта c, не має побічних ефектів.
double celsiusToFahrenheit(double c) {
    return c * 9.0 / 5.0 + 32.0;
}

// Чиста функція: обчислює VPD за формулою без зміни зовнішнього стану.
double calculateVPD(double temp, double humidity) {
    // Формула VPD
    return 0.6108 * std::exp(17.27 * temp / (temp + 237.3)) * (1.0 - humidity / 100.0);
}

// Чиста функція: перевіряє чи температура в межах 18-26 градусів.
bool isOptimalTemperature(double temp) {
    return temp >= 18.0 && temp <= 26.0;
}

// Функція вищого порядку: приймає іншу функцію (func) як аргумент.
std::vector<double> transformReadings(
    const std::vector<double>& readings,
    const std::function<double(double)>& func
) {
    std::vector<double> result;
    result.reserve(readings.size());
    for (double val : readings) {
        result.push_back(func(val));
    }
    return result;
}

// Завдання 3: Композиція функцій  pipeline обробки даних

// Чиста функція: нормалізує значення до діапазону [0, 1]
double normalize(double x, double min, double max) {
    if (max == min) return 0.0; // Захист від ділення на нуль
    return (x - min) / (max - min);
}

// Чиста функція: застосовує поріг
double applyThreshold(double x, double threshold) {
    return x > threshold ? 1.0 : x;
}

// Функція-композитор вищого порядку: повертає нову функцію, яка є композицією двох.
std::function<double(double)> compose( //!!!
    const std::function<double(double)>& f,
    const std::function<double(double)>& g
) {
    return [f, g](double x) { return f(g(x)); };
}

// Завдання 5. Міні-DSS: автоматичні рекомендації

std::string classifyTemperature(double temp) {
    if (temp > 35.0) return "CRITICAL_HIGH";
    if (temp > 26.0) return "HIGH";
    if (temp >= 18.0) return "OPTIMAL";
    if (temp >= 16.0) return "LOW";
    return "CRITICAL_LOW";
}

std::string classifyHumidity(double humidity) {
    if (humidity < 40.0) return "TOO_DRY";
    if (humidity <= 70.0) return "OPTIMAL";
    return "TOO_WET";
}

std::string generateAlert(const std::string& tempStatus, const std::string& humidStatus) {
    if (tempStatus == "CRITICAL_HIGH" || tempStatus == "HIGH") return "Увімкнути охолодження";
    if (humidStatus == "TOO_DRY") return "Полив та зволоження";
    if (tempStatus == "OPTIMAL" && humidStatus == "OPTIMAL") return "Всі показники в нормі";
    return "Потрібна увага оператора";
}

std::string generateRecommendation(const SensorReading& r) {
    std::string tempStat = classifyTemperature(r.temperature);
    std::string humStat = classifyHumidity(r.humidity);
    return "Зона " + std::to_string(r.zoneId) + ": " + generateAlert(tempStat, humStat);
}


// MAIN - Виконання та тестування
int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Вхідні дані
    std::vector<SensorReading> readings = {
        {1, 22.5, 68.0}, // норма
        {2, 37.2, 45.0}, // критична температура!
        {3, 24.1, 35.5}, // критична вологість!
        {4, 19.8, 72.0}, // норма
        {5, 38.0, 38.0}  // обидва показники критичні!
    };

    std::cout << "Завдання 2: Фільтрація аномальних показників\n";
    std::vector<SensorReading> criticalZones;
    // Використовуємо std::copy_if для фільтрації критичних умов
    std::copy_if(readings.begin(), readings.end(), std::back_inserter(criticalZones),
        [](const SensorReading& r) {
            return r.temperature > 35.0 || r.humidity < 40.0;
        }
    );

    for (const auto& r : criticalZones) {
        std::cout << "[ALERT] Зона " << r.zoneId << ": ";
        if (r.temperature > 35.0 && r.humidity < 40.0) {
            std::cout << "Температура " << r.temperature << "C, Вологість " << r.humidity << "%\n";
        }
        else if (r.temperature > 35.0) {
            std::cout << "Температура " << r.temperature << "C (>35C)\n";
        }
        else {
            std::cout << "Вологість " << r.humidity << "% (<40%)\n";
        }
    }

    std::cout << "\nЗавдання 3: Композиція функцій\n";
    auto normalizeTemp = [](double t) { return normalize(t, 0.0, 50.0); };
    auto applyAlertThreshold = [](double t) { return applyThreshold(t, 0.7); };
    auto tempPipeline = compose(applyAlertThreshold, normalizeTemp);

    double rawTemp = 37.5;
    std::cout << "Сира температура: " << rawTemp << " -> Результат pipeline: " << tempPipeline(rawTemp) << "\n";

    std::cout << "\nЗавдання 4: Аналіз даних (статистика) \n";
    std::vector<SensorReading> stressZones;
    std::copy_if(readings.begin(), readings.end(), std::back_inserter(stressZones),
        [](const SensorReading& r) {
            return r.temperature > 28.0 || r.temperature < 16.0;
        }
    );

    if (!stressZones.empty()) {
        double avgStressTemp = std::accumulate(stressZones.begin(), stressZones.end(), 0.0,
            [](double sum, const SensorReading& r) { return sum + r.temperature; }
        ) / stressZones.size();
        std::cout << "Середня температура у зонах стресу: " << avgStressTemp << "C\n";
    }

    double avgVPD = std::accumulate(readings.begin(), readings.end(), 0.0,
        [](double sum, const SensorReading& r) { return sum + calculateVPD(r.temperature, r.humidity); }
    ) / readings.size();

    std::cout << "Середній VPD по всіх зонах: " << avgVPD << " кПа. Рекомендація: ";
    if (avgVPD < 0.4) std::cout << "Занадто волого (зменшити вологість).\n";
    else if (avgVPD <= 1.2) std::cout << "Оптимально.\n";
    else std::cout << "Занадто сухо (збільшити вологість).\n";

    std::cout << "\n Завдання 5: Міні-DSS: автоматичні рекомендації \n";
    std::vector<std::string> recs(readings.size());
    std::transform(readings.begin(), readings.end(), recs.begin(),
        [](const SensorReading& r) { return generateRecommendation(r); }
    );

    for (const auto& rec : recs) {
        std::cout << rec << "\n";
    }

    return 0;
}
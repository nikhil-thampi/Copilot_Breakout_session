#include <iostream>

double calculatePurity(int sensorValue) {
    if (sensorValue < 0 || sensorValue > 24) {
        std::cout << "Invalid sensor value. It should be between 0 and 24 Karats." << std::endl;
        return -1;
    }
    return (sensorValue / 24.0) * 100;
}

int main() {
    int sensorValue;
    std::cout << "Enter the sensor value in Karats: ";
    std::cin >> sensorValue;

    double purity = calculatePurity(sensorValue);
    if (purity != -1) {
        std::cout << "The purity of the gold is: " << purity << "%" << std::endl;
    }

    return 0;

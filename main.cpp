#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

// Функция для вычисления НОД двух чисел
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    // Чтение числа N из входного файла
    ifstream inputFile("input.txt");
    int N;
    inputFile >> N;
    inputFile.close();

    int A = 0, B = 0;
    int maxGCD = 0;

    // Перебор всех возможных пар (A, B)
    for (int i = 1; i <= N / 2; ++i) {
        int currentA = i;
        int currentB = N - i;
        int currentGCD = gcd(currentA, currentB);
        if (currentGCD > maxGCD) {
            maxGCD = currentGCD;
            A = currentA;
            B = currentB;
        }
    }

    // Запись чисел A и B в выходной файл
    ofstream outputFile("output.txt");
    outputFile << A << " " << B;
    outputFile.close();

    return 0;
}

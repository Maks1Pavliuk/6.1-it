#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

const int SIZE = 21;
const int LOWER_BOUND = 15;
const int UPPER_BOUND = 85;

// Функція для генерації випадкових чисел в діапазоні [15, 85]
void generateArray(int arr[]) {
    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = LOWER_BOUND + rand() % (UPPER_BOUND - LOWER_BOUND + 1);
    }
}

// Функція для виведення масиву
void printArray(int arr[]) {
    for (int i = 0; i < SIZE; i++) {
        std::cout << std::setw(4) << arr[i];
    }
    std::cout << std::endl;
}

// Функція для обчислення кількості і суми елементів, які відповідають критерію
void calculateAndReplace(int arr[], int& count, int& sum) {
    count = 0;
    sum = 0;
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] % 2 != 0 && i % 13 != 0) {  // Умови для критерія
            sum += arr[i];
            count++;
            arr[i] = 0;  // Заміняємо на нуль
        }
    }
}

int main() {
    int arr[SIZE];
    int count = 0, sum = 0;

    generateArray(arr);
    std::cout << "Original array:\n";
    printArray(arr);

    calculateAndReplace(arr, count, sum);

    std::cout << "\nCount: " << count << ", Sum: " << sum << std::endl;
    std::cout << "Modified array:\n";
    printArray(arr);

    return 0;
}

#include <iostream>

template<typename T>
T findMax(T arr[], int size) {
    T max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

template<typename T>
T findMin(T arr[], int size) {
    T min = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

template<typename T>
void sortArray(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template<typename T>
int binarySearch(T arr[], int size, T key) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

template<typename T>
void replaceElement(T arr[], int size, T oldValue, T newValue) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == oldValue)
            arr[i] = newValue;
    }
}

int main() {
    int intArr[] = { 4, 2, 9, 5, 1 };
    double doubleArr[] = { 3.14, 2.71, 1.618, 0.577, 1.732 };

    int intSize = sizeof(intArr) / sizeof(int);
    int doubleSize = sizeof(doubleArr) / sizeof(double);

    std::cout << "Max of intArr: " << findMax(intArr, intSize) << std::endl;
    std::cout << "Min of intArr: " << findMin(intArr, intSize) << std::endl;
    std::cout << "Max of doubleArr: " << findMax(doubleArr, doubleSize) << std::endl;
    std::cout << "Min of doubleArr: " << findMin(doubleArr, doubleSize) << std::endl;

    sortArray(intArr, intSize);
    std::cout << "Sorted intArr: ";
    for (int i = 0; i < intSize; ++i)
        std::cout << intArr[i] << " ";
    std::cout << std::endl;

    int searchKey = 5;
    int searchResult = binarySearch(intArr, intSize, searchKey);
    if (searchResult != -1)
        std::cout << "Found " << searchKey << " at index " << searchResult << " in intArr." << std::endl;
    else
        std::cout << searchKey << " not found in intArr." << std::endl;

    replaceElement(intArr, intSize, 5, 10);
    std::cout << "After replacing 5 with 10 in intArr: ";
    for (int i = 0; i < intSize; ++i)
        std::cout << intArr[i] << " ";
    std::cout << std::endl;

    return 0;
}

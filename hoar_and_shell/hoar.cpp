#include <iostream>

using namespace std;

template <typename t> //шаблонная функция (для возможности сортировать массивы с разным типом данных)
void qSort(t* arr, int index_first, int index_last) {
    int i = index_first; //запоминаем индексы первого и последнего элемента для сортировки
    int j = index_last;
    t pivot = arr[(i + j) / 2]; //ищем pivot (середина массива)
    t temp; //буферная переменная для паерестановки

    while (i <= j) { //пока не дойдём до pivot
        while (arr[i] < pivot) i++; //пока слева элемент меньше pivot переходим к следующему
        while (arr[j] > pivot) j--; //пока справа элемент больше pivot переходим к предыдущему

        if (i <= j) { //когда нашли наибольший элемент слева и наименьший справа, меняем их местами
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++; //переходим к следующим элементам
            j--;
        }
    }

    //если массив не отсиртирован, продолжаем его сортировать, но с другими границами
    if (j > index_first) qSort(arr, index_first, j);
    if (i < index_last) qSort(arr, i, index_last);
}

template <typename t> //шаблонная функция для вывода массива
void print_array(t* arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int n;
    cout << "Enter number elements in array >> "; cin >> n;
    int* array = new int [n];

    cout << "Enter array (int) >> ";
    for (int i = 0; i < n; i++)
        cin >> array[i]; 

    cout << "Array (int) without sort: ";
    print_array(array, n);

    qSort(array, 0, n-1);

    cout << "Array (int) with sort: ";
    print_array(array, n);
    delete[] array;

    cout << "==========================================\n";

    cout << "Enter number elements in array >> "; cin >> n;
    float* array2 = new float [n];

    cout << "Enter array (float) >> ";
    for (int i = 0; i < n; i++)
        cin >> array2[i]; 

    cout << "Array (float) without sort: ";
    print_array(array2, n);

    qSort(array2, 0, n-1);

    cout << "Array (float) with sort: ";
    print_array(array2, n);
    delete[] array2;

    return 0;
}
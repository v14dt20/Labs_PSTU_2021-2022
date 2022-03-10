#include <iostream>
#include <ctime>

using namespace std;

void create_matrix (int*, int, int**);//функция для создания двумерного массива
void print_matrix(int**, int);//ф-ия для вывода матрицы

int main()
{
    srand(time(NULL));

    int n = 0;
    cout << "Enter n >> "; cin >> n;
    int* arr = new int[n];

    int** matrix = new int* [n];
    for (int i = 0; i < n; i++)
        matrix[i] = new int[n];

    cout << "Enter mass >> ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    create_matrix(arr, n, matrix);
    print_matrix(matrix, n);

    delete[] arr;
    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;
    return 0;
}


//=========================определение ф-ий=========================


void create_matrix (int* arr, int n, int** matrix)//функция для создания двумерного массива
{
    int* sum = new int[n];//создаём массив, который будет хранить сумму элементов каждого столбца
        for (int i = 0; i < n; i++)
            sum[i] = 0;

    for (int i = 0; i < n; i++)//пробегаемся по каждой строке
        if (i != n - 1)//если строка не последняя, то присваиваем каждому элементу данной строки рандомное значение и добавляем его в сумму
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = rand() % 100 + 1;
                sum[j] += matrix[i][j];
            }
        else//если же строка последняя, то элемент будет равен: элемент исходного массива - элемент из массива сумм
            for (int j = 0; j < n; j++)
                matrix[n-1][j] = arr[j] - sum[j];
}

void print_matrix(int** matrix, int n)//ф-ия для вывода матрицы
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}
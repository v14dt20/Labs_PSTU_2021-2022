#include <iostream>

using namespace std;

void Shell(int A[], int n) //сортировка Шелла
{
    int d = n;
    d = d / 2;
    while (d > 0)
    {
    for (int i = 0; i < n - d; i++)
    {
        int j = i;
        while (j >= 0 && A[j] > A[j+d])
        {
            int count = A[j];
            A[j] = A[j+d];
            A[j+d] = count;
            j--;
        }
    }
    d = d / 2;
    }
    for (int i = 0; i < n; i++) 
        cout << A[i] << " "; //вывод массива
}

//главная функция
int main()
{
    int n;
    cout << "Enter size of array >> "; 
    cin >> n;
    int *A = new int[n]; //объявление динамического массива
    for (int i = 0; i < n; i++) //ввод массива 
        cin >> A[i]; 
    cout << "\nSort array: ";
    Shell(A, n);
    delete[] A; //освобождение памяти
    return 0;
}
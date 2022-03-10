#include <iostream>
#include <cmath>

using namespace std;

void init_ring(int*, int);//инициализация
void print_ring(int*, int);//печать кольца
void print_el_ring(int*, int, int);//печать элемента по индексу
void print_ring_left(int*, int, int);//печать кольца влево
void print_ring_right(int*, int, int);//печать кольца вправо
void del_max_elements(int*, int*);//удалить все максимальные элементы

int main() 
{
    int n = 0;
    cout << "Enter n >> "; cin >> n;
    int* ring = new int[n];

    init_ring(ring, n);

    int k = 0;
    cout << "Enter k >> "; cin >> k;

    print_ring_left(ring, n, k);
    del_max_elements(ring, &n);
    print_ring_right(ring, n, k);
    

    delete[] ring;
    return 0;
}


//=============================определение ф-ий=================================


void init_ring(int* ring, int n)
{
    cout << "Enter ring: ";
    for (int i = 0; i < n; i++)
        cin >> ring[i];
}

void print_ring(int* ring, int n)
{
    for (int i = 0; i < n; i++)
        cout << ring[i] << " ";
    cout << "\n";
}

void print_el_ring(int* ring, int n, int index)
{
    if (index >= 0)
        cout << ring[index % n];
    else
        cout << ring[(index + ((abs(index) / n + 1) * n)) % n];
        //индекс высчитавается так:
        //если он положительный, то просто берём остаток от размера и получаем нужный индекс
        //если он отрицательный, то идём с конца, т.е взять остаток от ПОЛОЖИТЕЛЬНОГО числа
        //чтобы получить это самое число без изменения остатка, нужно к индексу прибавить столько размеров массива, сколько их содержится в модуле индекса с избытком
}

void print_ring_left(int* ring, int n, int k)//печать кольца влево
{
    for (int i = 0; i < n; i++)
    {
        print_el_ring(ring, n, k + i);
        cout << " ";
    }
    cout << "\n";
}

void print_ring_right(int* ring, int n, int k)//печать кольца вправо
{
    for (int i = 0; i < n; i++)
    {
        print_el_ring(ring, n, k - i);
        cout << " ";
    }
    cout << "\n";
}

void del_max_elements(int* ring, int* n)
{
    int max = ring[0];
    int count_max = 0;
    for (int i = 0; i < *n; i++)//ищем макс элемент и их кол-во
        if (ring[i] > max)
            max = ring[i];
    for (int i = 0; i < *n; i++)
        if (ring[i] == max)
            count_max++;

    *n -= count_max;//уменьшаем разиер массива
    int* buf_ring = new int[*n];//создаём буф укороченный массив

    int j = 0;
    for (int i = 0; i < (*n + count_max); i++)//заполняем его всеми элементами, кроме максимальых
        if (ring[i] != max)
        {
            buf_ring[j] = ring[i];
            j++;
        }
    
    ring[*n];//уменьшаем начальный массив
    for (int i = 0; i < *n; i++)//заполняем его из буферного
        ring[i] = buf_ring[i];
    
    delete[] buf_ring;//удаляем буф массив
}
#include <iostream>
#include <cmath>

using namespace std;

void dec_to_bin(int, int*);
void bin_to_dec(int*, int*);
void sdvig(int*, int);
//========================переопределение ф-ий====================
void dec_to_bin(long, int*);
void bin_to_dec(int*, long*);
void sdvig(long*, int);


int main() 
{
    int n = 0;
    int n2 = 0;

    cout << "Enter n >> "; cin >> n;
    int *arr = new int[n];

    cout << "Enter mass 1 >> ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];


    cout << "Enter n2 >> "; cin >> n2;
    int *arr2 = new int[n2];

    cout << "Enter mass 2 >> ";
    for (int i = 0; i < n2; i++)
        cin >> arr2[i];

    cout << "======================================\n";
    sdvig(arr, n);
    sdvig(arr2, n2);

    cout << "Mass 1: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    cout << "\nMass 2: ";
    for (int i = 0; i < n2; i++)
        cout << arr2[i] << " ";
    cout << "\n";

    delete[] arr;
    delete[] arr2;
    return 0;
}


//==============================определение ф-ий===========================


void dec_to_bin(int dec, int* bin)
{
    for (int i = 15; i >= 0; i--)
    {
        if (dec != 0)
        {
            bin[i] = dec % 2;
            dec /= 2;
        }
        else
            bin[i] = 0;
    }
}

void bin_to_dec(int* bin, int* dec)
{
    int j = 15;
    *dec = 0;
    for (int i = 0; i < 16; i++)
    {
        *dec += bin[i] * pow(2, j);
        j--;
    }
}

void sdvig(int* arr, int n)
{
    int s = arr[0];
    if (s % 2 == 0)//циклический сдвиг влево
    {
        for (int i = 0; i < n; i++)
        {
            int bin[16];
            dec_to_bin(arr[i], bin);//переводим элемент массива в двоичный код

            int buf_bin[16];//создаём буферный массив для двоичного кода
            for (int i = 0; i < 16; i++)
                buf_bin[i] = bin[i];

            for (int i = 0; i < 16; i++)//делаем сдвиг влево с шагом s
                bin[i] = buf_bin[((i+s) + 16) % 16];
            
            bin_to_dec(bin, &arr[i]);//переводим элемент обратно в десятичную сс
        }
    }
    else//циклический сдвиг вправо
    {  
        for (int i = 0; i < n; i++)
        {
            int bin[16];
            dec_to_bin(arr[i], bin);//переводим элемент массива в двоичный код

            int buf_bin[16];//создаём буферный массив для двоичного кода
            for (int i = 0; i < 16; i++)
                buf_bin[i] = bin[i];

            for (int i = 0; i < 16; i++)//делаем сдвиг влево с шагом s
                bin[i] = buf_bin[((i-s) + 16) % 16];
            
            bin_to_dec(bin, &arr[i]);//переводим элемент обратно в десятичную сс
        }
    }
}

//========================переопределение ф-ий====================
void dec_to_bin(long dec, int* bin)
{
    for (int i = 15; i >= 0; i--)
    {
        if (dec != 0)
        {
            bin[i] = dec % 2;
            dec /= 2;
        }
        else
            bin[i] = 0;
    }
}

void bin_to_dec(int* bin, long* dec)
{
    int j = 15;
    *dec = 0;
    for (int i = 0; i < 16; i++)
    {
        *dec += bin[i] * pow(2, j);
        j--;
    }
}

void sdvig(long* arr, int n)
{
    int s = arr[0];
    if (s % 2 == 0)//циклический сдвиг влево
    {
        for (int i = 0; i < n; i++)
        {
            int bin[256];
            dec_to_bin(arr[i], bin);//переводим элемент массива в двоичный код

            int buf_bin[256];//создаём буферный массив для двоичного кода
            for (int i = 0; i < 256; i++)
                buf_bin[i] = bin[i];

            for (int i = 0; i < 256; i++)//делаем сдвиг влево с шагом s
                bin[i] = buf_bin[((i+s) + 256) % 256];
            
            bin_to_dec(bin, &arr[i]);//переводим элемент обратно в десятичную сс
        }
    }
    else//циклический сдвиг вправо
    {  
        for (int i = 0; i < n; i++)
        {
            int bin[256];
            dec_to_bin(arr[i], bin);//переводим элемент массива в двоичный код

            int buf_bin[256];//создаём буферный массив для двоичного кода
            for (int i = 0; i < 256; i++)
                buf_bin[i] = bin[i];

            for (int i = 0; i < 256; i++)//делаем сдвиг влево с шагом s
                bin[i] = buf_bin[((i-s) + 256) % 256];
            
            bin_to_dec(bin, &arr[i]);//переводим элемент обратно в десятичную сс
        }
    }
}
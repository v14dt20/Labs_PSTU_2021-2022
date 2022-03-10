#include <iostream>
#include <string>
#include <string.h>

using namespace std;

struct stadion
{
    char name[50];
    int year;
    int count_square;
    char sports[255];
};

void print_stadion(stadion);//выввести стадион
void get_stadion(stadion*);//получать данные о стадионе
void print_file(FILE*);//вывести файл
void init(FILE*);//инициализация файла
void add_to_file(FILE*, stadion, stadion, int num = 0);//добавить стадионы перед num, по умолчанию записываем в начало файла
void delete_stadions(FILE*, int);//удалить стадионы

int main()
{
    FILE* file;
    stadion a;
    stadion b;
    init(file);
    get_stadion(&a);
    get_stadion(&b);
    add_to_file(file, a, b, 2);
    print_file(file);
    delete_stadions(file, 2019);
    print_file(file);

    return 0;
}


//=================================определний ф-ий==========================

//вывод информации о стадионе
//принимает стадион
void print_stadion(stadion a)
{
    cout << "----------------------------------\n";
    cout << "Name: " << a.name << "\n";
    cout << "Year: " << a.year << "\n";
    cout << "Count square: " << a.count_square << "\n";
    cout << "Sports: " << a.sports << "\n";
}

//получить информациб об стадионе
//принимает ссылку на стадион
void get_stadion(stadion* a)
{
    cout << "Name >> "; gets(a->name);
    cout << "Year >> "; cin >> a->year;
    cout << "Count square >> "; cin >> a->count_square;
    while (fgetc(stdin) != '\n');//чистим буфер
    cout << "Sports >> "; gets(a->sports);
}

//вывести содержимое файла
//1 элемент - кол-во стадионов в файле
//принимает ссылку на FILE
void print_file(FILE* file)
{
    cout << "==================================\nYour file:\n\n";
    stadion a;
    if ((file = fopen("1.dat", "rb")) != NULL)//если файл открылся без ошибок, то
    {
        int count_stadions = 0;//создаём переменную под кол-во 
        fread(&count_stadions, sizeof(int), 1, file);//считываем в эту переменную 1 элемент из файла
        while (!feof(file) && count_stadions != 0)//пока не достигнут конец файла и не все стадионы прочитаны
        {
            fread(&a, sizeof(stadion), 1, file);//считываем стадион
            print_stadion(a);//выводим информацию об этом стадионе
            count_stadions--;//уменьшаем кол-во оставшихся стадионов
        }
    }
    else //иначе выводим сообщение об ошибке и выходим из ф-ии
    {
        cout << "Error!\n";
        exit(2);
    }
    fclose(file);//закрываем файл
}

//инициализация файла
//принимает ссылку на FILE
void init(FILE* file)
{
    FILE* buf;
    int count = 0;
    if ((file = fopen("1.dat", "rb")) == NULL)//если файла не существует, то создаём его
    {
        cout << "Create file...\n";
        if ((buf = fopen("1.dat", "wb")) != 0)
            fwrite(&count, sizeof(int), 1, buf);//записываем в начало 0, т.к сейчас в файле 0 элементов
        else
        {
            cout << "Error!\n";
            exit(1);
        }
        fclose(buf);
    }
    else
    {
        cout << "File exist\n"; 
    }
    fclose(file);
    
}

//добавить 2 стадиона в файл перед элементом под заданным номером
//принимает: ссылка на FILE, 1 стадион, 2 стадион, целое число - номер элемента перед которым добавить
void add_to_file(FILE* file, stadion a, stadion b, int num)
{
    int count = 0;
    if ((file = fopen("1.dat", "rb")) != NULL)//считываем кол-во фильмов
        fread(&count, sizeof(int), 1, file);
    else 
    {
        cout << "Error!\n";
        exit(1);
    }
    fclose(file);
    
    int size_buf = count + 2;//размер буферного масива на 2 больше
    stadion* arr = new stadion[size_buf];//буф массив
    if ((file = fopen("1.dat", "rb")) != NULL)
    {
        int trash = 0;
        fread(&trash, sizeof(int), 1, file);//записываем 1 элемент из файла, он нам не нужен

        if (count == 0)//если файл пустой, то записываем в массив по индексам 0 и 1
        {
            arr[0] = a;
            arr[1] = b;
        }
        else if (num == 0)//если от пользователя пришёл 0, то записываем в начало массива 2 элемента, далее копируем
        {
            arr[0] = a;
            arr[1] = b;
            for (int i = 2; i < (count + 2); i++)
                fread(arr + i, sizeof(stadion), 1, file);
        }
        else if (num <= count)//если число пользователя меньше либо равно кол-ву элементов, то считываем до этого элемента под этим номером, далее записываем в массив филмы, продолжаем заполнять массив из файла
        {
            for (int i = 0; i < num; i++)
                fread(arr + i, sizeof(stadion), 1, file);
            arr[num] = a;
            arr[num + 1] = b;
            for (int i = num + 2; i < (count + 2); i++)
                fread(arr + i, sizeof(stadion), 1, file);
        }
        else
            cout << "Error! Num > count\n";
    }
    else 
    {
        cout << "Error!\n";
        exit(2);
    }
    fclose(file);
    
    count += 2;//увеличиваем кол-во
    if ((file = fopen("1.dat", "wb")) != NULL)
    {
        fwrite(&count, sizeof(int), 1, file);//записываем кол-во стадионов

        for (int i = 0; i < count; i++)//записываем все стадионы
            fwrite(arr + i, sizeof(stadion), 1, file);
    }
    else
    {
        cout << "Error!\n";
        exit(1);
    }
    fclose(file);

    delete[] arr;//удаляем массив
}

//удалить стадионы, которые старше заданного года
//принимает ссылку на FILE, целое число - минимальный год постройки
void delete_stadions(FILE* file, int year)//удалить стадионы
{
    int count = 0;//кол-во стадионов
    int count_trash = 0;//кол-во ненужных стадионов
    stadion a;//сюда считываем стадион из файла
    if ((file = fopen("1.dat", "rb")) != NULL)
    {
        fread(&count, sizeof(int), 1, file);//считываем кол-во стадионов в файле
        for (int i = 0; i < count; i++)//считываем каждый стадион
        {
            fread(&a, sizeof(stadion), 1, file);
            if (a.year < year)//если год стадиона меньше года от пользователя, то увеличиваем счётчик мусора
                count_trash++;
        }        
    }
    else 
    {
        cout << "Error!\n";
        exit(2);
    }
    fclose(file);

    count -= count_trash;//уменьшаем размер
    stadion* arr = new stadion[count];//создаём массив
    if ((file = fopen("1.dat", "rb")) != NULL)
    {
        int trash = 0;
        fread(&trash, sizeof(int), 1, file);//считываем кол-во стадионов
        int j = 0;
        for (int i = 0; i < trash; i++)//считываем каждый стадион
        {
            fread(&a, sizeof(stadion), 1, file);
            if (a.year >= year)//если год стадиона больше либо равен году от пользователя, то записываем в массив
            {
                arr[j] = a;
                j++;
            }
        }
    }
    else
    {
        cout << "Error!\n";
        exit(2);
    }
    fclose(file);

    if ((file = fopen("1.dat", "wb")) != NULL)
    {
        fwrite(&count, sizeof(int), 1, file);//записываем новое кол-во стадионов
        for (int i = 0; i < count; i++)//записываем каждый стадион
            fwrite(arr + i, sizeof(stadion), 1, file);
    }
    else
    {
        cout << "Enter!\n";
        exit(1);
    }
    fclose(file);

    delete[] arr;//удаляем массив
}
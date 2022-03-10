#include <iostream>
#include <cmath>
#include <stdarg.h>

using namespace std;

float length(int, int, int, int);
float square_triangle(int, int, int, int, int, int);
void belong (int, int, int, ...);

int main()
{
    belong(1,0, 3, 0,2, 0,0, 2,0);//true
    belong(5,0, 3, 0,2, 0,0, 2,0);//false
    belong(0,0, 6, -1,1, 1,1, 2,0, 1,-1, -1,-1, -2,0);//true

    return 0;
}


//=========================определение ф-ий=====================


float length(int x_1, int y_1, int x_2, int y_2)
{
    return sqrt(pow((x_2 - x_1), 2) + pow((y_2 - y_1), 2));
}

float square_triangle(int x_1, int y_1, int x_2, int y_2, int x_3, int y_3)
{   
    float a = length(x_1, y_1, x_2, y_2);
    float b = length(x_1, y_1, x_3, y_3);
    float c = length(x_2, y_2, x_3, y_3);
    float p = (a + b + c) / 2;
    if (a >= b + c || b >= a + c || c >= a + b)
        return 0;
    else
        return sqrt(p * (p - a) * (p - b) * (p - c));
}

void belong (int m_x, int m_y, int n, ...)
{
    va_list param;
    va_start(param, n * 2);

    int* arr_x = new int[n];//создаём массив под координаты x
    int* arr_y = new int[n];//создайм массив под координаты y
    int iter_x = 0;
    int iter_y = 0;
    for (int i = 0; i < (n * 2); i++)//заполняем даннные в массивы, если элемент на чётной позиции, то это х, иначе у
        if (i % 2 == 0)
        {
            arr_x[iter_x] = va_arg(param, int);
            iter_x++;
        }
        else
        {
            arr_y[iter_y] = va_arg(param, int);
            iter_y++;
        }

    // площадь многоугольника:
    // разбиваем многоугольник на треугольники, их будет на 2 меньше, чем вершин
    // у каждого треугольника одна вершина общая
    // следующие 2 вершины берём по порядку

    int square = 0;
    for (int i = 1; i <= (n - 2); i++)
        square += square_triangle(arr_x[0], arr_y[0], arr_x[i], arr_y[i], arr_x[i + 1], arr_y[i + 1]);

    // чтобы проверить принадлежность точки многоугольнику также делим многоугольник на треугольники
    // только теперь общая вершина это наша точка
    // если площадь многоугольника и 2 площадь будут равны, то точка принадлежит этому многоугольнику 

    int sum_square = 0;
    for (int i = 0; i < (n - 1); i++)
        sum_square += square_triangle(m_x, m_y, arr_x[i], arr_y[i], arr_x[i + 1], arr_y[i + 1]);

    //также слежует проверить принадлежность точки сторонам многоугольника
    bool check = false;
    for (int i = 0; i < n; i++)//перебираем все стороны многоугольника
    {
        float first = 0;//длина отрезка от начала стороны до точки м
        float second = 0;//длина отрезка от точки м до конца стороны
        float sum = 0;//длина стороны
        //если сумма первых двух будет равна длине стороны, то точка принадлежит стороне
        if (i != (n - 1))//если точка не последняя
        {
            first = length(m_x, m_y, arr_x[i], arr_y[i]);
            second = length(m_x, m_y, arr_x[i + 1], arr_y[i + 1]);
            sum = length(arr_x[i], arr_y[i], arr_x[i + 1], arr_y[i + 1]);
        }
        else//если точка последняя, то сторона с координатами последней точки и нулевой
        {
            first = length(m_x, m_y, arr_x[i], arr_y[i]);
            second = length(m_x, m_y, arr_x[0], arr_y[0]);
            sum = length(arr_x[i], arr_y[i], arr_x[0], arr_y[0]);
        }

        if (int(first + second) == int(sum))//проверка
        {
            check = true;
            break;//выходим из цикла, т.к. если принадлежит хотя бы 1 стороне, то принадлежит всему многоугольнику
        }
    }

    if ((square == sum_square) || check)//если площади совпадают или точка находится на стороне
        cout << "True\n";//выводим истину
    else
        cout << "False\n";//иначе выводим ложь
    
    va_end(param);
    delete[] arr_x;
    delete[] arr_y;
}
#include <iostream>
#include "date.h"

using namespace std;

int find_day(int month, int year)//возвращает кол-во дней в каждом месяце
{
    int num = 0;
    switch (month)
    {
        case 1:
            num = 31;
            break;
        case 2:
            if (year % 4 == 0)
                num = 29;
            else
                num = 28;
            break;
        case 3:
            num = 31;
            break;
        case 4:
            num = 30;
            break;
        case 5:
            num = 31;
            break;
        case 6:
            num = 30;
            break;
        case 7:
            num = 31;
            break;
        case 8:
            num = 31;
            break;
        case 9:
            num = 30;
            break;
        case 10:
            num = 31;
            break;
        case 11:
            num = 30;
            break;
        case 12:
            num = 31;
            break;
    }
    return num;
}

//конструкторы
DATE::DATE()
{
    first = 0;
    second = 0;
    third = 0;
}
DATE::DATE(int a, int b, int c)
{
    first = a;

    if (b >= 1 && b <= 12)//если месяц от января до декабря, то записываем без изменениц
        second = b;
    else//иначе
    {
        first += b / 12;//в год добавляем целоую часть при делении на 12 от пришедшего месяца
        second = b % 12;//в месяц записываем остаток от 12 от пришедшего месяца
    }

    int num = find_day(b, first);//сохраняем кол-во дней в данном месяце
    
    if (c >= 1 && c <= num)//если пришедший день от 1 до последнего этого месяца, то записываем
        third = c;
    else//иначе
    {
        third = c % (num);//в день записываем остаток от пришедшего
        second += c / (num);//к месяцу добавляем целую часть от пришедшего дня
        first += second / 12;//в год добавляем остаток от 12 от получившегося месяца 

        second %= 12;//в месяц записываем остаток 
    }
}
DATE::DATE(const DATE& D)
{
    first = D.first;
    second = D.second;
    third = D.third;
}

//деструктор
DATE::~DATE()
{

}

void DATE::add_first()//добавить 1 год
{
    ++first;
}
void DATE::add_second()//добавить 1 месяц
{
    ++second;
    first += second / 12;
    second %= 12;

    int num = find_day(second, first);
    
    //проверяем если в получившемся месяце дней меньше чем было 
    if (third <= num)
        return;
    else
    {
        second += third / (num);
        third %= (num);

        first += second / 12;
        second %= 12;
    }
}
void DATE::add_third()//добавить 1 день
{
    ++third;
    int num = find_day(second, first);
    
    //проверяем если дней получилось больше чем в месяце
    if (third <= num)
        return;
    else 
    {
        second += third / (num);
        third %= (num);

        first += second / 12;
        second %= 12;
    }
}

DATE& operator+(DATE& D, int n)//добавить n дней
{
    D.third += n;

    int num = find_day(D.second, D.first);

    //аналогигчно как при добавлении 1 дня
    if (D.third <= num)
        return D;
    else 
    {
        D.second += D.third / (num);
        D.third %= (num);

        D.first += (D.second / 12);
        D.second %= 12;
    }

    return D; 
}

//модификаторы
void DATE::set_first(int a)
{
    first = a;
}
void DATE::set_second(int b)
{
    second = b;
    first = second / 12;
    second %= 12;

    int num = find_day(second, first);
    
    //проверяем если в получившемся месяце дней меньше чем было 
    if (third <= num)
        return;
    else
    {
        second += third / (num);
        third %= (num);

        first += second / 12;
        second %= 12;
    }
}
void DATE::set_third(int c)
{
    third = c;
    int num = find_day(second, first);
    
    //проверяем если дней получилось больше чем в месяце
    if (third <= num)
        return;
    else 
    {
        second += third / (num);
        third %= (num);

        first += second / 12;
        second %= 12;
    }
}

//селекторы
int DATE::get_first()
{
    return first;
}
int DATE::get_second()
{
    return second;
}
int DATE::get_third()
{
    return third;
}

istream& operator>>(istream& in, DATE& D)//оператор ввода
{
    cout << "Year >> "; in >> D.first;
    cout << "Month >> "; in >> D.second;
    cout << "Day >> "; in >> D.third;

    if (D.second >= 1 && D.second <= 12)//если месяц от января до декабря, то записываем без изменениц
        D.second;
    else//иначе
    {
        D.first += D.second / 12;//в год добавляем целоую часть при делении на 12 от пришедшего месяца
        D.second %= 12;//в месяц записываем остаток от 12 от пришедшего месяца
    }

    int num = find_day(D.second, D.first);//сохраняем кол-во дней в данном месяце
    
    if (D.third >= 1 && D.third <= num)//если пришедший день от 1 до последнего этого месяца, то записываем
        D.third;
    else//иначе
    {
        D.third %= (num);//в день записываем остаток от пришедшего
        D.second += D.third / (num);//к месяцу добавляем целую часть от пришедшего дня
        D.first += D.second / 12;//в год добавляем остаток от 12 от получившегося месяца 

        D.second %= 12;//в месяц записываем остаток 
    }

    return in;
}
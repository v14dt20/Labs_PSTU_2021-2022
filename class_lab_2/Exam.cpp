#include <iostream>
#include "Exam.h"

using namespace std;

//конструкторы
Exam::Exam()
{
    FIO = "";
    discipline = "";
    mark = 0;
}
Exam::Exam(string first, string second, int third)
{
    FIO = first;
    discipline = second;
    mark = third;
}
Exam::Exam(const Exam& exam)
{
    FIO = exam.FIO;
    discipline = exam.discipline;
    mark = exam.mark;
}

//дкструктор
Exam::~Exam()
{
}

//селекторы
void Exam::get_FIO()
{
    cout << FIO << "\n";
}
void Exam::get_discipline()
{
    cout << discipline << "\n";
}
void Exam::get_mark()
{
    cout << mark << "\n";
}

//модификаторы
void Exam::set_FIO(string s)
{
    FIO = s;
}
void Exam::set_discipline(string s)
{
    discipline = s;
}
void Exam::set_mark(int num)
{
    mark = num;
}

//вывод
void Exam::print()
{
    cout << "FIO: " << FIO << "\n";
    cout << "Discipline: " << discipline << "\n";
    cout << "Mark: " << mark << "\n";
}
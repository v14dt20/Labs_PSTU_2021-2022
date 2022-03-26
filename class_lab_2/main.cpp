#include <iostream>
#include "Exam.h"

using namespace std;

int main()
{
    Exam a;
    Exam b("Tkachenko Vladislav Sergeevich", "Math", 4);
    Exam c(b);

    a.set_FIO("Ivanov Petr Andreevich");
    a.set_discipline("PE");
    a.set_mark(5);
    cout << "Exam a:\n";
    a.print();

    cout << "==============================\nExam b:\n";
    b.print();

    cout << "==============================\nExam c:\n";
    c.print();

    return 0;
}
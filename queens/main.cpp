#include <iostream>

using namespace std;

int board[8][8]; // 0 - если никто не бьёт, 1 - если бьёт, -1 - стои ферзь


void setQueen(int i, int j) { //заполняем еденицами все места куда может сходить ферзь на i, j -ом месте
    for (int x = 0; x < 8; x++) {
        ++board[x][j]; //по горизонтали
        ++board[i][x]; //по вертикали
        int foo;
        foo = j - i + x; //диагональ
        if (foo >= 0 && foo < 8)
            ++board[x][foo]; //по диагонали
        foo = j + i - x; //вторая диагональ
        if (foo >= 0 && foo < 8)
            ++board[x][foo];
    }
    board[i][j] = -1; //-1 значит что там стоит ферзь
}

resetQueen(int i, int j) { //убираем все ходы ферзя на i, j - ом месте
    for (int x = 0; x < 8; x++) {
        --board[x][j]; //по горизонтали
        --board[i][x]; //по вертикали
        int foo;
        foo = j - i + x; //диагональ
        if (foo >= 0 && foo < 8)
            --board[x][foo]; //по диагонали
        foo = j + i - x; //вторая диагональ
        if (foo >= 0 && foo < 8)
            --board[x][foo];
    }
    board[i][j] = 0; //0 значит что там никто не стоит
}

bool tryQueen(int i) { //попытка поставить ферзя на i-тый столбец
    bool result = false;
    for (int j = 0; j < 8; j++) {
        if (board[i][j] == 0) {//если в данной клетке ферзя не бьют
            setQueen(i, j); //ставим ферзя
            if (i == 7) { //если это последний стобец, то возвращаем true
                result = true;
            }
            else { //иначе 
                if (!(result = tryQueen(i + 1)))//если ферзя бьют в следующем столбце
                    resetQueen(i , j);//перестонавливаем ферзя
            }
        }
        if (result)//если в итоге удалось поставить ферзя, выходим из цикла
            break;
    }
    return result;//возвращаем резултат (true - можно поставить, false - нельзя поставить)
}

int main() {
    //============================================
    //заполняем матрицу нулями
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            board[i][j] = 0;
    //============================================
    
    tryQueen(0); //расставляем ферзей

    //============================================
    //выводим доску с ферзями в консоль
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == -1)
                cout << "Q ";
            else 
                cout << "_ ";
        }
        cout << "\n";
    }
    //============================================
    return 0;
}
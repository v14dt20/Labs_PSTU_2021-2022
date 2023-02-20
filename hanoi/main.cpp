#include <iostream>

using namespace std;

void hanoi(int n, int from, int to, int buf) {
    if (n != 0) {
        hanoi(n - 1, from, buf, to);
        cout << from << " => " << to << "\n";
        hanoi(n - 1, buf, to, from);
    }
}

int main() {
    int from, to, buf, count;
    
    do {
        cout << "Enter number first post (1-3) >> ";
        cin >> from;
    } while (from < 1 || from > 3);

    do {
        cout << "Enter number second post (1-3) >> ";
        cin >> to;
    } while ((to < 1 || to > 3) || to == from);

    do {
        cout << "Enter number bufer post (1-3) >> ";
        cin >> buf;
    } while ((buf < 1 || buf > 3) || buf == from || buf == to);

    cout << "Enter number rings >> ";
    cin >> count;

    hanoi(count, from, to, buf);

    return 0;
}
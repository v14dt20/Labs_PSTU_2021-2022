#include <iostream>

using namespace std;

const int N=17;

//интерполяционный поиск
int InterpolSearch(int A[], int key) {
    int mid, left=0, right=N-1;
    while (A[left]<=key && A[right]>=key) {
        mid=left+((key-A[left])*(right-left))/(A[right]-A[left]);
        if (A[mid]<key) 
            left=mid+1;
        else if (A[mid]>key) 
            right=mid-1;
        else 
            return mid;
    }
    if (A[left]==key) 
        return left;
    else 
        return -1;
}

int main() {
    int key;
    int A[N] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59 };
    cout << "Enter element for search >> "; cin >> key;
    cout << "Array: ";
    for (int i = 0; i < N; i++) 
        cout << A[i] << " ";
    int res = InterpolSearch(A, key);
    if (res == -1) 
        cout << "\nError";
    else 
        cout << "\nIndex of element: " << res + 1;
}
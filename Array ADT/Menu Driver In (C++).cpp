#include <iostream>
using namespace std;

class Array {
private:
    int *A;
    int size;
    int length;

    void swap(int *x, int *y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

public:
    Array() {
        size = 10;
        length = 0;
        A = new int[size];
    }

    Array(int sz) {   // FIX: constructor name
        size = sz;
        length = 0;
        A = new int[size];
    }

    ~Array() {
        delete[] A;
    }

    void Display() {
        cout << "Elements are:\n";
        for(int i = 0; i < length; i++)
            cout << A[i] << " ";
        cout << endl;
    }

    void Append(int x) {
        if(length < size)
            A[length++] = x;
    }

    void Insert(int index, int x) {
        if(index >= 0 && index <= length) {
            for(int i = length; i > index; i--)
                A[i] = A[i - 1];
            A[index] = x;
            length++;   // FIX: arr->length ❌
        }
    }

    int Delete(int index) {   // FIX: added class scope
        int x = 0;
        if(index >= 0 && index < length) {
            x = A[index];
            for(int i = index; i < length - 1; i++)
                A[i] = A[i + 1];
            length--;
        }
        return x;
    }

    int LinearSearch(int key) {
        for(int i = 0; i < length; i++) {
            if(key == A[i])
                return i;
        }
        return -1;
    }

    int BinarySearch(int key) {   // FIX: added parameter
        int l = 0, h = length - 1;

        while(l <= h) {
            int mid = (l + h) / 2;

            if(key == A[mid])
                return mid;
            else if(key < A[mid])
                h = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }

    int Get(int index) {
        if(index >= 0 && index < length)
            return A[index];
        return -1;
    }

    void Set(int index, int x) {
        if(index >= 0 && index < length)
            A[index] = x;
    }

    int Max() {
        int max = A[0];
        for(int i = 1; i < length; i++)
            if(A[i] > max)
                max = A[i];
        return max;
    }

    int Min() {
        int min = A[0];
        for(int i = 1; i < length; i++)
            if(A[i] < min)
                min = A[i];
        return min;
    }

    int Sum() {   // FIX: removed arr usage
        int s = 0;
        for(int i = 0; i < length; i++)
            s += A[i];
        return s;
    }

    float Avg() {
        return (float)Sum() / length;
    }

    void Reverse() {
        for(int i = 0, j = length - 1; i < j; i++, j--)
            swap(&A[i], &A[j]);
    }

    void InsertSort(int x) {
        int i = length - 1;
        if(length == size) return;

        while(i >= 0 && A[i] > x) {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = x;
        length++;
    }
};

int main() {
    int size;
    cout << "Enter Size of Array: ";
    cin >> size;

    Array arr1(size);

    int ch, x, index;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Sum\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch(ch) {
            case 1:
                cout << "Enter element and index: ";
                cin >> x >> index;
                arr1.Insert(index, x);
                break;

            case 2:
                cout << "Enter index: ";
                cin >> index;
                cout << "Deleted element: " << arr1.Delete(index) << endl;
                break;

            case 3:
                cout << "Enter element to search: ";
                cin >> x;
                cout << "Index: " << arr1.LinearSearch(x) << endl;
                break;

            case 4:
                cout << "Sum: " << arr1.Sum() << endl;
                break;

            case 5:
                arr1.Display();
                break;
        }

    } while(ch != 6);

    return 0;
}
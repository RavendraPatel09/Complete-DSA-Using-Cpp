#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 50, 20, 40, 30};
    int max = arr[0];

    for(int i = 1; i < 5; i++) {
        if(arr[i] > max)
            max = arr[i];
    }

    cout << max;

    return 0;
}
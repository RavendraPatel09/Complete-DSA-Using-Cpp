#include <iostream>
using namespace std;
int main() {
    int arr[5] = {10, 50, 20, 40, 30};
    int min = arr[0];
    for(int i = 1; i < 5; i++) {
        if(arr[i] < min)
            min = arr[i];
    }
    cout << min;
    return 0;
}
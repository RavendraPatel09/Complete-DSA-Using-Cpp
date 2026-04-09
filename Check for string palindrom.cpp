#include <iostream>
using namespace std;
int main() {
  char arr[] = "madam";
    int i = 0;
    int j = sizeof(arr) / sizeof(arr[0]) - 2; // Subtract 2 to exclude the null terminator
    bool isPalindrome = true;
    while (i < j) {
        if (arr[i] != arr[j]) {
            isPalindrome = false;
            break;
        }
        i++;
        j--;
    }
    if (isPalindrome)
        cout << "Palindrome";
    else
        cout << "Not a Palindrome";

    return 0;
}
#include <iostream>
#include <queue>
using namespace std;

int main() {

    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.front() << endl;
    cout << "Rear: " << q.back() << endl;

    q.pop();

    cout << "After deletion\n";

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
#include <iostream>
#include "Queue.h"
using namespace  std;
void choices(){
    cout << "Choose an option:" << endl;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Top" << endl;
    cout << "4. Quit" << endl;
}
int main() {
    Queue<int> q;
    int choice,data;
    while(true){
        choices();
        cin>>choice;
        switch (choice) {
            case 1:
                cout << "Enter data to enqueue: ";
                cin >> data;
                q.enQueue(data);
                cout << "Enqueued " << data << endl;
                break;
            case 2:
                try {
                    data = q.top();
                    q.deQueue();
                    cout << "Dequeued " << data << endl;
                } catch (const out_of_range& e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            case 3:
                try {
                    data = q.top();
                    cout << "Top element is " << data << endl;
                } catch (const out_of_range& e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
}


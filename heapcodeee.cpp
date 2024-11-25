#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to display the heap
void displayHeap(const vector<int>& heap, const string& heapType) {
    if (heap.empty()) {
        cout << "\nThe " << heapType << " is empty!\n";
        return;
    }
    cout << "\n" << heapType << ": ";
    for (int value : heap) {
        cout << value << " ";
    }
    cout << "\n";
}

// Main function
int main() {
    vector<int> heap; // Store the heap
    int choice, power, count;

    cout << "Welcome to the mansta Challenge!\n";
    cout << "Organize magical creatures based on their power levels using heaps.\n";

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add multiple magical creatures\n";
        cout << "2. Display current heap\n";
        cout << "3. Convert to Min-Heap\n";
        cout << "4. Convert to Max-Heap\n";
        cout << "5. Exit\n" << "\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: { // Add multiple magical creatures
                cout << "How many creatures would you like to add? ";
                cin >> count;

                for (int i = 1; i <= count; ++i) {
                    cout << "Enter the power level of creature " << i << ": ";
                    cin >> power;
                    heap.push_back(power);
                    push_heap(heap.begin(), heap.end());
                }
                cout << "All creatures added successfully!\n";
                break;
            }

            case 2: // Display the current heap
                displayHeap(heap, "Current Heap");
                break;

            case 3: { // Convert to Min-Heap
                sort(heap.begin(), heap.end());
                displayHeap(heap, "Min-Heap");
                break;
            }

            case 4: { // Convert to Max-Heap
                make_heap(heap.begin(), heap.end());
                displayHeap(heap, "Max-Heap");
                break;
            }

            case 5: // Exit
                cout << "Thank you for managing the mansta!\n";
                return 0;

            default: // Invalid input
                cout << "Invalid choice! Please try again.\n";
        }
    }
}

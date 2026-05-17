#include <iostream>
using namespace std;

int main() {
    int n, a[50];

    cout << "Enter size: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << "\n--- Sorting Steps ---\n";

    for (int i = 0; i < n-1; i++) {
        int min = i;

        cout << "\nStep " << i+1 << ":\n";
        cout << "Initial array: ";
        for(int k=0;k<n;k++) cout<<a[k]<<" ";
        cout << endl;

        for (int j = i+1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }

        cout << "Minimum element found: " << a[min] << endl;

        if(min != i) {
            cout << "Swapping " << a[i] << " and " << a[min] << endl;
            swap(a[i], a[min]);
        }
        else {
            cout << "No swap needed\n";
        }

        cout << "Array after step: ";
        for (int k = 0; k < n; k++) cout << a[k] << " ";
        cout << endl;
    }
    cout << "\nFinal Sorted array: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
}
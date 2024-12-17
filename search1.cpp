#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Item {
public:
    int code;
    string name;
    float cost;
    int quantity;

    Item(int c, string n, float co, int q) : code(c), name(n), cost(co), quantity(q) {}

    // Overload the < operator for sorting by item code
    bool operator<(const Item& other) const {
        return code < other.code;
    }
};

// Function to display items
void displayItems(const vector<Item>& items) {
    for (const auto& item : items) {
        cout << "Code: " << item.code << ", Name: " << item.name << ", Cost: " << item.cost << ", Quantity: " << item.quantity << endl;
    }
}

// Function to search for an item by code
void searchItem(const vector<Item>& items, int code) {
    auto it = find_if(items.begin(), items.end(), [code](const Item& item) {
        return item.code == code;
    });

    if (it != items.end()) {
        cout << "Item found: Code: " << it->code << ", Name: " << it->name << ", Cost: " << it->cost << ", Quantity: " << it->quantity << endl;
    } else {
        cout << "Item not found." << endl;
    }
}

int main() {
    vector<Item> items;

    // Adding some items
    items.emplace_back(101, "Item1", 50.5, 10);
    items.emplace_back(102, "Item2", 30.0, 5);
    items.emplace_back(103, "Item3", 20.75, 8);

    // Sorting items by code
    sort(items.begin(), items.end());

    // Display sorted items
    cout << "Sorted Items:" << endl;
    displayItems(items);

    // Search for an item by code
    int codeToSearch;
    cout << "Enter item code to search: ";
    cin >> codeToSearch;
    searchItem(items, codeToSearch);

    return 0;
}

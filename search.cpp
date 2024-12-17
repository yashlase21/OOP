#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class PersonalRecord {
public:
    string name;
    string dob; // Date of Birth
    string phone;

    PersonalRecord(string n, string d, string p) : name(n), dob(d), phone(p) {}

    // Overload the < operator for sorting by name
    bool operator<(const PersonalRecord& other) const {
        return name < other.name;
    }
};

// Function to display records
void displayRecords(const vector<PersonalRecord>& records) {
    for (const auto& record : records) {
        cout << "Name: " << record.name << ", DOB: " << record.dob << ", Phone: " << record.phone << endl;
    }
}

// Function to search for a record by name
void searchRecord(const vector<PersonalRecord>& records, const string& name) {
    auto it = find_if(records.begin(), records.end(), [&name](const PersonalRecord& record) {
        return record.name == name;
    });

    if (it != records.end()) {
        cout << "Record found: Name: " << it->name << ", DOB: " << it->dob << ", Phone: " << it->phone << endl;
    } else {
        cout << "Record not found." << endl;
    }
}

int main() {
    vector<PersonalRecord> records;

    // Adding some records
    records.emplace_back("Alice", "1990-01-01", "1234567890");
    records.emplace_back("Bob", "1985-05-15", "0987654321");
    records.emplace_back("Charlie", "1992-12-12", "1122334455");

    // Sorting records by name
    sort(records.begin(), records.end());

    // Display sorted records
    cout << "Sorted Records:" << endl;
    displayRecords(records);

    // Search for a record by name
    string nameToSearch;
    cout << "Enter name to search: ";
    cin >> nameToSearch;
    searchRecord(records, nameToSearch);

    return 0;
}

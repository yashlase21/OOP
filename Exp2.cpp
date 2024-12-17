#include <iostream>
#include <string>
#include <stdexcept> // For exception handling

using namespace std;

class StudentDatabase;

class Student {
    string name;
    int rollNumber;
    string classDivision;
    string dateOfBirth;
    string bloodGroup;
    string contactAddress;
    string phoneNumber;
    string drivingLicenseNo;
    
    static int count;  // Static member to keep track of number of students
    
public:
    // Default constructor
    Student() : name("Unknown"), rollNumber(0), classDivision("Unknown"), dateOfBirth("Unknown"), bloodGroup("Unknown"),
                contactAddress("Unknown"), phoneNumber("Unknown"), drivingLicenseNo("Unknown") {
        count++;
    }

    // Parameterized constructor
    Student(string n, int r, string c, string dob, string bg, string addr, string phone, string dl)
        : name(n), rollNumber(r), classDivision(c), dateOfBirth(dob), bloodGroup(bg),
          contactAddress(addr), phoneNumber(phone), drivingLicenseNo(dl) {
        count++;
    }

    // Copy constructor
    Student(const Student& other) {
        name = other.name;
        rollNumber = other.rollNumber;
        classDivision = other.classDivision;
        dateOfBirth = other.dateOfBirth;
        bloodGroup = other.bloodGroup;
        contactAddress = other.contactAddress;
        phoneNumber = other.phoneNumber;
        drivingLicenseNo = other.drivingLicenseNo;
        count++;
    }

    // Destructor
    ~Student() {
        count--;
    }

    // Static member function to get the number of students
    static int getStudentCount() {
        return count;
    }

    // Inline member function to display student info
    void display() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Class & Division: " << classDivision << endl;
        cout << "Date of Birth: " << dateOfBirth << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Contact Address: " << contactAddress << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Driving License No: " << drivingLicenseNo << endl;
    }

    // Friend class that can access private members of Student class
    friend class StudentDatabase;
};

// Initialize static variable count
int Student::count = 0;

class StudentDatabase {
    Student* students;   // Pointer to dynamically allocate memory for student records
    int size;

public:
    // Constructor to allocate memory for a certain number of students
    StudentDatabase(int n) {
        size = n;
        students = new Student[size];
    }

    // Destructor to free dynamically allocated memory
    ~StudentDatabase() {
        delete[] students;
    }

    // Function to input student details
    void inputStudentInfo(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Invalid index!");  // Exception handling
        }

        string name, classDivision, dob, bg, address, phone, license;
        int roll;

        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter roll number: ";
        cin >> roll;

        cout << "Enter class & division: ";
        cin.ignore();
        getline(cin, classDivision);

        cout << "Enter date of birth: ";
        getline(cin, dob);

        cout << "Enter blood group: ";
        getline(cin, bg);

        cout << "Enter contact address: ";
        getline(cin, address);

        cout << "Enter phone number: ";
        getline(cin, phone);

        cout << "Enter driving license number: ";
        getline(cin, license);

        students[index] = Student(name, roll, classDivision, dob, bg, address, phone, license);
    }

    // Function to display student details
    void displayStudentInfo(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Invalid index!");  // Exception handling
        }
        students[index].display();
    }

    // Function to display total number of students
    void displayStudentCount() const {
        cout << "Total number of students in the database: " << Student::getStudentCount() << endl;
    }
};

int main() {
    try {
        int n;
        cout << "Enter the number of students: ";
        cin >> n;

        StudentDatabase db(n);

        // Input student information
        for (int i = 0; i < n; i++) {
            cout << "\nEnter information for student " << i + 1 << endl;
            db.inputStudentInfo(i);
        }

        // Display all students' information
        for (int i = 0; i < n; i++) {
            cout << "\nStudent " << i + 1 << " Information: " << endl;
            db.displayStudentInfo(i);
        }

        // Display the total number of students
        db.displayStudentCount();
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;  // Handling exception
    }

    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    int m1, m2, m3;
    int total;
    double percentage;
    char grade;

    void input() {
        cout << "\nEnter Roll Number: ";
        cin >> rollNo;

        cin.ignore();
        cout << "Enter Student Name: ";
        getline(cin, name);

        cout << "Enter Marks for Subject 1: ";
        cin >> m1;
        cout << "Enter Marks for Subject 2: ";
        cin >> m2;
        cout << "Enter Marks for Subject 3: ";
        cin >> m3;

        calculate();
    }

    void calculate() {
        total = m1 + m2 + m3;
        percentage = total / 3.0;

        if (percentage >= 90)
            grade = 'A';
        else if (percentage >= 80)
            grade = 'B';
        else if (percentage >= 70)
            grade = 'C';
        else if (percentage >= 60)
            grade = 'D';
        else
            grade = 'F';
    }

    void display() {
        cout << "\nRoll No: " << rollNo;
        cout << "\nName: " << name;
        cout << "\nMarks: " << m1 << ", " << m2 << ", " << m3;
        cout << "\nTotal: " << total;
        cout << "\nPercentage: " << percentage << "%";
        cout << "\nGrade: " << grade;
        cout << "\n-----------------------------";
    }
};

void addResult() {
    Student s;
    ofstream file("results.txt", ios::app);

    s.input();

    file << s.rollNo << "," << s.name << ","
         << s.m1 << "," << s.m2 << "," << s.m3 << ","
         << s.total << "," << s.percentage << ","
         << s.grade << endl;

    file.close();

    cout << "\nResult Added Successfully!\n";
}

void viewResults() {
    ifstream file("results.txt");
    string line;

    cout << "\n===== All Student Results =====\n";
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

void searchResult() {
    ifstream file("results.txt");
    string line;
    int roll;
    bool found = false;

    cout << "\nEnter Roll Number to Search: ";
    cin >> roll;

    while (getline(file, line)) {
        if (line.find(to_string(roll)) != string::npos) {
            cout << line << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Student record not found!\n";

    file.close();
}

int main() {
    int choice;

    do {
        cout << "\n====== Exam Result Management System ======\n";
        cout << "1. Add Student Result\n";
        cout << "2. View All Results\n";
        cout << "3. Search Student Result\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addResult();
            break;
        case 2:
            viewResults();
            break;
        case 3:
            searchResult();
            break;
        case 4:
            cout << "Exiting Program...\n";
            break;
        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}

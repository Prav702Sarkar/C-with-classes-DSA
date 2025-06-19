#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Student {
    string name;
    int rollNo;
    int mark;
};

class StudentMarks {
private:
    Student students[100];
    int studentCount;

public:
    StudentMarks() {
        studentCount = 0;
    }

    void addStudent(string name, int rollNo, int mark) {
        if (studentCount < 100) {
            students[studentCount].name = name;
            students[studentCount].rollNo = rollNo;
            students[studentCount].mark = mark;
            studentCount++;
            cout << "Student added successfully.\n";
        } else {
            cout << "Student limit reached.\n";
        }
    }

    void updateMark(string name, int newMark) {
        bool found = false;
        for (int i = 0; i < studentCount; i++) {
            if (students[i].name == name) {
                students[i].mark = newMark;
                cout << "Mark updated for " << name << endl;
                found = true;
                break;
            }
        }
        if (!found) cout << "Student with name not found.\n";
    }

    void updateMark(int rollNo, int newMark) {
        bool found = false;
        for (int i = 0; i < studentCount; i++) {
            if (students[i].rollNo == rollNo) {
                students[i].mark = newMark;
                cout << "Mark updated for Roll No. " << rollNo << endl;
                found = true;
                break;
            }
        }
        if (!found) cout << "Student with roll number not found.\n";
    }

    void searchMark(int mark) {
        bool found = false;
        for (int i = 0; i < studentCount; i++) {
            if (students[i].mark == mark) {
                cout << "Mark found for " << students[i].name << " (Roll: " << students[i].rollNo << ")\n";
                found = true;
            }
        }
        if (!found) cout << "No student found with mark " << mark << endl;
    }

    void findHighLow() {
        if (studentCount == 0) {
            cout << "No student data available.\n";
            return;
        }

        int maxMark = students[0].mark;
        int minMark = students[0].mark;
        for (int i = 1; i < studentCount; i++) {
            maxMark = max(maxMark, students[i].mark);
            minMark = min(minMark, students[i].mark);
        }

        cout << "Highest Mark: " << maxMark << endl;
        cout << "Lowest Mark: " << minMark << endl;
    }

    void displayMarks() {
        if (studentCount == 0) {
            cout << "No students to display.\n";
            return;
        }
        cout << "Student List:\n";
        for (int i = 0; i < studentCount; i++) {
            cout << "Name: " << students[i].name
                 << ", Roll No: " << students[i].rollNo
                 << ", Marks: " << students[i].mark << endl;
        }
    }

    void sortMarks() {
        if (studentCount == 0) {
            cout << "No students to sort.\n";
            return;
        }

        for (int i = 0; i < studentCount - 1; i++) {
            for (int j = 0; j < studentCount - i - 1; j++) {
                if (students[j].mark > students[j + 1].mark) {
                    swap(students[j], students[j + 1]);
                }
            }
        }

        cout << "Students sorted by marks:\n";
        displayMarks();
    }
};

int main() {
    system("cls");
    StudentMarks sm;
    int choice;
    string name;
    int rollNo, mark;

    do {
        cout << "\n--- Student Marks Management ---\n";
        cout << "1. Add Student\n";
        cout << "2. Update Mark by Name\n";
        cout << "3. Update Mark by Roll No\n";
        cout << "4. Search by Mark\n";
        cout << "5. Display All\n";
        cout << "6. Find Highest/Lowest\n";
        cout << "7. Sort by Marks\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter name, roll number, and mark: ";
            cin >> name >> rollNo >> mark;
            sm.addStudent(name, rollNo, mark);
            break;
        case 2:
            cout << "Enter name and new mark: ";
            cin >> name >> mark;
            sm.updateMark(name, mark);
            break;
        case 3:
            cout << "Enter roll number and new mark: ";
            cin >> rollNo >> mark;
            sm.updateMark(rollNo, mark);
            break;
        case 4:
            cout << "Enter mark to search: ";
            cin >> mark;
            sm.searchMark(mark);
            break;
        case 5:
            sm.displayMarks();
            break;
        case 6:
            sm.findHighLow();
            break;
        case 7:
            sm.sortMarks();
            break;
        case 8:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 8);

    return 0;
}

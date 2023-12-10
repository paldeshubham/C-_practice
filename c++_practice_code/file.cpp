#include<iostream>
#include<fstream>
using namespace std;

class student {
    int roll_no;
    char name[20];
    char division[5];
    char address[50];
public:
    void accept();
    void display();
    int get_roll_no() {
        return roll_no;
    }
};

void student::accept() {
    cout << "enter roll_no:";
    cin >> roll_no;

    cout << "Enter name:";
    cin.ignore();
    cin.getline(name, 20);

    cout << "enter division:";
    cin >> division;

    cout << "enter address:";
    cin >> address;
}

void student::display() {
    cout << "\n" << roll_no << "\t" << name << "\t" << division << "\t" << address;
}

void create() {
    student s;
    ofstream out("student.txt");
    int n;
    cout << "how many records do you want to insert:";
    cin >> n;

    for (int i = 0; i < n; i++) {
        s.accept();
        out.write((char*)&s, (sizeof(s)));
    }
    out.close();
}

void search() {
    int n, flag = 0;
    cout << "enter the roll no you want to search:";
    cin >> n;
    ifstream infile("student.txt");
    student s;
    while (infile.read((char*)&s, sizeof(s))) {
        if (s.get_roll_no() == n) {
            cout << "Record found:";
            s.display();
            flag = 1;
            break;
        } else {
            flag = 0;
            cout << "record is not present:";
        }
    }
    infile.close();
}

void display() {
    ifstream infile("student.txt");
    student s;
    while (infile.read((char*)&s, sizeof(s))) {
        s.display();
    }
    infile.close();
}

void add_record() {
    student s;
    ofstream outfile("student.txt", ios::app);
    s.accept();
    outfile.write((char*)&s, sizeof(s));
    outfile.close();
    cout << "record added successfully:";
}

void delete_record() {
    student s;
    ifstream infile("student.txt");
    ofstream temp("temp.txt");
    int n, flag = 0;
    cout << "Enter the roll no you want to delete:";
    cin >> n;
    while (infile.read((char*)&s, sizeof(s))) {
        if (s.get_roll_no() != n) {
            temp.write((char*)&s, sizeof(s));
        } else {
            flag = 1;
            cout << "record deleted successfully:";
        }
    }
    if (flag == 0) {
        cout << "record not found";
    }
    infile.close();
    temp.close();
    remove("student.txt");
    rename("temp.txt", "student.txt");
}

int main() {
    int choice;
    do {
        cout << "\n1.create database\n2.Display\n3.Add record\n4.search\n5.Delete record\n6.exit";
        cin >> choice;  // Fix: Read the user's choice
        switch (choice) {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            add_record();
            break;
        case 4:
            search();
            break;
        case 5:
            delete_record();
            break;
        default:
            break;
        }
    } while (choice != 6);

    return 0;
}

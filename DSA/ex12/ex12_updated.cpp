#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct Employee {
    int id;
    string name, designation;
    double salary;

    string serialize() const {
        return to_string(id) + "," + name + "," + designation + "," + to_string(salary);
    }

    static Employee deserialize(const string &line) {
        Employee emp;
        string token;
        stringstream ss(line);
        getline(ss, token, ','); emp.id = stoi(token);
        getline(ss, emp.name, ',');
        getline(ss, emp.designation, ',');
        getline(ss, token, ','); emp.salary = stod(token);
        return emp;
    }
};

void addEmployee(const string &filename) {
    Employee emp;
    cout << "ID, Name, Designation, Salary:\n";
    cin >> emp.id; cin.ignore();
    getline(cin, emp.name);
    getline(cin, emp.designation);
    cin >> emp.salary;
    ofstream(filename, ios::app) << emp.serialize() << "\n";
    cout << "Added\n";
}

void showEmployee(const string &filename) {
    int targetId;
    cout << "Show ID: "; cin >> targetId;
    string line;
    bool found = false;
    for (ifstream file(filename); getline(file, line); ) {
        Employee emp = Employee::deserialize(line);
        if (emp.id == targetId) {
            cout << emp.serialize() << "\n";
            found = true;
            break;
        }
    }
    if (!found) cout << "Not found\n";
}

void deleteEmployee(const string &filename) {
    int deleteId;
    cout << "Del ID: "; cin >> deleteId;
    string line;
    bool deleted = false;
    ifstream inFile(filename);
    ofstream tempFile("temp.txt");
    while (getline(inFile, line)) {
        Employee emp = Employee::deserialize(line);
        if (emp.id != deleteId) tempFile << line << "\n";
        else deleted = true;
    }
    inFile.close(); tempFile.close();
    remove(filename.c_str());
    rename("temp.txt", filename.c_str());
    cout << (deleted ? "Deleted\n" : "Not found\n");
}

int main() {
    string filename = "employees.txt";
    int choice;
    while (cout << "1. Add  2. Show  3. Delete  4. Exit: ", cin >> choice) {
        if (choice == 1) addEmployee(filename);
        else if (choice == 2) showEmployee(filename);
        else if (choice == 3) deleteEmployee(filename);
        else break;
    }
}

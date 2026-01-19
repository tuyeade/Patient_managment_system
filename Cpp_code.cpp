#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

// ---------------- Structure ----------------
struct User {
    char username[20];
    char password[20];
};

struct Patient {
    int id;
    char name[50];
    int age;
    char gender[10];
    char disease[50];
};

// ---------------- FUNCTION DECLARATIONS ----------------
void signUp();
bool login();

void addPatient(Patient *p);
void viewPatients();
void searchPatient();
void updatePatient();
void deletePatient();

// ---------------- MAIN Function----------------
int main() {
    int x;

    do {
        cout << "\n===== WELCOME =====\n";
        cout << "1. Sign Up\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> x;

        switch (x) {
            case 1:
                signUp();
                break;

            case 2:
                if (login()) {
                    int choice;
                    do {
                        cout << "\n===== PATIENT MANAGEMENT SYSTEM =====\n";
                        cout << "1. Add Patient\n";
                        cout << "2. View Patients\n";
                        cout << "3. Search Patient\n";
                        cout << "4. Update Patient\n";
                        cout << "5. Delete Patient\n";
                        cout << "6. Logout\n";
                        cout << "Enter choice: ";
                        cin >> choice;

                        switch (choice) {
                            case 1: {
                                Patient p;
                                addPatient(&p);   
                                break;
                            }
                            case 2:
                                viewPatients();
                                break;
                            case 3:
                                searchPatient();
                                break;
                            case 4:
                                updatePatient();
                                break;
                            case 5:
                                deletePatient();
                                break;
                            case 6:
                                cout << "Logged out successfully.\n";
                                break;
                            default:
                                cout << "Invalid choice!\n";
                        }
                    } while (choice != 6);
                }
                break;

            case 3:
                cout << "Thank you for using the system.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (x != 3);

    return 0;
}

// ---------------- SIGN UP ----------------
void signUp() {
    User u;
    ofstream file("users.dat", ios::binary | ios::app);

    cout << "\n--- SIGN UP ---\n";
    cout << "Create Username: ";
    cin >> u.username;

    cout << "Create Password: ";
    cin >> u.password;

    file.write((char*)&u, sizeof(u));
    file.close();

    cout << "Sign up successful! You can now log in.\n";
}

// ---------------- LOGIN function ----------------
bool login() {
    User u;
    char user[20], pass[20];
    bool found = false;

    ifstream file("users.dat", ios::binary);

    if (!file) {
        cout << "No users found. Please sign up first.\n";
        return false;
    }

    cout << "\n--- LOGIN ---\n";
    cout << "Username: ";
    cin >> user;

    cout << "Password: ";
    cin >> pass;

    while (file.read((char*)&u, sizeof(u))) {
        if (strcmp(u.username, user) == 0 &&
            strcmp(u.password, pass) == 0) {
            found = true;
            break;
        }
    }

    file.close();

    if (found) {
        cout << "Login successful!\n";
        return true;
    } else {
        cout << "Invalid username or password!\n";
        return false;
    }
}

// ---------------- ADD PATIENT ----------------
void addPatient(Patient *p) {
    ofstream file("patients.dat", ios::binary | ios::app);

    cout << "Enter Patient ID: ";
    cin >> p->id;
    cin.ignore();

    cout << "Enter Name: ";
    cin.getline(p->name, 50);

    cout << "Enter Age: ";
    cin >> p->age;

    cout << "Enter Gender: ";
    cin >> p->gender;
    cin.ignore();

    cout << "Enter Disease: ";
    cin.getline(p->disease, 50);

    file.write((char*)p, sizeof(*p));
    file.close();

    cout << "Patient added successfully!\n";
}

#include<iostream>
void updatePatient() {
    Patient p;
    int id;
    bool found = false;

    fstream file("patients.dat", ios::binary | ios::in | ios::out);

    cout << "Enter Patient ID to update: ";
    cin >> id;
    cin.ignore();

    while (file.read((char*)&p, sizeof(p))) {
        if (p.id == id) {

            cout << "New Name: ";
            cin.getline(p.name, 50);

            cout << "New Age: ";
            cin >> p.age;

            cout << "New Gender: ";
            cin >> p.gender;
            cin.ignore();

            cout << "New Disease: ";
            cin.getline(p.disease, 50);

            file.seekp(-sizeof(p), ios::cur);
            file.write((char*)&p, sizeof(p));

            found = true;
            break;
        }
    }

    cout << (found ? "Updated successfully!\n" : "Patient not found!\n");
    file.close();
}

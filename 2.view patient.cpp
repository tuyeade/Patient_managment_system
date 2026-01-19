// ---------------- VIEW PATIENTS ----------------
void viewPatients() {
    Patient p;
    ifstream file("patients.dat", ios::binary);

    if (!file) {
        cout << "No patient records found.\n";
        return;
    }

    cout << left
         << setw(6)  << "ID"
         << setw(20) << "Name"
         << setw(6)  << "Age"
         << setw(10) << "Gender"
         << setw(20) << "Disease" << endl;

    cout << "------------------------------------------------------------\n";

    while (file.read((char*)&p, sizeof(p))) {
        cout << left
             << setw(6)  << p.id
             << setw(20) << p.name
             << setw(6)  << p.age
             << setw(10) << p.gender
             << setw(20) << p.disease << endl;
    }

    file.close();
}

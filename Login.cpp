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


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

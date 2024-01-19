#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class InMemoryFileManager {
private:
    map<string, string> files;  // In-memory storage for files

public:
    // Create a new file with the given content
    void createFile(const string& filename, const string& content) {
        files[filename] = content;
        cout << "File '" << filename << "' created successfully.\n";
    }

    // Read the content of a file
    void readFile(const string& filename) {
        auto it = files.find(filename);
        if (it != files.end()) {
            cout << "Content of file '" << filename << "':\n" << it->second << "\n";
        } else {
            cout << "File '" << filename << "' not found.\n";
        }
    }

    // Delete a file
    void deleteFile(const string& filename) {
        auto it = files.find(filename);
        if (it != files.end()) {
            files.erase(it);
            cout << "File '" << filename << "' deleted successfully.\n";
        } else {
            cout << "File '" << filename << "' not found.\n";
        }
    }

    // List all files
    void listFiles() {
        if (files.empty()) {
            cout << "No files in the system.\n";
        } else {
            cout << "List of files:\n";
            for (const auto& file : files) {
                cout << "- " << file.first << "\n";
            }
        }
    }
};

int main() {
    InMemoryFileManager fileManager;

    while (true) {
        cout << "\n1. Create File\n2. Read File\n3. Delete File\n4. List Files\n5. Exit\n";
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string filename, content;
                cout << "Enter file name: ";
                cin >> filename;
                cout << "Enter file content: ";
                cin.ignore();  // Clear the newline character from the buffer
                getline(cin, content);
                fileManager.createFile(filename, content);
                break;
            }
            case 2: {
                string filename;
                cout << "Enter file name to read: ";
                cin >> filename;
                fileManager.readFile(filename);
                break;
            }
            case 3: {
                string filename;
                cout << "Enter file name to delete: ";
                cin >> filename;
                fileManager.deleteFile(filename);
                break;
            }
            case 4:
                fileManager.listFiles();
                break;
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
    // cout<<"dd";

    return 0;
}

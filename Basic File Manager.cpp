#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
namespace fs = std::filesystem;
// Function to create a directory
void createDirectory(const std::string& dirName) {
    if (fs::create_directory(dirName)) {
        std::cout << "Directory created: " << dirName << std::endl;
    } else {
        std::cerr << "Error creating directory: " << dirName << std::endl;
    }
}

// Function to create a file
void createFile(const std::string& fileName) {
    std::ofstream file(fileName);
    if (file.is_open()) {
        std::cout << "File created: " << fileName << std::endl;
        file.close();
    } else {
        std::cerr << "Error creating file: " << fileName << std::endl;
    }
}

// Function to move/rename a file
void moveFile(const std::string& source, const std::string& destination) {
    if (fs::exists(source)) {
        fs::rename(source, destination);
        std::cout << "File moved from " << source << " to " << destination << std::endl;
    } else {
        std::cerr << "Source file does not exist: " << source << std::endl;
    }
}

// Function to copy a file
void copyFile(const std::string& source, const std::string& destination) {
    if (fs::exists(source)) {
        fs::copy_file(source, destination);
        std::cout << "File copied from " << source << " to " << destination << std::endl;
    } else {
        std::cerr << "Source file does not exist: " << source << std::endl;
    }
}

int main() {
    std::string command;
    std::string arg1, arg2;

    while (true) {
        std::cout << "Enter a command (create_dir, create_file, move, copy, exit): ";
        std::cin >> command;

        if (command == "create_dir") {
            std::cin >> arg1;
            createDirectory(arg1);
        } else if (command == "create_file") {
            std::cin >> arg1;
            createFile(arg1);
        } else if (command == "move") {
            std::cin >> arg1 >> arg2;
            moveFile(arg1, arg2);
        } else if (command == "copy") {
            std::cin >> arg1 >> arg2;
            copyFile(arg1, arg2);
        } else if (command == "exit") {
            break;
        } else {
            std::cerr << "Invalid command. Try again." << std::endl;
        }
    }

    return 0;
}
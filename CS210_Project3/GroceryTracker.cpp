#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <limits>

class GroceryTracker {
private:
    std::map<std::string, int> itemFrequency;

    // Load all the items from the file and count how many times each one shows up
    void LoadDataFromFile(const std::string& filename) {
        std::ifstream inFile(filename);
        if (!inFile.is_open()) {
            std::cerr << "Error: Couldn't open the input file: " << filename << std::endl;
            return;
        }

        std::string item;
        while (inFile >> item) {
            ++itemFrequency[item]; // bump the count for whatever item we just read
        }

        inFile.close();
    }

    // Save everything we counted into frequency.dat so we have a backup
    void WriteBackupFile(const std::string& filename) {
        std::ofstream outFile(filename); 
        if (!outFile.is_open()) {
            std::cerr << "Error: Couldn't create backup file: " << filename << std::endl;
            return;
        }

        for (const auto& pair : itemFrequency) {
            outFile << pair.first << " " << pair.second << std::endl;
        }

        outFile.close();
    }

public:
    // When we make a GroceryTracker, load the data right away and write the backup file
    GroceryTracker(const std::string& inputFile, const std::string& backupFile) {
        LoadDataFromFile(inputFile);
        WriteBackupFile(backupFile);
    }

    // Look up how many times a specific item appears
    int GetItemFrequency(const std::string& itemName) const {
        auto it = itemFrequency.find(itemName);
        if (it != itemFrequency.end()) {
            return it->second;
        }
        return 0; // item wasn't found at all
    }

    // Print every item and how many times it showed up
    void PrintAllFrequencies() const {
        std::cout << "\nItem Frequency List:\n";
        for (const auto& pair : itemFrequency) {
            std::cout << pair.first << " " << pair.second << std::endl;
        }
    }

    // Print a simple histogram using asterisks because why not
    void PrintHistogram() const {
        std::cout << "\nItem Frequency Histogram:\n";
        for (const auto& pair : itemFrequency) {
            std::cout << pair.first << " ";
            for (int i = 0; i < pair.second; ++i) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }
    }
};

// Make sure the user actually picks a menu option that exists
int GetValidatedMenuChoice() {
    int choice;
    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Search for item frequency\n";
        std::cout << "2. Print all item frequencies\n";
        std::cout << "3. Print histogram of item frequencies\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice (1-4): ";

        if (std::cin >> choice && choice >= 1 && choice <= 4) {
            return choice;
        }

        std::cout << "Invalid input. Please enter a number between 1 and 4.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main() {
    // Create the tracker (loads file + writes backup)
    GroceryTracker tracker("CS210_Project_Three_Input_File.txt", "frequency.dat");

    bool running = true;
    while (running) {
        int choice = GetValidatedMenuChoice();

        switch (choice) {
        case 1: {
            std::string itemName;
            std::cout << "Enter the item name to search for: ";
            std::cin >> itemName;
            int freq = tracker.GetItemFrequency(itemName);
            std::cout << "Frequency of \"" << itemName << "\": " << freq << std::endl;
            break;
        }
        case 2:
            tracker.PrintAllFrequencies();
            break;
        case 3:
            tracker.PrintHistogram();
            break;
        case 4:
            std::cout << "Exiting program. Goodbye!\n";
            running = false;
            break;
        default:
            // This should never happen because we validate input, but just in case
            break;
        }
    }

    return 0;
}

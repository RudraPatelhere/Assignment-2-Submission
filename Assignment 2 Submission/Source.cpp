#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

// Define a struct to hold the student's first name and last name
struct STUDENT_DATA
{
    std::string FIRST_NAME;  // Variable to store the student's first name
    std::string LAST_NAME;   // Variable to store the student's last name
};

// Declare a vector to store all the student data
std::vector<STUDENT_DATA> students;

// Function to load student data from the given file
void LOAD_STUDENTS_DATA(const std::string& fileName)
{
    std::ifstream SOURCE_FILE(fileName);  // Open the file with the given file name
    std::string LINE;  // Variable to hold each line read from the file

    if (SOURCE_FILE.is_open())
    {
        while (getline(SOURCE_FILE, LINE))  // Read each line from the file
        {
            std::stringstream SPLIT_LINE(LINE);  // Create a stringstream to split the line into parts
            std::string FIRST_NAME;  // Variable to hold the first name
            std::string LAST_NAME;   // Variable to hold the last name

            // Parse the first name and last name
            if (getline(SPLIT_LINE, FIRST_NAME, ',') &&
                getline(SPLIT_LINE, LAST_NAME))
            {
                STUDENT_DATA student;
                student.FIRST_NAME = FIRST_NAME;  // Set the first name
                student.LAST_NAME = LAST_NAME;    // Set the last name

                students.push_back(student);  // Add the student to the vector
            }
        }
        SOURCE_FILE.close();  // Close the file after fetching all the data
    }
    else
    {
        std::cout << "Cannot open the file: " << fileName << std::endl;  // Error message if file cannot be opened
    }
}

int main()
{
    LOAD_STUDENTS_DATA("StudentData.txt");  // Load student data from the file

    // Print all the student information
    for (const auto& student : students)
    {
        std::cout << "First Name: " << student.FIRST_NAME << ", Last Name: " << student.LAST_NAME << std::endl;
    }

    return 0;  // Exit the program
}

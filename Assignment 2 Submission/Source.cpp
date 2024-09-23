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

std::vector<STUDENT_DATA> students;  // Declare a vector to store all the student data

// Function to load student data from the given file
void LOAD_STUDENTS_DATA(const std::string& fileName)
{
    std::ifstream SOURCE_FILE(fileName);  // This will open the file with the given file name
    std::string LINE;  // Variable to hold each line read from the file

    // Check if the file opened successfully
    if (SOURCE_FILE.is_open())
    {
        // Loop through each line in the file
        while (getline(SOURCE_FILE, LINE))
        {
            std::stringstream SPLIT_LINE(LINE);  // Create a stringstream to split the line into parts
            std::string FIRST_NAME;  // Variable to hold the first name
            std::string LAST_NAME;   // Variable to hold the last name

            // Parse the first name and last name
            if (getline(SPLIT_LINE, FIRST_NAME, ',') &&
                getline(SPLIT_LINE, LAST_NAME))
            {
                STUDENT_DATA student;  // Create an instance of STUDENT_DATA
                student.FIRST_NAME = FIRST_NAME;  // Set the first name of the student
                student.LAST_NAME = LAST_NAME;    // Set the last name of the student

                // Push the student object into the vector
                students.push_back(student);
            }
        }
        SOURCE_FILE.close();  // Close the file after fetching all the data
    }
    else  // Error message if something went wrong
    {
        std::cout << "Oops, something went wrong. Cannot open the file: " << fileName << std::endl;
    }
}

int main()
{
#ifdef _DEBUG
    std::cout << "Running in Debug mode" << std::endl;  // Print a message for debug mode
    // Load data
    LOAD_STUDENTS_DATA("StudentData.txt");

    // Print the student data to verify it was loaded correctly
    for (const auto& student : students)
    {
        std::cout << "First Name: " << student.FIRST_NAME << ", Last Name: " << student.LAST_NAME << std::endl;
    }
#else
    std::cout << "This is standard mode" << std::endl;  // Message for non-debug mode
#endif

    return 1;  // Return 1 to indicate successful execution
}

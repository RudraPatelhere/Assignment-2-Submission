// Rudra Patel

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

// This struct will hold the student's first name, last name, and email (email which will included in pre-release mode)
struct STUDENT_DATA

{

    std::string FIRST_NAME;  // This is used to store the student's first name


    std::string LAST_NAME;   // This is used to store the student's last name

#ifdef PRE_RELEASE

    std::string EMAIL;       // This is used to store the student's email address (only in pre-release mode)

#endif
};

// This vector will store all the student data we read from the file

std::vector<STUDENT_DATA> students;

// Function to load student data from the file provided

void LOAD_STUDENTS_DATA(const std::string& fileName)
{
    std::ifstream SOURCE_FILE(fileName);  // This opens the file with the name we pass to it

    std::string LINE;  // This will hold each line we read from the file

    // Check if the file was opened successfully

    if (SOURCE_FILE.is_open())

    {

        // Loop through each line in the file

        while (getline(SOURCE_FILE, LINE))
        {
            std::stringstream SPLIT_LINE(LINE);  // This creates a stringstream to split the line into parts

            std::string FIRST_NAME;  // This will hold the first name part of the line

            std::string LAST_NAME;   // This will hold the last name part of the line

#ifdef PRE_RELEASE

            std::string EMAIL;       // This will hold the email address part of the line (if in pre-release mode)

#endif

            // Get the first name, last name, and email (if available)

            if (getline(SPLIT_LINE, FIRST_NAME, ',') &&

                getline(SPLIT_LINE, LAST_NAME, ',')

#ifdef PRE_RELEASE

                && getline(SPLIT_LINE, EMAIL)  // This reads the email if we're in pre-release mode

#endif
                )
            {
                STUDENT_DATA student;  // Create a student object to store the current line's data

                student.FIRST_NAME = FIRST_NAME;  // Set the first name of this student

                student.LAST_NAME = LAST_NAME;    // Set the last name of this student

#ifdef PRE_RELEASE

                student.EMAIL = EMAIL;  // Set the email of this student (only if in pre-release mode)

#endif

                students.push_back(student);  // Add this student to the vector

            }

        }
        SOURCE_FILE.close();  // Close the file after we've finished reading all the data
    }

    else

    {
        std::cout << "Oops, something went wrong. Cannot open the file: " << fileName << std::endl;  // Print an error if the file can't be opened
    }

}

int main()

{

#ifdef _DEBUG

    std::cout << "Running in Debug mode" << std::endl;  // This tells us we're in Debug mode

#ifdef PRE_RELEASE

    std::cout << "Running in Pre-Release mode" << std::endl;  // This tells us we're also in Pre-Release mode

    LOAD_STUDENTS_DATA("StudentData_Emails.txt");  // Load the file with email addresses

    // Print out all the student data, including emails

    for (const auto& student : students)

    {
        std::cout << "First Name: " << student.FIRST_NAME << ", Last Name: " << student.LAST_NAME << ", Email: " << student.EMAIL << std::endl;

    }

#else

    std::cout << "Running in Standard mode" << std::endl;  // This tells us we're in Standard mode

    LOAD_STUDENTS_DATA("StudentData.txt");  // Load the file without email addresses

    // Print out all the student data, without emails

    for (const auto& student : students)

    {

        std::cout << "First Name: " << student.FIRST_NAME << ", Last Name: " << student.LAST_NAME << std::endl;

    }

#endif

#else

#ifdef PRE_RELEASE

    std::cout << "Running in Pre-Release mode" << std::endl;  // This tells us we're in Pre-Release mode

    LOAD_STUDENTS_DATA("StudentData_Emails.txt");  // Load the file with email addresses

    // Print out just the emails of all students

    for (const auto& student : students)

    {

        std::cout << "Email: " << student.EMAIL << std::endl;

    }

#else

    std::cout << "Just running in Standard mode" << std::endl;  // This tells us we're only in Standard mode

#endif

#endif

    return 0;  // Return 0 to indicate the program finished successfully
}
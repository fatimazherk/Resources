// Write a program to calculate the GPA of students of all subjects of a single
// semester . Assume all the courses have the same credit hour (let’s assume 3
// credit hours).

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class CalculateGpa{
    vector<float> grades;
    int creditHourPerCourse;
    int totalCreditHours;
    int validCourses;
public:
    CalculateGpa(vector<float> g, int creditHour):grades(g), creditHourPerCourse(creditHour){
        validCourses = 0;
        totalCreditHours = 0;
        calculateTotalCreditHours();
    }

    void calculateTotalCreditHours(){
        for(float grade: grades){
            if(grade >= 0){
                totalCreditHours = totalCreditHours + creditHourPerCourse;
                validCourses++;
            }
        }
    }

    float calculateGpa(){
        float totalPoints = 0;
        for(float grade: grades){
            if(grade >= 0){
                totalPoints += grade * creditHourPerCourse;
            }
        }
        return validCourses > 0 ? totalPoints / totalCreditHours : 0.0;
    }
};

int main(){
    vector<float> aliGrades = {3.66, 3.33, 4.0, 3.0, 2.66};
    vector<float> hibaGrades = {3.33, 3.0, 3.66, 3.0, -1};
    vector<float> asmaGrades = {4.0, 3.66, 2.66, -1, -1};
    vector<float> zainGrades = {2.66, 2.33, 4.0, -1, -1};
    vector<float> faisalGrades = {3.33, 3.66, 4.0, 3.0, 3.33};

    vector<pair<string, vector<float>>> students = {
        {"Ali", aliGrades},
        {"Hiba", hibaGrades},
        {"Asma", asmaGrades},
        {"Zain", zainGrades},
        {"Faisal", faisalGrades}
    };

    int creditHourPerCourse = 3;
    for(const auto& student : students){
        CalculateGpa gpaCalculator(student.second, creditHourPerCourse);  // Corrected
        float gpa = gpaCalculator.calculateGpa();
        cout << student.first << "'s GPA: " << gpa << endl;
    }

    return 0;
}


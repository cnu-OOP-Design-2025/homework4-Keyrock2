#include "student_manager.h"
#include "student.h"

/* StudentManager */
int StudentManager::last_student_id = 1000;

void StudentManager::addStudent(const char *name, float midterm, float final)
{
    if (num_of_students < MAX_STUDENTS)
    {
        int id = ++last_student_id;
        students[num_of_students] = Student(name, id, midterm, final);
        num_of_students++;
    }
}

void StudentManager::deleteStudent(int id)
{
    int idx = findStudentByID(id);
    if (idx != -1)
    {
        for (int i = idx; i < num_of_students - 1; ++i)
        {
            students[i] = students[i + 1];
        }
        num_of_students--;
    }
}

void StudentManager::modifyStudent(const Student &student)
{
    int idx = findStudentByID(student.getID());
    if (idx != -1)
    {
        students[idx] = student;
    }
}

int StudentManager::findStudentByID(int id) const
{
    for (int i = 0; i < num_of_students; ++i)
    {
        if (students[i].getID() == id)
        {
            return i;
        }
    }
    return -1;
}

int StudentManager::findBestStudentInMidterm() const
{
    if (num_of_students == 0)
        return -1;
    float maxScore = -1.0f;
    int bestId = -1;
    for (int i = 0; i < num_of_students; ++i)
    {
        if (students[i].getRecord().getMidterm() > maxScore)
        {
            maxScore = students[i].getRecord().getMidterm();
            bestId = students[i].getID();
        }
    }
    return bestId;
}

int StudentManager::findBestStudentInFinal() const
{
    if (num_of_students == 0)
        return -1;
    float maxScore = -1.0f;
    int bestId = -1;
    for (int i = 0; i < num_of_students; ++i)
    {
        if (students[i].getRecord().getFinal() > maxScore)
        {
            maxScore = students[i].getRecord().getFinal();
            bestId = students[i].getID();
        }
    }
    return bestId;
}

int StudentManager::findBestStudent() const
{
    if (num_of_students == 0)
        return -1;
    float maxTotal = -1.0f;
    int bestId = -1;
    for (int i = 0; i < num_of_students; ++i)
    {
        if (students[i].getRecord().getTotal() > maxTotal)
        {
            maxTotal = students[i].getRecord().getTotal();
            bestId = students[i].getID();
        }
    }
    return bestId;
}

float StudentManager::getMidtermAverage() const
{
    if (num_of_students == 0)
        return 0.0f;
    float total = 0.0f;
    for (int i = 0; i < num_of_students; ++i)
    {
        total += students[i].getRecord().getMidterm();
    }
    return total / num_of_students;
}

float StudentManager::getFinalAverage() const
{
    if (num_of_students == 0)
        return 0.0f;
    float total = 0.0f;
    for (int i = 0; i < num_of_students; ++i)
    {
        total += students[i].getRecord().getFinal();
    }
    return total / num_of_students;
}

float StudentManager::getTotalAverage() const
{
    if (num_of_students == 0)
        return 0.0f;
    float total = 0.0f;
    for (int i = 0; i < num_of_students; ++i)
    {
        total += students[i].getRecord().getTotal();
    }
    return total / num_of_students;
}
#include <iostream>

using namespace std;

struct student
{
    int studentID;
    string studentName;
    student *next;
};

student s;
student *head = NULL;

void menu()
{
    cout << "1. Add student" << endl
         << "2. Delete a student" << endl
         << "3. View All students" << endl
         << "4. Exit" << endl
         << endl;
}

void insertFront()
{
    student *temp = new student;
    cout << "Enter the ID of the Student ";
    cin >> s.studentID;
    cout << "Enter the Name of the Student ";
    cin >> s.studentName;

    temp->next = head;
    temp->studentID = s.studentID;
    temp->studentName = s.studentName;

    if (head == NULL)
    {
        head = temp;
        cout << " Successfully Inserted..." << endl;
    }
    else
    {
        temp->next = head;
        temp->studentID = s.studentID;
        temp->studentName = s.studentName;
        head = temp;
        cout << " Successfully Inserted..." << endl;
    }
}

void insert_at_specific_place()
{
    int targetID;
    cout << "Enter the student ID after which you want to insert: ";
    cin >> targetID;
    cout << "Enter the ID of the Student ";
    cin >> s.studentID;
    cout << "Enter the Name of the Student ";
    cin >> s.studentName;

    student *temp = new student;
    temp->next = head;
    temp->studentID = s.studentID;
    temp->studentName = s.studentName;

    if (head == NULL)
    {
        head = temp;
        cout << " Successfully Inserted..." << endl;
    }
    else
    {
        student *finder = head;
        while (targetID != finder->studentID)
        {
            if (finder == NULL)
            {
                cout << "There is no student registered with this id, make sure the id is correct " << endl;
                return;
            }
            finder = finder->next;
        }
        temp->next = finder->next;
        finder->next = temp;
        cout << " Successfully Inserted..." << endl;
    }
}

void insertAtEnd()
{
    cout << "Enter the ID of the Student ";
    cin >> s.studentID;
    cout << "Enter the Name of the Student ";
    cin >> s.studentName;

    student *temp = new student;
    temp->studentID = s.studentID;
    temp->studentName = s.studentName;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        student *temp2;
        temp2 = head;
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
}

void add_Student()
{
    int ch;
    cout << "Where do you want to insert?" << endl;
    cout << "1. At the beginning" << endl;
    cout << "2. After a specific student's ID" << endl;
    cout << "3. At the end" << endl;
    cin >> ch;

    switch (ch)
    {
    case 1:
        insertFront();
        break;
    case 2:
        insert_at_specific_place();
        break;
    case 3:
        insertAtEnd();
        break;
    default:
        cout << "Wrong choice, choose again" << endl;
        add_Student();
        break;
    }
}

void delete_Student()
{
    int id;
    student *temp = head;
    cout << "Enter Student's ID to delete: ";
    cin >> id;
    while (temp->next != NULL)
    {
        if (id = temp->studentID)
        {
            temp->next = temp->next->next;
        }
        temp = temp->next;
    }
}

void viewAll()
{
    student *temp = head;
    if (temp == NULL)
    {
        cout << "there is no data!!!" << endl;
        return;
    }
    cout << "________________________" << endl;
    cout << "ID  |  Name" << endl;
    while (temp != NULL)
    {
        cout << temp->studentID << " | " << temp->studentName << endl;
        cout << "___________________" << endl;
        temp = temp->next;
    }
}

int main()
{
    menu();
    int choice;
    cout << "Enter your choice ";
    cin >> choice;

    while (true)
    {
        if (choice == 4)
        {
            cout << "Exiting...";
            break;
        }
        switch (choice)
        {
        case 1:
            add_Student();
            break;
        case 2:
            delete_Student();
            break;
        case 3:
            viewAll();
            break;
        default:
            cout << "wrong choice";
            break;
        }
        menu();
        cout << "Enter your choice ";
        cin >> choice;
    }
    return 0;
}

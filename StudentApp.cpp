#include<iostream> 

using namespace std;

struct student {
    int studentID;
    string studentName;
    student *next;
};
void insertFront();
void insertAtEnd();
void add_Student();
void delete_Student();
void viewAll();

student s;
student *head = NULL;
void menu() {
    cout<<"1. Add student"<<endl
    <<"2. Delete a student"<<endl
    <<"3. View All students"<<endl
    <<"4. Exit"<<endl<<endl;
}

void insertFront() {
    student *temp = new student;
    cout <<"Enter your ID ";
    cin>>s.studentID;
    cout <<"Enter your Name ";
    cin>>s.studentName;
    
    temp->next = head;
    temp->studentID = s.studentID;
    temp->studentName = s.studentName;
    head = temp;
}

void insertAtEnd() {
        cout <<"Enter your ID ";
        cin>>s.studentID;
        cout <<"Enter your Name ";
        cin>>s.studentName;
    
        student *temp = new student;
        temp->studentID = s.studentID;
        temp->studentName = s.studentName;
        temp->next = NULL;

        if(head == NULL) {
            head = temp;
        }
        else {
            student *temp2;
            temp2 = head;
            while(temp2->next != NULL) {
                temp2 = temp2->next;
            }
            temp2->next = temp;
        }
}
void add_Student() {
    int ch;
    cout <<"Are you adding at the front or at the end, (1 for front and 2 for end)-> ";
    cin >>ch;

    if(ch == 1) {
        insertFront();
    }
    else if(ch == 2) {
        insertAtEnd();
    }
    else {
        cout <<"Wrong choice choose again:"<<endl;
        add_Student();
    }
} 

void delete_Student() {
    int id;
    student *temp = head;
    cout <<"Enter an ID: ";
    cin >>id;
    while(temp->next != NULL) {
        if(id = temp->studentID) {
            temp->next = temp->next->next;
        }
        temp = temp->next;
    }
}

void viewAll() {
    student *temp = head;
    if (temp == NULL) {
        cout << "there is no data!!!" << endl;
        return;
    }
    cout << "ID     Name" << endl;
    while (temp != NULL) {
        cout << temp->studentID << "   " << temp->studentName << endl;
        temp = temp->next;
    }
}

int main() {
    menu();
    int choice;
    cout <<"Enter your choice ";
    cin >>choice;

    while(true) {
        if(choice == 4) {
            cout<<"Exiting...";
            break;
        }
        switch(choice) {
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
            cout <<"wrong choice";
            break;
        }
        menu();
        cout <<"Enter your choice ";
        cin >>choice;
    }
    return 0;
}

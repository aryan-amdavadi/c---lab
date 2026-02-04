#include<iostream>
using namespace std;

class Student
{
private:
    int id;
    string name;
    float marks[3];
public:
    Student(){
        id = 0;
        name = "null";
        for(int j=0;j<3;j++){
            marks[j] = 0;
        }
    }
    Student(int mId, string mName, float mMarks[3]){
        id = mId;
        name = mName;
        for(int j=0;j<3;j++){
            marks[j] = mark[j];
        }
    }
    float averageMarks(){
        cout << "Average Marks : "<< endl;
        cout << (marks[0]+marks[1]+marks[2])/3 << endl;
        return (marks[0]+marks[1]+marks[2])/3;
    }
    void display(){
        cout<<"ID: "<<id<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Marks: "<<marks[0]<<", "<<marks[1]<<", "<<marks[2]<<endl;
        cout<<"-----------------------------\n";
    }
    int getID(){
        return id;
    }
};
int main(){
    Student students[100];
    int studentCount = 0;
    int choice;

    do{
        cout<<"----Menu----"<<endl;
        cout<<"1. Add Student"<<endl;
        cout<<"2. Display All Students"<<endl;
        cout<<"3. Average Marks"<<endl;
        cout<<"4. Search Student by ID"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:{
                int id;
                string name;
                float marks[3];
                cout<<"\nEnter Student ID: ";
                cin>>id;
                cout<<"Enter Student Name: ";
                cin>>name;
                cout<<"Enter Marks for 3 subjects: ";
                for(int j=0;j<3;j++){
                    cin>>marks[j];
                }
                students[studentCount]=Student(id, name, marks);
                studentCount++;
                break;
            }
            case 2:{
                cout<<"\n--- Student Details ---\n";
                for(int i=0;i<studentCount;i++){
                    students[i].display();
                }
                break;
            }
            case 3:{
                int sID;
                cout << "Enter the student id :";
                cin >> sID;

                for(int i=0;i<studentCount;i++){
                    cout << students[i].getID() << endl;
                    if(sID == students[i].getID()){
                        students[i].averageMarks();
                        break;
                    }
                }
                break;
            }
            case 4:{
                int sID;
                cout<<"\nEnter Student ID to search: ";
                cin>>sID;
                int found = 0;
                for(int i=0;i<studentCount;i++){
                    if(students[i].getID() == sID){
                        students[i].display();
                        found = true;
                        break;
                    }
                }
                if(!found){
                    cout<<"Student with ID "<<sID<<" not found."<<endl;
                }
                break;
            }
            default:{
                cout<<"Invalid choice."<<endl;
            }
        }
    }while(choice != 5);

    return 0;
}
#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;
class Student{
    string name;
    string rollNo;
    string deptment;
    string mobile ;
    public:
    void getData();
    void Display();
};
void Student::getData()
{
    cout<<"Enter name : "<<flush;
    cin.ignore();
    getline(cin,name);
    cout<<"Enter Roll No:"<<flush;
    getline(cin,rollNo);
    cout<<"Enter Deptment Name: "<<flush;
    getline(cin,deptment);
    cout<<"Enter Mobile No: "<<flush;
    getline(cin,mobile);
}
void Student::Display()
{
    cout<<"Name: "<<name<<endl;
    cout<<"Roll No:"<<rollNo<<endl;
    cout<<"Deptment Name : "<<deptment<<endl;
    cout<<"Mobile No: "<<mobile<<endl;
}

class Detials{
    Student s;
    public:
    void write();
    void read()
    { 
        fstream fin("C://vs code/text.txt/StudentInFo.txt",ios::in);
        while(fin)
        {
          //put same file location than you can print data
             fstream fin("C://vs code/text.txt/StudentInFo.txt",ios::in);
             fin.read((char*)&s,sizeof(s));
             s.Display();
             int s;
             cout<<"Press 1 to Continue :"<<flush;
             cin>>s;
             if(s==1)
             {

             }else{
                exit(0);
             }
            
        }
           
    }
    
};
void Detials::write()
{
   int condition;
  // put file loaction than where you want to store 
     fstream fout("C://vs code/text.txt/StudentInFo.txt",ios::app);
    do{
    s.getData();
    fout.write((char*)&s,sizeof(s));
    cout<<"Press 1 to Continue else exit : "<<flush;
    cin>>condition;
    }while(condition==1);
    fout.close();
}

 

int main()
{
    Detials s;
    int i=0;
    do{
        system("cls");
        cout<<"1. Write date "<<endl;
        cout<<"2. Read data"<<endl;
        cout<<"0. Exit.. "<<endl;
        int choice;
        cout<<"Enter Option : "<<flush;
        cin>>choice;
        switch(choice)
        {
            case 1: s.write(); break;
            case 2: s.read(); break;
            case 0: exit(0);
            default: 
            cout<<"Invalid Option "<<endl;
            i++;
        }
    }while(i<=1);
}

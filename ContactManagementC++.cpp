/***************************************************************
    *         Contact Management Program(C++)                   *
    *                                                           *
    * Author:  @MohammedOmar                                    *
    *                                                           *
    * Purpose:Demonstration Of Contact Management Program.      *
    *                                                           *
    * Usage:                                                    *
    *      By Executing below program you can Add,Delete,       *
    *      Update/Edit,Search With Number,Search With Name,     *
    *      and Display all contacts.                            *
    *Program compiled and Executed Succesfully on code::blocks  *
    *************************************************************/
#include <iostream>
#include<stdlib.h>
#include<conio.h>
#include<string>
using namespace std;
class phonebook
{
struct record
{
    string name;
    string email;
    string number;
   record* next;
}*first;
public:
    int sno=0;
phonebook()
{
 first=NULL;
 sno=0;
}
void add();
void delete1();
void display();
void searchwithnumber();
void searchwithname();
void update();
};
void phonebook::add()
{
    record *newrecord,*temp;
    int n;
    newrecord=new(struct record);//creating a new record
    if(newrecord==NULL)//checking for memory location
    cout<<"error in allocating memory"<<endl;
    else{
            cout<<"\nEnter Following Details(Without Spaces)"<<endl;
    cout<<"\nEnter the name:";
    cin>>newrecord->name;
    cout<<"\nEnter the number:";
    cin>>newrecord->number;
    cout<<"\nEnter the mail id:";
    cin>>newrecord->email;
    newrecord->next=NULL;
    sno++;
    if(first==NULL)
    {
      first=newrecord;
    }
  else
  {

    temp=first;
      while(temp->next!=NULL)
      {
        temp=temp->next;
      }
       temp->next=newrecord;
       newrecord->next=NULL;
    }
   cout<<"\n Contact Added"<<endl;
    }
}
void phonebook::display()
{
    struct record *temp;
    if(first==NULL)
    {
        cout<<"\n NO CONTACTS"<<endl;
    }
    else
    {
       temp=first;int i=1;
       cout<<"===========================================\n";
       cout<<"S.NO\tNAME\tNUMBER\t\tEMAIL\n";
       cout<<"===========================================\n";
       while(temp!=NULL)
       {
       cout<<i++<<"\t"<<temp->name<<"\t"<<temp->number<<"\t"<<temp->email<<"\n";
        temp=temp->next;
        }
    }
}
void phonebook::delete1()
{
    char val[20];
    bool flag=false;
    if(first==NULL)
   {
    cout<<"\nNO CONTACTS"<<endl;
   }
  else
  {
      record *temp,*prev;
      cout<<"\n enter the conatct name to delete:";
    cin>>val;
    temp=first;
    if(temp->name==val)
    {
       first=temp->next;
      delete temp;
    }

   else
    {
        int i=1;
    while(temp->name!=val)
    {
        prev=temp;
        temp=temp->next;
        i++;
        if(i>sno){
                delete temp;
            goto end;
            flag=true;
        }
    }
    if(temp->name==val){
     if(temp->next==NULL)
    prev->next=NULL;
    else
    prev->next=temp->next;
    delete temp;
    }
    }
    cout<<"\nCONTACT DELETED"<<endl;
   }
end:
    if(flag)
    cout<<"NO CONTACT";
}
void phonebook::searchwithnumber(){
    if(first==NULL)
        cout<<"NO CONTACTS"<<endl;
    else{
            int i=1;
            bool flag=true;
        record *temp=first,*prev=NULL;
        cout<<"Enter Number:";
        string num;
        cin>>num;
        while(temp->number!=num){
                prev=temp;
            temp=temp->next;i++;
            if(i>sno){
                flag=false;
                cout<<"NO CONTACT WITH NUMBER"<<num<<endl;
                break;
            }
        }
        if(flag){
        cout<<"\tNAME:"<<temp->name<<"\n\n\tNUMBER:"<<temp->number<<"\n\n\tE-MAIL:"<<temp->email<<endl;
        }
    }
}
void phonebook::searchwithname(){
    if(first==NULL)
        cout<<"NO CONTACTS"<<endl;
    else{
            int i=1;
            bool flag=true;
        record *temp=first,*prev=NULL;
        cout<<"Enter Name:";
        string cname;
        cin>>cname;
        while(temp->name!=cname){
                prev=temp;
            temp=temp->next;i++;
            if(i>sno){
                flag=false;
                cout<<"NO CONTACT WITH NAME:"<<cname<<endl;
                break;
            }
        }
        if(flag){
        cout<<"\tNAME:"<<temp->name<<"\n\n\tNUMBER:"<<temp->number<<"\n\n\tE-MAIL:"<<temp->email<<endl;
        }
    }
}
void phonebook::update(){
    bool flag=false;
    if(first==NULL)
        cout<<"CONTACT LIST IS EMPTY"<<endl;
    else{
            int i=1;
    cout<<"Enter Name Of The Contact you Want To Edit:";
    string cname;
    cin>>cname;
    record *temp=first;
    while(temp->name!=cname){
        temp=temp->next;
        i++;
        if(i>sno){flag=true;
            goto end;
        }
    }
    cout<<"Enter Any one Of The Following:-"<<endl;
    cout<<"\t1)Edit Name\n\t2)Edit Number\n\t3)Edit Email\n\t4)Edit All\nChoice:";
    int ch;
    cin>>ch;
    switch(ch){
        case 1:cout<<"Enter New Name:";
                cin>>temp->name;
                cout<<"CONTACT UPDATED!"<<endl;
                break;
        case 2:cout<<"Enter New Number:";
                cin>>temp->number;
                cout<<"CONTACT UPDATED!"<<endl;
                break;
        case 3:cout<<"Enter New Email:";
                cin>>temp->email;
                cout<<"CONTACT UPDATED!"<<endl;
                break;
        case 4:cout<<"Enter New Name:";
                cin>>temp->name;
                cout<<"Enter New Number:";
                cin>>temp->number;
                cout<<"Enter New Email:";
                cin>>temp->email;
                cout<<"CONTACT UPDATED!"<<endl;
                break;
        default:cout<<"invalid choice";
    }
    }
end:
    if(flag)
    cout<<"NO CONTACT FOUND";
}
int main()
{
    phonebook s;
        int choice;
    do
    {
    cout<<"\t===================================\n";
    cout<<"\t            MENU\n";
    cout<<"\t===================================\n";
    cout<<"\t\nENTER YOUR CHOICE:"<<endl;
    cout<<"\t1)Add Contact"<<endl;
    cout<<"\t2)Display All"<<endl;
    cout<<"\t3)Search with name"<<endl;
    cout<<"\t4)Search with number"<<endl;
    cout<<"\t5)Delete"<<endl;
    cout<<"\t6)Edit/Update a Contact"<<endl;
    cout<<"\t7)Exit\nChoice:";
    cin>>choice;
    switch(choice)
    {
        case 1:s.add();
                cout<<"\nPRESS ANY KEY TO CONTINUE.....";
                getch();
                 system("cls");
              break;
        case 2:s.display();
                cout<<"\nPRESS ANY KEY TO CONTINUE.....";
                getch();
                 system("cls");
                break;
        case 3:s.searchwithname();
                cout<<"\nPRESS ANY KEY TO CONTINUE.....";
                getch();
                 system("cls");
            break;
        case 4:s.searchwithnumber();
                cout<<"\nPRESS ANY KEY TO CONTINUE.....";
                getch();
                 system("cls");
                break;
        case 5:s.delete1();
                cout<<"\nPRESS ANY KEY TO CONTINUE.....";
                getch();
                 system("cls");
                break;
        case 6:s.update();
                cout<<"\nPRESS ANY KEY TO CONTINUE.....";
                getch();
                 system("cls");
                break;
        case 7:exit(0);
         default:cout<<"Invalid choice";
   }

    }
   while(choice<7&&choice >0);

return 0;
}

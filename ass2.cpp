#include<iostream>
 using namespace std;
 class Student{
 private:
 string address;
 public:
 string name;
 string clas;
 string blood_grp;
 string dob;
 int div;
 string mobile_num;
 int roll_num;
 //exception handling.......
 Student(string clas,int div){
 name="vijay";
 this-> clas=clas;
 blood_grp="o+";
 dob="15/10/2005";
 this-> div=div;
 mobile_num="7615127512";
 roll_num=19;
 }
 Student(){
 try{
 cout<<"enter your roll number-";
 cin>>roll_num;
 if(roll_num<=0){
 throw(roll_num);
 }
 }
 catch(...){
 cout<<"incorrect roll number";
 roll_num=1;
 }
 cout<<"\n enter your name-"<<endl;
 cin>>name;
 cout<<"\n enter your class-"<<endl;
 cin>>clas;
cout<<"\n enter your division-"<<endl;
 cin>>div;
 cout<<"\n enter your mobile number-"<<endl;
 cin>>mobile_num;
 cout<<"\n enter your blood group-"<<endl;
 cin>>blood_grp;
 cout<<"\n enter your date of birth-"<<endl;
 cin>>dob;
 cout<<"\n enter your address-"<<endl;
 cin>>address;
 }
 Student(Student &s){
 name=s.name;
 clas=s.clas;
 div=s.div;
 mobile_num=s.mobile_num;
 blood_grp=s.blood_grp;
 dob=s.dob;
 roll_num=s.roll_num;
 address=s.address;
 }
 inline static void head(){
 cout<<"\n Name\t\tClass\tdivision\tmobile number\t\tbloodgrp\taddress\t\tdateofbirth\trollnumber"<<endl;
 }
 void display(){
 cout<<"\n"<<name<<"\t\t"<<clas<<"\t"<<div<<"\t\t"<<mobile_num<<"\t\t"<<blood_grp<<"\t\t"<<address<<"\t\t"<<dob<<"\t\t"<<roll_num<<endl;
 }
 ~Student(){
 cout<<"Destroying............"<<endl;
 }
 friend class Teacher;
 };
 class Teacher{
 public:
 void display(Student & S2){
 cout<<"\n adress="<<S2.address<<endl;
 }
 };
int main(){
 cout<<"\n Enter Student data:";
 int i,n;
 cout<<"\nenter the number ofstudents-";
 cin>>n;
 cout<<"\nAccepting object for Dynamic memory-";
 Student* s=new Student[n];
 Student::head();
 for(i=0;i<n;i++){
 s[i].display();
 }
 cout<<"\nthis pointer-";
 Student s4("TE",1);
 Student::head();
 s4.display();
 cout<<"\nCopy constructor-";
 Student S2;
 Student S3(S2);
 Student::head();
 S3.display();
 cout<<"\nacccessing member by friend class-";
 Teacher T1;
 T1.display(S2);
 delete[] s;
 }
 
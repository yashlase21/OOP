#include<iostream>
 #include<fstream>
 #include<cstring>
 using namespace std;
 class student{
 public:
 int rn;
 string name;
 float pr;
 void header(){
 ofstream out;
 out.open("Student.txt", ios :: app);
 out<<"ROLL NUMBR"<<"\t"<<"NAME"<<"\t"<<"PERCENTAGE";
 out<<endl;
 out.close();
 }
 void accept(){
 cout<<"\n Enter your roll number: ";
 cin>>rn;
 cin.ignore();
 cout<<"\n Enter your name: ";
 getline(cin,name);
 cout<<"\n Enter your percentage: ";
 cin>>pr;
 }
 void store(){
 ofstream out;
 out.open("Student.txt", ios::app);
 out<<"\t"<<rn;
 out<<"\t"<<name;
 out<<"\t"<<pr<<"%";
 out<<endl;
 out.close();
 }
 void read(){
 ifstream in;
 string str;
 in.open("Student.txt",ios::in); 
while(!in.eof()){
 getline(in,str);
 cout<<str<<endl;
 }
 in.close();
 }
 };
 int main(){
 student s[3],s1;
 s1.header();
 int ch;
 do{
 cout<<"\t.......MENU.......";
 cout<<"\n 1.Accept Student Information-:";
 cout<<"\n 2.Display Student Information-:";
 cout<<"\n 3.exit";
 cout<<"\n Enter your choice-:";
 cin>>ch;
 switch(ch){
 case 1:
cout<<"\n Enter the student data-:";
 for(int i=0;i<3;i++){
 s[i].accept();
 s[i].store();
 }
 break;
 case 2:
 cout<<"\nDisplaying the data......"<<endl;
 s1.read();
 break;
 case 3:
 cout<<"\nexiting.........";
 break;
 default:
 cout<<"enter valid choice-";
 break;
 }
 }while(ch!=3);
 }
#include<iostream>
 using namespace std;
 class Publ{
 public:
 string T;
 float P;
 void getdata(){
 cout<<"\nenter the price-";
 cin>>P;
 cin.ignore();
 cout<<"\nEnter the title-";
 getline(cin,T);
 }
 void display(){
 cout<<"\nThe title is-"<<T;
 cout<<"\nThe price is-"<<"Rs-"<<P;
 }
 };
 class book:public Publ{
 public:
 int PC;
 void getdata(){
 try{
 
 Publ::getdata();
 cout<<"\nEnter the Page count-";
 cin>>PC;
 if(PC<=0){
 throw PC;
 }
 }
 catch(...){
 cout<<"Invalid Page Count";
 PC=0;
 }
 }
 void display(){
 Publ::display();
 cout<<"\nThe Page Count is-"<<PC<<endl;
 }
 };
 class tape:public Publ{
public:
 float TM;
 void getdata(){
 try{
 Publ::getdata();
 cout<<"\nEnter the value of playing time-";
 cin>>TM;
 if(TM<=0){
 throw TM;
 }
 }
 catch(...){
 cout<<"Invalid Playing Time-";
 TM=0;
 }
 }
 void display(){
 Publ::display();
 cout<<"\nThe playing time is-"<<TM<<" min"<<endl;
 }
 };
 int main(){
 book b[100];
 tape t[100];
 int ch,BT=0,PT=0;
 do{
 cout<<"\n......PUBLICATION DETAILS........";
 cout<<"\n 1.Add book details";
 cout<<"\n 2.Add Tape details";
 cout<<"\n 3.Display Book details";
 cout<<"\n 4.Display Tape Details";
 cout<<"\n 5.Dispay Page count and Tape count";
 cout<<"\n 6.Exit....";
 cout<<"\n enter your choice-";
 cin>>ch;
 switch(ch){
 case 1:
 b[BT].getdata();
 BT++;
 break;
 case 2:
t[PT].getdata();
 PT++;
 break;
 case 3:
 for(int i=0;i<BT;i++){
 b[i].display();
 cout<<" ";
 }
 break;
 case 4:
 for(int i=0;i<PT;i++){
 t[i].display();
 cout<<" ";
 }
 break;
 case 5:
 cout<<"Page count is-"<<BT;
 cout<<"Playing Time is-"<<PT;
 break;
 case 6:
 cout<<"exiting.......";
 break;
 }
 }while(ch!=6);
 }
 
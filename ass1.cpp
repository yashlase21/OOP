#include<iostream>
 using namespace std;
 class complex{
 public:
 int rl,img;
 complex(){
 rl=0;
 img=0;
 }
 void display(){
 cout<<"The Complex Number Is : ";
 cout<<" "<<rl<<" + "<<img<<"i"<<endl;
 }
 complex operator+(complex& c2){
 complex c;
 c.rl=rl+c2.rl;
 c.img=img+c2.img;
 return c;
 }
 complex operator*(complex& c2){
 complex c;
 c.rl=(rl*c2.rl)-(img*c2.img);
 c.img=(rl*c2.img)+(img*c2.rl);
 return c;
 }
 friend istream& operator>>(istream& in,complex& c2){
 cout<<"Enter Real Part Of Complex Number : ";
 in>>c2.rl;
 cout<<"Enter Imaginary Part Of Complex Number : ";
 in>>c2.img;
 return in;
 }
 friend ostream& operator<<(ostream& out,complex& c){
 out<<c.rl;
 cout<<" + ";
 out<<c.img;
 cout<<"i"<<endl;
 return out;
 }
 };
 int main(){
 complex c1,c2,c3,c4;
 int ch;
do{
 cout<<"***menu***"<<endl;
 cout<<"1.default complex number\n";
 cout<<"2.Accept Two Complex Numbers\n";
 cout<<"3.Display Two Complex\n";
 cout<<"4.Addition Of Two Complex Numbers \n";
 cout<<"5.Multiplication Of Two Complex Numbers \n";
 cout<<"6.Exit \n\n";
 cout<<"Enter Choice :";
 cin>>ch;
 switch(ch){
 case 1:
 cout<<"The Default Complex Number Is : ";
 cout<<c1;
 cout<<"\n";
 break;
 case 2:
 cout<<"Enter First Complex Number \n";
 cin>>c1;
 cout<<"Enter Second Complex Number \n";
 cin>>c2;
 cout<<"\n";
 break;
 case 3:
 cout<<"First Complex Number Is : ";
 cout<<c1;
 cout<<"Second Complex Number Is : ";
 cout<<c2;
 cout<<"\n";
 break;
 case 4:
 cout<<"Addition Is : ";
 c4 = c1+c2;
 cout<<c4;
 cout<<"\n";
 break;
 case 5:
 cout<<"Multiplication Is :";
 c4 = c1*c2;
 cout<<c4;
 cout<<"\n";
 break;
 case 6:
cout<<"Exiting ......"<<endl;
 cout<<"\n";
 break;
 default:
 cout<<"Please Enter Valid Choice"<<endl;
 cout<<"\n";
 break;
 }
 }while(ch!=6);
 }
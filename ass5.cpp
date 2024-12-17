#include<iostream>
 using namespace std;
 template<class T>
 class sort{
 T a[50];
 int n;
 public:
 void accept(){
 cout<<"\n ENTER THE NO OF ELEMENTS IN ARRAY";
 cin>>n;
 cout<<"ENTER THE ELEMENTS"<<endl;
 for(int i=0;i<n;i++){
 cin>>a[i];
 }
 }
 void selection_sort(){
 T temp;
 for (int i=0;i<n-1;i++){
 int min=i;
 for (int j=i+1;j<n;j++){
 if (a[min]>a[j]){
 min=j;
 }
 }
 temp=a[min];
 a[min]=a[i];
 a[i]=temp;
 }
 }
 void display()
 { cout<<"SORTED ARRAY IS:";
 for (int i=0;i<n;i++){
 cout<<a[i]<<endl;
 }
 }
 };
 int main(){
 sort<int>s1;
 sort<float>s2;
 int ch;
 do{
 cout<<"_________________________MENU_________________________"<<endl;
 cout<<"\n 1. FOR INTEGER DATA";
cout<<"\n2.FORFLOATDATA";
 cout<<"\n3.EXIT";
 cout<<"\nENTERTHECHOICE";
 cin>>ch;
 switch(ch){
 case1:
 s1.accept();
 s1.selection_sort();
 s1.display();
 break;
 case2:
 s2.accept();
 s2.selection_sort();
 s2.display();
 break;
 case3:
 exit(0);
 }
 }while(ch!=3);
 }

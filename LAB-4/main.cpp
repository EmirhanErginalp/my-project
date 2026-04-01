#include <iostream>
#include <string>
#define MAX 5

using namespace std;

struct Package{
  string packageID;
  string destinationCity;
  int dimension[3];
  Package* next;

};
Package* top = nullptr;
struct Courier{
   string courierName;
   string vehicleType;

};

Courier Que[MAX];
int front = -1;
int rear = -1;

void push(string ID,string City,int l,int w,int h){
   Package* newPack = new Package;

   newPack->packageID = ID;
   newPack->destinationCity = City;
   newPack->dimension[0] = l;
   newPack->dimension[1] = w;
   newPack->dimension[2] = h;

   newPack->next = top;
   top = newPack;

   
}

void enque(string name,string vehicle){

    if ((rear + 1) % MAX == front) {
        cout << "kuyruk dolu\n"; 
        return;
    }
    if(front == -1){
        front = 0;
    }

    rear = (rear+1) % MAX;

    Que[rear].courierName = name;
    Que[rear].vehicleType = vehicle;
    



}

void dispatch(){

if(top == nullptr || front == -1){
    cout <<"basarisiz\n";
}
Package* dispatch = top;
string ID = dispatch->packageID;
string Name = Que[front].courierName;
cout << Name << "kurye " << ID << " paketi aldi.\n";

top = top->next;
delete dispatch;

if(front == rear){
    front = -1;
    rear = -1;
}else{
    front = (front+1) % MAX;
}


}

void display(){

    cout << "paketler:\n";
    if(top == nullptr){
       cout << "paket yok\n";
    }else{
        Package* temp = top;
        while(temp != nullptr){
            cout << "ID:" << temp->packageID << "\n";
            temp = temp->next; 
        }
    }
    cout << "kuryeler:\n";
    if(front == -1){
        cout <<"kurye yok\n";
    }else{
        int i = front;
        while(true){
            cout << "isim: " << Que[i].courierName << "\n";
            if(i == rear){
                break;
            }
            i = (i + 1) % MAX;
        }
        cout << "-------------------------------\n\n";
    }


}



int main(){

    push("001","Kocaeli",41,41,41);
    push("002","Düzce",1,1,1);
    push("003","Konya",42,42,42);

    enque("Emirhan","Motor");
    enque("Kerem","Bisiklet");
    enque("Salih","Araba");

    display();

    dispatch();
    display();

    dispatch();
    display();

  return 0; 
}
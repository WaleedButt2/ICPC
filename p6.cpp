#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <limits.h>
#include <queue>
using namespace std;
class CircularQueue{
    int *q;
    int Head;
    int Tail;
    int size;
public:
CircularQueue(){
    Head=0;
}

void read(int size){
    this->size=size;
    q= new int[size];
    Head=0;
    Tail=0;
    for(int i=0;i<size;i++){
        q[i]=0;
    }
}//when printing start from tail
void print(){
    //cout<<Head<<endl;
    for(int i=0;i<size;i++){
        cout<<q[i]<<' ';
    }
    cout<<endl;
}
void Move_Head(int x){
    int val=x;
  //  cout<<val<<endl;
   //cout<<q[Head]<<endl;
    while(x!=0){
        if(q[Head]==0)x--;
      //  cout<<Head<<' '<<x<<endl;
        Head++;
       // cout<<Head<<' '<<x<<endl;
        if(Head>=size) Head=0;
        // cout<<Head<<' '<<size<<endl;
    }
    while(q[Head]!=0) {Head++;if(Head>=size) Head=0;}
    //cout<<Head<<endl;
    q[Head]=val;
    if(val!=size)
    while(q[Head]!=0) {Head++;if(Head>=size) Head=0;}
}
void Run(int x){
int t=1;
if (x==1) {q[Head]=1; return;}
while(t<=x){
//cout<<"jojo"<<endl;
    Move_Head(t++);
}
}
};
int main(){
    int op;
    int x;
    cin>>op;
    for(int i=0;i<op;i++){
    cin>>x;
    CircularQueue jojo;
    jojo.read(x);
    jojo.Run(x);
    jojo.print();
    }
}
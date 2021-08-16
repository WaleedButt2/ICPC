#include <bits/stdc++.h>
using namespace std;
class Job{
public:
int a=0;
int t=0;
int c=0;
int order_no=0;
int output_cost=0;
int time=0;
};
class Printer{
public:
    bool Avaliability;
    int time_till_free;
    int Cost_per_time;
    bool dont_check;
    int latest_arrival_times;
Printer(){
    Avaliability=true;
    dont_check=false;
    Cost_per_time=0;
    time_till_free=0;
    latest_arrival_times=0;
}
};
void assort(Printer *t,int size){
    Printer temp;
    for(int j=0;j<size-1;j++){
        for(int i=0;i<size-1-j;i++){
        if(t[i].Cost_per_time>t[i+1].Cost_per_time){
            temp=t[i];
            t[i]=t[i+1];
            t[i+1]=temp;
        }
        }
    }
}
bool ret(Job x,Job s){
    return x.a<s.a;
}
bool res(Job x,Job s){
    return x.order_no<s.order_no;
}
void print(Printer *t,int size){
    for(int i=0;i<size;i++)   cout<<t[i].Cost_per_time<<' ';
    cout<<endl;
}
void print(Job *t,int size){
    for(int i=0;i<size;i++)   cout<<t[i].time<<' '<<t[i].output_cost<<endl;
    cout<<endl;
}
int current_avalible_print(Printer *printers,int size,int &current_avalible_printer,int a,int cost){
    for(int i=0;i<size;i++) if(cost<printers[i].Cost_per_time) printers[i].dont_check=true;
    for(int i=0;i<size;i++){
        printers[i].time_till_free-=a;
        if(printers[i].time_till_free<=0)
            printers[i].Avaliability=true;
    }
   // cout<<printers[0].time_till_free<<endl;
    for(int i=0;i<size;i++)
       if(printers[i].Avaliability==true&&printers[i].dont_check==false)return i; 
   // cout<<"as\n"; 
   // cout<<printers[0].time_till_free<<' '<<printers[1].time_till_free<<endl;
    for(int i=0;i<size;i++){
       if(i==size)  return i;
       if(printers[i].time_till_free<printers[i+1].time_till_free&&printers[i].dont_check==false)return i;
       }  
   cout<<"\nasa\n"<<endl;
    return current_avalible_printer;
}
void reset(Printer *printers,int size,int a){
    for(int i=0;i<size;i++) printers[i].dont_check=false;
    for(int i=0;i<size;i++){
        printers[i].time_till_free+=a;
        if(printers[i].time_till_free>0){
            printers[i].Avaliability=false;
        }
    }
}
int main(){
    int m,n,a,t,c,min_cost=INT_MAX;
    cin>>n>>m;; //n is no. of printers and m is no. of jobs
    Printer *printers= new Printer[n];
    Job *jobs = new Job [m];
    for(int i=0;i<n;i++){  
        cin>>printers[i].Cost_per_time;
        min_cost=min(min_cost,printers[i].Cost_per_time);
    }
    assort(printers,n);
    int current_avalible_printer=0;


    for(int i=0;i<m;i++){  
    cin>>jobs[i].a>>jobs[i].t>>jobs[i].c;
    jobs[i].order_no=i;
    //cout<<jobs[i].a<< ' '<<jobs[i].t << ' '<< jobs[i].c<<endl;
    }
    cout<<endl;
    sort(jobs,&jobs[m],ret);
    //print(jobs,m);
   // exit(0);
  // cout<<jobs[0].t<<endl;
 // cout<<m<<endl;
    for(int s=0;s<m;s++){
        a=jobs[s].a;c=jobs[s].c;t=jobs[s].t;
       // cout<<a<< ' '<<t << ' '<< c<<endl;
      //  exit(0);
        if(c<min_cost){
            //cout<<a<<" 0\n";
            jobs[s].output_cost=0;
            //cout<<jobs[s].order_no+1<<' '<<a<<endl;
            jobs[s].time=a;
            continue;
        }
       // cout<<printers[0].time_till_free<<' '<<a<<' '<<printers[0].latest_arrival_times<<endl;
        current_avalible_printer=current_avalible_print(printers,n,current_avalible_printer,a,c);
      //  cout<<printers[0].time_till_free<<' '<<a<<' '<<printers[0].latest_arrival_times<<endl;
        //cout<<current_avalible_printer<<' ';
        reset(printers,n,a);
        //cout<<12<<endl;
        //cout<<printers[0].time_till_free<<' '<<a<<' '<<printers[0].latest_arrival_times<<endl;
        //if(a<=printers[current_avalible_printer].time_till_free||printers[current_avalible_printer].Avaliability==true)printers[current_avalible_printer].latest_arrival_times+=a;
       // else printers[current_avalible_printer].latest_arrival_times=0;
        cout<<printers[0].time_till_free<<' '<<a<<' '<<current_avalible_printer<<endl;
        if(printers[current_avalible_printer].Avaliability==true||printers[current_avalible_printer].time_till_free<=a){
            printers[current_avalible_printer].Avaliability=false;
           // cout<<s<<endl;
            printers[current_avalible_printer].time_till_free=t+a;
        }
        else  printers[current_avalible_printer].time_till_free=1+t+printers[current_avalible_printer].time_till_free-printers[current_avalible_printer].latest_arrival_times;
       // cout<<endl<<printers[0].time_till_free<<' '<<printers[1].time_till_free<<endl;
        jobs[s].time=printers[current_avalible_printer].time_till_free;
        jobs[s].output_cost=printers[current_avalible_printer].Cost_per_time*t;
        cout<<printers[0].time_till_free<<' '<<a<<endl<<endl;
        printers[current_avalible_printer].latest_arrival_times=a;
   cout.flush();
    }
    sort(jobs,&jobs[m],res);
    print(jobs,m);
}

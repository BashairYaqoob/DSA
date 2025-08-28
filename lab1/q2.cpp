#include <iostream>
#include <cstring>
using namespace std;

class Exam{
    private:
    char* studentname;
    char* examdate;
    int score;
    public:
    Exam(){}
    Exam(const char* sn, const char* e, int s){
        studentname=new char[strlen(sn)+1];
        strcpy(studentname, sn);
        examdate=new char[strlen(e)+1];
        strcpy(examdate, e);
        this->score=s;
    }
    void changeDate(const char* d){
        delete[] examdate;
        examdate= new char[strlen(d)+1];
        strcpy(examdate,d);
    }
    void display(){
        cout<<"Student name: "<<studentname<<"\nExam date: "<<examdate<<"\nScore: "<<score<<endl;
    } 
    ~Exam(){
        delete[] studentname;
        delete[] examdate;
    }
};

int main(){
    Exam e1("Maha", "10/8/2025", 90);
    e1.display();
    Exam e2=e1;
    e2.display();
    e1.changeDate("14/8/2025");
    e2.display();
    //changing e1 also changes e2 (shallow copy)
    return 0;
}

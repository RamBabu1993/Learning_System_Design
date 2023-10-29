#include<bits/stdc++.h>
using namespace std;

class Abstract_class{
    virtual void ask_for_promotion(int age) =0;
};

class employee:Abstract_class{
private:
    // these are the attributes 
    string Company;
    int Age;

protected:
    string Name;
public:
    // constructor should be public most of the time.
    employee(string name, string company, int age){
        Name = name;
        Company = company;
        Age = age;
    }
    void set_name(string name){
        Name = name;
    }
    string get_name(){
        return Name;
    }
    void set_comapny(string company){
        Company = company;
    }
    string get_company(){
        return Company;
    }
    void set_age(int age){
        Age = age;
    }
    int get_age(){
        return Age;
    }

    // this is a method
    void Introduce_yourself(){
        cout<<"my name is "<<Name<<" my company is "<<Company<<" and my age is "<<Age<<endl;
    }
    void ask_for_promotion(int age){
        if(age>20){
            cout<<"Promoted"<<endl;
        }
        else 
            cout<<"Not Promoted!"<<endl;
    }
};

class developer:employee{
public:
    string fav_programming_lang;
    developer(string name, string company, int age, string prog_lang)
    :employee(name, company, age){
        fav_programming_lang = prog_lang;
    }
    void fix_bug(){
        cout<<Name<< " is fixing the bug!"<<endl;
    }
};

class teacher: public employee{
public:
    string Subject;
    void prepare_lession(){
        cout<<Name<< "is preparing "<<Subject<<" lession"<<endl;
    }
    teacher(string name, string company, int age, string subj)
    :employee(name, company, age){
        Subject = subj;
    }
};

int main(){
    employee employee1 = employee("rambabu", "Amazon", 21);
    // employee1.name = "Ram Babu";
    // employee1.age =25;
    // employee1.company = "Amazon";
    employee1.Introduce_yourself();
    return 0;
}
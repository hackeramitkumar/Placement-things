#include<bits/stdc++.h>
using namespace std;
#define ll long long


class Student{
    public:
string fName;
string lName;
int regNo;

Student(string fname,string lname,int regNo){
fName = fname;
lName = lname;
this->regNo = regNo;
}

bool operator == (const Student &s) const {
    return regNo == s.regNo ? true:false;
}
};

class HashFn{
public:
size_t operator()(const Student &s) const {
    return s.fName.length()+s.lName.length();
}
};

int main(){
Student amit0 = Student("Amit0","Kumar0",20);
Student amit1 =  Student("Amit1","Kumar1",21);
Student amit2 =  Student("Amit2","Kumar2",21);
Student amit3 =  Student("Amit3","Kumar3",23);
unordered_map<Student,int,HashFn> mp;
mp[amit0] = 85;
mp[amit2] = 90;
mp[amit1] = 56;

for(auto p : mp){
    Student s = p.first;
    cout<<s.fName<<" "<<s.lName<<" "<<s.regNo<<"  got the marks :"<< p.second<<endl;
}

cout<<(amit0 == amit1)<<"  "<<(amit1 == amit2)<<endl;

}
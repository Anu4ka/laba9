#include <iostream>
#include <fstream>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

#pragma pack(push, 1)
struct Student{
    char cname[64] = { 0 };  ///64
    double dmark;            ///8
    int iage;                ///4
    int icourse;             ///4
    bool bsex;               ///1 + 1
    
};
#pragma pack(pop)

void Print(Student& student){
    cout << student.cname << " " << student.dmark << " " << student.iage << " " << student.icourse << " " << student.bsex << endl;
}

void read(ifstream &infile){
    while(infile){
        Student student;
        infile.read(reinterpret_cast <char*> (&student), sizeof(Student));
        Print(student);
    }
}

void add(ofstream &outfile, string name, int age, bool sex, int course, double mark){
    Student student;
    strcpy(student.cname, name.c_str());
    student.dmark = mark;
    student.iage = age;
    student.icourse = course;
    student.bsex = sex;
    outfile.write(reinterpret_cast <char*> (&student), sizeof(Student));
    cout << student.iage << endl;
}

void getFoolsih(ifstream &infile, ofstream &outfile){
    while(infile){
        Student st;
        infile.read(reinterpret_cast <char*> (&st), sizeof(Student));
        //  Print(st);
        if(st.dmark < 4){
            outfile.write(reinterpret_cast <char*> (&st), sizeof(Student));
        }
    }
}

int main(){
    ofstream giveStudents("./students.bin", ios::binary);
    if(!giveStudents){
        cout << "Smt wrong!";
        return 1;
    }
    add(giveStudents, "Maxim Galton", 27, 1, 4, 4.3);
    add(giveStudents, "Gayl River", 18, 1, 1, 3.2);
    add(giveStudents, "Vilen Galton", 24, 1, 3, 6.7);
    add(giveStudents, "Dara River", 19, 0, 2, 5.5);
    add(giveStudents, "Kandia Leta", 19, 0, 3, 2.1);
    add(giveStudents, "Mark Dine", 18, 1, 1, 10.0);
    add(giveStudents, "Gelicia Aubvelts", 48, 0, 6, 3.9);
    add(giveStudents, "Fitz Nobody", 19, 2, 1, 3.3);
    add(giveStudents, "Danis Matiush", 22, 1, 4, 6.5);
    add(giveStudents, "Gospadin Past", 103, 1, 1, 2.1);
    add(giveStudents, "Vaclav Hoit", 63, 1, 6, 7.2);
    giveStudents.close();
    ifstream getstudents("./students.bin", ios::binary);
    if(!getstudents){
        cout << "Smt wrong!";
        return 1;
    }
    ofstream foolsihStrudents("./foolsihStrudents.bin", ios::binary);
    if(!foolsihStrudents){
        cout << "Smt wrong!";
        return 1;
    }
    getFoolsih(getstudents, foolsihStrudents);
    getstudents.close();
    foolsihStrudents.close();


    ifstream getfoolsihStrudents("./foolsihStrudents.bin", ios::binary);
    if(!getfoolsihStrudents){
        cout << "Smt wrong";
        return 1;
    }
    read(getfoolsihStrudents);
    getfoolsihStrudents.close();

    return 0;
}
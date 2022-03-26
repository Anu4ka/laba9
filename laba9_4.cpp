#include <iostream>
#include <fstream>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

struct Student{
    string cname;
    double dmark;
    int icourse;
    int iage = -1;
    bool bsex;
};

void Print(Student& student){
    cout << student.cname << " " << student.iage << " " << student.bsex << " " << student.icourse << student.dmark << endl;
}

void add(ofstream &outfile, string name, int iage, bool bsex, int icourse, double dmark){
    Student student;
    student.cname = name;
    student.iage = iage;
    student.bsex = bsex;
    student.icourse = icourse;
    student.dmark = dmark;
    outfile << student.cname << " " << student.iage << " " << student.bsex << " " << student.icourse << " " << student.dmark << endl;
}

void getFoolsih(ifstream &infile, ofstream &outfile){
    while(infile){
        string name;
        Student student;
        infile >> student.cname;
        infile >> name;
        student.cname += " ";
        student.cname += name;
        infile >> student.iage >> student.bsex >> student.icourse >> student.dmark;
        if(student.iage == -1){
            break;
        }
        if(student.dmark < 4){
            outfile << student.cname << " " << student.iage << " " << student.bsex << " " << student.icourse << " " << student.dmark << endl;
        }
    }
}

int main(){
    ofstream giveStudents("./students.txt");
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
    ifstream getstudents("./students.txt");
    if(!getstudents){
        cout << "Smt wrong!";
        return 1;
    }
    ofstream foolsihStrudents("./foolsihStrudents.txt");
    if(!foolsihStrudents){
        cout << "Smt wrong!";
        return 1;
    }
    getFoolsih(getstudents, foolsihStrudents);
    getstudents.close();
    foolsihStrudents.close();
    return 0;
}
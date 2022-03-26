#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>

using namespace std;

void getnewfile(ifstream &f_file, ifstream &g_file){
    ofstream out("./new_file.txt");
    if(!out.is_open()){
        cout << "Smt wrong";
        return;
    }
    double fvalue = 0;
    double gvalue = 0;
    f_file >> fvalue;
    g_file >> gvalue;
    double lastAddedNum  = 0;
    while(!f_file.fail() || !g_file.fail()){
        if(fvalue < gvalue){
            if(!f_file.fail()){
                f_file >> fvalue;
            } else {
                g_file >> gvalue;
            }
        } else {
            if(!g_file.fail()){
                g_file >> gvalue;
            } else {
                f_file >> fvalue;
            }
        }
        if(fvalue == gvalue && fvalue != lastAddedNum){
            out << fvalue << endl;
            lastAddedNum = fvalue;
        }
    }
    out.close();
}

int main(){
    ifstream f_file("./f_file.txt");
    ifstream g_file("./g_file.txt");
    if (f_file.is_open() && g_file.is_open()){
        getnewfile(f_file, g_file);
    } else {
        cout << "Smt wrong";
        return 1;
    }
    f_file.close();
    g_file.close();
    return 0;
}
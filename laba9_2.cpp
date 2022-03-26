#include <iostream>
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

void read_file(ifstream &infile){
    double v;
    infile.read(reinterpret_cast<char*>(&v),sizeof (double));
    while(!infile.eof()) {
        cout << v << endl;
        infile.read(reinterpret_cast<char*>(&v),sizeof(double));
    }
    cout << endl;
}


void createf(ofstream &outfile){
    for (int i = 0; i <= 10000; i++){
        double temp = i + 0.13;
        outfile.write(reinterpret_cast <char*> (&temp), sizeof (double));
    }
}

void createg(ofstream &outfile){
    for (int i = 0; i <= 10000; i += 5){
        double temp = 0;
        double decimal = 0.13;
        if(!(i % 2)){
            decimal = 0.26;
        }
        temp = i + decimal;
        outfile.write(reinterpret_cast <char*> (&temp), sizeof(double));
    }
}

void getnewfile(ifstream &f_file, ifstream &g_file){
    ofstream out;
    out.open("./new_file.bin", ios::binary);
    if(!out){
        cout << "Smt wrong AAA";
        return;
    }
    double fvalue = 0;
    double gvalue = 0;
    f_file.read(reinterpret_cast<char*>(&fvalue), sizeof(double));
    g_file.read(reinterpret_cast<char*>(&gvalue), sizeof(double));
    double lastAddedNum  = 0;
    while(f_file || g_file){
        if(fvalue < gvalue){
            if(f_file){
                f_file.read(reinterpret_cast<char*>(&fvalue), sizeof(fvalue));
            } else {
                g_file.read(reinterpret_cast<char*>(&gvalue), sizeof(double));
            }
        } else {
            if(g_file){
                g_file.read(reinterpret_cast<char*>(&gvalue), sizeof(double));
            } else {
                f_file.read(reinterpret_cast<char*>(&fvalue), sizeof(double));
            }
        }
        if(fvalue == gvalue && fvalue != lastAddedNum){
            out.write(reinterpret_cast <char*>(&fvalue), sizeof(double));
            lastAddedNum = fvalue;
        }
    }
    out.close();
    ifstream read_new("./new_file.bin", ios::binary);
    if(!read_new){
        cout << "Smt wrong! ";
        return;
    }
    read_file(read_new);
    read_new.close();
}

int main(){
    ofstream f_file("./f_file.bin", ios::binary);
    if(!f_file){
        cout << "Smt wrong!";
        return 0;
    }
    createf(f_file);
    f_file.close();
    ofstream g_file("./g_file.bin", ios::binary);
    if(!g_file){
        cout << "Smt wrong!";
        return 0;
    }
    createg(g_file);
    g_file.close();
    ifstream read_f("./f_file.bin", ios::binary);
    ifstream read_g("./g_file.bin", ios::binary);
    if (read_f && read_g){
        getnewfile(read_f, read_g);
    } else {
        cout << "Smt wrong 1212";
        return 0;
    }
    read_f.close();
    read_g.close();
    return 0;
}
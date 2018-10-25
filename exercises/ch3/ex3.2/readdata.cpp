/* 

   Exercise to read file and parse systemc literal values using stream input operator.
   
   Format output using to_string() method.

 */
#include <systemc.h>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

int sc_main(int sc_argc,  char *sc_argv[]) {
    vector< sc_uint<24> > data;
    ifstream datain;
    string line;
    datain.open("data.txt");
    unsigned int drop=0;
    
    if (datain.is_open()) {
        //while (getline(datain, line)) {
        while (!datain.eof()) {
            try {
                sc_uint<24> value;
                datain >> value;
                data.push_back(value);
            } catch (...) {
                drop++;
            }
        }
    }    
    datain.close();

    cout << "Read " << data.size() << " values, dropped " << drop << " entries\n";
    cout << "\n";
    
    cout << "DECIMAL VALUES\n";
    for (unsigned int i=0; i<data.size(); i++) {
        cout << data[i].to_string(SC_DEC) << "\n";
    }
    cout << "\n";

    cout << "HEX VALUES\n";
    for (vector< sc_uint<24> >::iterator i=data.begin(); i!=data.end(); i++) {
        cout << i->to_string(SC_HEX_SM) << "\n";
    }
    cout << "\n";

    
}

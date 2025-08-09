#include <iostream>
#include <systemc>

using namespace std;
using namespace sc_core;

// The objective is to use what's been covered up to now.
// The implementation relies on the simulator sceduling the tasks in
// the order of declaration.

SC_MODULE(printer) {
    SC_HAS_PROCESS(printer);
    printer(sc_module_name nm, 
            int count, 
            const std::string &label)
        : sc_module(nm)
        , _count(count)
        , _label(label)
    {
        SC_THREAD(print_status);
    }
    void print_status(void) {
        cout << _count << endl;
        cout << _label << endl;
    }
private: 
    const int _count;
    const std::string _label;
};


int sc_main(int argc, char* argv[]) {
    // ELABORATION
    printer ready("mod1",1, "Ready");
    printer set("mod2", 2, "Set");
    printer go("mod3", 3, "Go");
    sc_start();
    // POST PROCESSING
    return 0;
}

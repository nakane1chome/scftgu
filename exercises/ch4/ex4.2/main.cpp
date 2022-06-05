#include <iostream>
#include <systemc>

using namespace std;
using namespace sc_core;

SC_MODULE(basic_process_ex) {
    SC_HAS_PROCESS(basic_process_ex);
    basic_process_ex(sc_module_name nm) 
        : sc_module(nm)
    {
        SC_THREAD(my_thread_process);
    }
    void my_thread_process(void);
};

// Figure 4.11
void basic_process_ex::my_thread_process(void) {
    cout << "my_thread_process executed within " 
         << name() 
         << endl;
}

// Figure 4.2, Figure 4.12
int sc_main(int argc, char* argv[]) {
    // ELABORATION
    basic_process_ex my_instance("my_instance");
    cout << "Elaboration has completed..\n";
    sc_start();
    cout << "Simulation has started.\n";
    // POST PROCESSING
    return 0;
}

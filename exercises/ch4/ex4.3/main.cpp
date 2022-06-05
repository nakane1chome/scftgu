#include <iostream>
#include <systemc>

using namespace std;
using namespace sc_core;

SC_MODULE(basic_process_ex) {
    SC_HAS_PROCESS(basic_process_ex);
    basic_process_ex(sc_module_name nm) 
        : sc_module(nm)
    {
        SC_THREAD(my_thread_process1);
        SC_THREAD(my_thread_process2);
    }
    void my_thread_process1(void);
    void my_thread_process2(void);
};

// Figure 4.11
void basic_process_ex::my_thread_process1(void) {
    cout << "my_thread_process1 executed within " 
         << name() 
         << endl;
}
void basic_process_ex::my_thread_process2(void) {
    cout << "my_thread_process2 executed within " 
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

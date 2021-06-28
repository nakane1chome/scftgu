#define SC_INCLUDE_DYNAMIC_PROCESSES
#include <systemc>

#include <iostream>

using namespace std;
using namespace sc_core;

void spawned_thread() {// This will be spawned
    cout << "INFO: spawned_thread "  
         << sc_get_current_process_handle().name()
         << " @ " << sc_time_stamp() << endl;
    wait(10, SC_NS);
    cout << "INFO: exiting" << endl;
}

SC_MODULE(simple_spawn) {

  SC_CTOR(simple_spawn) {
    SC_THREAD(main_thread);
    
  }
  
  void main_thread(void);
};

void simple_spawn::main_thread() {
    wait(15, SC_NS);
    // Unused handle discarded
    sc_spawn(sc_bind(&spawned_thread));
    cout << "INFO: main_thread "  << name()
        << " @ " << sc_time_stamp() << endl;
    wait(15, SC_NS);
    cout << "INFO: main_thread stopping "  << name()
        << " @ " << sc_time_stamp() << endl;

}


int sc_main(int sc_argc,  char *sc_argv[]) {

  simple_spawn process0("process0");

  std::cout << "Elaboration complete...\n";
  
  sc_start();

  return 0;
  
}

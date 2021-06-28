#include <systemc.h>
#include <iostream>
#include "ex4.2_basic_process_ex.hpp"

SC_HAS_PROCESS(basic_process_ex) ;

basic_process_ex::basic_process_ex(sc_module_name name)
  : sc_module(name) {

  SC_THREAD(my_thread_ex);
}

void basic_process_ex::my_thread_ex(void)  {

  std::cout << "thread: my_thread_ex, "
	    << "module: basic_process_ex, "
	    << "instance: " << name() << "\n";
  
}

int sc_main(int sc_argc,  char *sc_argv[]) {

  basic_process_ex process0("process0");
  basic_process_ex process1("process1");

  std::cout << "Elaboration complete...\n";
  
  sc_start();

  return 0;
  
}



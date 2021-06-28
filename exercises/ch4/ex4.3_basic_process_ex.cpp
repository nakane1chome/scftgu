#include <systemc.h>
#include <iostream>
#include "ex4.3_basic_process_ex.hpp"

SC_HAS_PROCESS(basic_process_ex) ;

basic_process_ex::basic_process_ex(sc_module_name name)
  : sc_module(name) {

  SC_THREAD(my_thread_ex0);
  SC_THREAD(my_thread_ex1);
}

void basic_process_ex::my_thread_ex0(void)  {

  std::cout << "thread: my_thread_ex0, "
	    << "module: basic_process_ex, "
	    << "instance: " << name() << "\n";
  
}

void basic_process_ex::my_thread_ex1(void)  {

  std::cout << "thread: my_thread_ex1, "
	    << "module: basic_process_ex, "
	    << "instance: " << name() << "\n";
  
}

int sc_main(int sc_argc,  char *sc_argv[]) {

  basic_process_ex process0("process0");

  std::cout << "Elaboration complete...\n";
  
  sc_start();

  return 0;
  
}



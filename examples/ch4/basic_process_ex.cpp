#include <systemc.h>
#include <iostream>
#include "basic_process_ex.hpp"

void basic_process_ex::my_thread_ex(void)  {

  std::cout << "thread: my_thread_ex,"
	    << "module: basic_process_ex, "
	    << "instance: " << name() << "\n";
  
}

int sc_main(int sc_argc,  char *sc_argv[]) {

  basic_process_ex process0("process0");

  std::cout << "Elaboration complete...\n";
  
  sc_start();

  return 0;
  
}

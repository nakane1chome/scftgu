#include <iostream>
#include <systemc>

#include "engine_cylinder.hpp"

using namespace sc_core;
using namespace std;

int sc_main(int argc, char* argv[]) {
  sc_set_time_resolution(1,SC_US);
  sc_set_default_time_unit(1,SC_MS);

  cout << "Time resolution is " << sc_get_time_resolution() << endl;
  cout << "Default time unit is " << sc_get_default_time_unit() << endl;

  engine_cylinder cylinder0("cylinder0", 800);

  cout << "Starting engine cylinder simulation" << endl;
  sc_start(1, SC_SEC);
  cout << "Completed engine cylinder simulation" << endl;

  return 0;
}


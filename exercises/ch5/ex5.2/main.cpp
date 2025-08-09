//BEGIN main.cpp
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See time_flies.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc>
using std::cout;
using std::endl;
#include "time_flies.h"
using namespace sc_core;

int sc_main(int argc, char* argv[]) {
  sc_set_time_resolution(1,SC_FS);
  sc_set_default_time_unit(1,SC_SEC);
  cout << "Time resolution is " << sc_get_time_resolution() << endl;
  cout << "Default time unit is " << sc_get_default_time_unit() << endl;
  time_flies time_flies_i("time_flies_i");
  cout << "Starting time_flies simulation" << endl;
  sc_start();
  cout << "Exiting time_flies simulation." << endl;
  cout << "Simulator finished at " << time_flies_i.display_dhms(sc_time_stamp());
  cout << endl;
  // Nothing to fail, so we exit with an unconditional OK
  return 0;
}


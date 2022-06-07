//BEGIN time_flies.cpp
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See time_flies.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include <iomanip>
using std::cout;
using std::setw;
using std::endl;
#include <systemc>
#include <sstream>
#include <string>
using namespace sc_core;
#include "time_flies.h"

void time_flies::time_thread(void) {
  cout << "INFO: Time resolution is " << sc_get_time_resolution() << endl;
  // Start big, go small
  uint64_t raw_time = UINT64_MAX;
  cout << "INFO: Start time is " << display_dhms(sc_time_stamp()) << "!" << endl;
  do {
      sc_time wait_time(double(raw_time) * sc_get_time_resolution().to_seconds(), SC_SEC);
      cout << "INFO: Delaying " << display_dhms(wait_time) << " ";
      wait(wait_time);
      cout << "INFO: Time is " << display_dhms(sc_time_stamp()) << "!" << endl;
      // Divide by 2 until it's all gone
      raw_time >>= 1;
  } while (raw_time != 0);
  cout << "INFO: Time still " << display_dhms(sc_time_stamp()) << "!" << endl;
  #ifdef USE_STOP
  cout << "INFO: Simulation will stop at the current time." << endl;
  sc_stop();
  #else
  cout << "INFO: Simulation will now proceed to limit specified by sc_start()" << endl;
  cout << "----: which is \"the maximum simulation time allowed\"." << endl;
  #endif
}//end time_thread()

std::string time_flies::display_dhms(const sc_time &t_in) {
    double t = t_in.to_seconds();
    unsigned days = int(t/(3600.0*24));
    t -= days * 3600.0*24;
    unsigned hours   = int(t / 3600.0);
    t -= hours * 3600.0;
    unsigned minutes = int(t / 60.0);
    t -= minutes * 60.0;
    double   seconds = t;
    std::ostringstream mout;
    mout << std::dec 
         << days << "d " 
         << hours << "h " 
         << minutes << "m " 
         << std::fixed << seconds << "s";
    return mout.str();
}



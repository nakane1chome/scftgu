#include <systemc.h>

SC_MODULE(basic_process_ex) {

  SC_CTOR(basic_process_ex) {
    SC_THREAD(my_thread_ex);
    
  }

  void my_thread_ex(void);

  
};

#include <systemc.h>
#include <iostream>


SC_MODULE(counter) {

  SC_CTOR(counter);
  
  void my_thread_ex0(void);
  void my_thread_ex1(void);
  void my_thread_ex2(void);
  void decrement(void);

 private :
  unsigned int _count;
  
};


SC_HAS_PROCESS(counter) ;

counter::counter(sc_module_name name)
  : sc_module(name)
  , _count(3)
{

  // Each thread decrements by 1 and exits.
  SC_THREAD(my_thread_ex0);
  SC_THREAD(my_thread_ex1);
  SC_THREAD(my_thread_ex2);
}

void counter::my_thread_ex0(void)  {
  decrement();
}
void counter::my_thread_ex1(void)  {
  decrement();
}
void counter::my_thread_ex2(void)  {
  decrement();
}

void counter::decrement(void)  {
  std::cout << _count << "...";
  switch (_count) {
  case 3 : std::cout << "Ready..";
    break;
  case 2 : std::cout << "Set..";
    break;
  case 1 : std::cout << "Go!";
    break;
  }
  std::cout << _count << "\n";
  _count --;
}

int sc_main(int sc_argc,  char *sc_argv[]) {

  counter process0("process0");

  std::cout << "Elaboration complete...\n";
  
  sc_start();

  return 0;
  
}



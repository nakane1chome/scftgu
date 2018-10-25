/*

Exercise to demonstrate the performance difference for c++ primative
data types vs system c custom types.

Performance measurement is inbuilt for unix-like OS via getrusage().

 */

#define SC_INCLUDE_FX

#include <systemc.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <locale>

#include <stdio.h>
#include <stdlib.h>

#ifdef __unix__
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>
#endif

enum {
  ITERATIONS=100000,
  ARRAY_SIZE=1000,
};

using namespace std;

template<class T> T gen_rand(void) {
  // This could be much smarter for custom types, for this example the
  // aim is consistency. Performance could be measured with
  // uninitialized data.
  return (T) rand();
}


// Allocate array for input
template<class T > void generate_data(std::vector<T> &out, size_t count) {
    out.resize(count);
    for (size_t i=0; i<count; i++) {
        out[i] = gen_rand<T>();
    }
}

// Calculate squares of array of random data
template<class T> void squares(size_t count) {
    std::vector<T> data_in;
    std::vector<T> data_out(count);
    generate_data<T>(data_in, count);
    for (size_t i=0; i<count; i++) {
        data_out[i] = data_in[i] * data_in[i];
    }
}

// Function to pass to performance measurement function
typedef void (*squares_fn)(size_t count);

// Takes a function, interates several times and measures the performance.
// OS will need to tick over a few times to mesure, so using a large number of interations .
void run_and_time(const char *name, squares_fn fn)  {
  SC_REPORT_INFO("run_and_time_start", name);
#if __unix__
  static uint64_t first_time=0;
  struct rusage start_runtime;
  struct rusage end_runtime;
  if (getrusage(RUSAGE_SELF, &start_runtime) < 0) {
    perror("Could not get start resource usage");
  }
#endif
  for (unsigned int i=0; i< ITERATIONS; i++) {
    fn(ARRAY_SIZE);
  }
#if __unix__
  if (getrusage(RUSAGE_SELF, &end_runtime) < 0) {
    perror("Could not get start resource usage");
  }
  uint64_t ru_utime_diff_usec =
    (end_runtime.ru_utime.tv_usec - start_runtime.ru_utime.tv_usec) +
    (end_runtime.ru_utime.tv_sec - start_runtime.ru_utime.tv_sec)*1000000;
  if (first_time==0) {
    first_time = ru_utime_diff_usec;
  }
  double slowdown=(double)ru_utime_diff_usec/(double)first_time;
  std::ostringstream msg;
  msg.imbue(std::locale(""));
  msg << ru_utime_diff_usec;
  msg << " (" << slowdown << "x slower)";
  SC_REPORT_INFO("run_and_time_usec", msg.str().c_str());

#endif
  SC_REPORT_INFO("run_and_time_end", name);
}


// For each data type, Get a pointer to the template function instance
// and pass it to the measurement function.

int sc_main(int sc_argc,  char *sc_argv[]) {
  squares_fn squares_uint8 = &squares<uint8_t>;
  squares_fn squares_uint = &squares<unsigned int>;
  squares_fn squares_float = &squares<float>;
  squares_fn squares_double = &squares<double>;
  squares_fn squares_sc_int_8 = &squares<sc_int<8> >;
  squares_fn squares_sc_uint_19 = &squares<sc_uint<19> >;
  squares_fn squares_sc_bigint_8 = &squares<sc_bigint<8> >;
  squares_fn squares_sc_bigint_100 = &squares<sc_bigint<100> >;
  squares_fn squares_sc_fixed_12_12 = &squares<sc_fixed<12,12> >;
  run_and_time("uint8_t", squares_uint8);
  run_and_time("unsigned int", squares_uint);
  run_and_time("float", squares_float);
  run_and_time("double", squares_double);
  run_and_time("sc_int<8>", squares_sc_int_8);
  run_and_time("sc_uint<19>", squares_sc_uint_19);
  run_and_time("sc_bigint<8>", squares_sc_bigint_8);
  run_and_time("sc_bigint<100>", squares_sc_bigint_100);
  run_and_time("sc_fixed<12,12>", squares_sc_fixed_12_12);

  
  return 0;
}

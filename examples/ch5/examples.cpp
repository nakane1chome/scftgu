#include <systemc>

// 5.1 sc_time

// Figure 5.1

sc_time name1;
sc_time name2(/*double*/, /*sc_time_unit*/);
sc_time name3(/*const sc_time & */); 

// 5.1.1 SystemC Time Resolution 

// Figure 5.2
// Postitive power of ten for resolution
sc_set_time_resolution(/*double*/, /*sc_time_unit*/);

// 5.1.2 Working with sc_time

// Table 5.2
// sc_time operators: == != < <= > >=
// + - * /
// = += -= *= /=

// Figure 5.3
sc_time t_PERIOD(5, SC_NS);
sc_time t_TIMEOUT(100, SC_MS);
sc_time t_MEASURE, t_CURRENT, t_LAST_CLOCK;
if (t_MEASURE > t_HOLD) { error("Setup Violated."); }

// Figure 5.4
ostream_object << desired_sc_time_object;

// 5.2 sc_time_stamp()

// Figure 5.5
sc_time current_time = sc_time_stamp();

// Figure 5.6
cout << " The time is now "
     << sc_time_stamp()
     << "!" << endl;

// Figure 5.7
"The time is now 0 ns!";

// 5.3 sc_start()

// Figure 5.8

// sim "forever"
sc_start();
// sim no more than max_sc_time
sc_start(const sc_time& max_sc_time);
// sim no more than max_time time_units
sc_start(double max_time, sc_time_unit time_unit);

// Figure 5.9

// FILE: main.cpp
int sc_main(int argc, char *argv[]) {
    basic_process_ex my_instance("my_instance");
    sc_start(60.0, SC_SEC);
    return 0;
}

// 5.4 wait(sc_time)

// Figure 5.10
wait(delay_sc_time);

// Figure 5.10

// FILE: wait_ex.cpp
void wait_ex::my_thread_process(void) {
    wait(10, SC_NS);
    cout << "Not at " << sc_time_stamp() << endl;
    sctime t_DELAY(2, SC_MS);
    t_DELAY *= 2;
    cout << "Delaying " << t_DELAY << endl;
    wait(t_DELAY);
    cout << "Now at " << sc_time_stamp() << endl;
}

// Figure 5.12
int sc_main(int argc, char *argv[]) {
    sc_set_time_resolutiom(1, SC_MS);
    basic_process_ex my_instance("my_intance");
    sc_start(7200, SC_SEC); // Limit simulation to 2 hours (or 7200 secs)
    double t = sc_time_stamp(); // max i 7200 x 10**3
    unsigned hours = int(t / 3600.0);
    t -= 3600.0;
    unsigned minutes = int(t / 60.0);
    t -= 60.0*minutes;
    double seconds = t;
    cout << hours << "hours "
         << minutes << "minutes "
         << seconds << "seconds " // to the nearest ms
         << endl;
    return 0;
}

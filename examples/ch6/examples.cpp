// Fig 6.3 Two processes using wait()

// FILE: two_processes.h
SC_MODULE(two_processes) {
    void wiper_thread(void);
    void blinker_thread(void);
    SC_CTOR(two_processes) {
        SC_THREAD(wiper_thread);
        SC_THREAD(blinker_thread);
    }
};

// FILE: two_processes.cpp
void two_processes::wiper_thread(void) {
    while (true) {
        wipe_left();
        wait(500, SC_MS);
        wipe_right();
        wait(500, SC_MS);
    }
}
void two_processes::blinker_thread(void) {
    while(true) {
        blinker = true;
        cout << "Blink ON" << endl;
        wait(300, SC_MS);
        cout << "Blink OFF" << endl;
        blinker = false;
        wait(300, SC_MS);
    }
}

// Fig 6.13
event_name.notify(void);
event_name.notify(SC_ZERO_TIME);
event_name.notify(sc_time);
event_name.notify(double, units);
// Fig 6.14
sc_event A_event;
A_event.notify(10, SC_NS);
// Fig 6.15
event_name.cancel();

// Fig 6.16
wait(time);
wait(double, time_unit);
wait(event);
wait(event1 | event2);
wait(event1 & event2);
wait(time, event);
wait(); // static sensitivity

// Fig 6.17
sc_event ack_event, bus_error_event;
sc_time start_time(sc_time_timestamp());
wait(t_MAX_DELAY, ack_event | bus_error_event);
if (sc_time_stamp()-start_time == t_MAX_DELAY)
  break; // path for a timeout

// Figure 6.18
if (ack_event) do_something; // Illegal 
// Cannot test for event that occured. 

// Figure 6.20
SC_MODULE(missing_event) {
    SC_CTOR(missing_event) {
        SC_THREAD(B_thread); // ordered to cause
        SC_THREAD(A_thread); // problems
        SC_THREAD(C_thread);
    }
    void A_thread() {
        a_event.notify();
        cout << "A Sent an a_event!" << endl;
    }
    void B_thread() {
        wait(a_event);
        cout << "B got a_event!" << endl;
    }
    void C_thread() {
        wait(a_event);
        cout << "C got a_event!" << endl;
    }
    sc_event a_event;
};

// Figure 6.21
SC_MODULE(missing_event) {
    SC_CTOR(missing_event) {
        SC_THREAD(B_thread); // ordered to cause
        SC_THREAD(A_thread); // problems
        SC_THREAD(C_thread);
    }
    void A_thread() {
        while(true) {
            a_event.notify(SC_ZERO_TIME);
            cout << "A Sent an a_event!" << endl;
            wait(c_event);
            cout << "A got an c_event!" << endl;
        }
    }
    void B_thread() {
        while (true) {
            b_event.notify(SC_ZERO_TIME);
            cout << "B sent b_event!" << endl;
            wait(a_event);
            cout << "B got a_event!" << endl;            
    }
    void C_thread() {
        while (true) {
            c_event.notify(SC_ZERO_TIME);
            cout << "C sent c_event!" << endl;
            wait(b_event);
            cout << "C got b_event!" << endl;
        }
    }
    sc_event a_event, b_event, c_event;
};

#include <systemc.h>

// Figure 4.4
SC_MODULE(module_name) {
    // MODULE BODY
};

// Figure 4.6
class module_name : public sc_module {
    public:
    // MODULE BODY
};

// Figure 4.7
SC_MODULE(module_name) {
    SC_CTOR(module_name) 
        : // Init list
        {
            // Subdesign allocation
            // Subdesign connectivity
            // Process Registration
            // Misc Setup
        }
}

// Figure 4.10
SC_MODULE(basic_process_ex) {
    SC_CTOR(basic_process_ex) {
        SC_THREAD(my_thread_process);
    }
    void my_thread_process(void);
};

// Figure 4.11
void basic_process_ex::my_thread_process(void) {
    cout << "my_thread_process executed withing" 
         << name() 
         << endl;
}

// Figure 4.14
// File: module_name.h
SC_MODULE(module_name) {
    SC_HAS_PROCESS(module_name);
    module_name(sc_module_name 
                instname // [,other args..]
        ) : sc_module(instname)
        // [,other init]
    {
        // Constructor body
    }
};

// Figure 4.15
// File: module_name.h
SC_MODULE(module_name) {
    module_name(sc_module_name 
                instname // [,other args..]
        );
};

// Figure 4.16
// File: module_name.cpp
SC_HAS_PROCESS(module_name);
module_name::module_name(sc_module_name 
                         instname // [,other args..]
    ) : sc_module(instname)
        // [,other init]
{
    // Constructor body
}

// Figure 4.2, Figure 4.12
int sc_main(int argc, char* argv[]) {
    // ELABORATION
    basic_process_ex my_instance("my_instance");
    sc_start();
    // POST PROCESSING
    return 0;
}

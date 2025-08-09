#ifndef ENGINE_CYLINDER_HPP
#define ENGINE_CYLINDER_HPP

#include <systemc>

SC_MODULE(engine_cylinder) {
    engine_cylinder(sc_core::sc_module_name nm, 
                    unsigned int default_rpm);
    void combustion_process(void);
    // Revolution rate of the engine.
    unsigned int rpm;
};

#endif



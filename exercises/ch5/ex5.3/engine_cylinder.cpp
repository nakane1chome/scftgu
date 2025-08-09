#include <iostream>
#include <systemc>

#include "engine_cylinder.hpp"

using namespace sc_core;
using namespace std;

SC_HAS_PROCESS(engine_cylinder);
engine_cylinder::engine_cylinder(sc_module_name nm, 
                unsigned int default_rpm) 
    : sc_module(nm)
    , rpm(default_rpm)
{
    SC_THREAD(combustion_process);
}


// Names of they high level cycles.
static const char *CYCLES[4] = {
    "Intake",
    "Compression",
    "Power",
    "Exhaust",
};
// Rotation (in degrees) of each stage.
// 0 to terminate
struct stage {
    const char *name;
    unsigned int angle;
};
// See https://en.wikipedia.org/wiki/Otto_cycle
static const struct stage STAGES[4][3] = {
    { // Intake
        {"Intake Valve open",15+10},
        {"Exhaust valve closes", 180+30-10},
        {0,0},
    },
    { // Compression
        {"Intake Valve closes",180-30-30},
        {"Ignition",30},
        {0,0},
    },
    { // Expansion
            {"Explosion",180-45},
            {0,0},
    },
    { // Exhaust
        {"Exhaust valve opens", 45+180-15},
        {0,0},
    }   
};

void engine_cylinder::combustion_process(void) {
    unsigned int strokes = 0;
    while (true) {
        const sc_time cycle_time(60.0 / rpm, SC_SEC);
        const sc_time degree_time = cycle_time/360;
        for (unsigned int i=0; i<4; i++) {
            strokes ++;
            cout << "+ " << strokes << ": START CYCLE: " << i << ": " << CYCLES[i] << "\n";
            unsigned int j=0;
            while (STAGES[i][j].name!=0) {
                const sc_time delay = degree_time * STAGES[i][j].angle;
                cout << "@" << sc_time_stamp() << endl;
                cout << STAGES[i][j].name << "\n";
                wait(delay);
                j++;
            }
            cout << "+ " << strokes << ": END CYCLE: " << i << ": " << CYCLES[i] << "\n";
        }
    }
}

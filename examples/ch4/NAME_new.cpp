// Figure 4.17 Traditional style NAME.cpp
#include <systemc>
#include "NAME.h"

SC_HAS_PROCESS(NAME);
NAME::NAME(sc_module_name nm) 
    : sc_module(nm)
{
    // Channel allocations
    // Submodue allocations
    // Connectivity
    // Process registrations
}

void NAME::process(void) {
    // ...
}
void NAME::helper(void) {
    // ..
}

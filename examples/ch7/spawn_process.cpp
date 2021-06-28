#define SC_INCLUDE_DYNAMIC_PROCESS
#include <systemc>

void inject(void);

int count_changes(sc_signal<int>& sig);

class TestChan : public sc_module {
    bool Track(sc_signal<packet> &pkt);
    void Errors(int maxwarn, int maxerr);
    void Speed(void);
};


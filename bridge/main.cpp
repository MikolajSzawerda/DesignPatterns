#include <iostream>
#include "Types.h"
int main() {
    Radio r;
    TV t;
    Remote radio_pilot(r);
    Remote tv_pilot(t);

    radio_pilot.togglePower();
    tv_pilot.togglePower();

    tv_pilot.channelUp();
    radio_pilot.channelDown();
    return 0;
}


#include "Scheduler.h"

// ------------
//   PUBLIC
// ------------

Scheduler::Scheduler(unsigned long timeout) : timeout(timeout) { }

void Scheduler::start(){
    started = true;
    prev_time = millis();
}

void Scheduler::stop(){
    started = false;
}

bool Scheduler::hasTimeoutHappened(){
    return started && ((unsigned long)(millis() - prev_time) >= timeout);
}


// ------------
//   PRIVATE
// ------------
 

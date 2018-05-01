#ifndef _Scheduler_H
#define _Scheduler_H

#include "Arduino.h" 

class Scheduler {
public:
    Scheduler(unsigned long timeout);
    
    void start();
    void stop();
    bool hasTimeoutHappened();

private:
    bool started;
    unsigned long prev_time;
    unsigned long timeout;

};

#endif  // _Scheduler_H 

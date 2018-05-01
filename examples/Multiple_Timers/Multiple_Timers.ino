#include <Scheduler.h>

#define TIMEOUT_0 733
#define TIMEOUT_1 1113

// create timer with timeout of TIMEOUT
Scheduler timer0(TIMEOUT_0);
Scheduler timer1(TIMEOUT_1);

void setup() {
  // serial PC comm  
  Serial.begin(9600);
  // start timers
  timer0.start();
  timer1.start();
}

void loop() {
  // if we have a timeout since the start of the timer, 
  // then execute the following
  if (timer0.hasTimeoutHappened()){
    // Blink LED and display the timeout in the serial monitor
    Serial.println("TIMER 0 - Hey There Fella. I run faster than my mate below.");        
    // restart the timer counters (this if will execute in the 
    // next TIMEOUT interval)
    timer0.start();
  }  
  if (timer1.hasTimeoutHappened()){
    // Blink LED and display the timeout in the serial monitor
    Serial.println("TIMER 1 - Arduino Rocks !!! I'm slow but I do stuff too...");        
    Serial.println("");
    // restart the timer counters (this if will execute in the 
    // next TIMEOUT interval)
    timer1.start();
  } 
}

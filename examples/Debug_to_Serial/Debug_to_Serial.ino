#include <Scheduler.h>

#define TIMEOUT 1200

// create timer with timeout of TIMEOUT
Scheduler timer(TIMEOUT);

void setup() {
  // serial PC comm  
  Serial.begin(9600);
  // start the timer here
  timer.start();
}

void loop() {
  // if we have a timeout since the start of the timer, 
  // then execute the following
  if (timer.hasTimeoutHappened()){
    // Blink LED and display the timeout in the serial monitor
    Serial.println("We are running async here! We can display debug data now.");        
    // restart the timer counters (this if will execute in the 
    // next TIMEOUT interval)
    timer.start();
  }  
}

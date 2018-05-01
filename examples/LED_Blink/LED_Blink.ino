#include <Scheduler.h>

#define LED     13
#define TIMEOUT 1000

// create timer with timeout of TIMEOUT
Scheduler timer(TIMEOUT);

void setup() {
  // start LED as output and start the serial PC comm
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  // start the timer here
  timer.start();
}

void loop() {
  // keep LED off
  digitalWrite(LED, LOW);    
  // if we have a timeout since the start of the timer, 
  // then execute the following
  if (timer.hasTimeoutHappened()){
    // Blink LED and display the timeout in the serial monitor
    Serial.println("Timeout - LED Blinking");
    digitalWrite(LED, HIGH);
    delay(1250);    
    // stop the timer (this if will not execute anymore)
    timer.stop();
  }  
}

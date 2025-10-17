// 🚦 Ambulance Priority Traffic Signal Simulation

// Pin Definitions
int red = 13;       // Red LED
int yellow = 12;    // Yellow LED
int green = 11;     // Green LED
int switchPin = 2;  // Slide switch
int buzzer = 4;     // Buzzer

void setup() {
  // Initialize LEDs and buzzer
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  // Initialize switch (slide switch acts as HIGH/LOW input)
  pinMode(switchPin, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  int switchState = digitalRead(switchPin); // Read switch state

  if (switchState == HIGH) { // Switch ON → Ambulance detected
    Serial.println("Ambulance detected! Giving green signal...");
    
    // 🚨 Activate buzzer + Green light immediately
    digitalWrite(buzzer, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(green, HIGH);

    // Turn off buzzer after delay
    digitalWrite(buzzer, LOW);
  } 
  else {
    // 🕒 Normal traffic light cycle
    digitalWrite(buzzer, LOW);

    digitalWrite(red, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);
    delay(4000);

    digitalWrite(red, LOW);
    digitalWrite(yellow, HIGH);
    delay(1000);

    digitalWrite(yellow, LOW);
    digitalWrite(green, HIGH);
    delay(4000);

    digitalWrite(green, LOW);
  }
}

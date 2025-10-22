int red = 13;
int yellow = 12;
int green = 11;
int switchPin = 2;
int buzzer = 4;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int switchState = digitalRead(switchPin);

  if (switchState == HIGH) { // Ambulance detected
    Serial.println("Ambulance detected! Green light ON!");
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(3000); // Green + buzzer duration
    digitalWrite(buzzer, LOW);
  } 
  else {
    // Normal traffic sequence
    digitalWrite(red, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);
    digitalWrite(buzzer, LOW);
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

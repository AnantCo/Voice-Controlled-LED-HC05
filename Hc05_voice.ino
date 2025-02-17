int Green = 3;
int Yellow = 4;
int Red = 5;

void setup() {
  Serial.begin(9600);
  pinMode(Green, OUTPUT);
  pinMode(Yellow, OUTPUT);
  pinMode(Red, OUTPUT);

  // Ensure all LEDs are off initially
  digitalWrite(Green, LOW);
  digitalWrite(Yellow, LOW);
  digitalWrite(Red, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    String voice = Serial.readString(); // Read the entire string
    voice.trim(); // Remove spaces
    voice.toLowerCase(); // Convert to lowercase for consistency

    Serial.println("Command Received: " + voice);

    if (voice == "green") {
      digitalWrite(Green, HIGH);
    } else if (voice == "green off") {
      digitalWrite(Green, LOW);
    } else if (voice == "yellow") {
      digitalWrite(Yellow, HIGH);
    } else if (voice == "yellow off") {
      digitalWrite(Yellow, LOW);
    } else if (voice == "red") {
      digitalWrite(Red, HIGH);
    } else if (voice == "red off") {
      digitalWrite(Red, LOW);
    } else {
      Serial.println("Unknown Command!");
    }
  }
}

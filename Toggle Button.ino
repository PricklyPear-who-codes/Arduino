// Define the button pin
const int buttonPin = 2;
// Variable for the button's last state
int lastButtonState = LOW;
// Variable for the current state of the button
int currentButtonState;
// Define the toggler variable
int toggleNumber;
// Variable for the output pin
const int outputPin = 7;

void setup() {
  // Initialize the button pin as an input
  toggleNumber = 0;
  pinMode(buttonPin, INPUT);
  pinMode(outputPin, OUTPUT);
  digitalWrite(outputPin, LOW);
  Serial.begin(9600);
  Serial.println("Off");
}

void loop() {
  // Read the current state of the button
  currentButtonState = digitalRead(buttonPin);

  // Compare the button's current state to its previous state
  if (currentButtonState != lastButtonState) {
    // If the state has changed and the current state is HIGH, the button was pressed and the toggle number is zero
    if (currentButtonState == HIGH && toggleNumber == 0) {
      // Turn on if the button state is High and the number is zero
      Serial.println("On");
      digitalWrite(outputPin, HIGH);
      // Change the number so this same block doesn't happen every time
      toggleNumber = 1;
    } else {
      // If the button state is High and the number is 1
      if (currentButtonState == HIGH && toggleNumber == 1) {
        // Turn off if the button state is High and the number is one
        Serial.println("Off");
        digitalWrite(outputPin, LOW);
        // Change the number so this block doesn't happen everytime after the first one
        toggleNumber = 0;
      }
    }
    // Update the last button state
    lastButtonState = currentButtonState;
  }

  // Other code here

  // Delay a little bit to avoid bouncing
  delay(50);
}

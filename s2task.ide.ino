const uint8_t BTN_PIN = 2;
const uint8_t LED_PIN = 13;

uint8_t buttonPrevState = LOW;
uint8_t ledState = LOW;

void setup()
{
  // Initialize button pin as input with pull-up resistor
  pinMode(BTN_PIN, INPUT_PULLUP);
  
  // Initialize LED pin as output
  pinMode(LED_PIN, OUTPUT);
  
  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop()
{
  // Read the current state of the button
  uint8_t buttonState = digitalRead(BTN_PIN);
  
  // Print button state, previous button state, and LED state for debugging
  Serial.print("Button State: ");
  Serial.print(buttonState);
  Serial.print(" | Previous State: ");
  Serial.print(buttonPrevState);
  Serial.print(" | LED State: ");
  Serial.println(ledState);
  
  // If the button state changes, toggle the LED
  if(buttonState != buttonPrevState)
  {
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
  }
  
  // Update the previous button state
  buttonPrevState = buttonState;
    
  // Add a delay to avoid rapid toggling and improve readability in the serial monitor
  delay(500);
}

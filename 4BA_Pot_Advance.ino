int input;
String inputString = "";   // A string to hold incoming data
bool stringComplete = false;  // Whether the string is complete
int inputValue = 0;  // Variable to store the integer value
 
void setup() {
    Serial.begin(9600); 
    delay(2000);  
 
    Serial.println("Type something!");
}
 
void loop() {
  if (stringComplete) {
        // Convert the string to an integer
        inputValue = inputString.toInt();
        
        // Print the integer value
        Serial.print("You typed: ");
        Serial.println(inputValue);

        // Clear the string and reset the flag
        inputString = "";
        stringComplete = false;
    }

    // Read incoming serial data
    while (Serial.available()) {
        char inChar = (char)Serial.read();
        
        // If you get a newline, set the flag
        if (inChar == '\n') {
            stringComplete = true;
        } else {
            // Add the character to the input string
            inputString += inChar;
        }
    }
}
//This Code is Pushed in GITHUB and link is: https://github.com/Dharmik3107/4BA_Pot_Advance_GR.git
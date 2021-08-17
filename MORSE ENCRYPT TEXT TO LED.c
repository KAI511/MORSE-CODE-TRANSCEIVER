unsigned int led_pin = 12;

char *letters[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",    
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",  
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."         
};
 
char *numbers[] = {
  "-----", ".----", "..---", "...--", "....-", ".....", "-....", 
  "--...", "---..", "----."
};
 
unsigned int dot_duration = 100;
bool done = false;
 

void setup() {
  pinMode(led_pin, OUTPUT);
   
  
  Serial.begin(9600); 
   
  
  Serial.println("MORSE CODE LED PROGRAM");
  Serial.println("Enter your message(s) or ! to exit: ");
}
 

void loop() {
  char ch;
   
 
  while (!done) {
   
    if (Serial.available()) {     
   

      ch = Serial.read();    
   

      if (ch >= 'A' && ch <= 'Z') {
        Serial.println(ch);
        flash_morse_code(letters[ch - 'A']); 
        Serial.println(letters[ch - 'A']);
      }

      else  if (ch >= 'a' && ch <= 'z') {
        Serial.println(ch);
        flash_morse_code(letters[ch - 'a']);
        Serial.println(letters[ch - 'a']);
      }

      else if (ch >= '0' && ch <= '9') {
        Serial.println(ch);
        flash_morse_code(numbers[ch - '0']);
        Serial.println(numbers[ch - '0']);
      }
      else if (ch == ' ') {
       
        delay(dot_duration * 7);       
      }
      else if (ch == '!') {
        done = true;  
        Serial.println("Thank you! Your messages were sent successfully.");
        Serial.println("Goodbye.");
      }
    }     
  }  
  while(true) {}
}
 

void flash_morse_code(char *morse_code) {
    
  unsigned int i = 0;
    
  while (morse_code[i] != NULL) {
    flash_dot_or_dash(morse_code[i]);
    i++;
  }
    
  delay(dot_duration * 3);    
}
 

void flash_dot_or_dash(char dot_or_dash) {
   
  digitalWrite(led_pin, HIGH);
   
  if (dot_or_dash == '.') { 
    delay(dot_duration);           
  }
  else { 
    delay(dot_duration * 3);           
  }
   
  digitalWrite(led_pin, LOW);
 
  
  delay(dot_duration); 
}
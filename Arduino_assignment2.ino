

const int buzzerElement = 8; 


const int displayPins[] = {2, 3, 4, 5, 6, 7, 9};
const int totalSegments = 7;


const byte segmentMatrix[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, 
  {0, 1, 1, 0, 0, 0, 0}, 
  {1, 1, 0, 1, 1, 0, 1}, 
  {1, 1, 1, 1, 0, 0, 1}, 
  {0, 1, 1, 0, 0, 1, 1}, 
  {1, 0, 1, 1, 0, 1, 1}, 
  {1, 0, 1, 1, 1, 1, 1}, 
  {1, 1, 1, 0, 0, 0, 0}, 
  {1, 1, 1, 1, 1, 1, 1}, 
  {1, 1, 1, 1, 0, 1, 1}  
};

 
void clearAndShowDigit(int currentDigit) {
  if (currentDigit < 0 || currentDigit > 9) return;
  
  for (int segment = 0; segment < totalSegments; segment++) {
    digitalWrite(displayPins[segment], segmentMatrix[currentDigit][segment]);
  }
}

void setup() {
  Serial.begin(9600);
  Serial.println("--- Starting Hardware Countdown Execution ---");

  
  pinMode(buzzerElement, OUTPUT);
  for (int pinIndex = 0; pinIndex < totalSegments; pinIndex++) {
    pinMode(displayPins[pinIndex], OUTPUT);
  }


  int currentCounter = 9;

  
  while (currentCounter >= 1) {
    Serial.print("Current Display Unit: ");
    Serial.println(currentCounter);

    clearAndShowDigit(currentCounter);  
    tone(buzzerElement, 1000, 150);  
    
    delay(1000); //  
    currentCounter--; 
  }

  
  Serial.print("Current Display Unit: ");
  Serial.println(0);
  clearAndShowDigit(0); 
  
 
  tone(buzzerElement, 1500, 1000); 
  delay(1000); 

  Serial.println("--- Countdown Sequence Finished ---");
}

void loop() {
   
}
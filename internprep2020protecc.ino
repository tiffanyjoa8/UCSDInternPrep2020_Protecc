int blueledPin = 5;
const int BUTTON_PIN = 6;  // pushbutton
int buttonState = 0;   // reading pushbutton status

const int redledPin =  8; 
int soundsensor = 2; // sound sensor
boolean LEDStatus = false;
int vibPin = 9; //vibration sensor
int lightsensPin = 10;

#define echoPin 12
#define trigPin 11
long duration;
int distance;

const int buzzerPin = 7;

void setup() {
  //assign inputs
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(soundsensor, INPUT);
  pinMode(vibPin, INPUT);
  pinMode(lightsensPin, INPUT);
  pinMode(echoPin, INPUT);

  //assign outputs
  pinMode(blueledPin, OUTPUT);
  pinMode(redledPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
  Serial.println("Ultrasonic sensor readings\n");
}

void loop() {

////BLUE LED CHECK
//digitalWrite(blueledPin, HIGH);
//delay(1000);
//digitalWrite(blueledPin, LOW);
//delay(1000);
//
////RED LED CHECK
//digitalWrite(redledPin, HIGH);
//
//  PUSHBUTTON CHECK
  buttonState = digitalRead(BUTTON_PIN);

  // control LED according to the state of button
  if(buttonState == LOW)         // If button is pressed
  {
    digitalWrite(redledPin, HIGH); // turn on LED
    tone(buzzerPin, 1000); //play 1KHz sound signal
    delay(500);
    noTone(buzzerPin);
    delay(500);

    tone(buzzerPin, 1000); //play 1KHz sound signal
    delay(500);
    noTone(buzzerPin);
    delay(500);

    tone(buzzerPin, 1000); //play 1KHz sound signal
    delay(500);
    noTone(buzzerPin);
    delay(500);
  }
  else                           // if button not pressed
  {
    digitalWrite(redledPin, LOW);  // turn off LED
  }

//SOUND CHECK
  int SensorData=digitalRead(soundsensor); 
  if(SensorData==1){
    if(LEDStatus==false){
        LEDStatus=true;
        digitalWrite(redledPin,HIGH);

    tone(buzzerPin, 750); //play 1KHz sound signal
    delay(500);
    noTone(buzzerPin);
    delay(500);

    tone(buzzerPin, 750); //play 1KHz sound signal
    delay(500);
    noTone(buzzerPin);
    delay(500);

    tone(buzzerPin, 750); //play 1KHz sound signal
    delay(500);
    noTone(buzzerPin);
    delay(500);
    }
    else{
        LEDStatus=false;
        digitalWrite(redledPin,LOW);
    }
  }

//VIBE CHECK
  int val;
  val=digitalRead(vibPin);
  if(val==1)
  {
    digitalWrite(blueledPin,HIGH);
    
    tone(buzzerPin, 1100); //play 1KHz sound signal
    delay(500);
    noTone(buzzerPin);
    delay(500);

    tone(buzzerPin, 1100); //play 1KHz sound signal
    delay(500);
    noTone(buzzerPin);
    delay(500);

    tone(buzzerPin, 1100); //play 1KHz sound signal
    delay(500);
    noTone(buzzerPin);
    delay(500);
   }
   else
   digitalWrite(blueledPin,LOW);

//NOTE: photoresistor broke while testing???
////LIGHTSENS CHECK
//  int LightSensdata = digitalRead(lightsensPin);
//  if(LightSensdata==1)
//  {
//    digitalWrite(blueledPin,LOW);
//    Serial.print(LightSensdata);
//   }
//   else
//   digitalWrite(blueledPin,HIGH);
//   Serial.print(LightSensdata);


//ULTRASONSENS CHECK
// Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
if (distance < 5)
{
    tone(buzzerPin, 1200); //play 1KHz sound signal
    delay(500);
    noTone(buzzerPin);
    delay(500);

    tone(buzzerPin, 1200); //play 1KHz sound signal
    delay(500);
    noTone(buzzerPin);
    delay(500);

    tone(buzzerPin, 1200); //play 1KHz sound signal
    delay(500);
    noTone(buzzerPin);
    delay(500);
}
  

//PIEZO BUZZER PIN
//tone(buzzerPin, 262); //play 1KHz sound signal
//delay(500);
//noTone(buzzerPin);
//tone(buzzerPin, 294.8); //play 1KHz sound signal
//delay(500);
//noTone(buzzerPin);
//tone(buzzerPin, 327.5); //play 1KHz sound signal
//delay(500);
//noTone(buzzerPin);
   
}

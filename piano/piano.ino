#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define the analog pin for the potentiometer
#define POTENTIOMETER_PIN A3

// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
int buzzerPin = 11;
int button = 2;

// defines variables
long duration;
int distance;
char note[8];

void setup() {
  //distance setup
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication

  //passive buzzer
  pinMode(buzzerPin, OUTPUT);
  tone(buzzerPin, 1000, 2000);

  //button
  pinMode(button, INPUT);

  //LCD
  lcd.init();
  lcd.backlight();
}
void loop() {

  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  int buttonPressed = digitalRead(button);
  int frequency = 0;
  if(distance > 0 && distance <= 10){
    // G4
    frequency=392;
    lcd.clear();
    lcd.home();

    note[0]='S';
    note[1]='O';
    note[2]='L';
    note[3]=' ';
    note[4]=' ';
    note[5]=' ';
    note[6]=' ';
    note[7]=' ';
    note[8]=' ';
  }

  if(distance > 10 && distance <= 18){
    // A4
    frequency=440;
    lcd.clear();
    lcd.home();

    note[0]='L';
    note[1]='A';
    note[2]=' ';
    note[3]=' ';
    note[4]=' ';
    note[5]=' ';
    note[6]=' ';
    note[7]=' ';
    note[8]=' ';
  }

    if(distance > 18 && distance <= 26){
    // B4
    frequency=494;
    lcd.clear();
    lcd.home();

    note[0]='S';
    note[1]='I';
    note[2]=' ';
    note[3]=' ';
    note[4]=' ';
    note[5]=' ';
    note[6]=' ';
    note[7]=' ';
    note[8]=' ';
  }

    if(distance > 26 && distance <= 34){
    // C5
    frequency=523;
    lcd.clear();
    lcd.home();

    note[0]='D';
    note[1]='O';
    note[2]=' ';
    note[3]=' ';
    note[4]=' ';
    note[5]=' ';
    note[6]=' ';
    note[7]=' ';
    note[8]=' ';
  }

    if(distance > 34 && distance <= 42){
    // D5
    frequency=587;
    lcd.clear();
    lcd.home();

    note[0]='R';
    note[1]='E';
    note[2]=' ';
    note[3]=' ';
    note[4]=' ';
    note[5]=' ';
    note[6]=' ';
    note[7]=' ';
    note[8]=' ';
  }

    if(distance > 42 && distance <= 50){
    // D5#
    frequency=622;
    lcd.clear();
    lcd.home();

    note[0]='M';
    note[1]='I';
    note[2]=' ';
    note[3]='B';
    note[4]='E';
    note[5]='M';
    note[6]='O';
    note[7]='L';
    note[8]=' ';

  }

    if(distance > 50 && distance <= 58){
    // E5
    frequency=659;
    lcd.clear();
    lcd.home();

    note[0]='M';
    note[1]='I';
    note[2]=' ';
    note[3]=' ';
    note[4]=' ';
    note[5]=' ';
    note[6]=' ';
    note[7]=' ';
    note[8]=' ';
  }

  if(distance > 58 && distance <= 66){
    // F5
    frequency=698;
    lcd.clear();
    lcd.home();

    note[0]='F';
    note[1]='A';
    note[2]=' ';
    note[3]=' ';
    note[4]=' ';
    note[5]=' ';
    note[6]=' ';
    note[7]=' ';
    note[8]=' ';
  }

  if(distance > 66 && distance <= 74){
    // G5
    frequency=784;
    lcd.clear();
    lcd.home();

    note[0]='S';
    note[1]='O';
    note[2]='L';
    note[3]=' ';
    note[4]=' ';
    note[5]=' ';
    note[6]=' ';
    note[7]=' ';
    note[8]=' ';
  }

    if(distance > 74){
      noTone(buzzerPin);
      lcd.print(" Digital Piano");
      delay(400);
      lcd.clear();
      lcd.home();
    } else
  {
    tone(buzzerPin, frequency);
    lcd.print(note);
    delay(400);
    lcd.home();
  }

  // Read the potentiometer value
  int potValue = analogRead(POTENTIOMETER_PIN);

  // Set a threshold
  if (potValue > 512) {
    lcd.backlight(); // Turn on the backlight
  } else {
    lcd.noBacklight(); // Turn off the backlight
  }

  // Add a small delay to prevent excessive reading
  delay(100);
}


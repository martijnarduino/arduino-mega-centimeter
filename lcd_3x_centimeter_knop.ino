/* tweede post DigitaleCentimeter
lcd
scl 21 communication
sda 20 communication
vcc 5v gnd gnd

piezo
plus 17(PWM)
gnd gnd

knop
gnd gnd
plus A15

*LET OP WEERSTANDEN BIJ DE PLUS VAN DE LED'S

  led rood 14 gnd gnd
  led geel 16 gnd gnd

*LET OP WEERSTANDEN BIJ DE PLUS VAN DE LED'S

Ultrasone afstandsensor
vcc 5v
trig 9
echo 10
gnd gnd


*/
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
const int rs = 44, en = 45, d4 = 46, d5 = 47, d6 = 49, d7 = 48;
LiquidCrystal_I2C lcd(0x27, 16, 2);
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;
int counter;
void setup() {
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();

  
  lcd.begin(32, 1);
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  lcd.print("opstarten");
  delay (3000);
  lcd.clear();
  lcd.print("opstarten");
  lcd.setCursor (0,1);//P
  lcd.print("I         P");
  delay (1000);
  lcd.clear();
  lcd.print("opstarten");
  lcd.setCursor (0,1);
  lcd.print("II        P");
  delay (1000);
  lcd.clear();
  lcd.print("opstarten");
  lcd.setCursor (0,1);
  lcd.print("III       P");
  delay (1000);
  lcd.clear();
  lcd.print("opstarten");
  lcd.setCursor (0,1);
  lcd.print("IIII      P");
  delay (1000);
  lcd.clear();
  lcd.print("opstarten");
  lcd.setCursor (0,1);
  lcd.print("IIIII     P");
  delay (1000);
  lcd.clear();
  lcd.print("opstarten");
  lcd.setCursor (0,1);
  lcd.print("IIIIII    P");
  delay (1000);
  lcd.clear();
  lcd.print("opstarten");
  lcd.setCursor (0,1);
  lcd.print("IIIIIII   P");
  delay (1000);
  lcd.clear();
  lcd.print("opstarten");
  lcd.setCursor (0,1);
  lcd.print("IIIIIIII  P");
  delay (1000);
  lcd.clear();
  lcd.print("opstarten");
  lcd.setCursor (0,1);
  lcd.print("IIIIIIIII P");
  delay (1000);
  lcd.clear();
  lcd.print("opstarten");
  lcd.setCursor (0,1);
  lcd.print("IIIIIIIIIIP"); 
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
}
void loop() {

int potential = analogRead(A15);

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
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.print(distance);
Serial.println(" cm");
lcd.clear();

if (analogRead(A15) == LOW) {lcd.print("afstand ");
lcd.print(distance);
lcd.print(" cm"); 
lcd.setCursor(0, 1);
lcd.print("afstand ");
lcd.print(distance);
lcd.print("0 mm");
Serial.print("Afstand: ");
Serial.print(distance);
Serial.println("0 mm");
  } else { lcd.print("afstand ");
lcd.print(distance);
lcd.print(" cm"); 
lcd.setCursor(0, 1);

if (distance < 9) {
lcd.print("afstand 0.0");

  } else {
  lcd.print("afstand 0.");

  }
  lcd.print(distance);
lcd.print(" m");
if (distance < 2) {
tone(17, 523, 1000); // play tone 60 (C5 = 523 Hz)
delay (1000);
tone(17, 423, 1000); // play tone 60 (C5 = 523 Hz)
  }
  if (distance > 2000) {
    lcd.clear();
lcd.print ("kan de afstand");
lcd.setCursor(0, 1);
lcd.print ("NIET lezen");
tone(17, 523, 1000); // play tone 60 (C5 = 523 Hz)
digitalWrite(16, HIGH);
delay (1000);
tone(17, 423, 1000); // play tone 60 (C5 = 523 Hz)
digitalWrite(16, LOW);
digitalWrite(14, HIGH);
delay (1000);
tone(17, 523, 1000); // play tone 60 (C5 = 523 Hz)
digitalWrite(16, HIGH);
digitalWrite(14, LOW);
delay (1000);
tone(17, 423, 1000); // play tone 60 (C5 = 523 Hz)
digitalWrite(16, LOW);
delay (1000);
  }
  } 
delay (1000);


}

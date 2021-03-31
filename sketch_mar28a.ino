#define A0 14
#define A1 15
#define A2 16
#define A3 17
#define A4 18
#define A5 19



const int analogInPin0 = A0; //odd numbers trigpin(Pin0,Pin2,Pin4)
const int analogInPin1 = A1; //even numbers echopin (Pin1,Pin3,Pin6)
const int analogInPin2 = A2;
const int analogInPin3 = A3;
const int analogInPin4 = A4;
const int analogInPin5 = A5;
// define variables

int green = 2;
int red = 4;

// LED pinIn

long duration;

int distance = 0;

void setup() {
  // put your setup code here, to run once:
pinMode (analogInPin0, OUTPUT);
pinMode (analogInPin1, INPUT);
pinMode (analogInPin2, OUTPUT);
pinMode (analogInPin3, INPUT);
pinMode (analogInPin4, OUTPUT);
pinMode (analogInPin5, INPUT);
pinMode (green, OUTPUT);
pinMode (red, OUTPUT);
Serial.begin(9600);
}

void loop() {

if ((distance < 50)&&(distance > 0))
    {
      digitalWrite(green,HIGH);
      digitalWrite(red, LOW);
    }
    else if((distance > 51)&&(distance < 150)){
    
      digitalWrite(green,LOW);
      digitalWrite(red, HIGH);
    }
 
delayMicroseconds(10);
// Clears the trigPin
digitalWrite(analogInPin0,LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(analogInPin0,HIGH);
delayMicroseconds(10);
digitalWrite(analogInPin0,LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(analogInPin1, HIGH);
// Calculating the distance
distance= duration*0.034/2;

if ((distance < 50)&&(distance > 0))
    {
      digitalWrite(green,HIGH);
      digitalWrite(red, LOW);
    }
    else if((distance > 51)&&(distance < 150)){
    
      digitalWrite(green,LOW);
      digitalWrite(red, HIGH);
    }
    
Serial.println(distance);            // prints the value of the sensor to the serial monitor
  delay(100);                   // wait for this much time before printing next value
}

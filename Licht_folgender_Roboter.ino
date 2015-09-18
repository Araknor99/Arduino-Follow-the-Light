#include <Servo.h>
int sensorPin1 = 0; //rechter Lichtsensor
int sensorPin2 = 1; //linker Lichtsensor
Servo myservo;


void setup() {
  myservo.attach(9);
  Serial.begin(9600);
}

void loop() {
  int sensor1 = analogRead(sensorPin1);// Helligkeit rechts
  int sensor2 = analogRead(sensorPin2);//Helligkeit links
  int unterschied = sensor1 - sensor2;//Ausrechnen des Wertes der Helligkeit.
  Serial.print("sensor1 = " );//Anzeigen des Wertes des rechten Lichtsensors.
  Serial.print(sensor1);
  Serial.print(" sensor2 = " );//Anzeigen des Wertes des linken Lichtsensors.
  Serial.print(sensor2);
  Serial.print(" unterschied = " );//Anzeigen ob der Wert Positiv oder Negativ ist 
  Serial.println(unterschied);
  if (unterschied > 0) {// Entscheiden ob der Wert positiv ist.
  //Schrittbewegung nach rechts
    myservo.write(120);
    delay(200);
    myservo.write(100);
    delay(200);
  } else { //Wenn der Wert negativ ist.
    //Schrittbewegung nach links
    myservo.write(80);
    delay(200);
    myservo.write(60);
    delay(200);
  }
}

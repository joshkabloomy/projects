int fsrPin = 0;     // the FSR and 10K pulldown are connected to a0
int fsrReading;     // the analog reading from the FSR resistor divider
int fsrVoltage;     // the analog reading converted to voltage
int redLEDPin = 0;
int greenLEDPin = 1;
int blueLEDPin = 2;
double mass;
double range1 = 42; double range2 = 461; double range3 = 501; double range4 = 673;double range5 = 768;
double range6 = 944; 

void setup(void) {
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
  analogReadResolution(16);
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
}
 
void loop(void) {
  fsrReading = analogRead(fsrPin);  
  Serial.print("Analog reading = ");
  Serial.println(fsrReading);
  
  // analog voltage reading ranges from about 0 to 65535 which maps to 0V to 5.17 V
  fsrVoltage = map(fsrReading, 0, 65535, 0, 5170);
  Serial.print("Voltage reading in mV = ");
  Serial.println(fsrVoltage);  

 // convert to mass
 mass = 45.3 * exp(6.05 / 10000 * fsrVoltage) ;
 // exponetial function doesnt fit well with lower values, so subtract
 
 if (mass < 70.0){
    mass-=20;
  }
  else if (mass < 90){
    mass-=40;
  }
  else if (mass < 110){
    mass-=20;
  }
  else if (mass < 120){
    mass-=10;
  }
  
 Serial.print("Mass Converstion in grams = ");
 Serial.println(mass);  
 
 // change from fsrvoltage to mass later
  if (mass <= range1 ){ // assume green
      digitalWrite(greenLEDPin, LOW);
      digitalWrite(redLEDPin, HIGH);
      digitalWrite(blueLEDPin, LOW);
     
    
    }
    else if (mass >= range1 && mass < range2){ // assume green
      digitalWrite(greenLEDPin, HIGH);
      digitalWrite(redLEDPin, LOW);
      digitalWrite(blueLEDPin, LOW);
     
    
    }
    else if (mass >= range2 && mass <= range3){ // assume blue
    digitalWrite(greenLEDPin, LOW);
    digitalWrite(redLEDPin, LOW);
    digitalWrite(blueLEDPin, HIGH);
    
    
    }
    else if (mass > range3 && mass <= range4){ // assume red
    digitalWrite(greenLEDPin, LOW);
    digitalWrite(redLEDPin, LOW);
    digitalWrite(blueLEDPin, LOW);
   
    }
    else if (mass > range4 && mass <= range5){ // assume red
    digitalWrite(greenLEDPin, LOW);
    digitalWrite(redLEDPin, LOW);
    digitalWrite(blueLEDPin, HIGH);
   
    }
    else if (mass > range5 && mass <= range6){ // assume red
    digitalWrite(greenLEDPin, LOW);
    digitalWrite(redLEDPin, HIGH);
    digitalWrite(blueLEDPin, LOW);
   
    }
    else if (mass > range6 ){ // assume red
    digitalWrite(greenLEDPin, HIGH);
    digitalWrite(redLEDPin, LOW);
    digitalWrite(blueLEDPin, LOW);
   
    }
  
  Serial.println("--------------------");
  delay(1000);
}

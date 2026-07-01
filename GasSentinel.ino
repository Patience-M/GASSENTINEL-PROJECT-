#include <Servo.h>
#include <SoftwareSerial.h>

Servo myservo;
SoftwareSerial gsmSerial(10, 11);

// Configuration Constants
const String PHONE_NUMBER = "+256786053784"; 
const String MSG_MODERATE = "Alert: Moderate smoke detected. Fan activated.";
const String MSG_CRITICAL = "CRITICAL ALERT: High smoke levels detected!";

const int MQ2_ANALOG_PIN = A0; 
int sensorCleanAir = 280;
int sensorDenseSmoke = 800; 

// Pin Definitions
const int LEDGREEN = 7;
const int LEDYELLOW = 8;
const int LEDRED = 9;
const int Buzzer = 2;
const int RELAYFAN = 3;
const int RELAYGSM = 4;

// State Tracking Flags (Prevents SMS Spamming)
bool smsSentModerate = false;
bool smsSentCritical = false;

void setup() {
  Serial.begin(9600);
  gsmSerial.begin(9600); 
  
  myservo.attach(5);
  myservo.write(0); // Initialize window/vent closed
  
  pinMode(LEDGREEN, OUTPUT);
  pinMode(LEDYELLOW, OUTPUT);
  pinMode(LEDRED, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(RELAYFAN, OUTPUT);
  pinMode(RELAYGSM, OUTPUT);
  
  // Power up GSM module
  digitalWrite(RELAYGSM, HIGH);
  
  Serial.println("Stabilizing MQ-2 sensor and connecting GSM... Please wait.");
  delay(15000); 
  Serial.println("System ready.");
}

void loop() {
  int rawAnalogValue = analogRead(MQ2_ANALOG_PIN);
  int constrainedValue = constrain(rawAnalogValue, sensorCleanAir, sensorDenseSmoke);
  int smokePercentage = map(constrainedValue, sensorCleanAir, sensorDenseSmoke, 0, 100);
  
  Serial.print("Raw ADC: ");
  Serial.print(rawAnalogValue);
  Serial.print("  |  Smoke: ");
  Serial.print(smokePercentage);
  Serial.println("%");
  
  // ================= STATE 1: NORMAL =================
  if (smokePercentage < 15) {
    Serial.println("Status: Normal");
    digitalWrite(LEDGREEN, HIGH);
    digitalWrite(LEDYELLOW, LOW);
    digitalWrite(LEDRED, LOW);
    digitalWrite(RELAYFAN, LOW);   
    myservo.write(0); // Close vent
    noTone(Buzzer);
    
    // Reset flags when air clears so it can alert again if smoke returns
    smsSentModerate = false;
    smsSentCritical = false;
    
    delay(1000); 
  } 
  
  // ================= STATE 2: MODERATE =================
  else if (smokePercentage < 60) {
    Serial.println("Status: Moderate Smoke!");
    digitalWrite(LEDGREEN, LOW);
    digitalWrite(LEDYELLOW, HIGH);
    digitalWrite(LEDRED, LOW);
    digitalWrite(RELAYFAN, HIGH); // Turn extraction fan on
    myservo.write(180);           // Open vent fully

    // Check if we need to send the one-time notification
    if (!smsSentModerate) {
      // Turn buzzer on solid so it sounds while the 7-second SMS transmits
      tone(Buzzer, 1200); 
      sendSMS(MSG_MODERATE);
      smsSentModerate = true; // Lock the flag
    }
    
    // Standard rhythmic warning pulse for the rest of the duration
    tone(Buzzer, 1200); 
    delay(150);
    noTone(Buzzer);
    delay(850); 
  } 
  
  // ================= STATE 3: CRITICAL =================
  else {
    Serial.println("Status: CRITICAL SMOKE DETECTED!");
    digitalWrite(LEDGREEN, LOW);
    digitalWrite(LEDYELLOW, LOW);
    digitalWrite(LEDRED, HIGH);
    digitalWrite(RELAYFAN, HIGH);
    myservo.write(180);

    // Check if we need to send the one-time critical notification
    if (!smsSentCritical) {
      tone(Buzzer, 2200); // Continuous tone during transmission
      sendSMS(MSG_CRITICAL);
      smsSentCritical = true; // Lock the flag
    }
    
    // Rapid, aggressive dual-tone emergency siren
    for (int i = 0; i < 2; i++) {
      tone(Buzzer, 2500);
      delay(200);
      tone(Buzzer, 1800); 
      delay(200);
    }
  }
}

void sendSMS(String message) {
  Serial.println("Initializing SMS Send Sequence...");
  gsmSerial.println("AT+CMGF=1");
  delay(1000);
  
  gsmSerial.print("AT+CMGS=\"");
  gsmSerial.print(PHONE_NUMBER);
  gsmSerial.println("\"");
  delay(1000);
  
  gsmSerial.print(message);
  delay(100);
  gsmSerial.write(26); // ASCII code for Ctrl+Z to send
  delay(5000); 
  Serial.println("SMS Sent Successfully.");
}
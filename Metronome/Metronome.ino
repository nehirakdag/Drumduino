const int buzzer = 8; // Piezo Buzzer in digital port 9
const int potentiometer = 3;     // potentiometer pin
const int button = 13;
int currentState = HIGH;
int reading;
int previousState = LOW;
long previousTime = 0;
int val = 0;           // variable to store the value read
double bpm;
double delaytime;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  reading = digitalRead(button);
  if( reading == HIGH && previousState == LOW) {
    if ( currentState == HIGH) {
      currentState = LOW;
    }
    else {
      currentState = HIGH;
    }
  }
  previousState = reading;
  //Serial.print("Current State: ");
  //Serial.println(currentState);
  unsigned long currentTime = millis();
  if ( currentState == HIGH ) {
    val = analogRead(potentiometer);
    val -= 523; 
    bpm = (0.58 * val) + 40;
    delaytime = bpmToMillis(bpm);
    //Serial.print("BPM = ");
    //Serial.println(bpm);
    //Serial.print("Delay Time = ");
    //Serial.println(delaytime);
    if(currentTime - previousTime >= delaytime) {
      previousTime = currentTime;
      tone( buzzer, 330, 15);
    }
    //beep();
    //delay(delaytime);
  }
}

int bpmToMillis(double bpm)
{
 double val;
 val = bpm / 60;        //Gets BEats per second
 val = 1000 / val;    //Gets Milliseconds for delay
 return val;
}

void beep(){ 
  digitalWrite(buzzer, HIGH);
  delay(1);
  digitalWrite(buzzer, LOW);
}

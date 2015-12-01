int pinReading;
int padCutoff[] = {20, 5, 10, 15, 25, 15};
int playTimes[] = {0, 0, 0, 0, 0, 0};
int maxPlayTimes[] = {2, 2, 2, 2, 2, 2};
boolean activePads[] = {0, 0, 0, 0, 0, 0};

void setup() 
{ 
  Serial.begin( 115200 ); 
}
 
void loop() 
{
  for ( int i=0; i<6; i++) {
    pinReading = analogRead(i);
    if( pinReading > padCutoff[i]) {
      if( !activePads[i] ) {
        activePads[i] = true;
        playTimes[i] = 0;
        Serial.print( pinReading );
        Serial.print(' ');
      }
      else {
        playTimes[i]++;
        Serial.print( 0 );
        Serial.print(' ');
      }
    }
    else if(activePads[i] = true) {
      playTimes[i]++;
      Serial.print( 0 );
      Serial.print(' ');
      if(playTimes[i] > maxPlayTimes[i]) {
        activePads[i] = false;
      }
    }
    else{
      Serial.print( 0 );
      Serial.print(' ');
    }
  }
  Serial.println();

  delay( 10 );
}

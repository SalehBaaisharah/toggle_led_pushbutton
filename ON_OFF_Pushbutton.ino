#define ledPin 12
#define buttonPin 5

byte LBS; //last button state
byte ledState = LOW;
unsigned long LTBSC= millis(); //last time button state changed
unsigned long DD =50; //debounce duration

void setup(){
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin , INPUT);
  LBS =digitalRead(buttonPin);
}

void loop(){
  if (millis() - LTBSC >= DD){
    byte buttonState = digitalRead(buttonPin);
    if(buttonState !=LBS){
      LTBSC = millis();
      LBS = buttonState;
      if(buttonState ==LOW){
        if(ledState == HIGH){
          ledState = LOW;
        }
        else {
          ledState =HIGH;
        }
        digitalWrite(ledPin,ledState);
      }
    }
  }
}

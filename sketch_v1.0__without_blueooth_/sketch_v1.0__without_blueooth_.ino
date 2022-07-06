// Device on right feet
int stepfunc = 0;
int but1pin = 5;
int but2pin = 12;
boolean but1;
boolean but2;
int first = 0;
int func = 0;
int func1 = 0;
unsigned long lasttimer;
unsigned long timer;
unsigned int firstleg = 1500; //right first - 1000; left first 2000 (avarage)
int firstlegstate; // right = 0; left = 1
unsigned int stepcount = 0;
void setup() {
  pinMode(but1pin, INPUT_PULLUP);
  pinMode(but2pin, INPUT_PULLUP);
  Serial.begin(9600);
  while(first == 0){
    but1 = !digitalRead(but1pin);
    but2 = !digitalRead(but2pin);
    while(but1 == 0 && but2 == 1 && func == 0){
      but1 = !digitalRead(but1pin);
      but2 = !digitalRead(but2pin);
      lasttimer = millis();
      Serial.println("first loop end");
      Serial.println(lasttimer);
      func = 1;
    }
    
    while(but1 == 0 && but2 == 0 && first == 0){
      but1 = !digitalRead(but1pin);
      but2 = !digitalRead(but2pin);
      Serial.println(millis());
      timer = millis() - lasttimer;
      Serial.println("second loop end");
      first = 1;
    }      
  } 
  if(timer >= firstleg){
    Serial.println("Right leg first");
    firstlegstate = 0;
  }
  if(timer <= firstleg){
    Serial.println("Left leg first");
    firstlegstate = 1;
  }
  if(firstlegstate == 1){
    stepcount = 1;
  }
}

void loop() {
  but1 = !digitalRead(but1pin);
  but2 = !digitalRead(but2pin);
  while(but1 != 0 && but2 != 1 && func1 == 0){
    but1 = !digitalRead(but1pin);
    but2 = !digitalRead(but2pin);
  }
  if(but1 == 0 && but2 == 1){
    func1 = 1;
  }
  while(but1 == 0 && but2 == 0 && func1 ==1){
    stepcount = stepcount + 2;
    but1 = !digitalRead(but1pin);
    but2 = !digitalRead(but2pin);
    func1 = 0;
  }

  Serial.println(stepcount);
}

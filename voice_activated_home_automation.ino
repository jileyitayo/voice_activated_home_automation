String spokenwords;
int appliance1 = 4; //Kitchen light
int appliance2 = 5; //Room light
int appliance3 = 6; //Fan Socket
int appliance4 = 0; //Appliance

// -- turn all applicance on
void turnAllOn(){
  digitalWrite(appliance1, LOW);
  digitalWrite(appliance2, LOW);
  digitalWrite(appliance3, LOW);
  digitalWrite(appliance4, LOW);
}

// -- turn all applicance off
void turnAllOff(){
  digitalWrite(appliance1, HIGH);
  digitalWrite(appliance2, HIGH);
  digitalWrite(appliance3, HIGH);
  digitalWrite(appliance4, HIGH);
}

void setup() {
  // put your setup code here, to run once:
  // set applicance as output
    Serial.begin(9600);
    pinMode(appliance1, OUTPUT); 
    pinMode(appliance2, OUTPUT); 
    pinMode(appliance3, OUTPUT); 
    pinMode(appliance4, OUTPUT); 
    turnAllOff();
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available()) {  //Check if there is an available byte to read
    delay(10); //Delay added to make thing stable
    char c = Serial.read(); //Conduct a serial read
    if (c == '#') {break;} //Exit the loop when the # is detected after the word
    spokenwords += c; //Shorthand for voice = voice + c
  } 

  if (spokenwords.length() > 0) {
      Serial.println(spokenwords);

    //------------------Control Multiple Pins/ LEDs
         if(spokenwords == "*all on") {turnAllOn();}  //Turn On All Pins 
    else if(spokenwords == "*all off"){turnAllOff();} //Turn Off  All Pins
   
    //------------------Turn On One Applicance at a time
    else if(spokenwords == "*kitchen on") {digitalWrite(appliance1, LOW);}
    else if(spokenwords == "*room on") {digitalWrite(appliance2, LOW);}
    else if(spokenwords == "*fan on") {digitalWrite(appliance3, LOW);}
    else if(spokenwords == "*bedroom on") {digitalWrite(appliance4, LOW);}
    
    
    
    //------------------Turn Off One Applicance at a time
    else if(spokenwords == "*kitchen off") {digitalWrite(appliance1, HIGH);}
    else if(spokenwords == "*room off") {digitalWrite(appliance2, HIGH);}
    else if(spokenwords == "*fan off") {digitalWrite(appliance3, HIGH);}
    else if(spokenwords == "*bedroom off") {digitalWrite(appliance4, HIGH);}
    
  //--------------------Reset the variable after initiating
  spokenwords=""; }
}


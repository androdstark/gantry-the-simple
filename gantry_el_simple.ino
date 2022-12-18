int s2=5;
int s1=7;
int s3=6;
int d=11;
int u=10;
int l=13;
int r=12;

#define stepx 3
#define dirx 4

#define stepy 9
#define diry 8

boolean buttonStateu = LOW; 
boolean buttonStated = LOW;
boolean buttonStatel = LOW;
boolean buttonStater = LOW;
boolean buttonStates1 = LOW;
boolean buttonStates2 = LOW;
boolean buttonStates3 = LOW;

const int ledPin = 2;
int ledState=LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  pinMode(u, INPUT_PULLUP);
  pinMode(d, INPUT_PULLUP);
  pinMode(l, INPUT_PULLUP);
  pinMode(r, INPUT_PULLUP);
  pinMode(s1, INPUT_PULLUP);
  pinMode(s2, INPUT_PULLUP);
  pinMode(s3, INPUT_PULLUP);

  pinMode(stepx, OUTPUT);
  pinMode(dirx, OUTPUT);
  pinMode(stepy, OUTPUT);
  pinMode(diry, OUTPUT);
  
}

void loop() {
  
 // up
  if(debounceButton(buttonStateu, u)==LOW && buttonStateu==HIGH){
    digitalWrite(ledPin, HIGH);
    buttonStateu = LOW;
  }
  else if(debounceButton(buttonStateu, u) == HIGH && buttonStateu == LOW)
  {
    buttonStateu = HIGH;
    digitalWrite(ledPin, LOW);
  }
  //s2 
    if(debounceButton(buttonStates2, s2)==LOW && buttonStates2==HIGH){
      digitalWrite(ledPin, LOW);
      //do nothing
      buttonStates2 = LOW;
    }
    else if(debounceButton(buttonStates2, s2) == HIGH && buttonStates2 == LOW)
    {
      buttonStates2 = HIGH;
      
    }
  //s2 end
  //move motor up with while buttonstateu=low and buttonstates2=high... 
  if(buttonStateu==LOW && buttonStates2==HIGH){
    digitalWrite(diry, LOW); //move to up   
    digitalWrite(stepy, HIGH);      
    delay(1);          
    digitalWrite(stepy, LOW);        
    delay(1);          
  }
// up end

// down
  if(debounceButton(buttonStated, d)==LOW && buttonStated==HIGH){
    digitalWrite(ledPin, HIGH);
        
    buttonStated = LOW;
  }
  else if(debounceButton(buttonStated, d) == HIGH && buttonStated == LOW)
  {
    buttonStated = HIGH;
    digitalWrite(ledPin, LOW);
  }
  //move motor down with while buttonstated=low...
  if(buttonStated==LOW){
    digitalWrite(diry, HIGH); //move to down   
    digitalWrite(stepy, HIGH);      
    delay(1);          
    digitalWrite(stepy, LOW);        
    delay(1);          
  }
// down end

// left
  if(debounceButton(buttonStatel, l)==LOW && buttonStateu==HIGH){
    digitalWrite(ledPin, HIGH);
    buttonStatel = LOW;
  }
  else if(debounceButton(buttonStatel, l) == HIGH && buttonStatel == LOW)
  {
    buttonStatel = HIGH;
    digitalWrite(ledPin, LOW);
  }
  //s1
    if(debounceButton(buttonStates1, s1)==LOW && buttonStates1==HIGH){
      digitalWrite(ledPin, LOW);
      //do nothing
      buttonStates1 = LOW;
    }
    else if(debounceButton(buttonStates1, s1) == HIGH && buttonStates1 == LOW)
    {
      buttonStates1 = HIGH;
      
    }
  //s1 end
  //move motor up with while buttonstatel=low and buttonstates1=high... 
  if(buttonStatel==LOW && buttonStates1==HIGH){
    digitalWrite(dirx, HIGH); //move to left   
    digitalWrite(stepx, HIGH);      
    delay(5);          
    digitalWrite(stepx, LOW);        
    delay(5);          
  }
// left end

// right
  if(debounceButton(buttonStater, r)==LOW && buttonStater==HIGH){
    digitalWrite(ledPin, HIGH);
    buttonStater = LOW;
  }
  else if(debounceButton(buttonStater, r) == HIGH && buttonStater == LOW)
  {
    buttonStater = HIGH;
    digitalWrite(ledPin, LOW);
  }
  //s3
    if(debounceButton(buttonStates3, s3)==LOW && buttonStates3==HIGH){
      digitalWrite(ledPin, LOW);
      //do nothing
      buttonStates3 = LOW;
    }
    else if(debounceButton(buttonStates3, s3) == HIGH && buttonStates3 == LOW)
    {
      buttonStates3 = HIGH;
      
    }
  //s3 end
  //move motor up with while buttonstater=low and buttonstates3=high... 
  if(buttonStater==LOW && buttonStates3==HIGH){
    digitalWrite(dirx, LOW); //move to right   
    digitalWrite(stepx, HIGH);      
    delay(5);          
    digitalWrite(stepx, LOW);        
    delay(5);
    //buttonStater=LOW;
    //buttonStates3=HIGH;     
  }
// right end
}

 boolean debounceButton(boolean state, int boton)
{
  boolean stateNow = digitalRead(boton);
  if(state!=stateNow)
  {
    delay(15);
    stateNow = digitalRead(boton);
  }
  return stateNow;
 }

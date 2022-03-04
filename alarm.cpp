int on = 0;

int br = 0;
int c1 = 0;
String command = "";

int presss = 0;
int p1 = 1;

unsigned long StartTime = millis();

int presure = 0;

long res = 14400000; //add the time that shall pass befor the timer starts

long add = 86400000; //loop to reapeat it every 24 houers

long timee =0;

void setup(){

  pinMode(9,OUTPUT);
  pinMode(3,INPUT);
  pinMode(A1,INPUT);
  Serial.begin(9600);
  delay(1000);
}

void loop(){

  unsigned long CurrentTime = millis();
  unsigned long ElapsedTime = CurrentTime - StartTime;
  Serial.println(ElapsedTime);
  
  command = Serial.readString();
  presure = digitalRead(3);

  if (presure == 1){
    presss = 1;

  }
  else{
    presss = 0;

  }
  Serial.println(presss);

  if (presss == 1){
    if (p1 == 1){
      digitalWrite(9,HIGH);
      Serial.println("bon");
      p1 =0;
      
    }
    else if (p1 == 0){
      digitalWrite(9,LOW);
      p1 = 1;
    }
  }

  if (res < ElapsedTime){
    if(p1 == 1){
       Serial.println("acctivating");
       digitalWrite(9,HIGH);
       p1 =0;
    }
    else if (p1 == 0){
       Serial.println("deacctivating");
       digitalWrite(9,LOW);
       p1 = 1;      
    }
    res =res + add;
  }


  Serial.print(command);


  
  if (command != "" and c1 == 0){
    Serial.println("acctivating");
    digitalWrite(9,HIGH);
    c1 = 1;
    
  }
  else if (command != "" and c1 == 1){
         Serial.println("closing");
         digitalWrite(9,LOW);
         c1 = 0;
    
  }

  
}

#include <Servo.h>
Servo Spin;

int a=3,b=4,c=5,d=6,e=7,f=8,g=9, contador=0;
int ButtonMode=0, ButtonModeOld=0, ButtonAccept=0, ButtonAcceptOld=0;
int KeyMode=0;
int KeyAccept=0;
int menu=101;

int TimeSet=0;
unsigned long TimeCurrent=0;
unsigned long TimeRemaining=0;
unsigned long TimeStart=0;
unsigned long TimeEnd=0;

void Character(int index){

  if(index==0){
	digitalWrite(a,HIGH);//número 0
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,LOW);//número 0
  }
  if(index==1){
    digitalWrite(a,LOW);//número 1
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);//número 1
  }
  if(index==2){
    digitalWrite(a,HIGH);//número 2
    digitalWrite(b,HIGH);
    digitalWrite(c,LOW);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,LOW);
    digitalWrite(g,HIGH);//número 2
  }
  if(index==3){
    digitalWrite(a,HIGH);//número 3
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,HIGH);//número 3
  }
  if(index==4){
    digitalWrite(a,LOW);//número 4
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);//número 4
  }
  if(index==5){
    digitalWrite(a,HIGH);//número 5
    digitalWrite(b,LOW);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,LOW);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);//número 5
  }
  if(index==6){
    digitalWrite(a,HIGH);//número 6
    digitalWrite(b,LOW);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);//número 6
  }
  if(index==7){
    digitalWrite(a,HIGH);//número 7
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);//número 7
  }
  if(index==8){
    digitalWrite(a,HIGH);//número 8
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);//número 8
  }
  if(index==9){
    digitalWrite(a,HIGH);//número 9
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,LOW);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);//número 9
  }
  if(index==10){
    digitalWrite(a,HIGH);//RAYA SUP
    digitalWrite(b,LOW);
    digitalWrite(c,LOW);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);//raya sup
  }
  if(index==11){
    digitalWrite(a,LOW);//RAYA mid
    digitalWrite(b,LOW);
    digitalWrite(c,LOW);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,HIGH);//raya mid
  }
  if(index==12){
    digitalWrite(a,LOW);//RAYA inf
    digitalWrite(b,LOW);
    digitalWrite(c,LOW);
    digitalWrite(d,HIGH);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);//raya inf
  }
  if(index==13){
    digitalWrite(a,HIGH);//F
    digitalWrite(b,LOW);
    digitalWrite(c,LOW);
    digitalWrite(d,LOW);
    digitalWrite(e,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);//F
  }
  if(index==14){
    digitalWrite(a,HIGH);//P
    digitalWrite(b,HIGH);
    digitalWrite(c,LOW);
    digitalWrite(d,LOW);
    digitalWrite(e,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);//P
  }
  if(index==15){
    digitalWrite(a,HIGH);// &a
    digitalWrite(b,LOW);
    digitalWrite(c,LOW);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);//
  }
  if(index==16){
    digitalWrite(a,LOW);// &b
    digitalWrite(b,HIGH);
    digitalWrite(c,LOW);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);//
  }
  if(index==17){
    digitalWrite(a,LOW);//&c
    digitalWrite(b,LOW);
    digitalWrite(c,HIGH);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);//c
  }
  if(index==18){
    digitalWrite(a,LOW);//&d
    digitalWrite(b,LOW);
    digitalWrite(c,LOW);
    digitalWrite(d,HIGH);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);//d
  }
  if(index==19){
    digitalWrite(a,LOW);//&e
    digitalWrite(b,LOW);
    digitalWrite(c,LOW);
    digitalWrite(d,LOW);
    digitalWrite(e,HIGH);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);//e
  }
  if(index==20){
    digitalWrite(a,LOW);//&f
    digitalWrite(b,LOW);
    digitalWrite(c,LOW);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,HIGH);
    digitalWrite(g,LOW);//f
  }
  if(index==21){
    digitalWrite(a,LOW);//&g
    digitalWrite(b,LOW);
    digitalWrite(c,LOW);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,HIGH);//g
  }
  

  
}
void AnimatedChar(int index){
  if (index==1){
    int timing=(millis()%1000);
    if (timing<=200){ //d
      Character(18);
    }
    else if (timing>200 && timing<=300){ // c
      Character(17);
    }
    else if (timing>300 && timing<=400){ // g
      Character(21);
    }
    else if (timing>400 && timing<=600){ // f
      Character(20);
    }
    else if (timing>600 && timing<=700){ // a
      Character(15);
    }
    else if (timing>700 && timing<=800){ // b
      Character(16);
    }
    else if (timing>800 && timing<=900){ // g
      Character(21);
    }
    else if (timing>900){ // e
      Character(19);
    }
  }
  else if (index==2){ //full circle
		int timing=(millis()%900);
		if (timing<=150){ //d
			Character(15);
		}
		else if (timing>150 && timing<=300){ // c
			Character(16);
		}
		else if (timing>300 && timing<=450){ // g
			Character(17);
		}
		else if (timing>450 && timing<=600){ // f
			Character(18);
		}
		else if (timing>600 && timing<=750){ // a
			Character(19);
		}
		else if (timing>750){ // b
			Character(20);
        }
	}
}


void key (){


}
void Alarm(){
  
  int timing=millis()%5000;
  int arm=int(10+ abs(160*sin(float(timing)/600)));
  Spin.write(arm);
  Serial.println(arm);
}
void setup() {
  Serial.begin(9600);
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(2, INPUT);
  pinMode(13,INPUT);
  Spin.attach(11, 500, 2500);
  Serial.println("welcome to timer...");
}

void loop() {

  TimeCurrent = millis()-TimeStart;
  TimeRemaining = TimeStart-millis();
  
  ButtonMode=0;
  ButtonMode=digitalRead(2);
  if(ButtonModeOld==0 && ButtonMode==1){
    KeyMode=1;
  }
  else{
    KeyMode=0;
  }
  ButtonModeOld=ButtonMode;


  ButtonAccept=0;
  ButtonAccept=digitalRead(13);
  if(ButtonAcceptOld==0 && ButtonAccept==1){
    KeyAccept=1;
  }
  else{
    KeyAccept=0;
  }
  ButtonAcceptOld=ButtonAccept;

  
    
    if ((menu <2000) && (TimeSet==1)){
      
      if (millis() >= TimeEnd && millis() < TimeEnd+10000)
        Alarm();
     
    }
  
  if (menu >100 && menu <=1000){ // main menu
    if (menu == 101){ // Default screen |Check Alarm| F
      Character(13);
      if(KeyMode==1){
        menu=102;
        Serial.println("pause alarm?");
      }
      if(KeyAccept==1){
        menu=1001;
        Serial.println(TimeCurrent);

      }

    }
    else if (menu == 102){ // Default screen |Pause Alarm| P
      Character(14);
      if(KeyMode==1){
        menu=103;
        Serial.println("set up alarm?");
      }
      if(KeyAccept==1){
        menu=2001;
      }

    }
    else if (menu == 103){ // Default screen |Set Alarm| S
      Character(5);
      if(KeyMode==1){
        menu=101;
        Serial.println("check alarm?");
      }
		if(KeyAccept==1){
		menu=3001;
		TimeRemaining=0;
		TimeStart=-1;
		Serial.println("Setting up the hours ");
		Serial.print("contador: ");
		Serial.println(contador);
		}
    }
  }
  else if (menu >1000 && menu <=2000){ //Checking up the alarm 
    if (menu==1001){//(hours)
      if(KeyMode==1){
        menu=101;
            Serial.print("menu: ");
        Serial.println(menu);
      }
      if(KeyAccept==1){
        menu=3001;
              TimeSet=0;
                TimeStart=-1;
                Serial.print("menu: ");
        Serial.println(menu);
      }

    }
  }
  else if (menu >2000 && menu <=3000){ //Pausing up the alarm 
    if (menu==2001){//(hours)
      AnimatedChar(1);
      if(KeyAccept==1){
                menu=3002;
                Serial.print("menu: ");
        Serial.println(menu);
              
      }
    }
  }
  else if (menu >3000 && menu <=4000){ //Setting up the alarm 
    if (menu==3001){//(hours)
      	if(millis()%1500<200)
			Character(10);
		else
			Character(contador);
      if(KeyMode==1){
        contador++;
              if (contador>23)
                    contador=0;
                Serial.print("contador: ");
        Serial.println(contador);
      }
      if(KeyAccept==1){
        TimeSet+=contador*60;
        menu=3002;
        contador=0;
        Serial.println("Setting up the minutes ");
        Serial.print("contador: ");
        Serial.println(contador);
        
      }
    }
      else if (menu==3002){//(minutes)
      if(millis()%1500<200)
			Character(11);
		else
			Character(contador);
      if(KeyMode==1){
        contador++;
                if (contador>59)
                    contador=0;
                Serial.print("contador: ");
        Serial.println(contador);
      }
      if(KeyAccept==1){
        TimeSet+=contador;
                menu=101;
                
                
                int hours=TimeSet/60;
                int minutes=contador;
                contador=0;
                Serial.print("Alarm set to ");
        Serial.print(hours);
                Serial.print(" hours, and ");
        Serial.print(minutes);
                Serial.println(" minutes.");
                TimeRemaining=TimeSet*60000;
                Serial.println(TimeRemaining);
                TimeStart=millis();
                TimeEnd=millis()+TimeRemaining;
                TimeSet=1;
      }
    }
  }
}
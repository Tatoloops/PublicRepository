// C++ code
//
#include <Servo.h>

unsigned long TimeCurrent;
unsigned long TimeStart;
unsigned long TimeEnd;

int SeqCurrent;
int SeqSelected;
/*
	A B C are the leds
*/
int A;  //led A
int B;	//led B
int C;	//led C
Servo Spin;

int EnergyIIII; //1500
int EnergyIII;	//1100
int EnergyII;	//700
int EnergyI;	//300
int Energy0;	//0

void sequence0(){
  int Time01=TimeCurrent%18000;
  
  if (Time01<1000){
    analogWrite(A,Energy0);
  	analogWrite(B,Energy0);
    analogWrite(C,Energy0);
    Spin.write(90);
  }
  else if (Time01<2000){
    analogWrite(A,EnergyIIII);
  	analogWrite(B,EnergyIIII);
    analogWrite(C,EnergyIIII);
    Spin.write(170);
  }
  else if (Time01<3000){
    analogWrite(A,Energy0);
  	analogWrite(B,Energy0);
    analogWrite(C,Energy0);
    Spin.write(90);
  }
  else if (Time01<4000){
    analogWrite(A,EnergyIIII);
  	analogWrite(B,EnergyIIII);
    analogWrite(C,EnergyIIII);
    Spin.write(170);
  }
  else if (Time01<5000){
    analogWrite(A,Energy0);
  	analogWrite(B,Energy0);
    analogWrite(C,Energy0);
    Spin.write(90);
  }
  else if (Time01<6000){
    analogWrite(A,EnergyIIII);
  	analogWrite(B,EnergyIIII);
    analogWrite(C,EnergyIIII);
    Spin.write(170);
  }
  else if (Time01<7000){
    analogWrite(A,Energy0);
  	analogWrite(B,Energy0);
    analogWrite(C,Energy0);
    Spin.write(90);
  }
  else if (Time01<8000){
    analogWrite(A,EnergyI);
  	analogWrite(B,EnergyI);
    analogWrite(C,EnergyI);
    Spin.write(110);
  }
  else if (Time01<9000){
    analogWrite(A,EnergyII);
  	analogWrite(B,EnergyII);
    analogWrite(C,EnergyII);
    Spin.write(130);
  }
  else if (Time01<10000){
    analogWrite(A,EnergyIII);
  	analogWrite(B,EnergyIII);
    analogWrite(C,EnergyIII);
    Spin.write(150);
  }
  else if (Time01<11000){
    analogWrite(A,EnergyIIII);
  	analogWrite(B,EnergyIIII);
    analogWrite(C,EnergyIIII);
    Spin.write(170);
  }
  else if (Time01<14000){
    analogWrite(A,EnergyIII);
  	analogWrite(B,EnergyIII);
    analogWrite(C,EnergyIII);
    Spin.write(150);
  }
  else if (Time01<15000){
    analogWrite(A,EnergyII);
  	analogWrite(B,EnergyII);
    analogWrite(C,EnergyII);
    Spin.write(130);
  }
  else if (Time01<16000){
    analogWrite(A,EnergyI);
  	analogWrite(B,EnergyI);
    analogWrite(C,EnergyI);
    Spin.write(110);
  }
  else if (Time01<17000){
    analogWrite(A,Energy0);
  	analogWrite(B,Energy0);
    analogWrite(C,Energy0);
    Spin.write(90);
  }
  
}
void sequence1(){
  int energy001=int(abs(EnergyIIII*sin(float(TimeCurrent)/600)));
    analogWrite(A,energy001);
  if (energy001>=1000){
  	analogWrite(B,EnergyIIII);
  	analogWrite(C,Energy0);
    Spin.write(150);
  }
  else if(energy001<=500){
    analogWrite(B,Energy0);
  	analogWrite(C,EnergyIIII);
    Spin.write(30);
  }
  else
    Spin.write(90); 
}
void sequence2(){
  int energy001=int(abs(EnergyIIII*sin(float(TimeCurrent)/500)));
  int energy002=int(EnergyIIII-abs(EnergyIIII*sin(float(TimeCurrent)/500)));
  int arm=int(10+ abs(160*sin(float(TimeCurrent)/600)));
  analogWrite(A,energy001);
  analogWrite(B,energy002);
  Spin.write(arm);
  if (energy001%100 <50)
 	analogWrite(C,EnergyIIII);
  else
    analogWrite(C,Energy0);
  
  
}
void sequence3(){
  int Time01=TimeCurrent%6000;
  if (Time01<=2000){
    analogWrite(A,HIGH);
    analogWrite(B,LOW);
    analogWrite(C,LOW);
    Spin.write(60);
  }
  else if (Time01<=3000){
    analogWrite(A,LOW);
    analogWrite(B,HIGH);
    analogWrite(C,LOW);
    Spin.write(90);
  }
  else if (Time01<=5000){
    analogWrite(A,LOW);
    analogWrite(B,LOW);
    analogWrite(C,HIGH);
    Spin.write(120);
  }
  else if (Time01<=6000){
    analogWrite(A,LOW);
    analogWrite(B,HIGH);
    analogWrite(C,LOW);
    Spin.write(90);
  }

}
void sequence4(){
  int Time01=TimeCurrent%6000;
  if (Time01<=2000){
    analogWrite(A,HIGH);
    analogWrite(B,LOW);
    analogWrite(C,HIGH);
    Spin.write(20);
  }
  else if (Time01<=3000){
    analogWrite(A,LOW);
    analogWrite(B,HIGH);
    analogWrite(C,LOW);
    Spin.write(40);
  }
  else if (Time01<=5000){
    analogWrite(A,HIGH);
    analogWrite(B,HIGH);
    analogWrite(C,HIGH);
    Spin.write(60);
  }
  else if (Time01<=6000){
    analogWrite(A,LOW);
    analogWrite(B,LOW);
    analogWrite(C,LOW);
    Spin.write(80);
  }
  
}
void sequence5(){
  
  
}
void sequence6(){
  
  
}
void sequence7(){
  
  
}

void setup(){
  
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(11,OUTPUT);
  // PINS
  A=3;
  B=5;
  C=6;
  
  Spin.attach(11, 500, 2500);
  
  SeqCurrent=0;
  SeqSelected=0;
  
  analogWrite(A,LOW);
  analogWrite(B,LOW);
  analogWrite(C,LOW);
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  
    EnergyIIII=1500; //1500
	EnergyIII=1100;	//1100
	EnergyII=700;	//700
	EnergyI=300;	//300
	Energy0=0;	//0
}

void loop(){
    int Entrada=analogRead(A0);
  
    if (Entrada>=995)		SeqSelected=7;
    else if (Entrada>=950)	SeqSelected=6;
    else if (Entrada>=900)	SeqSelected=5;
    else if (Entrada>=700)	SeqSelected=4;
    else if (Entrada>=500)	SeqSelected=3;
    else if (Entrada>=300)	SeqSelected=2;
    else if (Entrada>=100)	SeqSelected=1;
    else if (Entrada>=5)	SeqSelected=0;
      
    TimeCurrent = millis()-TimeStart;
      
    if (SeqCurrent != SeqSelected){
      TimeStart=TimeCurrent;
      SeqCurrent=SeqSelected;
      Serial.print("starting sequence: ");
      Serial.println(SeqCurrent);
  	}
  
  if (SeqCurrent==0) sequence0();
  else if (SeqCurrent==1) sequence1();
  else if (SeqCurrent==2) sequence2();
  else if (SeqCurrent==3) sequence3();
  else if (SeqCurrent==4) sequence4();
  else if (SeqCurrent==5) sequence5();
  else if (SeqCurrent==6) sequence6();
  else if (SeqCurrent==7) sequence7();
}

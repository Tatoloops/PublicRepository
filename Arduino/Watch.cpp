int a=3,b=4,c=5,d=6,e=7,f=8,g=9, contador=0,ButtonMode,ButtonAccept;
int menu=100;


unsigned long TimeCurrent=0;
unsigned long TimeStart=0;
unsigned long TimeEnd=0;

char Character(int index){

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
}

void key (){


}
void setup() {
	pinMode(a,OUTPUT);
	pinMode(b,OUTPUT);
	pinMode(c,OUTPUT);
	pinMode(d,OUTPUT);
	pinMode(e,OUTPUT);
	pinMode(f,OUTPUT);
	pinMode(g,OUTPUT);
}

void loop() {

	TimeCurrent = millis()-TimeStart;
	TimeRemaining = TimeStart-millis();
	Serial.println(contador);

	ButtonMode=digitalRead(2);
	ButtonAccept=digitalRead(13);

	if (menu >100 && menu <=1000){ // main menu
		if (menu == 101){ // Default screen |Check Alarm|

		}
		else if (menu == 102){ // Default screen |Pause Alarm|

		}
		else if (menu == 103){ // Default screen |Set Alarm|

		}
	}
	else if (menu >1000 && menu <10000){

	}
}
//センサの宣言
const int SW = A0; //スイッチ
const int ACCEL_Z = A1;
const int ACCEL_Y = A2;
const int ACCEL_X = A3;

//モータードライバーの宣言
const int intA1 = 2;
const int intA2 = 4;
const int enA = 3;

const int intB1 = 5;
const int intB2 = 7;
const int enB = 6;

const int intC1 = 8;
const int intC2 = 10;
const int enC = 9;

const int intD1 = 12;
const int intD2 = 13;
const int enD = 11;

int delayTime = 200;

//電磁石の宣言
#define MOTOR_MAX 5

boolean motorStates[MOTOR_MAX] = {
  false, false, false, false, false};
boolean motorStatesPre[MOTOR_MAX] = {
  false, false, false, false, false};

boolean buttonFlag = false;
boolean buttonFlagPre = false;

int motorSpeed = 255;

boolean motorDir = true;
boolean buttonTrigger = true;
boolean debugFlag = false;

//コンデンサの宣言

//Serial Setting
#define RX_BUFFER_SIZE 16
char rxChrData;
char rxString[RX_BUFFER_SIZE];
int rxIndex = 0;

//Command [Active]

//Command[AutoChange]
#define COM_A_AUTO '5' //

//Command : [set][value]
#define COM_S_SPEED 's' //
#define COM_S_DIRECTION 'd' //
#define COM_S_BUTTON 'b' //
#define COM_S_DEBUG 'D' //

//delimiters
#define SERIAL_DELIMITAR '\n'
#define RX_BUFFER_SIZE 16

//Srial Communication
void serialEvent(){
  while(Serial.available() > 0){
    rxChrData = Serial.read();  //入力された文字列を「rxChrData」に格納
  }
}

void setup(){
  Serial.begin(9600);

  pinMode(enA, OUTPUT);
  pinMode(intA1, OUTPUT);
  pinMode(intA2, OUTPUT);

  pinMode(enB, OUTPUT);
  pinMode(intB1, OUTPUT);
  pinMode(intB2, OUTPUT);

  pinMode(enC, OUTPUT);
  pinMode(intC1, OUTPUT);
  pinMode(intC2, OUTPUT);

  pinMode(enD, OUTPUT);
  pinMode(intD1, OUTPUT);
  pinMode(intD2, OUTPUT);

  pinMode(SW, INPUT);
  digitalWrite(SW, HIGH);
}

void loop(){
  if(rxChrData == 'S'){
    Serial.print("AutoMode:");
    AutoMode();
  }
  if(rxChrData == 'C'){
    Serial.print("CycronMode:");
    CycronMode();
  }
  if(rxChrData == 'D'){
    Serial.print("DirectionMode:");
    DirectionMode();
  }
  if(rxChrData == 'N'){
    Serial.print("Sansannanabyoushi:");
    Nanabyoushi();
  }
}

void AutoMode(){
  int i;
  Serial.println("START");
  for(i=0; i<20; i++){
    digitalWrite(intA1, LOW);
    digitalWrite(intA2, HIGH);
    analogWrite(enA, 252);
    Serial.println("start;A");
    delay(100);
    digitalWrite(intA1, LOW);
    digitalWrite(intA2, LOW);
    analogWrite(enA, 0);

    digitalWrite(intB1, LOW);
    digitalWrite(intB2, HIGH);
    analogWrite(enB, 252);
    Serial.println("start:B");
    delay(100);
    digitalWrite(intB1, LOW);
    digitalWrite(intB2, LOW);
    analogWrite(enB, 0);

/*
    digitalWrite(intC1, LOW);
    digitalWrite(intC2, HIGH);
    analogWrite(enC, 252);
    Serial.println("start:C");
    delay(100);
    digitalWrite(intC1, LOW);
    digitalWrite(intC2, LOW);
    analogWrite(enC, 0);

    digitalWrite(intD1, LOW);
    digitalWrite(intD2, HIGH);
    analogWrite(enD, 252);
    Serial.println("start:D");
    delay(100);
    digitalWrite(intD1, LOW);
    digitalWrite(intD2, LOW);
    analogWrite(enD, 0);
*/
  }

  /*
  for(i=0; i<10; i++){
   digitalWrite(intA1, HIGH);
   digitalWrite(intA2, LOW);
   analogWrite(enA, 252);
   Serial.println("start;A");
   delay(100);
   digitalWrite(intA1, LOW);
   digitalWrite(intA2, LOW);
   analogWrite(enA, 0);
   
   digitalWrite(intB1, HIGH);
   digitalWrite(intB2, LOW);
   analogWrite(enB, 252);
   Serial.println("start:B");
   delay(100);
   digitalWrite(intB1, LOW);
   digitalWrite(intB2, LOW);
   analogWrite(enB, 0);
   
   digitalWrite(intC1, HIGH);
   digitalWrite(intC2, LOW);
   analogWrite(enC, 252);
   Serial.println("start:C");
   delay(100);
   digitalWrite(intC1, LOW);
   digitalWrite(intC2, LOW);
   analogWrite(enC, 0);
   
   digitalWrite(intD1, HIGH);
   digitalWrite(intD2, LOW);
   analogWrite(enD, 252);
   Serial.println("start:D");
   delay(100);
   digitalWrite(intD1, LOW);
   digitalWrite(intD2, LOW);
   analogWrite(enD, 0);
   }
   */
}

void CycronMode(){
  Serial.println("START");
  int i = 0;
  while(i < 10){
    PaceUp();
    PaceDown();
    i++;
  }
}

void PaceUp(){
  Serial.println("UP");
  int time;
  int count = 40;
  for(time =300; time >= 0 && time <= 300; time = time - count){
    //Serial.print("nowtime:");
    //Serial.println(time);
    //delay(time);
    
    digitalWrite(intA1, LOW);
    digitalWrite(intA2, HIGH);
    analogWrite(enA, 252);
    Serial.println("start;A");
    delay(time);
    digitalWrite(intA1, LOW);
    digitalWrite(intA2, LOW);
    analogWrite(enA, 0);

    digitalWrite(intB1, LOW);
    digitalWrite(intB2, HIGH);
    analogWrite(enB, 252);
    Serial.println("start:B");
    delay(time);
    digitalWrite(intB1, LOW);
    digitalWrite(intB2, LOW);
    analogWrite(enB, 0);

    digitalWrite(intC1, LOW);
    digitalWrite(intC2, HIGH);
    analogWrite(enC, 252);
    Serial.println("start:C");
    delay(time);
    digitalWrite(intC1, LOW);
    digitalWrite(intC2, LOW);
    analogWrite(enC, 0);

    digitalWrite(intD1, LOW);
    digitalWrite(intD2, HIGH);
    analogWrite(enD, 252);
    Serial.println("start:D");
    delay(time);
    digitalWrite(intD1, LOW);
    digitalWrite(intD2, LOW);
    analogWrite(enD, 0);
   count--;
  }
}

void PaceDown(){
  Serial.println("DOWN");
  int time;
  int count = 10;
  for(time = 10; time <= 300 && time >= 0; time = time + count){
    //Serial.print("nowtime:");
    //Serial.println(time);
    //delay(time);
    digitalWrite(intA1, LOW);
    digitalWrite(intA2, HIGH);
    analogWrite(enA, 252);
    Serial.println("start;A");
    delay(time);
    digitalWrite(intA1, LOW);
    digitalWrite(intA2, LOW);
    analogWrite(enA, 0);

    digitalWrite(intB1, LOW);
    digitalWrite(intB2, HIGH);
    analogWrite(enB, 252);
    Serial.println("start:B");
    delay(time);
    digitalWrite(intB1, LOW);
    digitalWrite(intB2, LOW);
    analogWrite(enB, 0);

    digitalWrite(intC1, LOW);
    digitalWrite(intC2, HIGH);
    analogWrite(enC, 252);
    Serial.println("start:C");
    delay(time);
    digitalWrite(intC1, LOW);
    digitalWrite(intC2, LOW);
    analogWrite(enC, 0);

    digitalWrite(intD1, LOW);
    digitalWrite(intD2, HIGH);
    analogWrite(enD, 252);
    Serial.println("start:D");
    delay(time);
    digitalWrite(intD1, LOW);
    digitalWrite(intD2, LOW);
    analogWrite(enD, 0);
    count++;
  }
}

void DirectionMode (){
  Serial.println("START");
  int c = 0;
  while(c < 10){
    /*motorDir = true;
    delay(100);
    motorDir = false;
    delay(100);
    */
    digitalWrite(intD1, HIGH);
    digitalWrite(intD2, LOW);
    delay(100);
    digitalWrite(intD1, LOW);
    digitalWrite(intD2, HIGH);
    delay(100);
    c++;
  }
}

void Nanabyoushi(){
  Serial.println("START");
  /*
  for(int i=0; i<=20; i++){
  digitalWrite(intA1, HIGH);
  digitalWrite(intA2, LOW);
  analogWrite(enA, 252);
  digitalWrite(intB1, LOW);
  digitalWrite(intB1, LOW);
  analogWrite(enB, 0);
  delay(300);
  digitalWrite(intA1, LOW);
  digitalWrite(intA2, LOW);
  analogWrite(enA, 0);
  digitalWrite(intB1, HIGH);
  digitalWrite(intB2, LOW);
  analogWrite(enB, 252);
  delay(300);
  digitalWrite(intA1, HIGH);
  digitalWrite(intA2, LOW);
  analogWrite(enA, 252);
  digitalWrite(intB1, LOW);
  digitalWrite(intB1, LOW);
  analogWrite(enB, 0);
  delay(300);
  digitalWrite(intA1, LOW);
  digitalWrite(intA2, LOW);
  analogWrite(enA, 0);
  digitalWrite(intB1, LOW);
  digitalWrite(intB1, LOW);
  analogWrite(enB, 0);
  delay(500);
  */
   for(int i=0; i<=20; i++){
  digitalWrite(intA1, HIGH);
  digitalWrite(intA2, LOW);
  analogWrite(enA, 252);
  delay(100);
  digitalWrite(intA1, LOW);
  digitalWrite(intA2, LOW);
  analogWrite(enA, 0);
  delay(100);
  
  if(i % 5 == 0){
    digitalWrite(intB1, LOW);
  digitalWrite(intB1, LOW);
  analogWrite(enB, 0);
  delay(300);
  i++;
  Serial.println("I");
  }
  
}

//======ActiveMotor関数を呼び出す鑵子======//

//======StopMotor関数を呼び出す鑵子======//

//=================StopMotor関数======================//

//================ActiveMotor関数=====================//






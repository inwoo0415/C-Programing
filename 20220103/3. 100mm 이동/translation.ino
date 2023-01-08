#include <NewPing.h>

#define F_SONAR 8 // 전방 초음파 센서 핑을 8번에 연결
#define R_SONAR 10 // 오른쪽 초음파 센서 핑을 10번에 연결
#define L_SONAR 11 // 왼쪽 초음파 센서 핑을 11번에 연결
#define INL_1 2
#define INL_2 3
#define ENL 5

#define INR_1 7
#define INR_2 4
#define ENR 6
#define MAXDISTANCE 200

NewPing F_sensor(F_SONAR,F_SONAR,MAXDISTANCE);
float F_distance = 0; //정면 초음파 센서값을 저장할 변수 선언
NewPing L_sensor(L_SONAR,L_SONAR,MAXDISTANCE);
float L_distance = 0; //왼쪽 초음파 센서값을 저장할 변수 선언
NewPing R_sensor(R_SONAR,R_SONAR,MAXDISTANCE);
float R_distance =0; //오른쪽 초음파 센서값을 저장할 변수 선언


void GO(int t, int L_speed, int R_speed)
{
  digitalWrite(INL_2,HIGH);
  digitalWrite(INL_1,LOW);
  digitalWrite(INR_1,HIGH);
  digitalWrite(INR_2,LOW);
  analogWrite(ENL, L_speed);
  analogWrite(ENR, R_speed);
  delay(t);
  }
void Back(int t, int L_speed, int R_speed)
{
  digitalWrite(INL_2,HIGH);
  digitalWrite(INL_1,LOW);
  digitalWrite(INR_2,HIGH);
  digitalWrite(INL_1,LOW);
  analogWrite(ENL,L_speed);
  analogWrite(ENR,R_speed);
  delay(t);
}
 
void Right(int t,int L_speed, int R_speed)
{
  digitalWrite(INL_2,HIGH);
  digitalWrite(INL_1,LOW);
  digitalWrite(INR_2,HIGH);
  digitalWrite(INR_1,LOW);
  analogWrite(ENL,L_speed);
  analogWrite(ENR,R_speed);
  delay(t);
}
 
void Left(int t,int L_speed, int R_speed)
{
  digitalWrite(INL_2,HIGH);
  digitalWrite(INL_1,LOW);
 
  digitalWrite(INR_1,HIGH);
  digitalWrite(INR_2,LOW);
  analogWrite(ENL,L_speed);
  analogWrite(ENR,R_speed);
  delay(t);
  }  
void Stop(int t, int L_speed, int R_speed )
{
  digitalWrite(INL_1,LOW);
  digitalWrite(INL_2,LOW);
  digitalWrite(INR_2,LOW);
  digitalWrite(INR_1,LOW);
  analogWrite(ENL,L_speed);
  analogWrite(ENR,R_speed);
  delay(t);
}



float F_distance_D_1 = 0.0;
float F_distance_D_2 = 0.0;

float R_distance_D_1 = 0.0;
float R_distance_D_2 = 0.0;

float L_distance_D_1 = 0.0;
float L_distance_D_2 = 0.0;
float ang = 0.0;

void go_foward()
{
  float F_distance_D_1 = 0.0;
  float F_distance_D_2 = 0.0;
  float F_distance_D_3 = 0.0;
  
  float R_distance_D_1 = 0.0;
  float R_distance_D_2 = 0.0;
  float R_distance_D_3 = 0.0;

  float L_distance_D_1 = 0.0;
  float L_distance_D_2 = 0.0;
  float L_distance_D_3 = 0.0;
  
  float ang = 0.0;
  
  F_distance_D_1 = (float)(F_sensor.ping())*10;
  L_distance_D_1 = (float)(F_sensor.ping())*10;
  R_distance_D_1 = (float)(F_sensor.ping())*10;
  
  GO(1, 50, 50);
  delay(800);
  Stop(1, 0, 0);
  delay(800);
  
  F_distance_D_2 = (float)(F_sensor.ping())*10;
  L_distance_D_2 = (float)(F_sensor.ping())*10;
  R_distance_D_2 = (float)(F_sensor.ping())*10;

  F_distance_D_3 = F_distance_D_1 - F_distance_D_2;
  L_distance_D_3 = L_distance_D_1 - L_distance_D_2;
  R_distance_D_3 = R_distance_D_1 - R_distance_D_2;

  ang = atan(F_distance_D_3 / R_distance_D_3)*(180/3.1415);


  
  Serial.print("F1 : ");
  Serial.println(F_distance_D_1);
  Serial.println();
  Serial.print("F2 : ");
  Serial.println(F_distance_D_2);
  Serial.println();
  Serial.print("F3 : ");
  Serial.println(F_distance_D_3);
  Serial.println();

  Serial.print("R1 : ");
  Serial.println(R_distance_D_1);
  Serial.println();
  Serial.print("R2 : ");
  Serial.println(R_distance_D_2);
  Serial.print("R3 : ");
  Serial.println(R_distance_D_3);
  Serial.println();
  
  Serial.print("ang : ");
  Serial.println(ang);

 }
 
  

void setup()
{
  // put your setup code here, to run once:
  pinMode(F_SONAR, OUTPUT); // 전방 초음파 센서 출력
  pinMode(R_SONAR, OUTPUT); // 오른쪽 초음파 센서 출력
  pinMode(L_SONAR, OUTPUT); // 왼쪽 초음파 센서 출력
  Serial.begin(115200);
  pinMode(INL_1, OUTPUT);
  pinMode(INL_2, OUTPUT);
  pinMode(INR_1, OUTPUT);
  pinMode(INR_2, OUTPUT);
  analogWrite(ENL, 100);
  analogWrite(ENR, 100);

   go_foward();
}



void loop()
{
  
       
}

 
 

#include <NewPing.h>
#define MAX_DISTANCE 150

#define F_SONAR 8 // 전방 초음파 센서 핑을 8번에 연결
#define R_SONAR 10 // 오른쪽 초음파 센서 핑을 10번에 연결
#define L_SONAR 11 // 왼쪽 초음파 센서 핑을 11번에 연결
#define INL_1 2
#define INL_2 3
#define ENL 5

#define INR_1 7
#define INR_2 4
#define ENR 6

#define Total_width 300
#define error 5





NewPing F_sensor(F_SONAR,F_SONAR,MAX_DISTANCE);
float F_distance = 0; //정면 초음파 센서값을 저장할 변수 선언
NewPing L_sensor(L_SONAR,L_SONAR,MAX_DISTANCE);
float L_distance = 0; //왼쪽 초음파 센서값을 저장할 변수 선언
NewPing R_sensor(R_SONAR,R_SONAR,MAX_DISTANCE);
float R_distance =0; //오른쪽 초음파 센서값을 저장할 변수 선언


float R_Sonar_Distance = 0.0;

float R_Sonar_Error = 0.0;


float L_Sonar_Distance = 0.0;

float L_Sonar_Error = 0.0;

float F_Sonar_Distance = 0.0;

float motor_different = 0.0;

float ck_L=0;
float ck_R=0;



void read_sonar_sensor(void) // 초음파 센서 값을 읽는 함수
{

    R_Sonar_Distance = R_sensor.ping_cm()*10.; // 각자에 맞도록 센서 번호 설정
    L_Sonar_Distance = L_sensor.ping_cm()*10.;
    F_Sonar_Distance = F_sensor.ping_cm()*10.;
    
    if(R_Sonar_Distance == 0) R_Sonar_Distance = MAX_DISTANCE * 10.0;
    if(L_Sonar_Distance == 0) L_Sonar_Distance = MAX_DISTANCE * 10.0;
    if(F_Sonar_Distance == 0) F_Sonar_Distance = MAX_DISTANCE * 10.0;
    
    
}

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
 
/*void GO(int t, int L_speed, int R_speed)
{
  digitalWrite(INL_1,HIGH);
  digitalWrite(INL_2,LOW);
  digitalWrite(INR_2,HIGH);
  digitalWrite(INR_1,LOW);
  analogWrite(ENL, L_speed);
  analogWrite(ENR, R_speed);
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
  digitalWrite(INL_1,HIGH);
  digitalWrite(INL_2,LOW);
  digitalWrite(INR_1,HIGH);
  digitalWrite(INR_2,LOW);
  analogWrite(ENL,L_speed);
  analogWrite(ENR,R_speed);
  delay(t);
  }*/  
void Stop(int t)
{
  digitalWrite(INL_1,LOW);
  digitalWrite(INL_2,LOW);
  digitalWrite(INR_2,LOW);
  digitalWrite(INR_1,LOW);
  delay(t);
}




void setup() 
{
  Serial.begin(115200);
  pinMode(INL_1, OUTPUT);
  pinMode(INL_2, OUTPUT);
  pinMode(INR_1, OUTPUT);
  pinMode(INR_2, OUTPUT);
  analogWrite(ENL, 80);
  analogWrite(ENR, 80);



}

float min_distance=100000;

int ck=0;


void loop() 
{   
    
    read_sonar_sensor();

    motor_different=R_Sonar_Distance-L_Sonar_Distance;
    
    ck_L=60+motor_different*0.4;
    ck_R=60-motor_different*0.4;

    if(ck_L<0) // 속도값이 -값이 나오지 않도록 설정
    {ck_L=0;}
    if(ck_L>200)
    {ck_L=200;}
    if(ck_R<0)
    {ck_R=0;}
    if(ck_R>200) // 속도값이 최대속도 이상으로 나오지 않게 설정
    {ck_R=200;}

    if(Total_width+error*2 >= R_Sonar_Distance+L_Sonar_Distance && R_Sonar_Distance==L_Sonar_Distance)
    {
      GO(1,ck_L,ck_R);
      ck=0;
    }

    
    else if(R_Sonar_Distance<=L_Sonar_Distance+error && R_Sonar_Distance>=L_Sonar_Distance-error)
    {
      if(ck<0){
        while(1){
          read_sonar_sensor();
          Right(1,60, 100);
          if(Total_width+error*4>=R_Sonar_Distance+L_Sonar_Distance){break;}
          }
      }
      else{
        while(1){
          read_sonar_sensor();
          Left(1,100,60);
          if(Total_width+error*4>=R_Sonar_Distance+L_Sonar_Distance){break;}
          }
        }
    }

    
    
    else
    {
      GO(1,ck_L,ck_R);
      ck=ck_R-ck_L;
    }


}

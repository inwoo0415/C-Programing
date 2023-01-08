
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



int motor_different = 0.0;


NewPing F_sensor(F_SONAR,F_SONAR,MAX_DISTANCE);
float F_distance = 0; //정면 초음파 센서값을 저장할 변수 선언
NewPing L_sensor(L_SONAR,L_SONAR,MAX_DISTANCE);
float L_distance = 0; //왼쪽 초음파 센서값을 저장할 변수 선언
NewPing R_sensor(R_SONAR,R_SONAR,MAX_DISTANCE);
float R_distance =0; //오른쪽 초음파 센서값을 저장할 변수 선언


float R_Sonar_Distance = 0.0;
float R_Sonar_Distance_old = 0.0;
float R_Sonar_Error = 0.0;


float L_Sonar_Distance = 0.0;
float L_Sonar_Distance_old = 0.0;
float L_Sonar_Error = 0.0;

float F_Sonar_Distance = 0.0;
float F_Sonar_Distance_old = 0.0;
float F_Sonar_Error = 0.0;

void read_sonar_sensor(void) // 초음파 센서 값을 읽는 함수
{

    R_Sonar_Distance = R_sensor.ping_cm()*10.; // 각자에 맞도록 센서 번호 설정
    L_Sonar_Distance = L_sensor.ping_cm()*10.;
    F_Sonar_Distance = F_sensor.ping_cm()*10.;
    
    if(R_Sonar_Distance == 0) R_Sonar_Distance = MAX_DISTANCE * 10.0;
    if(L_Sonar_Distance == 0) L_Sonar_Distance = MAX_DISTANCE * 10.0;
    if(F_Sonar_Distance == 0) F_Sonar_Distance = MAX_DISTANCE * 10.0;
    
    
}

void update_sonar_old(void)
{
    R_Sonar_Distance_old = R_Sonar_Distance; // 과거 값을 현재 값을 대입
    L_Sonar_Distance_old = L_Sonar_Distance;
    F_Sonar_Distance_old = F_Sonar_Distance;

}

void update_sonar_error(void)
{
  R_Sonar_Error = R_Sonar_Distance - R_Sonar_Distance_old;  // 움직일때마다 틀어진 값
  L_Sonar_Error = L_Sonar_Distance - L_Sonar_Distance_old;
  F_Sonar_Error = F_Sonar_Distance - F_Sonar_Distance_old;

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
void Back(int t, int L_speed, int R_speed)
{
  digitalWrite(INL_1,HIGH);
  digitalWrite(INL_2,LOW);
  digitalWrite(INR_2,HIGH);
  digitalWrite(INR_1,LOW);
  analogWrite(ENL,L_speed);
  analogWrite(ENR,R_speed);
  delay(t);
}
 
void Right(int t,int L_speed, int R_speed)
{
   digitalWrite(INL_2,HIGH);
  digitalWrite(INL_1,LOW);
  digitalWrite(INR_2,HIGH);
  digitalWrite(INL_1,LOW);
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
  analogWrite(ENL, 100);
  analogWrite(ENR, 100);




}

void loop() 
{
    float P_gain = 0.5;
    read_sonar_sensor(); // 순서 외우기 -> 현재 값 구하고 에러 구하고 과거값 구하기 !! 순서 틀리면 과거값하고 현재값이 같음.
    update_sonar_error();
    update_sonar_old();
    Serial.print(R_Sonar_Distance); Serial.print("\t ");
    Serial.print(R_Sonar_Distance_old); Serial.print("\t ");
    Serial.println(R_Sonar_Error); 
    motor_different = R_Sonar_Error*P_gain;
    GO(1, 50 - motor_different, 90 + motor_different);
    delay(300);
   
}

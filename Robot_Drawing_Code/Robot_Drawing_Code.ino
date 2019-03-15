int motor1F = 6;
int motor1R = 5;
int motor2F = 9; 
int motor2R = 10; 
int motor1E = 7;
int motor2E = 3;
int delayTime = 3000;
int button1 = A0;
int button2 = A3;
int button3 = A6;

//5, 6, 9, 10

void setup() 
{
  pinMode(motor1F, OUTPUT);
  pinMode(motor1R, OUTPUT);
  pinMode(motor2F, OUTPUT);
  pinMode(motor2R, OUTPUT);
  pinMode(motor1E, OUTPUT);
  pinMode(motor2E, OUTPUT);
  pinMode(button1, INPUT);
  randomSeed(analogRead(0));
  Serial.begin(9600);
}

void stop()
{
  digitalWrite(motor1E, LOW);
  digitalWrite(motor2E, LOW);
}

//Forward, Backwards, Left, Right Initializer
void goF(int speed, int time) //Go Forward, speed(0 - 255), time(Seconds)
{
  digitalWrite(motor1E, HIGH);
  digitalWrite(motor2E, HIGH);
  analogWrite(motor1F, speed); //Motor 1 full speed in forward 
  analogWrite(motor1R, 0); //Motor 1 does not move in reverse
  analogWrite(motor2F, speed); //Motor 2 full speed in forward 
  analogWrite(motor2R, 0); //Motor 2 does not move in reverse
  delay(time);
  stop();
}
void goB(int speed, int time) //Go Forward, speed(0 - 255), time(Seconds)
{
  digitalWrite(motor1E, HIGH);
  digitalWrite(motor2E, HIGH);
  analogWrite(motor1F, 0); //Motor 1 full speed in forward 
  analogWrite(motor1R, speed); //Motor 1 does not move in reverse
  analogWrite(motor2F, 0); //Motor 2 full speed in forward 
  analogWrite(motor2R, speed); //Motor 2 does not move in reverse
  delay(time);
  stop();
}
void turnL(int speed, int time) //Turn Left, speed(0 - 255), time(Seconds)
{
  digitalWrite(motor1E, HIGH);
  digitalWrite(motor2E, HIGH);

  analogWrite(motor1F, 0); //Motor 1 does not move in forward 
  analogWrite(motor1R, speed); //Motor 1 does not move in reverse
  analogWrite(motor2F, speed); //Motor 2 full speed in forward 
  analogWrite(motor2R, 0); //Motor 2 does not move in reverse
  delay(time);
  stop();
}
void turnR(int speed, int time) //Turn Right, speed(0 - 255), time(Seconds)
{
  digitalWrite(motor1E, HIGH);
  digitalWrite(motor2E, HIGH);

  analogWrite(motor1F, speed); //Motor 1 full speed in forward 
  analogWrite(motor1R, 0); //Motor 1 does not move in reverse
  analogWrite(motor2F, 0); //Motor 2 does not move in forward 
  analogWrite(motor2R, speed); //Motor 2 does not move in reverse
  delay(time);
  stop();
  
}




void move(int fM1_speed, int fM2_speed, int rM1_speed, int rM2_speed, int time1)
{
  digitalWrite(motor1E, HIGH);
  digitalWrite(motor2E, HIGH);

  analogWrite(motor1F, fM1_speed); //Motor 1 forward 
  analogWrite(motor1R, rM1_speed); //Motor 1 reverse
  analogWrite(motor2F, fM2_speed); //Motor 2 forward 
  analogWrite(motor2R, rM2_speed); //Motor 2 reverse

  delay(time1);
  stop();

}

void square()
{
  int time = 4000;
  int speed = 255;
  int i;
  for(i = 0; i < 4; i++)
  {
    goF(speed, 2000);
    turnR(speed, 6500);
    
  }
 
}

void diagnol1()
{
  int time = 4000;
  int speed = 255;
  int i;
  for(i = 0; i < 20; i++)
  {
    goF(speed, 2000);
    turnR(speed, 7000);
    
  }
 
}


void circle()
{
  move(255, 0, 0, 150, 35000); 
}

void swirl(float mul, float time1)// Multiplyer changes distance between rings, Time1 changes time.
{//Good swirl value: .8, 120000
  float i;
  float num;
  float num2;
  float incr = 1000;
  for(i = 1000; i <= time1; i+= incr)
  {
    digitalWrite(motor1E, HIGH);
    digitalWrite(motor2E, HIGH);
   
    num = ((-255/time1)*(((mul)*i)-time1));
    Serial.print("motor speed:");
    Serial.print(num);
    Serial.print("\t time:");
    Serial.print(i/1000);
    Serial.print("\n");
    //num2 = (255/time1)*i;
    analogWrite(motor1F, 255);
    analogWrite(motor2R, num);
    delay(incr);
  }

    Serial.print("Done\n");
    delay(10000);
}




void square_in_circle()
{
  int time = 4000;
  int speed = 255;
  int i, j;
  
  for(j = 0; i < 8; j++)
  {  for(i = 0; i < 4; i++)
    {
      goF(speed, 2000);
      turnR(speed, 6500);
    }
    turnL(speed, 3500);
  }
}
  

void infinity()
{
  move(255, 0, 0, 200, 30000); //fM1_speed, fM2_speed, rM1_speed, rM2_speed, time1
  delay(1000);
  move(0, 255, 200, 0, 30000);
}


void loop() 
{
   Serial.print(analogRead(button1));
   Serial.print("\t");
   Serial.print(analogRead(button2));
   Serial.print("\t");
   Serial.println(analogRead(button3));
   if(analogRead(button1) != 0)
   {
      swirl(.8, 12000);
      stop();
   }
   if(analogRead(button2) != 0)
   {
    infinity();
    stop();
   }
   if(analogRead(button3) != 0)
   {
    
   }
   stop();
   
  
}

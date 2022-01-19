
#define SENSE 13 //IR sensor's pin set
#define EN1 12 //motor 1's pin set
#define EN2 11 //motor 2's pin set
#define IN1 10 //motor 1's terminal
#define IN2 9 //motor 1's another terminal
#define IN3 8 //motor 2's terminal
#define IN4 7 //motor 2's another terminal
void setup (){
pinMode (SENSE,INPUT); //Sensor's value set as input
pinMode (EN1,OUTPUT); //Motor's Value set as output
pinMode (EN2,OUTPUT); //Motor 2's Value set as output
pinMode (IN1,OUTPUT); //motor terminal set as Output
pinMode (IN2,OUTPUT); //motor terminal set as Output
pinMode (IN3,OUTPUT); //motor terminal set as Output
pinMode (IN4,OUTPUT); //motor terminal set as Output
}

void loop (){
  int statusIR = digitalRead(SENSE); //reading the value of sendor countinusely

  digitalWrite (EN1,HIGH); //set motor 1 high
  digitalWrite (EN2,HIGH); //set motor 2 high
  if(statusIR == 0) //if sensor found an obstacle
  {
    digitalWrite (IN1,LOW); //<--------|
    digitalWrite (IN2,LOW); //         |-------------->Stop
    digitalWrite (IN3,LOW); //         |
    digitalWrite (IN4,LOW); //<--------|
    delay (100); //wait 100 milliseconds
    digitalWrite (IN1,LOW); //<--------|
    digitalWrite (IN2,HIGH);//         |-------------->Move Back!
    digitalWrite (IN3,LOW); //         |
    digitalWrite (IN4,HIGH);//<--------|
    delay (500); //wait 500 milliseconds
    digitalWrite (IN1,HIGH);//<--------|
    digitalWrite (IN2,LOW); //         |--------------->Turn left
    digitalWrite (IN3,LOW); //         |
    digitalWrite (IN4,HIGH);//<--------|
   delay (1000);//wait 1 second
   }
  else if (statusIR==1); //if there is no obstacle ahead
   {
  delay(1000);//wait 1 second
    
  digitalWrite (IN1,HIGH);//<--------|
  digitalWrite (IN2,LOW); //         |--------------->Go front
  digitalWrite (IN3,HIGH);//         |
  digitalWrite (IN4,LOW); //<--------|
   }   
  }

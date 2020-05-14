//Define IR Sensor pins
#define R A0     // Right_Sensor o/p
#define M A1     // Middle_Sensor o/p
#define L A2     // Left_sensor o/p

// Define the Motor pins 
# define Right_motor_pin_pos  12     
# define Enable_rigth  6   
# define Enable_left  5   
# define Left_motor_pin_pos  4      


void setup()  {
  pinMode(Enable_rigth, OUTPUT);  
  pinMode(Enable_left, OUTPUT);  
  pinMode(Left_motor_pin_pos, OUTPUT);   
  pinMode(Left_motor_pin_neg, OUTPUT);    
  pinMode(Right_motor_pin_pos_pos, OUTPUT);  
  pinMode(Right_motor_pin_neg, OUTPUT);  
  
  
  digitalWrite (Enable_left, HIGH);  // HIGH means left motor is enabled
  digitalWrite (Enable_rigth, HIGH);  // Right motor is enabled
  
  pinMode(R, INPUT);  //Rigth sensor pin
  pinMode(L, INPUT);  //Left Sensor pin
  pinMode(M, INPUT);  // Middle Sensor pin.
} 


void loop()  {
  
// If only middle sensor doesnot give output value go straight.
       if ((digitalRead(L)) && (!digitalRead(M)) && (digitalRead(R))) {
        digitalWrite (Left_motor_pin_pos,HIGH);
        digitalWrite (Right_motor_pin_pos,HIGH);
        }
        
// If only the left sensor doesnot give output, then turn left
       if ((!digitalRead(L)) && (digitalRead(M)) && (digitalRead(R))) {
        digitalWrite (Left_motor_pin_pos,LOW);
        digitalWrite (Right_motor_pin_pos,HIGH);
       }

// If only the right sensor doesnot give output, then turn right
       if ((digitalRead(L)) && (digitalRead(M)) && (!digitalRead(R))) {
        digitalWrite (Left_motor_pin_pos,HIGH);
        digitalWrite (Right_motor_pin_pos,LOW);
       }

}

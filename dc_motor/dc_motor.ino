const int LEFT_MOTOR_ENA = 13;  
const int LEFT_MOTOR_IN1 = 12;  
const int LEFT_MOTOR_IN2 = 14;  

const int RIGHT_MOTOR_ENB = 27; 
const int RIGHT_MOTOR_IN3 = 26; 
const int RIGHT_MOTOR_IN4 = 25; 

const int LEFT_MOTOR_CHANNEL = 0;
const int RIGHT_MOTOR_CHANNEL = 1;

void setup() {
  Serial.begin(115200);
  
  pinMode(LEFT_MOTOR_IN1, OUTPUT);
  pinMode(LEFT_MOTOR_IN2, OUTPUT);
  pinMode(RIGHT_MOTOR_IN3, OUTPUT);
  pinMode(RIGHT_MOTOR_IN4, OUTPUT);
  
  Serial.println("ESP32 L298N Motor Control Initialized");
  Serial.println("Commands: ");
  Serial.println("F - Forward");
  Serial.println("B - Backward");
  Serial.println("L - Turn Left");
  Serial.println("R - Turn Right");
  Serial.println("S - Stop");
  Serial.println("0-9 - Speed control (0=min, 9=max)");
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();
    
    switch(command) {
      case 'F': 
        moveForward();
        break;
      case 'B': 
        moveBackward();
        break;
      case 'L': 
        turnLeft();
        break;
      case 'R': 
        turnRight();
        break;
      case 'S': 
        stopMotors();
        break;
      case '0'...'9':
        setSpeed(map(command - '0', 0, 9, 0, 255));
        break;
    }
  }
}

void setSpeed(int speed) {
  ledcWrite(LEFT_MOTOR_CHANNEL, speed);
  ledcWrite(RIGHT_MOTOR_CHANNEL, speed);
  Serial.print("Speed set to: ");
  Serial.println(speed);
}

void moveForward() {
  digitalWrite(LEFT_MOTOR_IN1, HIGH);
  digitalWrite(LEFT_MOTOR_IN2, LOW);
  digitalWrite(RIGHT_MOTOR_IN3, HIGH);
  digitalWrite(RIGHT_MOTOR_IN4, LOW);
  Serial.println("Moving Forward");
}

void moveBackward() {
  digitalWrite(LEFT_MOTOR_IN1, LOW);
  digitalWrite(LEFT_MOTOR_IN2, HIGH);
  digitalWrite(RIGHT_MOTOR_IN3, LOW);
  digitalWrite(RIGHT_MOTOR_IN4, HIGH);
  Serial.println("Moving Backward");
}

void turnLeft() {
  digitalWrite(LEFT_MOTOR_IN1, LOW);
  digitalWrite(LEFT_MOTOR_IN2, HIGH);
  digitalWrite(RIGHT_MOTOR_IN3, HIGH);
  digitalWrite(RIGHT_MOTOR_IN4, LOW);
  Serial.println("Turning Left");
}

void turnRight() {
  digitalWrite(LEFT_MOTOR_IN1, HIGH);
  digitalWrite(LEFT_MOTOR_IN2, LOW);
  digitalWrite(RIGHT_MOTOR_IN3, LOW);
  digitalWrite(RIGHT_MOTOR_IN4, HIGH);
  Serial.println("Turning Right");
}

void stopMotors() {
  digitalWrite(LEFT_MOTOR_IN1, LOW);
  digitalWrite(LEFT_MOTOR_IN2, LOW);
  digitalWrite(RIGHT_MOTOR_IN3, LOW);
  digitalWrite(RIGHT_MOTOR_IN4, LOW);
  Serial.println("Stopped");
}

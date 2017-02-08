//CODY CAMPBELL
//PROJECT CONTRIVE
//This code is adapted from the magsensor example code provided by adafruit.

//select "USB Keyboard" from the Tools-> USB Type menu to use keyboard/mouse functionality of the teensy 3.2

//using this i2c library to access SDA1 and SCL1 from the back of the teensy
#include <i2c_t3-master>

//make sure these libraries reference WIRE1 instead of WIRE
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>

/* Assign a unique ID to this sensor at the same time */
Adafruit_LSM303_Mag_Unified mag = Adafruit_LSM303_Mag_Unified(12345);

void displaySensorDetails(void){
  sensor_t sensor;
  mag.getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" uT");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" uT");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" uT");
  Serial.println("------------------------------------");
  Serial.println("");
  delay(500);
}

void setup(void){
  Serial.begin(9600);
  Serial.println("Magnetometer Test"); Serial.println("");

  /* Enable auto-gain */
  mag.enableAutoRange(true);

  /* Initialise the sensor */
  if(!mag.begin()){
    /* There was a problem detecting the LSM303 ... check your connections */
    Serial.println("No LSM303 detected, check libraries!! (adafruit libraries must reference wire1 - NOT wire)");
    Serial.println("entering infinite loop");
    while(1);
  }

  /* Display some basic information on this sensor */
  displaySensorDetails();
}

void loop(void){
  /* Get a new sensor event */
  sensors_event_t event;
  mag.getEvent(&event);

  //check capacitive button for mode switching

  //check up
  if(event.magnetic.y > ) upDown =  1;
  if(event.magnetic.y < ) upDown = -1;

  //check left + right
  if(event.magnetic.x > ) leftRight =  1;
  if(event.magnetic.x < ) leftRight = -1;


  //check if up/down or left/right released
  if((event.magnetic.y > ) && (event.magnetic.y < )) upDown = 0;
  if((event.magnetic.x > ) && (event.magnetic.x < )) leftRight = 0;

  //push input updates
  pushInput(inputMode, upDown, leftRight);
}


void pushInput(int inputMode, int upDown, int leftRight){
  switch(inputMode){
    //arrow keys
    case 0:
      //up/down
      if(upDown ==  1) Keyboard.set_key1(KEY_UP);
      if(upDown == -1) Keyboard.set_key1(KEY_DOWN);
      //left/right
      if(leftRight ==  1) Keyboard.set_key2(KEY_RIGHT);
      if(leftRight == -1) Keyboard.set_key2(KEY_LEFT);
      //off?
      if(upDown    == 0) Keyboard.set_key1(0);
      if(leftRight == 0) Keyboard.set_key2(0);
      break;
      
    //WASD
    case 1:
      //up/down
      if(upDown ==  1) Keyboard.set_key1(KEY_W);
      if(upDown == -1) Keyboard.set_key1(KEY_S);
      //left/right
      if(leftRight ==  1) Keyboard.set_key2(KEY_D);
      if(leftRight == -1) Keyboard.set_key2(KEY_A);
      //off?
      if(upDown    == 0) Keyboard.set_key1(0);
      if(leftRight == 0) Keyboard.set_key2(0);
      break;

    //Mouse
    case 2:
      Mouse.move(leftRight, upDown);
  }
}



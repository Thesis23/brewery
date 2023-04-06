#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;
Adafruit_MPU6050 mpu2;
const int MPU_addr_1 = 0x68; // I2C address of the first MPU-6050
const int MPU_addr_2 = 0x69; // I2C address of the second MPU-6050

void setup(void) {
  Serial.begin(115200);

  // Try to initialize!
  if (!mpu.begin(MPU_addr_1)) {
    Serial.println("Failed to find MPU6050 1 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 1 Found!");

  // set accelerometer range to +-8G
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);

  // set gyro range to +- 500 deg/s
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);

  // set filter bandwidth to 21 Hz
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  delay(100);



  // Try to initialize!
  if (!mpu2.begin(MPU_addr_2)) {
    Serial.println("Failed to find MPU6050 2 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 2 Found!");

  // set accelerometer range to +-8G
  mpu2.setAccelerometerRange(MPU6050_RANGE_8_G);

  // set gyro range to +- 500 deg/s
  mpu2.setGyroRange(MPU6050_RANGE_500_DEG);

  // set filter bandwidth to 21 Hz
  mpu2.setFilterBandwidth(MPU6050_BAND_21_HZ);

  delay(100);
  
}

void loop() {
  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  Serial.print("0");
  Serial.print(",");
  /* Print out the values */
  //Serial.print("Acceleration X: ");
  Serial.print(a.acceleration.x);
  Serial.print(",");
  //Serial.print(", Y: ");
  Serial.print(a.acceleration.y);
  Serial.print(",");
  //Serial.print(", Z: ");
  Serial.print(a.acceleration.z);
  Serial.print(",");
  //Serial.println(" m/s^2");

  //Serial.print("Rotation X: ");
  Serial.print(g.gyro.x);
  Serial.print(",");
  //Serial.print(", Y: ");
  Serial.print(g.gyro.y);
  Serial.print(",");
  //Serial.print(", Z: ");
  Serial.print(g.gyro.z);
  Serial.print(",");
  //Serial.println(" rad/s");

  //Serial.print("Temperature: ");
  Serial.print(temp.temperature);
  //Serial.println(" degC");
  Serial.println("");



  /* Get new sensor events with the readings */
  sensors_event_t a1, g1, temp1;
  mpu2.getEvent(&a1, &g1, &temp1);
  Serial.print("1");
  Serial.print(",");
  /* Print out the values */
  //Serial.print("Acceleration X: ");
  Serial.print(a1.acceleration.x);
  Serial.print(",");
  //Serial.print(", Y: ");
  Serial.print(a1.acceleration.y);
  Serial.print(",");
  //Serial.print(", Z: ");
  Serial.print(a1.acceleration.z);
  Serial.print(",");
  //Serial.println(" m/s^2");

  //Serial.print("Rotation X: ");
  Serial.print(g1.gyro.x);
  Serial.print(",");
  //Serial.print(", Y: ");
  Serial.print(g1.gyro.y);
  Serial.print(",");
  //Serial.print(", Z: ");
  Serial.print(g1.gyro.z);
  Serial.print(",");
  //Serial.println(" rad/s");

  //Serial.print("Temperature: ");
  Serial.print(temp1.temperature);
  //Serial.println(" degC");
  Serial.println("");
  
  delay(50);
}

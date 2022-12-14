#include <Ftduino.h>

void setup() {
  Serial.begin(9600);
  ftduino.init();
  

  while (ftduino.input_get(Ftduino::I3) || ftduino.input_get(Ftduino::I4)){
    ftduino.motor_set(Ftduino::M1, Ftduino::LEFT, Ftduino::MAX/2);
    ftduino.motor_set(Ftduino::M2, Ftduino::LEFT, Ftduino::MAX/2);
    delay(2000);
  }
}
void loop() {
  // M1 + M2 = Ketten Fortbewegung
  // I1 = Sensor vorne
  // I2 = Sensor hinten
  while (ftduino.input_get(Ftduino::I3) || ftduino.input_get(Ftduino::I4)){
    ftduino.motor_set(Ftduino::M1, Ftduino::RIGHT, Ftduino::MAX/2);
    ftduino.motor_set(Ftduino::M2, Ftduino::RIGHT, Ftduino::MAX/2);
    delay(1000); //Anpassen
    ftduino.motor_set(Ftduino::M1, Ftduino::LEFT, Ftduino::MAX/2);
    ftduino.motor_set(Ftduino::M2, Ftduino::RIGHT,Ftduino::MAX/2);
    delay(2000); //anpassen
    ftduino.motor_set(Ftduino::M1, Ftduino::LEFT, Ftduino::MAX/2);
    ftduino.motor_set(Ftduino::M2, Ftduino::LEFT, Ftduino::MAX/2);
  }
}
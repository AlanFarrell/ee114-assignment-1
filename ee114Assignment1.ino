#include <ee108.h>

int index = 0;
int calc;

int input[] = {};
String input;

String msg = "your string = ???";
String msg2 = "your num = ";
String msg3 = "this number can be displayed as a 10-bit unsinged integer";
String msg4 = "error, this cannot be assigned as a 10-bit unsigned itneger";
String msg5 = "this is an even number";
String msg6 = "this is an odd numer";


int my_int = 1023;


void setup() {
  Serial.begin(9600);
}


void loop() {

  
  setup_barleds();
  readIn();
  binary_check();
  bar_chart(my_int);
  binary_convert(my_int);
  
  Serial.end();
}


void readIn() {
  Serial.println(msg);
  //waiting for the user to enter a value
  while (Serial.available() == 0) {
  }
 input = Serial.read();

 for(int i = 0; i <= num 
}


void setup_barleds () {
  for (int barledIndex = 0; barledIndex <= NUM_BAR_LEDS; barledIndex++) {
    pinMode(BAR_LED_1_PIN + barledIndex, OUTPUT);
  }
}


void binary_check() {
  //seen as 10 bits only goes from 0-1023
  //as long as it is between 0 and 1023 we can proceed
  //no need to account for negatives as then it would be signed binary digit
  if (my_int <= 1023) {
    Serial.println(msg3);
  }
  else {
    Serial.println(msg4);
  }
}


void bar_chart(byte binNum) {
  for (int i = 0; i <= 10; i++) {
    //bitread tells us whether there is a 1/0
    //for every 1 we find a light is turned on
    //else the light remains off
    if (bitRead(binNum, i) == 1) {
      digitalWrite(BAR_LED_1_PIN + i, HIGH);
    }
    else {
      digitalWrite(BAR_LED_1_PIN + i, LOW);
    }
  }

  if (BAR_LED_1_PIN == HIGH) {
    Serial.println(msg5);
  }
  else {
    Serial.println(msg6);
  }
}

void binary_convert(int n) {
  int inverse_binaryNum[16] = {};

  //manually caclulating binary using division
  //goes from LSB -> MSB
  for (int i = 0; n > 0; i++) {
    inverse_binaryNum[i] = n % 2;
    //remainder gets added to the list using MOD(modulus) operator
    n = n / 2;
    //divide N by two so the next MOD has the correct value
  }

  //printint in reverse so it is MSB -> LSB
  for (int i = 10; i >= 0; i--) {
    Serial.print(inverse_binaryNum[i]);
  }
  Serial.println(" "); //formatting
}

int input[] = {};
int stringIndex = 0;


void setup() {
  Serial.begin(9600);
}



void loop() {
  Serial.println("input pls");
  
  while (Serial.available() == 0) {
    
  }
  
  for (int i = 0; i < Serial.available(); i++) {
    input[stringIndex]  = Serial.read();
    stringIndex++;
  }
for(int i = 0; i <=  sizeof(input[0]); i++){
  Serial.print(input[i]);
}
  
  Serial.end();
}

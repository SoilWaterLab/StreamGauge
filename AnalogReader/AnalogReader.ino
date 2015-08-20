int N=4;
int t=1000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly: 
  Serial.print(millis());
  Serial.print(",");
  for(int i=0; i<N; i++){
    Serial.print(analogRead(i));
    if(i<N-1){
      Serial.print(",");
    }
  }
  Serial.print("\n");
  delay(t);
}

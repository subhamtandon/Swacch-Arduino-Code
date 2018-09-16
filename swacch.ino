int pir_out=A0;

long duration;
int distance;

int md_2=11;
int md_7=10;

int ult_in=9;
int ult_out=8;

int buzzer=7;

void setup()
{
pinMode(pir_out,INPUT);

pinMode(md_7,OUTPUT);
pinMode(md_2,OUTPUT);

pinMode(ult_in,OUTPUT);
pinMode(ult_out,INPUT);
digitalWrite(ult_in,HIGH);

pinMode(buzzer,OUTPUT);



Serial.begin(9600);
}

void loop()
{
if(digitalRead(pir_out)==HIGH)
{
 Serial.print("HIGH");
 digitalWrite(md_2,HIGH);
 digitalWrite(md_7,LOW);

 delay(3000);

 digitalWrite(md_2,LOW);
 digitalWrite(md_7,LOW);

//delay(3000);
}
else
{
  Serial.print("LOW");
  digitalWrite(md_7,HIGH);
  digitalWrite(md_2,LOW);
  delay(2000);
  digitalWrite(md_2,LOW);
  digitalWrite(md_7,LOW);
  delay(1000);
}


// Clears the trigPin
digitalWrite(ult_in, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(ult_in, HIGH);
delayMicroseconds(10);
digitalWrite(ult_in, LOW);

duration = pulseIn(ult_out, HIGH);

// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);

if(distance==6)
{
 digitalWrite(buzzer,HIGH);
}
else
{
 digitalWrite(buzzer,LOW);
}

}

int sensor = 3;
int LED = 2;

long dauer = 0;
long entfernung = 0;

bool state;

void setup()
{
  Serial.begin(9600);
  pinMode(sensor, OUTPUT);
}


void loop()
{
  pinMode(sensor, OUTPUT);
  digitalWrite(sensor, LOW);
  delayMicroseconds(2);
  digitalWrite(sensor, HIGH);
  delayMicroseconds(5);
  digitalWrite(sensor, LOW);
  pinMode(sensor, INPUT);
  long duration;
  duration = pulseIn(sensor, HIGH);
  long entfernung = duration / 29 / 2;

  state = (entfernung < 200)
  
  digitalWrite(LED, state);
    
  delay(2);
}


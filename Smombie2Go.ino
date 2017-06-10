int _pin = 3;
int LED = 2;

long dauer=0; // Das Wort dauer ist jetzt eine Variable, unter der die Zeit gespeichert wird, die eine Schallwelle bis zur Reflektion und zurück benötigt. Startwert ist hier 0.
long entfernung=0; // Das Wort „entfernung“ ist jetzt die variable, unter der die berechnete Entfernung gespeichert wird. Info: Anstelle von „int“ steht hier vor den beiden Variablen „long“. Das hat den Vorteil, dass eine größere Zahl gespeichert werden kann. Nachteil: Die Variable benötigt mehr Platz im Speicher.


void setup()
{
  Serial.begin (9600); //Serielle kommunikation starten, damit man sich später die Werte am serial monitor ansehen kann.
  pinMode(_pin, OUTPUT);
}


void loop()
{
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(_pin, HIGH);
  delayMicroseconds(5);
  digitalWrite(_pin,LOW);
  pinMode(_pin,INPUT);
  long duration;
  duration = pulseIn(_pin,HIGH);
  long entfernung = duration/29/2;

  if (!(entfernung >= 500 || entfernung <= 120))
  {
  Serial.println(entfernung);

  int t = entfernung - 20;
  digitalWrite(LED, HIGH); delay(t);
  digitalWrite(LED, LOW); delay(t);
  digitalWrite(LED, HIGH); delay(t);
  digitalWrite(LED, LOW); delay(t);
  }
  
  delay(1);
  }
}


int led_pins[] = {3,5,6,9,10,11};
double brightness[] = {0,0,0,0,0,0};
bool increasing[] = {true,true,true,true,true,true};
const int intensity = 5;

void setup()
{
  Serial.begin(9600);
  pinMode(led_pins[0],OUTPUT);
  pinMode(led_pins[1],OUTPUT);
  pinMode(led_pins[2],OUTPUT);
  pinMode(led_pins[3],OUTPUT);
  pinMode(led_pins[4],OUTPUT);
  pinMode(led_pins[5],OUTPUT);

  randomSeed(analogRead(0));

  init_random_brightness();
  init_random_increasing();
}

void loop()
{
  update_brightness();
}

void init_random_brightness()
{
  for(int i=0; i<6; i++)
  {
    brightness[i] = round(random(0,255));
    delay(10);
  }
}

void init_random_increasing()
{
  for(int i=0; i<6; i++)
  {
    if(random(0,100) % 2 == 0)
    {
      increasing[i] = true;
    }
    else
    {
      increasing[i] = false;
    }
    delay(10);
    Serial.println(random(0,100) % 2);
  }
}

void update_brightness()
{
  for(int i=0; i<6; i++)
  {
    if(increasing[i])
    {
      brightness[i] += intensity;
    }
    else
    {
      brightness[i] -= intensity;
    }

    if(brightness[i] >= 255)
    {
      brightness[i] = 255;
      increasing[i] = false;
    }
    if(brightness[i] <= 0)
    {
      brightness[i] = 0;
      increasing[i] = true;
    }

    analogWrite(led_pins[i], round(brightness[i]));
    delay(10);
  }
}



long randNumber;
const int buttonPin = A0;
const int ledPin = 13;

int buttonState = 0;


// 2-dimensional array of row pin numbers:
const int row[8] = {
  2, 7, 19, 5, 13, 18, 12, 16
};

// 2-dimensional array of column pin numbers:
const int col[8] = {
  6, 11, 10, 3, 17, 4, 8, 9
};

// 2-dimensional array of pixels:
int pixels[8][8];

// cursor position:
int x = 5;
int y = 5;
void clearChannels()
{
  digitalWrite(col[7], LOW); //col 1
  digitalWrite(col[5], LOW); //col 2
  digitalWrite(row[7], LOW); //is a col 3
  digitalWrite(col[0], LOW); // col 4
  digitalWrite(col[2], LOW); //col 5
  digitalWrite(col[4], LOW); // col 6
  digitalWrite(col[1], LOW); //col 7
  digitalWrite(row[2], LOW); //col 8?
}
void num1()
{
  clearChannels();
  digitalWrite(col[7], HIGH); //col 1
}
void num2()
{
  clearChannels();
  digitalWrite(col[7], HIGH); //col 1
  digitalWrite(col[5], HIGH); //col 2

}
void num3()
{
  clearChannels();
  digitalWrite(col[7], HIGH); //col 1
  digitalWrite(col[5], HIGH); //col 2
  digitalWrite(row[7], HIGH); //is a col 3

}
void num4()
{
  clearChannels();
   digitalWrite(col[7], HIGH); //col 1
  digitalWrite(col[5], HIGH); //col 2
  digitalWrite(row[7], HIGH); //is a col 3
  digitalWrite(col[0], HIGH); // col 4

}
void num5()
{
  clearChannels();
   digitalWrite(col[7], HIGH); //col 1
  digitalWrite(col[5], HIGH); //col 2
  digitalWrite(row[7], HIGH); //is a col 3
  digitalWrite(col[0], HIGH); // col 4
  digitalWrite(col[2], HIGH); //col 5
}

void num6()
{
   clearChannels();
   digitalWrite(col[7], HIGH); //col 1
  digitalWrite(col[5], HIGH); //col 2
  digitalWrite(row[7], HIGH); //is a col 3
  digitalWrite(col[0], HIGH); // col 4
  digitalWrite(col[2], HIGH); //col 5
  digitalWrite(col[4], HIGH); // col 6
}
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);

  randomSeed(analogRead(0));
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin, INPUT);

   for (int thisPin = 0; thisPin < 8; thisPin++) {
    // initialize the output pins:
    pinMode(col[thisPin], OUTPUT);
    pinMode(row[thisPin], OUTPUT);
    // take the col pins (i.e. the cathodes) high to ensure that the LEDS are off:
    //digitalWrite(col[thisPin], LOW);
  }
  //num2();
}

bool isPressed = false;
void loop() 
{
  buttonState = digitalRead(buttonPin);
  buttonState = analogRead(buttonPin);
  //Serial.println(buttonState);

  if(buttonState == 1023 && !isPressed)
  {
    Serial.println("BUTTON PRESED!");
    randNumber = random(7);
     Serial.println(randNumber);

    //on
    //digitalWrite(ledPin, HIGH);
    Serial.println(randNumber);
    isPressed = true;

  }
  else if(buttonState == LOW && isPressed)
  {
    //off
    isPressed = false;
    digitalWrite(ledPin, LOW);

  }

  switch(randNumber)
  {
    case 1:
      num1();
      break;
    case 2:
      num2();
      break;
    case 3:
      num3();
      break;
    case 4:
      num4();
      break;
    case 5:
      num5();
      break;
    case 6:
      num6();
      break;
  }
 

  

  //delay(180);
  // put your main code here, to run repeatedly:

}
//https://docs.arduino.cc/built-in-examples/digital/Button/

//use this for the led
//https://www.instructables.com/Connect-an-8x8-LED-matrix-to-a-Small-Breadboard/

/*digitalWrite(col[7], HIGH); //col 1
  digitalWrite(col[5], HIGH); //col 2
  digitalWrite(row[7], HIGH); //is a col 3
  digitalWrite(col[0], HIGH); // col 4
  digitalWrite(col[2], HIGH); //col 5
  digitalWrite(col[4], HIGH); // col 6
  digitalWrite(col[1], HIGH); //col 7
  digitalWrite(row[2], HIGH); //col 8? */
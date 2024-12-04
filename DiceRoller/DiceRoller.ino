#define LED PORTB
#define PB_PIN_DIRS B11111111
#define PD_PIN_DIRS B11111100
#define PC_PIN_DIRS B1111100

long randNumber;
const int buttonPin = A0;
const int ledPin = 13;

int buttonState = 0;
int state = 0;


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
void testCode()
{
  digitalWrite(col[3], HIGH); //issue
   
  digitalWrite(col[6], HIGH); //issue
   
  digitalWrite(row[0], HIGH);
  digitalWrite(row[1], HIGH); //sorta ccorrect seems to be 3 insrred if 2
  
  digitalWrite(row[3], HIGH); //row 7
  digitalWrite(row[4], HIGH);  //row 6
  digitalWrite(row[5], HIGH); //row 4
  digitalWrite(row[6], HIGH); //row 7
}
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
  //set port nine to write using output
  clearChannels();
  //digitalWrite(col[7], HIGH); //col 1
   asm (
    "sbi %0, %1 \n"
    :: "I" (_SFR_IO_ADDR(PORTB)), "I" (PORTB1)
  );


}
void num2()
{
  clearChannels();
 digitalWrite(col[7], HIGH); //col 1
   /*asm (
    "sbi %0, %1 \n"
    :: "I" (_SFR_IO_ADDR(PORTB)), "I" (PORTB1)
  );*/
  digitalWrite(col[5], HIGH); //col 2
  /* asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTD)), "I" (PORTD4)
  );*/

}
void num3()
{
  clearChannels();
  //digitalWrite(col[7], HIGH); //col 1
  asm (
    "sbi %0, %1 \n"
    :: "I" (_SFR_IO_ADDR(PORTB)), "I" (PORTB1)
  );
  //digitalWrite(col[5], HIGH); //col 2
   asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTD)), "I" (PORTD4)
  );
  //digitalWrite(row[7], HIGH); //is a col 3
    asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTC)), "I" (PORTC2)
  );


}
void num4()
{
  clearChannels();
  /* digitalWrite(col[7], HIGH); //col 1
  digitalWrite(col[5], HIGH); //col 2
  digitalWrite(row[7], HIGH); //is a col 3
  digitalWrite(col[0], HIGH); // col 4*/

  asm (
    "sbi %0, %1 \n"
    :: "I" (_SFR_IO_ADDR(PORTB)), "I" (PORTB1)
  );

  
  //digitalWrite(col[5], HIGH); //col 2
   asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTD)), "I" (PORTD4)
  );

  //digitalWrite(row[7], HIGH); //is a col 3
  asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTC)), "I" (PORTC2)
  );

  //digitalWrite(col[0], HIGH); // col 4
   asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTD)), "I" (PORTD6)
  );

}
void num5()
{
  clearChannels();
   /*digitalWrite(col[7], HIGH); //col 1
  digitalWrite(col[5], HIGH); //col 2
  digitalWrite(row[7], HIGH); //is a col 3
  digitalWrite(col[0], HIGH); // col 4
  digitalWrite(col[2], HIGH); //col 5*/

  asm (
    "sbi %0, %1 \n"
    :: "I" (_SFR_IO_ADDR(PORTB)), "I" (PORTB1)
  );

  
  //digitalWrite(col[5], HIGH); //col 2
   asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTD)), "I" (PORTD4)
  );

  //digitalWrite(row[7], HIGH); //is a col 3
  asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTC)), "I" (PORTC2)
  );

  //digitalWrite(col[0], HIGH); // col 4
   asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTD)), "I" (PORTD6)
  );
  
  //digitalWrite(col[2], HIGH); //col 5
  asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTB)), "I" (PORTB2) //might be incorrct becasue of wiring
  );
}
void num6()
{
   clearChannels();
   /*digitalWrite(col[7], HIGH); //col 1
  digitalWrite(col[5], HIGH); //col 2
  digitalWrite(row[7], HIGH); //is a col 3
  digitalWrite(col[0], HIGH); // col 4
  digitalWrite(col[2], HIGH); //col 5
  digitalWrite(col[4], HIGH); // col 6*/

  asm (
    "sbi %0, %1 \n"
    :: "I" (_SFR_IO_ADDR(PORTB)), "I" (PORTB1)
  );

  
  //digitalWrite(col[5], HIGH); //col 2
   asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTD)), "I" (PORTD4)
  );

  //digitalWrite(row[7], HIGH); //is a col 3
  asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTC)), "I" (PORTC2)
  );

  //digitalWrite(col[0], HIGH); // col 4
   asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTD)), "I" (PORTD6)
  );
  
  //digitalWrite(col[2], HIGH); //col 5
  asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTB)), "I" (PORTB2) //might be incorrct becasue of wiring
  );

  //digitalWrite(col[4], HIGH); // col 6
  asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTC)), "I" (PORTC3) 
  );
  
}
void num7()
{
   clearChannels();
   /*digitalWrite(col[7], HIGH); //col 1
  digitalWrite(col[5], HIGH); //col 2
  digitalWrite(row[7], HIGH); //is a col 3
  digitalWrite(col[0], HIGH); // col 4
  digitalWrite(col[2], HIGH); //col 5
  digitalWrite(col[4], HIGH); // col 6*/

  asm (
    "sbi %0, %1 \n"
    :: "I" (_SFR_IO_ADDR(PORTB)), "I" (PORTB1)
  );

  
  //digitalWrite(col[5], HIGH); //col 2
   asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTD)), "I" (PORTD4)
  );

  //digitalWrite(row[7], HIGH); //is a col 3
  asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTC)), "I" (PORTC2)
  );

  //digitalWrite(col[0], HIGH); // col 4
   asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTD)), "I" (PORTD6)
  );
  
  //digitalWrite(col[2], HIGH); //col 5
  asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTB)), "I" (PORTB2) //might be incorrct becasue of wiring
  );

  //digitalWrite(col[4], HIGH); // col 6
  asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTC)), "I" (PORTC3) 
  );
  //digitalWrite(col[1], HIGH); //col 7
   asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTB)), "I" (PORTB3) 
  );
  
}
void num8()
{
   clearChannels();
   /*digitalWrite(col[7], HIGH); //col 1
  digitalWrite(col[5], HIGH); //col 2
  digitalWrite(row[7], HIGH); //is a col 3
  digitalWrite(col[0], HIGH); // col 4
  digitalWrite(col[2], HIGH); //col 5
  digitalWrite(col[4], HIGH); // col 6*/

  asm (
    "sbi %0, %1 \n"
    :: "I" (_SFR_IO_ADDR(PORTB)), "I" (PORTB1)
  );

  
  //digitalWrite(col[5], HIGH); //col 2
   asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTD)), "I" (PORTD4)
  );

  //digitalWrite(row[7], HIGH); //is a col 3
  asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTC)), "I" (PORTC2)
  );

  //digitalWrite(col[0], HIGH); // col 4
   asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTD)), "I" (PORTD6)
  );
  
  //digitalWrite(col[2], HIGH); //col 5
  asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTB)), "I" (PORTB2) //might be incorrct becasue of wiring
  );

  //digitalWrite(col[4], HIGH); // col 6
  asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTC)), "I" (PORTC3) 
  );
  //digitalWrite(col[1], HIGH); //col 7
   asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTB)), "I" (PORTB3) 
  );
    //digitalWrite(row[2], HIGH); //col 8? 
   asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTC)), "I" (PORTC5) 
  );
}
void num9()
{
   clearChannels();
  //digitalWrite(col[7], HIGH); //col 1
  asm (
    "sbi %0, %1 \n"
    :: "I" (_SFR_IO_ADDR(PORTB)), "I" (PORTB1)
  );
    //digitalWrite(row[2], HIGH); //col 8? 
   asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTC)), "I" (PORTC5) 
  );
}
void num10()
{
  clearChannels();

   //digitalWrite(col[5], HIGH); //col 2
   asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTD)), "I" (PORTD4)
  );
  //digitalWrite(row[2], HIGH); //col 8? 
   asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTC)), "I" (PORTC5) 
  );
}
void num11()
{
  clearChannels();
  num10();
  //digitalWrite(col[7], HIGH); //col 1
  asm (
    "sbi %0, %1 \n"
    :: "I" (_SFR_IO_ADDR(PORTB)), "I" (PORTB1)
  );
}
void num12()
{
  clearChannels();
  num9();
  //digitalWrite(row[7], HIGH); //is a col 3
  asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTC)), "I" (PORTC2)
  );

}
void num13()
{
  num10();
  //digitalWrite(row[7], HIGH); //is a col 3
  asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTC)), "I" (PORTC2)
  );
}
void num14()
{
  num10();
  //digitalWrite(col[0], HIGH); // col 4
   asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTD)), "I" (PORTD6)
  );
}
void num15()
{
  num10();
  //digitalWrite(col[2], HIGH); //col 5

  asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTB)), "I" (PORTB2) //might be incorrct becasue of wiring
  );
}
void num16()
{
  num10();
  //digitalWrite(col[4], HIGH); // col 6
  asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTC)), "I" (PORTC3) 
  );
}
void num17()
{
  num10();
   //digitalWrite(col[1], HIGH); //col 7
   asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTB)), "I" (PORTB3) 
  );
}
void num18()
{
  clearChannels();
  //digitalWrite(col[2], HIGH); //col 5
  asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTB)), "I" (PORTB2) //might be incorrct becasue of wiring
  );

  //digitalWrite(col[4], HIGH); // col 6
  asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTC)), "I" (PORTC3) 
  );

  //digitalWrite(col[1], HIGH); //col 7
   asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTB)), "I" (PORTB3) 
  );
}
void num19()
{
  num18();
  //digitalWrite(col[7], HIGH); //col 1
  asm (
    "sbi %0, %1 \n"
    :: "I" (_SFR_IO_ADDR(PORTB)), "I" (PORTB1)
  );

}
void num20()
{
  clearChannels();
  //digitalWrite(col[5], HIGH); //col 2
   asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTD)), "I" (PORTD4)
  );

  //digitalWrite(row[7], HIGH); //is a col 3
  asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTC)), "I" (PORTC2)
  );

  //digitalWrite(col[0], HIGH); // col 4
   asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTD)), "I" (PORTD6)
  );
  
  //digitalWrite(col[2], HIGH); //col 5
  asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTB)), "I" (PORTB2) //might be incorrct becasue of wiring
  );

  //digitalWrite(col[4], HIGH); // col 6
  asm(
    "sbi %0, %1 \n\t"
    :
    :"I"(_SFR_IO_ADDR(PORTC)), "I" (PORTC3) 
  );


}

int randomNumber(int num)
{
  int localNumber = num;
  int localResult = 0;
  //&1 is the localNumber and &0 is the localResult
  asm(
    "mov r3, %1 \n\t"

//shift number , then xor with store, restore value
    "ldi r16, 6 \n\t"
    "firstLoop: \n\t"
    "lsl r3 \n\t"
    "dec r16 \n\t"
    "brne firstLoop \n\t"

    "eor %1, r3 \n\t" 
    "mov r3, %1 \n\t"

    "ldi r16, 7 \n\t"
    "secondLoop: \n\t"
    "lsr r3 \n\t"
    "dec 16 \n\t"
    "brne secondLoop \n\t"

    "eor %1, r3 \n\t" 
    "mov r3, %1 \n\t"

    "ldi r16, 1 \n\t"
    "thirdLoop: \n\t"
    "lsl r3 \n\t"
    "dec r16 \n\t"
    "brne thirdLoop \n\t"
    

    "eor %1, r3 \n\t" 
    "mov r3, %1 \n\t"

    "mov %0, %1 \n\t"
    :"r=" (localResult)
    :"r" (localNumber)
    : "r16"
    
  );

 // Serial.println(localResult);
  return localResult;

}
int convertToRange(int min, int max, int num)
{
  return num % (max - min + 1) + min;

}
bool readMessesge()
{
  char byte = 0;
  
  if(Serial.available() == 1)
  {
    byte = Serial.read(); 
    
    Serial.println(byte);
    Serial.flush();
    return true;
  }
  
  return false;
}
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);

  randomSeed(analogRead(0));
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin, INPUT);
  state = 7;


   

//sets all ports
  asm (
    "out %0, %1 \n"
    : : "I" (_SFR_IO_ADDR(DDRB)), "r" (PB_PIN_DIRS)
  );
  asm (
    "out %0, %1 \n"
    : : "I" (_SFR_IO_ADDR(DDRD)), "r" (PD_PIN_DIRS)
  );
  asm (
    "out %0, %1 \n"
    : : "I" (_SFR_IO_ADDR(DDRC)), "r" (PC_PIN_DIRS)
  );

  num8();
  //digitalWrite(row[3], HIGH); //1 - 5
 // digitalWrite(row[6], HIGH); //row 2 - 12
  //digitalWrite(row[4], HIGH);  //row 3 -13
  //digitalWrite(col[6], HIGH); //4 - 8
  //digitalWrite(row[5], HIGH); //5 - 18
  //digitalWrite(row[1], HIGH); //6 - 7
  //digitalWrite(col[3], HIGH); //7 - 3
  //digitalWrite(row[0], HIGH);//8 - 2
  
  
  
 
}
int const MAX_DICE = 6;
const int DICE[MAX_DICE] = {4,6,8,10,12,20};
int currIndex = 0;

bool isPressed = false;
void loop() 
{
  bool read = readMessesge();
  //Serial.println(read);
  if(read)
  {
    Serial.println("CHANGING INDEX");
    //change the range
    currIndex++;
    if(currIndex >= MAX_DICE)
    {
      currIndex = 0;
    }
    read = false;
  }
  buttonState = digitalRead(buttonPin);
  buttonState = analogRead(buttonPin);
  //Serial.println(buttonState);

  if(buttonState == 1023 && !isPressed)
  {
   
    Serial.println("BUTTON PRESED!");
    state = randomNumber(state);
    randNumber = convertToRange(1, DICE[currIndex], state);
    Serial.println("randNubmer inRange");
    Serial.println(randNumber);

    /*randNumber = random(21);
     Serial.println(randNumber);

    //on
    //digitalWrite(ledPin, HIGH);
    Serial.println(randNumber);*/
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
    case 7:
      num7();
      break;
    case 8:
      num8();
      break;
    case 9:
      num9();
      break;
    case 10:
      num10();
      break;
    case 11:
      num11();
      break;
    case 12:
      num12();
      break;
    case 13:
      num13();
      break;
    case 14:
      num14();
      break;
    case 15:
      num15();
      break;
    case 16:
      num16();
      break;
    case 17:
      num17();
      break;
    case 18:
      num18();
      break;
    case 19:
      num19();
      break;
    case 20:
      num20();
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
struct XorShift
{
  public:

  void setSeed(int seed)
  {
    mSeed = seed;

  };

  int getSeed()
  {
    return mSeed;
  }

  int generate()
  {
 
    //right now the code is too big so in order to fix it needs to chopped in to smaller 8 bit chunks?
     __asm__ (
      "mov r17, %[input] \n\t"

      "mov r19, r17 \n\t"//used to store a copy of that data for the xor
      //this is how you load a imideate
      //use r18 for all imediates

      "LDI r16, 6 \n\t" //used for shift

      "firstShift: \n\t"
        "ROL r17 \n\t"
        //"add r17, r16 \n\t"
        "dec r16 \n\t"
        "cp r16, 0 \n\t"
      
      "BRNE firstShift \n\t"

      "EOR r17, r19 \n\t"
      "Mov r19, r17 \n\t"// store the new state

      "LDI r16, 4 \n\t" //second shift
      "secondShift: \n\t"
        "ROR r17 \n\t"
        //"add r17, r16 \n\t"
        "dec r16 \n\t"
        "cp r16, 0 \n\t"
      
      "BRNE secondShift \n\t"
      "EOR r17, r19 \n\t"
      "Mov r19, r17 \n\t"// store the new state

      "LDI r16, 2 \n\t" //second shift
      "thirdShift: \n\t"
        "ROL r17 \n\t"
        //"add r17, r16 \n\t"
        "dec r16 \n\t"
        "cp r16, 0 \n\t"
      
      "BRNE thirdShift \n\t"
      "EOR r17, r19 \n\t"
      "Mov r19, r17 \n\t"// store the new state

     
      "mov %[result], r17"
      :
      //output
      [result] "=r"(mSeed)
      :
      //input
      [input] "r" (mSeed)
      :
      //Clobbers
    );

    return mSeed;

  }
  private:
  int mSeed;
};

XorShift* xorShift;

const int MAX_MESSAGE_LENGTH = 12;
int readAndPrintMessege()
{
  

   while (Serial.available() > 0)
  {
   //Create a place to hold the incoming message
   static char message[MAX_MESSAGE_LENGTH];
   static unsigned int message_pos = 0;

   //Read the next available byte in the serial receive buffer
   char inByte = Serial.read();

   //Message coming in (check not terminating character) and guard for over message size
   if ( inByte != '\n' && (message_pos - MAX_MESSAGE_LENGTH - 1) )
   {
     //Add the incoming byte to our message
     message[message_pos] = inByte;
     message_pos++;
   }
   //Full message received...
   else
   {
     //Add null character to string
     message[message_pos] = '\0';

     //Print the message (or do other things)
     Serial.println(atoi(message));

     //Reset for the next message

     message_pos = 0;

     return atoi(message);
   }
 }

 return 0;
 
 //Check to see if anything is available in the serial receive buffer
}

int seed = 0;
void setup() {
 Serial.begin(9600);
 xorShift = new XorShift();
  
 
 
}
bool isInit = true;
void loop() {

  if(isInit)
  {
    seed = readAndPrintMessege();
  }

 if(seed <= 0)
 {

 }
 else
 {
  isInit = false;
  Serial.write("Sucsees!");
  
  int test =  xorShift->generate();

  Serial.println("First Nubmer test");
  Serial.println(test);

  Serial.println("seed ");
  Serial.write(xorShift->getSeed());

  test = xorShift->generate();
  Serial.println("Second number Nubmer test");
  Serial.println(test);

  seed=0;

 
 }
}




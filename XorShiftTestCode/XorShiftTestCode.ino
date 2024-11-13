struct XorShift
{
  public:

  void setSeed(char seed)
  {
    mSeed = seed;

  };

  int getSeed()
  {
    return mSeed;
  }

  char generate()
  {



    char temp;

    Serial.println("mSeed before mangle");
    Serial.println(mSeed);
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
      "NEG r17 \n\t"
      "EOR r17, r19 \n\t"
      "Mov r19, r17 \n\t"// store the new state

      "LDI r16, 4 \n\t" //second shift
      "secondShift: \n\t"
        "ROR r17 \n\t"
        //"add r17, r16 \n\t"
        "dec r16 \n\t"
        "cp r16, 0 \n\t"
      
      "BRNE secondShift \n\t"

      //need some if statment for the neg so that it does not do it when we are already positve
      "NEG r17 \n\t"

      "EOR r17, r19 \n\t"
      "Mov r19, r17 \n\t"// store the new state

      "LDI r16, 2 \n\t" //second shift
      "thirdShift: \n\t"
        "ROL r17 \n\t"
        //"add r17, r16 \n\t"
        "dec r16 \n\t"
        "cp r16, 0 \n\t"
      
      "BRNE thirdShift \n\t"
      "NEG r17 \n\t"
      "EOR r17, r19 \n\t"
      "Mov r19, r17 \n\t"// store the new state */

     
      "mov %[result], r17"
      :
      //output
      [result] "=r"(temp)
      :
      //input
      [input] "r" (mSeed)
      :
      //Clobbers
    );
    Serial.println("temp");
    Serial.println(temp);

    return mSeed = temp;

  }
  private:
  char mSeed;
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
 
 xorShift = (XorShift*)malloc(sizeof(XorShift));
  
 
 
}
bool isInit = true;
void loop() {

  if(isInit)
  {
    seed = readAndPrintMessege(); 
    xorShift->setSeed(seed);
  }

 if(seed <= 0)
 {

 }
 else
 {
  
  isInit = false;
  Serial.write("Sucsees!");
  xorShift->setSeed('');
  int test =  xorShift->generate();
  

  Serial.println("First Nubmer test");
  Serial.println(test);

  Serial.println("seed ");
  Serial.write(xorShift->getSeed());


  seed=0;

 
 }
}




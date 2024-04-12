
//Nymble firmware task
// define the text to be send to MCU
const char text[] = "Finance Minister Arun Jaitley Tuesday hit out at former RBI governor Raghuram Rajanfor predicting that the next banking crisi would be triggered by MSME lending, saying postmortem easier than taking action when it was required. Rajan, who had as the chief economist at IMF warned of impending financial crisis of 2008, in a note to a parliamentarycommittee warned against ambitious credit targets and loan waivers, saying that they could be the sources of next banking crisis. Government should focus on sources of the next crisis, not just the last one. In particular, government should refrain from setting ambitious credit targets or waiving loans. Credit targetsare sometimes acheived by abandoning appropriate due diligence, creating the environment for future NPAs, \"Rajan said in the note.\" Both MUDRA loans as well as the Kisan Credit Card, while popular, have to be examined more closely or potential credit risk. Rajan, who was RBI governor for three years till September 2016, is currently.\n";

void setup() {
  
Serial.begin(2400);  //Initializing communication
}

void loop() {
  //declare variables to store timing data
  unsigned long starttime = 0;        
  unsigned long endtime = 0;
  unsigned long transmissiontime = 0;
  // declare variable for storing the number of bytes transmitted
  unsigned long bytestransmitted = 0;

  // Record the start time
  starttime = millis();
  // send text from PC to MCU
Serial.write(text);
bytestransmitted = sizeof(text); // Record the number of bytes transmitted
 while (Serial.available()){      // Loop till all the characters are received back
   char receivetext = Serial.read();  //Read all the received characters and store it in a variable receivetext
   Serial.print(receivetext);       //Print the data stored in receivetext variable to the serial monitor
   bytestransmitted++; // Increment the count of bytes transmitted
   Serial.println();  //Move to the next line in the serial monitor
   delay(10);     // For stability
 }
 endtime = millis();   //Record the end time of data transmission
 // Calculate transmission time
  transmissiontime = endtime - starttime;

  // Calculate transmission speed in bytes per second
  float transmissionSpeed = (float)bytestransmitted / (transmissiontime / 1000.0);

  // Print the transmission speed
  Serial.print("Transmission Speed: ");
  Serial.print(transmissionSpeed);
  Serial.println(" bytes per second");
}

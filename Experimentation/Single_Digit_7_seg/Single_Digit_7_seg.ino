//7 segment test diplay code
//from top left to top right, wrapping around the bottom,
//pinmap for 7-seg digit display 
//pin 1 top seg
//pin 2 top left seg
//pin 3 common source
//pin 4 empty
//pin 5 empty
//pin 6 left dot seg
//pin 7 bottom left seg
//pin 8 bottom segment
//pin 9 right dot
//pin 10 bottom right seg
//pin 11 middle seg
//pin 12 empty
//pin 13 top right seg
//pin 14 common source 


//***code and pin assignments*** 
//addr: 0 top seg
//addr: 1 top left seg
//addr: 2 left dot seg
//addr: 3 bottom left seg
//addr: 4 bottom segment
//addr: 5 right dot
//addr: 6 bottom right seg
//addr: 7 middle seg
//addr: 8 top right seg 

static const int pin[9] = {14,15,16,17,18,19,20,21,22};

static const char numCodes[][10] = {
  "110110101", //0
  "000000101", //1
  "100110011", //2
  "100010111", //3
  "010000111", //4
  "110010110", //5
  "110110110", //6
  "100000101", //7
  "110110111", //8
  "110000111"  //9
  };

void dispNum(int Num){//uses data from numCodes to cycle through all segs in display
    int cnt;
    for (cnt = 0; cnt < 9; cnt = cnt + 1){ //scans through numcode, sets appropriate pins high/low
      if(numCodes[Num][cnt] == '1'){
        digitalWrite(pin[cnt],LOW);
      }
      else{
        digitalWrite(pin[cnt],HIGH);    
      }
    } 
  }
  
void dispReset(){
    int cnt;
    for (cnt = 0; cnt < 9; cnt = cnt + 1){ //resets all segments  
       digitalWrite(pin[cnt],HIGH);
    } 
  }

void dispNumDuration(int Num, int runtime){//reduces constant load on chip. runtime is in 20's of ms. runtime 50 = 1s;
    int cnt;
    for(cnt = 0; cnt < runtime; cnt = cnt + 1){
      dispNum(Num);
      delay(10);
      dispReset();
      delay(10);
      }
  }
  
void setup() {
    int cnt;
    for (cnt = 0; cnt < 9; cnt = cnt + 1){ 
      pinMode(pin[cnt],OUTPUT);//instantiates every pin in pin[] to OUTPUT
      digitalWrite(pin[cnt],HIGH);//instantiates every pin in pin[] to HIGH, pins are directly driving leds, which have a common source and are thus active low.
    } 
  }

void loop() {
  dispNumDuration(5,50);
  dispNumDuration(4,50);
  dispNumDuration(3,50);
  dispNumDuration(2,50);
  dispNumDuration(1,50);
  dispNumDuration(0,50);
}

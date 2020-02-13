#include "LEDMatrix.h"
#include "MatrixBuffer.h"
#include "String5x7Buffer.h"

Max7219_8x8 max7219_8x8;
//MatrixBuffer *matrixBuffer1 = new MatrixBuffer(8, 4), *matrixBuffer2;
char text[] = "Hello world!\0";
String5x7Buffer *string5x7Buffer = new String5x7Buffer(4, text, false);

void setup(){
  max7219_8x8.LAT = 10;
  max7219_8x8.DAT = 11;
  max7219_8x8.CLK = 13;
  max7219_8x8.screen_n = 4;
  
  max7219_8x8.init();
  max7219_8x8.test();

//  makeSimpleMatrix();
}

//void makeSimpleMatrix() {
//  // LED8個のONOFFを1Byteで表す
//  const uint8_t sample[8][4] = {  //  1枚目       2枚目        3枚目       4枚目
//                                        {0b00000000, 0b01111000, 0b00000000, 0b00000000},
//                                        {0b00111100, 0b01001000, 0b00011110, 0b00111000},
//                                        {0b01100110, 0b01001000, 0b00100000, 0b00100100},
//                                        {0b01100110, 0b01110000, 0b00100000, 0b00100010},
//                                        {0b01111110, 0b01001000, 0b00100000, 0b00100010},
//                                        {0b01100110, 0b01001000, 0b00100000, 0b00100100},
//                                        {0b01100110, 0b01001000, 0b00100000, 0b00111000},
//                                        {0b01100110, 0b01111100, 0b00011110, 0b00000000}
//                                      };
//  uint8_t **data = matrixBuffer1->getData();
//  for (int i = 0; i < 8; ++i) {
//    for (int j = 0; j < 4; ++j) {
//      data[i][j] = sample[i][j];
//    }
//  }
//  matrixBuffer2 = matrixBuffer1->clone();
//  matrixBuffer2->flip();
//}

void loop(){
//  MatrixBuffer *matrixBuffer3 = matrixBuffer1->clone();
//  max7219_8x8.print(matrixBuffer3);
//  delay(1000);
//
//  for (int i = 0; i < 32; ++i) {
//    matrixBuffer3->leftScroll(false);
//    max7219_8x8.print(matrixBuffer3);
//    delay(200);
//  }
//
//  max7219_8x8.print(matrixBuffer2);
//  delay(1000);
//
//  delete matrixBuffer3;

  for (int i=0; i < 74; ++i) {
    max7219_8x8.print(string5x7Buffer);
    string5x7Buffer->leftScroll(false);
    delay(100);
  }
  delay(1000);
  string5x7Buffer->reset();
}


//void scrollLeft(int pattern[8][LEDNUM]){
//  int i, d;
////  int temp;
//
//  for(d = 1; d < 9; d++){
//    for(i = 0; i < LEDNUM; i++){
//      sendTo7219(d, pattern[d][i]);
//    }
//  }
//}

/*
 * // 縦方向のウェーブ
  if(0){
  for(d = 1; d <= 8; d++){
    for(c = 0; c < LEDNUM; c++)
      sendTo7219(d, 0xFF);
    delay(500);
  }

  for(d = 1; d <= 8; d++){
    for(c = 0; c < LEDNUM; c++)
      sendTo7219(d, 0x00);
    delay(500);
  }
  
  // 横方向のウェーブ
    // 作ろう
    // digit: 0b 00000000 00000000 00000000 00000000
  data = 1;
  d = 1;
  for(int x = 0; x < 8*LEDNUM; x++){
    for(d = 1; d < 3; d++){}
    
    for(int i = 0; i < (8*LEDNUM - x) / 8; i++){   // 後ろの表示しない部分
      sendTo7219(d, 0);
      delay(DEBUG);
    }
    
    sendTo7219(d, data << (x % 8));
    delay(DEBUG);
    
    for(int i = 0; i < x / 8; i++){                // 手前の表示しない部分
      sendTo7219(d, 0);
      delay(DEBUG);
    }
    delay(500);
  }*/
  /*for(d = 1; d <= 8; d++){
    for(int x = 0; x < 8*LEDNUM; x++){
      long int temp = data << 1;
      sendTo7219(d, temp >> 24);
      sendTo7219(d, temp >> 16);
      sendTo7219(d, temp >> 8);
      sendTo7219(d, temp);
    }
    delay(300);
  }*/
  /*
  data = 0xFFFFFFFF;
  for(int x = 0; x < 8*LEDNUM; x++){
    data = data & !(1 << x);
    for(d = 1; d <= 8; d++){
      sendTo7219(d, data >> 24);
      sendTo7219(d, data >> 16);
      sendTo7219(d, data >> 8);
      sendTo7219(d, data);
    }
    delay(300);
  }*/

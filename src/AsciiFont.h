#ifndef _ASCIIFONT_H_
#define _ASCIIFONT_H_

#include <stdint.h>

#ifdef ARDUINO
#include <avr/pgmspace.h>
#endif

#include "MatrixLED.h"

#define _ASCII_CHAR_NUM 95
#define _ASCII_HEIGHT 7
#define _ASCII_OFFSET 0x20  // access as "_fonts['a' - _ASCII_OFFSET]"

/**
 * @brief Get a row of indicated ascii char.
 * @param c [in] Char to get row.
 * @param row [in] Row number between [0, 6].
 * @retval uint8_t Row data on success.
 * @retval uint8_t N/A row data on illegal c.
 * @retval 0 on illegal row.
*/
static inline uint8_t getASCIIRow(char c, uint8_t row);

/**
 * @brief Write single ascii char to single matrixLED.
 * @param matrixLED [in] Pointer of MatrixLED.
 * @param c [in] Char to write.
 * @param offset_from_left [in] Offset size from left end.
*/
void writeAsciiToMatrixLED(MatrixLED *matrixLED, char c, int8_t offset_from_left);

/**
 * @brief Write ascii string to multiple matrixLED.
 * @param matrixLEDs [in] Pointer of MatrixLED-Array.
 * @param ledlen [in] Length of MatrixLED-Array.
 * @param string [in] Char-Array to write.
 * @param offset_from_left [in] Offset size from left end.
 * @retval Number of used matrix panels (from left).
*/
// #pragma deprecated(writeAsciisToMatrixLEDs)
size_t writeAsciisToMatrixLEDs(MatrixLED *matrixLEDs, uint8_t ledlen, const char *string, uint8_t offset_from_left);

/**
 * @brief Write ascii string to multiple matrixLED.
 * @param matrixLEDArray [in] Pointer of MatrixLEDArray.
 * @param string [in] Char-Array to write.
 * @param offset_from_left [in] Offset size from left end.
 * @note This is an alias for "writeAsciisToMatrixLEDs(matrixLEDArray->matrixLEDs, matrixLEDArray->length, string, offset_from_left)"
*/
void writeAsciisToMatrixLEDArray(MatrixLEDArray *matrixLEDArray, const char *string, uint8_t offset_from_left);


#ifdef ARDUINO
static const uint8_t _ASCII_FONTS[_ASCII_CHAR_NUM][_ASCII_HEIGHT] PROGMEM
#else
static const uint8_t _ASCII_FONTS[_ASCII_CHAR_NUM][_ASCII_HEIGHT]
#endif

= {
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},  // 0x20, Space
  {0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x04},  // 0x21, !
  {0x09, 0x09, 0x12, 0x00, 0x00, 0x00, 0x00},  // 0x22, "
  {0x0a, 0x0a, 0x1f, 0x0a, 0x1f, 0x0a, 0x0a},  // 0x23, #
  {0x04, 0x0f, 0x14, 0x0e, 0x05, 0x1e, 0x04},  // 0x24, $
  {0x19, 0x19, 0x02, 0x04, 0x08, 0x13, 0x13},  // 0x25, %
  {0x04, 0x0a, 0x0a, 0x0a, 0x15, 0x12, 0x0d},  // 0x26, &
  {0x04, 0x04, 0x08, 0x00, 0x00, 0x00, 0x00},  // 0x27, '
  {0x02, 0x04, 0x08, 0x08, 0x08, 0x04, 0x02},  // 0x28, (
  {0x08, 0x04, 0x02, 0x02, 0x02, 0x04, 0x08},  // 0x29, )
  {0x04, 0x15, 0x0e, 0x1f, 0x0e, 0x15, 0x04},  // 0x2a, *
  {0x00, 0x04, 0x04, 0x1f, 0x04, 0x04, 0x00},  // 0x2b, +
  {0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x08},  // 0x2c, ,
  {0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00},  // 0x2d, -
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x0c},  // 0x2e, .
  {0x01, 0x01, 0x02, 0x04, 0x08, 0x10, 0x10},  // 0x2f, /
  {0x0e, 0x11, 0x13, 0x15, 0x19, 0x11, 0x0e},  // 0x30, 0
  {0x04, 0x0c, 0x04, 0x04, 0x04, 0x04, 0x0e},  // 0x31, 1
  {0x0e, 0x11, 0x01, 0x02, 0x04, 0x08, 0x1f},  // 0x32, 2
  {0x0e, 0x11, 0x01, 0x06, 0x01, 0x11, 0x0e},  // 0x33, 3
  {0x02, 0x06, 0x0a, 0x12, 0x1f, 0x02, 0x02},  // 0x34, 4
  {0x1f, 0x10, 0x1e, 0x01, 0x01, 0x11, 0x0e},  // 0x35, 5
  {0x06, 0x08, 0x10, 0x1e, 0x11, 0x11, 0x0e},  // 0x36, 6
  {0x1f, 0x01, 0x02, 0x04, 0x08, 0x08, 0x08},  // 0x37, 7
  {0x0e, 0x11, 0x11, 0x0e, 0x11, 0x11, 0x0e},  // 0x38, 8
  {0x0e, 0x11, 0x11, 0x0f, 0x01, 0x02, 0x0c},  // 0x39, 9
  {0x00, 0x0c, 0x0c, 0x00, 0x0c, 0x0c, 0x00},  // 0x3a, :
  {0x00, 0x0c, 0x0c, 0x00, 0x0c, 0x04, 0x08},  // 0x3b, ;
  {0x02, 0x04, 0x08, 0x10, 0x08, 0x04, 0x02},  // 0x3c, <
  {0x00, 0x00, 0x1f, 0x00, 0x1f, 0x00, 0x00},  // 0x3d, =
  {0x08, 0x04, 0x02, 0x01, 0x02, 0x04, 0x08},  // 0x3e, >
  {0x0e, 0x11, 0x01, 0x02, 0x04, 0x00, 0x04},  // 0x3f, ?
  {0x0e, 0x11, 0x17, 0x15, 0x17, 0x10, 0x0f},  // 0x40, @
  {0x04, 0x0a, 0x11, 0x11, 0x1f, 0x11, 0x11},  // 0x41, A
  {0x1e, 0x11, 0x11, 0x1e, 0x11, 0x11, 0x1e},  // 0x42, B
  {0x0e, 0x11, 0x10, 0x10, 0x10, 0x11, 0x0e},  // 0x43, C
  {0x1e, 0x09, 0x09, 0x09, 0x09, 0x09, 0x1e},  // 0x44, D
  {0x1f, 0x10, 0x10, 0x1c, 0x10, 0x10, 0x1f},  // 0x45, E
  {0x1f, 0x10, 0x10, 0x1f, 0x10, 0x10, 0x10},  // 0x46, F
  {0x0e, 0x11, 0x10, 0x10, 0x13, 0x11, 0x0f},  // 0x37, G
  {0x11, 0x11, 0x11, 0x1f, 0x11, 0x11, 0x11},  // 0x48, H
  {0x0e, 0x04, 0x04, 0x04, 0x04, 0x04, 0x0e},  // 0x49, I
  {0x1f, 0x02, 0x02, 0x02, 0x02, 0x12, 0x0c},  // 0x4a, J
  {0x11, 0x12, 0x14, 0x18, 0x14, 0x12, 0x11},  // 0x4b, K
  {0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x1f},  // 0x4c, L
  {0x11, 0x1b, 0x15, 0x11, 0x11, 0x11, 0x11},  // 0x4d, M
  {0x11, 0x11, 0x19, 0x15, 0x13, 0x11, 0x11},  // 0x4e, N
  {0x0e, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0e},  // 0x4f, O
  {0x1e, 0x11, 0x11, 0x1e, 0x10, 0x10, 0x10},  // 0x50, P
  {0x0e, 0x11, 0x11, 0x11, 0x15, 0x12, 0x0d},  // 0x51, Q
  {0x1e, 0x11, 0x11, 0x1e, 0x14, 0x12, 0x11},  // 0x52, R
  {0x0e, 0x11, 0x10, 0x0e, 0x01, 0x11, 0x0e},  // 0x53, S
  {0x1f, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04},  // 0x54, T
  {0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0e},  // 0x55, U
  {0x11, 0x11, 0x11, 0x11, 0x11, 0x0a, 0x04},  // 0x56, V
  {0x11, 0x11, 0x11, 0x15, 0x15, 0x1b, 0x11},  // 0x57, W
  {0x11, 0x11, 0x0a, 0x04, 0x0a, 0x11, 0x11},  // 0x58, X
  {0x11, 0x11, 0x0a, 0x04, 0x04, 0x04, 0x04},  // 0x59, Y
  {0x1f, 0x01, 0x02, 0x04, 0x08, 0x10, 0x1f},  // 0x5a, Z
  {0x0e, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0e},  // 0x5b, [
  {0x10, 0x10, 0x08, 0x04, 0x02, 0x01, 0x01},  // 0x5c, '\'
  {0x0e, 0x02, 0x02, 0x02, 0x02, 0x02, 0x0e},  // 0x5d, ]
  {0x04, 0x0a, 0x11, 0x00, 0x00, 0x00, 0x00},  // 0x5e, ^
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f},  // 0x5f, _
  {0x04, 0x04, 0x02, 0x00, 0x00, 0x00, 0x00},  // 0x60, `
  {0x00, 0x0e, 0x01, 0x0d, 0x13, 0x13, 0x0d},  // 0x61, a
  {0x10, 0x10, 0x10, 0x1c, 0x12, 0x12, 0x1c},  // 0x62, b
  {0x00, 0x00, 0x00, 0x0e, 0x10, 0x10, 0x0e},  // 0x63, c
  {0x01, 0x01, 0x01, 0x07, 0x09, 0x09, 0x07},  // 0x64, d
  {0x00, 0x00, 0x0e, 0x11, 0x1f, 0x10, 0x0f},  // 0x65, e
  {0x06, 0x09, 0x08, 0x1c, 0x08, 0x08, 0x08},  // 0x66, f
  {0x0e, 0x11, 0x13, 0x0d, 0x01, 0x01, 0x0e},  // 0x67, g
  {0x10, 0x10, 0x10, 0x16, 0x19, 0x11, 0x11},  // 0x68, h
  {0x00, 0x04, 0x00, 0x0c, 0x04, 0x04, 0x0e},  // 0x69, i
  {0x02, 0x00, 0x06, 0x02, 0x02, 0x12, 0x0c},  // 0x6a, j
  {0x10, 0x10, 0x12, 0x14, 0x18, 0x14, 0x12},  // 0x6b, k
  {0x0c, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04},  // 0x6c, l
  {0x00, 0x00, 0x0a, 0x15, 0x15, 0x11, 0x11},  // 0x6d, m
  {0x00, 0x00, 0x16, 0x19, 0x11, 0x11, 0x11},  // 0x6e, n
  {0x00, 0x00, 0x0e, 0x11, 0x11, 0x11, 0x0e},  // 0x6f, o
  {0x00, 0x1c, 0x12, 0x12, 0x1c, 0x10, 0x10},  // 0x70, p
  {0x00, 0x07, 0x09, 0x09, 0x07, 0x01, 0x01},  // 0x71, q
  {0x00, 0x00, 0x16, 0x19, 0x10, 0x10, 0x10},  // 0x72, r
  {0x00, 0x00, 0x0f, 0x10, 0x0e, 0x01, 0x1e},  // 0x73, s
  {0x08, 0x08, 0x1c, 0x08, 0x08, 0x09, 0x06},  // 0x74, t
  {0x00, 0x00, 0x11, 0x11, 0x11, 0x13, 0x0d},  // 0x75, u
  {0x00, 0x00, 0x11, 0x11, 0x11, 0x0a, 0x04},  // 0x76, v
  {0x00, 0x00, 0x11, 0x11, 0x15, 0x15, 0x0a},  // 0x77, w
  {0x00, 0x00, 0x11, 0x0a, 0x04, 0x0a, 0x11},  // 0x78, x
  {0x00, 0x11, 0x11, 0x0f, 0x01, 0x11, 0x0e},  // 0x79, y
  {0x00, 0x00, 0x1f, 0x02, 0x04, 0x08, 0x1f},  // 0x7a, z
  {0x06, 0x08, 0x08, 0x10, 0x08, 0x08, 0x06},  // 0x7b, {
  {0x04, 0x04, 0x04, 0x00, 0x04, 0x04, 0x04},  // 0x7c, |
  {0x0c, 0x02, 0x02, 0x01, 0x02, 0x02, 0x0c},  // 0x7d, }
  {0x08, 0x15, 0x02, 0x00, 0x00, 0x00, 0x00}   // 0x7e, ~
};

// Send this when fail gettng ascii char (Not Available);
static const uint8_t _NA_CHAR[_ASCII_HEIGHT]
= {
  0b00011001,
  0b00010101,
  0b00010011,
  0b00000000,
  0b00000100,
  0b00001110,
  0b00010001,
};

static inline uint8_t getASCIIRow(
  char c,
  uint8_t row
) {
  if (c < _ASCII_OFFSET || _ASCII_CHAR_NUM - 1 + _ASCII_OFFSET < c)
    return *(_NA_CHAR + row);
  
  if (7 < row)
    return 0x00;
  
  #ifdef ARDUINO  // using EEPROM
  return pgm_read_byte(*(_ASCII_FONTS + c - _ASCII_OFFSET) + row);
  #else
  return *(*(_ASCII_FONTS + c - _ASCII_OFFSET) + row);
  #endif
}

#endif  /* _ASCIIFONT_H_ */

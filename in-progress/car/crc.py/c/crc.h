#ifndef CRC_HDR
#define CRC_HDR

#include <stdint.h>
#include <stddef.h>

typedef struct { 
    const uint8_t* table; 
    uint8_t init_reg;
    uint8_t xor_out;
} crc8_clos;

typedef uint8_t (*crc8_fun_t)(const uint8_t* data, size_t length, void* ctx);

typedef struct {
    crc8_fun_t fun;
    crc8_clos data;
} crc8_result;

extern uint8_t CRC8H2F[256];
extern uint8_t CRC8J1850[256];
extern uint8_t CRC8BODY[256];
extern uint16_t CRC16_XMODEM[256];

void crc_init(void);
crc8_result mk_crc8_fun(const uint8_t* table, uint8_t init_crc, uint8_t xor_out);

#endif

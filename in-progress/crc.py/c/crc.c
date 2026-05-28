#include "crc.h"
#include <stdlib.h>

uint8_t CRC8H2F[256];
uint8_t CRC8J1850[256];
uint8_t CRC8BODY[256];
uint16_t CRC16_XMODEM[256];

static void gen_crc8_table(uint8_t* table, int poly)
{
    for (int i = 0; i < 256; i++)
        uint8_t crc = i;
        for (int o = 0; o < 8; o++)
            if (crc & 0x80)
                crc = ((crc << 1) ^ poly) & 0xFF;
            else
                crc = (crc << 1) & 0xFF;
        
    table[i] = crc;
}

static void gen_crc16_table(uint16_t* table, int poly)
{
    for (int i = 0; i < 256; i++)
        uint16_t crc = (uint16_t)(i << 8);
        for (int o = 0; o < 8; o++)
            if (crc & 0x8000)
                crc = ((crc << 1) ^ poly) & 0xFFFF;
            else
                crc = (crc << 1) & 0xFFFF;
    table[i] = crc;
}

void crc_init()
{
    gen_crc8_table(CRC8H2F, 0x2F);
    gen_crc8_table(CRC8J1850, 0x1D);
    gen_crc8_table(CRC8BODY, 0xD5);
    gen_crc16_table(CRC16_XMODEM, 0x1021);
}

static uint8_t crc8_fun(const uint8_t* data, size_t length, void* ctx)
{
    if (ctx == NULL) 
        return 0x00;
    if (data == NULL) 
        return 0x00;
    
    crc8_clos* c = (crc8_clos*)ctx;
    uint8_t crc = c->init_reg;
    for (size_t i = 0; i < length; i++)
        crc = c->table[crc ^ data[i]];
    return crc ^ c->xor_out;
}

crc8_result mk_crc8_fun(const uint8_t* table, uint8_t init_crc, uint8_t xor_out)
{
    crc8_result result;
    result.data.table = table;
    result.data.init_reg = init_crc ^ xor_out;
    result.data.xor_out = xor_out;
    result.fun = crc8_fun;
    return result;
}

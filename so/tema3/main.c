#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint8_t t1;
    uint8_t t2;
    uint8_t t3;
    uint8_t t4;
} str_t;

// 0x1000000
// 0 0 0 1 - cel mai mare nr la dreapta
// 1 0 0 0 - 

typedef struct {
    char nume[24];
    uint32_t timestamp;
    char msg[128];
} log_t;


// 24     | 4 |     128
// 24     | 4 |     128
// 24     | 4 |     128
// 24     | 4 |     128
// 24     | 4 |     128
// 24     | 4 |     128

// 156 * 100 = 15600

log_t array[100];
uint8_t array_counter;

int main(const int ca) {

    array[0].nume = "salut";
    array[0].timestamp = 0;
    array[0].msg = "tot ok";

    return 0;
}
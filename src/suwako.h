#include "kbase.h"

#ifndef SUWAKO_H
#define SUWAKO_H

#define SUWAKO_NULL (0xFFFF)

/*	--	suwa objs	--	*/
typedef uint8_t suwa_data[0x20];
typedef struct suwa_stat {
	uint8_t dead; // obvious
	uint16_t mode; // mode, for obj type
	uint16_t next,id; // next index, current index
	// 0xFFFF is treated as NULL.
} PACKED suwa_stat;

typedef struct suwako
{
	suwa_stat stat; // $04
	suwa_data data; // $20
	// size = $20
} PACKED suwako;

#endif

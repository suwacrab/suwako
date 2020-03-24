#include "kbase.h"

#ifndef SUWAKO_H
#define SUWAKO_H

#define KANAKO_NULL (0xFFFF)

/*	--	suwa objs	--	*/
typedef uint32_t suwa_data[5];
typedef struct suwa_stat {
	uint8_t dead; // obvious
	uint16_t mode; // mode, for obj type
	uint16_t next,id; // next index, current index
	// 0xFFFF is treated as NULL.
} suwa_stat;

typedef struct suwako
{
	vec2_16 pos; // $04
	suwa_stat stat; // $04
	suwa_data data; // $10
	// size = $20
} suwako;

#endif

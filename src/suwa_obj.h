#include "kbase.h"

#ifndef SUWAKO_H
#define SUWAKO_H

#define POOL_NULL (0xFFFF)

/*	--	suwa objs	--	*/
typedef uint32_t suwa_data[2];
typedef struct suwa_stat {
	uint8_t type,dead;
	uint16_t next,id; // next index, current index*
	// 0xFFFF is treated as NULL.
} suwa_stat;

typedef struct suwa_obj
{
	VEC2 pos,vel; // $10
	suwa_stat stat; // $04
	suwa_data data; // $0C
	// size = $20
} suwa_obj;

/*	--	obj yasas	--	*/
typedef struct kanako 
{
	suwa_obj *objs;
	u16 first,len;
} kanako;

/*	--	yasa funcs	--	*/
kanako *kanako_init(kanako *yasa,suwa_obj *objs,u16 len);
suwa_obj *kanako_add(kanako *yasa);
void kanako_updt(kanako *yasa);

#endif

#include "kbase.h"

#ifndef SUWAOBJ_H
#define SUWAOBJ_H

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

/*	--	obj pools	--	*/
typedef struct obj_pool 
{
	suwa_obj *objs;
	u16 first,len;
} obj_pool;

/*	--	pool funcs	--	*/
obj_pool *obj_pool_init(obj_pool *pool,suwa_obj *objs,u16 len);
suwa_obj *obj_pool_add(obj_pool *pool);
void obj_pool_updt(obj_pool *pool);

#endif

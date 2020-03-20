#include "suwa_obj.h"

/*	--	pool funcs	--	*/
obj_pool *obj_pool_init(obj_pool *pool,suwa_obj *objs,u16 len)
{
	// allocate pool
	pool->objs = objs;
	pool->len = len;
	pool->first = 0x0000;
	printf("obj_pool size: $%04lX\n",sizeof(suwa_obj) * len);
	// set next objs
	for(u32 i=0; i<len; i++)
	{ 
		pool->objs[i].stat.id = i;
		pool->objs[i].stat.dead = true; 
		pool->objs[i].stat.next = i+1;
		pool->objs[i].stat.type = 0;
	}
	pool->objs[len-1].stat.next = POOL_NULL;
	return pool;
}
suwa_obj *obj_pool_add(obj_pool *pool)
{
	if(pool->first == 0xFFFF) return NULL;
	suwa_obj *nobj = &pool->objs[pool->first];
	nobj->stat.dead = false;
	pool->first = nobj->stat.next;
	return nobj;
}
void obj_pool_updt(obj_pool *pool)
{
	suwa_obj *objs = pool->objs;
	u16 len = pool->len;
	for(u32 i=0; i<len; i++)
	{
		if(objs[i].stat.dead) // if obj is dead...
		{ // set obj's next to first, and set first to obj.
			objs[i].stat.next = pool->first;
			pool->first = i;
		}
	}
}



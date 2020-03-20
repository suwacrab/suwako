#include "kanako.h"

kanako *kanako_init(kanako *yasa,suwako *objs,u16 len)
{
	// allocate yasa
	yasa->objs = objs;
	yasa->len = len;
	yasa->first = 0x0000;
	printf("suwako size: $%04lX[$%04X]\n",sizeof(suwako),len);
	printf("kanako size: $%04lX\n",sizeof(suwako) * len);
	// set next objs
	for(u32 i=0; i<len; i++)
	{ 
		yasa->objs[i].stat.id = i;
		yasa->objs[i].stat.dead = true; 
		yasa->objs[i].stat.next = i+1;
		yasa->objs[i].stat.type = 0;
	}
	yasa->objs[len-1].stat.next = POOL_NULL;
	return yasa;
}
suwako *kanako_add(kanako *yasa)
{
	if(yasa->first == 0xFFFF) return NULL;
	suwako *nobj = &yasa->objs[yasa->first];
	nobj->stat.dead = false;
	yasa->first = nobj->stat.next;
	return nobj;
}
void kanako_updt(kanako *yasa)
{
	suwako *objs = yasa->objs;
	u16 len = yasa->len;
	for(u32 i=0; i<len; i++)
	{
		if(objs[i].stat.dead) // if obj is dead...
		{ // set obj's next to first, and set first to obj.
			objs[i].stat.next = yasa->first;
			yasa->first = i;
		}
	}
}



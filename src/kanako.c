#include "kanako.h"

kanako *kanako_init(kanako *yasa,suwako *objs,u16 len)
{
	// allocate yasa
	yasa->objs = objs;
	yasa->len = len;
	yasa->first = 0x0000;
	yasa->alive = 0x0000;
	printf("suwako size: $%04lX[$%04X]\n",sizeof(suwako),len);
	printf("kanako size: $%04lX\n",sizeof(suwako) * len);
	// set next objs
	for(u32 i=0; i<len; i++)
	{ 
		yasa->objs[i].stat.id = i;
		yasa->objs[i].stat.dead = true; 
		yasa->objs[i].stat.next = i+1;
		yasa->objs[i].stat.mode = 0;
	}
	yasa->objs[len-1].stat.next = KANAKO_NULL;
	return yasa;
}
suwako *kanako_add(kanako *yasa,u16 mode)
{
	if(yasa->first == KANAKO_NULL) return NULL;
	suwako *nobj = &yasa->objs[yasa->first];
	nobj->stat.dead = false;
	nobj->stat.mode = mode;
	yasa->first = nobj->stat.next;
	yasa->alive++;

	return nobj;
}
void kanako_del(kanako *yasa,u16 id)
{
	yasa->objs[id].stat.dead = true;
	yasa->objs[id].stat.next = yasa->first;
	yasa->first = id;
	yasa->alive--;
}



#include "kbase.h"
#include "suwako.h"

#ifndef KANAKO_H
#define KANAKO__H

/*	--	obj yasas	--	*/
typedef struct kanako 
{
	suwako *objs;
	uint16_t first,len,alive;
} kanako;

/*	--	yasa funcs	--	*/
kanako *kanako_init(kanako *yasa,suwako *objs,u16 len);
suwako *kanako_add(kanako *yasa,u16 mode);
void kanako_del(kanako *yasa,u16 id);

#endif


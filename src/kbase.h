#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/resource.h>

#include <inttypes.h>
#include <time.h>
#include <assert.h>
#include <uchar.h>
#include <wchar.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#ifndef KBASE_H
#define KBASE_H

// misc
#define ALIGN(n) __attribute__((aligned(n)))
#define PACKED __attribute__((packed))
#define INLINE static inline
#define SDL_SECOND (1000)

/*	--	types	--	*/
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef uintptr_t uptr;

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

typedef u8 byte;
typedef u8 pix8;

// KB = 1024 bytes
// MB = 1024 KB
#define KBSIZE(n) ( (sizeof(u8)*1024) * (n) )
#define MBSIZE(n) ( KBSIZE(1024) * (n) )

/*	--	ranges	--	*/
INLINE s32 clamp(s32 x,s32 min,s32 max) // clamps x between min & max
{ return (x < min) ? min : (x > max) ? max : x; }
INLINE bool in_range(s32 x,s32 min,s32 max) // returns if x is between min & max
{ return (x >= min) && (x <= max); }

/*	--	IO operations	--	*/
INLINE void fread_u8(u8 *pntr,FILE *f) // read little-endian u8 value from file
{ fread(pntr,sizeof(u8),1,f); }
INLINE void fread_u16(u16 *pntr,FILE *f) // read little-endian u16 value from file
{
	u8 b1; fread_u8(&b1,f); // read 1st byte
	u8 b2; fread_u8(&b2,f); // read 2nd byte
	(*pntr) = b1 | (b2<<8);
}
INLINE void fread_u32(u32 *pntr,FILE *f) // read little-endian u32 value from file
{
	u16 hw1; fread_u16(&hw1,f);
	u16 hw2; fread_u16(&hw2,f);
	(*pntr) = hw1 | (hw2<<16);
}

INLINE void fwrite_u8(u8 n,FILE *f) // write little-endian u8 value to file
{ fwrite(&n,sizeof(u8),1,f);}
INLINE void fwrite_u16(u16 n,FILE *f) // write little-endian u16 value to file
{ fwrite_u8(n&0xFF,f); fwrite_u8(n>>8,f); }
INLINE void fwrite_u32(u32 n,FILE *f) // write little-endian u32 value to file
{ fwrite_u16(n&0xFFFF,f); fwrite_u16(n>>16,f); }


/*	--	string types	--	*/
INLINE void str_upper(char *str,u32 len)
{ for(u32 i=0; i<len; i++) str[i] = toupper(str[i]); }
INLINE void str_lower(char *str,u32 len)
{ for(u32 i=0; i<len; i++) str[i] = tolower(str[i]); }

/*	--	fixed-point types	--	*/
typedef s32 f32;
typedef s16 f16;

#define int2fx(n,s) ( (n)<<(s) )
#define fx2int(n,s) ( (n)>>(s) )
#define fixmul(a,b,d) ( ((a)>>((d)>>1)) * ((b)>>((d)>>1)) )
#define fixmul2(a,b,d) ( ((a)*(b)) >> (d) )

/*	--	vector types	--	*/
typedef struct { f32 x,y,z; } vec3_32;
typedef struct { f32 x,y; } vec2_32;
typedef struct { f16 x,y; } vec2_16;

#endif

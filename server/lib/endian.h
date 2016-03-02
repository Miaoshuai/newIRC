/*======================================================
    > File Name: endian.h
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年01月30日 星期六 00时00分42秒
 =======================================================*/
#ifndef ENDIAN_H
#define ENDIAN_H

#include <stdint.h>
#include <endian.h>

uint64_t hostToNetwork64(uint64_t host64);

uint32_t hostToNetwork32(uint32_t host32);

uint16_t hostToNetwork16(uint16_t host16);

uint64_t networkToHost64(uint64_t net64);

uint32_t networkToHost32(uint32_t net32);

uint16_t networkToHost16(uint16_t net16);

void hello(void);

#endif

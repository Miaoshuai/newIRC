/*======================================================
    > File Name: endian.cpp
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年01月30日 星期六 23时21分07秒
 =======================================================*/
#include "endian.h"
#include <stdint.h>
#include <endian.h>
#include <stdio.h>
    
uint64_t hostToNetwork64(uint64_t host64)
{
    return htobe64(host64);
}

uint32_t hostToNetwork32(uint32_t host32)
{
    return htobe32(host32);
}

uint16_t hostToNetwork16(uint16_t host16)
{
    return htobe16(host16);
}

uint64_t networkToHost64(uint64_t net64)
{
    return be64toh(net64);
}

uint32_t networkToHost32(uint32_t net32)
{
    return be32toh(net32);
}

uint16_t networkToHost16(uint16_t net16)
{
    return be16toh(net16);
}


void hello(void)
{
    printf("hello\n");
}

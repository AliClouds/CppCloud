/*-------------------------------------------------------------------------
FileName     : route_exchange.h
Description  : 路由交换拦截器
remark       : 
Modification :
--------------------------------------------------------------------------
   1、Date  2018-09-19       create     hejl 
-------------------------------------------------------------------------*/
#ifndef _ROUTE_EXCHANGE_H_
#define _ROUTE_EXCHANGE_H_
#include "clibase.h"


class RouteExchage: public HEpBase
{
public:
    HEPCLASS_DECL(RouteExchage, RouteExchage);

    RouteExchage(void);
    void init( void );

    static int on_CMD_ERAALL_REQ( void* ptr, unsigned cmdid, void* param );

protected: // interface IEPollRun
	//virtual int onEvent( int evtype, va_list ap );
    //virtual int qrun( int flag, long p2 );

protected:
    static int s_my_svrid;
};

#endif
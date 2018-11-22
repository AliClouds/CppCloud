/*-------------------------------------------------------------------------
FileName     : service_provider.h
Description  : 服务提供者
remark       : 
Modification :
--------------------------------------------------------------------------
   1、Date  2018-10-16       create     hejl 
-------------------------------------------------------------------------*/
#ifndef _SERVICE_PROVIDER_H_
#define _SERVICE_PROVIDER_H_
#include <string>
#include <map>
#include "cloud/svrprop.h"

using namespace std;
class CliBase;

struct ServiceItem : public SvrProp
{
	string regname2;
	ServiceItem( void );

	int parse0( const string& name, CliBase* cli, int prvdid );
	int parse( CliBase* cli );
	void getJsonStr( string& strjson, int oweight = 0 ) const;
	void getCalcJson( string& strjson , int oweight) const;

	int score( short idc, short rack ) const;
};

typedef map<int, ServiceItem*> SVRITEM_MAP;

class ServiceProvider
{
public:
	ServiceProvider( const string& svrName );
	~ServiceProvider( void );

	int setItem( CliBase* cli, int prvdid );
	bool removeItme( CliBase* cli );

	// 计算返回可用服务
	int query( string& jstr, short idc, short rack, short version, short limit ) const;
	int getAllJson( string& strjson ) const;

private:
	const string m_regName;
	map<CliBase*, SVRITEM_MAP> m_svrItems;
};

#endif

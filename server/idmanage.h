/******************************************************************* 
 *  summery:        ����ObjectIdͬ��������(��ʱ����)
 *  author:         hejl
 *  date:           2016-10-17
 *  description:    ʹ�ù����ڴ汣֤�����ͬ������
 ******************************************************************/
#ifndef _IDMANAGE_H_
#define _IDMANAGE_H_
#include <string>
#include "comm/lock.h"
#include "comm/public.h"

using std::string;
const char SHMDATA_VERSION = 1;
const int VAL_COUNT = 4; 
enum id_index_t
{
    IDX_PROBE, // ̽��id
    IDX_ONOFF, // ������id
};

class IdMgr
{
    struct ShmData
    {
        char ver;
        short hostid;
        int addsum; // ͳ��flush�������˵���
        long long num;
    };

    SINGLETON_CLASS2(IdMgr);
private:
    IdMgr(void);
    ~IdMgr(void);

public:
    int init(int key);
    void uninit(void);

    int set(long long val);
    long long getObjectId(void);

private:
    key_t m_key;
    int m_shmid; // �����ڴ��ʶ;
    ShmData* m_ptr;
    SemLock m_lock;
};

#endif
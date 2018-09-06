/******************************************************************* 
 *  summery: ��Ϣ���д�����
 *  author:  hejl
 *  date:    2017-03-15
 *  description: ��װipc msgget msgsnd msgrcv ...
 ******************************************************************/

class IpcMsg
{
public:
    IpcMsg(void);
    int init(int key, bool creatIfno);

    // ��ȡ���е�����
    int qsize(void);
    // ɾ��
    int del(void);

    // ����(����mode)
    int send(const void* dataptr, unsigned int size);
    // ����(����mode)
    int recv(void* dataptr, unsigned int size, bool noerr, bool noblock = false);
    // ��ն��е�����
    int clear(int num = 0);

private:
    int m_key;
    int m_msgid;
};


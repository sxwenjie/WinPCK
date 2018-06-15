#include "PckClassThread.h"

SRWLOCK				CPckClassThreadWorker::g_mt_LockCompressedflag;
SRWLOCK				CPckClassThreadWorker::g_mt_LockThreadID;
SRWLOCK				CPckClassThreadWorker::g_mt_LockReadFileMap;

int					CPckClassThreadWorker::mt_threadID;		//线程ID

HANDLE				CPckClassThreadWorker::mt_evtAllWriteFinish;											//线程事件
CMapViewFileRead	*CPckClassThreadWorker::mt_lpFileRead;													//全局读文件的句柄,目前仅用于重压缩
CMapViewFileWrite	*CPckClassThreadWorker::mt_lpFileWrite;												//全局写文件的句柄
QWORD				CPckClassThreadWorker::mt_CompressTotalFileSize;										//预计的压缩文件大小
DWORD				CPckClassThreadWorker::mt_dwFileCountOfWriteTarget;									//写入数据的目标数量,一般=mt_dwFileCount，添加时=重压缩时的有效文件数量

#ifdef _DEBUG
DWORD				CPckClassThreadWorker::mt_dwCurrentQueuePosPut;
DWORD				CPckClassThreadWorker::mt_dwCurrentQueuePosGet;				//当前队列位置
#endif

QWORD				CPckClassThreadWorker::mt_dwAddressQueue;												//全局压缩过程的写文件的位置，只由Queue控制
QWORD				CPckClassThreadWorker::mt_dwAddressNameQueue;											//读出的pck文件的压缩文件名索引起始位置

																							//添加时使用变量

char				CPckClassThreadWorker::mt_szCurrentNodeString[MAX_PATH_PCK_260];						//（界面线程中当前显示的）节点对应的pck中的文件路径
int					CPckClassThreadWorker::mt_nCurrentNodeStringLen;


#include "GRIMemoryManager.h"


GRIMemoryManager::GRIMemoryManager()
{
    blockNameTable = new QList<QString>();  //These pointer assignments lead to later bugs for soem reason
    nameTable = new QList< QList<QString>* >();
    dataBlockTable = new QList< QList<GRIBuffer*>* >();
    lockTable = new QList< QList<QReadWriteLock *>* >();
    LogMsg.SetObjectName("MM");
    log.setString(&temp,QIODevice::ReadWrite);
}



GRIMemoryManager::~GRIMemoryManager()
{

    int i;
    int s = dataBlockTable->size();
    for (i = 0; i< s; i++ ) {
        QList<GRIBuffer*> *bufferTable = dataBlockTable->at(i);
        QList<QString> *bufferNameTable = nameTable->at(i);
        QList<QReadWriteLock *> *mutexs = lockTable->at(i);
        int bIndex;
        int bSize = bufferTable->size();
        for (bIndex =0; bIndex < bSize; bIndex++) {
            GRIBuffer *buf = bufferTable->at(bIndex);
            buf->clear();
            QReadWriteLock *lock = mutexs->at(bIndex);
            delete lock;
        }
        bufferTable->clear();
        bufferNameTable->clear();
        mutexs->clear();

    }
    lockTable->clear();
    blockNameTable->clear();
    nameTable->clear();
    dataBlockTable->clear();
    delete lockTable;
    delete blockNameTable;
    delete nameTable;
    delete dataBlockTable;
}



//creates a new buffer
bool GRIMemoryManager::bufferCreate(QString dataBlockName, QString bufferName)
{
    int blockIndex = locateDataBlock(dataBlockName);

    if (blockIndex == -1) {                         //if block does not exist yet

        QList<QReadWriteLock *> *locks = new QList<QReadWriteLock *>();  //add lock block
        QReadWriteLock *lock = new QReadWriteLock();
        locks->append(lock);

        QList<GRIBuffer*> *bufferTable = new QList<GRIBuffer*>();             //add buffer block
        GRIBuffer *buf = new GRIBuffer(lock);
        bufferTable->append(buf);

        lockTable->append(locks);                                       //adding to tables
        dataBlockTable->append(bufferTable);
        blockNameTable->append(dataBlockName);

        QList<QString> *names = new QList<QString>();                     //adding names to block
        names->append(bufferName);
        nameTable->append(names);
        return true;
    } else {                                        //if block exists

        if (locateBuffer(bufferName, blockIndex) != -1) {
            return false;
        }

        QList<QReadWriteLock *> *locks = lockTable->at(blockIndex);
        QReadWriteLock *lock = new QReadWriteLock();
        locks->append(lock);


        QList<GRIBuffer*> *bufferTable = dataBlockTable->at(blockIndex);
        GRIBuffer *buf = new GRIBuffer(lock);
        bufferTable->append(buf);



        QList<QString> *names = nameTable->at(blockIndex);
        names->append(bufferName);
        return true;
    }
}




void GRIMemoryManager::bufferDelete(QString dataBlockName, QString bufferName)
{

    GRIBuffer *buf = grabBuffer(dataBlockName, bufferName);
    buf->clear();
    unsigned int i = locateBuffer(dataBlockName, bufferName);
    unsigned int j = locateDataBlock(dataBlockName);
    //remove lock
    QList<QReadWriteLock *> *lockList = lockTable->at(j);
    QReadWriteLock *lock = lockList->at(i);
    delete lock;
    lockList->removeAt(i);

    //remove buffer
    QList<GRIBuffer *> *bufList = dataBlockTable->at(j);
    GRIBuffer *temp = bufList->at(i);
    delete temp;
    bufList->removeAt(i);

    //remove name of buffer from table
    QList<QString> *strList = nameTable->at(j);
    strList->removeAt(i);
}



void GRIMemoryManager::deletePacket(QString dataBlockName, QString bufferName, unsigned int packetNumber)
{
    GRIBuffer *buf = grabBuffer(dataBlockName, bufferName);
    buf->clearPacket(packetNumber);
}


//returns the index of the current packet being read from
unsigned int GRIMemoryManager::currentPacketPosition(QString dataBlockName, QString bufferName)
{
    GRIBuffer *buf = grabBuffer(dataBlockName, bufferName);
    return buf->currentPacket();
}



//returns the index of the most recently added packet (the last packet in the buffer)
int GRIMemoryManager::lastPacket(QString dataBlockName, QString bufferName)
{
    GRIBuffer *buf = grabBuffer(dataBlockName, bufferName);

    return buf->bufferSize() == 0 ? -1 : (buf->bufferSize())-1;
}



unsigned int GRIMemoryManager::sizeofBuffer(QString dataBlockName, QString bufferName)
{
    GRIBuffer *buf = grabBuffer(dataBlockName, bufferName);
    return buf->bufferSize();
}




unsigned int GRIMemoryManager::sizeofPacket(QString dataBlockName, QString bufferName, unsigned int packetNumber)
{
    GRIBuffer *buf = grabBuffer(dataBlockName, bufferName);
    return buf->packetSize(packetNumber);
}



//sets the packet marker to be the given packetNumber. Subsequent readMemory calls will start
//from this position.
bool GRIMemoryManager::setPacketPosition(QString dataBlockName, QString bufferName, unsigned int packetNumber)
{
    GRIBuffer *buf = grabBuffer(dataBlockName, bufferName);
    buf->setPacketMarker(packetNumber);
    return true;
}



void GRIMemoryManager::bufferReadLock(QString dataBlockName, QString bufferName)
{
    unsigned int i = locateDataBlock(dataBlockName);
    unsigned int j = locateBuffer(bufferName, i);
    QList<QReadWriteLock *> *locks = lockTable->at(i);
    QReadWriteLock *lock = locks->at(j);
    //lock->lockForRead();
    while (!lock->tryLockForRead(50)) {
        QThread::currentThread()->wait(50);
    }
}



void GRIMemoryManager::bufferWriteLock(QString dataBlockName, QString bufferName)
{
    unsigned int i = locateDataBlock(dataBlockName);
    unsigned int j = locateBuffer(bufferName, i);
    QList<QReadWriteLock *> *locks = lockTable->at(i);
    QReadWriteLock *lock = locks->at(j);
    //lock->lockForWrite();
    while (!lock->tryLockForWrite(50)) {
        QThread::currentThread()->wait(50);
    }
}



void GRIMemoryManager::unlockBuffer(QString dataBlockName, QString bufferName)
{
    unsigned int i = locateDataBlock(dataBlockName);
    unsigned int j = locateBuffer(bufferName, i);
    QList<QReadWriteLock *> *locks = lockTable->at(i);
    QReadWriteLock *lock = locks->at(j);
    lock->unlock();
}



//returns the index of the given buffer
unsigned int GRIMemoryManager::locateBuffer(QString dataBlockName, QString bufferName)
{
    int blockIndex = locateDataBlock(dataBlockName);
    QList<QString> *bufferNames = nameTable->at(blockIndex);
    int i;
    int size = bufferNames->size();
    for (i = 0; i < size ; i++) {
        if (bufferNames->at(i) == bufferName) {
            return i;
        }
    }
    return -1;                                      //should not reach here if buffer exists
}



//overloaded method
unsigned int GRIMemoryManager::locateBuffer(QString bufferName, unsigned int blockIndex)
{

    QList<QString> *bufferNames = nameTable->at(blockIndex);
    int i;
    int size = bufferNames->size();
    for (i = 0; i < size ; i++) {
        if (bufferNames->at(i) == bufferName) {
            return i;
        }
    }
    return -1;                                      //should not reach here if buffer exists
}



//returns the index of the given data block in the GRIMemoryManager's tables
int GRIMemoryManager::locateDataBlock(QString dataBlockName)
{
    int i;

    int size = blockNameTable->size();

    for (i = 0; i < size; i++ ) {
        if (blockNameTable->at(i) == dataBlockName) {
            return i;
        }
    }
    return -1;                                      //should not reach here if buffer block exists
}



//returns a pointer a to the buffer requested
GRIBuffer* GRIMemoryManager::grabBuffer(QString dataBlockName, QString bufferName)
{
    int blockIndex = locateDataBlock(dataBlockName);
    if (blockIndex == -1) return 0;
    QList<GRIBuffer*> *bufferTable = dataBlockTable->at(blockIndex);
    int bufferIndex = locateBuffer(bufferName, blockIndex);
    if (bufferIndex == -1) return 0;
    GRIBuffer *buf = bufferTable->at(bufferIndex);
    return buf;
}



//returns a copy of the packet requested
char* GRIMemoryManager::readMemory(QString dataBlockName, QString bufferName, unsigned int packetNumber, char* buffer)
{
    GRIMemoryManager::bufferReadLock(dataBlockName, bufferName);

    GRIBuffer *buf = grabBuffer(dataBlockName, bufferName);
    if (packetNumber >= buf->bufferSize()) {
        buf->waitOnQueue();
    }


    //if buf = 0, should throw exception HERE

    unsigned int packSize = buf->packetSize(packetNumber);

    for (int i = 0; i < packSize; i++) {
        *(buffer+i) = buf->readBuffer(packetNumber,i);
    }

    buf->incrementPacketMarker();

    GRIMemoryManager::unlockBuffer(dataBlockName, bufferName);
    return buffer;

}



//returns a copy of the packet requested
char* GRIMemoryManager::readMemory(QString dataBlockName, QString bufferName, char* buffer)
{
    //GRIMemoryManager::bufferReadLock(dataBlockName, bufferName);
    GRIBuffer *buf = grabBuffer(dataBlockName, bufferName);
    int packetNumber = buf->currentPacket();
    //buf->incrementPacketMarker();
    //GRIMemoryManager::unlockBuffer(dataBlockName, bufferName);
    return GRIMemoryManager::readMemory(dataBlockName, bufferName, packetNumber, buffer);
}



//writes into the packet specified
bool GRIMemoryManager::writeMemory(QString dataBlockName, QString bufferName, unsigned int packetNumber, unsigned int size, char dataArray[])
{
    GRIMemoryManager::bufferWriteLock(dataBlockName, bufferName);
    GRIBuffer *buf = grabBuffer(dataBlockName, bufferName);

    for (unsigned int s = 0; s < size; s++) {
        if (!(buf->writeToBuffer(dataArray[s], packetNumber, s))) {
            return false;
        }
    }




    buf->wakeAllOnQueue();
    GRIMemoryManager::unlockBuffer(dataBlockName,bufferName);
    return true;
}



//overloaded method
bool GRIMemoryManager::writeMemory(QString dataBlockName, QString bufferName, unsigned int size, char dataArray[])
{
    //GRIMemoryManager::bufferWriteLock(dataBlockName, bufferName);
    GRIBuffer *buf = grabBuffer(dataBlockName, bufferName);
    int curPacket = buf->nextPacket();
    //GRIMemoryManager::unlockBuffer(dataBlockName, bufferName);
    return GRIMemoryManager::writeMemory(dataBlockName, bufferName, curPacket, size, dataArray);
}

void GRIMemoryManager::CommitLog(int level)
{

    if(LogMsg.IsLevelEnabled(level))
    {

        if(LogMsg.SetMessageTime(log.read(),level))

            logSignal(LogMsg);
    } else {
        log.flush();
    }
}

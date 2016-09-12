#include "DataMap.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"

#ifndef NULL
#define NULL ((void*)0)
#endif // NULL

#define SET_TYPE(name, type) \
                reset(); \
                assignName(name); \
                m_dataType = (type)

#define SET_AS(type, value) \
                * ((type *)&m_simpleData) = value

#define GET_AS(type, value) \
                *((type*)(&value)) = *((type*)(&m_simpleData))

const char * DataMap::TYPE_STRING = "string";
const char * DataMap::TYPE_INT = "int";
const char * DataMap::TYPE_FLOAT = "float";
const char * DataMap::TYPE_DOUBLE = "double";
const char * DataMap::TYPE_LONG = "long";
const char * DataMap::TYPE_SHORT = "short";
const char * DataMap::TYPE_BOOL = "boolean";
const char * DataMap::TYPE_OBJECT = "object";
const char * DataMap::TYPE_LIST = "list";


DataMap::DataMap()
{
    init();
}

DataMap::~DataMap()
{
    //dtor
    printf("delete DataMap %p\n", this);
    reset();
}
DataMap::DataMap(const char* name, const char* value)
{
    init();
    setString(name, value);
}

DataMap::DataMap(const char* name, const int value)
{
    init();
    setInt(name, value);
}

DataMap::DataMap(const char* name, const float value)
{
    init();
    setFloat(name, value);
}

DataMap::DataMap(const char* name, const double value)
{
    init();
    setDouble(name, value);
}

DataMap::DataMap(const char* name, const long value)
{
    init();
    setLong(name, value);
}

DataMap::DataMap(const char* name, const short value)
{
    init();
    setShort(name, value);
}

DataMap::DataMap(const char* name, const bool value)
{
    init();
    setBool(name, value);
}

DataMap::DataMap(const char* name, DataMap* value)
{
    init();
    setDataMap(name, value);
}

void* DataMap::getValue()
{
    if (m_dataType == NULL){
        return NULL;
    }
    if (strcmp(m_dataType, DataMap::TYPE_LIST) == 0){
        return m_value;
    }
    if (strcmp(m_dataType, DataMap::TYPE_STRING) == 0){
        return m_value;
    }
    if (strcmp(m_dataType, DataMap::TYPE_OBJECT) == 0){
        return m_value;
    }
    return &m_simpleData;
}

DataMap* DataMap::getValueByName(const char* pName)
{
    if (m_dataType == NULL){
        return NULL;
    }
    if (strcmp(m_dataType, TYPE_LIST) != 0){
        return NULL;
    }
    DataMap* pData = (DataMap*)m_value;
    while(pData != NULL){
        const char* curName = pData->m_name;
        if (strcmp(curName, pName) == 0){
            return pData;
        }
        pData = pData->m_next;
    }
    return NULL;
}

void DataMap::assignName(const char* name){
    void* pAlloced = malloc((strlen(name)/4+1)<<2);
    m_name = (char *) pAlloced;
    strcpy(m_name, name);
}

DataMap& DataMap::setString(const char* name, const char* value)
{
    SET_TYPE(name, TYPE_STRING);
    m_value =  malloc(strlen(value)+1);
    strcpy((char*)m_value, value);
    return *this;
}

DataMap& DataMap::setInt(const char* name, const int value)
{
    SET_TYPE(name, TYPE_INT);
    SET_AS(int, value);
    return *this;
}

DataMap& DataMap::setFloat(const char* name, const float value)
{
    SET_TYPE(name, TYPE_FLOAT);
    SET_AS(float, value);
    return *this;
}

DataMap& DataMap::setDouble(const char* name, const double value)
{
    SET_TYPE(name, TYPE_DOUBLE);
    SET_AS(double, value);
    return *this;
}

DataMap& DataMap::setLong(const char* name, const long value)
{
    SET_TYPE(name, TYPE_LONG);
    SET_AS(long, value);
    return *this;
}

DataMap& DataMap::setShort(const char* name, const short value)
{
    SET_TYPE(name, TYPE_LONG);
    SET_AS(short, value);
    return *this;
}

DataMap& DataMap::setBool(const char* name, const bool value)
{
    SET_TYPE(name, TYPE_BOOL);
    SET_AS(int, value?1:0);
    return *this;
}

DataMap& DataMap::setDataMap(const char* name, DataMap* value)
{
    SET_TYPE(name, TYPE_OBJECT);
    m_value = value;
    return *this;
}


#define PUSH(name, value)                                                       \
        if (m_dataType != NULL){                                                \
            if (strcmp (m_dataType, TYPE_LIST) != 0){                           \
                throw "DataMap with simple data type cannot add more value";    \
            }                                                                   \
        }                                                                       \
        DataMap* newData = new DataMap(name, value);                            \
        m_dataType = TYPE_LIST;                                                 \
        addToList(newData);                                                     \
        return *this

DataMap& DataMap::pushString(const char* name, const char* value) throw (const char *)
{
    PUSH(name, value);
}

DataMap& DataMap::pushInt(const char* name, const int value) throw (const char *)
{
    PUSH(name, value);
}

DataMap& DataMap::pushFloat(const char* name, const float value) throw (const char *)
{
    PUSH(name, value);
}

DataMap& DataMap::pushDouble(const char* name, const double value) throw (const char *)
{
    PUSH(name, value);
}

DataMap& DataMap::pushLong(const char* name, const long value) throw (const char *)
{
    PUSH(name, value);
}

DataMap& DataMap::pushShort(const char* name, const short value) throw (const char *)
{
    PUSH(name, value);
}

DataMap& DataMap::pushBool(const char* name, const bool value) throw (const char *)
{
    PUSH(name, value);
}

DataMap& DataMap::pushDataMap(const char* name, DataMap* value) throw (const char *)
{
    PUSH(name, value);
}

void DataMap::reset()
{

    if (m_name != NULL){
        printf("  delete name %s\n", m_name);
        delete m_name;
    }
    if (m_dataType == NULL){

    }else if (strcmp(m_dataType, DataMap::TYPE_STRING) == 0){
        if (m_value != NULL ) {
            printf("  delete string %s\n", (char*)m_value);
            delete (char*)m_value;
        }
    }else if (strcmp(m_dataType, DataMap::TYPE_OBJECT) == 0){
        if (m_value != NULL ) {
            printf("  delete object %p\n", (DataMap*)m_value);
            delete (DataMap*)m_value;
        }
    }else if (strcmp(m_dataType, DataMap::TYPE_LIST) == 0){
        if (m_value != NULL ) {
            DataMap* pCurrent = (DataMap*)m_value;
            DataMap* pNext;
            while(pCurrent != NULL){
                pNext = pCurrent->m_next;
                delete pCurrent;
                pCurrent = pNext;
            }
        }
    }

    init();
}

void DataMap::init()
{
    m_dataType = NULL;
    m_name = NULL;
    m_value = NULL;
}

void DataMap::addToList(DataMap* pNewData){
    if (m_value == NULL){
        m_value = pNewData;
        m_next = NULL;
        return;
    }

    DataMap* pLst = (DataMap*)m_value;
    while(pLst->m_next != NULL) {
        pLst = pLst->m_next;
    }
    pLst->m_next = pNewData;
}

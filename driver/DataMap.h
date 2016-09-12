#ifndef DATAMAP_H
#define DATAMAP_H


class DataMap
{
    public:
        static const char * TYPE_STRING;
        static const char * TYPE_INT;
        static const char * TYPE_FLOAT;
        static const char * TYPE_DOUBLE;
        static const char * TYPE_LONG;
        static const char * TYPE_SHORT;
        static const char * TYPE_BOOL;
        static const char * TYPE_OBJECT;
        static const char * TYPE_LIST;

    public:
        DataMap();
        virtual ~DataMap();
        DataMap(const char* name, const char* value);
        DataMap(const char* name, const int value);
        DataMap(const char* name, const float value);
        DataMap(const char* name, const double value);
        DataMap(const char* name, const long value);
        DataMap(const char* name, const short value);
        DataMap(const char* name, const bool value);
        DataMap(const char* name, DataMap* value);

    public:
        void* getValue();
        DataMap* getValueByName(const char* pName);

        DataMap& setString(const char*name, const char* value);
        DataMap& setInt(const char*name, const int value);
        DataMap& setFloat(const char*name, const float value);
        DataMap& setDouble(const char*name, const double value);
        DataMap& setLong(const char*name, const long value);
        DataMap& setShort(const char*name, const short value);
        DataMap& setBool(const char*name, const bool value);
        DataMap& setDataMap(const char*name, DataMap* value);

        DataMap& pushString(const char*name, const char* value) throw (const char *);
        DataMap& pushInt(const char*name, const int value) throw (const char *);
        DataMap& pushFloat(const char*name, const float value) throw (const char *);
        DataMap& pushDouble(const char*name, const double value) throw (const char *);
        DataMap& pushLong(const char*name, const long value) throw (const char *);
        DataMap& pushShort(const char*name, const short value) throw (const char *);
        DataMap& pushBool(const char*name, const bool value) throw (const char *) ;
        DataMap& pushDataMap(const char*name, DataMap* value) throw (const char *);

        const char* getName() { return m_name;}
        const char* getDataType() { return m_dataType;}


    protected:
        void reset();
        void init();
        void assignName(const char* name);
        void addToList(DataMap* pNewData);

    protected:
        const char* m_dataType;
        void* m_value;
        char* m_name;
        DataMap * m_next;

        long long m_simpleData;
};


#endif // DATAMAP_H

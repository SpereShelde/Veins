//
// Generated file, do not edit! Created by nedtool 5.5 from veins/modules/messages/Mac80211Pkt.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include "Mac80211Pkt_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace veins {

// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

Register_Class(Mac80211Pkt)

Mac80211Pkt::Mac80211Pkt(const char *name, short kind) : ::veins::MacPkt(name,kind)
{
    this->address3 = 0;
    this->address4 = 0;
    this->fragmentation = 0;
    this->informationDS = 0;
    this->sequenceControl = 0;
    this->retry = false;
    this->duration = 0;
}

Mac80211Pkt::Mac80211Pkt(const Mac80211Pkt& other) : ::veins::MacPkt(other)
{
    copy(other);
}

Mac80211Pkt::~Mac80211Pkt()
{
}

Mac80211Pkt& Mac80211Pkt::operator=(const Mac80211Pkt& other)
{
    if (this==&other) return *this;
    ::veins::MacPkt::operator=(other);
    copy(other);
    return *this;
}

void Mac80211Pkt::copy(const Mac80211Pkt& other)
{
    this->address3 = other.address3;
    this->address4 = other.address4;
    this->fragmentation = other.fragmentation;
    this->informationDS = other.informationDS;
    this->sequenceControl = other.sequenceControl;
    this->retry = other.retry;
    this->duration = other.duration;
}

void Mac80211Pkt::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::veins::MacPkt::parsimPack(b);
    doParsimPacking(b,this->address3);
    doParsimPacking(b,this->address4);
    doParsimPacking(b,this->fragmentation);
    doParsimPacking(b,this->informationDS);
    doParsimPacking(b,this->sequenceControl);
    doParsimPacking(b,this->retry);
    doParsimPacking(b,this->duration);
}

void Mac80211Pkt::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::veins::MacPkt::parsimUnpack(b);
    doParsimUnpacking(b,this->address3);
    doParsimUnpacking(b,this->address4);
    doParsimUnpacking(b,this->fragmentation);
    doParsimUnpacking(b,this->informationDS);
    doParsimUnpacking(b,this->sequenceControl);
    doParsimUnpacking(b,this->retry);
    doParsimUnpacking(b,this->duration);
}

int Mac80211Pkt::getAddress3() const
{
    return this->address3;
}

void Mac80211Pkt::setAddress3(int address3)
{
    this->address3 = address3;
}

int Mac80211Pkt::getAddress4() const
{
    return this->address4;
}

void Mac80211Pkt::setAddress4(int address4)
{
    this->address4 = address4;
}

int Mac80211Pkt::getFragmentation() const
{
    return this->fragmentation;
}

void Mac80211Pkt::setFragmentation(int fragmentation)
{
    this->fragmentation = fragmentation;
}

int Mac80211Pkt::getInformationDS() const
{
    return this->informationDS;
}

void Mac80211Pkt::setInformationDS(int informationDS)
{
    this->informationDS = informationDS;
}

int Mac80211Pkt::getSequenceControl() const
{
    return this->sequenceControl;
}

void Mac80211Pkt::setSequenceControl(int sequenceControl)
{
    this->sequenceControl = sequenceControl;
}

bool Mac80211Pkt::getRetry() const
{
    return this->retry;
}

void Mac80211Pkt::setRetry(bool retry)
{
    this->retry = retry;
}

::omnetpp::simtime_t Mac80211Pkt::getDuration() const
{
    return this->duration;
}

void Mac80211Pkt::setDuration(::omnetpp::simtime_t duration)
{
    this->duration = duration;
}

class Mac80211PktDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Mac80211PktDescriptor();
    virtual ~Mac80211PktDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(Mac80211PktDescriptor)

Mac80211PktDescriptor::Mac80211PktDescriptor() : omnetpp::cClassDescriptor("veins::Mac80211Pkt", "veins::MacPkt")
{
    propertynames = nullptr;
}

Mac80211PktDescriptor::~Mac80211PktDescriptor()
{
    delete[] propertynames;
}

bool Mac80211PktDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Mac80211Pkt *>(obj)!=nullptr;
}

const char **Mac80211PktDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Mac80211PktDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Mac80211PktDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount() : 7;
}

unsigned int Mac80211PktDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *Mac80211PktDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "address3",
        "address4",
        "fragmentation",
        "informationDS",
        "sequenceControl",
        "retry",
        "duration",
    };
    return (field>=0 && field<7) ? fieldNames[field] : nullptr;
}

int Mac80211PktDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "address3")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "address4")==0) return base+1;
    if (fieldName[0]=='f' && strcmp(fieldName, "fragmentation")==0) return base+2;
    if (fieldName[0]=='i' && strcmp(fieldName, "informationDS")==0) return base+3;
    if (fieldName[0]=='s' && strcmp(fieldName, "sequenceControl")==0) return base+4;
    if (fieldName[0]=='r' && strcmp(fieldName, "retry")==0) return base+5;
    if (fieldName[0]=='d' && strcmp(fieldName, "duration")==0) return base+6;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Mac80211PktDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "int",
        "bool",
        "simtime_t",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : nullptr;
}

const char **Mac80211PktDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Mac80211PktDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Mac80211PktDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Mac80211Pkt *pp = (Mac80211Pkt *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Mac80211PktDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Mac80211Pkt *pp = (Mac80211Pkt *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Mac80211PktDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Mac80211Pkt *pp = (Mac80211Pkt *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getAddress3());
        case 1: return long2string(pp->getAddress4());
        case 2: return long2string(pp->getFragmentation());
        case 3: return long2string(pp->getInformationDS());
        case 4: return long2string(pp->getSequenceControl());
        case 5: return bool2string(pp->getRetry());
        case 6: return simtime2string(pp->getDuration());
        default: return "";
    }
}

bool Mac80211PktDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Mac80211Pkt *pp = (Mac80211Pkt *)object; (void)pp;
    switch (field) {
        case 0: pp->setAddress3(string2long(value)); return true;
        case 1: pp->setAddress4(string2long(value)); return true;
        case 2: pp->setFragmentation(string2long(value)); return true;
        case 3: pp->setInformationDS(string2long(value)); return true;
        case 4: pp->setSequenceControl(string2long(value)); return true;
        case 5: pp->setRetry(string2bool(value)); return true;
        case 6: pp->setDuration(string2simtime(value)); return true;
        default: return false;
    }
}

const char *Mac80211PktDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *Mac80211PktDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Mac80211Pkt *pp = (Mac80211Pkt *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace veins


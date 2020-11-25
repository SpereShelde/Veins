//
// Generated file, do not edit! Created by nedtool 5.5 from veins/base/messages/AirFrame.msg.
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
#include "AirFrame_m.h"

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

Register_Class(AirFrame)

AirFrame::AirFrame(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->duration = 0;
    this->state = 1;
    this->type = 0;
    this->id = 0;
    this->protocolId = 0;
    this->channel = 0;
    this->mcs = 0;
}

AirFrame::AirFrame(const AirFrame& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

AirFrame::~AirFrame()
{
}

AirFrame& AirFrame::operator=(const AirFrame& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void AirFrame::copy(const AirFrame& other)
{
    this->signal = other.signal;
    this->poa = other.poa;
    this->duration = other.duration;
    this->state = other.state;
    this->type = other.type;
    this->id = other.id;
    this->protocolId = other.protocolId;
    this->channel = other.channel;
    this->mcs = other.mcs;
}

void AirFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->signal);
    doParsimPacking(b,this->poa);
    doParsimPacking(b,this->duration);
    doParsimPacking(b,this->state);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->id);
    doParsimPacking(b,this->protocolId);
    doParsimPacking(b,this->channel);
    doParsimPacking(b,this->mcs);
}

void AirFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->signal);
    doParsimUnpacking(b,this->poa);
    doParsimUnpacking(b,this->duration);
    doParsimUnpacking(b,this->state);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->id);
    doParsimUnpacking(b,this->protocolId);
    doParsimUnpacking(b,this->channel);
    doParsimUnpacking(b,this->mcs);
}

Signal& AirFrame::getSignal()
{
    return this->signal;
}

void AirFrame::setSignal(const Signal& signal)
{
    this->signal = signal;
}

POA& AirFrame::getPoa()
{
    return this->poa;
}

void AirFrame::setPoa(const POA& poa)
{
    this->poa = poa;
}

::omnetpp::simtime_t AirFrame::getDuration() const
{
    return this->duration;
}

void AirFrame::setDuration(::omnetpp::simtime_t duration)
{
    this->duration = duration;
}

int AirFrame::getState() const
{
    return this->state;
}

void AirFrame::setState(int state)
{
    this->state = state;
}

int AirFrame::getType() const
{
    return this->type;
}

void AirFrame::setType(int type)
{
    this->type = type;
}

long AirFrame::getId() const
{
    return this->id;
}

void AirFrame::setId(long id)
{
    this->id = id;
}

int AirFrame::getProtocolId() const
{
    return this->protocolId;
}

void AirFrame::setProtocolId(int protocolId)
{
    this->protocolId = protocolId;
}

int AirFrame::getChannel() const
{
    return this->channel;
}

void AirFrame::setChannel(int channel)
{
    this->channel = channel;
}

int AirFrame::getMcs() const
{
    return this->mcs;
}

void AirFrame::setMcs(int mcs)
{
    this->mcs = mcs;
}

class AirFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    AirFrameDescriptor();
    virtual ~AirFrameDescriptor();

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

Register_ClassDescriptor(AirFrameDescriptor)

AirFrameDescriptor::AirFrameDescriptor() : omnetpp::cClassDescriptor("veins::AirFrame", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

AirFrameDescriptor::~AirFrameDescriptor()
{
    delete[] propertynames;
}

bool AirFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AirFrame *>(obj)!=nullptr;
}

const char **AirFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *AirFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int AirFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount() : 9;
}

unsigned int AirFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<9) ? fieldTypeFlags[field] : 0;
}

const char *AirFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "signal",
        "poa",
        "duration",
        "state",
        "type",
        "id",
        "protocolId",
        "channel",
        "mcs",
    };
    return (field>=0 && field<9) ? fieldNames[field] : nullptr;
}

int AirFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "signal")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "poa")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "duration")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "state")==0) return base+3;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+4;
    if (fieldName[0]=='i' && strcmp(fieldName, "id")==0) return base+5;
    if (fieldName[0]=='p' && strcmp(fieldName, "protocolId")==0) return base+6;
    if (fieldName[0]=='c' && strcmp(fieldName, "channel")==0) return base+7;
    if (fieldName[0]=='m' && strcmp(fieldName, "mcs")==0) return base+8;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *AirFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "Signal",
        "POA",
        "simtime_t",
        "int",
        "int",
        "long",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<9) ? fieldTypeStrings[field] : nullptr;
}

const char **AirFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *AirFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int AirFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    AirFrame *pp = (AirFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *AirFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AirFrame *pp = (AirFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string AirFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AirFrame *pp = (AirFrame *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getSignal(); return out.str();}
        case 1: {std::stringstream out; out << pp->getPoa(); return out.str();}
        case 2: return simtime2string(pp->getDuration());
        case 3: return long2string(pp->getState());
        case 4: return long2string(pp->getType());
        case 5: return long2string(pp->getId());
        case 6: return long2string(pp->getProtocolId());
        case 7: return long2string(pp->getChannel());
        case 8: return long2string(pp->getMcs());
        default: return "";
    }
}

bool AirFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    AirFrame *pp = (AirFrame *)object; (void)pp;
    switch (field) {
        case 2: pp->setDuration(string2simtime(value)); return true;
        case 3: pp->setState(string2long(value)); return true;
        case 4: pp->setType(string2long(value)); return true;
        case 5: pp->setId(string2long(value)); return true;
        case 6: pp->setProtocolId(string2long(value)); return true;
        case 7: pp->setChannel(string2long(value)); return true;
        case 8: pp->setMcs(string2long(value)); return true;
        default: return false;
    }
}

const char *AirFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(Signal));
        case 1: return omnetpp::opp_typename(typeid(POA));
        default: return nullptr;
    };
}

void *AirFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    AirFrame *pp = (AirFrame *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getSignal()); break;
        case 1: return (void *)(&pp->getPoa()); break;
        default: return nullptr;
    }
}

} // namespace veins


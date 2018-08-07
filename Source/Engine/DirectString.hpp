void __thiscall DString::DString(DString *this); // idb
void __thiscall DString::DString(DString *this, DString *d); // idb
void __thiscall DString::DString(DString *this, char *s); // idb
void __thiscall DString::~DString(DString *this); // idb
ostream *__cdecl operator<<(ostream *out, DString *d); // idb
istream *__cdecl operator>>(istream *in, DString *d); // idb
DString *__thiscall DString::operator=(DString *this, char *s); // idb
DString *__thiscall DString::operator=(DString *this, DString *d); // idb
int __cdecl operator==(DString *one, DString *two); // idb
int __cdecl operator==(DString *one, char *two); // idb
int __cdecl operator==(char *one, DString *two); // idb
int __cdecl operator!=(DString *one, DString *two); // idb
int __cdecl operator!=(DString *one, char *two); // idb
int __cdecl operator!=(char *one, DString *two); // idb
int __cdecl operator<(DString *one, DString *two); // idb
int __cdecl operator<(DString *one, char *two); // idb
int __cdecl operator<(char *one, DString *two); // idb
int __cdecl operator>(DString *one, DString *two); // idb
int __cdecl operator>(DString *one, char *two); // idb
int __cdecl operator>(char *one, DString *two); // idb
DString *__thiscall DString::operator+(DString *this, DString *result, DString *__$ReturnUdt); // idb
char *__thiscall DString::operator[](DString *this, int i); // idb
char *__thiscall DString::operator char *(DString *this); // idb
int __thiscall DString::length(DString *this); // idb
int __thiscall DString::index(DString *this); // idb
int __thiscall DString::contains(DString *this, DString s); // idb
int __thiscall DString::contains(DString *this, char *s); // idb
int __thiscall DString::numWords(DString *this); // idb
DString *__thiscall DString::word(DString *this, DString *result, int __$ReturnUdt); // idb
DString *__thiscall DString::nextWord(DString *this, DString *result, int __$ReturnUdt); // idb
void __thiscall DString::moveToFirstWord(DString *this); // idb
void __thiscall DString::moveToNextWord(DString *this); // idb
DString *__thiscall DString::subString(DString *this, DString *result, int __$ReturnUdt, int start); // idb
void __thiscall DString::append(DString *this, DString d); // idb
DString *__thiscall DString::stripTrailing(DString *this, DString *result, char __$ReturnUdt); // idb
DString *__thiscall DString::stripLeading(DString *this, DString *result, char __$ReturnUdt); // idb
int __thiscall DString::asInt(DString *this); // idb
double __thiscall DString::asDouble(DString *this);
void __thiscall DString::uppercase(DString *this); // idb
DString *__thiscall DString::asUppercase(DString *this, DString *result); // idb
void __thiscall DString::lowercase(DString *this); // idb
DString *__thiscall DString::asLowercase(DString *this, DString *result); // idb
void __thiscall DString::change(DString *this, char o, char n); // idb
void __thiscall DKeyString::DKeyString(DKeyString *this); // idb
void __thiscall DKeyString::DKeyString(DKeyString *this, DString k, DString v); // idb
void __thiscall DKeyString::~DKeyString(DKeyString *this); // idb
DString *__thiscall DKeyString::key(DKeyString *this, DString *result); // idb
void __thiscall DKeyString::setKey(DKeyString *this, DString k); // idb
DString *__thiscall DKeyString::value(DKeyString *this, DString *result); // idb
void __thiscall DKeyString::setValue(DKeyString *this, DString v); // idb
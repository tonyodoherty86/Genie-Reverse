
//----- (004465D0) --------------------------------------------------------
void __thiscall DString::DString(DString *this)
{
  DString *v1; // ebx@1
  char *v2; // edx@1

  v1 = this;
  this->stringValue = 0;
  this->lengthValue = 0;
  this->numWordsValue = -1;
  this->indexValue = 0;
  this->currentWordValue = 0;
  v2 = (char *)malloc(1u);
  v1->stringValue = v2;
  strcpy(v2, message_in);
}

//----- (00446620) --------------------------------------------------------
void __thiscall DString::DString(DString *this, DString *d)
{
  DString *v2; // ebx@1
  int v3; // eax@1
  char *v4; // edx@2

  v2 = this;
  this->lengthValue = d->lengthValue;
  this->numWordsValue = d->numWordsValue;
  this->indexValue = d->indexValue;
  this->currentWordValue = d->currentWordValue;
  v3 = this->lengthValue;
  if ( v3 <= 0 )
  {
    this->stringValue = 0;
  }
  else
  {
    v4 = (char *)malloc(v3 + 1);
    v2->stringValue = v4;
    strcpy(v4, d->stringValue);
  }
}

//----- (00446690) --------------------------------------------------------
void __thiscall DString::DString(DString *this, char *s)
{
  DString *v2; // ebx@1
  size_t v3; // kr04_4@1
  char *v4; // edx@2

  v2 = this;
  v3 = strlen(s) + 1;
  v2->numWordsValue = -1;
  v2->lengthValue = v3 - 1;
  v2->indexValue = 0;
  v2->currentWordValue = 0;
  if ( (signed int)(v3 - 1) <= 0 )
  {
    v2->stringValue = 0;
  }
  else
  {
    v4 = (char *)malloc(v3);
    v2->stringValue = v4;
    strcpy(v4, s);
  }
}

//----- (00446700) --------------------------------------------------------
void __thiscall DString::~DString(DString *this)
{
  if ( this->stringValue )
    free(this->stringValue);
}

//----- (00446710) --------------------------------------------------------
ostream *__cdecl operator<<(ostream *out, DString *d)
{
  if ( d->stringValue )
    ostream::operator<<(out, d->stringValue);
  return out;
}

//----- (00446730) --------------------------------------------------------
istream *__cdecl operator>>(istream *in, DString *d)
{
  char buffer[256]; // [sp+4h] [bp-100h]@1

  ++in->_fGline;
  istream::get(in, buffer, 256, 10);
  DString::operator=(d, buffer);
  return in;
}

//----- (00446780) --------------------------------------------------------
DString *__thiscall DString::operator=(DString *this, char *s)
{
  DString *v2; // ebx@1
  size_t v3; // kr04_4@3
  char *v4; // edx@4
  unsigned int v5; // ecx@4
  char v6; // al@4
  char *v7; // edi@4
  char *v8; // esi@4
  DString *result; // eax@4

  v2 = this;
  if ( this->stringValue )
    free(this->stringValue);
  v2->numWordsValue = -1;
  v2->indexValue = 0;
  v2->currentWordValue = 0;
  v3 = strlen(s) + 1;
  v2->lengthValue = v3 - 1;
  if ( (signed int)(v3 - 1) <= 0 )
  {
    v2->stringValue = 0;
    result = v2;
  }
  else
  {
    v4 = (char *)malloc(v3);
    v2->stringValue = v4;
    v5 = strlen(s) + 1;
    v6 = v5;
    v5 >>= 2;
    qmemcpy(v4, s, 4 * v5);
    v8 = &s[4 * v5];
    v7 = &v4[4 * v5];
    LOBYTE(v5) = v6;
    result = v2;
    qmemcpy(v7, v8, v5 & 3);
  }
  return result;
}

//----- (00446800) --------------------------------------------------------
DString *__thiscall DString::operator=(DString *this, DString *d)
{
  DString *v2; // ebx@1
  int v3; // eax@3
  char *v4; // edx@4
  unsigned int v5; // ecx@4
  char v6; // al@4
  char *v7; // esi@4
  char *v8; // edi@4
  char *v9; // esi@4
  DString *result; // eax@4

  v2 = this;
  if ( this->stringValue )
    free(this->stringValue);
  v2->numWordsValue = d->numWordsValue;
  v2->indexValue = d->indexValue;
  v2->currentWordValue = d->currentWordValue;
  v3 = d->lengthValue;
  v2->lengthValue = v3;
  if ( v3 <= 0 )
  {
    v2->stringValue = 0;
    result = v2;
  }
  else
  {
    v4 = (char *)malloc(v3 + 1);
    v2->stringValue = v4;
    v5 = strlen(d->stringValue) + 1;
    v6 = v5;
    v7 = d->stringValue;
    v5 >>= 2;
    qmemcpy(v4, d->stringValue, 4 * v5);
    v9 = &v7[4 * v5];
    v8 = &v4[4 * v5];
    LOBYTE(v5) = v6;
    result = v2;
    qmemcpy(v8, v9, v5 & 3);
  }
  return result;
}

//----- (00446880) --------------------------------------------------------
BOOL __cdecl operator==(DString *one, DString *two)
{
  return strcmp(one->stringValue, two->stringValue) == 0;
}

//----- (004468E0) --------------------------------------------------------
BOOL __cdecl operator==(DString *one, char *two)
{
  return strcmp(one->stringValue, two) == 0;
}

//----- (00446930) --------------------------------------------------------
BOOL __cdecl operator==(char *one, DString *two)
{
  return strcmp(one, two->stringValue) == 0;
}

//----- (00446980) --------------------------------------------------------
BOOL __cdecl operator!=(DString *one, DString *two)
{
  return strcmp(one->stringValue, two->stringValue) != 0;
}

//----- (004469E0) --------------------------------------------------------
BOOL __cdecl operator!=(DString *one, char *two)
{
  return strcmp(one->stringValue, two) != 0;
}

//----- (00446A30) --------------------------------------------------------
BOOL __cdecl operator!=(char *one, DString *two)
{
  return strcmp(one, two->stringValue) != 0;
}

//----- (00446A80) --------------------------------------------------------
int __cdecl operator<(DString *one, DString *two)
{
  int result; // eax@1

  result = strcmp(one->stringValue, two->stringValue);
  if ( result )
    result = -(result < 0) - ((result < 0) - 1) < 0;
  return result;
}

//----- (00446AE0) --------------------------------------------------------
int __cdecl operator<(DString *one, char *two)
{
  int result; // eax@1

  result = strcmp(one->stringValue, two);
  if ( result )
    result = -(result < 0) - ((result < 0) - 1) < 0;
  return result;
}

//----- (00446B30) --------------------------------------------------------
int __cdecl operator<(char *one, DString *two)
{
  int result; // eax@1

  result = strcmp(one, two->stringValue);
  if ( result )
    result = -(result < 0) - ((result < 0) - 1) < 0;
  return result;
}

//----- (00446B80) --------------------------------------------------------
int __cdecl operator>(DString *one, DString *two)
{
  int result; // eax@1

  result = strcmp(one->stringValue, two->stringValue);
  if ( result )
    result = -(result < 0) - ((result < 0) - 1) > 0;
  return result;
}

//----- (00446BE0) --------------------------------------------------------
int __cdecl operator>(DString *one, char *two)
{
  int result; // eax@1

  result = strcmp(one->stringValue, two);
  if ( result )
    result = -(result < 0) - ((result < 0) - 1) > 0;
  return result;
}

//----- (00446C30) --------------------------------------------------------
int __cdecl operator>(char *one, DString *two)
{
  int result; // eax@1

  result = strcmp(one, two->stringValue);
  if ( result )
    result = -(result < 0) - ((result < 0) - 1) > 0;
  return result;
}

//----- (00446C80) --------------------------------------------------------
DString *__thiscall DString::operator+(DString *this, DString *result, DString *__$ReturnUdt)
{
  DString v4; // [sp-14h] [bp-40h]@1
  int v5; // [sp+4h] [bp-28h]@1
  DString *v6; // [sp+8h] [bp-24h]@1
  DString newStr; // [sp+Ch] [bp-20h]@1
  int v8; // [sp+28h] [bp-4h]@1

  v5 = 0;
  DString::DString(&newStr, this);
  v6 = &v4;
  v8 = 1;
  DString::DString(&v4, __$ReturnUdt);
  DString::append(&newStr, v4);
  DString::DString(result, &newStr);
  v5 = 1;
  LOBYTE(v8) = 0;
  DString::~DString(&newStr);
  return result;
}

//----- (00446D10) --------------------------------------------------------
char *__thiscall DString::operator[](DString *this, int i)
{
  char *result; // eax@3

  if ( i < 0 || this->lengthValue < i + 1 )
    result = this->stringValue;
  else
    result = &this->stringValue[i];
  return result;
}

//----- (00446D30) --------------------------------------------------------
char *__thiscall DString::operator char *(DString *this)
{
  return this->stringValue;
}

//----- (00446D40) --------------------------------------------------------
int __thiscall DString::length(DString *this)
{
  return this->lengthValue;
}

//----- (00446D50) --------------------------------------------------------
int __thiscall DString::index(DString *this)
{
  return this->indexValue;
}

//----- (00446D60) --------------------------------------------------------
int __thiscall DString::contains(DString *this, DString s)
{
  DString *v2; // esi@1
  const char *v3; // eax@1
  int result; // eax@2

  v2 = this;
  v3 = DString::operator char *(&s);
  if ( strstr(v2->stringValue, v3) )
  {
    DString::~DString(&s);
    result = 1;
  }
  else
  {
    DString::~DString(&s);
    result = 0;
  }
  return result;
}

//----- (00446DE0) --------------------------------------------------------
BOOL __thiscall DString::contains(DString *this, char *s)
{
  return strstr(this->stringValue, s) != 0;
}

//----- (00446E00) --------------------------------------------------------
int __thiscall DString::numWords(DString *this)
{
  DString *v1; // esi@1
  int result; // eax@1
  signed int v3; // ebx@4
  int v4; // edi@6

  v1 = this;
  result = this->numWordsValue;
  if ( result == -1 )
  {
    result = this->lengthValue;
    if ( result )
    {
      if ( *this->stringValue == 32 )
      {
        this->numWordsValue = 0;
        v3 = 0;
      }
      else
      {
        this->numWordsValue = 1;
        v3 = 1;
      }
      v4 = 0;
      if ( result > 0 )
      {
        do
        {
          if ( v3 || isspace(v1->stringValue[v4]) )
          {
            if ( isspace(v1->stringValue[v4]) )
              v3 = 0;
          }
          else
          {
            v3 = 1;
            ++v1->numWordsValue;
          }
          ++v4;
        }
        while ( v4 < v1->lengthValue );
      }
      result = v1->numWordsValue;
    }
  }
  return result;
}

//----- (00446E90) --------------------------------------------------------
DString *__thiscall DString::word(DString *this, DString *result, int __$ReturnUdt)
{
  int v3; // ebp@1
  DString *v4; // edi@1
  int v5; // eax@3
  DString *v6; // esi@4
  int v7; // esi@5
  signed int v8; // ebx@5
  int i; // ebx@14
  DString rStr; // [sp+14h] [bp-20h]@17
  int v12; // [sp+30h] [bp-4h]@17

  v3 = 0;
  v4 = this;
  if ( __$ReturnUdt > DString::numWords(this) || __$ReturnUdt < 1 )
    goto LABEL_22;
  v5 = v4->currentWordValue + 1;
  if ( __$ReturnUdt == v5 )
  {
    v6 = result;
    v4->currentWordValue = v5;
    DString::nextWord(v4, result, 1);
    return v6;
  }
  v7 = 0;
  v8 = 0;
  if ( __$ReturnUdt )
  {
    do
    {
      if ( v7 >= v4->lengthValue )
        break;
      if ( v8 || isspace(v4->stringValue[v7]) )
      {
        if ( isspace(v4->stringValue[v7]) )
          v8 = 0;
      }
      else
      {
        ++v3;
        v8 = 1;
      }
      ++v7;
    }
    while ( v3 != __$ReturnUdt );
  }
  if ( v3 != __$ReturnUdt )
  {
LABEL_22:
    v6 = result;
    DString::DString(result, message_in);
    return v6;
  }
  for ( i = v7 - 1; !isspace(v4->stringValue[v7]); ++v7 )
  {
    if ( v7 >= v4->lengthValue )
      break;
  }
  DString::subString(v4, &rStr, i, v7 - i);
  v6 = result;
  v12 = 0;
  DString::DString(result, &rStr);
  v12 = -1;
  DString::~DString(&rStr);
  return v6;
}

//----- (00446FD0) --------------------------------------------------------
DString *__thiscall DString::nextWord(DString *this, DString *result, int __$ReturnUdt)
{
  DString *v3; // edi@1
  int v4; // esi@1
  int i; // ebp@4
  DString rStr; // [sp+10h] [bp-20h]@9
  int v8; // [sp+2Ch] [bp-4h]@9

  v3 = this;
  v4 = this->indexValue;
  if ( isspace(this->stringValue[v4]) )
  {
    do
    {
      if ( v4 >= v3->lengthValue )
        break;
      ++v4;
    }
    while ( isspace(v3->stringValue[v4]) );
  }
  for ( i = v4; !isspace(v3->stringValue[v4]); ++v4 )
  {
    if ( v4 >= v3->lengthValue )
      break;
  }
  if ( __$ReturnUdt )
    v3->indexValue = v4;
  DString::subString(v3, &rStr, i, v4 - i);
  v8 = 1;
  DString::DString(result, &rStr);
  LOBYTE(v8) = 0;
  DString::~DString(&rStr);
  return result;
}

//----- (004470B0) --------------------------------------------------------
void __thiscall DString::moveToFirstWord(DString *this)
{
  this->indexValue = 0;
  this->currentWordValue = 0;
}

//----- (004470C0) --------------------------------------------------------
void __thiscall DString::moveToNextWord(DString *this)
{
  DString *v1; // esi@1
  int v2; // eax@2
  char *v3; // ecx@3
  int v4; // eax@3
  int v5; // eax@5
  char *v6; // ecx@6
  int v7; // eax@6

  v1 = this;
  if ( isspace(this->stringValue[this->indexValue]) )
  {
    do
    {
      v2 = v1->indexValue;
      if ( v2 >= v1->lengthValue )
        break;
      v3 = v1->stringValue;
      v4 = v2 + 1;
      v1->indexValue = v4;
    }
    while ( isspace(v3[v4]) );
  }
  if ( !isspace(v1->stringValue[v1->indexValue]) )
  {
    do
    {
      v5 = v1->indexValue;
      if ( v5 >= v1->lengthValue )
        break;
      v6 = v1->stringValue;
      v7 = v5 + 1;
      v1->indexValue = v7;
    }
    while ( !isspace(v6[v7]) );
  }
}

//----- (00447140) --------------------------------------------------------
DString *__thiscall DString::subString(DString *this, DString *result, int __$ReturnUdt, int start)
{
  DString *v4; // esi@1
  char *v5; // eax@1
  int v6; // edx@1
  char *v7; // edi@1
  int i; // ecx@1
  char v9; // al@3
  DString rStr; // [sp+10h] [bp-20h]@4
  int v12; // [sp+2Ch] [bp-4h]@4

  v4 = this;
  v5 = (char *)malloc(start + 1);
  v6 = __$ReturnUdt;
  v7 = v5;
  for ( i = 0; v6 < v4->lengthValue; v7[i - 1] = v9 )
  {
    if ( i >= start )
      break;
    ++i;
    v9 = v4->stringValue[v6++];
  }
  v7[i] = 0;
  DString::DString(&rStr, v7);
  v12 = 1;
  DString::DString(result, &rStr);
  LOBYTE(v12) = 0;
  DString::~DString(&rStr);
  return result;
}

//----- (004471F0) --------------------------------------------------------
void __thiscall DString::append(DString *this, DString d)
{
  DString *v2; // edi@1
  int v3; // esi@1
  int v4; // eax@1
  char *i; // ebx@1
  int j; // ebp@3

  v2 = this;
  v3 = 0;
  v4 = DString::length(&d);
  for ( i = (char *)malloc(v4 + v2->lengthValue + 1); v3 < v2->lengthValue; i[v3 - 1] = v2->stringValue[v3 - 1] )
    ++v3;
  for ( j = v2->lengthValue; v3 < j + DString::length(&d); ++v3 )
  {
    i[v3] = *DString::operator[](&d, v3 - j);
    j = v2->lengthValue;
  }
  i[v3] = 0;
  free(v2->stringValue);
  v2->stringValue = i;
  v2->lengthValue += DString::length(&d);
  v2->numWordsValue = -1;
  v2->indexValue = 0;
  v2->currentWordValue = 0;
  DString::~DString(&d);
}

//----- (004472D0) --------------------------------------------------------
DString *__thiscall DString::stripTrailing(DString *this, DString *result, char __$ReturnUdt)
{
  DString *v3; // esi@1
  int v4; // eax@1
  char *v5; // ecx@1
  char v6; // bl@3
  DString *v7; // eax@4
  DString v9; // [sp+Ch] [bp-20h]@4
  int v10; // [sp+28h] [bp-4h]@4

  v3 = this;
  v4 = this->lengthValue;
  v5 = &this->stringValue[v4];
  if ( *(v5 - 1) == __$ReturnUdt )
  {
    do
    {
      if ( v4 <= 0 )
        break;
      v6 = *(v5 - 2);
      --v4;
      --v5;
    }
    while ( v6 == __$ReturnUdt );
  }
  v7 = DString::subString(v3, &v9, 0, v4);
  v10 = 0;
  DString::operator=(v3, v7);
  v10 = -1;
  DString::~DString(&v9);
  DString::DString(result, v3);
  return result;
}

//----- (00447370) --------------------------------------------------------
DString *__thiscall DString::stripLeading(DString *this, DString *result, char __$ReturnUdt)
{
  DString *v3; // esi@1
  int v4; // eax@1
  char *v5; // ecx@1
  DString *v6; // eax@4
  DString v8; // [sp+Ch] [bp-20h]@4
  int v9; // [sp+28h] [bp-4h]@4

  v3 = this;
  v4 = 0;
  v5 = this->stringValue;
  if ( *v5 == __$ReturnUdt )
  {
    do
    {
      if ( v4 >= v3->lengthValue )
        break;
      ++v4;
    }
    while ( v5[v4] == __$ReturnUdt );
  }
  v6 = DString::subString(v3, &v8, v4, v3->lengthValue);
  v9 = 0;
  DString::operator=(v3, v6);
  v9 = -1;
  DString::~DString(&v8);
  DString::DString(result, v3);
  return result;
}

//----- (00447400) --------------------------------------------------------
int __thiscall DString::asInt(DString *this)
{
  return atoi(this->stringValue);
}

//----- (00447410) --------------------------------------------------------
double __thiscall DString::asDouble(DString *this)
{
  return atof(this->stringValue);
}

//----- (00447420) --------------------------------------------------------
void __thiscall DString::uppercase(DString *this)
{
  DString *v1; // edi@1
  int i; // esi@1

  v1 = this;
  for ( i = 0; i < DString::length(v1); ++i )
    v1->stringValue[i] = toupper(v1->stringValue[i]);
}

//----- (00447460) --------------------------------------------------------
DString *__thiscall DString::asUppercase(DString *this, DString *result)
{
  DString rStr; // [sp+8h] [bp-20h]@1
  int v4; // [sp+24h] [bp-4h]@1

  DString::DString(&rStr, this->stringValue);
  v4 = 1;
  DString::uppercase(&rStr);
  DString::DString(result, &rStr);
  LOBYTE(v4) = 0;
  DString::~DString(&rStr);
  return result;
}

//----- (004474E0) --------------------------------------------------------
void __thiscall DString::lowercase(DString *this)
{
  DString *v1; // edi@1
  int i; // esi@1

  v1 = this;
  for ( i = 0; i < DString::length(v1); ++i )
    v1->stringValue[i] = tolower(v1->stringValue[i]);
}

//----- (00447520) --------------------------------------------------------
DString *__thiscall DString::asLowercase(DString *this, DString *result)
{
  DString rStr; // [sp+8h] [bp-20h]@1
  int v4; // [sp+24h] [bp-4h]@1

  DString::DString(&rStr, this->stringValue);
  v4 = 1;
  DString::lowercase(&rStr);
  DString::DString(result, &rStr);
  LOBYTE(v4) = 0;
  DString::~DString(&rStr);
  return result;
}

//----- (004475A0) --------------------------------------------------------
void __thiscall DString::change(DString *this, char o, char n)
{
  int i; // edx@1
  char *v4; // eax@2

  for ( i = 0; i < this->lengthValue; ++i )
  {
    v4 = &this->stringValue[i];
    if ( *v4 == o )
      *v4 = n;
  }
}

//----- (004475D0) --------------------------------------------------------
void __thiscall DKeyString::DKeyString(DKeyString *this)
{
  DKeyString *v1; // esi@1

  v1 = this;
  DString::DString(&this->keyValue, message_in);
  DString::DString(&v1->valueValue, message_in);
}

//----- (00447620) --------------------------------------------------------
void __thiscall DKeyString::DKeyString(DKeyString *this, DString k, DString v)
{
  DKeyString *v3; // esi@1

  v3 = this;
  DString::DString(&this->keyValue, &k);
  DString::DString(&v3->valueValue, &v);
  DString::~DString(&k);
  DString::~DString(&v);
}

//----- (004476A0) --------------------------------------------------------
void __thiscall DKeyString::~DKeyString(DKeyString *this)
{
  DKeyString *v1; // esi@1

  v1 = this;
  DString::~DString(&this->valueValue);
  DString::~DString(&v1->keyValue);
}

//----- (004476F0) --------------------------------------------------------
DString *__thiscall DKeyString::key(DKeyString *this, DString *result)
{
  DString::DString(result, &this->keyValue);
  return result;
}

//----- (00447710) --------------------------------------------------------
void __thiscall DKeyString::setKey(DKeyString *this, DString k)
{
  DString::operator=(&this->keyValue, &k);
  DString::~DString(&k);
}

//----- (00447760) --------------------------------------------------------
DString *__thiscall DKeyString::value(DKeyString *this, DString *result)
{
  DString::DString(result, &this->valueValue);
  return result;
}

//----- (00447780) --------------------------------------------------------
void __thiscall DKeyString::setValue(DKeyString *this, DString v)
{
  DString::operator=(&this->valueValue, &v);
  DString::~DString(&v);
}


/**
 * @file    Engine\DirectString.hpp
 * @author  Yvan Burrie
 * @date    2018/08/08
 * @version 1.0
 */

class DString
{
public:

    char *stringValue;

    int lengthValue;

    int numWordsValue;

    int indexValue;

    int currentWordValue;


    DString();
    DString(DString *d);
    DString(char *s);
    ~DString();

    //std::ostream *operator<<(ostream *out, DString *d);
    //std::istream *operator>>(istream *in, DString *d);
    DString *operator=(char *s);
    DString *operator=(DString *d);
    int operator==(DString *two);
    int operator==(char *two);
    //int operator==(DString *two);
    int operator!=(DString *two);
    int operator!=(char *two);
    //int operator!=(DString *two);
    int operator<(DString *two);
    int operator<(char *two);
    //int operator<(DString *two);
    int operator>(DString *two);
    int operator>(char *two);
    //int operator>(DString *two);
    //DString *operator+(DString *result, DString *__$ReturnUdt);
    char *operator[](int i);
    //char *operator char *();
    int length();
    int index();
    int contains(DString s);
    int contains(char *s);
    int numWords();
    DString *word(DString *result, int __$ReturnUdt);
    DString *nextWord(DString *result, int __$ReturnUdt);
    void moveToFirstWord();
    void moveToNextWord();
    DString *subString(DString *result, int __$ReturnUdt, int start);
    void append(DString d);
    DString *stripTrailing(DString *result, char __$ReturnUdt);
    DString *stripLeading(DString *result, char __$ReturnUdt);
    int asInt();
    double asDouble();
    void uppercase();
    DString *asUppercase(DString *result);
    void lowercase();
    DString *asLowercase(DString *result);
    void change(char o, char n);
};

class DKeyString
{
public:

    DString keyValue;

    DString valueValue;

    DKeyString();

    DKeyString(DString k, DString v);

    ~DKeyString();

    DString *key(DString *result);

    void setKey(DString k);

    DString *value(DString *result);

    void setValue(DString v);
};

#pragma once

/**
 * @file    Engine\DebuggingLog.hpp
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 */

class TDebuggingLog
{
public:

    int Timestamp;
    int DateTimestamp;
    int LogToFile;
    int LogToOutput;
    int Sequence;
    int Flush;
    int LogIsOpen;
    int LogError;
    unsigned int LogStartTickCount;
    unsigned int SeqNo;
    char TBuff[800];
    char osbuf[1000];
    char Filename[128];

    TDebuggingLog();
    ~TDebuggingLog();

    void LogFile(int DoLog);
    void LogOutput(int DoLog);
    void LogTimestamp(int DoTimestamp);
    void LogDateTimestamp(int DoTimestamp);

    void Time();
    void FlushToDisk(int DoFlush);
    void LogSequence(int DoSequence);

    void OpenLog();
    void FlushLog();
    void CloseLog();

    static void Log(char *fmt, ...);

    static char *YesOrNo(int TorF);
};

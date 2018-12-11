#pragma once

/**
 * @file    Engine\RGE\AiModule.hpp
 * @author  Yvan Burrie
 * @date    2018/06/25
 * @version 1.0
 */

#include "IDA.h"
#include "stdio.h"

class TribeMainDecisionAIModule;
class MainDecisionAIModule;

class AIModuleID
{
public:

    int id;

    char name[64];

    AIModuleID(char *n, int i);

    ~AIModuleID();

    void setID(int i, char *n);
};

class AIModuleMessage
{
public:

    int id;

    char text[128];

    int priority;

    AIModuleID sender,
               recipient;

    int data1,
        data2,
        data3;

    AIModuleMessage *callbackMessage;

    int timeStamp;

    AIModuleMessage *next,
                    *prev;

    AIModuleMessage();
    AIModuleMessage(int s, int r, int i, int p, int d1, int d2, int d3, AIModuleMessage *c, int t);
    AIModuleMessage(AIModuleMessage *m);

    ~AIModuleMessage();

    void setText(char *t);
    void setSender(int i, char *n);
    void setRecipient(int i, char *n);
};

class AIModule
{
public:

    AIModuleID idValue;

    int playerNumberValue;

    char playerNameValue[64];

    int runningValue,
        pausedValue;

    int logHistoryValue;
    int logCommonHistoryValue;
    FILE *historyLogFile;
    char historyLogFilename[64];

    int intelligenceLevelValue;
    int priorityValue;
    int processFrameValue;

    AIModule();
    AIModule(char *n, int i, int pN, void *pW);

    ~AIModule();

    AIModuleID *id(AIModuleID *result);
    int idNumber();
    int playerNumber();
    char *playerName();
    void setPlayer(int i, char *n);
    void start();
    void stop();
    void toggleRun();
    void togglePause();
    int running();
    int paused();
    int loggingHistory();
    int loggingCommonHistory();
    void setLogCommonHistory(int v);
    int intelligenceLevel();
    int setIntelligenceLevel(int v);
    int priority();
    int setPriority(int v);
    int incrementPriority(int v);
    int decrementPriority(int v);
    int sendMessage(AIModuleMessage *m, int processNow);
    int processMessage(AIModuleMessage *m);
    int update(int timeLimit);
    int messageLimit();
    int callbackLimit();
    int messageTimeout();
    int purgeMessages(AIModuleID s);
    int purgeMessagesWithID(AIModuleID s, int i);
    int purgeMessagesWithPriorityBelow(AIModuleID s, int p);
    int purgeMessagesWithData(AIModuleID s, int i, int n, int d);
    int purgeCallbacks(AIModuleID s);
    int purgeCallbacksWithID(AIModuleID s, int i);
    int purgeCallbacksWithPriorityBelow(AIModuleID s, int p);
    int purgeCallbacksWithData(AIModuleID s, int i, int n, int d);
    int filterOutMessage(AIModuleMessage *m);
    void logCommonHistory(char *textIn, ...);
    int processFrame();
    void incrementProcessFrame();
    int timeDifference(AIModuleMessage *m);
};

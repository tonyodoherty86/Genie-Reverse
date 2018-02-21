
/**
 * @file    Engine\Chat.hpp
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 */

#define ID_CHAT_ADD_MSG 0x17D5

#define CHAT_MAX_ARRAY_SIZE 50

class TChat
{
public:

	HWND *HostWnd;

	int chatGroupPlayers[10];

	char *Chat[CHAT_MAX_ARRAY_SIZE + 1];

	int CurrentMsgNo;

	class TTaunt *taunt;

	TChat(HWND *HostWndIn);
	~TChat();

	char *AddChatMsg(char *PlayerName, char *Text, char Local);
	char *GetChatMsg(int lineno);

	void ClearChat();

	static int MaxArraySize();

	void setWindowHandle(HWND *newHandle);
	void setInChatGroup(int playerNum, int status);

	int inChatGroup(int playerNum);

	void StopSoundSystem();
	int RestartSoundSystem(TSound_Driver *driver);
};

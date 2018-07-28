
/**
 * @file    Engine\Chat.cpp
 * @author  Yvan Burrie
 * @date    2018/06/22
 * @version 1.0
 */

TChat::TChat(HWND *HostWndIn)
{
    this->taunt = new TTaunt(sound_system); /* rge_base_game->sound_system */

    this->HostWnd = HostWndIn;

    memset(this->Chat, 0, sizeof(this->Chat));

    this->CurrentMsgNo = 0;

    int i = 0;
    do{
        this->setInChatGroup(i, 0);
    }
    while( ++i <= PLAYERS_ITERATIONS );
}

TChat::~TChat()
{
    this->ClearChat();

    if( this->taunt ){
        delete this->taunt;
    }
}

char *TChat::AddChatMsg(char *PlayerName, char *Text, char Local)
{
    char *result;

    if( PlayerName && Text ){

        if( this->CurrentMsgNo++ >= CHAT_MAX_ARRAY_SIZE ){
            this->CurrentMsgNo = 0;
        }

        if( this->Chat[this->CurrentMsgNo] ){
            delete this->Chat[this->CurrentMsgNo];
        }

        this->Chat[this->CurrentMsgNo] = new char[strlen(PlayerName) + strlen(Text) + 3];

        if( result = this->Chat[this->CurrentMsgNo] ){

            sprintf(result, "%s: %s", PlayerName, Text);

            PostMessageA(
                *this->HostWnd,
                WM_USER,
                ID_CHAT_ADD_MSG,
                this->CurrentMsgNo);

            if( this->taunt ){
                this->taunt->PlayTauntStr(Text, Local);
            }

            result = (char *)1;
        }
    }else{
        result = 0;
    }
    return result;
}

char *TChat::GetChatMsg(int lineno)
{
    if( lineno >= 0 &&
        lineno <= CHAT_MAX_ARRAY_SIZE ){
        return this->Chat[lineno];
    }else{
        return 0;
    }
}

void TChat::ClearChat()
{
    delete this->Chat;

    this->CurrentMsgNo = 0;
}

int TChat::MaxArraySize()
{
    return CHAT_MAX_ARRAY_SIZE;
}

void TChat::setWindowHandle(HWND *newHandle)
{
    this->HostWnd = newHandle;
}

void TChat::setInChatGroup(int playerNum, int status)
{
    if( playerNum >= 1 &&
        playerNum <= PLAYERS_ITERATIONS ){
        this->chatGroupPlayers[playerNum] = status;
    }
}

int TChat::inChatGroup(int playerNum)
{
    if( playerNum >= 0 &&
        playerNum <= PLAYERS_ITERATIONS ){
        return this->chatGroupPlayers[playerNum];
    }else{
        return 0;
    }
}

void TChat::StopSoundSystem()
{
    if( this->taunt ){
        this->taunt->StopSoundSystem();
    }
}

int TChat::RestartSoundSystem(TSound_Driver *driver)
{
    if( this->taunt ){
        return this->RestartSoundSystem(driver);
    }else{
        return 1;
    }
}

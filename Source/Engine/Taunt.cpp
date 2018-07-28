
/* The function TTaunt::PlayTauntStr() will filter the mute and no-mute strings typed in the chat by the user. */
#define TAUNT_MSG_MUTE "!MUTE"
#define TAUNT_MSG_NOMUTE "!NOMUTE"

void TTaunt::TTaunt(TSound_Driver *driver)
{
    this->TauntDir[0] = 0;
    
    this->RestartSoundSystem(driver);
    
    this->Mute = 0;
}

int TTaunt::PlayTauntStr(char *Msg, char Local)
{
    if( !strnicmp(Msg, TAUNT_MSG_MUTE, strlen(TAUNT_MSG_MUTE)) && Local )
    {
        this->Mute = 1;
    }
    if( !strnicmp(Msg, TAUNT_MSG_NOMUTE, strlen(TAUNT_MSG_NOMUTE)) && Local )
    {
        this->Mute = 0;
    }
    if( this->Mute )
    {
        return 0;
    }
    else
    {
        if( int TauntNo = TTaunt::GetTauntNo(Msg) )
        {
            this->PlayTauntNo(TauntNo);
        }
        return TauntNo;
    }
}

IDirectSoundBuffer * TTaunt::PlayTauntNo(int TauntNo)
{
    char FName[128];
    TDigital *audio;
    int i;

    if( !this->Mute && this != (TTaunt *)-275 && TauntNo )
    {
        sprintf(FName, "%sTaunt%.3d.wav", this->TauntDir, TauntNo);
        
        i = 4;
        do
        {
            audio = this->Audio[i];
            
            if( audio && !audio->is_playing() )
            {
                audio->unload();
            }
        }
        while( --i );
        
        i = 0;
        while( true )
        {
            audio = this->Audio[i];
            
            if( audio && !audio->is_playing() )
            {
                audio->unload();
            }
            if( ++i >= 4 )
            {
                return 0;
            }
        }
        
        TDigital *v9 = this->Audio[i];
        
        if( v9->load(FName, -1) )
            return v9->play();
        
        v9->unload();
    }
    return 0;
}

static int TTaunt::GetTauntNo(char *Msg)
{
    char *v2 = Msg;
    if( *Msg == 33 )
        v2 = Msg + 1;
    int result = atoi(v2);
    if( result )
        result = result > 999 ? 0 : result;
    return result;
}

char * TTaunt::GetTauntText(int TauntNo)
{
    char TauntsYou[] = "Taunts you!";
    
    char v4;
    char *v5;
    char *v6;

    char *v2 = this->TBuff;
    
    unsigned int v3 = strlen(TauntsYou) + 1;
    
    v4 = v3;
    v3 >>= 2;
    qmemcpy(v2, TauntsYou, 4 * v3);
    v6 = &TauntsYou[4 * v3];
    v5 = &v2[4 * v3];
    LOBYTE(v3) = v4;

    qmemcpy(v5, v6, v3 & 3);

    return v2;
}

void TTaunt::StopSoundSystem()
{
    int i = sizeof(TTaunt::Audio);
    while( --i )
    {
        
    }
  TTaunt *v1; // edi@1
  signed int v2; // ebx@1
  TDigital *v3; // esi@2

  v1 = this;
  v2 = 4;
  do
  {
    v3 = v1->Audio[0];
    if( v1->Audio[0] )
    {
      TDigital::~TDigital(v1->Audio[0]);
      operator delete(v3);
      v1->Audio[0] = 0;
    }
    v1 = (TTaunt *)((char *)v1 + 4);
    --v2;
  }
  while( v2 );
}

bool TTaunt::RestartSoundSystem(TSound_Driver *driver)
{
    int i = sizeof(TTaunt::Audio);
    do
    {
        this->Audio[i] = new TDigital(driver, "Silence", -1);
    }
    while( --i );
    
    return true;
}

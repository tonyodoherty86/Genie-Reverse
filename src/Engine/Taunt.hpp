
/**
 * @file    Engine\Taunt.hpp
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 */

class TTaunt
{
public:

	TDigital *Audio[4];

	int LastAudioPlayed;

	char TBuff[255];

	char TauntDir[128];

	int Mute = 0;

	TTaunt(TSound_Driver *driver);

	int PlayTauntStr(char *Msg, char Local);

	IDirectSoundBuffer * PlayTauntNo(int TauntNo);

	static int GetTauntNo(char *Msg);

	char * GetTauntText(int TauntNo);

	void StopSoundSystem();

	bool RestartSoundSystem(TSound_Driver *driver);
};

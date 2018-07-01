
//----- (00424E40) --------------------------------------------------------
void __thiscall RGE_Comm_Error::RGE_Comm_Error(RGE_Comm_Error *this, void *Host)
{
  this->HostHWND = Host;
  this->LastReportedError = 0;
}

//----- (00424E60) --------------------------------------------------------
void __thiscall RGE_Comm_Error::NotifyWindowParam(RGE_Comm_Error *this, COMMMESSAGES msg, int lparam)
{
  PostMessageA(this->HostHWND, 0x400u, msg, lparam);
  TDebuggingLog::Log(L, fmt, msg, lparam);
}

//----- (00424EB0) --------------------------------------------------------
void __thiscall RGE_Comm_Error::ShowReturn(RGE_Comm_Error *this, int hr, char *Text)
{
  RGE_Comm_Error *v3; // edi@1

  v3 = this;
  if ( !hr )
    return;
  TDebuggingLog::Log(L, aComm______dpCa, hr, Text);
  v3->LastReportedError = hr;
  if ( hr <= -2147467263 )
  {
    if ( hr == -2147467263 )
    {
      TDebuggingLog::Log(L, aUnsupported_);
      return;
    }
    if ( hr == -2147483638 )
    {
      TDebuggingLog::Log(L, aComErrorPendin);
      return;
    }
    goto LABEL_136;
  }
  if ( hr <= -2147221232 )
  {
    if ( hr == -2147221232 )
    {
      TDebuggingLog::Log(L, aCommClassNoAgg);
    }
    else
    {
      switch ( hr )
      {
        case -2147467259:
          TDebuggingLog::Log(L, aGenericUndefin);
          RGE_Comm_Error::NotifyWindowParam(v3, COMM_FATAL_ERROR, 0);
          break;
        case -2147467262:
          RGE_Comm_Error::NotifyWindowParam(v3, COMM_FATAL_ERROR, 0);
          TDebuggingLog::Log(L, aNoInterface);
          break;
        case -2147467261:
          TDebuggingLog::Log(L, aComInvalidPoin);
          break;
        case -2147467260:
          TDebuggingLog::Log(L, aComAborted);
          break;
        default:
          goto LABEL_136;
      }
    }
    return;
  }
  if ( hr <= -2147024882 )
  {
    if ( hr == -2147024882 )
    {
      TDebuggingLog::Log(L, aOutOfMemory);
      return;
    }
    if ( hr != -2147024891 )
    {
      if ( hr == -2147024890 )
      {
        TDebuggingLog::Log(L, aComInvalidHand);
        return;
      }
      goto LABEL_136;
    }
    TDebuggingLog::Log(L, aComErrorAccess);
LABEL_98:
    RGE_Comm_Error::NotifyWindowParam(v3, COMM_NO_LINK, 0);
    return;
  }
  if ( hr <= -2005467131 )
  {
    if ( hr == -2005467131 )
    {
      TDebuggingLog::Log(L, aAlreadyInitial);
      return;
    }
    if ( hr == -2147024809 )
    {
      TDebuggingLog::Log(L, aInvalidParams);
      return;
    }
    goto LABEL_136;
  }
  if ( hr <= -2005467116 )
  {
    if ( hr == -2005467116 )
    {
      TDebuggingLog::Log(L, aActivePlayersC);
      return;
    }
    if ( hr != -2005467126 )
      goto LABEL_136;
    TDebuggingLog::Log(L, aAccessDeniedBu);
    goto LABEL_98;
  }
  if ( hr <= -2005467096 )
  {
    if ( hr != -2005467096 )
    {
      if ( hr == -2005467106 )
      {
        TDebuggingLog::Log(L, aBufferSizeFail);
        return;
      }
      goto LABEL_136;
    }
    TDebuggingLog::Log(L, aCanTAddPlayer);
LABEL_82:
    RGE_Comm_Error::NotifyWindowParam(v3, COMM_NO_NEW_PLAYERS, 0);
    return;
  }
  if ( hr <= -2005467076 )
  {
    if ( hr == -2005467076 )
    {
      TDebuggingLog::Log(L, aCanTCreatePlay);
      return;
    }
    if ( hr == -2005467086 )
    {
      TDebuggingLog::Log(L, aCanTCreateGrou);
      return;
    }
    goto LABEL_136;
  }
  if ( hr <= -2005467056 )
  {
    if ( hr == -2005467056 )
    {
      TDebuggingLog::Log(L, aDeviceCapsAreN);
      TDebuggingLog::Log(L, aError_1);
      return;
    }
    if ( hr == -2005467066 )
    {
      TDebuggingLog::Log(L, aCanTCreateSess);
      return;
    }
    goto LABEL_136;
  }
  if ( hr <= -2005467016 )
  {
    if ( hr == -2005467016 )
    {
      TDebuggingLog::Log(L, aInvalidFlags);
      return;
    }
    if ( hr == -2005467046 )
    {
      TDebuggingLog::Log(L, aExceptionRaise);
      return;
    }
    goto LABEL_136;
  }
  if ( hr <= -2005466986 )
  {
    if ( hr == -2005466986 )
    {
      TDebuggingLog::Log(L, aInvalidPlaye_1);
      return;
    }
    if ( hr == -2005467006 )
    {
      TDebuggingLog::Log(L, aInvalidObject);
      return;
    }
    goto LABEL_136;
  }
  if ( hr <= -2005466976 )
  {
    if ( hr == -2005466976 )
    {
      TDebuggingLog::Log(L, aNotAbleToDoMul);
      return;
    }
    if ( hr == -2005466981 )
    {
      TDebuggingLog::Log(L, aInvalidGroup);
      return;
    }
    goto LABEL_136;
  }
  if ( hr <= -2005466946 )
  {
    if ( hr == -2005466946 )
    {
      TDebuggingLog::Log(L, aNoMessages);
      return;
    }
    if ( hr == -2005466966 )
    {
      TDebuggingLog::Log(L, aNoConnection);
      return;
    }
    goto LABEL_136;
  }
  if ( hr <= -2005466926 )
  {
    if ( hr == -2005466926 )
    {
      TDebuggingLog::Log(L, aNoPlayersAreCo);
      return;
    }
    if ( hr == -2005466936 )
    {
      TDebuggingLog::Log(L, aNoNameServerRu);
      return;
    }
    goto LABEL_136;
  }
  if ( hr <= -2005466906 )
  {
    if ( hr == -2005466906 )
    {
      TDebuggingLog::Log(L, aSendOverflow);
      return;
    }
    if ( hr == -2005466916 )
    {
      TDebuggingLog::Log(L, aNoSessionsAreA);
      return;
    }
    goto LABEL_136;
  }
  if ( hr <= -2005466886 )
  {
    if ( hr != -2005466886 )
    {
      if ( hr == -2005466896 )
      {
        TDebuggingLog::Log(L, aCommTimeoutRcv);
        RGE_Comm_Error::NotifyWindowParam(v3, COMM_HOST_BUSY, 0);
        return;
      }
      goto LABEL_136;
    }
    TDebuggingLog::Log(L, aCommunicatio_1);
    goto LABEL_82;
  }
  if ( hr <= -2005466856 )
  {
    if ( hr == -2005466856 )
    {
      RGE_Comm_Error::NotifyWindowParam(v3, COMM_NO_LINK, 0);
      TDebuggingLog::Log(L, aUserCancel);
      return;
    }
    if ( hr == -2005466866 )
    {
      TDebuggingLog::Log(L, aBusyRcvd);
      return;
    }
    goto LABEL_136;
  }
  if ( hr <= -2005466836 )
  {
    if ( hr == -2005466836 )
    {
      TDebuggingLog::Log(L, aPlayerLostConn);
      return;
    }
    if ( hr == -2005466846 )
    {
      TDebuggingLog::Log(L, aUnableToCreate);
      return;
    }
    goto LABEL_136;
  }
  if ( hr <= -2005466816 )
  {
    if ( hr != -2005466816 )
    {
      if ( hr == -2005466826 )
      {
        TDebuggingLog::Log(L, aLostConnection);
        RGE_Comm_Error::NotifyWindowParam(v3, COMM_CANCEL_GAME, 0);
        return;
      }
      goto LABEL_136;
    }
    TDebuggingLog::Log(L, aUnknownApplica);
    goto LABEL_98;
  }
  if ( hr <= -2005466796 )
  {
    if ( hr == -2005466796 )
    {
      TDebuggingLog::Log(L, aTheSecurePassw);
      return;
    }
    if ( hr == -2005466806 )
    {
      RGE_Comm_Error::NotifyWindowParam(v3, COMM_NO_NEW_PLAYERS, 0);
      TDebuggingLog::Log(L, aTheSessionIsIn);
      return;
    }
    goto LABEL_136;
  }
  if ( hr <= -2005466136 )
  {
    if ( hr == -2005466136 )
    {
      TDebuggingLog::Log(L, aBufferSizeFa_1);
      return;
    }
    if ( hr == -2005466786 )
    {
      TDebuggingLog::Log(L, aTheSessionIsIn);
      return;
    }
    goto LABEL_136;
  }
  if ( hr <= -2005466116 )
  {
    if ( hr == -2005466116 )
    {
      TDebuggingLog::Log(L, aApplicationHas);
      return;
    }
    if ( hr == -2005466126 )
    {
      TDebuggingLog::Log(L, aCanTStartTheAp);
      return;
    }
    goto LABEL_136;
  }
  if ( hr > -2005466086 )
  {
    if ( hr <= -2005465136 )
    {
      if ( hr == -2005465136 )
      {
        TDebuggingLog::Log(L, aSecurityAuthen);
        return;
      }
      if ( hr == -2005466066 )
      {
        TDebuggingLog::Log(L, aNotALobbySessi);
        return;
      }
      goto LABEL_136;
    }
    if ( hr <= -2005465116 )
    {
      if ( hr == -2005465116 )
      {
        TDebuggingLog::Log(L, aTheEncryptionF);
        return;
      }
      if ( hr == -2005465126 )
      {
        TDebuggingLog::Log(L, aCanTLoadSecuri);
        return;
      }
      goto LABEL_136;
    }
    if ( hr <= -2005465096 )
    {
      if ( hr == -2005465096 )
      {
        TDebuggingLog::Log(L, aCanTLoadSecu_1);
        return;
      }
      if ( hr == -2005465106 )
      {
        TDebuggingLog::Log(L, aTheSecuritySig);
        return;
      }
      goto LABEL_136;
    }
    if ( hr == -2005465076 )
    {
      TDebuggingLog::Log(L, aCanTLoadCapi);
    }
    else
    {
      if ( hr != -2005465056 )
      {
LABEL_136:
        TDebuggingLog::Log(L, aSUnhandledDpEr, Text, hr, hr);
        return;
      }
      TDebuggingLog::Log(L, aTheSecureLogon);
    }
  }
  else
  {
    if ( hr == -2005466086 )
    {
      TDebuggingLog::Log(L, aUnknownApplica);
      return;
    }
    if ( hr != -2005466096 )
      goto LABEL_136;
  }
}

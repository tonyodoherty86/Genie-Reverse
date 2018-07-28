
//----- (004CC730) --------------------------------------------------------
void __userpurge TRIBE_History_Info::TRIBE_History_Info(TRIBE_History_Info *this@<ecx>, int a2@<ebp>, int infile)
{
  this->history = 0;
  this->events = 0;
  this->number_of_entries = 0;
  this->number_of_events = 0;
  this->max_number_of_entries = 0;
  if ( infile >= 0 )
    TRIBE_History_Info::load(this, a2, infile);
}

//----- (004CC760) --------------------------------------------------------
void __thiscall TRIBE_History_Info::~TRIBE_History_Info(TRIBE_History_Info *this)
{
  TRIBE_History_Info *v1; // esi@1
  TRIBE_History_Events *i; // eax@3

  v1 = this;
  if ( this->history )
    free(this->history);
  for ( i = v1->events; i; i = v1->events )
  {
    v1->events = i->next;
    free(i);
  }
}

//----- (004CC7A0) --------------------------------------------------------
void __thiscall TRIBE_History_Info::save(TRIBE_History_Info *this, int outfile)
{
  TRIBE_History_Info *v2; // esi@1
  int v3; // edi@1
  TRIBE_History_Events *v4; // eax@1
  TRIBE_History_Events *i; // esi@3

  v2 = this;
  v3 = outfile;
  rge_write(outfile, &this->number_of_entries, 4);
  rge_write(v3, &v2->number_of_events, 4);
  rge_write(v3, &v2->max_number_of_entries, 4);
  rge_write(v3, v2->history, v2->max_number_of_entries);
  v4 = v2->events;
  for ( outfile = 0; v4; v4 = v4->next )
    ++outfile;
  rge_write(v3, &outfile, 4);
  for ( i = v2->events; i; i = i->next )
    rge_write(v3, i, 16);
}

//----- (004CC840) --------------------------------------------------------
void __userpurge TRIBE_History_Info::load(TRIBE_History_Info *this@<ecx>, int a2@<ebp>, int infile)
{
  TRIBE_History_Info *v3; // esi@1
  int v4; // edi@1
  TRIBE_History_Entry *v5; // eax@1
  int v6; // ecx@1
  TRIBE_History_Events **v7; // ebx@1
  void *v8; // esi@2
  bool v9; // zf@2
  bool v10; // sf@2

  v3 = this;
  v4 = infile;
  rge_read(a2, infile, infile, &this->number_of_entries, 4);
  rge_read(a2, v4, v4, &v3->number_of_events, 4);
  rge_read(a2, v4, v4, &v3->max_number_of_entries, 4);
  v5 = (TRIBE_History_Entry *)calloc(v3->max_number_of_entries, 1u);
  v6 = v3->max_number_of_entries;
  v3->history = v5;
  rge_read(a2, v4, v4, v5, v6);
  v7 = &v3->events;
  rge_read(a2, v4, v4, &infile, 4);
  if ( infile > 0 )
  {
    do
    {
      v8 = calloc(1u, 0x10u);
      rge_read(a2, v4, v4, v8, 16);
      *v7 = (TRIBE_History_Events *)v8;
      v9 = infile == 1;
      v10 = infile - 1 < 0;
      v7 = (TRIBE_History_Events **)((char *)v8 + 12);
      --infile;
    }
    while ( !v10 && !v9 );
  }
}

//----- (004CC8E0) --------------------------------------------------------
void __thiscall TRIBE_History_Info::add_history_entry(TRIBE_History_Info *this, char history_type, char entry)
{
  TRIBE_History_Info *v3; // ebx@1
  signed int v4; // esi@1
  TRIBE_History_Entry *v5; // ebp@2

  v3 = this;
  v4 = this->max_number_of_entries;
  if ( this->number_of_entries >= v4 )
  {
    this->max_number_of_entries = v4 + 60;
    v5 = (TRIBE_History_Entry *)calloc(v4 + 60, 1u);
    if ( v4 > 0 )
    {
      qmemcpy(v5, v3->history, v4);
      free(v3->history);
    }
    v3->history = v5;
  }
  if ( !history_type )
    v3->history[v3->number_of_entries].population = entry;
  ++v3->number_of_entries;
}

//----- (004CC950) --------------------------------------------------------
int __thiscall TRIBE_History_Info::get_history_entry_num(TRIBE_History_Info *this)
{
  return this->number_of_entries;
}

//----- (004CC960) --------------------------------------------------------
char __thiscall TRIBE_History_Info::get_history_entry(TRIBE_History_Info *this, char history_type, int time)
{
  char result; // al@4

  if ( time >= this->number_of_entries || time < 0 || history_type )
    result = 0;
  else
    result = this->history[time].population;
  return result;
}

//----- (004CC990) --------------------------------------------------------
void __thiscall TRIBE_History_Info::add_history_event(TRIBE_History_Info *this, char history_event)
{
  TRIBE_History_Info *v2; // esi@1
  TRIBE_History_Events *v3; // eax@2

  v2 = this;
  if ( this->number_of_entries > 0 )
  {
    v3 = (TRIBE_History_Events *)calloc(1u, 0x10u);
    v3->next = v2->events;
    v3->time = v2->number_of_entries;
    v3->world_time = rge_base_game->world->world_time;
    v3->event = history_event;
    v2->events = v3;
  }
}

//----- (004CC9E0) --------------------------------------------------------
int __thiscall TRIBE_History_Info::get_history_event_num(TRIBE_History_Info *this)
{
  return this->number_of_events;
}

//----- (004CC9F0) --------------------------------------------------------
char __thiscall TRIBE_History_Info::get_history_event(TRIBE_History_Info *this, int number, char *event, int *time)
{
  TRIBE_History_Events *v4; // eax@1
  char result; // al@4

  v4 = this->events;
  if ( v4 )
  {
    while ( number )
    {
      v4 = v4->next;
      if ( !v4 )
        return 0;
    }
    *event = v4->event;
    *time = v4->time;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004CCA30) --------------------------------------------------------
char __thiscall TRIBE_History_Info::get_history_event(TRIBE_History_Info *this, int time_slice, char *event)
{
  TRIBE_History_Events *v3; // eax@1
  char result; // al@4

  v3 = this->events;
  if ( v3 )
  {
    while ( v3->time != time_slice )
    {
      v3 = v3->next;
      if ( !v3 )
        return 0;
    }
    *event = v3->event;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

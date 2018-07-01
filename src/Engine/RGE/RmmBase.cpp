
//----- (00480790) --------------------------------------------------------
void __thiscall RGE_Random_Map_Module::RGE_Random_Map_Module(RGE_Random_Map_Module *this, RGE_Map *in_map, RGE_Random_Map_Module *parent_module, char resources_needed)
{
  RGE_Random_Map_Module *v4; // esi@1
  RGE_Tile **v5; // eax@2
  RGE_Map *v6; // ecx@2
  int v7; // eax@2
  RGE_Map *v8; // ecx@2
  RGE_Random_Map_Module *v9; // ecx@4

  v4 = this;
  this->vfptr = (RGE_Random_Map_ModuleVtbl *)&RGE_Random_Map_Module::`vftable';
  this->parent = parent_module;
  this->map = in_map;
  if ( in_map )
  {
    v5 = RGE_Map::give_up_map_offsets(in_map);
    v6 = v4->map;
    v4->map_row_offset = v5;
    v7 = RGE_Map::get_map_width(v6);
    v8 = v4->map;
    v4->map_width = v7;
    v4->map_height = RGE_Map::get_map_height(v8);
  }
  else
  {
    this->map_row_offset = 0;
    this->map_width = 0;
    this->map_height = 0;
  }
  v9 = v4->parent;
  v4->list = 0;
  v4->search_map = 0;
  v4->stack_array = 0;
  v4->search_map_rows = 0;
  v4->stack_offsets = 0;
  if ( v9 )
  {
    RGE_Random_Map_Module::add_module(v9, v4);
    RGE_Random_Map_Module::share_resources(
      v4->parent,
      &v4->search_map,
      &v4->search_map_rows,
      &v4->stack_array,
      &v4->stack_offsets);
  }
  else if ( resources_needed )
  {
    RGE_Random_Map_Module::create_shared_resources(v4);
  }
}
// 571E30: using guessed type unsigned __int8 (__thiscall *RGE_Random_Map_Module::`vftable')(RGE_Random_Map_Module *__hidden this);

//----- (00480840) --------------------------------------------------------
void __thiscall RGE_Random_Map_Module::~RGE_Random_Map_Module(RGE_Random_Map_Module *this)
{
  RGE_Random_Map_Module *v1; // esi@1
  RGE_Random_Map_Module_List *v2; // eax@1
  RGE_Random_Map_Module *v3; // edi@2
  RGE_Random_Map_Module *v4; // ecx@5

  v1 = this;
  v2 = this->list;
  for ( this->vfptr = (RGE_Random_Map_ModuleVtbl *)&RGE_Random_Map_Module::`vftable'; v2; v2 = v1->list )
  {
    v3 = v2->module;
    if ( v2->module )
    {
      RGE_Random_Map_Module::~RGE_Random_Map_Module(v2->module);
      operator delete(v3);
    }
  }
  v4 = v1->parent;
  if ( v4 )
  {
    RGE_Random_Map_Module::remove_module(v4, v1);
    v1->search_map = 0;
    v1->search_map_rows = 0;
    v1->stack_array = 0;
    v1->stack_offsets = 0;
    v1->map = 0;
    v1->map_row_offset = 0;
    v1->map_width = 0;
    v1->map_height = 0;
  }
  else
  {
    RGE_Random_Map_Module::destroy_shared_resources(v1);
    v1->map = 0;
    v1->map_row_offset = 0;
    v1->map_width = 0;
    v1->map_height = 0;
  }
}
// 571E30: using guessed type unsigned __int8 (__thiscall *RGE_Random_Map_Module::`vftable')(RGE_Random_Map_Module *__hidden this);

//----- (004808C0) --------------------------------------------------------
double __thiscall RGE_Random_Map_Module::get_schedule(RGE_Random_Map_Module *this)
{
  return this->schedule;
}

//----- (004808D0) --------------------------------------------------------
char __thiscall RGE_Random_Map_Module::generate(RGE_Random_Map_Module *this)
{
  RGE_Random_Map_Module *v1; // esi@1
  RGE_Random_Map_Module **v2; // ebx@1
  RGE_Random_Map_Module_List *v3; // edi@1
  RGE_Random_Map_Module_List *v4; // ebp@2
  float v5; // ST1C_4@3
  RGE_Random_Map_Module **v6; // esi@4
  float v7; // ST1C_4@6
  int v8; // eax@13
  RGE_Random_Map_Module_List *v9; // esi@13
  int v10; // eax@15
  char result; // al@16
  RGE_Random_Map_Module *v12; // [sp+14h] [bp-4h]@1

  v1 = this;
  v2 = 0;
  v3 = this->list;
  v12 = this;
  if ( v3 )
  {
    do
    {
      v4 = v3->next;
      if ( v2 && (v5 = RGE_Random_Map_Module::get_schedule(v3->module), RGE_Random_Map_Module::get_schedule(*v2) <= v5) )
      {
        v6 = v2;
        while ( v6[1] )
        {
          v7 = RGE_Random_Map_Module::get_schedule(v3->module);
          if ( RGE_Random_Map_Module::get_schedule((RGE_Random_Map_Module *)v6[1]->vfptr) > v7 )
            break;
          v6 = (RGE_Random_Map_Module **)v6[1];
          if ( !v6 )
            goto LABEL_11;
        }
        v3->next = (RGE_Random_Map_Module_List *)v6[1];
        v6[1] = (RGE_Random_Map_Module *)v3;
      }
      else
      {
        v3->next = (RGE_Random_Map_Module_List *)v2;
        v2 = (RGE_Random_Map_Module **)v3;
      }
LABEL_11:
      v3 = v4;
    }
    while ( v4 );
    v1 = v12;
  }
  v1->list = (RGE_Random_Map_Module_List *)v2;
  v8 = debug_rand(aCMsdevWorkA_20, 138);
  TDebuggingLog::Log(L, aRge_random_map, v8);
  v9 = v1->list;
  if ( v9 )
  {
    while ( (unsigned __int8)((int (*)(void))v9->module->vfptr->generate)() )
    {
      v10 = debug_rand(aCMsdevWorkA_20, 143);
      TDebuggingLog::Log(L, aRge_random_m_1, v10);
      v9 = v9->next;
      if ( !v9 )
        return 1;
    }
    result = 0;
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (004809E0) --------------------------------------------------------
char __thiscall RGE_Random_Map_Module::add_module(RGE_Random_Map_Module *this, RGE_Random_Map_Module *module)
{
  RGE_Random_Map_Module *v2; // esi@1
  char result; // al@2
  RGE_Random_Map_Module_List *v4; // eax@3

  v2 = this;
  if ( module )
  {
    v4 = (RGE_Random_Map_Module_List *)calloc(1u, 8u);
    v4->next = v2->list;
    v4->module = module;
    v2->list = v4;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00480A20) --------------------------------------------------------
char __thiscall RGE_Random_Map_Module::remove_module(RGE_Random_Map_Module *this, RGE_Random_Map_Module *module)
{
  RGE_Random_Map_Module_List *v2; // eax@1
  RGE_Random_Map_Module_List *v3; // edx@1
  RGE_Random_Map_Module_List *v4; // ecx@4
  RGE_Random_Map_Module_List **v5; // eax@4
  char result; // al@9

  v2 = this->list;
  v3 = 0;
  if ( v2 )
  {
    if ( v2->module == module )
    {
      v3 = this->list;
      this->list = v2->next;
    }
    else
    {
      v4 = v2->next;
      v5 = &v2->next;
      if ( v4 )
      {
        do
        {
          if ( v4->module == module )
          {
            v3 = v4;
            *v5 = v4->next;
          }
          v5 = &(*v5)->next;
          v4 = *v5;
        }
        while ( *v5 );
      }
    }
  }
  if ( v3 )
  {
    free(v3);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00480A80) --------------------------------------------------------
void __thiscall RGE_Random_Map_Module::create_shared_resources(RGE_Random_Map_Module *this)
{
  RGE_Random_Map_Module *v1; // esi@1
  char *v2; // eax@1
  size_t v3; // ecx@1
  char **v4; // eax@1
  int v5; // ecx@1
  int v6; // eax@1
  int i; // ecx@3
  int v8; // eax@4
  int j; // edx@5
  int v10; // ecx@6
  int v11; // eax@7

  v1 = this;
  v2 = (char *)calloc(this->map_width * this->map_height, 1u);
  v3 = v1->map_height;
  v1->search_map = v2;
  v4 = (char **)calloc(v3, 4u);
  v5 = v1->map_height;
  v1->search_map_rows = v4;
  v6 = 0;
  if ( v5 > 0 )
  {
    do
    {
      v1->search_map_rows[v6] = &v1->search_map[v1->map_width * v6];
      ++v6;
    }
    while ( v6 < v1->map_height );
  }
  v1->stack_array = (Map_Stack *)calloc(v1->map_width * v1->map_height, 0x18u);
  v1->stack_offsets = (Map_Stack **)calloc(v1->map_height, 4u);
  for ( i = 0; i < v1->map_height; v1->stack_offsets[i - 1] = &v1->stack_array[v8] )
    v8 = v1->map_width * i++;
  for ( j = 0; j < v1->map_height; ++j )
  {
    v10 = 0;
    if ( v1->map_width > 0 )
    {
      v11 = 0;
      do
      {
        ++v11;
        v1->stack_offsets[j][v11 - 1].x = v10++;
        *((_DWORD *)&v1->stack_offsets[j][v11] - 5) = j;
      }
      while ( v10 < v1->map_width );
    }
  }
}

//----- (00480B60) --------------------------------------------------------
void __thiscall RGE_Random_Map_Module::destroy_shared_resources(RGE_Random_Map_Module *this)
{
  RGE_Random_Map_Module *v1; // esi@1
  char **v2; // eax@3
  Map_Stack *v3; // eax@5
  Map_Stack **v4; // eax@7

  v1 = this;
  if ( this->search_map )
    free(this->search_map);
  v2 = v1->search_map_rows;
  v1->search_map = 0;
  if ( v2 )
    free(v2);
  v3 = v1->stack_array;
  v1->search_map_rows = 0;
  if ( v3 )
    free(v3);
  v4 = v1->stack_offsets;
  v1->stack_array = 0;
  if ( v4 )
    free(v4);
  v1->stack_offsets = 0;
}

//----- (00480BC0) --------------------------------------------------------
void __thiscall RGE_Random_Map_Module::update_child_resources(RGE_Random_Map_Module *this)
{
  RGE_Random_Map_Module_List *i; // esi@1

  for ( i = this->list; i; i = i->next )
    RGE_Random_Map_Module::update_resources(i->module);
}

//----- (00480BE0) --------------------------------------------------------
void __thiscall RGE_Random_Map_Module::update_resources(RGE_Random_Map_Module *this)
{
  RGE_Random_Map_Module *v1; // esi@1

  v1 = this;
  RGE_Random_Map_Module::share_resources(
    this->parent,
    &v1->search_map,
    &v1->search_map_rows,
    &this->stack_array,
    &this->stack_offsets);
  RGE_Random_Map_Module::update_child_resources(v1);
}

//----- (00480C10) --------------------------------------------------------
void __thiscall RGE_Random_Map_Module::update_child_map_info(RGE_Random_Map_Module *this)
{
  RGE_Random_Map_Module *v1; // edi@1
  RGE_Random_Map_Module_List *i; // esi@1

  v1 = this;
  for ( i = this->list; i; i = i->next )
    RGE_Random_Map_Module::update_map_info(i->module, v1->map);
}

//----- (00480C30) --------------------------------------------------------
void __thiscall RGE_Random_Map_Module::update_map_info(RGE_Random_Map_Module *this, RGE_Map *new_map)
{
  RGE_Random_Map_Module *v2; // esi@1
  RGE_Tile **v3; // eax@2
  RGE_Map *v4; // ecx@2
  int v5; // eax@2
  RGE_Map *v6; // ecx@2

  v2 = this;
  this->map = new_map;
  if ( new_map )
  {
    v3 = RGE_Map::give_up_map_offsets(new_map);
    v4 = v2->map;
    v2->map_row_offset = v3;
    v5 = RGE_Map::get_map_width(v4);
    v6 = v2->map;
    v2->map_width = v5;
    v2->map_height = RGE_Map::get_map_height(v6);
    RGE_Random_Map_Module::update_child_map_info(v2);
  }
  else
  {
    this->map_row_offset = 0;
    this->map_width = 0;
    this->map_height = 0;
    RGE_Random_Map_Module::update_child_map_info(this);
  }
}

//----- (00480C80) --------------------------------------------------------
void __thiscall RGE_Random_Map_Module::share_resources(RGE_Random_Map_Module *this, char **search_map_pointer, char ***search_map_rows_pointer, Map_Stack **stack_array_pointer, Map_Stack ***stack_offsets_pointer)
{
  if ( search_map_pointer )
    *search_map_pointer = this->search_map;
  if ( search_map_rows_pointer )
    *search_map_rows_pointer = this->search_map_rows;
  if ( stack_array_pointer )
    *stack_array_pointer = this->stack_array;
  if ( stack_offsets_pointer )
    *stack_offsets_pointer = this->stack_offsets;
}

//----- (00480CC0) --------------------------------------------------------
void __stdcall RGE_Random_Map_Module::init_stack(Map_Stack *stack)
{
  stack->x = -1;
  stack->y = -1;
  stack->next = 0;
  stack->prev = 0;
  LODWORD(stack->cost) = 0;
  LODWORD(stack->tot_cost) = 0;
}

//----- (00480CF0) --------------------------------------------------------
void __stdcall RGE_Random_Map_Module::deinit_stack(Map_Stack *stack)
{
  Map_Stack *v2; // eax@1

  v2 = stack->next;
  if ( v2 )
  {
    v2->prev = 0;
    stack->next = 0;
  }
}

//----- (00480D10) --------------------------------------------------------
void __thiscall RGE_Random_Map_Module::push_stack(RGE_Random_Map_Module *this, Map_Stack *stack, int x, int y, float cost, float tot_cost)
{
  Map_Stack *v6; // esi@1
  Map_Stack *v7; // ecx@1
  Map_Stack *v8; // edx@3

  v6 = &this->stack_offsets[y][x];
  RGE_Random_Map_Module::remove_stack_node(v6);
  v7 = stack->next;
  if ( v7 && v7->tot_cost < (double)tot_cost )
  {
    do
    {
      v8 = v7;
      v7 = v7->next;
    }
    while ( v7 && v7->tot_cost < (double)tot_cost );
    RGE_Random_Map_Module::add_stack_node(v8, v6);
    v6->cost = cost;
    v6->tot_cost = tot_cost;
  }
  else
  {
    RGE_Random_Map_Module::add_stack_node(stack, v6);
    v6->cost = cost;
    v6->tot_cost = tot_cost;
  }
}

//----- (00480DA0) --------------------------------------------------------
Map_Stack *__stdcall RGE_Random_Map_Module::pop_stack(Map_Stack *stack, int *x, int *y, float *cost)
{
  Map_Stack *v5; // esi@1
  Map_Stack *result; // eax@2
  Map_Stack *v7; // ST00_4@3

  v5 = stack->next;
  if ( v5 )
  {
    v7 = stack->next;
    *x = v5->x;
    *y = v5->y;
    *cost = v5->cost;
    RGE_Random_Map_Module::remove_stack_node(v7);
    result = v5;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00480DE0) --------------------------------------------------------
void __stdcall RGE_Random_Map_Module::add_stack_node(Map_Stack *stack, Map_Stack *new_stack)
{
  Map_Stack *v3; // ecx@4
  Map_Stack *v4; // ecx@4

  if ( new_stack->next || new_stack->prev )
    RGE_Random_Map_Module::remove_stack_node(new_stack);
  v3 = stack->next;
  new_stack->prev = stack;
  new_stack->next = v3;
  v4 = stack->next;
  if ( v4 )
    v4->prev = new_stack;
  stack->next = new_stack;
}

//----- (00480E20) --------------------------------------------------------
void __stdcall RGE_Random_Map_Module::remove_stack_node(Map_Stack *stack)
{
  Map_Stack *v2; // ecx@1
  Map_Stack *v3; // ecx@3

  v2 = stack->prev;
  if ( v2 )
    v2->next = stack->next;
  v3 = stack->next;
  if ( v3 )
    v3->prev = stack->prev;
  stack->next = 0;
  stack->prev = 0;
}

//----- (00480E50) --------------------------------------------------------
void __thiscall RGE_Random_Map_Module::clear_stack(RGE_Random_Map_Module *this)
{
  int i; // edi@1
  int v2; // edx@2
  int v3; // eax@3

  for ( i = 0; i < this->map_height; ++i )
  {
    v2 = 0;
    if ( this->map_width > 0 )
    {
      v3 = 0;
      do
      {
        ++v2;
        ++v3;
        *((_DWORD *)&this->stack_offsets[i][v3] - 2) = 0;
        *((_DWORD *)&this->stack_offsets[i][v3] - 1) = 0;
      }
      while ( v2 < this->map_width );
    }
  }
}

//----- (00480EA0) --------------------------------------------------------
bool __stdcall RGE_Random_Map_Module::check_stack(Map_Stack *stack)
{
  return stack->next || stack->prev;
}

//----- (00480EC0) --------------------------------------------------------
void __stdcall RGE_Random_Map_Module::randomize_stack(Map_Stack *stack)
{
  Map_Stack *v2; // esi@1
  signed int v3; // edi@1
  int v4; // eax@5
  int v5; // eax@6
  Map_Stack **v6; // ebp@6
  Map_Stack **v7; // edi@7
  bool v8; // sf@14
  unsigned __int8 v9; // of@14
  signed int v10; // [sp+10h] [bp-968h]@3
  signed int v11; // [sp+14h] [bp-964h]@6
  Map_Stack sub_stacks[100]; // [sp+18h] [bp-960h]@1

  v2 = sub_stacks;
  v3 = 100;
  do
  {
    RGE_Random_Map_Module::init_stack(v2);
    ++v2;
    --v3;
  }
  while ( v3 );
  v10 = 2;
  do
  {
    while ( stack->next )
    {
      v4 = debug_rand(aCMsdevWorkA_20, 488);
      RGE_Random_Map_Module::add_stack_node(&sub_stacks[100 * v4 / 0x7FFF], stack->next);
    }
    v5 = 24;
    v6 = &sub_stacks[0].next;
    v11 = 24;
    do
    {
      v7 = (Map_Stack **)((char *)&sub_stacks[0].next + v5);
      while ( *v6 )
      {
        RGE_Random_Map_Module::add_stack_node(stack, *v6);
LABEL_12:
        if ( *v7 )
          RGE_Random_Map_Module::add_stack_node(stack, *v7);
      }
      if ( *v7 )
        goto LABEL_12;
      v6 += 12;
      v5 = v11 + 48;
      v9 = __OFSUB__(v11 + 48, 2424);
      v8 = v11 - 2376 < 0;
      v11 += 48;
    }
    while ( v8 ^ v9 );
    --v10;
  }
  while ( v10 );
}

//----- (00480FB0) --------------------------------------------------------
char __thiscall RGE_Random_Map_Module::find_path(RGE_Random_Map_Module *this, int x, int y, int *end_x, int *end_y, float *terrain)
{
  RGE_Random_Map_Module *v6; // esi@1
  char v7; // bl@1
  Map_Stack path_stack; // [sp+8h] [bp-18h]@1

  v6 = this;
  RGE_Random_Map_Module::init_stack(&path_stack);
  v7 = RGE_Random_Map_Module::find_path(v6, &path_stack, x, y, end_x, end_y, terrain);
  RGE_Random_Map_Module::deinit_stack(&path_stack);
  return v7;
}

//----- (00481000) --------------------------------------------------------
char __thiscall RGE_Random_Map_Module::find_path(RGE_Random_Map_Module *this, Map_Stack *path_stack, int x, int y, int *end_x, int *end_y, float *terrain)
{
  RGE_Random_Map_Module *v7; // esi@1
  int *v8; // ebp@1
  int *v9; // edi@1
  int v10; // eax@1
  unsigned __int8 v11; // ST2C_1@1
  float *v12; // edx@1
  int v13; // edx@2
  int v14; // ecx@2
  int v15; // ebp@2
  int v16; // eax@2
  int v17; // ecx@2
  long double v18; // st7@2
  double v19; // st7@4
  double v20; // st7@5
  int v21; // ebp@7
  char *v22; // eax@7
  char *v23; // edi@7
  char v24; // al@7
  double v25; // st6@9
  float v26; // ST28_4@9
  float tot_cost; // ST10_4@9
  int *v28; // ebx@15
  double v29; // st7@15
  double v30; // st7@16
  int v31; // ebp@18
  char *v32; // eax@18
  char *v33; // edi@18
  char v34; // al@18
  double v35; // st6@20
  float v36; // ST28_4@20
  float v37; // ST10_4@20
  double v38; // st7@26
  double v39; // st7@27
  int v40; // edi@29
  char *v41; // ebx@29
  char *v42; // ebp@29
  char v43; // bl@29
  char v44; // al@30
  double v45; // st7@31
  float v46; // ST28_4@31
  float v47; // ST10_4@31
  char **v48; // ebx@36
  int v49; // eax@36
  char *v50; // ebx@36
  char v51; // bl@36
  float *v52; // ebx@37
  int *v53; // edx@40
  double v54; // st7@40
  double v55; // st7@40
  double v56; // st7@41
  float v57; // ST10_4@43
  char **v58; // ebx@47
  int v59; // eax@47
  char *v60; // ebx@47
  char v61; // bl@47
  float *v62; // ebx@48
  int *v63; // edx@51
  double v64; // st7@51
  double v65; // st7@51
  double v66; // st7@52
  float v67; // ST10_4@54
  int *v68; // ebx@58
  double v69; // st7@58
  double v70; // st7@59
  int v71; // edi@61
  char *v72; // eax@61
  char *v73; // edx@61
  char v74; // al@61
  double v75; // st7@63
  float v76; // ST28_4@63
  float v77; // ST10_4@63
  char **v78; // edx@68
  int v79; // ebx@68
  char *v80; // eax@68
  char *v81; // edx@68
  char v82; // al@68
  float *v83; // ebx@69
  int *v84; // ecx@72
  double v85; // st7@72
  double v86; // st7@72
  double v87; // st7@73
  float v88; // ST10_4@75
  int v89; // ecx@79
  char *v90; // edx@79
  char v91; // al@79
  char *v92; // edx@79
  float *v93; // ebx@80
  double v94; // st7@83
  double v95; // st7@83
  double v96; // st7@84
  float v97; // ST10_4@86
  long double v98; // st7@90
  Map_Stack *v99; // eax@91
  char result; // al@92
  int *v101; // eax@93
  int *v102; // ecx@93
  int *v103; // eax@94
  char *v104; // eax@95
  int *v105; // ecx@95
  int *v106; // eax@95
  int v107; // edx@95
  int *v108; // ecx@96
  int *v109; // edx@96
  int *v110; // ecx@97
  int *v111; // edx@97
  int *v112; // eax@98
  int v113; // edx@98
  int *v114; // eax@99
  int *v115; // ecx@99
  int *v116; // edx@100
  int *v117; // eax@100
  bool up; // [sp+15h] [bp-23h]@20
  bool down; // [sp+16h] [bp-22h]@9
  bool right; // [sp+17h] [bp-21h]@31
  bool righta; // [sp+17h] [bp-21h]@63
  char *calc_cost; // [sp+18h] [bp-20h]@36
  float calc_costa; // [sp+18h] [bp-20h]@40
  char *calc_costb; // [sp+18h] [bp-20h]@47
  float calc_costc; // [sp+18h] [bp-20h]@51
  float calc_costd; // [sp+18h] [bp-20h]@72
  float calc_coste; // [sp+18h] [bp-20h]@83
  unsigned __int8 tile_type; // [sp+1Ch] [bp-1Ch]@8
  unsigned __int8 tile_typea; // [sp+1Ch] [bp-1Ch]@19
  unsigned __int8 tile_typeb; // [sp+1Ch] [bp-1Ch]@62
  float tcost; // [sp+20h] [bp-18h]@29
  float tcosta; // [sp+20h] [bp-18h]@61
  float hcost; // [sp+24h] [bp-14h]@2
  float cost; // [sp+28h] [bp-10h]@1
  int ty; // [sp+2Ch] [bp-Ch]@2
  int map_h; // [sp+30h] [bp-8h]@1
  int map_w; // [sp+34h] [bp-4h]@1

  v7 = this;
  cost = 0.0;
  map_w = this->map_width - 1;
  map_h = this->map_height - 1;
  RGE_Random_Map_Module::clear_stack(this);
  memset(v7->search_map, 0, v7->map_width * v7->map_height);
  v8 = end_x;
  v9 = end_y;
  v7->search_map_rows[y][x] = 3;
  v10 = *v9;
  v11 = *((_BYTE *)&v7->map_row_offset[v10][*v8] + 5) & 0x1F;
  v12 = terrain;
  v7->search_map_rows[v10][*v8] = 2;
  if ( v12[v11] <= 0.0 )
    return 0;
  v13 = x;
  v14 = *v8;
  v15 = *v9;
  v16 = x - v14;
  v17 = y;
  ty = (y - *v9) * (y - *v9) + v16 * v16;
  v18 = sqrt((double)ty);
  hcost = v18;
  if ( v18 != 0.0 )
  {
    do
    {
      if ( v17 >= map_h )
      {
        down = 0;
      }
      else
      {
        v19 = hcost;
        if ( v15 <= v17 )
          v20 = v19 - -1.0;
        else
          v20 = v19 - 1.0;
        v21 = v17 + 1;
        v22 = v7->search_map_rows[v17 + 1];
        v23 = &v22[v13];
        v24 = v22[v13];
        if ( v24 )
        {
          if ( v24 == 2 )
          {
            v101 = end_x;
            v7->search_map_rows[v21][v13] = 7;
            v102 = end_y;
            *v101 = x;
            result = 1;
            *v102 = v21;
            return result;
          }
          down = v24 != 1;
        }
        else
        {
          tile_type = *((_BYTE *)&v7->map_row_offset[v21][v13] + 5) & 0x1F;
          if ( terrain[tile_type] <= 0.0 )
          {
            *v23 = 1;
            v17 = y;
            v13 = x;
            down = 0;
          }
          else
          {
            v25 = cost + terrain[tile_type];
            *v23 = 7;
            v26 = v25;
            tot_cost = v26 + v20;
            RGE_Random_Map_Module::push_stack(v7, path_stack, x, v17 + 1, v26, tot_cost);
            v17 = y;
            v13 = x;
            down = 1;
          }
        }
      }
      if ( v17 <= 0 )
      {
        up = 0;
      }
      else
      {
        v28 = end_y;
        v29 = hcost;
        if ( *end_y >= v17 )
          v30 = v29 - -1.0;
        else
          v30 = v29 - 1.0;
        v31 = v17 - 1;
        v32 = v7->search_map_rows[v17 - 1];
        v33 = &v32[v13];
        v34 = v32[v13];
        if ( v34 )
        {
          if ( v34 == 2 )
          {
            v103 = end_x;
            v7->search_map_rows[v31][v13] = 6;
            *v103 = x;
            *v28 = v31;
            return 1;
          }
          up = v34 != 1;
        }
        else
        {
          tile_typea = *((_BYTE *)&v7->map_row_offset[v31][v13] + 5) & 0x1F;
          if ( terrain[tile_typea] <= 0.0 )
          {
            *v33 = 1;
            v17 = y;
            v13 = x;
            up = 0;
          }
          else
          {
            v35 = cost + terrain[tile_typea];
            *v33 = 6;
            v36 = v35;
            v37 = v36 + v30;
            RGE_Random_Map_Module::push_stack(v7, path_stack, x, v17 - 1, v36, v37);
            v17 = y;
            v13 = x;
            up = 1;
          }
        }
      }
      if ( v13 > 0 )
      {
        v38 = hcost;
        if ( *end_x >= v13 )
          v39 = v38 - -1.0;
        else
          v39 = v38 - 1.0;
        v40 = v13 - 1;
        v41 = v7->search_map_rows[v17];
        tcost = v39;
        v42 = &v41[v13 - 1];
        v43 = v41[v13 - 1];
        if ( v43 )
        {
          if ( v43 == 2 )
          {
            v104 = v7->search_map_rows[v17];
            v105 = end_x;
            v104[v40] = 4;
            v106 = end_y;
            v107 = y;
            *v105 = v40;
            *v106 = v107;
            return 1;
          }
          right = v43 != 1;
        }
        else
        {
          v44 = *((_BYTE *)&v7->map_row_offset[v17][v40] + 5);
          if ( terrain[v44 & 0x1F] <= 0.0 )
          {
            *v42 = 1;
            v17 = y;
            v13 = x;
            right = 0;
          }
          else
          {
            v45 = terrain[v44 & 0x1F] + cost;
            *v42 = 4;
            v46 = v45;
            v47 = v46 + tcost;
            RGE_Random_Map_Module::push_stack(v7, path_stack, v40, y, v46, v47);
            v17 = y;
            v13 = x;
            right = 1;
          }
        }
        if ( v17 > 0 )
        {
          v48 = v7->search_map_rows;
          v49 = v17 - 1;
          ty = v17 - 1;
          v50 = &v48[v17 - 1][v40];
          calc_cost = v50;
          v51 = *v50;
          if ( v51 )
          {
            if ( v51 == 2 )
            {
              v108 = end_x;
              v7->search_map_rows[v49][v40] = 8;
              v109 = end_y;
              *v108 = v40;
              *v109 = v49;
              return 1;
            }
          }
          else
          {
            v52 = &terrain[*((_BYTE *)&v7->map_row_offset[v17 - 1][v40] + 5) & 0x1F];
            if ( *v52 <= 0.0 )
            {
              *calc_cost = 1;
              v17 = y;
              v13 = x;
            }
            else if ( up && right )
            {
              v53 = end_y;
              v54 = cost - *v52 * -1.36;
              *calc_cost = 8;
              calc_costa = v54;
              v55 = tcost;
              if ( *v53 >= y )
                v56 = v55 - -0.41;
              else
                v56 = v55 - 0.41;
              v57 = calc_costa + v56;
              RGE_Random_Map_Module::push_stack(v7, path_stack, v40, ty, calc_costa, v57);
              v17 = y;
              v13 = x;
            }
          }
        }
        if ( v17 < map_h )
        {
          v58 = v7->search_map_rows;
          v59 = v17 + 1;
          ty = v17 + 1;
          v60 = &v58[v17 + 1][v40];
          calc_costb = v60;
          v61 = *v60;
          if ( v61 )
          {
            if ( v61 == 2 )
            {
              v110 = end_x;
              v7->search_map_rows[v59][v40] = 9;
              v111 = end_y;
              *v110 = v40;
              *v111 = v59;
              return 1;
            }
          }
          else
          {
            v62 = &terrain[*((_BYTE *)&v7->map_row_offset[v17 + 1][v40] + 5) & 0x1F];
            if ( *v62 <= 0.0 )
            {
              *calc_costb = 1;
              v17 = y;
              v13 = x;
            }
            else if ( down && right )
            {
              v63 = end_y;
              v64 = cost - *v62 * -1.36;
              *calc_costb = 9;
              calc_costc = v64;
              v65 = tcost;
              if ( *v63 <= y )
                v66 = v65 - -0.41;
              else
                v66 = v65 - 0.41;
              v67 = calc_costc + v66;
              RGE_Random_Map_Module::push_stack(v7, path_stack, v40, ty, calc_costc, v67);
              v17 = y;
              v13 = x;
            }
          }
        }
      }
      if ( v13 < map_w )
      {
        v68 = end_x;
        v69 = hcost;
        if ( *end_x <= v13 )
          v70 = v69 - -1.0;
        else
          v70 = v69 - 1.0;
        v71 = v13 + 1;
        tcosta = v70;
        v72 = v7->search_map_rows[v17];
        v73 = &v72[v71];
        v74 = v72[v71];
        if ( v74 )
        {
          if ( v74 == 2 )
          {
            v112 = end_y;
            v7->search_map_rows[v17][v71] = 5;
            v113 = y;
            *v68 = v71;
            *v112 = v113;
            return 1;
          }
          righta = v74 != 1;
        }
        else
        {
          tile_typeb = *((_BYTE *)&v7->map_row_offset[v17][v71] + 5) & 0x1F;
          if ( terrain[tile_typeb] <= 0.0 )
          {
            *v73 = 1;
            v17 = y;
            righta = 0;
          }
          else
          {
            v75 = cost + terrain[tile_typeb];
            *v73 = 5;
            v76 = v75;
            v77 = v76 + tcosta;
            RGE_Random_Map_Module::push_stack(v7, path_stack, v71, y, v76, v77);
            v17 = y;
            righta = 1;
          }
        }
        if ( v17 > 0 )
        {
          v78 = v7->search_map_rows;
          v79 = v17 - 1;
          ty = v17 - 1;
          v80 = v78[v17 - 1];
          v81 = &v80[v71];
          v82 = v80[v71];
          if ( v82 )
          {
            if ( v82 == 2 )
            {
              v114 = end_x;
              v115 = end_y;
              v7->search_map_rows[v79][v71] = 10;
              *v114 = v71;
              *v115 = v79;
              return 1;
            }
          }
          else
          {
            v83 = &terrain[*((_BYTE *)&v7->map_row_offset[v17 - 1][v71] + 5) & 0x1F];
            if ( *v83 <= 0.0 )
            {
              *v81 = 1;
              v17 = y;
            }
            else if ( up && righta )
            {
              v84 = end_y;
              v85 = cost - *v83 * -1.36;
              *v81 = 10;
              calc_costd = v85;
              v86 = tcosta;
              if ( *v84 >= y )
                v87 = v86 - -0.40000001;
              else
                v87 = v86 - 0.40000001;
              v88 = calc_costd + v87;
              RGE_Random_Map_Module::push_stack(v7, path_stack, v71, ty, calc_costd, v88);
              v17 = y;
            }
          }
        }
        if ( v17 < map_h )
        {
          v89 = v17 + 1;
          v90 = v7->search_map_rows[v89];
          v91 = v90[v71];
          v92 = &v90[v71];
          if ( v91 )
          {
            if ( v91 == 2 )
            {
              v116 = end_x;
              v7->search_map_rows[v89][v71] = 11;
              v117 = end_y;
              *v116 = v71;
              *v117 = v89;
              return 1;
            }
          }
          else
          {
            v93 = &terrain[*((_BYTE *)&v7->map_row_offset[v89][v71] + 5) & 0x1F];
            if ( *v93 <= 0.0 )
            {
              *v92 = 1;
            }
            else if ( down && righta )
            {
              v94 = cost - *v93 * -1.36;
              *v92 = 11;
              calc_coste = v94;
              v95 = tcosta;
              if ( *end_y <= y )
                v96 = v95 - -0.40000001;
              else
                v96 = v95 - 0.40000001;
              v97 = calc_coste + v96;
              RGE_Random_Map_Module::push_stack(v7, path_stack, v71, v89, calc_coste, v97);
            }
          }
        }
      }
      if ( !RGE_Random_Map_Module::pop_stack(path_stack, &x, &y, &cost) )
        return 0;
      v13 = x;
      v15 = *end_y;
      v17 = y;
      ty = (y - *end_y) * (y - *end_y) + (x - *end_x) * (x - *end_x);
      v98 = sqrt((double)ty);
      hcost = v98;
    }
    while ( v98 != 0.0 );
  }
  v99 = path_stack->next;
  if ( !v99 )
    return 1;
  v99->prev = 0;
  return 1;
}

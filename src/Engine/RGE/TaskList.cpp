
//----- (00471D70) --------------------------------------------------------
void __thiscall RGE_Tile_List::add_node(RGE_Tile_List *this, int col, int row)
{
  RGE_Tile_List *v3; // ebx@1
  RGE_Tile_List_Node *v4; // ebp@2
  int v5; // ecx@2
  int v6; // eax@3

  v3 = this;
  if ( this->num_active >= this->list_size )
  {
    v4 = (RGE_Tile_List_Node *)calloc(2 * this->list_size, 8u);
    qmemcpy(v4, v3->list, 8 * v3->list_size);
    free(v3->list);
    v5 = v3->list_size;
    v3->list = v4;
    v3->list_size = 2 * v5;
  }
  v3->list[v3->num_active].col = col;
  v3->list[v3->num_active].row = row;
  v6 = v3->new_count + 1;
  ++v3->num_active;
  v3->new_count = v6;
}

//----- (00471DF0) --------------------------------------------------------
void __thiscall RGE_Tile_List::del_list(RGE_Tile_List *this)
{
  RGE_Tile_List *v1; // esi@1
  int v2; // eax@1

  v1 = this;
  v2 = this->collapse_list;
  this->num_active = 0;
  this->new_count = 0;
  if ( v2 )
  {
    free(this->list);
    v1->list_size = 8;
    v1->list = (RGE_Tile_List_Node *)calloc(8u, 8u);
    v1->collapse_list = 0;
  }
}

//----- (00471E40) --------------------------------------------------------
void __thiscall RGE_Tile_List::RGE_Tile_List(RGE_Tile_List *this, int Initial_Size)
{
  RGE_Tile_List *v2; // esi@1

  v2 = this;
  this->list = (RGE_Tile_List_Node *)calloc(Initial_Size, 8u);
  v2->list_size = Initial_Size;
  v2->num_active = 0;
  v2->new_count = 0;
  v2->collapse_list = 0;
}

//----- (00471E70) --------------------------------------------------------
void __thiscall RGE_Tile_List::~RGE_Tile_List(RGE_Tile_List *this)
{
  if ( this->list )
    free(this->list);
}

//----- (00471E90) --------------------------------------------------------
void __thiscall RGE_Tile_List::get_list_info(RGE_Tile_List *this, RGE_Tile_List_Node **theList, int *list_size)
{
  *theList = this->list;
  *list_size = this->num_active;
}

//----- (00471EB0) --------------------------------------------------------
int __thiscall RGE_Tile_List::get_new_count(RGE_Tile_List *this)
{
  int result; // eax@1

  result = this->new_count;
  this->new_count = 0;
  return result;
}

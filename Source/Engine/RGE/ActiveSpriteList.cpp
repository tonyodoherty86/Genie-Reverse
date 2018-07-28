
/**
 * @file    Engine\RGE\ActiveSpriteList.cpp
 * @author  Yvan Burrie
 * @date    2018/06/27
 * @version 1.0
 */

RGE_Active_Sprite_List::RGE_Active_Sprite_List(RGE_Static_Object *owner_in)
{
    this->owner = owner_in;
}

RGE_Active_Sprite_List::~RGE_Active_Sprite_List()
{
    this->delete_list();
}

void RGE_Active_Sprite_List::load(int infile, RGE_Sprite **sprites)
{
    RGE_Sprite **v3; // ebx@1
    RGE_Active_Sprite_List *v4; // esi@1
    char (*v5)(RGE_Active_Sprite_List *, int, char, RGE_Sprite **); // ebp@1
    RGE_Active_Sprite_Node *v6; // ecx@3
    RGE_Active_Sprite_Node *v7; // eax@4

    v3 = sprites;
    v4 = this;
    v5 = this->vfptr->load_node;
    do
        rge_read((int)v5, infile, infile, &sprites, 1);
    while( v5(v4, infile, (char)sprites, v3) );
    v6 = 0;
    if( v4->list )
    {
        do
        {
            v7 = v4->list->next;
            v4->list->next = v6;
            v6 = v4->list;
            v4->list = v7;
        }
        while( v7 );
    }
    v4->list = v6;
}

char RGE_Active_Sprite_List::load_node(int infile, char type, RGE_Sprite **sprites)
{
    RGE_Active_Sprite_List *v5; // edi@1
    RGE_Active_Sprite_Node *v6; // esi@4
    RGE_Active_Animated_Sprite *v7; // eax@4
    RGE_Active_Sprite *v8; // eax@5
    RGE_Active_Sprite *v10; // eax@6
    RGE_Active_Sprite *v11; // eax@7

    v5 = this;
    if( type )
    {
        if( type == 1 )
        {
            v6 = (RGE_Active_Sprite_Node *)calloc(0xCu, 1u);
            v10 = (RGE_Active_Sprite *)operator new(0x14u);
            if( v10 )
            {
                RGE_Active_Sprite::RGE_Active_Sprite(v10, a2, infile, sprites);
                v6->node = v11;
                v6->next = v5->list;
                v5->list = v6;
                return 1;
            }
        }
        else
        {
            if( type != 2 )
                return 1;
            v6 = (RGE_Active_Sprite_Node *)calloc(0xCu, 1u);
            v7 = (RGE_Active_Animated_Sprite *)operator new(0x28u);
            if( v7 )
            {
                RGE_Active_Animated_Sprite::RGE_Active_Animated_Sprite(v7, a2, infile, sprites);
                v6->node = v8;
                v6->next = v5->list;
                v5->list = v6;
                return 1;
            }
        }
        v6->node = 0;
        v6->next = v5->list;
        v5->list = v6;
        return 1;
    }
    return 0;
}

void RGE_Active_Sprite_List::save(int outfile)
{
    RGE_Active_Sprite_Node *v2; // esi@1
    char ender; // [sp+Bh] [bp-1h]@1

    v2 = this->list;
    for( ender = 0; v2; v2 = v2->next )
        ((void (__stdcall *)(int))v2->node->vfptr->save)(outfile);
    rge_write(outfile, &ender, 1);
}

void RGE_Active_Sprite_List::delete_list()
{
    RGE_Active_Sprite_List *v1; // ebx@1
    RGE_Active_Sprite_Node *v2; // esi@1
    RGE_Active_Sprite_Node *v3; // edi@2
    RGE_Static_Object *v4; // ecx@3

    v1 = this;
    v2 = this->list;
    if( v2 )
    {
        do
        {
            v3 = v2->next;
            if( RGE_Active_Sprite::check_for_shadows(v2->node) )
            {
                v4 = v1->owner;
                if( v4 )
                    RGE_Static_Object::remove_shadows(v4);
            }
            if( v2->node )
                ((void (__stdcall *)(_DWORD))v2->node->vfptr->__vecDelDtor)(1);
            free(v2);
            v2 = v3;
        }
        while( v3 );
    }
    v1->list = 0;
}

RGE_Active_Sprite_Node *RGE_Active_Sprite_List::copy_sprite_list()
{
    RGE_Active_Sprite_List *v1; // edi@1
    RGE_Active_Sprite_Node *v2; // ebx@1
    RGE_Active_Sprite_Node *i; // esi@1
    RGE_Active_Sprite_Node *result; // eax@3

    v1 = this;
    v2 = this->list;
    this->list = 0;
    for( i = v2; i; i = i->next )
        RGE_Active_Sprite_List::add_sprite(v1, i->node->sprite, i->order, i->node->offset_x, i->node->offset_y);
    result = v1->list;
    v1->list = v2;
    return result;
}

void RGE_Active_Sprite_List::use_sprite_list(RGE_Active_Sprite_Node *temp_list)
{
    RGE_Active_Sprite_List *v2; // esi@1

    v2 = this;
    RGE_Active_Sprite_List::delete_list(this);
    v2->list = temp_list;
}

void RGE_Active_Sprite_List::add_sprite(RGE_Sprite *sprite, char order, int x, int y)
{
    RGE_Active_Sprite_List *v5; // esi@1
    RGE_Static_Object *v6; // ecx@3
    RGE_Active_Sprite_Node **v7; // edi@5
    RGE_Active_Sprite_Node *v8; // eax@5
    RGE_Active_Sprite_Node *i; // eax@8
    _BYTE *v10; // esi@12
    int *v11; // eax@12
    int v12; // edx@12

    v5 = this;
    if( sprite )
    {
        if( RGE_Sprite::check_for_shadows(sprite) )
        {
            v6 = v5->owner;
            if( v6 )
                RGE_Static_Object::remove_shadows(v6);
        }
        v7 = &v5->list;
        v8 = v5->list;
        if( v8 )
        {
            while( v8->node->sprite != sprite )
            {
                v8 = v8->next;
                if( !v8 )
                    goto LABEL_8;
            }
            ++v8->count;
        }
        else
        {
LABEL_8:
            for( i = v5->list; i && i->order <= (unsigned __int8)order; i = i->next )
                v7 = &i->next;
            v10 = calloc(0xCu, 1u);
            RGE_Sprite::make_active_sprite(sprite);
            v12 = *v11;
            *(_DWORD *)v10 = v11;
            (*(void (**)(int *, int, int))(v12 + 4))(v11, x, y);
            v10[4] = order;
            *((_DWORD *)v10 + 2) = *v7;
            *v7 = (RGE_Active_Sprite_Node *)v10;
        }
    }
}

void RGE_Active_Sprite_List::remove_sprite(RGE_Sprite *sprite)
{
    RGE_Active_Sprite_List *v2; // edi@1
    RGE_Active_Sprite_Node *v3; // esi@1
    char *v4; // eax@1
    char v5; // cl@5
    RGE_Static_Object *v6; // ecx@8

    v2 = this;
    v3 = this->list;
    v4 = (char *)&this->list;
    if( v3 )
    {
        while( v3->node->sprite != sprite )
        {
            v4 = (char *)&v3->next;
            v3 = v3->next;
            if( !v3 )
                return;
        }
        v5 = v3->count;
        if( v5 )
        {
            v3->count = v5 - 1;
        }
        else
        {
            *(_DWORD *)v4 = v3->next;
            if( RGE_Active_Sprite::check_for_shadows(v3->node) )
            {
                v6 = v2->owner;
                if( v6 )
                    RGE_Static_Object::remove_shadows(v6);
            }
            if( v3->node )
                ((void (__stdcall *)(_DWORD))v3->node->vfptr->__vecDelDtor)(1);
            free(v3);
        }
    }
}

void RGE_Active_Sprite_List::update(float time, float speed)
{
    for( RGE_Active_Sprite_Node *i = this->list; i; i = i->next )
        i->node->update(time, speed);
}

void RGE_Active_Sprite_List::draw(int facet, short x, short y, short sx, short sy, RGE_Color_Table *player_color, TDrawArea *draw_area)
{
    for( RGE_Active_Sprite_Node *i = this->list; i; i = i->next )
        i->node->draw(
            facet,
            x,
            y,
            sx,
            sy,
            player_color,
            draw_area);
}

void RGE_Active_Sprite_List::normal_draw(int facet, short x, short y, RGE_Color_Table *player_color, TDrawArea *draw_area)
{
    for( RGE_Active_Sprite_Node *i = this->list; i; i = i->next )
        i->node->normal_draw(
            facet,
            x,
            y,
            player_color,
            draw_area);
}

void RGE_Active_Sprite_List::shadow_draw(int facet, short x, short y, RGE_Color_Table *player_color, TDrawArea *draw_area, int flag)
{
    for( RGE_Active_Sprite_Node *sub_sprite = this->list; sub_sprite; sub_sprite = sub_sprite->next ){
        sub_sprite->node->shadow_draw(
            facet,
            x,
            y,
            player_color,
            draw_area,
            flag);
    }
}

short RGE_Active_Sprite_List::frame(RGE_Sprite *sprite)
{
    RGE_Active_Sprite_Node *v2; // eax@1
    short result; // ax@4

    v2 = this->list;
    if( v2 )
    {
        while( v2->node->sprite != sprite )
        {
            v2 = v2->next;
            if( !v2 )
                return 0;
        }
        result = v2->node->vfptr->what_frame(v2->node);
    }
    else
    {
        result = 0;
    }
    return result;
}

bool RGE_Active_Sprite_List::is_animating(RGE_Sprite *sprite)
{
    for( RGE_Active_Sprite_Node *sub_sprite = this->list; sub_sprite; sub_sprite = sub_sprite->next ){
        if( sub_sprite->node->sprite == sprite ){
            return sub_sprite->node->is_animating();
        }
    }
    return false;
}

void RGE_Active_Sprite_List::set_frame(RGE_Sprite *sprite, int new_frame)
{
    for( RGE_Active_Sprite_Node *sub_sprite = this->list; sub_sprite; sub_sprite = sub_sprite->next ){
        if( sub_sprite->node->sprite == sprite ){
            sub_sprite->node->set_frame(new_frame);
        }
    }
}

bool RGE_Active_Sprite_List::frame_passed(RGE_Sprite *sprite, int pass_frame)
{
    for( RGE_Active_Sprite_Node *sub_sprite = this->list; sub_sprite; sub_sprite = sub_sprite->next ){
        if( sub_sprite->node->sprite == sprite ){
            return sub_sprite->node->frame_passed(pass_frame);
        }
    }
    return false;
}

bool RGE_Active_Sprite_List::looped(RGE_Sprite *sprite)
{
    for( RGE_Active_Sprite_Node *sub_sprite = this->list; sub_sprite; sub_sprite = sub_sprite->next ){
        if( sub_sprite->node->sprite == sprite ){
            return sub_sprite->node->looped();
        }
    }
    return false;
}

short RGE_Active_Sprite_List::get_facetindex(RGE_Sprite *sprite, int facet)
{
    for( RGE_Active_Sprite_Node *sub_sprite = this->list; sub_sprite; sub_sprite = sub_sprite->next ){
        if( sub_sprite->node->sprite == sprite ){
            return sub_sprite->node->get_facetindex(facet);
        }
    }
    return 0;
}

char RGE_Active_Sprite_List::get_frame(short *min_x, short *min_y, short *max_x, short *max_y, RGE_Sprite *sprite, int facet)
{
    for( RGE_Active_Sprite_Node *sub_sprite = this->list; sub_sprite; sub_sprite = sub_sprite->next ){
        if( sub_sprite->node->sprite == sprite ){
            return sub_sprite->node->get_frame(min_x, min_y, max_x, max_y, facet);
        }
    }
    return 0;
}

char RGE_Active_Sprite_List::get_lowest_draw_level()
{
    for( char i = 20; RGE_Active_Sprite_Node *v1 = this->list; v1 = v1->next ){
        char v3 = v1->node->get_lowest_draw_level();
        if( (unsigned __int8)v3 < (unsigned __int8)i )
            i = v3;
    }
    return i;
}

bool RGE_Active_Sprite_List::check_for_shadows()
{
    if( RGE_Active_Sprite_Node *v1 = this->list ){
        while( 1 ){
            int result = v1->node->check_for_shadows();
            if( result )
                break;
            v1 = v1->next;
            if( v1 == nullptr )
                return result;
        }
        return true;
    }else{
        return false;
    }
}

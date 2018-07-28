
/**
 * @file    Engine\RGE\Command.cpp
 * @author  Yvan Burrie
 * @date    2018/03/09
 * @version 1.0
 */

void RGE_Command::RGE_Command(RGE_Game_World *gworld, TCommunications_Handler *com_handler)
{
    this->world = gworld;
    this->com_hand = com_handler;

    this->last_order = 0;
    this->last_order_size = 0;
}

void RGE_Command::~RGE_Command()
{
    this->world = 0;
    this->com_hand = 0;

    if( this->last_order )
        free(this->last_order);
}

void RGE_Command::reset_communications(TCommunications_Handler *com_hand_in)
{
    this->com_hand = com_hand_in;
}

RGE_Static_Object *RGE_Command::get_obj(RGE_Obj_Info info)
{
    if( info.id == -1 )
    {
        return NULL;
    }
    else
    {
        return this->world->object(info.id);
    }
}

void RGE_Command::do_commands()
{
    if( this->com_hand )
    {
        void *v3 = this->com_hand->get_command();
        if( v3 )
        {
            do
            {
                this->do_command(v3);

                if( v3 )
                    delete v3;

                v3 = this->com_hand->get_command();
            }
            while( v3 );
        }
    }
}

void RGE_Command::do_command_order(RGE_Command_Order *order)
{
    signed int v2; // ebx@1
    RGE_Obj_Info *v3; // esi@1
    RGE_Command *v4; // edi@1
    signed int v5; // ebp@3
    RGE_Static_Object *v6; // eax@4
    double v7; // st7@18
    RGE_Static_Object *v8; // eax@20
    RGE_Static_Object *v9; // esi@20
    RGE_Static_ObjectVtbl *v10; // ebp@21
    int *v11; // ebx@21
    int v12; // edi@21
    char v14; // c0@25
    double v15; // st7@27
    double v16; // st7@31
    RGE_Master_Static_Object *v17; // edx@34
    bool v18; // sf@39
    unsigned __int8 v19; // of@39
    RGE_Static_Object *v20; // eax@43
    RGE_Static_Object *v21; // esi@43
    RGE_Static_ObjectVtbl *v22; // ebp@44
    int *v23; // ebx@44
    int v24; // edi@44
    RGE_Static_Object *v25; // [sp-10h] [bp-48h]@36
    float v26; // [sp-Ch] [bp-44h]@36
    float v27; // [sp-8h] [bp-40h]@36
    float adjustedYLocation; // [sp+10h] [bp-28h]@2
    float adjustedYLocationa; // [sp+10h] [bp-28h]@25
    float adjustedXLocation; // [sp+14h] [bp-24h]@2
    float adjustedXLocationa; // [sp+14h] [bp-24h]@25
    int unit_num; // [sp+18h] [bp-20h]@1
    float totalX; // [sp+1Ch] [bp-1Ch]@2
    float totalXa; // [sp+1Ch] [bp-1Ch]@18
    float totalY; // [sp+20h] [bp-18h]@2
    float totalYa; // [sp+20h] [bp-18h]@18
    float maxY; // [sp+24h] [bp-14h]@2
    float maxYa; // [sp+24h] [bp-14h]@19
    float maxYb; // [sp+24h] [bp-14h]@42
    float i; // [sp+28h] [bp-10h]@2
    int ia; // [sp+28h] [bp-10h]@18
    int ib; // [sp+28h] [bp-10h]@41
    RGE_Command *v43; // [sp+30h] [bp-8h]@1
    RGE_Static_Object *target; // [sp+34h] [bp-4h]@1

    v2 = order->unit_num;
    v3 = (RGE_Obj_Info *)&order[1];
    v4 = this;
    v43 = this;
    unit_num = order->unit_num;
    target = RGE_Command::get_obj(this, order->target);
    if( v2 <= 1 )
        goto LABEL_52;
    adjustedYLocation = 10000.0;
    adjustedXLocation = 0.0;
    i = 10000.0;
    maxY = 0.0;
    totalX = 0.0;
    totalY = 0.0;
    if( v2 > 0 )
    {
        v5 = v2;
        do
        {
            v6 = RGE_Command::get_obj(v4, (RGE_Obj_Info)v3->id);
            if( v6 )
            {
                if( v6->world_x >= (double)adjustedYLocation )
                {
                    if( v6->world_x > (double)adjustedXLocation )
                        adjustedXLocation = v6->world_x;
                }
                else
                {
                    adjustedYLocation = v6->world_x;
                }
                if( v6->world_y >= (double)i )
                {
                    if( v6->world_y > (double)maxY )
                        maxY = v6->world_y;
                }
                else
                {
                    i = v6->world_y;
                }
                totalX = totalX + v6->world_x;
                totalY = totalY + v6->world_y;
            }
            ++v3;
            --v5;
        }
        while( v5 );
        v3 = (RGE_Obj_Info *)&order[1];
    }
    if( adjustedXLocation - adjustedYLocation > 8.0 || maxY - i > 8.0 )
    {
LABEL_52:
        ib = 0;
        if( v2 > 0 )
        {
            maxYb = *(float *)&v3;
            do
            {
                v20 = RGE_Command::get_obj(v4, (RGE_Obj_Info)v3->id);
                v21 = v20;
                if( v20 )
                {
                    RGE_Static_Object::removeAllFromPathingGroup(v20);
                    v22 = v21->vfptr;
                    v21->vfptr->setWaitingToMove(v21, 1);
                    v23 = (int *)&order[1].command;
                    v24 = 0;
                    do
                    {
                        if( v24 != ib )
                            RGE_Static_Object::addToPathingGroup(v21, *v23);
                        ++v24;
                        ++v23;
                    }
                    while( v24 < unit_num );
                    ((void (__thiscall *)(RGE_Static_Object *, RGE_Static_Object *, _DWORD, _DWORD, _DWORD))v22->do_command)(
                        v21,
                        target,
                        LODWORD(order->location_x),
                        LODWORD(order->location_y),
                        0);
                    v2 = unit_num;
                    v4 = v43;
                }
                v3 = (RGE_Obj_Info *)(LODWORD(maxYb) + 4);
                v19 = __OFSUB__(ib + 1, v2);
                v18 = ib++ + 1 - v2 < 0;
                LODWORD(maxYb) += 4;
            }
            while( v18 ^ v19 );
        }
    }
    else
    {
        v7 = (double)unit_num;
        ia = 0;
        totalXa = totalX / v7;
        totalYa = totalY / v7;
        if( v2 > 0 )
        {
            maxYa = *(float *)&v3;
            do
            {
                v8 = RGE_Command::get_obj(v4, (RGE_Obj_Info)v3->id);
                v9 = v8;
                if( v8 )
                {
                    RGE_Static_Object::removeAllFromPathingGroup(v8);
                    v10 = v9->vfptr;
                    v9->vfptr->setWaitingToMove(v9, 1);
                    v11 = (int *)&order[1].command;
                    v12 = 0;
                    do
                    {
                        if( v12 != ia )
                            RGE_Static_Object::addToPathingGroup(v9, *v11);
                        ++v12;
                        ++v11;
                    }
                    while( v12 < unit_num );
                    adjustedXLocationa = v9->world_x - totalXa + order->location_x;
                    adjustedYLocationa = v9->world_y - totalYa + order->location_y;
                    if( v14 )
                    {
                        adjustedXLocationa = 1.0;
                    }
                    else
                    {
                        v15 = (double)v9->owner->world->map->map_width;
                        if( adjustedXLocationa >= v15 )
                            adjustedXLocationa = v15 - 1.0;
                    }
                    if( adjustedYLocationa >= 0.0 )
                    {
                        v16 = (double)v9->owner->world->map->map_height;
                        if( adjustedYLocationa >= v16 )
                            adjustedYLocationa = v16 - 1.0;
                    }
                    else
                    {
                        adjustedYLocationa = 1.0;
                    }
                    if( target && ((v17 = target->master_obj, v17->radius_x > 0.0) || v17->radius_y > 0.0) )
                    {
                        v27 = adjustedYLocationa;
                        v26 = adjustedXLocationa;
                        v25 = target;
                    }
                    else
                    {
                        v27 = adjustedYLocationa;
                        v26 = adjustedXLocationa;
                        v25 = 0;
                    }
                    ((void (__thiscall *)(RGE_Static_Object *, RGE_Static_Object *, float, float, _DWORD))v10->do_command)(
                        v9,
                        v25,
                        COERCE_FLOAT(LODWORD(v26)),
                        COERCE_FLOAT(LODWORD(v27)),
                        0);
                    v2 = unit_num;
                    v4 = v43;
                }
                v3 = (RGE_Obj_Info *)(LODWORD(maxYa) + 4);
                v19 = __OFSUB__(ia + 1, v2);
                v18 = ia++ + 1 - v2 < 0;
                LODWORD(maxYa) += 4;
            }
            while( v18 ^ v19 );
        }
    }
}

//----- (00434290) --------------------------------------------------------
void RGE_Command::do_command_stop(RGE_Command_Stop *order)
{
    RGE_Command *v2; // ebx@1
    RGE_Obj_Info *v3; // edi@1
    int v4; // ebp@2
    RGE_Static_Object *v5; // eax@3
    RGE_Static_Object *v6; // esi@3

    v2 = this;
    v3 = (RGE_Obj_Info *)&order[1];
    if( order->unit_num > 0 )
    {
        v4 = order->unit_num;
        do
        {
            v5 = RGE_Command::get_obj(v2, (RGE_Obj_Info)v3->id);
            v6 = v5;
            if( v5 )
            {
                RGE_Static_Object::removeAllFromPathingGroup(v5);
                v6->vfptr->stop(v6);
            }
            ++v3;
            --v4;
        }
        while( v4 );
    }
}

//----- (004342E0) --------------------------------------------------------
void RGE_Command::do_command_pause(RGE_Command_Pause *order)
{
    RGE_Command *v2; // edi@1
    RGE_Obj_Info *v3; // esi@1
    int v4; // ebx@2
    RGE_Static_Object *v5; // eax@3

    v2 = this;
    v3 = (RGE_Obj_Info *)&order[1];
    if( order->unit_num > 0 )
    {
        v4 = order->unit_num;
        do
        {
            v5 = RGE_Command::get_obj(v2, (RGE_Obj_Info)v3->id);
            if( v5 )
                v5->vfptr->pause(v5);
            ++v3;
            --v4;
        }
        while( v4 );
    }
}

void RGE_Command::do_command_work(RGE_Command_Order *order, int a4)
{
    RGE_Command *v4; // edi@1
    int *v5; // ebx@1
    int v6; // ebp@1
    RGE_Static_Object *v7; // eax@3
    RGE_Static_Object *v8; // esi@3
    RGE_Static_ObjectVtbl *v9; // ebp@4
    RGE_Obj_Info *v10; // edi@4
    bool v11; // sf@9
    unsigned __int8 v12; // of@9
    int v13; // [sp+4h] [bp-28h]@2
    int index; // [sp+14h] [bp-18h]@1
    RGE_Obj_Info *v15; // [sp+18h] [bp-14h]@2
    int unit_num; // [sp+1Ch] [bp-10h]@1
    RGE_Static_Object *target; // [sp+20h] [bp-Ch]@1
    RGE_Command *v18; // [sp+24h] [bp-8h]@1

    v4 = this;
    v5 = (int *)&order[1].command;
    v6 = order->unit_num;
    v18 = this;
    unit_num = order->unit_num;
    target = RGE_Command::get_obj(this, order->target);
    index = 0;
    if( v6 > 0 )
    {
        v13 = a2;
        v15 = (RGE_Obj_Info *)&order[1];
        do
        {
            v7 = RGE_Command::get_obj(v4, (RGE_Obj_Info)v15->id);
            v8 = v7;
            if( v7 )
            {
                RGE_Static_Object::removeAllFromPathingGroup(v7);
                v9 = v8->vfptr;
                ((void (__thiscall *)(RGE_Static_Object *, signed int, int))v8->vfptr->setWaitingToMove)(v8, 1, v13);
                v10 = 0;
                do
                {
                    if( v10 != v15 )
                        RGE_Static_Object::addToPathingGroup(v8, *v5);
                    v10 = (RGE_Obj_Info *)((char *)v10 + 1);
                    ++v5;
                }
                while( (signed int)v10 < (signed int)target );
                v13 = 0;
                ((void (__thiscall *)(RGE_Static_Object *, RGE_Command *, _DWORD, _DWORD))v9->work)(
                    v8,
                    v18,
                    *(_DWORD *)(a4 + 12),
                    *(_DWORD *)(a4 + 16));
                v4 = v18;
                v6 = unit_num;
                v5 = (int *)&order[1].command;
            }
            v12 = __OFSUB__(index + 1, v6);
            v11 = index++ + 1 - v6 < 0;
            ++v15;
        }
        while( v11 ^ v12 );
    }
}

void RGE_Command::do_command_move(RGE_Command_Order *order)
{
    RGE_Command *v2; // ebp@1
    signed int v3; // edi@1
    int *v4; // ebx@1
    RGE_Obj_Info *v5; // esi@3
    RGE_Static_Object *v6; // eax@4
    double v7; // st7@18
    RGE_Static_Object *v8; // eax@21
    RGE_Static_Object *v9; // esi@21
    RGE_Static_ObjectVtbl *v10; // ebp@22
    int *v11; // ebx@22
    int v12; // edi@22
    char v14; // c0@26
    double v15; // st7@28
    double v16; // st7@32
    RGE_Master_Static_Object *v17; // edx@35
    float v18; // edi@37
    float v19; // ebx@37
    UnitAIModule *v20; // eax@40
    UnitAIModule *v21; // eax@40
    RGE_Master_Static_Object *v22; // edx@41
    UnitAIModule *v23; // eax@45
    bool v24; // sf@46
    unsigned __int8 v25; // of@46
    RGE_Static_Object *v26; // eax@51
    RGE_Static_Object *v27; // esi@51
    RGE_Static_ObjectVtbl *v28; // ebp@52
    int v29; // edi@52
    UnitAIModule *v30; // eax@57
    UnitAIModule *v31; // eax@57
    RGE_Master_Static_Object *v32; // edx@58
    UnitAIModule *v33; // eax@62
    int v34; // [sp-14h] [bp-4Ch]@43
    int v35; // [sp-14h] [bp-4Ch]@60
    RGE_Static_Object *v36; // [sp-10h] [bp-48h]@37
    int v37; // [sp-10h] [bp-48h]@43
    int v38; // [sp-10h] [bp-48h]@60
    float v39; // [sp-Ch] [bp-44h]@37
    float v40; // [sp-Ch] [bp-44h]@43
    float v41; // [sp-Ch] [bp-44h]@60
    float v42; // [sp-8h] [bp-40h]@37
    float v43; // [sp-8h] [bp-40h]@43
    float v44; // [sp-8h] [bp-40h]@60
    float adjustedYLocation; // [sp+10h] [bp-28h]@2
    float adjustedYLocationa; // [sp+10h] [bp-28h]@26
    float adjustedXLocation; // [sp+14h] [bp-24h]@2
    float adjustedXLocationa; // [sp+14h] [bp-24h]@26
    int unit_num; // [sp+18h] [bp-20h]@1
    float totalX; // [sp+1Ch] [bp-1Ch]@2
    float totalXa; // [sp+1Ch] [bp-1Ch]@18
    float totalY; // [sp+20h] [bp-18h]@2
    float totalYa; // [sp+20h] [bp-18h]@18
    RGE_Static_Object *target; // [sp+24h] [bp-14h]@1
    float maxY; // [sp+28h] [bp-10h]@2
    RGE_Obj_Info *maxYa; // [sp+28h] [bp-10h]@19
    RGE_Obj_Info *maxYb; // [sp+28h] [bp-10h]@49
    float i; // [sp+2Ch] [bp-Ch]@2
    int ia; // [sp+2Ch] [bp-Ch]@18
    int ib; // [sp+2Ch] [bp-Ch]@48
    RGE_Command *v61; // [sp+34h] [bp-4h]@1

    v2 = this;
    v3 = order->unit_num;
    v4 = (int *)&order[1].command;
    v61 = this;
    unit_num = order->unit_num;
    target = RGE_Command::get_obj(this, order->target);
    if( v3 <= 1 )
        goto LABEL_66;
    adjustedYLocation = 10000.0;
    adjustedXLocation = 0.0;
    i = 10000.0;
    maxY = 0.0;
    totalX = 0.0;
    totalY = 0.0;
    if( v3 > 0 )
    {
        v5 = (RGE_Obj_Info *)&order[1];
        do
        {
            v6 = RGE_Command::get_obj(v2, (RGE_Obj_Info)v5->id);
            if( v6 )
            {
                if( v6->world_x >= (double)adjustedYLocation )
                {
                    if( v6->world_x > (double)adjustedXLocation )
                        adjustedXLocation = v6->world_x;
                }
                else
                {
                    adjustedYLocation = v6->world_x;
                }
                if( v6->world_y >= (double)i )
                {
                    if( v6->world_y > (double)maxY )
                        maxY = v6->world_y;
                }
                else
                {
                    i = v6->world_y;
                }
                totalX = totalX + v6->world_x;
                totalY = totalY + v6->world_y;
            }
            ++v5;
            --v3;
        }
        while( v3 );
        v3 = unit_num;
    }
    if( adjustedXLocation - adjustedYLocation > 8.0 || maxY - i > 8.0 )
    {
LABEL_66:
        ib = 0;
        if( v3 > 0 )
        {
            maxYb = (RGE_Obj_Info *)&order[1];
            while( 1 )
            {
                v26 = RGE_Command::get_obj(v2, (RGE_Obj_Info)maxYb->id);
                v27 = v26;
                if( v26 )
                {
                    RGE_Static_Object::removeAllFromPathingGroup(v26);
                    v28 = v27->vfptr;
                    v27->vfptr->setWaitingToMove(v27, 1);
                    v29 = 0;
                    do
                    {
                        if( v29 != ib )
                            RGE_Static_Object::addToPathingGroup(v27, *v4);
                        ++v29;
                        ++v4;
                    }
                    while( v29 < unit_num );
                    ((void (__thiscall *)(RGE_Static_Object *, RGE_Static_Object *, _DWORD, _DWORD, _DWORD))v28->move_to)(
                        v27,
                        target,
                        LODWORD(order->location_x),
                        LODWORD(order->location_y),
                        0);
                    if( RGE_Static_Object::unitAI(v27) )
                    {
                        v30 = RGE_Static_Object::unitAI(v27);
                        UnitAIModule::setCurrentOrder(v30, 710);
                        v31 = RGE_Static_Object::unitAI(v27);
                        UnitAIModule::setCurrentAction(v31, 610);
                        if( target && ((v32 = target->master_obj, v32->radius_x > 0.0) || v32->radius_y > 0.0) )
                        {
                            v44 = order->location_y;
                            v41 = order->location_x;
                            v38 = v32->object_group;
                            v35 = target->id;
                        }
                        else
                        {
                            v44 = order->location_y;
                            v41 = order->location_x;
                            v38 = -1;
                            v35 = -1;
                        }
                        v33 = RGE_Static_Object::unitAI(v27);
                        UnitAIModule::setCurrentTarget(v33, v35, v38, v41, v44, 0.0);
                    }
                }
                v25 = __OFSUB__(ib + 1, unit_num);
                v24 = ib++ + 1 - unit_num < 0;
                ++maxYb;
                if( !(v24 ^ v25) )
                    break;
                v4 = (int *)&order[1].command;
                v2 = v61;
            }
        }
    }
    else
    {
        v7 = (double)unit_num;
        ia = 0;
        totalXa = totalX / v7;
        totalYa = totalY / v7;
        if( v3 > 0 )
        {
            maxYa = (RGE_Obj_Info *)&order[1];
            while( 1 )
            {
                v8 = RGE_Command::get_obj(v2, (RGE_Obj_Info)maxYa->id);
                v9 = v8;
                if( v8 )
                {
                    RGE_Static_Object::removeAllFromPathingGroup(v8);
                    v10 = v9->vfptr;
                    v9->vfptr->setWaitingToMove(v9, 1);
                    v11 = (int *)&order[1].command;
                    v12 = 0;
                    do
                    {
                        if( v12 != ia )
                            RGE_Static_Object::addToPathingGroup(v9, *v11);
                        ++v12;
                        ++v11;
                    }
                    while( v12 < unit_num );
                    adjustedXLocationa = v9->world_x - totalXa + order->location_x;
                    adjustedYLocationa = v9->world_y - totalYa + order->location_y;
                    if( v14 )
                    {
                        adjustedXLocationa = 1.0;
                    }
                    else
                    {
                        v15 = (double)v9->owner->world->map->map_width;
                        if( adjustedXLocationa >= v15 )
                            adjustedXLocationa = v15 - 1.0;
                    }
                    if( adjustedYLocationa >= 0.0 )
                    {
                        v16 = (double)v9->owner->world->map->map_height;
                        if( adjustedYLocationa >= v16 )
                            adjustedYLocationa = v16 - 1.0;
                    }
                    else
                    {
                        adjustedYLocationa = 1.0;
                    }
                    if( target && ((v17 = target->master_obj, v17->radius_x > 0.0) || v17->radius_y > 0.0) )
                    {
                        v18 = adjustedYLocationa;
                        v19 = adjustedXLocationa;
                        v42 = adjustedYLocationa;
                        v39 = adjustedXLocationa;
                        v36 = target;
                    }
                    else
                    {
                        v18 = adjustedYLocationa;
                        v19 = adjustedXLocationa;
                        v42 = adjustedYLocationa;
                        v39 = adjustedXLocationa;
                        v36 = 0;
                    }
                    ((void (__thiscall *)(RGE_Static_Object *, RGE_Static_Object *, float, float, _DWORD))v10->move_to)(
                        v9,
                        v36,
                        COERCE_FLOAT(LODWORD(v39)),
                        COERCE_FLOAT(LODWORD(v42)),
                        0);
                    if( RGE_Static_Object::unitAI(v9) )
                    {
                        v20 = RGE_Static_Object::unitAI(v9);
                        UnitAIModule::setCurrentOrder(v20, 710);
                        v21 = RGE_Static_Object::unitAI(v9);
                        UnitAIModule::setCurrentAction(v21, 610);
                        if( target && ((v22 = target->master_obj, v22->radius_x > 0.0) || v22->radius_y > 0.0) )
                        {
                            v43 = v18;
                            v40 = v19;
                            v37 = v22->object_group;
                            v34 = target->id;
                        }
                        else
                        {
                            v43 = v18;
                            v40 = v19;
                            v37 = -1;
                            v34 = -1;
                        }
                        v23 = RGE_Static_Object::unitAI(v9);
                        UnitAIModule::setCurrentTarget(v23, v34, v37, v40, v43, 0.0);
                    }
                }
                v25 = __OFSUB__(ia + 1, unit_num);
                v24 = ia++ + 1 - unit_num < 0;
                ++maxYa;
                if( !(v24 ^ v25) )
                    break;
                v2 = v61;
            }
        }
    }
}

//----- (004348B0) --------------------------------------------------------
void RGE_Command::do_command_create(RGE_Command_Create *order)
{
    RGE_Player *v2; // edx@1

    v2 = this->world->players[order->player_id];
    ((void (__stdcall *)(RGE_Player *, _DWORD, _DWORD, _DWORD))v2->master_objects[order->obj_catagory]->vfptr->make_new_obj)(
        v2,
        LODWORD(order->location_x),
        LODWORD(order->location_y),
        LODWORD(order->location_z));
}

//----- (004348F0) --------------------------------------------------------
void RGE_Command::do_command_add_attribute(RGE_Command_Add_Attribute *order)
{
    int v2; // eax@1

    HIWORD(v2) = HIWORD(order);
    LOWORD(v2) = order->attr_id;
    this->world->players[order->player_id]->add_attribute_num(
        v2,
        LODWORD(order->attr_amount),
        0);
}

//----- (00434920) --------------------------------------------------------
void RGE_Command::do_command_give_attribute(RGE_Command_Give_Attribute *order)
{
    RGE_Command *v2; // ebx@1
    RGE_Player **v3; // edx@1
    RGE_Player *v4; // ecx@1
    float v5; // ST10_4@2
    float v6; // edx@2
    int v7; // edi@2
    RGE_Player *v8; // ebx@2

    v2 = this;
    v3 = this->world->players;
    v4 = v3[order->player_id];
    if( v4->attributes[order->attr_id] >= (double)order->attr_amount )
    {
        LOWORD(v3) = order->attr_id;
        v5 = -order->attr_amount;
        ((void (__stdcall *)(RGE_Player **, _DWORD, _DWORD))v4->vfptr->add_attribute_num)(v3, LODWORD(v5), 0);
        v6 = order->attr_amount;
        LOWORD(v6) = order->attr_id;
        ((void (__stdcall *)(float, _DWORD, _DWORD))v2->world->players[order->to_player_id]->vfptr->add_attribute_num)(
            COERCE_FLOAT(LODWORD(v6)),
            LODWORD(order->attr_amount),
            0);
        rge_base_game->vfptr->notification(
            rge_base_game,
            7,
            order->player_id,
            order->to_player_id,
            order->attr_id,
            (signed __int64)order->attr_amount);
        v7 = order->to_player_id;
        v8 = v2->world->players[v7];
        ((void (__fastcall *)(RGE_Player *, _DWORD, _DWORD, int, signed int, _DWORD, _DWORD, _DWORD))v8->vfptr->notify)(
            v8,
            (unsigned __int64)(signed __int64)order->attr_amount >> 32,
            order->player_id,
            v7,
            522,
            order->attr_id,
            (signed __int64)order->attr_amount,
            0);
    }
}

//----- (00434A00) --------------------------------------------------------
void RGE_Command::do_command_formation(RGE_Command_Formation *fCommand)
{
    int v2; // ebx@1
    RGE_Obj_Info *v3; // edi@1
    int v4; // esi@2
    RGE_Static_Object *v5; // eax@3
    long double v6; // st6@4
    RGE_Static_Object *v7; // eax@15
    RGE_Static_Object *v8; // edi@15
    RGE_Static_ObjectVtbl *v9; // ebp@16
    int *v10; // ebx@16
    int v11; // esi@16
    double v12; // st7@24
    double v13; // st7@26
    float v14; // ST28_4@27
    float v15; // ST28_4@29
    bool v16; // sf@34
    unsigned __int8 v17; // of@34
    float tempY; // [sp+10h] [bp-2Ch]@9
    float tempX; // [sp+14h] [bp-28h]@9
    float adjustedYLocation; // [sp+18h] [bp-24h]@21
    float adjustedXLocation; // [sp+1Ch] [bp-20h]@21
    int tempCount; // [sp+20h] [bp-1Ch]@9
    RGE_Static_Object *referenceUnit; // [sp+24h] [bp-18h]@2
    int unitNum; // [sp+28h] [bp-14h]@1
    int i; // [sp+2Ch] [bp-10h]@13
    RGE_Command *v26; // [sp+30h] [bp-Ch]@1
    float distance; // [sp+38h] [bp-4h]@0
    float distancea; // [sp+38h] [bp-4h]@14

    v26 = this;
    v2 = fCommand->unitNum;
    v3 = (RGE_Obj_Info *)&fCommand[1];
    unitNum = fCommand->unitNum;
    if( v2 > 1 )
    {
        v4 = 0;
        referenceUnit = 0;
        if( v2 > 0 )
        {
            do
            {
                v5 = RGE_Command::get_obj(v26, (RGE_Obj_Info)v3->id);
                if( v5 )
                {
                    v6 = sqrt(v5->world_x * v5->world_x + v5->world_y * v5->world_y);
                    if( !v4 || v6 < distance )
                    {
                        distance = v6;
                        referenceUnit = v5;
                    }
                }
                ++v4;
                ++v3;
            }
            while( v4 < v2 );
            v3 = (RGE_Obj_Info *)&fCommand[1];
        }
        tempX = 1.0;
        tempY = 1.0;
        tempCount = 0;
        switch ( fCommand->formationID )
        {
            case 0:
                tempX = 1.0;
                tempY = 1.0;
                break;
            case 2:
            case 3:
                tempX = 2.0;
                tempY = 2.0;
                break;
            case 1:
            case 4:
            case 5:
                tempX = 1.5;
                tempY = 1.5;
                break;
            default:
                break;
        }
        i = 0;
        if( v2 > 0 )
        {
            distancea = *(float *)&v3;
            do
            {
                v7 = RGE_Command::get_obj(v26, (RGE_Obj_Info)v3->id);
                v8 = v7;
                if( v7 )
                {
                    RGE_Static_Object::removeAllFromPathingGroup(v7);
                    v9 = v8->vfptr;
                    v8->vfptr->setWaitingToMove(v8, 1);
                    v10 = (int *)&fCommand[1].command;
                    v11 = 0;
                    do
                    {
                        if( v11 != i )
                            RGE_Static_Object::addToPathingGroup(v8, *v10);
                        ++v11;
                        ++v10;
                    }
                    while( v11 < unitNum );
                    if( v8 != referenceUnit )
                    {
                        adjustedYLocation = referenceUnit->world_y;
                        adjustedXLocation = referenceUnit->world_x;
                        switch ( fCommand->formationID )
                        {
                            case 0:
                                adjustedXLocation = adjustedXLocation + tempX;
                                tempX = tempX - -1.0;
                                adjustedYLocation = adjustedYLocation + tempY;
                                tempY = tempY - -1.0;
                                goto LABEL_32;
                            case 1:
                                adjustedXLocation = adjustedXLocation + tempX;
                                tempX = tempX - -1.5;
                                adjustedYLocation = adjustedYLocation - tempY;
                                tempY = tempY - -1.5;
                                goto LABEL_32;
                            case 2:
                                v12 = tempX - -2.0;
                                adjustedXLocation = adjustedXLocation + tempX;
                                goto LABEL_31;
                            case 3:
                                adjustedYLocation = adjustedYLocation + tempY;
                                tempY = tempY - -2.0;
                                goto LABEL_32;
                            case 5:
                                adjustedXLocation = adjustedXLocation - tempX;
                                v13 = adjustedYLocation;
                                if( tempCount )
                                    goto LABEL_30;
                                tempCount = 1;
                                v14 = v13 - tempY;
                                ((void (__thiscall *)(RGE_Static_Object *, _DWORD, float, _DWORD, signed int))v9->move_to)(
                                    v8,
                                    0,
                                    COERCE_FLOAT(LODWORD(adjustedXLocation)),
                                    LODWORD(v14),
                                    1065353216);
                                break;
                            case 4:
                                adjustedXLocation = adjustedXLocation + tempX;
                                v13 = adjustedYLocation;
                                if( tempCount )
                                {
LABEL_30:
                                    adjustedYLocation = v13 + tempY;
                                    v12 = tempX - -1.5;
                                    tempY = tempY - -1.5;
                                    tempCount = 0;
LABEL_31:
                                    tempX = v12;
LABEL_32:
                                    ((void (__thiscall *)(RGE_Static_Object *, _DWORD, float, _DWORD, signed int))v9->move_to)(
                                        v8,
                                        0,
                                        COERCE_FLOAT(LODWORD(adjustedXLocation)),
                                        LODWORD(adjustedYLocation),
                                        1065353216);
                                }
                                else
                                {
                                    tempCount = 1;
                                    v15 = v13 - tempY;
                                    ((void (__thiscall *)(RGE_Static_Object *, _DWORD, float, _DWORD, signed int))v9->move_to)(
                                        v8,
                                        0,
                                        COERCE_FLOAT(LODWORD(adjustedXLocation)),
                                        LODWORD(v15),
                                        1065353216);
                                }
                                break;
                            default:
                                goto LABEL_32;
                        }
                    }
                    v2 = unitNum;
                }
                v3 = (RGE_Obj_Info *)(LODWORD(distancea) + 4);
                v17 = __OFSUB__(i + 1, v2);
                v16 = i++ + 1 - v2 < 0;
                LODWORD(distancea) += 4;
            }
            while( v16 ^ v17 );
        }
    }
}

//----- (00434D40) --------------------------------------------------------
void RGE_Command::do_command_ai_order(RGE_Command_AI_Order *aiOrder)
{
    RGE_Command *v2; // edi@1
    RGE_Static_Object *v3; // eax@1

    v2 = this;
    v3 = RGE_Game_World::object(this->world, aiOrder->recipient);
    if( v3 )
    {
        RGE_Static_Object::removeAllFromPathingGroup(v3);
        ((void (__stdcall *)(_DWORD, int, _DWORD, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v2->world->players[aiOrder->player_id]->vfptr->processAIOrder)(
            aiOrder->issuer,
            aiOrder->recipient,
            aiOrder->orderType,
            aiOrder->target,
            aiOrder->targetOwner,
            LODWORD(aiOrder->targetX),
            LODWORD(aiOrder->targetY),
            LODWORD(aiOrder->targetZ),
            LODWORD(aiOrder->range),
            aiOrder->immediate,
            aiOrder->inFront,
            aiOrder->orderPriority);
    }
}

//----- (00434DC0) --------------------------------------------------------
void RGE_Command::do_command_group_ai_order(RGE_Command_Group_AI_Order *aiOrder)
{
    RGE_Command_Group_AI_Order *v2; // esi@1
    RGE_Command *v3; // ebx@1
    RGE_Obj_Info *v4; // ebp@2
    RGE_Static_Object *v5; // edi@3
    float targetY; // [sp+28h] [bp-Ch]@8
    float targetX; // [sp+2Ch] [bp-8h]@5
    int v8; // [sp+30h] [bp-4h]@2
    RGE_Command_Group_AI_Order *aiOrdera; // [sp+38h] [bp+4h]@11

    v2 = aiOrder;
    v3 = this;
    if( aiOrder->recipient_count > 0 )
    {
        v4 = (RGE_Obj_Info *)&aiOrder[1];
        v8 = aiOrder->recipient_count;
        do
        {
            v5 = RGE_Command::get_obj(v3, (RGE_Obj_Info)v4->id);
            if( v5 )
            {
                if( LODWORD(v2->targetX) == -1082130432 )
                    targetX = v5->world_x;
                else
                    targetX = v2->targetX;
                if( LODWORD(v2->targetY) == -1082130432 )
                    targetY = v5->world_y;
                else
                    targetY = v2->targetY;
                if( LODWORD(v2->targetZ) == -1082130432 )
                    aiOrdera = (RGE_Command_Group_AI_Order *)LODWORD(v5->world_z);
                else
                    aiOrdera = (RGE_Command_Group_AI_Order *)LODWORD(v2->targetZ);
                RGE_Static_Object::removeAllFromPathingGroup(v5);
                ((void (__stdcall *)(_DWORD, int, _DWORD, int, _DWORD, float, float, RGE_Command_Group_AI_Order *, _DWORD, _DWORD, _DWORD, _DWORD))v3->world->players[v2->player_id]->vfptr->processAIOrder)(
                    v2->issuer,
                    v5->id,
                    v2->orderType,
                    v2->target,
                    v2->targetOwner,
                    COERCE_FLOAT(LODWORD(targetX)),
                    COERCE_FLOAT(LODWORD(targetY)),
                    aiOrdera,
                    LODWORD(v2->range),
                    v2->immediate,
                    v2->inFront,
                    v2->orderPriority);
            }
            ++v4;
            --v8;
        }
        while( v8 );
    }
}

//----- (00434EB0) --------------------------------------------------------
void RGE_Command::do_command_resign(RGE_Command_Resign *order)
{
    RGE_Command *v2; // esi@1
    int v3; // edi@2
    int v4; // ebp@2
    int v5; // esi@2
    RGE_Base_Game *v6; // ecx@2
    int v7; // eax@3
    RGE_Command *v8; // [sp+10h] [bp-4h]@1

    v2 = this;
    v8 = this;
    if( RGE_Base_Game::multiplayerGame(rge_base_game) )
    {
        v3 = 0;
        v4 = 0;
        v5 = 1;
        rge_base_game->resigned[order->comm_player_id] = 1;
        v6 = rge_base_game;
        do
        {
            v7 = RGE_Base_Game::playerID(v6, v5);
            v6 = rge_base_game;
            if( v7 == order->player_id )
            {
                ++v3;
                if( rge_base_game->resigned[v5] )
                    ++v4;
            }
            ++v5;
        }
        while( v5 < 9 );
        if( v3 == v4 )
            (*(void (__stdcall **)(_DWORD))&v8->world->players[order->player_id]->vfptr->gap4[4])(order->dropped);
    }
    else
    {
        (*(void (__stdcall **)(_DWORD))&v2->world->players[order->player_id]->vfptr->gap4[4])(order->dropped);
    }
}

//----- (00434F70) --------------------------------------------------------
void RGE_Command::do_command_add_waypoint(RGE_Command_Add_Waypoint *wOrder)
{
    RGE_Command *v2; // edi@1

    v2 = this;
    if( RGE_Game_World::object(this->world, wOrder->recipient) )
        ((void (__stdcall *)(int, XYZBYTEPoint *, _DWORD))v2->world->players[wOrder->player_id]->vfptr->processAddWaypointCommand)(
            wOrder->recipient,
            wOrder->waypoint,
            wOrder->numberWaypoints);
}

//----- (00434FB0) --------------------------------------------------------
void RGE_Command::do_command_group_waypoint(RGE_Command_Group_Waypoint *order)
{
    RGE_Command_Group_Waypoint *v2; // esi@1
    RGE_Command *v3; // ebp@1
    RGE_Obj_Info *v4; // edi@1
    RGE_Static_Object *v5; // eax@3
    char v6; // dl@4
    RGE_Player *v7; // ecx@4
    int v8; // eax@4
    int v9; // [sp+Ch] [bp-4h]@2

    v2 = order;
    v3 = this;
    v4 = (RGE_Obj_Info *)&order[1];
    if( order->unit_num > 0 )
    {
        v9 = order->unit_num;
        do
        {
            v5 = RGE_Command::get_obj(v3, (RGE_Obj_Info)v4->id);
            if( v5 )
            {
                v6 = v2->y;
                LOBYTE(order) = v2->x;
                v7 = v5->owner;
                v8 = v5->id;
                *(_WORD *)((char *)&order + 1) = (unsigned __int8)v6;
                ((void (__stdcall *)(int, RGE_Command_Group_Waypoint **, signed int))v7->vfptr->processAddWaypointCommand)(
                    v8,
                    &order,
                    1);
            }
            ++v4;
            --v9;
        }
        while( v9 );
    }
}

//----- (00435020) --------------------------------------------------------
void RGE_Command::do_command_create_group(RGE_Command_Create_Group *gCommand)
{
    RGE_Static_Object *v2; // eax@1

    v2 = RGE_Game_World::object(this->world, gCommand->groupCommander);
    if( v2 )
    {
        if( v2->owner->id == gCommand->player_id )
            RGE_Static_Object::commanderCreateGroup(
                v2,
                gCommand->unitsToGroup,
                gCommand->numberUnitsToGroup,
                gCommand->groupCommander,
                gCommand->groupRange);
    }
}

//----- (00435060) --------------------------------------------------------
void RGE_Command::do_command_add_to_group(RGE_Command_Add_To_Group *gCommand)
{
    RGE_Static_Object *v2; // eax@1

    v2 = RGE_Game_World::object(this->world, gCommand->groupCommander);
    if( v2 )
    {
        if( v2->owner->id == gCommand->player_id )
            RGE_Static_Object::commanderAddToGroup(v2, gCommand->newUnit, gCommand->groupRange);
    }
}

//----- (004350A0) --------------------------------------------------------
void RGE_Command::do_command_remove_from_group(RGE_Command_Remove_From_Group *gCommand)
{
    RGE_Static_Object *v2; // eax@1

    v2 = RGE_Game_World::object(this->world, gCommand->groupCommander);
    if( v2 )
    {
        if( v2->owner->id == gCommand->player_id )
            RGE_Static_Object::commanderRemoveFromGroup(v2, gCommand->unit);
    }
}

//----- (004350E0) --------------------------------------------------------
void RGE_Command::do_command_destroy_group(RGE_Command_Destroy_Group *gCommand)
{
    RGE_Static_Object *v2; // eax@1

    v2 = RGE_Game_World::object(this->world, gCommand->groupCommander);
    if( v2 )
    {
        if( v2->owner->id == gCommand->player_id )
            RGE_Static_Object::commanderDestroyGroup(v2);
    }
}

//----- (00435110) --------------------------------------------------------
char RGE_Command::duplicate_check_command_order(RGE_Command_Order *order)
{
    RGE_Command_Order *v2; // ebx@1
    char *v3; // esi@1
    int v4; // edi@1
    int v5; // ecx@5
    RGE_Command_Order *v6; // eax@6
    RGE_Command_Order *ordera; // [sp+18h] [bp+4h]@1

    v2 = order;
    v3 = this->last_order;
    v4 = order->unit_num;
    ordera = order + 1;
    if( v4 == (unsigned __int8)v3[8]
        && (unsigned short)(signed __int64)*((float *)v3 + 3) == (unsigned short)(signed __int64)v2->location_x
        && (unsigned short)(signed __int64)*((float *)v3 + 4) == (unsigned short)(signed __int64)v2->location_y
        && *((_DWORD *)v3 + 1) == v2->target.id )
    {
        v5 = 0;
        if( v4 <= 0 )
            return 1;
        v6 = ordera;
        while( *(_DWORD *)&v6->command == *(_DWORD *)(&v6->command + v3 + 20 - (char *)ordera) )
        {
            ++v5;
            v6 = (RGE_Command_Order *)((char *)v6 + 4);
            if( v5 >= v4 )
                return 1;
        }
    }
    return 0;
}

//----- (004351B0) --------------------------------------------------------
char RGE_Command::duplicate_check_command_stop(RGE_Command_Stop *order)
{
    char *v2; // ecx@1
    int v3; // edx@1
    int v4; // esi@1
    char result; // al@2
    int v6; // ecx@3
    char *v7; // eax@4

    v2 = this->last_order;
    v3 = order->unit_num;
    v4 = (int)(v2 + 2);
    if( v3 == (unsigned __int8)v2[1] )
    {
        v6 = 0;
        if( v3 <= 0 )
        {
            result = 1;
        }
        else
        {
            v7 = (char *)v4;
            while( *(_DWORD *)&v7[(_DWORD)order + -v4 + 2] == *(_DWORD *)v7 )
            {
                ++v6;
                v7 += 4;
                if( v6 >= v3 )
                    return 1;
            }
            result = 0;
        }
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (00435210) --------------------------------------------------------
char RGE_Command::close_check_for_duplicate_orders(char *order)
{
    char result; // al@3

    switch ( *order )
    {
        case 0:
        case 2:
        case 3:
            if( !RGE_Command::duplicate_check_command_order(this, (RGE_Command_Order *)order) )
                goto LABEL_6;
            result = 1;
            break;
        case 1:
            if( !RGE_Command::duplicate_check_command_stop(this, (RGE_Command_Stop *)order) )
                goto LABEL_6;
            result = 1;
            break;
        default:
LABEL_6:
            result = 0;
            break;
    }
    return result;
}

//----- (00435260) --------------------------------------------------------
char RGE_Command::check_for_duplicate_orders(char *order, int order_size)
{
    RGE_Command *v3; // esi@1
    char *v4; // eax@1
    char result; // al@5

    v3 = this;
    v4 = this->last_order;
    if( v4
        && this->last_order_size == order_size
        && *v4 == *order
        && (signed int)(debug_timeGetTime() - this->last_order_time) < 500 )
    {
        result = RGE_Command::close_check_for_duplicate_orders(v3, order);
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (004352C0) --------------------------------------------------------
void RGE_Command::submit(void *order, int order_size)
{
    RGE_Command *v3; // esi@1

    v3 = this;
    if( !RGE_Command::check_for_duplicate_orders(this, (char *)order, order_size) )
        TCommunications_Handler::new_command(v3->com_hand, order, order_size);
    if( v3->last_order )
        free(v3->last_order);
    v3->last_order = (char *)order;
    v3->last_order_size = order_size;
    v3->last_order_time = debug_timeGetTime();
}

//----- (00435320) --------------------------------------------------------
void RGE_Command::command_order(RGE_Static_Object **unit, short unit_count, RGE_Static_Object *target, float location_x, float location_y)
{
    short v6; // bx@1
    int v7; // ebp@1
    RGE_Static_Object **v8; // edi@1
    size_t v9; // eax@1
    void *v10; // eax@3
    _DWORD *v11; // esi@3
    bool v12; // zf@3
    char *v13; // eax@3
    int v14; // edi@5
    char *v15; // edx@5
    int v16; // ecx@6
    char *v17; // edx@15
    RGE_Static_Object *v18; // eax@17
    char *v19; // ecx@18
    signed int v20; // eax@21
    RGE_Command *v21; // [sp+10h] [bp-4h]@1
    int unit_counta; // [sp+1Ch] [bp+8h]@1

    v6 = unit_count;
    v7 = unit_count;
    v8 = unit;
    v9 = 4 * unit_count + 20;
    v21 = this;
    unit_counta = 4 * unit_count + 20;
    if( unit )
    {
        if( v6 >= 1 )
        {
            v10 = calloc(1u, v9);
            v11 = v10;
            v12 = v10 == 0;
            v13 = (char *)v10 + 20;
            if( !v12 )
            {
                if( v7 > 0 )
                {
                    v14 = v7;
                    v15 = (char *)((char *)unit - v13);
                    do
                    {
                        v16 = *(_DWORD *)&v13[(_DWORD)v15];
                        if( v16 )
                            *(_DWORD *)v13 = *(_DWORD *)(v16 + 4);
                        else
                            *(_DWORD *)v13 = -1;
                        v13 += 4;
                        --v14;
                    }
                    while( v14 );
                    v8 = unit;
                }
                if( target )
                    v11[1] = target->id;
                else
                    v11[1] = -1;
                *(_BYTE *)v11 = 0;
                *((_BYTE *)v11 + 8) = v6;
                *((float *)v11 + 3) = location_x;
                *((float *)v11 + 4) = location_y;
                if( target )
                    v17 = target->master_obj->name;
                else
                    v17 = asc_583B74;
                v18 = *v8;
                if( *v8 )
                    v19 = v18->master_obj->name;
                else
                    v19 = asc_583B74;
                if( v18 )
                    v20 = v18->owner->id;
                else
                    v20 = -1;
                TDebuggingLog::Log(L, aSendCmdOrderCn, v7, v20, v19, v17);
                RGE_Command::submit(v21, v11, unit_counta);
            }
        }
    }
}

//----- (00435420) --------------------------------------------------------
void RGE_Command::command_stop(RGE_Static_Object **unit, short unit_count)
{
    int v3; // esi@1
    void *v4; // eax@3
    _BYTE *v5; // edi@3
    bool v6; // zf@3
    char *v7; // eax@3
    int v8; // esi@5
    char *v9; // edx@5
    int v10; // ecx@6
    RGE_Static_Object *v11; // eax@11
    char *v12; // ecx@12
    signed int v13; // eax@15
    RGE_Command *v14; // [sp+14h] [bp-4h]@1

    v3 = 4 * unit_count + 2;
    v14 = this;
    if( unit )
    {
        if( unit_count >= 1 )
        {
            v4 = calloc(1u, 4 * unit_count + 2);
            v5 = v4;
            v6 = v4 == 0;
            v7 = (char *)v4 + 2;
            if( !v6 )
            {
                if( unit_count > 0 )
                {
                    v8 = unit_count;
                    v9 = (char *)((char *)unit - v7);
                    do
                    {
                        v10 = *(_DWORD *)&v7[(_DWORD)v9];
                        if( v10 )
                            *(_DWORD *)v7 = *(_DWORD *)(v10 + 4);
                        else
                            *(_DWORD *)v7 = -1;
                        v7 += 4;
                        --v8;
                    }
                    while( v8 );
                    v3 = 4 * unit_count + 2;
                }
                *v5 = 1;
                v5[1] = unit_count;
                v11 = *unit;
                if( *unit )
                    v12 = v11->master_obj->name;
                else
                    v12 = asc_583B74;
                if( v11 )
                    v13 = v11->owner->id;
                else
                    v13 = -1;
                TDebuggingLog::Log(L, aSendCmdStopCnt, unit_count, v13, v12);
                RGE_Command::submit(v14, v5, v3);
            }
        }
    }
}

//----- (004354F0) --------------------------------------------------------
void RGE_Command::command_stop(int playerID, int *unitID, int numUnits)
{
    int v4; // ebp@3
    void *v5; // eax@3
    _BYTE *v6; // esi@3
    bool v7; // zf@3
    char *v8; // eax@3
    int v9; // edx@5
    char *v10; // ecx@5
    RGE_Static_Object *v11; // eax@8
    char *v12; // eax@9
    RGE_Command *v13; // [sp+10h] [bp-4h]@1

    v13 = this;
    if( unitID )
    {
        if( numUnits >= 1 )
        {
            v4 = 4 * numUnits + 2;
            v5 = calloc(1u, v4);
            v6 = v5;
            v7 = v5 == 0;
            v8 = (char *)v5 + 2;
            if( !v7 )
            {
                if( numUnits > 0 )
                {
                    v9 = numUnits;
                    v10 = (char *)((char *)unitID - v8);
                    do
                    {
                        *(_DWORD *)v8 = *(_DWORD *)&v8[(_DWORD)v10];
                        v8 += 4;
                        --v9;
                    }
                    while( v9 );
                    v4 = 4 * numUnits + 2;
                }
                *v6 = 1;
                v6[1] = numUnits;
                v11 = RGE_Game_World::object(v13->world, *unitID);
                if( v11 )
                    v12 = v11->master_obj->name;
                else
                    v12 = asc_583B74;
                TDebuggingLog::Log(L, aSendCmdStop2Cn, numUnits, playerID, v12);
                RGE_Command::submit(v13, v6, v4);
            }
        }
    }
}

//----- (004355A0) --------------------------------------------------------
void RGE_Command::command_pause(int playerID, int *unitID, int numUnits)
{
    void *v4; // eax@3
    _BYTE *v5; // esi@3
    bool v6; // zf@3
    char *v7; // eax@3
    int v8; // edx@5
    char *v9; // ecx@5
    RGE_Command *v10; // [sp+10h] [bp-4h]@1

    v10 = this;
    if( unitID )
    {
        if( numUnits >= 1 )
        {
            v4 = calloc(1u, 4 * numUnits + 2);
            v5 = v4;
            v6 = v4 == 0;
            v7 = (char *)v4 + 2;
            if( !v6 )
            {
                if( numUnits > 0 )
                {
                    v8 = numUnits;
                    v9 = (char *)((char *)unitID - v7);
                    do
                    {
                        *(_DWORD *)v7 = *(_DWORD *)&v7[(_DWORD)v9];
                        v7 += 4;
                        --v8;
                    }
                    while( v8 );
                }
                *v5 = 13;
                v5[1] = numUnits;
                TDebuggingLog::Log(L, aSendCmdPause);
                RGE_Command::submit(v10, v5, 4 * numUnits + 2);
            }
        }
    }
}

//----- (00435620) --------------------------------------------------------
void RGE_Command::command_work(RGE_Static_Object **unit, short unit_count, RGE_Static_Object *target, float location_x, float location_y)
{
    short v6; // bx@1
    int v7; // ebp@1
    RGE_Static_Object **v8; // edi@1
    size_t v9; // eax@1
    void *v10; // eax@3
    _DWORD *v11; // esi@3
    bool v12; // zf@3
    char *v13; // eax@3
    int v14; // edi@5
    char *v15; // edx@5
    int v16; // ecx@6
    char *v17; // edx@15
    RGE_Static_Object *v18; // eax@17
    char *v19; // ecx@18
    signed int v20; // eax@21
    RGE_Command *v21; // [sp+10h] [bp-4h]@1
    int unit_counta; // [sp+1Ch] [bp+8h]@1

    v6 = unit_count;
    v7 = unit_count;
    v8 = unit;
    v9 = 4 * unit_count + 20;
    v21 = this;
    unit_counta = 4 * unit_count + 20;
    if( unit )
    {
        if( v6 >= 1 )
        {
            v10 = calloc(1u, v9);
            v11 = v10;
            v12 = v10 == 0;
            v13 = (char *)v10 + 20;
            if( !v12 )
            {
                if( v7 > 0 )
                {
                    v14 = v7;
                    v15 = (char *)((char *)unit - v13);
                    do
                    {
                        v16 = *(_DWORD *)&v13[(_DWORD)v15];
                        if( v16 )
                            *(_DWORD *)v13 = *(_DWORD *)(v16 + 4);
                        else
                            *(_DWORD *)v13 = -1;
                        v13 += 4;
                        --v14;
                    }
                    while( v14 );
                    v8 = unit;
                }
                if( target )
                    v11[1] = target->id;
                else
                    v11[1] = -1;
                *(_BYTE *)v11 = 2;
                *((_BYTE *)v11 + 8) = v6;
                *((float *)v11 + 3) = location_x;
                *((float *)v11 + 4) = location_y;
                if( target )
                    v17 = target->master_obj->name;
                else
                    v17 = asc_583B74;
                v18 = *v8;
                if( *v8 )
                    v19 = v18->master_obj->name;
                else
                    v19 = asc_583B74;
                if( v18 )
                    v20 = v18->owner->id;
                else
                    v20 = -1;
                TDebuggingLog::Log(L, aSendCmdWorkCnt, v7, v20, v19, v17);
                RGE_Command::submit(v21, v11, unit_counta);
            }
        }
    }
}

//----- (00435720) --------------------------------------------------------
void RGE_Command::command_work(int playerID, int *unitID, int numUnits, int targetID, int targetPlayerID, float xLoc, float yLoc)
{
    void *v8; // eax@3
    float *v9; // esi@3
    bool v10; // zf@3
    char *v11; // eax@3
    int v12; // edx@5
    char *v13; // ecx@5
    RGE_Static_Object *v14; // ebp@7
    RGE_Static_Object *v15; // eax@7
    char *v16; // ecx@8
    char *v17; // eax@11
    RGE_Command *v18; // [sp+Ch] [bp-4h]@1

    v18 = this;
    if( unitID )
    {
        if( numUnits >= 1 )
        {
            v8 = calloc(1u, 4 * numUnits + 20);
            v9 = (float *)v8;
            v10 = v8 == 0;
            v11 = (char *)v8 + 20;
            if( !v10 )
            {
                if( numUnits > 0 )
                {
                    v12 = numUnits;
                    v13 = (char *)((char *)unitID - v11);
                    do
                    {
                        *(_DWORD *)v11 = *(_DWORD *)&v11[(_DWORD)v13];
                        v11 += 4;
                        --v12;
                    }
                    while( v12 );
                }
                v9[3] = xLoc;
                *(_BYTE *)v9 = 2;
                *((_BYTE *)v9 + 8) = numUnits;
                *((_DWORD *)v9 + 1) = targetID;
                v9[4] = yLoc;
                v14 = RGE_Game_World::object(v18->world, *unitID);
                v15 = RGE_Game_World::object(v18->world, targetID);
                if( v15 )
                    v16 = v15->master_obj->name;
                else
                    v16 = asc_583B74;
                if( v14 )
                    v17 = v14->master_obj->name;
                else
                    v17 = asc_583B74;
                TDebuggingLog::Log(L, aSendCmdWork2Cn, numUnits, playerID, v17, v16);
                RGE_Command::submit(v18, v9, 4 * numUnits + 20);
            }
        }
    }
}

//----- (00435810) --------------------------------------------------------
void RGE_Command::command_move(RGE_Static_Object **unit, short unit_count, RGE_Static_Object *target, float location_x, float location_y)
{
    short v6; // bx@2
    int v7; // edi@3
    void *v8; // eax@3
    _DWORD *v9; // esi@3
    bool v10; // zf@3
    char *v11; // eax@3
    int v12; // edi@5
    char *v13; // edx@5
    int v14; // ecx@6
    RGE_Static_Object *v15; // eax@14
    char *v16; // ecx@15
    signed int v17; // eax@18
    RGE_Command *v18; // [sp+10h] [bp-4h]@1
    size_t unit_counta; // [sp+1Ch] [bp+8h]@3

    v18 = this;
    if( unit )
    {
        v6 = unit_count;
        if( unit_count >= 1 )
        {
            v7 = 4 * unit_count + 20;
            unit_counta = 4 * unit_count + 20;
            v8 = calloc(1u, unit_counta);
            v9 = v8;
            v10 = v8 == 0;
            v11 = (char *)v8 + 20;
            if( !v10 )
            {
                if( v6 > 0 )
                {
                    v12 = v6;
                    v13 = (char *)((char *)unit - v11);
                    do
                    {
                        v14 = *(_DWORD *)&v11[(_DWORD)v13];
                        if( v14 )
                            *(_DWORD *)v11 = *(_DWORD *)(v14 + 4);
                        else
                            *(_DWORD *)v11 = -1;
                        v11 += 4;
                        --v12;
                    }
                    while( v12 );
                    v7 = unit_counta;
                }
                if( target )
                    v9[1] = target->id;
                else
                    v9[1] = -1;
                *(_BYTE *)v9 = 3;
                *((_BYTE *)v9 + 8) = v6;
                *((float *)v9 + 3) = location_x;
                *((float *)v9 + 4) = location_y;
                v15 = *unit;
                if( *unit )
                    v16 = v15->master_obj->name;
                else
                    v16 = asc_583B74;
                if( v15 )
                    v17 = v15->owner->id;
                else
                    v17 = -1;
                TDebuggingLog::Log(L, aSendCmdMoveCnt, v6, v17, v16);
                RGE_Command::submit(v18, v9, v7);
            }
        }
    }
}

//----- (00435900) --------------------------------------------------------
void RGE_Command::command_move(int playerID, int *unitID, int numUnits, int targetID, int targetPlayerID, float xLoc, float yLoc)
{
    int v8; // ebp@3
    void *v9; // eax@3
    _BYTE *v10; // esi@3
    bool v11; // zf@3
    char *v12; // eax@3
    int v13; // edx@5
    char *v14; // ecx@5
    RGE_Static_Object *v15; // eax@8
    char *v16; // eax@9
    RGE_Command *v17; // [sp+10h] [bp-4h]@1

    v17 = this;
    if( unitID )
    {
        if( numUnits >= 1 )
        {
            v8 = 4 * numUnits + 20;
            v9 = calloc(1u, v8);
            v10 = v9;
            v11 = v9 == 0;
            v12 = (char *)v9 + 20;
            if( !v11 )
            {
                if( numUnits > 0 )
                {
                    v13 = numUnits;
                    v14 = (char *)((char *)unitID - v12);
                    do
                    {
                        *(_DWORD *)v12 = *(_DWORD *)&v12[(_DWORD)v14];
                        v12 += 4;
                        --v13;
                    }
                    while( v13 );
                    v8 = 4 * numUnits + 20;
                }
                *v10 = 3;
                v10[8] = numUnits;
                *((_DWORD *)v10 + 1) = targetID;
                *((float *)v10 + 3) = xLoc;
                *((float *)v10 + 4) = yLoc;
                v15 = RGE_Game_World::object(v17->world, *unitID);
                if( v15 )
                    v16 = v15->master_obj->name;
                else
                    v16 = asc_583B74;
                TDebuggingLog::Log(L, aSendCmdMove2Cn, numUnits, playerID, v16);
                RGE_Command::submit(v17, v10, v8);
            }
        }
    }
}

//----- (004359C0) --------------------------------------------------------
void RGE_Command::command_create(short obj_catagory, short player_id, float location_x, float location_y, float location_z)
{
    RGE_Command *v6; // edi@1
    float *v7; // esi@1

    v6 = this;
    v7 = (float *)calloc(1u, 0x14u);
    v7[2] = location_x;
    v7[3] = location_y;
    *((_BYTE *)v7 + 4) = player_id;
    v7[4] = location_z;
    *(_BYTE *)v7 = 4;
    *((_WORD *)v7 + 1) = obj_catagory;
    TDebuggingLog::Log(L, aSendCmdCreateC, obj_catagory, player_id);
    RGE_Command::submit(v6, v7, 20);
}

//----- (00435A30) --------------------------------------------------------
void RGE_Command::command_add_attribute(int player_id, int attr_id, float attr_amount)
{
    RGE_Command *v4; // edi@1
    float *v5; // esi@1

    v4 = this;
    v5 = (float *)calloc(1u, 8u);
    *(_BYTE *)v5 = 5;
    *((_BYTE *)v5 + 1) = player_id;
    *((_BYTE *)v5 + 2) = attr_id;
    v5[1] = attr_amount;
    TDebuggingLog::Log(L, aSendCmdAddAttr, player_id, attr_id);
    RGE_Command::submit(v4, v5, 8);
}

//----- (00435A80) --------------------------------------------------------
void RGE_Command::command_give_attribute(int player_id, int to_player_id, int attr_id, float attr_amount)
{
    RGE_Command *v5; // edi@1
    float *v6; // esi@1

    v5 = this;
    v6 = (float *)calloc(1u, 8u);
    *(_BYTE *)v6 = 7;
    *((_BYTE *)v6 + 1) = player_id;
    *((_BYTE *)v6 + 2) = to_player_id;
    *((_BYTE *)v6 + 3) = attr_id;
    v6[1] = attr_amount;
    TDebuggingLog::Log(L, aSendCmdGivAttr, player_id, to_player_id, attr_id);
    RGE_Command::submit(v5, v6, 8);
}

//----- (00435AE0) --------------------------------------------------------
void RGE_Command::command_formation(RGE_Static_Object **unit, int unitCount, int formationID)
{
    int v4; // ebx@1
    int v5; // edi@1
    void *v6; // eax@3
    _DWORD *v7; // esi@3
    bool v8; // zf@3
    char *v9; // eax@3
    int v10; // edi@5
    char *v11; // edx@5
    int v12; // ecx@6
    RGE_Static_Object *v13; // eax@11
    char *v14; // ecx@12
    signed int v15; // eax@15
    RGE_Command *v16; // [sp+10h] [bp-4h]@1
    int unitCounta; // [sp+1Ch] [bp+8h]@1

    v4 = unitCount;
    v5 = 4 * unitCount + 12;
    v16 = this;
    unitCounta = 4 * unitCount + 12;
    if( unit )
    {
        if( v4 >= 1 )
        {
            v6 = calloc(1u, v5);
            v7 = v6;
            v8 = v6 == 0;
            v9 = (char *)v6 + 12;
            if( !v8 )
            {
                if( v4 > 0 )
                {
                    v10 = v4;
                    v11 = (char *)((char *)unit - v9);
                    do
                    {
                        v12 = *(_DWORD *)&v9[(_DWORD)v11];
                        if( v12 )
                            *(_DWORD *)v9 = *(_DWORD *)(v12 + 4);
                        else
                            *(_DWORD *)v9 = -1;
                        v9 += 4;
                        --v10;
                    }
                    while( v10 );
                    v5 = unitCounta;
                }
                *(_BYTE *)v7 = 6;
                v7[1] = (unsigned __int8)v4;
                v7[2] = formationID;
                v13 = *unit;
                if( *unit )
                    v14 = v13->master_obj->name;
                else
                    v14 = asc_583B74;
                if( v13 )
                    v15 = v13->owner->id;
                else
                    v15 = -1;
                TDebuggingLog::Log(L, aSendCmdFormati, v4, v15, v14);
                RGE_Command::submit(v16, v7, v5);
            }
        }
    }
}

//----- (00435BB0) --------------------------------------------------------
void RGE_Command::command_create_group(int playerID, int groupCommander, int *units, int unitCount, float range)
{
    RGE_Command *v6; // edi@1
    void *v7; // esi@1
    int *v8; // eax@2
    int *v9; // ecx@2
    int v10; // edx@2
    int v11; // ebp@3
    RGE_Static_Object *v12; // eax@4
    char *v13; // eax@5

    v6 = this;
    v7 = calloc(1u, 0x74u);
    *(_BYTE *)v7 = 8;
    *((_BYTE *)v7 + 1) = playerID;
    *((_DWORD *)v7 + 1) = groupCommander;
    if( unitCount > 0 )
    {
        v8 = units;
        v9 = (int *)((char *)v7 + 12);
        v10 = unitCount;
        do
        {
            v11 = *v8;
            ++v8;
            *v9 = v11;
            ++v9;
            --v10;
        }
        while( v10 );
    }
    *((_BYTE *)v7 + 112) = unitCount;
    *((float *)v7 + 2) = range;
    v12 = RGE_Game_World::object(v6->world, *units);
    if( v12 )
        v13 = v12->master_obj->name;
    else
        v13 = asc_583B74;
    TDebuggingLog::Log(L, aSendCmdCrtGrou, unitCount, playerID, v13);
    RGE_Command::submit(v6, v7, 116);
}

//----- (00435C50) --------------------------------------------------------
void RGE_Command::command_add_to_group(int playerID, int groupCommander, int newUnit, float range)
{
    RGE_Command *v5; // edi@1
    void *v6; // eax@1
    void *v7; // esi@1
    RGE_Static_Object *v8; // eax@1
    char *v9; // eax@2

    v5 = this;
    v6 = calloc(1u, 0x10u);
    v7 = v6;
    *((_DWORD *)v6 + 1) = groupCommander;
    *(_BYTE *)v6 = 14;
    *((_BYTE *)v6 + 1) = playerID;
    *((_DWORD *)v6 + 3) = newUnit;
    *((float *)v6 + 2) = range;
    v8 = RGE_Game_World::object(v5->world, newUnit);
    if( v8 )
        v9 = v8->master_obj->name;
    else
        v9 = asc_583B74;
    TDebuggingLog::Log(L, aSendCmdAddGrou, playerID, v9);
    RGE_Command::submit(v5, v7, 16);
}

//----- (00435CD0) --------------------------------------------------------
void RGE_Command::command_remove_from_group(int playerID, int commander, int unit)
{
    RGE_Command *v4; // edi@1
    void *v5; // eax@1
    void *v6; // esi@1
    RGE_Static_Object *v7; // eax@1
    char *v8; // eax@2

    v4 = this;
    v5 = calloc(1u, 0xCu);
    v6 = v5;
    *((_DWORD *)v5 + 1) = commander;
    *(_BYTE *)v5 = 15;
    *((_BYTE *)v5 + 1) = playerID;
    *((_DWORD *)v5 + 2) = unit;
    v7 = RGE_Game_World::object(v4->world, unit);
    if( v7 )
        v8 = v7->master_obj->name;
    else
        v8 = asc_583B74;
    TDebuggingLog::Log(L, aSendCmdRemGrou, playerID, v8);
    RGE_Command::submit(v4, v6, 12);
}

//----- (00435D40) --------------------------------------------------------
void RGE_Command::command_destroy_group(int playerID, int groupCommander)
{
    RGE_Command *v3; // edi@1
    _BYTE *v4; // esi@1

    v3 = this;
    v4 = calloc(1u, 8u);
    *v4 = 9;
    v4[1] = playerID;
    *((_DWORD *)v4 + 1) = groupCommander;
    TDebuggingLog::Log(L, aSendCmdDesGrou, playerID);
    RGE_Command::submit(v3, v4, 8);
}

//----- (00435D90) --------------------------------------------------------
void RGE_Command::command_ai_order(int playerID, int issuer, int recipient, int orderType, int target, int targetOwner, float targetX, float targetY, float targetZ, float range, char immediate, char inFront, char priority)
{
    RGE_Command *v14; // edi@1
    void *v15; // eax@1
    void *v16; // esi@1
    RGE_Static_Object *v17; // eax@1
    RGE_Static_Object *immediatea; // [sp+3Ch] [bp+2Ch]@1
    char *immediateb; // [sp+3Ch] [bp+2Ch]@5
    char *prioritya; // [sp+44h] [bp+34h]@2

    v14 = this;
    v15 = calloc(1u, 0x28u);
    v16 = v15;
    *((_BYTE *)v15 + 1) = playerID;
    *((_BYTE *)v15 + 2) = issuer;
    *((_WORD *)v15 + 4) = orderType;
    *((_BYTE *)v15 + 10) = priority;
    *((_BYTE *)v15 + 16) = targetOwner;
    *((float *)v15 + 5) = targetX;
    *((float *)v15 + 6) = targetY;
    *((float *)v15 + 7) = targetZ;
    *(_BYTE *)v15 = 10;
    *((_DWORD *)v15 + 1) = recipient;
    *((_DWORD *)v15 + 3) = target;
    *((float *)v15 + 8) = range;
    *((_BYTE *)v15 + 36) = immediate;
    *((_BYTE *)v15 + 37) = inFront;
    immediatea = RGE_Game_World::object(v14->world, recipient);
    v17 = RGE_Game_World::object(v14->world, target);
    if( v17 )
        prioritya = v17->master_obj->name;
    else
        prioritya = asc_583B74;
    if( immediatea )
        immediateb = immediatea->master_obj->name;
    else
        immediateb = asc_583B74;
    TDebuggingLog::Log(
        L,
        aSendCmdAiOrdPl,
        playerID,
        orderType,
        issuer,
        recipient,
        immediateb,
        target,
        prioritya,
        (unsigned int)(signed __int64)targetX,
        (unsigned int)(signed __int64)targetY);
    RGE_Command::submit(v14, v16, 40);
}

//----- (00435EA0) --------------------------------------------------------
void RGE_Command::command_group_ai_order(int playerID, int issuer, RGE_Static_Object **recipient, short recipient_count, int orderType, int target, int targetOwner, float targetX, float targetY, float targetZ, float range, char immediate, char inFront, char priority)
{
    void *v15; // eax@3
    float *v16; // esi@3
    bool v17; // zf@3
    char *v18; // eax@3
    int v19; // edi@5
    char *v20; // edx@5
    int v21; // ecx@6
    RGE_Static_Object *v22; // eax@10
    char *v23; // ecx@11
    char *v24; // eax@14
    RGE_Command *v25; // [sp+Ch] [bp-8h]@1

    v25 = this;
    if( recipient )
    {
        if( recipient_count >= 1 )
        {
            v15 = calloc(1u, 4 * recipient_count + 36);
            v16 = (float *)v15;
            v17 = v15 == 0;
            v18 = (char *)v15 + 36;
            if( !v17 )
            {
                if( recipient_count > 0 )
                {
                    v19 = recipient_count;
                    v20 = (char *)((char *)recipient - v18);
                    do
                    {
                        v21 = *(_DWORD *)&v18[(_DWORD)v20];
                        if( v21 )
                            *(_DWORD *)v18 = *(_DWORD *)(v21 + 4);
                        else
                            *(_DWORD *)v18 = -1;
                        v18 += 4;
                        --v19;
                    }
                    while( v19 );
                }
                *((_BYTE *)v16 + 2) = issuer;
                *((_BYTE *)v16 + 6) = priority;
                *((_BYTE *)v16 + 12) = targetOwner;
                *((_BYTE *)v16 + 3) = recipient_count;
                v16[4] = targetX;
                v16[5] = targetY;
                *((_DWORD *)v16 + 2) = target;
                v16[6] = targetZ;
                v16[7] = range;
                *(_BYTE *)v16 = 17;
                *((_BYTE *)v16 + 1) = playerID;
                *((_WORD *)v16 + 2) = orderType;
                *((_BYTE *)v16 + 32) = immediate;
                *((_BYTE *)v16 + 33) = inFront;
                v22 = RGE_Game_World::object(v25->world, target);
                if( v22 )
                    v23 = v22->master_obj->name;
                else
                    v23 = asc_583B74;
                if( *recipient )
                    v24 = (*recipient)->master_obj->name;
                else
                    v24 = asc_583B74;
                TDebuggingLog::Log(L, aSendCmdGrpAiOr, playerID, orderType, issuer, recipient_count, v24, v23);
                RGE_Command::submit(v25, v16, 4 * recipient_count + 36);
            }
        }
    }
}

//----- (00435FE0) --------------------------------------------------------
void RGE_Command::command_resign(int player_id, int comm_player_id, int dropped)
{
    RGE_Command *v4; // edi@1
    _BYTE *v5; // esi@1

    v4 = this;
    v5 = calloc(1u, 4u);
    v5[2] = comm_player_id;
    *v5 = 11;
    v5[1] = player_id;
    v5[3] = dropped;
    TDebuggingLog::Log(L, aSendCmdResignP, player_id, dropped);
    RGE_Command::submit(v4, v5, 4);
}

//----- (00436030) --------------------------------------------------------
void RGE_Command::command_add_waypoint(int playerID, int recipient, XYZBYTEPoint *waypoint, int numWaypoints)
{
    RGE_Command *v5; // ebp@1
    _BYTE *v6; // esi@1
    int v7; // edi@2
    char *v8; // eax@2
    int v9; // ecx@2
    char v10; // dl@3
    RGE_Static_Object *v11; // eax@4
    char *v12; // eax@5

    v5 = this;
    v6 = calloc(1u, 0x18u);
    *v6 = 12;
    v6[1] = playerID;
    *((_DWORD *)v6 + 1) = recipient;
    v6[8] = numWaypoints;
    if( numWaypoints > 0 )
    {
        v7 = numWaypoints;
        v8 = &waypoint->z;
        v9 = (int)(v6 + 10);
        do
        {
            v10 = *(v8 - 2);
            v8 += 3;
            *(_BYTE *)(v9 - 1) = v10;
            *(_BYTE *)v9 = *(v8 - 4);
            *(_BYTE *)(v9 + 1) = *(v8 - 3);
            v9 += 3;
            --v7;
        }
        while( v7 );
    }
    v11 = RGE_Game_World::object(v5->world, recipient);
    if( v11 )
        v12 = v11->master_obj->name;
    else
        v12 = asc_583B74;
    TDebuggingLog::Log(L, aSendCmdAddWayP, playerID, v12);
    RGE_Command::submit(v5, v6, 24);
}

//----- (004360D0) --------------------------------------------------------
void RGE_Command::command_add_waypoint(int playerID, int recipient, char x, char y, char z)
{
    RGE_Command *v6; // edi@1
    void *v7; // eax@1
    void *v8; // esi@1
    RGE_Static_Object *v9; // eax@1
    char *v10; // eax@2

    v6 = this;
    v7 = calloc(1u, 0x18u);
    v8 = v7;
    *((_BYTE *)v7 + 9) = x;
    *(_BYTE *)v7 = 12;
    *((_BYTE *)v7 + 1) = playerID;
    *((_DWORD *)v7 + 1) = recipient;
    *((_BYTE *)v7 + 8) = 1;
    *((_BYTE *)v7 + 10) = y;
    *((_BYTE *)v7 + 11) = z;
    v9 = RGE_Game_World::object(v6->world, recipient);
    if( v9 )
        v10 = v9->master_obj->name;
    else
        v10 = asc_583B74;
    TDebuggingLog::Log(L, aSendCmdAddWay2, playerID, v10);
    RGE_Command::submit(v6, v8, 24);
}

//----- (00436150) --------------------------------------------------------
void RGE_Command::command_group_waypoint(RGE_Static_Object **unit, short unit_count, char location_x, char location_y)
{
    short v5; // bx@1
    int v6; // esi@1
    size_t v7; // eax@1
    void *v8; // eax@3
    _BYTE *v9; // edi@3
    bool v10; // zf@3
    char *v11; // eax@3
    char *v12; // edx@5
    int v13; // ecx@6
    RGE_Static_Object *v14; // eax@10
    char *v15; // ecx@11
    signed int v16; // eax@14
    RGE_Command *v17; // [sp+10h] [bp-4h]@1
    int unit_counta; // [sp+1Ch] [bp+8h]@1

    v5 = unit_count;
    v6 = unit_count;
    v7 = 4 * unit_count + 4;
    v17 = this;
    unit_counta = 4 * unit_count + 4;
    if( unit )
    {
        if( v5 >= 1 )
        {
            v8 = calloc(1u, v7);
            v9 = v8;
            v10 = v8 == 0;
            v11 = (char *)v8 + 4;
            if( !v10 )
            {
                if( v6 > 0 )
                {
                    v12 = (char *)((char *)unit - v11);
                    do
                    {
                        v13 = *(_DWORD *)&v11[(_DWORD)v12];
                        if( v13 )
                            *(_DWORD *)v11 = *(_DWORD *)(v13 + 4);
                        else
                            *(_DWORD *)v11 = -1;
                        v11 += 4;
                        --v6;
                    }
                    while( v6 );
                }
                *v9 = 16;
                v9[1] = v5;
                v9[2] = location_x;
                v9[3] = location_y;
                v14 = *unit;
                if( *unit )
                    v15 = v14->master_obj->name;
                else
                    v15 = asc_583B74;
                if( v14 )
                    v16 = v14->owner->id;
                else
                    v16 = -1;
                TDebuggingLog::Log(L, aSendCmdGrpWayP, v16, v15);
                RGE_Command::submit(v17, v9, unit_counta);
            }
        }
    }
}

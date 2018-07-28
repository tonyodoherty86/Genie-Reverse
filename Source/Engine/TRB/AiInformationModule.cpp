
/**
 * @file    Engine\TRB\AiInformationModule.cpp
 * @author  Yvan Burrie
 * @date    2018/07/03
 * @version 1.0
 */

void TribeInformationAIModule::TribeInformationAIModule(void *pW, int pID)
{
    TribeInformationAIModule *v3; // ebp@1
    signed int v4; // eax@1
    int v5; // eax@3
    signed int v6; // ecx@3
    int *v7; // eax@5
    signed int v8; // ecx@5
    ObjectMemory *v9; // eax@7
    int v10; // ecx@8
    int v11; // eax@9
    BuildingLot *v12; // eax@11
    int i; // eax@12
    AttackMemory *v14; // eax@14
    int v15; // ecx@15
    int v16; // eax@16
    int v17; // eax@18
    signed int v18; // edx@18
    signed int v19; // edx@20
    int v20; // edi@20
    int *v21; // eax@20
    signed int v22; // ecx@21
    int *v23; // eax@24
    signed int v24; // ecx@24

    v3 = this;

    v3->farmsTaskedThisUpdate.value = 0;
    v3->farmsTaskedThisUpdate.numberValue = 0;
    v3->farmsTaskedThisUpdate.desiredNumberValue = 0;
    v3->farmsTaskedThisUpdate.maximumSizeValue = 0;
    v3->md = 0;
    v3->mapXSizeValue = -1;
    v3->mapYSizeValue = -1;
    v3->lastUpdateRowValue = 0;
    v3->maxImportantObjectMemory = 500;
    v3->importantObjects.value = 0;
    v3->importantObjects.numberValue = 0;
    v3->importantObjects.desiredNumberValue = 0;
    v3->importantObjects.maximumSizeValue = 0;
    v3->importantUnits.value = 0;
    v3->importantUnits.numberValue = 0;
    v3->importantUnits.desiredNumberValue = 0;
    v3->importantUnits.maximumSizeValue = 0;
    v3->importantMiscs.value = 0;
    v3->importantMiscs.numberValue = 0;
    v3->importantMiscs.desiredNumberValue = 0;
    v3->importantMiscs.maximumSizeValue = 0;
    v3->itemsToDefend.value = 0;
    v3->itemsToDefend.numberValue = 0;
    v3->itemsToDefend.desiredNumberValue = 0;
    v3->itemsToDefend.maximumSizeValue = 0;
    InfluenceMap::InfluenceMap(&v3->pathMap, 254, 254, -1);
    v3->playerObjects.value = 0;
    v3->playerObjects.numberValue = 0;
    v3->playerObjects.desiredNumberValue = 0;
    v3->playerObjects.maximumSizeValue = 0;
    v3->playerBuildings.value = 0;
    v3->playerBuildings.numberValue = 0;
    v3->playerBuildings.desiredNumberValue = 0;
    v3->playerBuildings.maximumSizeValue = 0;
    v3->maxBuildingLots = 200;
    v3->maxAttackMemories = 25;
    v3->saveLearnInformationValue = 0;
    v3->numberFoundForestTilesValue = 0;
    v3->vfptr = (AIModuleVtbl *)&TribeInformationAIModule::`vftable';
    strcpy(v3->unitHistoryFilename, aLearnDefault_u);
    v3->resourceTypesValue = (int **)operator new(0x10u);
    v3->numberResourceTypesValue = (int *)operator new(0x10u);
    v4 = 0;
    do
    {
        ++v4;
        v3->numberResourceTypesValue[v4 - 1] = 0;
        v3->resourceTypesValue[v4 - 1] = 0;
    }
    while ( v4 < 4 );
    memset(v3->unitHistory, 0, sizeof(v3->unitHistory));
    memset(v3->playHistory, 0, sizeof(v3->playHistory));
    v5 = (int)v3->dropsitesByAge[1];
    v6 = 4;
    do
    {
        *(_DWORD *)(v5 - 16) = 0;
        *(_DWORD *)v5 = 1;
        *(_DWORD *)(v5 + 16) = 1;
        *(_DWORD *)(v5 + 32) = 1;
        v5 += 4;
        --v6;
    }
    while ( v6 );
    v7 = v3->closestDropsiteResourceID;
    v8 = 4;
    do
    {
        *(v7 - 4) = -1;
        *v7 = -1;
        ++v7;
        --v8;
    }
    while ( v8 );
    v9 = (ObjectMemory *)operator new(36 * v3->maxImportantObjectMemory);
    v3->importantObjectMemory = v9;
    if ( v9 )
    {
        v10 = 0;
        if ( v3->maxImportantObjectMemory > 0 )
        {
            v11 = 0;
            do
            {
                ++v10;
                v3->importantObjectMemory[v11].id = -1;
                v3->importantObjectMemory[v11].type = -1;
                v3->importantObjectMemory[v11].group = -1;
                v3->importantObjectMemory[v11].x = 0;
                v3->importantObjectMemory[v11].y = 0;
                v3->importantObjectMemory[v11].z = 0;
                v3->importantObjectMemory[v11].owner = 0;
                v3->importantObjectMemory[v11].hitPoints = 0;
                v3->importantObjectMemory[v11].attackAttempts = 0;
                v3->importantObjectMemory[v11].kills = 0;
                LODWORD(v3->importantObjectMemory[v11].damageCapability) = 0;
                LODWORD(v3->importantObjectMemory[v11].rateOfFire) = 0;
                LODWORD(v3->importantObjectMemory[v11].range) = 0;
                ++v11;
            }
            while ( v10 < v3->maxImportantObjectMemory );
        }
    }
    v12 = (BuildingLot *)operator new(8 * v3->maxBuildingLots);
    v3->buildingLots = v12;
    if ( v12 )
    {
        for ( i = 0; i < v3->maxBuildingLots; *((_BYTE *)&v3->buildingLots[i] - 4) = 0 )
        {
            v3->buildingLots[++i - 1].typeID = -1;
            *((_BYTE *)&v3->buildingLots[i] - 3) = 0;
            *((_BYTE *)&v3->buildingLots[i] - 2) = 0;
        }
    }
    v14 = (AttackMemory *)operator new(24 * v3->maxAttackMemories);
    v3->attackMemories = v14;
    if ( v14 )
    {
        v15 = 0;
        if ( v3->maxAttackMemories > 0 )
        {
            v16 = 0;
            do
            {
                ++v15;
                v3->attackMemories[v16].id = -1;
                v3->attackMemories[v16].id = -1;
                v3->attackMemories[v16].minX = 0;
                v3->attackMemories[v16].minY = 0;
                v3->attackMemories[v16].maxX = 0;
                v3->attackMemories[v16].maxY = 0;
                v3->attackMemories[v16].attackingOwner = -1;
                v3->attackMemories[v16].targetOwner = -1;
                v3->attackMemories[v16].kills = 0;
                v3->attackMemories[v16].success = 0;
                v3->attackMemories[v16].play = -1;
                ++v16;
            }
            while ( v15 < v3->maxAttackMemories );
        }
    }
    v17 = (int)&v3->minGatePosition[0].y;
    v3->lastWallPosition.x = -1;
    v3->lastWallPosition.y = -1;
    v3->lastWallPosition2.x = -1;
    v3->lastWallPosition2.y = -1;
    v3->numberGatesValue = -1;
    v18 = 4;
    do
    {
        *(_DWORD *)(v17 - 4) = -1;
        *(_DWORD *)v17 = -1;
        *(_DWORD *)(v17 + 28) = -1;
        *(_DWORD *)(v17 + 32) = -1;
        v17 += 8;
        --v18;
    }
    while ( v18 );
    v19 = 4;
    memset(v3->fullyExploredZoneValue, 0, 0xFCu);
    v20 = (int)&v3->fullyExploredZoneValue[252];
    *(_WORD *)v20 = 0;
    *(_BYTE *)(v20 + 2) = 0;
    v21 = &v3->quadrantLog[0][0].numberAttacksByUs;
    do
    {
        v22 = 4;
        do
        {
            *(v21 - 2) = 0;
            *(v21 - 1) = 0;
            *v21 = 0;
            v21 += 3;
            --v22;
        }
        while ( v22 );
        --v19;
    }
    while ( v19 );
    v23 = v3->maxResources;
    v24 = 4;
    do
    {
        *(v23 - 8) = 0;
        *v23 = 0;
        *(v23 - 4) = 0;
        ++v23;
        --v24;
    }
    while ( v24 );
}

void TribeInformationAIModule::TribeInformationAIModule(int pID, int infile)
{
    TribeInformationAIModule *v3; // ebp@1
    signed int v4; // eax@1
    int v5; // eax@3
    signed int v6; // ecx@3
    int *v7; // eax@5
    signed int v8; // ecx@5
    int v9; // edi@7
    int i; // esi@8
    int v11; // esi@11
    ObjectMemory *v12; // eax@11
    int v13; // esi@12
    int v14; // edi@13
    int *k; // edi@15
    BuildingLot *v16; // eax@15
    int j; // esi@16
    int *v18; // ebx@18
    AttackMemory *v19; // eax@18
    int v20; // esi@19
    int v21; // ecx@23
    int v22; // eax@23
    int v23; // ebx@28
    int *v24; // esi@28
    int l; // eax@29
    int v26; // ecx@36
    int v27; // eax@36
    int v28; // ebx@41
    int *v29; // esi@41
    int m; // eax@42
    int v31; // ecx@49
    int v32; // eax@49
    int v33; // ebx@54
    int *v34; // esi@54
    int n; // eax@55
    int v36; // ecx@62
    int v37; // eax@62
    int v38; // ebx@67
    int *v39; // esi@67
    int ii; // eax@68
    int v41; // ecx@75
    int v42; // eax@75
    int v43; // ebx@80
    int *v44; // esi@80
    int jj; // eax@81
    int v46; // ecx@88
    int v47; // eax@88
    int v48; // ebx@93
    int *v49; // esi@93
    int kk; // eax@94
    int v51; // edi@100
    XYPoint *v52; // esi@103
    signed int v53; // ebx@103
    int *v54; // eax@110
    signed int v55; // edx@110
    signed int v56; // ecx@111
    int *v57; // esi@114
    signed int v58; // ebx@114
    void *v59; // eax@116
    int tempIntNum; // [sp+10h] [bp-1Ch]@22
    int tempInt; // [sp+14h] [bp-18h]@23
    int data; // [sp+18h] [bp-14h]@9
    TribeInformationAIModule *v63; // [sp+1Ch] [bp-10h]@1
    int v64; // [sp+28h] [bp-4h]@1

    v3 = this;
    v63 = this;
    InformationAIModule::InformationAIModule((InformationAIModule *)&this->vfptr, 0, pID);
    v64 = 0;
    v3->farmsTaskedThisUpdate.value = 0;
    v3->farmsTaskedThisUpdate.numberValue = 0;
    v3->farmsTaskedThisUpdate.desiredNumberValue = 0;
    v3->farmsTaskedThisUpdate.maximumSizeValue = 0;
    v3->md = 0;
    v3->importantObjects.value = 0;
    v3->importantObjects.numberValue = 0;
    v3->importantObjects.desiredNumberValue = 0;
    v3->importantObjects.maximumSizeValue = 0;
    v3->importantUnits.value = 0;
    v3->importantUnits.numberValue = 0;
    v3->importantUnits.desiredNumberValue = 0;
    v3->importantUnits.maximumSizeValue = 0;
    v3->importantMiscs.value = 0;
    v3->importantMiscs.numberValue = 0;
    v3->importantMiscs.desiredNumberValue = 0;
    v3->importantMiscs.maximumSizeValue = 0;
    v3->itemsToDefend.value = 0;
    v3->itemsToDefend.numberValue = 0;
    v3->itemsToDefend.desiredNumberValue = 0;
    v3->itemsToDefend.maximumSizeValue = 0;
    InfluenceMap::InfluenceMap(&v3->pathMap, 254, 254, -1);
    v3->playerObjects.value = 0;
    v3->playerObjects.numberValue = 0;
    v3->playerObjects.desiredNumberValue = 0;
    v3->playerObjects.maximumSizeValue = 0;
    v3->playerBuildings.value = 0;
    v3->playerBuildings.numberValue = 0;
    v3->playerBuildings.desiredNumberValue = 0;
    v3->playerBuildings.maximumSizeValue = 0;
    v3->saveLearnInformationValue = 0;
    v3->numberFoundForestTilesValue = 0;
    v3->vfptr = (AIModuleVtbl *)&TribeInformationAIModule::`vftable';
    strcpy(v3->unitHistoryFilename, aLearnDefault_u);
    LOBYTE(v64) = 8;
    v3->resourceTypesValue = (int **)operator new(0x10u);
    v3->numberResourceTypesValue = (int *)operator new(0x10u);
    v4 = 0;
    do
    {
        ++v4;
        v3->numberResourceTypesValue[v4 - 1] = 0;
        v3->resourceTypesValue[v4 - 1] = 0;
    }
    while ( v4 < 4 );
    memset(v3->unitHistory, 0, sizeof(v3->unitHistory));
    memset(v3->playHistory, 0, sizeof(v3->playHistory));
    v5 = (int)v3->dropsitesByAge[1];
    v6 = 4;
    do
    {
        *(_DWORD *)(v5 - 16) = 0;
        *(_DWORD *)v5 = 1;
        *(_DWORD *)(v5 + 16) = 1;
        *(_DWORD *)(v5 + 32) = 1;
        v5 += 4;
        --v6;
    }
    while ( v6 );
    v7 = v3->closestDropsiteResourceID;
    v8 = 4;
    do
    {
        *(v7 - 4) = -1;
        *v7 = -1;
        ++v7;
        --v8;
    }
    while ( v8 );
    v9 = 0;
    do
    {
        rge_read((int)v3, v9, infile, &pID, 4);
        for ( i = 0; i < pID; ++i )
        {
            rge_read((int)v3, v9, infile, &data, 4);
            TribeInformationAIModule::addResourceType(v3, v9, data);
        }
        ++v9;
    }
    while ( v9 < 4 );
    v11 = infile;
    rge_read(infile, &this->mapXSizeValue, 4);
    rge_read(infile, &this->mapYSizeValue, 4);
    rge_read(infile, &this->lastUpdateRowValue, 4);
    rge_read(infile, &this->maxImportantObjectMemory, v11, &v3->maxImportantObjectMemory, 4);
    v12 = (ObjectMemory *)operator new(36 * v3->maxImportantObjectMemory);
    v3->importantObjectMemory = v12;
    if ( v12 )
    {
        v13 = 0;
        if ( v3->maxImportantObjectMemory > 0 )
        {
            v14 = 0;
            do
            {
                rge_read((int)v3, v14 * 36, infile, &v3->importantObjectMemory[v14], 36);
                ++v13;
                ++v14;
            }
            while ( v13 < v3->maxImportantObjectMemory );
        }
        k = &v3->maxBuildingLots;
        rge_read((int)v3, (int)&v3->maxBuildingLots, infile, &v3->maxBuildingLots, 4);
        v16 = (BuildingLot *)operator new(8 * v3->maxBuildingLots);
        v3->buildingLots = v16;
        if ( v16 )
        {
            for ( j = 0; j < *k; ++j )
                rge_read((int)v3, (int)k, infile, &v3->buildingLots[j], 8);
            v18 = &v3->maxAttackMemories;
            rge_read((int)v3, (int)k, infile, &v3->maxAttackMemories, 4);
            v19 = (AttackMemory *)operator new(24 * v3->maxAttackMemories);
            v3->attackMemories = v19;
            if ( v19 )
            {
                v20 = 0;
                if ( *v18 > 0 )
                {
                    k = 0;
                    do
                    {
                        rge_read((int)v3, (int)k, infile, (char *)v3->attackMemories + (unsigned int)k, 24);
                        ++v20;
                        k += 6;
                    }
                    while ( v20 < *v18 );
                }
                rge_read((int)v3, (int)k, infile, &tempIntNum, 4);
                for ( pID = 0; pID < tempIntNum; ++pID )
                {
                    rge_read((int)v3, (int)k, infile, &tempInt, 4);
                    v21 = v3->importantObjects.numberValue;
                    v22 = 0;
                    for ( k = (int *)tempInt; v22 < v21; ++v22 )
                    {
                        if ( v22 >= v3->importantObjects.maximumSizeValue )
                            break;
                        if ( v3->importantObjects.value[v22] == tempInt )
                            goto LABEL_34;
                    }
                    if ( v21 > v3->importantObjects.maximumSizeValue - 1 )
                    {
                        v23 = v21 + 1;
                        v24 = (int *)operator new(4 * (v21 + 1));
                        if ( v24 )
                        {
                            for ( l = 0; l < v3->importantObjects.maximumSizeValue; v24[l - 1] = v3->importantObjects.value[l - 1] )
                            {
                                if ( l >= v23 )
                                    break;
                                ++l;
                            }
                            operator delete(v3->importantObjects.value);
                            v3->importantObjects.value = v24;
                            v3->importantObjects.maximumSizeValue = v23;
                        }
                    }
                    v3->importantObjects.value[v3->importantObjects.numberValue++] = (int)k;
LABEL_34:
                    ;
                }
                rge_read((int)v3, (int)k, infile, &tempIntNum, 4);
                for ( pID = 0; pID < tempIntNum; ++pID )
                {
                    rge_read((int)v3, (int)k, infile, &tempInt, 4);
                    v26 = v3->importantUnits.numberValue;
                    v27 = 0;
                    for ( k = (int *)tempInt; v27 < v26; ++v27 )
                    {
                        if ( v27 >= v3->importantUnits.maximumSizeValue )
                            break;
                        if ( v3->importantUnits.value[v27] == tempInt )
                            goto LABEL_47;
                    }
                    if ( v26 > v3->importantUnits.maximumSizeValue - 1 )
                    {
                        v28 = v26 + 1;
                        v29 = (int *)operator new(4 * (v26 + 1));
                        if ( v29 )
                        {
                            for ( m = 0; m < v3->importantUnits.maximumSizeValue; v29[m - 1] = v3->importantUnits.value[m - 1] )
                            {
                                if ( m >= v28 )
                                    break;
                                ++m;
                            }
                            operator delete(v3->importantUnits.value);
                            v3->importantUnits.value = v29;
                            v3->importantUnits.maximumSizeValue = v28;
                        }
                    }
                    v3->importantUnits.value[v3->importantUnits.numberValue++] = (int)k;
LABEL_47:
                    ;
                }
                rge_read((int)v3, (int)k, infile, &tempIntNum, 4);
                for ( pID = 0; pID < tempIntNum; ++pID )
                {
                    rge_read((int)v3, (int)k, infile, &tempInt, 4);
                    v31 = v3->importantMiscs.numberValue;
                    v32 = 0;
                    for ( k = (int *)tempInt; v32 < v31; ++v32 )
                    {
                        if ( v32 >= v3->importantMiscs.maximumSizeValue )
                            break;
                        if ( v3->importantMiscs.value[v32] == tempInt )
                            goto LABEL_60;
                    }
                    if ( v31 > v3->importantMiscs.maximumSizeValue - 1 )
                    {
                        v33 = v31 + 1;
                        v34 = (int *)operator new(4 * (v31 + 1));
                        if ( v34 )
                        {
                            for ( n = 0; n < v3->importantMiscs.maximumSizeValue; v34[n - 1] = v3->importantMiscs.value[n - 1] )
                            {
                                if ( n >= v33 )
                                    break;
                                ++n;
                            }
                            operator delete(v3->importantMiscs.value);
                            v3->importantMiscs.value = v34;
                            v3->importantMiscs.maximumSizeValue = v33;
                        }
                    }
                    v3->importantMiscs.value[v3->importantMiscs.numberValue++] = (int)k;
LABEL_60:
                    ;
                }
                rge_read((int)v3, (int)k, infile, &tempIntNum, 4);
                for ( pID = 0; pID < tempIntNum; ++pID )
                {
                    rge_read((int)v3, (int)k, infile, &tempInt, 4);
                    v36 = v3->itemsToDefend.numberValue;
                    v37 = 0;
                    for ( k = (int *)tempInt; v37 < v36; ++v37 )
                    {
                        if ( v37 >= v3->itemsToDefend.maximumSizeValue )
                            break;
                        if ( v3->itemsToDefend.value[v37] == tempInt )
                            goto LABEL_73;
                    }
                    if ( v36 > v3->itemsToDefend.maximumSizeValue - 1 )
                    {
                        v38 = v36 + 1;
                        v39 = (int *)operator new(4 * (v36 + 1));
                        if ( v39 )
                        {
                            for ( ii = 0; ii < v3->itemsToDefend.maximumSizeValue; v39[ii - 1] = v3->itemsToDefend.value[ii - 1] )
                            {
                                if ( ii >= v38 )
                                    break;
                                ++ii;
                            }
                            operator delete(v3->itemsToDefend.value);
                            v3->itemsToDefend.value = v39;
                            v3->itemsToDefend.maximumSizeValue = v38;
                        }
                    }
                    v3->itemsToDefend.value[v3->itemsToDefend.numberValue++] = (int)k;
LABEL_73:
                    ;
                }
                rge_read((int)v3, (int)k, infile, &tempIntNum, 4);
                for ( pID = 0; pID < tempIntNum; ++pID )
                {
                    rge_read((int)v3, (int)k, infile, &tempInt, 4);
                    v41 = v3->playerBuildings.numberValue;
                    v42 = 0;
                    for ( k = (int *)tempInt; v42 < v41; ++v42 )
                    {
                        if ( v42 >= v3->playerBuildings.maximumSizeValue )
                            break;
                        if ( v3->playerBuildings.value[v42] == tempInt )
                            goto LABEL_86;
                    }
                    if ( v41 > v3->playerBuildings.maximumSizeValue - 1 )
                    {
                        v43 = v41 + 1;
                        v44 = (int *)operator new(4 * (v41 + 1));
                        if ( v44 )
                        {
                            for ( jj = 0; jj < v3->playerBuildings.maximumSizeValue; v44[jj - 1] = v3->playerBuildings.value[jj - 1] )
                            {
                                if ( jj >= v43 )
                                    break;
                                ++jj;
                            }
                            operator delete(v3->playerBuildings.value);
                            v3->playerBuildings.value = v44;
                            v3->playerBuildings.maximumSizeValue = v43;
                        }
                    }
                    v3->playerBuildings.value[v3->playerBuildings.numberValue++] = (int)k;
LABEL_86:
                    ;
                }
                rge_read((int)v3, (int)k, infile, &tempIntNum, 4);
                for ( pID = 0; pID < tempIntNum; ++pID )
                {
                    rge_read((int)v3, (int)k, infile, &tempInt, 4);
                    v46 = v3->playerObjects.numberValue;
                    v47 = 0;
                    for ( k = (int *)tempInt; v47 < v46; ++v47 )
                    {
                        if ( v47 >= v3->playerObjects.maximumSizeValue )
                            break;
                        if ( v3->playerObjects.value[v47] == tempInt )
                            goto LABEL_99;
                    }
                    if ( v46 > v3->playerObjects.maximumSizeValue - 1 )
                    {
                        v48 = v46 + 1;
                        v49 = (int *)operator new(4 * (v46 + 1));
                        if ( v49 )
                        {
                            for ( kk = 0; kk < v3->playerObjects.maximumSizeValue; v49[kk - 1] = v3->playerObjects.value[kk - 1] )
                            {
                                if ( kk >= v48 )
                                    break;
                                ++kk;
                            }
                            operator delete(v3->playerObjects.value);
                            v3->playerObjects.value = v49;
                            v3->playerObjects.maximumSizeValue = v48;
                        }
                    }
                    v3->playerObjects.value[v3->playerObjects.numberValue++] = (int)k;
LABEL_99:
                    ;
                }
                v51 = infile;
                InfluenceMap::load(&v3->pathMap, infile);
                rge_read((int)v3, v51, v51, &v3->lastWallPosition, 8);
                rge_read((int)v3, v51, v51, &v3->lastWallPosition2, 8);
                if ( save_game_version < 1.6 )
                    rge_read((int)v3, v51, v51, &v3->numberGatesValue, 8);
                else
                    rge_read((int)v3, v51, v51, &v3->numberGatesValue, 4);
                v52 = v3->maxGatePosition;
                v53 = 4;
                do
                {
                    rge_read((int)v3, v51, v51, &v52[-4], 8);
                    rge_read((int)v3, v51, v51, v52, 8);
                    ++v52;
                    --v53;
                }
                while ( v53 );
                rge_read((int)v3, v51, v51, &v3->saveLearnInformationValue, 4);
                if ( save_game_version < 1.6 )
                {
                    strcpy(v3->learnFileName, message_in);
                    v51 = infile;
                }
                else
                {
                    rge_read((int)v3, v51, v51, &tempInt, 4);
                    rge_read((int)v3, v51, v51, v3->learnFileName, tempInt);
                    v3->learnFileName[tempInt] = 0;
                }
                rge_read((int)v3, v51, v51, v3->fullyExploredZoneValue, 255);
                if ( save_game_version < 2.5 )
                {
                    v54 = &v3->quadrantLog[0][0].numberAttacksByUs;
                    v55 = 4;
                    do
                    {
                        v56 = 4;
                        do
                        {
                            *(v54 - 2) = 0;
                            *(v54 - 1) = 0;
                            *v54 = 0;
                            v54 += 3;
                            --v56;
                        }
                        while ( v56 );
                        --v55;
                    }
                    while ( v55 );
                }
                else
                {
                    rge_read((int)v3, v51, v51, v3->quadrantLog, 192);
                }
                v57 = v3->maxResources;
                rge_read((int)v3, v51, v51, v3->maxResources, 16);
                rge_read((int)v3, v51, v51, v3->numResources, 16);
                v58 = 4;
                do
                {
                    if ( *v57 )
                    {
                        v59 = operator new(20 * *v57);
                        *(v57 - 8) = (int)v59;
                        rge_read((int)v3, v51, v51, v59, 20 * *v57);
                    }
                    else
                    {
                        *(v57 - 8) = 0;
                    }
                    ++v57;
                    --v58;
                }
                while ( v58 );
                if ( save_game_version >= 6.8000002 )
                    rge_read((int)v3, v51, v51, v3->dropsitesByAge, 64);
                if ( save_game_version >= 6.8000002 )
                {
                    rge_read((int)v3, v51, v51, v3->closestDropsiteValue, 16);
                    rge_read((int)v3, v51, v51, v3->closestDropsiteResourceID, 16);
                }
                if ( save_game_version >= 6.9099998 )
                    rge_read((int)v3, v51, v51, &v3->numberFoundForestTilesValue, 4);
                if ( save_game_version >= 6.9899998 )
                    rge_read((int)v3, v51, v51, v3->playHistory, 64000);
            }
        }
    }
}

void TribeInformationAIModule::~TribeInformationAIModule()
{
    TribeInformationAIModule *v1; // esi@1
    int v2; // ebp@1
    signed int v3; // edi@1
    int v4; // eax@4
    int v5; // ebx@4
    int v6; // ecx@5
    int *v7; // eax@6
    int v8; // edi@11
    AttackMemory *v9; // edx@12
    int v10; // ecx@15
    ObjectMemory *v11; // eax@16
    int v12; // ebp@21
    int v13; // edi@22
    int v14; // eax@23
    int *v15; // edi@27
    signed int v16; // ebp@27
    int i; // ebp@31
    int *v18; // edi@33
    int j; // eax@34
    int k; // ebp@39
    int v21; // ebx@41
    int *v22; // edi@41
    int l; // eax@42
    RGE_Player *v24; // eax@49
    int v25; // eax@51
    int v26; // edi@51
    void **v27; // edi@59
    signed int v28; // ebx@59
    int *v29; // eax@63
    int *v30; // eax@65
    int *v31; // eax@67
    int *v32; // eax@69
    int *v33; // eax@71
    int *v34; // eax@73
    int *v35; // eax@75
    int count; // [sp+10h] [bp-1Ch]@5
    int tempInt; // [sp+14h] [bp-18h]@31
    int outFile; // [sp+18h] [bp-14h]@4
    TribeInformationAIModule *v39; // [sp+1Ch] [bp-10h]@1
    int v40; // [sp+28h] [bp-4h]@1

    v1 = this;
    v39 = this;
    this->vfptr = (AIModuleVtbl *)&TribeInformationAIModule::`vftable';
    v2 = 0;
    v40 = 8;
    v3 = 0;
    do
    {
        operator delete(v1->resourceTypesValue[v3]);
        ++v3;
    }
    while ( v3 < 4 );
    operator delete(v1->resourceTypesValue);
    operator delete(v1->numberResourceTypesValue);
    if ( v1->saveLearnInformationValue == 1 )
    {
        v4 = rge_open(v1->learnFileName, 33537, 384);
        v5 = v4;
        outFile = v4;
        if ( v4 != -1 )
        {
            rge_write(v4, &v1->mapXSizeValue, 4);
            rge_write(v5, &v1->mapYSizeValue, 4);
            v6 = v1->maxAttackMemories;
            count = 0;
            if ( v6 > 0 )
            {
                v7 = &v1->attackMemories->id;
                do
                {
                    if ( *v7 != -1 )
                        ++count;
                    v7 += 6;
                    --v6;
                }
                while ( v6 );
            }
            rge_write(v5, &count, 4);
            if ( v1->maxAttackMemories > 0 )
            {
                v8 = 0;
                do
                {
                    v9 = v1->attackMemories;
                    if ( v9[v8].id != -1 )
                        rge_write(v5, &v9[v8], 24);
                    ++v2;
                    ++v8;
                }
                while ( v2 < v1->maxAttackMemories );
            }
            v10 = v1->maxImportantObjectMemory;
            count = 0;
            if ( v10 > 0 )
            {
                v11 = v1->importantObjectMemory;
                do
                {
                    if ( v11->id != -1 && v11->type == 109 )
                        ++count;
                    ++v11;
                    --v10;
                }
                while ( v10 );
            }
            rge_write(v5, &count, 4);
            v12 = 0;
            if ( v1->maxImportantObjectMemory > 0 )
            {
                v13 = 0;
                do
                {
                    v14 = (int)&v1->importantObjectMemory[v13].id;
                    if ( *(_DWORD *)v14 != -1 && *(_WORD *)(v14 + 4) == 109 )
                        rge_write(v5, (void *)v14, 36);
                    ++v12;
                    ++v13;
                }
                while ( v12 < v1->maxImportantObjectMemory );
            }
            v15 = v1->maxResources;
            v16 = 4;
            do
            {
                rge_write(v5, v15, 4);
                rge_write(v5, v15 - 4, 4);
                if ( *v15 )
                    rge_write(v5, (void *)*(v15 - 8), 20 * *v15);
                ++v15;
                --v16;
            }
            while ( v16 );
            tempInt = v1->importantMiscs.numberValue;
            rge_write(v5, &tempInt, 4);
            for ( i = 0; i < v1->importantMiscs.numberValue; ++i )
            {
                if ( i > v1->importantMiscs.maximumSizeValue - 1 )
                {
                    v18 = (int *)operator new(4 * i + 4);
                    if ( v18 )
                    {
                        for ( j = 0; j < v1->importantMiscs.maximumSizeValue; v18[j - 1] = v1->importantMiscs.value[j - 1] )
                        {
                            if ( j >= i + 1 )
                                break;
                            ++j;
                        }
                        operator delete(v1->importantMiscs.value);
                        v1->importantMiscs.value = v18;
                        v1->importantMiscs.maximumSizeValue = i + 1;
                    }
                }
                tempInt = v1->importantMiscs.value[i];
                rge_write(v5, &tempInt, 4);
            }
            tempInt = v1->itemsToDefend.numberValue;
            rge_write(v5, &tempInt, 4);
            for ( k = 0; k < v1->itemsToDefend.numberValue; ++k )
            {
                if ( k > v1->itemsToDefend.maximumSizeValue - 1 )
                {
                    v21 = k + 1;
                    v22 = (int *)operator new(4 * k + 4);
                    if ( v22 )
                    {
                        for ( l = 0; l < v1->itemsToDefend.maximumSizeValue; v22[l - 1] = v1->itemsToDefend.value[l - 1] )
                        {
                            if ( l >= v21 )
                                break;
                            ++l;
                        }
                        operator delete(v1->itemsToDefend.value);
                        v1->itemsToDefend.value = v22;
                        v1->itemsToDefend.maximumSizeValue = v21;
                    }
                    v5 = outFile;
                }
                tempInt = v1->itemsToDefend.value[k];
                rge_write(v5, &tempInt, 4);
            }
            rge_close(v5);
        }
    }
    v24 = v1->md->player;
    if ( BYTE1(v24->world[1].game_speed) == v24->id || BYTE1(v24->world[1].game_speed) == -1 )
    {
        v25 = rge_open(v1->unitHistoryFilename, 33537, 384);
        v26 = v25;
        if ( v25 != -1 )
        {
            rge_write(v25, v1->unitHistory, 44);
            rge_close(v26);
        }
    }
    if ( v1->importantObjectMemory )
        operator delete(v1->importantObjectMemory);
    if ( v1->buildingLots )
        operator delete(v1->buildingLots);
    if ( v1->attackMemories )
        operator delete(v1->attackMemories);
    v27 = (void **)v1->resources;
    v28 = 4;
    do
    {
        if ( *v27 )
        {
            operator delete(*v27);
            *v27 = 0;
        }
        ++v27;
        --v28;
    }
    while ( v28 );
    v29 = v1->playerBuildings.value;
    LOBYTE(v40) = 7;
    if ( v29 )
    {
        operator delete(v29);
        v1->playerBuildings.value = 0;
    }
    v1->playerBuildings.numberValue = 0;
    v1->playerBuildings.desiredNumberValue = 0;
    v1->playerBuildings.maximumSizeValue = 0;
    v30 = v1->playerObjects.value;
    LOBYTE(v40) = 6;
    if ( v30 )
    {
        operator delete(v30);
        v1->playerObjects.value = 0;
    }
    v1->playerObjects.numberValue = 0;
    v1->playerObjects.desiredNumberValue = 0;
    v1->playerObjects.maximumSizeValue = 0;
    LOBYTE(v40) = 5;
    InfluenceMap::~InfluenceMap(&v1->pathMap);
    v31 = v1->itemsToDefend.value;
    LOBYTE(v40) = 4;
    if ( v31 )
    {
        operator delete(v31);
        v1->itemsToDefend.value = 0;
    }
    v1->itemsToDefend.numberValue = 0;
    v1->itemsToDefend.desiredNumberValue = 0;
    v1->itemsToDefend.maximumSizeValue = 0;
    v32 = v1->importantMiscs.value;
    LOBYTE(v40) = 3;
    if ( v32 )
    {
        operator delete(v32);
        v1->importantMiscs.value = 0;
    }
    v1->importantMiscs.numberValue = 0;
    v1->importantMiscs.desiredNumberValue = 0;
    v1->importantMiscs.maximumSizeValue = 0;
    v33 = v1->importantUnits.value;
    LOBYTE(v40) = 2;
    if ( v33 )
    {
        operator delete(v33);
        v1->importantUnits.value = 0;
    }
    v1->importantUnits.numberValue = 0;
    v1->importantUnits.desiredNumberValue = 0;
    v1->importantUnits.maximumSizeValue = 0;
    v34 = v1->importantObjects.value;
    LOBYTE(v40) = 1;
    if ( v34 )
    {
        operator delete(v34);
        v1->importantObjects.value = 0;
    }
    v1->importantObjects.numberValue = 0;
    v1->importantObjects.desiredNumberValue = 0;
    v1->importantObjects.maximumSizeValue = 0;
    v35 = v1->farmsTaskedThisUpdate.value;
    LOBYTE(v40) = 0;
    if ( v35 )
    {
        operator delete(v35);
        v1->farmsTaskedThisUpdate.value = 0;
    }
    v1->farmsTaskedThisUpdate.numberValue = 0;
    v1->farmsTaskedThisUpdate.desiredNumberValue = 0;
    v1->farmsTaskedThisUpdate.maximumSizeValue = 0;
    v40 = -1;
    InformationAIModule::~InformationAIModule((InformationAIModule *)&v1->vfptr);
}
// 575510: using guessed type int (*TribeInformationAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (004D8270) --------------------------------------------------------
int TribeInformationAIModule::initialize()
{
    TribeInformationAIModule *v1; // esi@1
    RGE_Map *v2; // eax@1
    RGE_Game_Info *v3; // edi@1
    RGE_Person_Info *v4; // eax@2
    int result; // eax@2
    int v6; // edx@3
    unsigned int v7; // ecx@3
    char v8; // al@3
    char *v9; // edi@3
    char *v10; // esi@3

    v1 = this;
    v2 = this->md->player->world->map;
    this->mapXSizeValue = v2->map_width;
    this->mapYSizeValue = v2->map_height;
    v3 = rge_base_game->player_game_info;
    if ( RGE_Game_Info::get_current_player_name(rge_base_game->player_game_info) )
    {
        v4 = RGE_Game_Info::get_current_player_name(v3);
        sprintf(v1->unitHistoryFilename, aLearnS_uh, v4);
        result = 1;
    }
    else
    {
        v6 = (int)v1->unitHistoryFilename;
        v7 = strlen(aLearnDefault_u) + 1;
        v8 = v7;
        v7 >>= 2;
        qmemcpy(v1->unitHistoryFilename, aLearnDefault_u, 4 * v7);
        v10 = &aLearnDefault_u[4 * v7];
        v9 = (char *)(v6 + 4 * v7);
        LOBYTE(v7) = v8;
        result = 1;
        qmemcpy(v9, v10, v7 & 3);
    }
    return result;
}

//----- (004D8300) --------------------------------------------------------
int TribeInformationAIModule::update@<eax>(TribeInformationAIModule *this@<ecx>, double a2@<st0>, int timeLimit)
{
    TribeInformationAIModule *v3; // esi@1
    int v4; // eax@1
    RGE_Player *v5; // ecx@1
    RGE_Visible_Map *v6; // edx@1
    RGE_Game_World *v7; // ecx@1
    RGE_Tile_List_Node *v8; // eax@3
    int v9; // ebp@4
    int v10; // esi@4
    int v11; // ebx@4
    signed int v12; // ecx@4
    AIModuleVtbl **v13; // eax@5
    RGE_Object_Node *j; // edi@6
    RGE_Static_Object *v15; // esi@7
    int v16; // ebx@9
    bool v17; // sf@20
    unsigned __int8 v18; // of@20
    char visibleStatus; // [sp+7h] [bp-25h]@4
    TribeInformationAIModule *v21; // [sp+8h] [bp-24h]@1
    int qX; // [sp+Ch] [bp-20h]@6
    RGE_Tile_List_Node *list; // [sp+10h] [bp-1Ch]@1
    RGE_Map *gMap; // [sp+14h] [bp-18h]@1
    int i; // [sp+18h] [bp-14h]@2
    int listSize; // [sp+1Ch] [bp-10h]@1
    RGE_Visible_Map *vMap; // [sp+20h] [bp-Ch]@1
    InfluenceMap *v28; // [sp+24h] [bp-8h]@3
    int tileType; // [sp+28h] [bp-4h]@4

    v3 = this;
    v21 = this;
    RGE_Tile_List::get_list_info(&this->md->player->tile_list, &list, &listSize);
    v4 = RGE_Tile_List::get_new_count(&v3->md->player->tile_list);
    v5 = v3->md->player;
    v6 = v5->visible;
    v7 = v5->world;
    vMap = v6;
    gMap = v7->map;
    if ( v4 > 0 )
    {
        i = listSize - v4;
        if ( listSize - v4 < listSize )
        {
            v8 = list;
            v28 = &v3->pathMap;
            do
            {
                v9 = v8->row;
                v10 = v8->col;
                visibleStatus = RGE_Visible_Map::get_visible(vMap, v8->col, v8->row);
                v11 = v9;
                v12 = v21->mapXSizeValue;
                tileType = *((_BYTE *)&gMap->map_row_offset[v9][v10] + 5) & 0x1F;
                if ( v12 != -1 )
                {
                    v13 = &v21->vfptr + 3 * (v11 * 4 / v21->mapYSizeValue + 4 * (4 * v10 / v12) + 86);
                    *v13 = (AIModuleVtbl *)((char *)*v13 + 1);
                }
                InfluenceMap::setValue(v28, v10, v9, 0);
                qX = 0;
                for ( j = gMap->map_row_offset[v11][v10].objects.list; j; j = j->next )
                {
                    v15 = j->node;
                    if ( visibleStatus != -128 || v15->master_obj->fog_flag )
                    {
                        v16 = v15->master_obj->object_group;
                        if ( TribeInformationAIModule::importantObject(v16) == 1 )
                            TribeInformationAIModule::addImportantObject(v21, a2, v15, 0);
                        if ( v16 == 15 )
                            ++qX;
                    }
                }
                if ( qX > 0 && (tileType == 10 || tileType == 19 || tileType == 13 || tileType == 20) )
                    ++v21->numberFoundForestTilesValue;
                v8 = list + 1;
                v18 = __OFSUB__(i + 1, listSize);
                v17 = i++ + 1 - listSize < 0;
                ++list;
            }
            while ( v17 ^ v18 );
        }
    }
    return 1;
}

//----- (004D84D0) --------------------------------------------------------
void TribeInformationAIModule::setMainDecisionAI(TribeMainDecisionAIModule *m)
{
    this->md = m;
}

//----- (004D84E0) --------------------------------------------------------
int TribeInformationAIModule::save(int outfile)
{
    int v2; // ebp@1
    TribeInformationAIModule *v3; // esi@1
    signed int v4; // edi@1
    int i; // ebx@2
    int v6; // edi@5
    int v7; // ebx@6
    int j; // edi@8
    int v9; // edi@10
    int v10; // ebx@11
    int k; // ebx@13
    int *v12; // edi@15
    int l; // eax@16
    int m; // ebx@21
    int *v15; // edi@23
    int n; // eax@24
    int ii; // ebx@29
    int *v18; // edi@31
    int jj; // eax@32
    int kk; // ebx@37
    int *v21; // edi@39
    int ll; // eax@40
    int mm; // ebx@45
    int *v24; // edi@47
    int nn; // eax@48
    int i1; // ebx@53
    int *v27; // edi@55
    int i2; // eax@56
    XYPoint *v29; // edi@61
    signed int v30; // ebx@61
    int *v31; // edi@63
    int *v32; // eax@63
    signed int v33; // ecx@63
    signed int v34; // ebx@68
    int data; // [sp+10h] [bp-4h]@2

    v2 = outfile;
    v3 = this;
    v4 = 0;
    do
    {
        data = v3->numberResourceTypesValue[v4];
        rge_write(v2, &data, 4);
        for ( i = 0; i < v3->numberResourceTypesValue[v4]; ++i )
        {
            data = v3->resourceTypesValue[v4][i];
            rge_write(v2, &data, 4);
        }
        ++v4;
    }
    while ( v4 < 4 );
    rge_write(v2, &v3->mapXSizeValue, 4);
    rge_write(v2, &v3->mapYSizeValue, 4);
    rge_write(v2, &v3->lastUpdateRowValue, 4);
    rge_write(v2, &v3->maxImportantObjectMemory, 4);
    v6 = 0;
    if ( v3->maxImportantObjectMemory > 0 )
    {
        v7 = 0;
        do
        {
            rge_write(v2, &v3->importantObjectMemory[v7], 36);
            ++v6;
            ++v7;
        }
        while ( v6 < v3->maxImportantObjectMemory );
    }
    rge_write(v2, &v3->maxBuildingLots, 4);
    for ( j = 0; j < v3->maxBuildingLots; ++j )
        rge_write(v2, &v3->buildingLots[j], 8);
    rge_write(v2, &v3->maxAttackMemories, 4);
    v9 = 0;
    if ( v3->maxAttackMemories > 0 )
    {
        v10 = 0;
        do
        {
            rge_write(v2, &v3->attackMemories[v10], 24);
            ++v9;
            ++v10;
        }
        while ( v9 < v3->maxAttackMemories );
    }
    outfile = v3->importantObjects.numberValue;
    rge_write(v2, &outfile, 4);
    for ( k = 0; k < v3->importantObjects.numberValue; ++k )
    {
        if ( k > v3->importantObjects.maximumSizeValue - 1 )
        {
            v12 = (int *)operator new(4 * k + 4);
            if ( v12 )
            {
                for ( l = 0; l < v3->importantObjects.maximumSizeValue; v12[l - 1] = v3->importantObjects.value[l - 1] )
                {
                    if ( l >= k + 1 )
                        break;
                    ++l;
                }
                operator delete(v3->importantObjects.value);
                v3->importantObjects.value = v12;
                v3->importantObjects.maximumSizeValue = k + 1;
            }
        }
        outfile = v3->importantObjects.value[k];
        rge_write(v2, &outfile, 4);
    }
    outfile = v3->importantUnits.numberValue;
    rge_write(v2, &outfile, 4);
    for ( m = 0; m < v3->importantUnits.numberValue; ++m )
    {
        if ( m > v3->importantUnits.maximumSizeValue - 1 )
        {
            v15 = (int *)operator new(4 * m + 4);
            if ( v15 )
            {
                for ( n = 0; n < v3->importantUnits.maximumSizeValue; v15[n - 1] = v3->importantUnits.value[n - 1] )
                {
                    if ( n >= m + 1 )
                        break;
                    ++n;
                }
                operator delete(v3->importantUnits.value);
                v3->importantUnits.value = v15;
                v3->importantUnits.maximumSizeValue = m + 1;
            }
        }
        outfile = v3->importantUnits.value[m];
        rge_write(v2, &outfile, 4);
    }
    outfile = v3->importantMiscs.numberValue;
    rge_write(v2, &outfile, 4);
    for ( ii = 0; ii < v3->importantMiscs.numberValue; ++ii )
    {
        if ( ii > v3->importantMiscs.maximumSizeValue - 1 )
        {
            v18 = (int *)operator new(4 * ii + 4);
            if ( v18 )
            {
                for ( jj = 0; jj < v3->importantMiscs.maximumSizeValue; v18[jj - 1] = v3->importantMiscs.value[jj - 1] )
                {
                    if ( jj >= ii + 1 )
                        break;
                    ++jj;
                }
                operator delete(v3->importantMiscs.value);
                v3->importantMiscs.value = v18;
                v3->importantMiscs.maximumSizeValue = ii + 1;
            }
        }
        outfile = v3->importantMiscs.value[ii];
        rge_write(v2, &outfile, 4);
    }
    outfile = v3->itemsToDefend.numberValue;
    rge_write(v2, &outfile, 4);
    for ( kk = 0; kk < v3->itemsToDefend.numberValue; ++kk )
    {
        if ( kk > v3->itemsToDefend.maximumSizeValue - 1 )
        {
            v21 = (int *)operator new(4 * kk + 4);
            if ( v21 )
            {
                for ( ll = 0; ll < v3->itemsToDefend.maximumSizeValue; v21[ll - 1] = v3->itemsToDefend.value[ll - 1] )
                {
                    if ( ll >= kk + 1 )
                        break;
                    ++ll;
                }
                operator delete(v3->itemsToDefend.value);
                v3->itemsToDefend.value = v21;
                v3->itemsToDefend.maximumSizeValue = kk + 1;
            }
        }
        outfile = v3->itemsToDefend.value[kk];
        rge_write(v2, &outfile, 4);
    }
    outfile = v3->playerBuildings.numberValue;
    rge_write(v2, &outfile, 4);
    for ( mm = 0; mm < v3->playerBuildings.numberValue; ++mm )
    {
        if ( mm > v3->playerBuildings.maximumSizeValue - 1 )
        {
            v24 = (int *)operator new(4 * mm + 4);
            if ( v24 )
            {
                for ( nn = 0; nn < v3->playerBuildings.maximumSizeValue; v24[nn - 1] = v3->playerBuildings.value[nn - 1] )
                {
                    if ( nn >= mm + 1 )
                        break;
                    ++nn;
                }
                operator delete(v3->playerBuildings.value);
                v3->playerBuildings.value = v24;
                v3->playerBuildings.maximumSizeValue = mm + 1;
            }
        }
        outfile = v3->playerBuildings.value[mm];
        rge_write(v2, &outfile, 4);
    }
    outfile = v3->playerObjects.numberValue;
    rge_write(v2, &outfile, 4);
    for ( i1 = 0; i1 < v3->playerObjects.numberValue; ++i1 )
    {
        if ( i1 > v3->playerObjects.maximumSizeValue - 1 )
        {
            v27 = (int *)operator new(4 * i1 + 4);
            if ( v27 )
            {
                for ( i2 = 0; i2 < v3->playerObjects.maximumSizeValue; v27[i2 - 1] = v3->playerObjects.value[i2 - 1] )
                {
                    if ( i2 >= i1 + 1 )
                        break;
                    ++i2;
                }
                operator delete(v3->playerObjects.value);
                v3->playerObjects.value = v27;
                v3->playerObjects.maximumSizeValue = i1 + 1;
            }
        }
        outfile = v3->playerObjects.value[i1];
        rge_write(v2, &outfile, 4);
    }
    InfluenceMap::save(&v3->pathMap, v2);
    rge_write(v2, &v3->lastWallPosition, 8);
    rge_write(v2, &v3->lastWallPosition2, 8);
    rge_write(v2, &v3->numberGatesValue, 4);
    v29 = v3->maxGatePosition;
    v30 = 4;
    do
    {
        rge_write(v2, &v29[-4], 8);
        rge_write(v2, v29, 8);
        ++v29;
        --v30;
    }
    while ( v30 );
    rge_write(v2, &v3->saveLearnInformationValue, 4);
    outfile = strlen(v3->learnFileName);
    rge_write(v2, &outfile, 4);
    rge_write(v2, v3->learnFileName, strlen(v3->learnFileName));
    rge_write(v2, v3->fullyExploredZoneValue, 255);
    rge_write(v2, v3->quadrantLog, 192);
    v31 = v3->maxResources;
    v32 = v3->maxResources;
    v33 = 4;
    do
    {
        if ( *v32 && !*(v32 - 8) )
            *v32 = 0;
        ++v32;
        --v33;
    }
    while ( v33 );
    rge_write(v2, v3->maxResources, 16);
    rge_write(v2, v3->numResources, 16);
    v34 = 4;
    do
    {
        if ( *v31 )
            rge_write(v2, (void *)*(v31 - 8), 20 * *v31);
        ++v31;
        --v34;
    }
    while ( v34 );
    rge_write(v2, v3->dropsitesByAge, 64);
    rge_write(v2, v3->closestDropsiteValue, 16);
    rge_write(v2, v3->closestDropsiteResourceID, 16);
    rge_write(v2, &v3->numberFoundForestTilesValue, 4);
    rge_write(v2, v3->playHistory, 64000);
    return 1;
}

//----- (004D8C80) --------------------------------------------------------
void TribeInformationAIModule::blotExploredMap(int minX, int minY, int maxX, int maxY)
{
    TribeInformationAIModule *v5; // ebp@1
    int v6; // ebx@1
    int v7; // eax@2
    int v8; // esi@2
    XYPoint max; // [sp+8h] [bp-10h]@1
    XYPoint min; // [sp+10h] [bp-8h]@1

    v5 = this;
    min.y = minY;
    min.x = minX;
    TribeInformationAIModule::mapBound(this, &min);
    max.y = maxY;
    max.x = maxX;
    TribeInformationAIModule::mapBound(v5, &max);
    v6 = min.x;
    if ( min.x <= max.x )
    {
        v7 = max.y;
        v8 = min.y;
        do
        {
            if ( v8 <= v7 )
            {
                do
                {
                    if ( InfluenceMap::lookupValue(&v5->pathMap, v6, v8) != 1 )
                        InfluenceMap::setValue(&v5->pathMap, v6, v8, 2);
                    v7 = max.y;
                    ++v8;
                }
                while ( v8 <= max.y );
                v8 = min.y;
            }
            ++v6;
        }
        while ( v6 <= max.x );
    }
}

//----- (004D8D20) --------------------------------------------------------
RGE_Static_Object *TribeInformationAIModule::closestUnexploredTile(int uID, float cX, float cY, float *uX, float *uY)
{
    TribeInformationAIModule *v6; // edi@1
    RGE_Player *v7; // eax@1
    RGE_Static_Object *result; // eax@1
    int v9; // ebx@2
    int v10; // esi@2
    int v11; // ebp@2
    int v12; // eax@8
    char v13; // bl@23
    float v14; // ST1C_4@29
    float v15; // ST18_4@29
    bool v16; // sf@33
    unsigned __int8 v17; // of@33
    float v18; // ST0C_4@36
    int v19; // ebx@37
    int v20; // ebp@37
    int v21; // eax@37
    int v22; // edi@38
    int v23; // esi@39
    int v24; // edx@39
    int v25; // edi@44
    int v26; // ebx@44
    int v27; // eax@44
    double v28; // st7@52
    char initialZone; // [sp+37h] [bp-35h]@2
    int direction; // [sp+38h] [bp-34h]@2
    RGE_Static_Object *obj; // [sp+3Ch] [bp-30h]@1
    int offTop; // [sp+40h] [bp-2Ch]@2
    int offBottom; // [sp+44h] [bp-28h]@2
    int civilianObj; // [sp+48h] [bp-24h]@2
    int j; // [sp+4Ch] [bp-20h]@8
    int i; // [sp+50h] [bp-1Ch]@7
    TribeInformationAIModule *v37; // [sp+54h] [bp-18h]@1
    RGE_Visible_Map *vMap; // [sp+58h] [bp-14h]@1
    int stepSize; // [sp+5Ch] [bp-10h]@7
    float pathDistance; // [sp+60h] [bp-Ch]@36
    XYPoint cPoint; // [sp+64h] [bp-8h]@2
    int uIDa; // [sp+70h] [bp+4h]@38
    int b; // [sp+74h] [bp+8h]@2
    int ba; // [sp+74h] [bp+8h]@37
    int a; // [sp+78h] [bp+Ch]@2
    int aa; // [sp+78h] [bp+Ch]@37

    v6 = this;
    v37 = this;
    v7 = this->md->player;
    vMap = v7->visible;
    result = RGE_Game_World::object(v7->world, uID);
    obj = result;
    if ( !result )
        return result;
    civilianObj = result->master_obj->object_group == 4;
    initialZone = RGE_Static_Object::currentZone(result);
    v9 = 0;
    direction = (unsigned __int8)((char)debug_rand(aCMsdevWorkA_52, 919) % -4);
    v10 = (signed __int64)cX;
    cPoint.x = (signed __int64)cX;
    v11 = (signed __int64)cY;
    cPoint.y = (signed __int64)cY;
    b = 0;
    a = 0;
    offTop = 0;
    offBottom = 0;
LABEL_3:
    if ( b && a && offTop && offBottom )
    {
        TribeInformationAIModule::setFullyExploredZone(v6, uID, 1);
        return 0;
    }
    ++v9;
    i = 0;
    stepSize = v9;
    while ( 1 )
    {
        j = 0;
        v12 = (((unsigned __int64)(direction + 1) >> 32) ^ abs(direction + 1) & 3)
                - ((unsigned __int64)(direction + 1) >> 32);
        direction = v12;
        if ( v9 > 0 )
            break;
LABEL_33:
        v17 = __OFSUB__(i + 1, 2);
        v16 = i++ - 1 < 0;
        if ( !(v16 ^ v17) )
            goto LABEL_3;
    }
    while ( 1 )
    {
        switch ( v12 )
        {
            case 0:
                cPoint.y = ++v11;
                break;
            case 1:
                ++v10;
                goto LABEL_14;
            case 2:
                cPoint.y = --v11;
                break;
            case 3:
                --v10;
LABEL_14:
                cPoint.x = v10;
                break;
            default:
                break;
        }
        if ( v10 >= 0 )
            break;
        b = 1;
LABEL_32:
        if ( ++j >= v9 )
            goto LABEL_33;
    }
    if ( v10 >= v6->mapXSizeValue )
    {
        a = 1;
        goto LABEL_32;
    }
    if ( v11 < 0 )
    {
        offTop = 1;
        goto LABEL_32;
    }
    if ( v11 >= v6->mapYSizeValue )
    {
        offBottom = 1;
        goto LABEL_32;
    }
    v13 = InfluenceMap::lookupValue(&v6->pathMap, v10, v11);
    if ( RGE_Visible_Map::get_visible(vMap, v10, v11) == 15
        || civilianObj == 1 && v13 != -1
        || !civilianObj && v13 != -1 && v13 != 2
        || (v14 = (double)cPoint.y,
                v15 = (double)cPoint.x,
                !((int (__stdcall *)(_DWORD, _DWORD, signed int))obj->vfptr->passableTile)(LODWORD(v15), LODWORD(v14), 1))
        || RGE_Static_Object::lookupZone(obj, v10, v11) != initialZone )
    {
        v9 = stepSize;
        v12 = direction;
        goto LABEL_32;
    }
    v18 = obj->master_obj->los - 1.0;
    if ( ((int (*)(RGE_Static_Object *, int, int, _DWORD, _DWORD, signed int, float *, signed int, signed int, signed int))obj->vfptr->canPath)(
                 obj,
                 v10,
                 v11,
                 (signed __int64)obj->world_z,
                 LODWORD(v18),
                 -1,
                 &pathDistance,
                 1,
                 -1,
                 -1) )
    {
        InfluenceMap::setValue(&v6->pathMap, v10, v11, 0);
    }
    else
    {
        InfluenceMap::setValue(&v6->pathMap, v10, v11, 1);
        v19 = -1;
        v20 = 0;
        aa = 0;
        ba = 0;
        v21 = (int)v6->quadrantLog;
        do
        {
            uIDa = 0;
            v22 = v21;
            do
            {
                v23 = *(_DWORD *)v22;
                v24 = debug_rand(aCMsdevWorkA_52, 1056) % 100 + v23 + 5 * *(_DWORD *)(v22 + 4);
                if ( v19 == -1 || v19 > v24 + 20 * *(_DWORD *)(v22 + 4) )
                {
                    v19 = v24 + 20 * *(_DWORD *)(v22 + 4);
                    v20 = ba * v37->mapXSizeValue / 4;
                    aa = uIDa * v37->mapYSizeValue / 4;
                }
                v22 += 12;
                v17 = __OFSUB__(uIDa + 1, 4);
                v16 = uIDa++ - 3 < 0;
            }
            while ( v16 ^ v17 );
            v21 = v22;
            v17 = __OFSUB__(ba + 1, 4);
            v16 = ba++ - 3 < 0;
        }
        while ( v16 ^ v17 );
        v25 = v37->mapXSizeValue / 4 + v20 - 1;
        v26 = v37->mapYSizeValue / 4 + aa - 1;
        v27 = (unsigned __int8)((char)debug_rand(aCMsdevWorkA_52, 1072) % -4);
        if ( v27 )
        {
            if ( v27 == 1 )
            {
                cPoint.x = v20;
                cPoint.y = v26;
            }
            else
            {
                cPoint.x = v25;
                if ( v27 == 2 )
                    cPoint.y = v26;
                else
                    cPoint.y = aa;
            }
        }
        else
        {
            cPoint.x = v20;
            cPoint.y = aa;
        }
    }
    v28 = (double)cPoint.y;
    *uX = (double)cPoint.x;
    result = (RGE_Static_Object *)1;
    *uY = v28;
    return result;
}

//----- (004D9110) --------------------------------------------------------
BOOL TribeInformationAIModule::fullyExploredZone(int id)
{
    TribeInformationAIModule *v2; // esi@1
    RGE_Static_Object *v3; // eax@1

    v2 = this;
    v3 = MainDecisionAIModule::object((MainDecisionAIModule *)&this->md->vfptr, id);
    return v3 && !v2->fullyExploredZoneValue[(unsigned __int8)RGE_Static_Object::currentZone(v3)];
}

//----- (004D9160) --------------------------------------------------------
void TribeInformationAIModule::setFullyExploredZone(int id, int v)
{
    TribeInformationAIModule *v3; // esi@1
    RGE_Static_Object *v4; // eax@1

    v3 = this;
    v4 = MainDecisionAIModule::object((MainDecisionAIModule *)&this->md->vfptr, id);
    if ( v4 )
        v3->fullyExploredZoneValue[(unsigned __int8)RGE_Static_Object::currentZone(v4)] = v;
}

//----- (004D91A0) --------------------------------------------------------
BOOL TribeInformationAIModule::tileUncovered(int x, int y)
{
    return x >= 0
            && y >= 0
            && x < this->mapXSizeValue
            && y < this->mapYSizeValue
            && InfluenceMap::lookupValue(&this->pathMap, x, y) != 255;
}

//----- (004D91F0) --------------------------------------------------------
void TribeInformationAIModule::setTileExplored(int x, int y)
{
    if ( x >= 0 && y >= 0 && x < this->mapXSizeValue && y < this->mapYSizeValue )
        InfluenceMap::setValue(&this->pathMap, x, y, 0);
}

//----- (004D9230) --------------------------------------------------------
int __stdcall TribeInformationAIModule::ownerOfGameID(int id)
{
    return -1;
}

//----- (004D9240) --------------------------------------------------------
int TribeInformationAIModule::gameIDOfResourceObject(int rType, int gathererID, float *roXPos, float *roYPos, int *dropsiteID, int *exclusions, int numExclusions)
{
    TribeInformationAIModule *v8; // esi@1
    RGE_Static_Object *v9; // eax@1
    RGE_Static_Object *v10; // edi@1
    int v11; // ebx@2
    ResourceMemory *v12; // edi@2
    int v13; // edx@3
    int v14; // edx@4
    char v15; // al@4
    char v16; // cl@5
    signed int v17; // ebp@8
    int v18; // eax@8
    int *v19; // ecx@9
    RGE_Static_Object *v20; // eax@15
    RGE_Static_Object *v21; // edi@15
    __int16 v22; // ax@19
    __int16 v23; // ax@23
    int v24; // eax@26
    int v25; // ebp@26
    unsigned int v26; // eax@28
    int v27; // ebp@28
    __int16 v28; // ax@33
    TribeMainDecisionAIModule *v29; // eax@42
    int v30; // ecx@45
    int v31; // eax@45
    int v32; // ebx@57
    int v33; // eax@59
    int v34; // ecx@64
    bool v35; // sf@64
    unsigned __int8 v36; // of@64
    int v38; // [sp+10h] [bp-24h]@3
    ResourceMemory *bestObject; // [sp+14h] [bp-20h]@2
    int bestValue; // [sp+18h] [bp-1Ch]@2
    int fishingBoat; // [sp+1Ch] [bp-18h]@2
    int i; // [sp+20h] [bp-14h]@2
    int updateResourceDist; // [sp+24h] [bp-10h]@2
    int gathererX; // [sp+28h] [bp-Ch]@2
    int gathererY; // [sp+2Ch] [bp-8h]@2
    RGE_Static_Object *gathererObj; // [sp+30h] [bp-4h]@1
    char gathererIDa; // [sp+3Ch] [bp+8h]@2

    v8 = this;
    *dropsiteID = -1;
    v9 = MainDecisionAIModule::object((MainDecisionAIModule *)&this->md->vfptr, gathererID);
    v10 = v9;
    gathererObj = v9;
    if ( !v9 )
        return -1;
    gathererIDa = RGE_Static_Object::currentZone(v9);
    gathererX = (signed __int64)v10->world_x;
    gathererY = (signed __int64)v10->world_y;
    v11 = rType;
    fishingBoat = TribeInformationAIModule::isBoat(v10);
    v12 = 0;
    bestValue = -1;
    bestObject = 0;
    updateResourceDist = 0;
    i = 0;
    if ( v8->numResources[rType] <= 0 )
        goto LABEL_66;
    v13 = 0;
    v38 = 0;
    do
    {
        v14 = (int)&v8->resources[v11]->id + v13;
        v15 = *(_BYTE *)(v14 + 13);
        if ( v15 == 1 )
            goto LABEL_64;
        v16 = *(_BYTE *)(v14 + 12);
        if ( v16 )
        {
            if ( !v15 )
                *(_BYTE *)(v14 + 12) = v16 - 1;
        }
        else
        {
            v17 = 0;
            v18 = 0;
            if ( numExclusions > 0 )
            {
                v19 = exclusions;
                while ( *v19 != *(_DWORD *)v14 )
                {
                    ++v18;
                    ++v19;
                    if ( v18 >= numExclusions )
                        goto LABEL_14;
                }
                v17 = 1;
            }
LABEL_14:
            if ( v17 != 1 )
            {
                v20 = MainDecisionAIModule::object((MainDecisionAIModule *)&v8->md->vfptr, *(_DWORD *)v14);
                v21 = v20;
                if ( v20 )
                {
                    if ( fishingBoat != 1 || (v22 = v20->master_obj->object_group, v22 == 5) || v22 == 31 || v22 == 33 )
                    {
                        if ( fishingBoat || (v23 = v21->master_obj->object_group, v23 != 5) && v23 != 31 && v23 != 33 )
                        {
                            v24 = (int)&v8->resources[v11][v38].id;
                            v25 = (gathererY - *(_BYTE *)(v24 + 5)) * (gathererY - *(_BYTE *)(v24 + 5))
                                    + (gathererX - *(_BYTE *)(v24 + 4)) * (gathererX - *(_BYTE *)(v24 + 4))
                                    + 10 * *(_DWORD *)(v24 + 8);
                            if ( v21->master_obj->id == 59 )
                            {
                                if ( *(_BYTE *)(v24 + 14) > 0x14u )
                                    goto LABEL_64;
                                v26 = (signed int)(458129845 * (unsigned __int64)*(_BYTE *)(v24 + 6) >> 32) >> 4;
                                v27 = (v26 >> 31) + v26 + v25;
                                if ( TribeTacticalAIModule::numberGatherersWithTarget(&v8->md->tacticalAI, v21->id) > 2 )
                                    v27 += 200;
                            }
                            else
                            {
                                v27 = *(_BYTE *)(v24 + 6) / 50 + v25;
                            }
                            if ( !bestObject || v27 < bestValue )
                            {
                                v28 = v21->master_obj->object_group;
                                if ( (v28 == 9 || v28 == 10) && v21->object_state > 2u && v21->attribute_amount_held > 25.0 )
                                    v27 += 25;
                                if ( TribeInformationAIModule::withinXTilesOfEnemyTowncenter(v8, v21, 25) != 1 )
                                {
                                    if ( TribeInformationAIModule::withinXTilesOfAttackOnPlayer(v8, v21, 15, v8->md->player->id) == 1 )
                                        v27 += 500;
                                    if ( v21->master_obj->id == 50 )
                                    {
                                        v29 = v8->md;
                                        if ( v21->owner->id != v29->player->id
                                            || v21->object_state != 2
                                            || TribeTacticalAIModule::numberGatherersWithTarget(&v29->tacticalAI, v21->id) > 0 )
                                        {
                                            goto LABEL_64;
                                        }
                                        v30 = v8->farmsTaskedThisUpdate.numberValue;
                                        v31 = 0;
                                        if ( v30 > 0 )
                                        {
                                            do
                                            {
                                                if ( v31 >= v8->farmsTaskedThisUpdate.maximumSizeValue )
                                                    break;
                                                if ( v8->farmsTaskedThisUpdate.value[v31] == v21->id )
                                                    goto LABEL_63;
                                                ++v31;
                                            }
                                            while ( v31 < v30 );
                                            v11 = rType;
                                        }
                                    }
                                    if ( (v11 != 1 || TribeTacticalAIModule::numberGatherersWithTarget(&v8->md->tacticalAI, v21->id) <= 0)
                                        && (v11 != 3 && v11 != 2
                                         || TribeTacticalAIModule::numberGatherersWithTarget(&v8->md->tacticalAI, v21->id) <= 3) )
                                    {
                                        if ( v21->master_obj->id == 48 && v21->object_state == 2 )
                                        {
                                            v32 = TribeTacticalAIModule::strategicNumber(&v8->md->tacticalAI, 204);
                                            if ( TribeTacticalAIModule::actualGathererCountByRealResourceID(&v8->md->tacticalAI, 0) < v32 )
                                            {
LABEL_63:
                                                v11 = rType;
                                                goto LABEL_64;
                                            }
                                            v11 = rType;
                                        }
                                        v33 = (int)&v8->resources[v11][v38].id;
                                        if ( gathererIDa == RGE_Static_Object::lookupZone(
                                                                                    gathererObj,
                                                                                    *(_BYTE *)(v33 + 4),
                                                                                    *(_BYTE *)(v33 + 5))
                                            && (!bestObject || v27 < bestValue) )
                                        {
                                            bestObject = &v8->resources[v11][v38];
                                            bestValue = v27;
                                            *roXPos = v21->world_x;
                                            *roYPos = v21->world_y;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                else
                {
                    v8->resources[v11][v38].gone = 1;
                    if ( v8->closestDropsiteResourceID[v11] == v8->resources[v11][v38].id )
                        updateResourceDist = 1;
                }
            }
        }
LABEL_64:
        v34 = v8->numResources[v11];
        v13 = v38 * 20 + 20;
        v36 = __OFSUB__(i + 1, v34);
        v35 = i++ + 1 - v34 < 0;
        ++v38;
    }
    while ( v35 ^ v36 );
    v12 = bestObject;
LABEL_66:
    if ( updateResourceDist == 1 )
        TribeInformationAIModule::updateResourceDropsites(v8, v11);
    if ( v12 )
    {
        ++v12->gatherAttempts;
        *dropsiteID = v12->dropsiteID;
        return v12->id;
    }
    return -1;
}

//----- (004D96B0) --------------------------------------------------------
int TribeInformationAIModule::gameIDsOfObjectType(int oType, int **objects, int **owners, int ownerNumber)
{
    TribeInformationAIModule *v5; // esi@1
    int v6; // ebp@1
    int v7; // ebx@3
    int *v8; // edi@3
    int j; // eax@4
    RGE_Static_Object *v10; // edi@8
    int *v11; // ebx@19
    int *v12; // edi@19
    int v13; // eax@20
    char *v14; // ecx@21
    int v15; // ebx@29
    int *v16; // edi@29
    int k; // eax@30
    int maxCount; // [sp+8h] [bp-10h]@1
    int count; // [sp+Ch] [bp-Ch]@1
    RGE_Static_Object *tempObj; // [sp+10h] [bp-8h]@8
    int i; // [sp+14h] [bp-4h]@1

    v5 = this;
    v6 = 0;
    *objects = 0;
    count = 0;
    *owners = 0;
    maxCount = 10;
    for ( i = 0; v6 < v5->importantObjects.numberValue; i = v6 )
    {
        if ( v6 > v5->importantObjects.maximumSizeValue - 1 )
        {
            v7 = v6 + 1;
            v8 = (int *)operator new(4 * v6 + 4);
            if ( v8 )
            {
                for ( j = 0; j < v5->importantObjects.maximumSizeValue; v8[j - 1] = v5->importantObjects.value[j - 1] )
                {
                    if ( j >= v7 )
                        break;
                    ++j;
                }
                operator delete(v5->importantObjects.value);
                v5->importantObjects.value = v8;
                v5->importantObjects.maximumSizeValue = v7;
            }
        }
        v10 = RGE_Game_World::object(v5->md->aiPlayer->world, v5->importantObjects.value[v6]);
        tempObj = v10;
        if ( v10
            && (ownerNumber != -5 || v5->md->aiPlayer->id != v10->owner->id)
            && (ownerNumber != -6 || !(*(int (__stdcall **)(_DWORD))&v5->md->aiPlayer->vfptr->gap4[20])(v10->owner->id))
            && (ownerNumber == -1 || v10->owner->id == ownerNumber)
            && (oType == -1 || oType == v10->master_obj->id) )
        {
            if ( count == maxCount || !*objects )
            {
                v11 = (int *)operator new(8 * maxCount);
                v12 = (int *)operator new(8 * maxCount);
                if ( *objects )
                {
                    v13 = 0;
                    if ( maxCount > 0 )
                    {
                        do
                        {
                            v14 = (char *)&v12[v13++];
                            *(_DWORD *)&v14[(char *)v11 - (char *)v12] = (*objects)[v13 - 1];
                            *(_DWORD *)v14 = (*owners)[v13 - 1];
                        }
                        while ( v13 < maxCount );
                        v6 = i;
                    }
                }
                maxCount *= 2;
                if ( *objects )
                    operator delete(*objects);
                if ( *owners )
                    operator delete(*owners);
                *objects = v11;
                *owners = v12;
                v10 = tempObj;
            }
            if ( v6 > v5->importantObjects.maximumSizeValue - 1 )
            {
                v15 = v6 + 1;
                v16 = (int *)operator new(4 * v6 + 4);
                if ( v16 )
                {
                    for ( k = 0; k < v5->importantObjects.maximumSizeValue; v16[k - 1] = v5->importantObjects.value[k - 1] )
                    {
                        if ( k >= v15 )
                            break;
                        ++k;
                    }
                    operator delete(v5->importantObjects.value);
                    v5->importantObjects.value = v16;
                    v5->importantObjects.maximumSizeValue = v15;
                }
                v10 = tempObj;
            }
            (*objects)[count++] = v5->importantObjects.value[v6];
            (*owners)[count - 1] = v10->owner->id;
        }
        ++v6;
    }
    return count;
}

//----- (004D9970) --------------------------------------------------------
int TribeInformationAIModule::gameIDsOwnedBy(int oType, int **objects, int ownerNumber)
{
    void **v4; // esi@1
    TribeInformationAIModule *v5; // ebp@1
    int v6; // ebx@1
    signed int v7; // edi@1
    RGE_Static_Object *v8; // eax@4
    _DWORD *v9; // ebx@10
    signed int i; // eax@11
    int v11; // ecx@17
    bool v12; // sf@17
    unsigned __int8 v13; // of@17
    int count; // [sp+10h] [bp-8h]@1
    int v16; // [sp+14h] [bp-4h]@2
    int **objectsa; // [sp+20h] [bp+8h]@1

    v4 = (void **)objects;
    v5 = this;
    v6 = 0;
    *objects = 0;
    count = 0;
    v7 = 10;
    objectsa = 0;
    if ( this->maxImportantObjectMemory > 0 )
    {
        v16 = 0;
        do
        {
            if ( *(int *)((char *)&v5->importantObjectMemory->id + v6) != -1 )
            {
                v8 = RGE_Game_World::object(v5->md->aiPlayer->world, *(int *)((char *)&v5->importantObjectMemory->id + v6));
                if ( v8 )
                {
                    if ( v8->owner->id == ownerNumber && (oType == -1 || oType == *(&v5->importantObjectMemory->owner + v6)) )
                    {
                        if ( count == v7 || !*v4 )
                        {
                            v9 = operator new(8 * v7);
                            if ( *v4 )
                            {
                                for ( i = 0; i < v7; v9[i - 1] = *((_DWORD *)*v4 + i - 1) )
                                    ++i;
                            }
                            v7 *= 2;
                            if ( *v4 )
                                operator delete(*v4);
                            *v4 = v9;
                            v6 = v16;
                        }
                        *((_DWORD *)*v4 + count++) = *(int *)((char *)&v5->importantObjectMemory->id + v6);
                    }
                }
            }
            v11 = v5->maxImportantObjectMemory;
            v6 += 36;
            v13 = __OFSUB__((char *)objectsa + 1, v11);
            v12 = (signed int)objectsa + -v11 + 1 < 0;
            objectsa = (int **)((char *)objectsa + 1);
            v16 = v6;
        }
        while ( v12 ^ v13 );
    }
    return count;
}

//----- (004D9A90) --------------------------------------------------------
int TribeInformationAIModule::numberGameIDsOwnedBy(int oType, int ownerNumber)
{
    TribeInformationAIModule *v3; // esi@1
    int v4; // edi@1
    int v5; // ebx@1
    RGE_Static_Object *v6; // eax@3
    int count; // [sp+Ch] [bp-4h]@1

    v3 = this;
    v4 = 0;
    v5 = 0;
    for ( count = 0; v5 < v3->maxImportantObjectMemory; ++v4 )
    {
        if ( v3->importantObjectMemory[v4].id != -1 )
        {
            v6 = RGE_Game_World::object(v3->md->aiPlayer->world, v3->importantObjectMemory[v4].id);
            if ( v6 )
            {
                if ( v6->owner->id == ownerNumber && (oType == -1 || oType == v3->importantObjectMemory[v4].owner) )
                    ++count;
            }
        }
        ++v5;
    }
    return count;
}

//----- (004D9B20) --------------------------------------------------------
void TribeInformationAIModule::placeDock(BuildItem *bi, float cX, float cY, int centerType, int edgeType)
{
    TribeMainDecisionAIModule *v6; // edx@1
    TRIBE_Player *v7; // eax@1
    RGE_Player *v8; // edx@1
    RGE_Visible_Map *v9; // ebx@1
    RGE_Map *v10; // esi@1
    int v11; // edi@1
    int v12; // esi@2
    int v13; // ebx@10
    double v14; // st6@12
    double v15; // rt0@12
    double v16; // st6@12
    float v17; // ST34_4@13
    float v18; // ST1C_4@12
    float v19; // ST18_4@12
    double v20; // st6@13
    double v21; // st7@13
    int v22; // ST30_4@13
    char *v23; // ebx@13
    signed int v24; // ecx@17
    double v25; // st7@18
    ConstructionItem *v26; // edi@27
    char *v27; // ST1C_4@28
    int v28; // ST18_4@28
    float zs; // ST14_4@28
    float ys; // ST10_4@28
    float xs; // ST0C_4@28
    float v32; // ST04_4@28
    float v33; // ST00_4@28
    int y; // [sp+30h] [bp-140h]@2
    int ya; // [sp+30h] [bp-140h]@12
    float cD; // [sp+34h] [bp-13Ch]@13
    TribeInformationAIModule *v37; // [sp+38h] [bp-138h]@1
    int bXTile; // [sp+3Ch] [bp-134h]@1
    RGE_Visible_Map *vMap; // [sp+40h] [bp-130h]@1
    RGE_Zone_Map *zoneMap; // [sp+44h] [bp-12Ch]@1
    float bD; // [sp+48h] [bp-128h]@1
    int bYTile; // [sp+4Ch] [bp-124h]@1
    signed int randSelect; // [sp+50h] [bp-120h]@1
    int x; // [sp+54h] [bp-11Ch]@1
    char currentZone; // [sp+58h] [bp-118h]@10
    RGE_Map *gMap; // [sp+5Ch] [bp-114h]@1
    int tempInt; // [sp+60h] [bp-110h]@1
    char zoneCounter[256]; // [sp+64h] [bp-10Ch]@1
    int v49; // [sp+16Ch] [bp-4h]@27

    v6 = this->md;
    v7 = v6->aiPlayer;
    v8 = v6->player;
    v9 = v7->visible;
    v37 = this;
    v10 = v7->world->map;
    vMap = v7->visible;
    memset(zoneCounter, 0xFFu, sizeof(zoneCounter));
    gMap = v10;
    bXTile = -1;
    bYTile = -1;
    bD = -1.0;
    zoneMap = RGE_Zone_Map_List::get_zone_map(
                            v10->map_zones,
                            v8->world->terrains[*(_WORD *)(*((_DWORD *)v8->master_objects + 19) + 102)],
                            v8->world->terrain_size,
                            &tempInt);
    v11 = 1;
    x = 1;
    for ( randSelect = debug_rand(aCMsdevWorkA_52, 1705) % 50; v11 < v9->widthValue - 2; x = v11 )
    {
        v12 = 1;
        for ( y = 1; v12 < v9->heightValue - 2; y = v12 )
        {
            if ( RGE_Visible_Map::get_visible(v9, v11, v12)
                && v11 - 1 >= 0
                && v12 - 1 >= 0
                && v11 + 1 <= v9->widthValue - 1
                && v12 + 1 <= v9->heightValue - 1
                && (centerType == -1 || (*((_BYTE *)&gMap->map_row_offset[v12][v11] + 5) & 0x1F) == centerType) )
            {
                currentZone = RGE_Zone_Map::get_zone_info(zoneMap, v11, v12);
                v13 = RGE_Zone_Map::numberTilesInZone(zoneMap, currentZone);
                if ( v13 >= TribeTacticalAIModule::strategicNumber(&v37->md->tacticalAI, 112) )
                {
                    if ( TribeInformationAIModule::hasAdjacentTileType(v37, v11, v12, edgeType) )
                    {
                        v14 = (double)y;
                        *(float *)&ya = v14;
                        v15 = v14 - -0.5;
                        v16 = (double)x;
                        v18 = v15;
                        v19 = v16 - -0.5;
                        if ( !ConstructionAIModule::randomLot((ConstructionAIModule *)&v37->md->constructionAI.vfptr, v19, v18) )
                        {
                            v17 = v16;
                            v20 = v17 - cX;
                            v21 = *(float *)&ya - cY;
                            *(float *)&v22 = v20;
                            v23 = &zoneCounter[(unsigned __int8)currentZone];
                            cD = v20 * *(float *)&v22 + v21 * v21;
                            if ( zoneCounter[(unsigned __int8)currentZone] == -1 )
                                *v23 = TribeInformationAIModule::numberDocksInZone(v37, (unsigned __int8)currentZone, zoneMap);
                            if ( *v23 )
                                cD = (double)(1000 * (unsigned __int8)*v23) + cD;
                            v24 = TribeInformationAIModule::closestDockDistance(v37, v11, v12);
                            if ( v24 == -1 )
                                v25 = cD;
                            else
                                v25 = (double)(100000 / v24) + cD;
                            if ( bXTile == -1 || v25 < (double)randSelect + bD )
                            {
                                bD = v25;
                                bXTile = v11;
                                bYTile = v12;
                            }
                        }
                    }
                }
                v9 = vMap;
            }
            ++v12;
        }
        ++v11;
    }
    if ( bXTile != -1 )
    {
        v26 = (ConstructionItem *)operator new(0x80u);
        v49 = 0;
        if ( v26 )
        {
            v27 = BaseItem::name((BaseItem *)&bi->vfptr);
            v28 = BaseItem::typeID((BaseItem *)&bi->vfptr);
            zs = BaseItem::zSize((BaseItem *)&bi->vfptr);
            ys = BaseItem::ySize((BaseItem *)&bi->vfptr);
            xs = BaseItem::xSize((BaseItem *)&bi->vfptr);
            v32 = (double)bYTile - -0.5;
            v33 = (double)bXTile - -0.5;
            ConstructionItem::ConstructionItem(v26, v33, v32, 0.0, xs, ys, zs, v28, v27);
        }
    }
}

//----- (004D9EC0) --------------------------------------------------------
int TribeInformationAIModule::numberDocksInZone(int zone, RGE_Zone_Map *zoneMap)
{
    TribeInformationAIModule *v3; // esi@1
    int v4; // ebx@1
    int v5; // ebp@3
    int *v6; // edi@3
    int i; // eax@4
    RGE_Static_Object *v8; // eax@8
    int count; // [sp+8h] [bp-8h]@1

    v3 = this;
    v4 = 0;
    for ( count = 0; v4 < v3->playerBuildings.numberValue; ++v4 )
    {
        if ( v4 > v3->playerBuildings.maximumSizeValue - 1 )
        {
            v5 = v4 + 1;
            v6 = (int *)operator new(4 * v4 + 4);
            if ( v6 )
            {
                for ( i = 0; i < v3->playerBuildings.maximumSizeValue; v6[i - 1] = v3->playerBuildings.value[i - 1] )
                {
                    if ( i >= v5 )
                        break;
                    ++i;
                }
                operator delete(v3->playerBuildings.value);
                v3->playerBuildings.value = v6;
                v3->playerBuildings.maximumSizeValue = v5;
            }
        }
        v8 = MainDecisionAIModule::object((MainDecisionAIModule *)&v3->md->vfptr, v3->playerBuildings.value[v4]);
        if ( v8
            && v8->master_obj->id == 45
            && (unsigned __int8)RGE_Zone_Map::get_zone_info(zoneMap, (signed __int64)v8->world_x, (signed __int64)v8->world_y) == zone )
        {
            ++count;
        }
    }
    return count;
}

//----- (004D9FC0) --------------------------------------------------------
int TribeInformationAIModule::closestDockDistance(int x, int y)
{
    TribeInformationAIModule *v3; // esi@1
    int v4; // ebp@1
    int v5; // ebx@3
    int *v6; // edi@3
    int i; // eax@4
    RGE_Static_Object *v8; // eax@8
    int v9; // edi@10
    signed __int64 v10; // rax@10
    int distance; // [sp+8h] [bp-8h]@1

    v3 = this;
    v4 = 0;
    for ( distance = -1; v4 < v3->playerBuildings.numberValue; ++v4 )
    {
        if ( v4 > v3->playerBuildings.maximumSizeValue - 1 )
        {
            v5 = v4 + 1;
            v6 = (int *)operator new(4 * v4 + 4);
            if ( v6 )
            {
                for ( i = 0; i < v3->playerBuildings.maximumSizeValue; v6[i - 1] = v3->playerBuildings.value[i - 1] )
                {
                    if ( i >= v5 )
                        break;
                    ++i;
                }
                operator delete(v3->playerBuildings.value);
                v3->playerBuildings.value = v6;
                v3->playerBuildings.maximumSizeValue = v5;
            }
        }
        v8 = MainDecisionAIModule::object((MainDecisionAIModule *)&v3->md->vfptr, v3->playerBuildings.value[v4]);
        if ( v8 )
        {
            if ( v8->master_obj->id == 45 )
            {
                v9 = x - (unsigned __int64)(signed __int64)v8->world_x;
                v10 = (signed __int64)sqrt((double)(signed int)((y - (unsigned __int64)(signed __int64)v8->world_y)
                                                                                                            * (y - (unsigned __int64)(signed __int64)v8->world_y)
                                                                                                            + v9 * v9));
                if ( (_DWORD)v10 )
                {
                    if ( distance == -1 || distance > (signed int)v10 )
                        distance = v10;
                }
            }
        }
    }
    return distance;
}

//----- (004DA0E0) --------------------------------------------------------
int TribeInformationAIModule::hasAdjacentTileType(int x, int y, int aType)
{
    int v4; // eax@1
    RGE_Game_World *v5; // edx@1
    int v6; // ecx@1
    int v7; // edi@1
    RGE_Map *v8; // esi@1

    v4 = x;
    v5 = this->md->aiPlayer->world;
    v6 = y;
    v7 = 0;
    v8 = v5->map;
    while ( 1 )
    {
        switch ( v7 )
        {
            case 0:
                v6 = y;
                v4 = x - 1;
                goto LABEL_4;
            case 7:
LABEL_4:
                --v6;
                break;
            case 1:
            case 2:
                ++v4;
                break;
            case 3:
            case 4:
                ++v6;
                break;
            case 5:
            case 6:
                --v4;
                break;
            default:
                break;
        }
        if ( v4 >= 0
            && v6 >= 0
            && v4 <= v8->map_width - 1
            && v6 <= v8->map_height - 1
            && (*((_BYTE *)&v8->map_row_offset[v6][v4] + 5) & 0x1F) == aType )
        {
            return 1;
        }
        if ( ++v7 >= 8 )
            return 0;
    }
}

//----- (004DA190) --------------------------------------------------------
int TribeInformationAIModule::mapXSize()
{
    if ( this->mapXSizeValue == -1 )
        this->mapXSizeValue = this->md->aiPlayer->world->map->map_width;
    return this->mapXSizeValue;
}

//----- (004DA1C0) --------------------------------------------------------
int TribeInformationAIModule::mapYSize()
{
    if ( this->mapYSizeValue == -1 )
        this->mapYSizeValue = this->md->aiPlayer->world->map->map_height;
    return this->mapYSizeValue;
}

//----- (004DA1F0) --------------------------------------------------------
void TribeInformationAIModule::addEnemyInfluences(int ownerID, int targetID)
{
    TribeInformationAIModule *v3; // ebp@1
    int v4; // eax@1
    int v5; // eax@3
    int v6; // eax@4
    RGE_Static_Object *v7; // eax@5
    RGE_Static_Object *v8; // ebx@5
    int v9; // edi@6
    int v10; // esi@7
    int v11; // eax@7
    int v12; // eax@9
    float *v13; // esi@14
    double v14; // st7@15
    float *v15; // esi@15
    int v16; // edi@15
    int v17; // esi@16
    int v18; // eax@16
    int v19; // eax@18
    int v20; // edx@23
    bool v21; // sf@23
    unsigned __int8 v22; // of@23
    int v23; // [sp+4h] [bp-28h]@2
    int i; // [sp+8h] [bp-24h]@1
    XYPoint maxLOS; // [sp+Ch] [bp-20h]@6
    XYPoint maxRange; // [sp+14h] [bp-18h]@15
    XYPoint minLOS; // [sp+1Ch] [bp-10h]@6
    XYPoint minRange; // [sp+24h] [bp-8h]@15

    v3 = this;
    v4 = 0;
    i = 0;
    if ( this->maxImportantObjectMemory > 0 )
    {
        v23 = 0;
        do
        {
            v5 = (int)&v3->importantObjectMemory->id + v4;
            if ( *(_BYTE *)(v5 + 11) == ownerID )
            {
                v6 = *(_DWORD *)v5;
                if ( v6 != targetID )
                {
                    v7 = MainDecisionAIModule::object((MainDecisionAIModule *)&v3->md->vfptr, v6);
                    v8 = v7;
                    if ( v7 )
                    {
                        minLOS.x = (signed __int64)(v7->world_x - v7->master_obj->los);
                        minLOS.y = (signed __int64)(v7->world_y - v7->master_obj->los);
                        TribeInformationAIModule::mapBound(v3, &minLOS);
                        maxLOS.x = (signed __int64)(v8->master_obj->los + v8->world_x);
                        maxLOS.y = (signed __int64)(v8->master_obj->los + v8->world_y);
                        TribeInformationAIModule::mapBound(v3, &maxLOS);
                        v9 = minLOS.x;
                        if ( minLOS.x <= maxLOS.x )
                        {
                            v10 = minLOS.y;
                            v11 = maxLOS.y;
                            do
                            {
                                if ( v10 <= v11 )
                                {
                                    do
                                    {
                                        v12 = (unsigned __int8)PathingSystem::lookupMisc(&aiPathSystem, v9, v10) + 10;
                                        if ( v12 > 255 )
                                            LOBYTE(v12) = -1;
                                        PathingSystem::setMisc(&aiPathSystem, v9, v10, v12);
                                        v11 = maxLOS.y;
                                        ++v10;
                                    }
                                    while ( v10 <= maxLOS.y );
                                    v10 = minLOS.y;
                                }
                                ++v9;
                            }
                            while ( v9 <= maxLOS.x );
                        }
                        v13 = &v3->importantObjectMemory[v23].range;
                        if ( *v13 > 1.0 )
                        {
                            v14 = v8->world_y;
                            minRange.x = (signed __int64)(v8->world_x - *v13);
                            minRange.y = (signed __int64)(v14 - *v13);
                            TribeInformationAIModule::mapBound(v3, &minRange);
                            v15 = &v3->importantObjectMemory[v23].range;
                            maxRange.x = (signed __int64)(*v15 + v8->world_x);
                            maxRange.y = (signed __int64)(*v15 + v8->world_y);
                            TribeInformationAIModule::mapBound(v3, &maxRange);
                            v16 = minRange.x;
                            if ( minRange.x <= maxRange.x )
                            {
                                v17 = minRange.y;
                                v18 = maxRange.y;
                                do
                                {
                                    if ( v17 <= v18 )
                                    {
                                        do
                                        {
                                            v19 = (unsigned __int8)PathingSystem::lookupMisc(&aiPathSystem, v16, v17) + 10;
                                            if ( v19 > 255 )
                                                LOBYTE(v19) = -1;
                                            PathingSystem::setMisc(&aiPathSystem, v16, v17, v19);
                                            v18 = maxRange.y;
                                            ++v17;
                                        }
                                        while ( v17 <= maxRange.y );
                                        v17 = minRange.y;
                                    }
                                    ++v16;
                                }
                                while ( v16 <= maxRange.x );
                            }
                        }
                    }
                }
            }
            v20 = v3->maxImportantObjectMemory;
            v4 = v23 * 36 + 36;
            v22 = __OFSUB__(i + 1, v20);
            v21 = i++ + 1 - v20 < 0;
            ++v23;
        }
        while ( v21 ^ v22 );
    }
}

//----- (004DA420) --------------------------------------------------------
void TribeInformationAIModule::addPriorAttackInfluences(int ownerID, int targetID)
{
    TribeInformationAIModule *v3; // ebx@1
    int v4; // ebp@1
    int v5; // eax@2
    int v6; // eax@5
    int v7; // edi@5
    int v8; // eax@6
    int v9; // esi@7
    int v10; // edi@10
    int v11; // esi@11
    int v12; // eax@11
    int i; // [sp+8h] [bp-14h]@1
    XYPoint max; // [sp+Ch] [bp-10h]@5
    XYPoint min; // [sp+14h] [bp-8h]@5

    v3 = this;
    v4 = 0;
    for ( i = 0; i < v3->maxAttackMemories; ++i )
    {
        v5 = (int)&v3->attackMemories[v4].id;
        if ( *(_DWORD *)v5 != -1 && *(_BYTE *)(v5 + 10) == ownerID && *(_BYTE *)(v5 + 9) == v3->md->player->id )
        {
            min.x = *(_BYTE *)(v5 + 5);
            min.y = *(_BYTE *)(v5 + 6);
            TribeInformationAIModule::mapBound(v3, &min);
            v6 = (int)&v3->attackMemories[v4].id;
            max.x = *(_BYTE *)(v6 + 7);
            max.y = *(_BYTE *)(v6 + 8);
            TribeInformationAIModule::mapBound(v3, &max);
            v7 = min.x;
            if ( min.x <= max.x )
            {
                v8 = max.y;
                do
                {
                    v9 = min.y;
                    if ( min.y <= v8 )
                    {
                        do
                        {
                            PathingSystem::setMisc(&aiPathSystem, v7, v9, 75);
                            v8 = max.y;
                            ++v9;
                        }
                        while ( v9 <= max.y );
                    }
                    ++v7;
                }
                while ( v7 <= max.x );
            }
            min.x -= 5;
            min.y -= 5;
            TribeInformationAIModule::mapBound(v3, &min);
            max.x += 5;
            max.y += 5;
            TribeInformationAIModule::mapBound(v3, &max);
            v10 = min.x;
            if ( min.x <= max.x )
            {
                v11 = min.y;
                v12 = max.y;
                do
                {
                    if ( v11 <= v12 )
                    {
                        do
                        {
                            PathingSystem::setMisc(&aiPathSystem, v10, v11, 15);
                            v12 = max.y;
                            ++v11;
                        }
                        while ( v11 <= max.y );
                        v11 = min.y;
                    }
                    ++v10;
                }
                while ( v10 <= max.x );
            }
        }
        ++v4;
    }
}

//----- (004DA5A0) --------------------------------------------------------
ObjectMemory *TribeInformationAIModule::objectMemory(int id)
{
    int v2; // edx@2
    int v3; // eax@2
    ObjectMemory *v4; // edi@3
    ObjectMemory *v5; // ecx@3
    ObjectMemory *result; // eax@6

    if ( id == -1 || (v2 = this->maxImportantObjectMemory, v3 = 0, v2 <= 0) )
    {
        result = 0;
    }
    else
    {
        v4 = this->importantObjectMemory;
        v5 = this->importantObjectMemory;
        while ( v5->id != id )
        {
            ++v3;
            ++v5;
            if ( v3 >= v2 )
                return 0;
        }
        result = &v4[v3];
    }
    return result;
}

//----- (004DA5F0) --------------------------------------------------------
ObjectMemory *TribeInformationAIModule::addObjectMemory@<eax>(TribeInformationAIModule *this@<ecx>, double a2@<st0>, RGE_Static_Object *oObj)
{
    TribeInformationAIModule *v3; // ebp@1
    ObjectMemory *result; // eax@2
    RGE_Static_ObjectVtbl *v5; // edi@3
    RGE_Master_Static_Object *v6; // ebx@3
    float weaponRange; // ST30_4@3
    float rateOfFire; // ST2C_4@3
    float damageCapability; // ST28_4@3

    v3 = this;
    if ( oObj )
    {
        v5 = oObj->vfptr;
        v6 = oObj->master_obj;
        oObj->vfptr->weaponRange(oObj);
        weaponRange = a2;
        v5->rateOfFire(oObj);
        rateOfFire = a2;
        ((void (*)(RGE_Static_Object *))v5->damageCapability)(oObj);
        damageCapability = a2;
        result = TribeInformationAIModule::addObjectMemory(
                             v3,
                             oObj->id,
                             v6->id,
                             v6->object_group,
                             (signed __int64)oObj->world_x,
                             (signed __int64)oObj->world_y,
                             (signed __int64)oObj->world_z,
                             oObj->owner->id,
                             (signed __int64)oObj->hp,
                             0,
                             0,
                             damageCapability,
                             rateOfFire,
                             weaponRange,
                             oObj);
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (004DA680) --------------------------------------------------------
ObjectMemory *TribeInformationAIModule::addObjectMemory(int id, __int16 type, __int16 group, char x, char y, char z, char ownerID, __int16 hitPoints, int attackAttempts, char kills, float damageCapability, float rateOfFire, float weaponRange, RGE_Static_Object *object)
{
    TribeInformationAIModule *v15; // esi@1
    int v16; // ebp@1
    signed int v17; // edi@1
    int v18; // eax@1
    ObjectMemory *v19; // edx@2
    TribeMainDecisionAIModule *v20; // eax@9
    int v21; // ebp@9
    RGE_Player *v22; // ecx@12
    int v23; // eax@15
    char *v24; // ebp@18
    ObjectMemory *result; // eax@19
    int v26; // edi@20
    int v27; // eax@21
    int v28; // ecx@21
    int v29; // edx@22
    int v30; // eax@24
    int v31; // eax@26
    int v32; // edi@26
    int v33; // eax@27
    int v34; // ecx@28

    v15 = this;
    v16 = this->maxImportantObjectMemory;
    v17 = -1;
    v18 = 0;
    if ( v16 <= 0 )
    {
LABEL_8:
        if ( object )
        {
            v20 = this->md;
            v21 = BYTE1(v20->player->world[1].game_speed);
            if ( TribeTacticalAIModule::strategicNumber(&v20->tacticalAI, 201) == 1
                && (v21 == v15->md->player->id || v21 == 255) )
            {
                v22 = object->owner;
                if ( v22->id > 0 && !RGE_Player::computerPlayer(v22) && RGE_Base_Game::singlePlayerGame(rge_base_game) == 1 )
                {
                    v23 = TribeInformationAIModule::convertUnitToIntType(object);
                    if ( v23 != -1 )
                        ++v15->unitHistory[v23];
                }
            }
        }
        if ( v17 == -1 )
        {
            v24 = (char *)operator new(72 * v15->maxImportantObjectMemory);
            if ( v24 )
            {
                v26 = 0;
                if ( v15->maxImportantObjectMemory > 0 )
                {
                    v27 = 0;
                    v28 = (int)(v24 + 6);
                    do
                    {
                        ++v26;
                        v28 += 36;
                        v29 = v15->importantObjectMemory[v27].id;
                        ++v27;
                        *(_DWORD *)(v28 - 42) = v29;
                        *(_WORD *)(v28 - 38) = *((_WORD *)&v15->importantObjectMemory[v27] - 16);
                        *(_WORD *)(v28 - 36) = *((_WORD *)&v15->importantObjectMemory[v27] - 15);
                        *(_BYTE *)(v28 - 34) = *((_BYTE *)&v15->importantObjectMemory[v27] - 28);
                        *(_BYTE *)(v28 - 33) = *((_BYTE *)&v15->importantObjectMemory[v27] - 27);
                        *(_BYTE *)(v28 - 32) = *((_BYTE *)&v15->importantObjectMemory[v27] - 26);
                        *(_BYTE *)(v28 - 31) = *((_BYTE *)&v15->importantObjectMemory[v27] - 25);
                        *(_WORD *)(v28 - 30) = *((_WORD *)&v15->importantObjectMemory[v27] - 12);
                        *(_DWORD *)(v28 - 26) = *((_DWORD *)&v15->importantObjectMemory[v27] - 5);
                        *(_BYTE *)(v28 - 22) = *((_BYTE *)&v15->importantObjectMemory[v27] - 16);
                        *(_DWORD *)(v28 - 18) = *((_DWORD *)&v15->importantObjectMemory[v27] - 3);
                        *(_DWORD *)(v28 - 14) = *((_DWORD *)&v15->importantObjectMemory[v27] - 2);
                        *(_DWORD *)(v28 - 10) = *((_DWORD *)&v15->importantObjectMemory[v27] - 1);
                    }
                    while ( v26 < v15->maxImportantObjectMemory );
                }
                if ( v26 < 2 * v15->maxImportantObjectMemory )
                {
                    v30 = (int)&v24[36 * v26 + 6];
                    do
                    {
                        ++v26;
                        *(_DWORD *)(v30 - 6) = -1;
                        *(_WORD *)(v30 - 2) = -1;
                        *(_WORD *)v30 = -1;
                        *(_BYTE *)(v30 + 2) = 0;
                        *(_BYTE *)(v30 + 3) = 0;
                        *(_BYTE *)(v30 + 4) = 0;
                        *(_BYTE *)(v30 + 5) = 0;
                        *(_WORD *)(v30 + 6) = 0;
                        *(_DWORD *)(v30 + 10) = 0;
                        *(_BYTE *)(v30 + 14) = 0;
                        *(_DWORD *)(v30 + 18) = 0;
                        *(_DWORD *)(v30 + 22) = 0;
                        *(_DWORD *)(v30 + 26) = 0;
                        v30 += 36;
                    }
                    while ( v26 < 2 * v15->maxImportantObjectMemory );
                }
                operator delete(v15->importantObjectMemory);
                v31 = v15->maxImportantObjectMemory;
                v15->importantObjectMemory = (ObjectMemory *)v24;
                *(_DWORD *)&v24[36 * v31] = id;
                v15->importantObjectMemory[v15->maxImportantObjectMemory].type = type;
                v15->importantObjectMemory[v15->maxImportantObjectMemory].group = group;
                v15->importantObjectMemory[v15->maxImportantObjectMemory].x = x;
                v15->importantObjectMemory[v15->maxImportantObjectMemory].y = y;
                v15->importantObjectMemory[v15->maxImportantObjectMemory].z = z;
                v15->importantObjectMemory[v15->maxImportantObjectMemory].owner = ownerID;
                v15->importantObjectMemory[v15->maxImportantObjectMemory].hitPoints = hitPoints;
                v15->importantObjectMemory[v15->maxImportantObjectMemory].attackAttempts = attackAttempts;
                v15->importantObjectMemory[v15->maxImportantObjectMemory].kills = kills;
                v15->importantObjectMemory[v15->maxImportantObjectMemory].damageCapability = damageCapability;
                v15->importantObjectMemory[v15->maxImportantObjectMemory].rateOfFire = rateOfFire;
                v15->importantObjectMemory[v15->maxImportantObjectMemory].range = weaponRange;
                v32 = v15->maxImportantObjectMemory;
                v15->maxImportantObjectMemory = 2 * v32;
                result = &v15->importantObjectMemory[v32];
            }
            else
            {
                result = 0;
            }
        }
        else
        {
            v33 = v17;
            v15->importantObjectMemory[v33].id = id;
            v15->importantObjectMemory[v33].type = type;
            v15->importantObjectMemory[v33].group = group;
            v15->importantObjectMemory[v33].x = x;
            v15->importantObjectMemory[v33].y = y;
            v15->importantObjectMemory[v33].z = z;
            v15->importantObjectMemory[v33].owner = ownerID;
            v15->importantObjectMemory[v33].hitPoints = hitPoints;
            v15->importantObjectMemory[v33].attackAttempts = attackAttempts;
            v15->importantObjectMemory[v33].kills = kills;
            v15->importantObjectMemory[v33].damageCapability = damageCapability;
            v15->importantObjectMemory[v33].rateOfFire = rateOfFire;
            v15->importantObjectMemory[v33].range = weaponRange;
            result = &v15->importantObjectMemory[v17];
        }
    }
    else
    {
        v19 = this->importantObjectMemory;
        while ( v19->id != id )
        {
            if ( v19->id == -1 && v17 == -1 )
                v17 = v18;
            ++v18;
            ++v19;
            if ( v18 >= v16 )
                goto LABEL_8;
        }
        v34 = v18;
        v15->importantObjectMemory[v34].id = id;
        v15->importantObjectMemory[v34].type = type;
        v15->importantObjectMemory[v34].group = group;
        v15->importantObjectMemory[v34].x = x;
        v15->importantObjectMemory[v34].y = y;
        v15->importantObjectMemory[v34].z = z;
        v15->importantObjectMemory[v34].owner = ownerID;
        v15->importantObjectMemory[v34].hitPoints = hitPoints;
        v15->importantObjectMemory[v34].attackAttempts = attackAttempts;
        v15->importantObjectMemory[v34].kills = kills;
        v15->importantObjectMemory[v34].damageCapability = damageCapability;
        v15->importantObjectMemory[v34].rateOfFire = rateOfFire;
        v15->importantObjectMemory[v34].range = weaponRange;
        result = &v15->importantObjectMemory[v18];
    }
    return result;
}

//----- (004DABB0) --------------------------------------------------------
int TribeInformationAIModule::addImportantObject@<eax>(TribeInformationAIModule *this@<ecx>, double a2@<st0>, RGE_Static_Object *oObj, int addedFromAlliedCP)
{
    RGE_Static_Object *v4; // edi@1
    TribeInformationAIModule *v5; // esi@1
    RGE_Player *v6; // ecx@4
    RGE_Game_World *v7; // ebp@4
    signed int v8; // ebx@8
    RGE_Player *v9; // edi@11
    int v10; // eax@17
    int v11; // ecx@17
    int v12; // ebp@17
    int i; // eax@17
    int v14; // ebx@22
    int *v15; // edi@22
    int j; // eax@23
    int v17; // ecx@29
    int v18; // ebp@29
    int k; // eax@29
    int v20; // ebx@34
    int *v21; // edi@34
    int l; // eax@35
    int v23; // ecx@43
    int v24; // ebp@43
    int m; // eax@43
    int v26; // ebx@48
    int *v27; // edi@48
    int n; // eax@49
    int oType; // [sp+10h] [bp-4h]@3
    int addedFromAlliedCPa; // [sp+1Ch] [bp+8h]@17

    v4 = oObj;
    v5 = this;
    if ( !oObj )
        return 0;
    if ( oObj->id < 0 )
        return 0;
    oType = oObj->master_obj->object_group;
    if ( !TribeInformationAIModule::importantObject(oType) )
        return 0;
    v6 = v5->md->player;
    v7 = v6->world;
    if ( !addedFromAlliedCP && oObj->owner->id > 0 )
    {
        if ( (*(int (__stdcall **)(_DWORD))&v6->vfptr->gap4[20])(oObj->owner->id) )
        {
            if ( v7->player_num > 3 )
            {
                v8 = 1;
                if ( TribeTacticalAIModule::strategicNumber(&v5->md->tacticalAI, 194) == 1 && v7->player_num > 1 )
                {
                    do
                    {
                        if ( v8 != v5->md->player->id )
                        {
                            v9 = v7->players[v8];
                            if ( RGE_Player::computerPlayer(v9) )
                            {
                                if ( (*(int (__stdcall **)(signed int))&v5->md->player->vfptr->gap4[24])(v8)
                                    && (*(int (**)(RGE_Player *, _DWORD))&v9->vfptr->gap4[24])(v9, v5->md->player->id) )
                                {
                                    TribeInformationAIModule::addImportantObject(
                                        (TribeInformationAIModule *)(v9[1].position_checksum + 3308),
                                        oObj,
                                        1);
                                }
                            }
                        }
                        ++v8;
                    }
                    while ( v8 < v7->player_num );
                    v4 = oObj;
                }
            }
        }
    }
    v10 = TribeInformationAIModule::checkDefend(v5, v4);
    v11 = v5->importantObjects.numberValue;
    v12 = v4->id;
    addedFromAlliedCPa = v10;
    for ( i = 0; i < v11; ++i )
    {
        if ( i >= v5->importantObjects.maximumSizeValue )
            break;
        if ( v5->importantObjects.value[i] == v12 )
            goto LABEL_28;
    }
    if ( v11 > v5->importantObjects.maximumSizeValue - 1 )
    {
        v14 = v11 + 1;
        v15 = (int *)operator new(4 * (v11 + 1));
        if ( v15 )
        {
            for ( j = 0; j < v5->importantObjects.maximumSizeValue; v15[j - 1] = v5->importantObjects.value[j - 1] )
            {
                if ( j >= v14 )
                    break;
                ++j;
            }
            operator delete(v5->importantObjects.value);
            v5->importantObjects.value = v15;
            v5->importantObjects.maximumSizeValue = v14;
        }
    }
    v4 = oObj;
    v5->importantObjects.value[v5->importantObjects.numberValue++] = v12;
LABEL_28:
    if ( TribeInformationAIModule::importantUnit(oType) == 1 )
    {
        v17 = v5->importantUnits.numberValue;
        v18 = v4->id;
        for ( k = 0; k < v17; ++k )
        {
            if ( k >= v5->importantUnits.maximumSizeValue )
                break;
            if ( v5->importantUnits.value[k] == v18 )
                goto LABEL_55;
        }
        if ( v17 > v5->importantUnits.maximumSizeValue - 1 )
        {
            v20 = v17 + 1;
            v21 = (int *)operator new(4 * (v17 + 1));
            if ( v21 )
            {
                for ( l = 0; l < v5->importantUnits.maximumSizeValue; v21[l - 1] = v5->importantUnits.value[l - 1] )
                {
                    if ( l >= v20 )
                        break;
                    ++l;
                }
                operator delete(v5->importantUnits.value);
                v5->importantUnits.value = v21;
                v5->importantUnits.maximumSizeValue = v20;
            }
        }
        v5->importantUnits.value[v5->importantUnits.numberValue++] = v18;
LABEL_54:
        v4 = oObj;
        goto LABEL_55;
    }
    if ( TribeInformationAIModule::importantResource(oType) == 1 )
    {
        TribeInformationAIModule::addResourceObject(v5, v4);
        goto LABEL_55;
    }
    if ( TribeInformationAIModule::importantMisc(oType) == 1 )
    {
        v23 = v5->importantMiscs.numberValue;
        v24 = v4->id;
        for ( m = 0; m < v23; ++m )
        {
            if ( m >= v5->importantMiscs.maximumSizeValue )
                break;
            if ( v5->importantMiscs.value[m] == v24 )
                goto LABEL_55;
        }
        if ( v23 > v5->importantMiscs.maximumSizeValue - 1 )
        {
            v26 = v23 + 1;
            v27 = (int *)operator new(4 * (v23 + 1));
            if ( v27 )
            {
                for ( n = 0; n < v5->importantMiscs.maximumSizeValue; v27[n - 1] = v5->importantMiscs.value[n - 1] )
                {
                    if ( n >= v26 )
                        break;
                    ++n;
                }
                operator delete(v5->importantMiscs.value);
                v5->importantMiscs.value = v27;
                v5->importantMiscs.maximumSizeValue = v26;
            }
        }
        v5->importantMiscs.value[v5->importantMiscs.numberValue++] = v24;
        goto LABEL_54;
    }
LABEL_55:
    if ( TribeInformationAIModule::importantUnit(oType) == 1 || addedFromAlliedCPa == 1 )
        TribeInformationAIModule::addObjectMemory(v5, a2, v4);
    return 1;
}

//----- (004DAF80) --------------------------------------------------------
int TribeInformationAIModule::addImportantObject@<eax>(TribeInformationAIModule *this@<ecx>, double a2@<st0>, int oID)
{
    TribeInformationAIModule *v3; // esi@1
    RGE_Static_Object *v4; // eax@1

    v3 = this;
    v4 = MainDecisionAIModule::object((MainDecisionAIModule *)&this->md->vfptr, oID);
    return TribeInformationAIModule::addImportantObject(v3, a2, v4, 0);
}

//----- (004DAFB0) --------------------------------------------------------
int __stdcall TribeInformationAIModule::importantObject(int oType)
{
    int result; // eax@3

    if ( TribeInformationAIModule::importantUnit(oType)
        || TribeInformationAIModule::importantResource(oType)
        || (result = TribeInformationAIModule::importantMisc(oType)) != 0 )
    {
        result = 1;
    }
    return result;
}

//----- (004DAFF0) --------------------------------------------------------
BOOL __stdcall TribeInformationAIModule::importantUnit(int oType)
{
    return !oType
            || oType == 3
            || oType == 4
            || oType == 24
            || oType == 21
            || oType == 6
            || oType == 25
            || oType == 17
            || oType == 26
            || oType == 12
            || oType == 35
            || oType == 23
            || oType == 36
            || oType == 28
            || oType == 18
            || oType == 13
            || oType == 2
            || oType == 20
            || oType == 27
            || oType == 22
            || oType == 39;
}

//----- (004DB070) --------------------------------------------------------
BOOL __stdcall TribeInformationAIModule::importantResource(int oType)
{
    return oType == 31
            || oType == 5
            || oType == 33
            || oType == 7
            || oType == 9
            || oType == 8
            || oType == 32
            || oType == 15;
}

//----- (004DB0B0) --------------------------------------------------------
BOOL __stdcall TribeInformationAIModule::importantMisc(int oType)
{
    return oType == 1 || oType == 30;
}

//----- (004DB0D0) --------------------------------------------------------
BOOL __stdcall TribeInformationAIModule::isBuilding(RGE_Static_Object *obj)
{
    __int16 v2; // ax@1

    v2 = obj->master_obj->object_group;
    return v2 == 3 || v2 == 27;
}

//----- (004DB100) --------------------------------------------------------
int __stdcall TribeInformationAIModule::isUnitBuilding(RGE_Static_Object *obj)
{
    RGE_Master_Static_Object *v2; // eax@1
    int result; // eax@2
    __int16 v4; // ax@3

    v2 = obj->master_obj;
    if ( v2->object_group == 3 )
    {
        v4 = v2->id;
        result = v4 == 109 || v4 == 12 || v4 == 87 || v4 == 49 || v4 == 45 || !v4 || v4 == 101 || v4 == 104;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (004DB160) --------------------------------------------------------
BOOL __stdcall TribeInformationAIModule::isBoat(RGE_Static_Object *obj)
{
    __int16 v2; // ax@1

    v2 = obj->master_obj->object_group;
    return v2 == 21 || v2 == 2 || v2 == 20 || v2 == 22;
}

//----- (004DB190) --------------------------------------------------------
BOOL __stdcall TribeInformationAIModule::isWall(RGE_Static_Object *obj)
{
    return obj->master_obj->object_group == 27;
}

//----- (004DB1B0) --------------------------------------------------------
BOOL __stdcall TribeInformationAIModule::isTower(RGE_Static_Object *obj)
{
    __int16 v2; // ax@1

    v2 = obj->master_obj->id;
    return v2 == 79 || v2 == 199 || v2 == 69 || v2 == 383 || v2 == 380;
}

//----- (004DB1F0) --------------------------------------------------------
RGE_Static_Object *TribeInformationAIModule::isBoatAccessible(RGE_Static_Object *unit, int target)
{
    RGE_Static_Object *result; // eax@1
    RGE_Master_Static_Object *v4; // ecx@2
    __int16 v5; // ax@2

    result = MainDecisionAIModule::object((MainDecisionAIModule *)&this->md->vfptr, target);
    if ( result )
    {
        v4 = result->master_obj;
        v5 = v4->object_group;
        result = (RGE_Static_Object *)(v5 == 21 || v5 == 2 || v5 == 20 || v5 == 22 || v4->id == 45);
    }
    return result;
}

//----- (004DB240) --------------------------------------------------------
int TribeInformationAIModule::isLandAccessible(RGE_Static_Object *unit, int target)
{
    RGE_Static_Object *v3; // eax@1
    __int16 v4; // ax@2
    int result; // eax@6

    v3 = MainDecisionAIModule::object((MainDecisionAIModule *)&this->md->vfptr, target);
    result = 0;
    if ( v3 )
    {
        v4 = v3->master_obj->object_group;
        if ( v4 != 21 && v4 != 2 && v4 != 20 && v4 != 22 )
            result = 1;
    }
    return result;
}

//----- (004DB280) --------------------------------------------------------
int __stdcall TribeInformationAIModule::influenceCanPlaceStructure(BuildItem *bi)
{
    return 1;
}

//----- (004DB290) --------------------------------------------------------
void TribeInformationAIModule::influencePlaceStructure(BuildItem *bi, int builderID, int alternateType, float alternateSize, char *alternateName, int alternateMinD, int alternateMaxD, int alternateX, int alternateY, PlacementState *placementState, unsigned int startTime)
{
    TribeInformationAIModule *v12; // edi@1
    PlacementState *v13; // ebx@3
    int v14; // esi@4
    MainDecisionAIModule *v15; // ecx@9
    RGE_Static_Object *v16; // eax@11
    int v17; // esi@13
    int v18; // eax@21
    int v19; // esi@25
    int v20; // edi@25
    signed int v21; // esi@27
    int v22; // eax@33
    TribeMainDecisionAIModule *v23; // ecx@38
    int v24; // eax@39
    RGE_Static_Object *v25; // ecx@42
    BuildingLot *v26; // eax@48
    BuildingLot *v27; // esi@48
    int v28; // ecx@50
    ConstructionItem *v29; // eax@52
    float v30; // ST2C_4@53
    float v31; // ST28_4@53
    ConstructionItem *v32; // eax@54
    float v33; // ST2C_4@55
    float v34; // ST28_4@55
    TribeInformationAIModule *v35; // edi@58
    signed int v36; // esi@61
    int v37; // esi@64
    signed int v38; // ebp@64
    unsigned int v39; // eax@66
    int v40; // edx@68
    int v41; // ecx@69
    int v42; // ecx@77
    RGE_Master_Static_ObjectVtbl *v43; // eax@110
    float v44; // ST28_4@110
    float v45; // ST24_4@110
    int v46; // ebp@111
    signed int v47; // ebx@111
    int v48; // edi@111
    int v49; // eax@112
    int v50; // esi@114
    int v51; // eax@116
    int v52; // eax@122
    int v53; // esi@124
    int v54; // eax@124
    int v55; // eax@128
    XYPoint *v56; // esi@128
    TribeInformationAIModule *v57; // ebx@129
    int v58; // edi@132
    int v59; // ecx@136
    int v60; // eax@136
    int v61; // edx@148
    signed __int64 v62; // rax@154
    int v63; // edx@155
    int v64; // edx@172
    ConstructionItem *v65; // eax@177
    float v66; // ST2C_4@178
    float v67; // ST28_4@178
    ConstructionItem *v68; // eax@179
    float v69; // ST2C_4@180
    float v70; // ST28_4@180
    int v71; // ecx@183
    int v72; // eax@186
    char *v73; // [sp+3Ch] [bp-1B8h]@4
    char *v74; // [sp+40h] [bp-1B4h]@4
    TribeInformationAIModule *v75; // [sp+58h] [bp-19Ch]@1
    float buildingSize; // [sp+5Ch] [bp-198h]@4
    int buildingType; // [sp+60h] [bp-194h]@4
    signed int x; // [sp+64h] [bp-190h]@64
    RGE_Static_Object *randSelect; // [sp+68h] [bp-18Ch]@1
    signed int randSelecta; // [sp+68h] [bp-18Ch]@62
    int placementType; // [sp+6Ch] [bp-188h]@21
    signed int bestPoint; // [sp+70h] [bp-184h]@64
    signed int bestPoint_4; // [sp+74h] [bp-180h]@64
    int basePlacementTotal; // [sp+78h] [bp-17Ch]@9
    signed int y; // [sp+7Ch] [bp-178h]@77
    int maximumDistance; // [sp+80h] [bp-174h]@25
    XYPoint centerPoint; // [sp+84h] [bp-170h]@15
    XYPoint maxClear; // [sp+8Ch] [bp-168h]@94
    XYPoint minClear; // [sp+94h] [bp-160h]@94
    int bestPointValue; // [sp+9Ch] [bp-158h]@10
    int minimumDistance; // [sp+A0h] [bp-154h]@25
    ConstructionItem *v92; // [sp+A4h] [bp-150h]@52
    XYPoint max; // [sp+A8h] [bp-14Ch]@46
    unsigned int availableTime; // [sp+B0h] [bp-144h]@66
    int firstTimeThrough; // [sp+B4h] [bp-140h]@72
    int useExcludeRegion; // [sp+B8h] [bp-13Ch]@69
    XYPoint min; // [sp+BCh] [bp-138h]@46
    XYPoint maxExclude; // [sp+C4h] [bp-130h]@46
    XYPoint minExclude; // [sp+CCh] [bp-128h]@46
    int blockingObject; // [sp+D4h] [bp-120h]@110
    int overlapSize; // [sp+D8h] [bp-11Ch]@9
    XYPoint newPosition; // [sp+DCh] [bp-118h]@128
    TRIBE_Master_Building_Object *masterObj; // [sp+E4h] [bp-110h]@9
    char buildingName[256]; // [sp+E8h] [bp-10Ch]@4
    int v105; // [sp+1F0h] [bp-4h]@52

    v12 = this;
    v75 = this;
    randSelect = MainDecisionAIModule::object(
                                 (MainDecisionAIModule *)&this->md->vfptr,
                                 -1,
                                 -1,
                                 4,
                                 -1,
                                 -1,
                                 -1,
                                 -1,
                                 -1,
                                 -1,
                                 -1);
    if ( !randSelect )
    {
        placementState->active = 0;
        return;
    }
    v13 = placementState;
    if ( placementState->active == 1 )
    {
        v14 = placementState->buildingTypeID;
        v74 = placementState->buildingName;
        buildingType = placementState->buildingTypeID;
        buildingSize = placementState->buildingSize;
        v73 = buildingName;
    }
    else
    {
        if ( bi )
        {
            v14 = BaseItem::typeID((BaseItem *)&bi->vfptr);
            buildingType = v14;
            buildingSize = BaseItem::xSize((BaseItem *)&bi->vfptr);
            v74 = BaseItem::name((BaseItem *)&bi->vfptr);
        }
        else
        {
            v14 = alternateType;
            buildingType = alternateType;
            buildingSize = alternateSize;
            v74 = alternateName;
        }
        v73 = buildingName;
    }
    strncpy(v73, v74, 0xFFu);
    overlapSize = (signed __int64)buildingSize;
    v15 = (MainDecisionAIModule *)&v12->md->vfptr;
    basePlacementTotal = 20 * overlapSize * overlapSize;
    masterObj = (TRIBE_Master_Building_Object *)v15->player->master_objects[v14];
    if ( !masterObj )
        goto LABEL_184;
    bestPointValue = (int)MainDecisionAIModule::object(v15, -1, 109, -1, -1, -1, -1, -1, -1, -1, -1);
    if ( placementState->active == 1 )
        v16 = MainDecisionAIModule::object((MainDecisionAIModule *)&v12->md->vfptr, placementState->builderID);
    else
        v16 = MainDecisionAIModule::object((MainDecisionAIModule *)&v12->md->vfptr, builderID);
    v17 = (int)v16;
    if ( bi || placementState->active == 1 )
    {
        if ( bestPointValue )
        {
            v17 = bestPointValue;
        }
        else if ( !v16 )
        {
            v17 = (int)randSelect;
        }
        centerPoint.x = (signed __int64)*(float *)(v17 + 56);
        centerPoint.y = (signed __int64)*(float *)(v17 + 60);
    }
    else
    {
        centerPoint.x = alternateX;
        centerPoint.y = alternateY;
    }
    v18 = TribeInformationAIModule::placementCode(buildingType);
    placementType = v18;
    if ( v18 == -1 )
    {
        AIModule::logCommonHistory((AIModule *)&v75->vfptr, aInvalidInfluen, buildingType);
        goto LABEL_184;
    }
    if ( bi || placementState->active == 1 )
    {
        if ( v18 == 1 )
        {
            minimumDistance = 7;
            v21 = 1;
            if ( TribeTacticalAIModule::inAge(&v75->md->tacticalAI, 2) )
            {
                v21 = 2;
            }
            else if ( TribeTacticalAIModule::inAge(&v75->md->tacticalAI, 3) )
            {
                v21 = 3;
            }
            else if ( TribeTacticalAIModule::inAge(&v75->md->tacticalAI, 4) )
            {
                v21 = 4;
            }
            v22 = v21 * TribeTacticalAIModule::strategicNumber(&v75->md->tacticalAI, 86);
            v19 = minimumDistance;
            maximumDistance = v22;
        }
        else
        {
            if ( v18 == 2 )
            {
                v19 = 4;
                minimumDistance = 4;
                v20 = TribeTacticalAIModule::strategicNumber(&v75->md->tacticalAI, 87);
                maximumDistance = v20;
LABEL_42:
                v25 = (RGE_Static_Object *)bestPointValue;
                if ( !bestPointValue )
                    v25 = randSelect;
                RGE_Static_Object::currentZone(v25);
                goto LABEL_45;
            }
            if ( v18 == 3 || v18 == 4 )
            {
                v24 = TribeTacticalAIModule::strategicNumber(&v75->md->tacticalAI, 73);
                v23 = v75->md;
                v19 = v24;
                minimumDistance = v24;
            }
            else
            {
                v19 = 4;
                minimumDistance = 4;
                v23 = v75->md;
            }
            maximumDistance = TribeTacticalAIModule::strategicNumber(&v23->tacticalAI, 74);
        }
        v20 = maximumDistance;
        goto LABEL_42;
    }
    v19 = alternateMinD;
    maximumDistance = alternateMaxD;
    minimumDistance = alternateMinD;
    RGE_Static_Object::lookupZone(randSelect, alternateX, alternateY);
    v20 = alternateMaxD;
LABEL_45:
    if ( v19 >= v20 )
        goto LABEL_184;
    min.x = centerPoint.x - v20;
    min.y = centerPoint.y - v20;
    TribeInformationAIModule::mapBound(v75, &min);
    max.x = v20 + centerPoint.x;
    max.y = centerPoint.y + v20;
    TribeInformationAIModule::mapBound(v75, &max);
    minExclude.x = centerPoint.x - v19;
    minExclude.y = centerPoint.y - v19;
    TribeInformationAIModule::mapBound(v75, &minExclude);
    maxExclude.x = v19 + centerPoint.x;
    maxExclude.y = centerPoint.y + v19;
    TribeInformationAIModule::mapBound(v75, &maxExclude);
    if ( !bi )
        goto LABEL_190;
    if ( placementState->active )
        goto LABEL_59;
    v26 = TribeInformationAIModule::availableLot(v75, buildingType);
    v27 = v26;
    if ( !v26 )
    {
LABEL_190:
        if ( !placementState->active )
        {
            v35 = v75;
            TribeInformationAIModule::setupInfluenceMap(
                v75,
                (int)placementState,
                placementType,
                buildingType,
                &centerPoint,
                &min,
                &max);
LABEL_60:
            if ( placementState->active )
            {
                v38 = placementState->bestPointValue;
                v37 = placementState->iterationX;
                randSelecta = placementState->randomInfluence;
                bestPoint = placementState->bestPoint.x;
                bestPoint_4 = placementState->bestPoint.y;
                bestPointValue = placementState->bestPointValue;
                x = v37;
            }
            else
            {
                v36 = TribeTacticalAIModule::strategicNumber(&v35->md->tacticalAI, 168);
                if ( v36 <= 0 )
                    randSelecta = 0;
                else
                    randSelecta = debug_rand(aCMsdevWorkA_52, 2760) % v36;
                v37 = min.x;
                v38 = -1;
                bestPoint = -1;
                bestPoint_4 = -1;
                x = min.x;
                bestPointValue = -1;
            }
            availableTime = v35->md->player->world->availableComputerPlayerUpdateTime;
            v39 = debug_timeGetTime();
            if ( !placementState->active && v39 - startTime >= availableTime )
            {
                placementState->buildingTypeID = buildingType;
                strncpy(placementState->buildingName, buildingName, 0xFFu);
                v40 = minimumDistance;
                placementState->buildingSize = buildingSize;
                placementState->builderID = builderID;
                placementState->minimumDistance = v40;
                placementState->maximumDistance = maximumDistance;
                placementState->bestPoint.x = bestPoint;
                placementState->active = 1;
                placementState->bestPoint.y = bestPoint_4;
                placementState->bestPointValue = v38;
                placementState->iterationX = v37;
                placementState->randomInfluence = randSelecta;
                placementState->buildItem = bi;
                return;
            }
            v41 = placementType;
            useExcludeRegion = 0;
            if ( placementType == 4 || placementType == 3 )
                useExcludeRegion = 1;
            firstTimeThrough = 1;
            if ( v37 <= max.x )
            {
                do
                {
                    if ( firstTimeThrough )
                    {
                        firstTimeThrough = 0;
                    }
                    else if ( debug_timeGetTime() - startTime >= availableTime )
                    {
                        v13->buildingTypeID = buildingType;
                        strncpy(v13->buildingName, buildingName, 0xFFu);
                        v72 = minimumDistance;
                        v13->buildingSize = buildingSize;
                        v13->builderID = builderID;
                        v13->minimumDistance = v72;
                        v13->maximumDistance = maximumDistance;
                        v13->bestPoint.x = bestPoint;
                        v13->active = 1;
                        v13->bestPoint.y = bestPoint_4;
                        v13->bestPointValue = v38;
                        v13->iterationX = v37;
                        v13->randomInfluence = randSelecta;
                        v13->buildItem = bi;
                        return;
                    }
                    v42 = min.y;
                    y = min.y;
                    if ( min.y <= max.y )
                    {
                        while ( 1 )
                        {
                            if ( useExcludeRegion == 1 && minExclude.x <= v37 && v37 <= maxExclude.x && minExclude.y <= v42 )
                            {
                                if ( v42 <= maxExclude.y )
                                    goto LABEL_162;
                                v13 = placementState;
                                v37 = x;
                                v42 = y;
                            }
                            if ( buildingSize == 5.0 )
                            {
LABEL_94:
                                minClear.x = v37 - 2;
                                minClear.y = v42 - 2;
                                maxClear.x = v37 + 2;
                                v42 += 2;
                                goto LABEL_108;
                            }
                            if ( buildingSize == 3.0 )
                                break;
                            if ( buildingSize == 2.0 )
                            {
                                if ( placementType != 6 && placementType != 3 && placementType != 4 )
                                {
                                    minClear.x = v37 - 2;
                                    minClear.y = v42 - 2;
                                    maxClear.x = v37 + 1;
                                    ++v42;
                                    goto LABEL_108;
                                }
                                minClear.x = v37 - 1;
                                minClear.y = v42 - 1;
                            }
                            else
                            {
                                if ( buildingSize != 1.0 )
                                {
                                    AIModule::logCommonHistory((AIModule *)&v75->vfptr, aUnsupportedBui, buildingSize, buildingSize);
                                    goto LABEL_184;
                                }
                                if ( placementType != 6 && placementType != 3 && placementType != 4 )
                                    goto LABEL_105;
                                minClear.x = v37;
                                minClear.y = v42;
                            }
                            maxClear.x = v37;
LABEL_108:
                            maxClear.y = v42;
                            if ( TribeInformationAIModule::mapBound(v75, &minClear) != 1
                                && TribeInformationAIModule::mapBound(v75, &maxClear) != 1 )
                            {
                                v43 = masterObj->vfptr;
                                blockingObject = -1;
                                v44 = (double)y - -0.5;
                                v45 = (double)x - -0.5;
                                if ( !(unsigned __int8)((int (__stdcall *)(RGE_Player *, _DWORD, _DWORD, int *, signed int, signed int, signed int, signed int, signed int, signed int))v43->check_placement)(
                                                                                 v75->md->player,
                                                                                 LODWORD(v45),
                                                                                 LODWORD(v44),
                                                                                 &blockingObject,
                                                                                 1,
                                                                                 1,
                                                                                 1,
                                                                                 1,
                                                                                 1,
                                                                                 1) )
                                {
                                    v46 = 0;
                                    v47 = 0;
                                    v48 = minClear.x;
                                    if ( minClear.x <= maxClear.x )
                                    {
                                        v49 = maxClear.y;
                                        do
                                        {
                                            if ( v47 )
                                                break;
                                            v50 = minClear.y;
                                            if ( minClear.y <= v49 )
                                            {
                                                do
                                                {
                                                    if ( v47 )
                                                        break;
                                                    v51 = InfluenceMap::lookupValue(&iMap, v48, v50);
                                                    if ( v51 == 255 )
                                                        v47 = 1;
                                                    else
                                                        v46 += v51;
                                                    v49 = maxClear.y;
                                                    ++v50;
                                                }
                                                while ( v50 <= maxClear.y );
                                            }
                                            ++v48;
                                        }
                                        while ( v48 <= maxClear.x );
                                    }
                                    if ( v47 != 1 )
                                    {
                                        v52 = placementType;
                                        if ( placementType == 4 || placementType == 6 )
                                        {
                                            v53 = iMap.connectionCountValue;
                                            v54 = InfluenceMap::connectionsIncluding(&iMap, &minClear, &maxClear, -1, -1, 1, 0, 1) - v53;
                                            if ( placementType == 4 && v54 > 6 )
                                                goto LABEL_162;
                                            v46 *= v54;
                                            v52 = placementType;
                                        }
                                        if ( v52 == 4 )
                                        {
                                            newPosition.y = y;
                                            v55 = v75->lastWallPosition.x;
                                            v56 = &v75->lastWallPosition;
                                            newPosition.x = x;
                                            if ( v55 == -1 )
                                            {
                                                v57 = v75;
                                            }
                                            else
                                            {
                                                v57 = v75;
                                                if ( !TribeInformationAIModule::isNextTo(&v75->lastWallPosition, &newPosition, 0) )
                                                    v46 /= 2;
                                            }
                                            v58 = TribeInformationAIModule::facetTo(v56, &newPosition);
                                            if ( (((unsigned __int64)v58 >> 32) ^ abs(v58) & 1) - ((unsigned __int64)v58 >> 32) == 1 )
                                                v46 *= 3;
                                            if ( TribeInformationAIModule::facetTo(&v57->lastWallPosition2, v56) == v58 )
                                                v46 *= 3;
                                            v59 = abs(v56->x - centerPoint.x);
                                            v60 = abs(v57->lastWallPosition.y - centerPoint.y);
                                            if ( v60 >= v59 )
                                            {
                                                if ( v60 > v59 && (v58 == 3 || v58 == 7) )
                                                    goto LABEL_143;
                                            }
                                            else
                                            {
                                                if ( v58 != 1 )
                                                {
                                                    if ( v58 == 5 )
                                                        v46 *= 3;
                                                    goto LABEL_152;
                                                }
LABEL_143:
                                                v46 *= 3;
                                            }
LABEL_152:
                                            if ( placementType == 1 || placementType == 2 )
                                            {
                                                v92 = (ConstructionItem *)((y - centerPoint.y) * (y - centerPoint.y)
                                                                                                 + (x - centerPoint.x) * (x - centerPoint.x));
                                                v62 = (signed __int64)sqrt((double)(signed int)v92);
                                                if ( (signed int)v62 - 10 > 0 )
                                                {
                                                    v63 = ((signed int)v62 - 10) / 5;
                                                    if ( v46 - v63 > basePlacementTotal )
                                                        v46 -= v63;
                                                }
                                            }
                                            if ( bestPointValue == -1 || bestPointValue < v46 + randSelecta )
                                            {
                                                if ( bestPointValue >= v46 )
                                                    randSelecta /= 2;
                                                bestPoint = x;
                                                bestPoint_4 = y;
                                                bestPointValue = v46;
                                            }
                                            goto LABEL_162;
                                        }
                                        if ( v52 == 1 || v52 == 2 )
                                        {
                                            if ( TribeInformationAIModule::undesirableLot(v75, buildingType, x, y, 10) != 1 )
                                                goto LABEL_152;
                                            v61 = v46 / 10;
                                        }
                                        else
                                        {
                                            if ( v52 == 6
                                                || TribeInformationAIModule::undesirableLot(v75, buildingType, x, y, overlapSize) != 1 )
                                            {
                                                goto LABEL_152;
                                            }
                                            v61 = v46 / 10;
                                        }
                                        v46 = v61;
                                        goto LABEL_152;
                                    }
                                }
                            }
LABEL_162:
                            v13 = placementState;
                            v37 = x;
                            if ( ++y > max.y )
                            {
                                v38 = bestPointValue;
                                goto LABEL_164;
                            }
                            v42 = y;
                        }
                        if ( placementType != 6
                            && placementType != 3
                            && placementType != 4
                            && placementType != 1
                            && placementType != 2
                            && placementType != 8 )
                        {
                            goto LABEL_94;
                        }
LABEL_105:
                        minClear.x = v37 - 1;
                        minClear.y = v42 - 1;
                        maxClear.x = v37 + 1;
                        ++v42;
                        goto LABEL_108;
                    }
LABEL_164:
                    x = ++v37;
                }
                while ( v37 <= max.x );
                v35 = v75;
                v41 = placementType;
            }
            if ( v38 != -1 && (basePlacementTotal < v38 || v41 != 2 && (basePlacementTotal < v38 || v41 != 1)) )
            {
                if ( v41 == 4 )
                {
                    v64 = v35->lastWallPosition.y;
                    v35->lastWallPosition2.x = v35->lastWallPosition.x;
                    v35->lastWallPosition2.y = v64;
                    v35->lastWallPosition.x = bestPoint;
                    v35->lastWallPosition.y = bestPoint_4;
                }
                if ( bi || v13->active == 1 )
                {
                    if ( buildingSize == 2.0 )
                    {
                        v65 = (ConstructionItem *)operator new(0x80u);
                        v92 = v65;
                        v105 = 2;
                        if ( v65 )
                        {
                            v66 = (double)bestPoint_4;
                            v67 = (double)bestPoint;
                            ConstructionItem::ConstructionItem(
                                v65,
                                v67,
                                v66,
                                1.0,
                                buildingSize,
                                buildingSize,
                                1.0,
                                buildingType,
                                buildingName);
                        }
                    }
                    else
                    {
                        v68 = (ConstructionItem *)operator new(0x80u);
                        v92 = v68;
                        v105 = 3;
                        if ( v68 )
                        {
                            v69 = (double)bestPoint_4 - -0.5;
                            v70 = (double)bestPoint - -0.5;
                            ConstructionItem::ConstructionItem(
                                v68,
                                v70,
                                v69,
                                1.0,
                                buildingSize,
                                buildingSize,
                                1.0,
                                buildingType,
                                buildingName);
                        }
                    }
                    v105 = -1;
                    TribeInformationAIModule::storeLot(v35, buildingType, bestPoint, bestPoint_4, 1);
                    v13->active = 0;
                }
                else
                {
                    TribeInformationAIModule::storeLot(v35, buildingType, bestPoint, bestPoint_4, 0);
                    v13->active = 0;
                }
                return;
            }
            if ( v41 == 4 )
            {
                v71 = v35->lastWallPosition.y;
                v35->lastWallPosition2.x = v35->lastWallPosition.x;
                v35->lastWallPosition2.y = v71;
                v35->lastWallPosition.x = -1;
                v35->lastWallPosition.y = -1;
            }
LABEL_184:
            v13->active = 0;
            return;
        }
LABEL_59:
        v35 = v75;
        goto LABEL_60;
    }
    if ( placementType == 4 )
    {
        v28 = v75->lastWallPosition.y;
        v75->lastWallPosition2.x = v75->lastWallPosition.x;
        v75->lastWallPosition2.y = v28;
        v75->lastWallPosition.x = v26->x;
        v75->lastWallPosition.y = v26->y;
    }
    if ( buildingSize == 2.0 )
    {
        v29 = (ConstructionItem *)operator new(0x80u);
        v92 = v29;
        v105 = 0;
        if ( v29 )
        {
            v30 = (double)v27->y;
            v31 = (double)v27->x;
            ConstructionItem::ConstructionItem(
                v29,
                v31,
                v30,
                1.0,
                buildingSize,
                buildingSize,
                1.0,
                buildingType,
                buildingName);
            v27->status = 1;
            placementState->active = 0;
            return;
        }
    }
    else
    {
        v32 = (ConstructionItem *)operator new(0x80u);
        v92 = v32;
        v105 = 1;
        if ( v32 )
        {
            v33 = (double)v27->y - -0.5;
            v34 = (double)v27->x - -0.5;
            ConstructionItem::ConstructionItem(
                v32,
                v34,
                v33,
                1.0,
                buildingSize,
                buildingSize,
                1.0,
                buildingType,
                buildingName);
            v27->status = 1;
            placementState->active = 0;
            return;
        }
    }
    v27->status = 1;
    placementState->active = 0;
}

//----- (004DC1B0) --------------------------------------------------------
void TribeInformationAIModule::addObject(RGE_Static_Object *obj)
{
    RGE_Static_Object *v2; // edi@1
    TribeInformationAIModule *v3; // esi@1
    ObjectMemory *v4; // eax@3
    int v5; // ecx@5
    int v6; // ebp@5
    int i; // eax@5
    int v8; // ebx@10
    int *v9; // edi@10
    int j; // eax@11
    int v11; // ecx@18
    int v12; // ebp@18
    int k; // eax@18
    int v14; // ebx@23
    int *v15; // edi@23
    int l; // eax@24
    __int16 v17; // ax@29

    v2 = obj;
    v3 = this;
    if ( obj && obj->id >= 0 )
    {
        v4 = TribeInformationAIModule::objectMemory(this, obj->id);
        if ( v4 )
            v4->owner = obj->owner->id;
        v5 = v3->playerObjects.numberValue;
        v6 = obj->id;
        for ( i = 0; i < v5; ++i )
        {
            if ( i >= v3->playerObjects.maximumSizeValue )
                break;
            if ( v3->playerObjects.value[i] == v6 )
                goto LABEL_17;
        }
        if ( v5 > v3->playerObjects.maximumSizeValue - 1 )
        {
            v8 = v5 + 1;
            v9 = (int *)operator new(4 * (v5 + 1));
            if ( v9 )
            {
                for ( j = 0; j < v3->playerObjects.maximumSizeValue; v9[j - 1] = v3->playerObjects.value[j - 1] )
                {
                    if ( j >= v8 )
                        break;
                    ++j;
                }
                operator delete(v3->playerObjects.value);
                v3->playerObjects.value = v9;
                v3->playerObjects.maximumSizeValue = v8;
            }
            v2 = obj;
        }
        v3->playerObjects.value[v3->playerObjects.numberValue++] = v6;
LABEL_17:
        if ( TribeInformationAIModule::isBuilding(v2) == 1 )
        {
            v11 = v3->playerBuildings.numberValue;
            v12 = v2->id;
            for ( k = 0; k < v11; ++k )
            {
                if ( k >= v3->playerBuildings.maximumSizeValue )
                    break;
                if ( v3->playerBuildings.value[k] == v12 )
                    goto LABEL_29;
            }
            if ( v11 > v3->playerBuildings.maximumSizeValue - 1 )
            {
                v14 = v11 + 1;
                v15 = (int *)operator new(4 * (v11 + 1));
                if ( v15 )
                {
                    for ( l = 0; l < v3->playerBuildings.maximumSizeValue; v15[l - 1] = v3->playerBuildings.value[l - 1] )
                    {
                        if ( l >= v14 )
                            break;
                        ++l;
                    }
                    operator delete(v3->playerBuildings.value);
                    v3->playerBuildings.value = v15;
                    v3->playerBuildings.maximumSizeValue = v14;
                }
            }
            v3->playerBuildings.value[v3->playerBuildings.numberValue++] = v12;
LABEL_29:
            v17 = obj->master_obj->id;
            if ( v17 == 109 || v17 == 103 || v17 == 68 )
                TribeInformationAIModule::updateAllResourceDropsites(v3);
            if ( obj->master_obj->id == 50 )
                TribeInformationAIModule::addResourceObject(v3, obj);
        }
    }
}

//----- (004DC3A0) --------------------------------------------------------
void TribeInformationAIModule::removeObject(int objID)
{
    TribeInformationAIModule *v2; // esi@1
    int v3; // eax@1
    int v4; // ecx@1
    int *v5; // edx@2
    int v6; // eax@8
    int v7; // edx@10
    int v8; // eax@10
    int *v9; // ecx@11
    int v10; // eax@17
    RGE_Static_Object *v11; // edi@19
    ObjectMemory *v12; // eax@20

    v2 = this;
    v3 = 0;
    v4 = this->playerBuildings.maximumSizeValue;
    if ( v4 > 0 )
    {
        v5 = v2->playerBuildings.value;
        do
        {
            if ( *v5 == objID )
                break;
            ++v3;
            ++v5;
        }
        while ( v3 < v4 );
    }
    if ( v3 < v4 )
    {
        if ( v3 < v4 - 1 )
        {
            do
            {
                ++v3;
                v2->playerBuildings.value[v3 - 1] = v2->playerBuildings.value[v3];
            }
            while ( v3 < v2->playerBuildings.maximumSizeValue - 1 );
        }
        v6 = v2->playerBuildings.numberValue - 1;
        v2->playerBuildings.numberValue = v6;
        if ( v6 < 0 )
            v2->playerBuildings.numberValue = 0;
    }
    v7 = v2->playerObjects.maximumSizeValue;
    v8 = 0;
    if ( v7 > 0 )
    {
        v9 = v2->playerObjects.value;
        do
        {
            if ( *v9 == objID )
                break;
            ++v8;
            ++v9;
        }
        while ( v8 < v7 );
    }
    if ( v8 < v7 )
    {
        if ( v8 < v7 - 1 )
        {
            do
            {
                ++v8;
                v2->playerObjects.value[v8 - 1] = v2->playerObjects.value[v8];
            }
            while ( v8 < v2->playerObjects.maximumSizeValue - 1 );
        }
        v10 = v2->playerObjects.numberValue - 1;
        v2->playerObjects.numberValue = v10;
        if ( v10 < 0 )
            v2->playerObjects.numberValue = 0;
    }
    v11 = MainDecisionAIModule::object((MainDecisionAIModule *)&v2->md->vfptr, objID);
    if ( v11 )
    {
        v12 = TribeInformationAIModule::objectMemory(v2, objID);
        if ( v12 )
            v12->owner = v11->owner->id;
    }
}

//----- (004DC490) --------------------------------------------------------
ObjectMemory *TribeInformationAIModule::objectToAttackWithPlay(int ownerID, int *soldiers, int numSoldiers, int *playToRun, int *playUnits, int *numberPlayUnits, int *playCommander)
{
    ObjectMemory *result; // eax@1
    TribeInformationAIModule *v9; // ebx@1
    ObjectMemory *v10; // edx@2
    int v11; // edi@3
    RGE_Game_World *v12; // esi@3
    AIPlayBook *v13; // ecx@3
    AIPlay *v14; // eax@6
    AIPlay *v15; // ebp@6
    signed int v16; // edi@9
    int v17; // esi@11
    AIPlayPhase *v18; // eax@13
    AIPlayPhaseCommand *v19; // eax@13
    int v20; // ecx@14
    int v21; // eax@14
    bool v22; // sf@22
    unsigned __int8 v23; // of@22
    int v24; // edi@24
    int v25; // esi@24
    int v26; // edx@24
    int v27; // eax@24
    int v28; // ebp@24
    int v29; // eax@30
    int i; // [sp+10h] [bp-1E0h]@3
    ObjectMemory *target; // [sp+14h] [bp-1DCh]@2
    AIPlay *play; // [sp+18h] [bp-1D8h]@6
    int p; // [sp+1Ch] [bp-1D4h]@9
    RGE_Game_World *world; // [sp+20h] [bp-1D0h]@3
    AIPlayBook *playbook; // [sp+24h] [bp-1CCh]@3
    AIPlayStatus playStatus; // [sp+28h] [bp-1C8h]@8

    result = (ObjectMemory *)numSoldiers;
    v9 = this;
    if ( numSoldiers )
    {
        result = TribeInformationAIModule::objectToAttackByGroup2(this, ownerID, soldiers, numSoldiers);
        v10 = result;
        target = result;
        if ( result )
        {
            v11 = 0;
            i = 0;
            v12 = v9->md->player->world;
            world = v12;
            v13 = v12->playbook;
            *playToRun = -1;
            playbook = v13;
            if ( v13->numberPlaysValue > 0 )
            {
                while ( 1 )
                {
                    v14 = AIPlayBook::play(v13, v11);
                    v15 = v14;
                    play = v14;
                    if ( v14 )
                    {
                        if ( AIPlay::humanPlay(v14) != 1 )
                        {
                            AIPlayStatus::AIPlayStatus(&playStatus);
                            playStatus.playNumberValue = v11;
                            AIPlay::fillGroups(v15, &playStatus, soldiers, numSoldiers, v12);
                            if ( !playStatus.deviationValue )
                            {
                                v16 = 0;
                                p = 0;
                                while ( !v16 )
                                {
                                    v17 = 0;
                                    do
                                    {
                                        if ( v16 )
                                            break;
                                        v18 = AIPlay::phase(v15, p);
                                        v19 = AIPlayPhase::command(v18, v17);
                                        if ( v19->typeValue == 1 )
                                        {
                                            v20 = target->x + v19->value1Value;
                                            v21 = target->y + v19->value2Value;
                                            if ( v20 < 0 || v21 < 0 || v20 >= v9->mapXSizeValue || v21 >= v9->mapYSizeValue )
                                                v16 = 1;
                                            if ( TribeInformationAIModule::inRangeOfUnits(v9, ownerID, v20, v21, 0) == 1 )
                                                v16 = 1;
                                        }
                                        v15 = play;
                                        ++v17;
                                    }
                                    while ( v17 < 5 );
                                    v23 = __OFSUB__(p + 1, 10);
                                    v22 = p++ - 9 < 0;
                                    if ( !(v22 ^ v23) )
                                    {
                                        if ( !v16 )
                                        {
                                            v24 = TribeInformationAIModule::calculatePlayVariation(v9, i);
                                            v25 = 100 - v15->deathPercentageValue;
                                            v26 = debug_rand(aCMsdevWorkA_52, 3401) % 50;
                                            v27 = 0;
                                            v28 = v26;
                                            switch ( play->typeValue )
                                            {
                                                case 1:
                                                    v27 = TribeTacticalAIModule::strategicNumber(&v9->md->tacticalAI, 189);
                                                    break;
                                                case 2:
                                                    v27 = TribeTacticalAIModule::strategicNumber(&v9->md->tacticalAI, 198);
                                                    break;
                                                case 3:
                                                    v27 = TribeTacticalAIModule::strategicNumber(&v9->md->tacticalAI, 199);
                                                    break;
                                            }
                                            v29 = v28 + v27 + 2 * (v24 + v25);
                                            if ( *playToRun == -1 || v29 > 0 )
                                            {
                                                *playToRun = i;
                                                AIPlayStatus::copyUnits(&playStatus, playUnits, numberPlayUnits);
                                                *playCommander = playUnits[debug_rand(aCMsdevWorkA_52, 3434) % *numberPlayUnits];
                                            }
                                        }
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    v13 = playbook;
                    if ( ++i >= playbook->numberPlaysValue )
                        break;
                    v12 = world;
                    v11 = i;
                }
                v10 = target;
            }
            if ( *playToRun == -1 )
            {
                result = 0;
            }
            else
            {
                ++v9->playHistory[*playToRun];
                result = v10;
            }
        }
    }
    return result;
}

//----- (004DC750) --------------------------------------------------------
ObjectMemory *TribeInformationAIModule::objectToAttack(int ownerID, int ignoreSiegeTargets, int ignoreBoatTargets, int unitID, int *validAttack)
{
    TribeInformationAIModule *v6; // edi@1
    ObjectMemory *result; // eax@1
    int v8; // ebp@1
    RGE_Static_Object *v9; // eax@3
    RGE_Static_Object *v10; // ebx@3
    __int16 v11; // ax@5
    int v12; // eax@13
    RGE_Static_Object *v13; // eax@14
    RGE_Static_Object *v14; // esi@14
    double v15; // st7@16
    int v16; // ST24_4@16
    double v17; // st7@16
    __int16 v18; // ax@24
    RGE_Master_Static_Object *v19; // eax@29
    __int16 v20; // ax@30
    UnitAIModule *v21; // eax@36
    int v22; // ebp@37
    int v23; // ebx@37
    int v24; // esi@37
    signed __int64 v25; // rax@39
    int v26; // ecx@39
    int v27; // ebp@44
    unsigned int v28; // esi@44
    signed __int64 v29; // rax@44
    signed int v30; // eax@64
    TribeTacticalAIModule *v31; // ecx@64
    RGE_Master_Static_Object *v32; // esi@72
    __int16 v33; // ax@72
    signed int v34; // ebx@74
    signed int v35; // ebp@81
    int v36; // esi@83
    int v37; // esi@83
    int v38; // esi@83
    int v39; // esi@83
    int v40; // esi@83
    int v41; // eax@83
    int v42; // esi@83
    int v43; // esi@83
    int v44; // esi@83
    int v45; // esi@83
    int v46; // esi@83
    int v47; // esi@83
    int v48; // esi@83
    int v49; // esi@83
    int v50; // esi@83
    int v51; // ecx@91
    bool v52; // sf@91
    unsigned __int8 v53; // of@91
    int specialRating1; // [sp+10h] [bp-88h]@64
    int v55; // [sp+14h] [bp-84h]@12
    char unitZone; // [sp+1Bh] [bp-7Dh]@5
    RGE_Static_Object *unit; // [sp+1Ch] [bp-7Ch]@3
    int rOFRating; // [sp+20h] [bp-78h]@16
    int rOFRatinga; // [sp+20h] [bp-78h]@61
    int siegeWeapon; // [sp+24h] [bp-74h]@7
    int rangeRating; // [sp+28h] [bp-70h]@58
    float timeToKill; // [sp+2Ch] [bp-6Ch]@20
    ObjectMemory *bestObject; // [sp+30h] [bp-68h]@11
    float timeToBeKilled; // [sp+34h] [bp-64h]@17
    int boatWeapon; // [sp+38h] [bp-60h]@9
    int zoneRating; // [sp+3Ch] [bp-5Ch]@70
    int specialRating2; // [sp+40h] [bp-58h]@66
    RGE_Static_Object *tempObj; // [sp+44h] [bp-54h]@14
    signed int killRating; // [sp+48h] [bp-50h]@51
    int bestAttackValue; // [sp+4Ch] [bp-4Ch]@11
    int specialRating3; // [sp+50h] [bp-48h]@68
    int i; // [sp+54h] [bp-44h]@11
    int dCRating; // [sp+58h] [bp-40h]@54
    signed int hpRating; // [sp+5Ch] [bp-3Ch]@48
    int distanceRating; // [sp+60h] [bp-38h]@45
    int unitIsPriest; // [sp+64h] [bp-34h]@9
    int numberNonSiegeTargets; // [sp+68h] [bp-30h]@11
    int randomRating; // [sp+6Ch] [bp-2Ch]@64
    int numberNonBoatTargets; // [sp+70h] [bp-28h]@11
    ObjectMemory oLimits; // [sp+74h] [bp-24h]@11

    v6 = this;
    result = TribeInformationAIModule::wonderToAttack(this, -1);
    v8 = 0;
    if ( result )
    {
        *validAttack = 1;
    }
    else
    {
        v9 = MainDecisionAIModule::object((MainDecisionAIModule *)&v6->md->vfptr, unitID);
        v10 = v9;
        unit = v9;
        if ( v9 && RGE_Static_Object::unitAI(v9) )
        {
            unitZone = RGE_Static_Object::currentZone(v10);
            v11 = v10->master_obj->id;
            if ( v11 == 35 || v11 == 36 || (siegeWeapon = 0, v11 == 11) )
                siegeWeapon = 1;
            boatWeapon = TribeInformationAIModule::isBoat(v10);
            unitIsPriest = 0;
            if ( v10->master_obj->object_group == 18 )
                unitIsPriest = 1;
            TribeInformationAIModule::findObjectMemoryLimits(
                v6,
                &oLimits,
                ownerID,
                unitID,
                &numberNonSiegeTargets,
                &numberNonBoatTargets);
            bestObject = 0;
            bestAttackValue = -1;
            i = 0;
            if ( v6->maxImportantObjectMemory > 0 )
            {
                v55 = 0;
                do
                {
                    v12 = (int)&v6->importantObjectMemory->id + v8;
                    if ( *(_BYTE *)(v12 + 11) == ownerID )
                    {
                        v13 = MainDecisionAIModule::object((MainDecisionAIModule *)&v6->md->vfptr, *(_DWORD *)v12);
                        v14 = v13;
                        tempObj = v13;
                        if ( v13 )
                        {
                            if ( v13->object_state <= 2u )
                            {
                                v15 = TribeInformationAIModule::damagePerSecond(
                                                v6,
                                                unitID,
                                                (signed __int64)v13->world_x,
                                                (signed __int64)v13->world_y);
                                *(float *)&rOFRating = v15;
                                (*((void (**)(RGE_Static_Object *, RGE_Static_Object *))&v14->vfptr->rateOfFire + 1))(
                                    v14,
                                    v10);
                                *(float *)&v16 = v15;
                                v10->vfptr->rateOfFire(v10);
                                v17 = *(float *)&v16 / v15;
                                timeToBeKilled = *(float *)&rOFRating <= 0.0 ? -1.0 : (float)(v10->hp / *(float *)&rOFRating);
                                timeToKill = v17 <= 0.0 ? -1.0 : (float)((double)*(__int16 *)((char *)&v6->importantObjectMemory->hitPoints
                                                                                                                                                        + v8)
                                                                                                             / v17);
                                if ( siegeWeapon
                                    || !ignoreSiegeTargets
                                    || (v18 = v14->master_obj->object_group, v18 != 3) && v18 != 27
                                    || numberNonSiegeTargets <= 0 )
                                {
                                    if ( boatWeapon
                                        || !ignoreBoatTargets
                                        || (v19 = v14->master_obj, v19->id != 45)
                                        && (v20 = v19->object_group, v20 != 2)
                                        && v20 != 21
                                        && v20 != 22
                                        && v20 != 20
                                        || numberNonBoatTargets <= 0 )
                                    {
                                        if ( !unitIsPriest
                                            || (v21 = RGE_Static_Object::unitAI(v10),
                                                    v21->vfptr->canConvert(v21, *(int *)((char *)&v6->importantObjectMemory->id + v8))) )
                                        {
                                            v22 = (int)&v6->importantObjectMemory->id + v8;
                                            v23 = (signed __int64)v14->world_x;
                                            v24 = *(_BYTE *)(v22 + 8) - v23;
                                            if ( v24 < 0 )
                                                v24 = -v24;
                                            v25 = (signed __int64)tempObj->world_y;
                                            v26 = *(_BYTE *)(v22 + 9) - (_DWORD)v25;
                                            if ( v26 < 0 )
                                                v26 = -v26;
                                            if ( v24 <= 5 && v26 <= 5 || RGE_Visible_Map::get_visible(v6->md->player->visible, v23, v25) == 15 )
                                            {
                                                v27 = (int)&v6->importantObjectMemory->id + v55;
                                                v28 = *(_BYTE *)(v27 + 8) - (unsigned int)(signed __int64)unit->world_x;
                                                v29 = (signed __int64)sqrt((double)(signed int)((*(_BYTE *)(v27 + 9)
                                                                                                                                             - (unsigned int)(signed __int64)unit->world_y)
                                                                                                                                            * (*(_BYTE *)(v27 + 9)
                                                                                                                                             - (unsigned int)(signed __int64)unit->world_y)
                                                                                                                                            + v28 * v28));
                                                if ( oLimits.id )
                                                    distanceRating = 100 - 100 * (signed int)v29 / oLimits.id;
                                                else
                                                    distanceRating = 100;
                                                if ( oLimits.hitPoints )
                                                    hpRating = 100 * *(_WORD *)(v27 + 12) / oLimits.hitPoints;
                                                else
                                                    hpRating = 100;
                                                if ( oLimits.kills )
                                                    killRating = 100 * *(_BYTE *)(v27 + 20) / (unsigned __int8)oLimits.kills;
                                                else
                                                    killRating = 100;
                                                if ( oLimits.damageCapability == 0.0 )
                                                    dCRating = 100;
                                                else
                                                    dCRating = (signed __int64)(*(float *)(v27 + 24) * 100.0 / oLimits.damageCapability);
                                                if ( *(float *)(v27 + 24) <= 0.0 )
                                                {
                                                    rangeRating = 0;
                                                    rOFRatinga = 0;
                                                }
                                                else
                                                {
                                                    if ( oLimits.range == 0.0 )
                                                        rangeRating = 100;
                                                    else
                                                        rangeRating = (signed __int64)(*(float *)(v27 + 32) * 100.0 / oLimits.range);
                                                    if ( oLimits.rateOfFire == 0.0 )
                                                        rOFRatinga = 100;
                                                    else
                                                        rOFRatinga = 100
                                                                             - (unsigned __int64)(signed __int64)(*(float *)(v27 + 28)
                                                                                                                                                    * 100.0
                                                                                                                                                    / oLimits.rateOfFire);
                                                }
                                                v30 = debug_rand(aCMsdevWorkA_52, 3638);
                                                v31 = &v6->md->tacticalAI;
                                                specialRating1 = 0;
                                                randomRating = v30 % 100;
                                                if ( *(__int16 *)((char *)&v6->importantObjectMemory->type + v55) == TribeTacticalAIModule::strategicNumber(
                                                                                                                                                                                             v31,
                                                                                                                                                                                             106) )
                                                    specialRating1 = 1;
                                                specialRating2 = 0;
                                                if ( *(__int16 *)((char *)&v6->importantObjectMemory->type + v55) == TribeTacticalAIModule::strategicNumber(
                                                                                                                                                                                             &v6->md->tacticalAI,
                                                                                                                                                                                             107) )
                                                    specialRating2 = 1;
                                                specialRating3 = 0;
                                                if ( *(__int16 *)((char *)&v6->importantObjectMemory->type + v55) == TribeTacticalAIModule::strategicNumber(
                                                                                                                                                                                             &v6->md->tacticalAI,
                                                                                                                                                                                             108) )
                                                    specialRating3 = 1;
                                                zoneRating = 0;
                                                if ( unitZone == RGE_Static_Object::lookupZone(
                                                                                     unit,
                                                                                     (signed __int64)tempObj->world_x,
                                                                                     (signed __int64)tempObj->world_y) )
                                                    zoneRating = 1;
                                                v32 = tempObj->master_obj;
                                                v33 = v32->object_group;
                                                if ( v33 != 3 && v33 != 27 )
                                                    v34 = siegeWeapon != 0 ? -1 : 1;
                                                else
                                                    v34 = siegeWeapon != 0 ? 1 : -1;
                                                if ( v32->id != 45 && v33 != 2 && v33 != 21 && v33 != 22 && v33 != 20 )
                                                    v35 = boatWeapon != 0 ? -1 : 1;
                                                else
                                                    v35 = boatWeapon != 0 ? 1 : -1;
                                                v36 = *(int *)((char *)&v6->importantObjectMemory->attackAttempts + v55)
                                                        * TribeTacticalAIModule::strategicNumber(&v6->md->tacticalAI, 89);
                                                v37 = v35 * TribeTacticalAIModule::strategicNumber(&v6->md->tacticalAI, 144) + v36;
                                                v38 = v34 * TribeTacticalAIModule::strategicNumber(&v6->md->tacticalAI, 123) + v37;
                                                v39 = zoneRating * TribeTacticalAIModule::strategicNumber(&v6->md->tacticalAI, 122) + v38;
                                                v40 = killRating * TribeTacticalAIModule::strategicNumber(&v6->md->tacticalAI, 80) + v39;
                                                v41 = TribeTacticalAIModule::strategicNumber(&v6->md->tacticalAI, 83);
                                                v42 = randomRating * v41 + v40;
                                                v43 = distanceRating * TribeTacticalAIModule::strategicNumber(&v6->md->tacticalAI, 77) + v42;
                                                v44 = specialRating3 * TribeTacticalAIModule::strategicNumber(&v6->md->tacticalAI, 111) + v43;
                                                v45 = rangeRating * TribeTacticalAIModule::strategicNumber(&v6->md->tacticalAI, 90) + v44;
                                                v46 = hpRating * TribeTacticalAIModule::strategicNumber(&v6->md->tacticalAI, 78) + v45;
                                                v47 = dCRating * TribeTacticalAIModule::strategicNumber(&v6->md->tacticalAI, 79) + v46;
                                                v48 = rOFRatinga * TribeTacticalAIModule::strategicNumber(&v6->md->tacticalAI, 82) + v47;
                                                v49 = specialRating2 * TribeTacticalAIModule::strategicNumber(&v6->md->tacticalAI, 110) + v48;
                                                v50 = specialRating1 * TribeTacticalAIModule::strategicNumber(&v6->md->tacticalAI, 109) + v49;
                                                if ( timeToKill > (double)timeToBeKilled && timeToBeKilled != -1.0 || timeToKill == -1.0 )
                                                    v50 = 1;
                                                if ( !bestObject || v50 > bestAttackValue )
                                                {
                                                    bestObject = (ObjectMemory *)((char *)v6->importantObjectMemory + v55);
                                                    bestAttackValue = v50;
                                                    *validAttack = 1;
                                                }
                                            }
                                            v10 = unit;
                                            v8 = v55;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    v51 = v6->maxImportantObjectMemory;
                    v8 += 36;
                    v53 = __OFSUB__(i + 1, v51);
                    v52 = i++ + 1 - v51 < 0;
                    v55 = v8;
                }
                while ( v52 ^ v53 );
            }
            result = bestObject;
        }
        else
        {
            result = 0;
        }
    }
    return result;
}

//----- (004DCF10) --------------------------------------------------------
ObjectMemory *TribeInformationAIModule::objectToAttackByGroup@<eax>(TribeInformationAIModule *this@<ecx>, double a2@<st0>, int ownerID, TacticalAIGroup *group, AttackState *attackState, unsigned int startTime, int a7, TacticalAIGroup *a8)
{
    TribeInformationAIModule *v8; // esi@1
    int v9; // eax@1
    RGE_Static_Object *v10; // eax@1
    RGE_Static_Object *v11; // ebx@1
    AttackState *v12; // edi@7
    int v13; // eax@9
    int v14; // eax@11
    int v15; // STC8_4@14
    float v16; // ST80_4@14
    int v17; // eax@14
    int v18; // edi@15
    int v20; // ebp@16
    int v21; // eax@17
    RGE_Static_Object *v22; // edi@17
    RGE_Static_ObjectVtbl *v23; // edi@20
    float v24; // ST80_4@20
    int v25; // eax@20
    ObjectMemory *v26; // ebp@24
    RGE_Static_ObjectVtbl *v27; // ebp@28
    float v28; // ST80_4@28
    float v29; // ST80_4@30
    TacticalAIGroup *v30; // edi@31
    int v31; // ebx@31
    bool v32; // zf@31
    bool v33; // sf@31
    int *v34; // edi@33
    int l; // eax@34
    int *v36; // edi@40
    int m; // eax@41
    int *v38; // edi@46
    int n; // eax@47
    int v40; // ecx@54
    int *v41; // eax@54
    int v42; // eax@60
    int v43; // edi@61
    int v44; // ebx@61
    unsigned int v45; // ebp@64
    int v46; // eax@65
    RGE_Static_Object *v47; // eax@66
    RGE_Static_Object *v48; // ebp@66
    char v49; // al@71
    char v50; // al@74
    int v51; // edi@78
    double v52; // st7@80
    signed int v53; // ecx@80
    UnitAIModule *v54; // eax@86
    float v55; // STB0_4@87
    double v56; // st7@87
    char v58; // c3@87
    int v59; // ebp@89
    unsigned int v60; // edi@89
    long double v61; // st7@89
    signed int v62; // edi@92
    int v63; // ebp@98
    int v64; // eax@99
    RGE_Static_Object *v65; // eax@99
    RGE_Static_Object *v66; // edi@99
    UnitAIModule *v67; // eax@101
    ObjectMemory *v68; // ecx@107
    int v69; // eax@107
    int v70; // ecx@107
    long double v71; // st7@107
    RGE_Static_Object *v72; // ebp@110
    __int16 v73; // ax@111
    double v74; // st7@113
    int v75; // STA8_4@116
    float v76; // STB0_4@116
    double v77; // st7@116
    int v78; // ecx@122
    RGE_Static_ObjectVtbl *v79; // edi@123
    float v80; // ST80_4@123
    float v81; // ST80_4@124
    int v82; // ebp@125
    int *v83; // edi@127
    int i; // eax@128
    int *v85; // edi@134
    int j; // eax@135
    int *v87; // edi@140
    int k; // eax@141
    int v89; // edx@147
    int v90; // ecx@151
    unsigned __int8 v91; // of@151
    int v92; // eax@155
    char tempZone; // [sp+97h] [bp-5Dh]@71
    char commanderZone; // [sp+98h] [bp-5Ch]@3
    float miscFactor; // [sp+9Ch] [bp-58h]@105
    ObjectMemory *wonder; // [sp+A0h] [bp-54h]@24
    ObjectMemory *wondera; // [sp+A0h] [bp-54h]@60
    RGE_Static_Object *commanderObj; // [sp+A4h] [bp-50h]@1
    float (*inProgressCount)(RGE_Static_Object *); // [sp+A8h] [bp-4Ch]@28
    int inProgressCounta; // [sp+A8h] [bp-4Ch]@78
    int inProgressCountb; // [sp+A8h] [bp-4Ch]@87
    int inProgressCountc; // [sp+A8h] [bp-4Ch]@98
    float (*inProgressCountd)(RGE_Static_Object *); // [sp+A8h] [bp-4Ch]@123
    int commanderIsBoat; // [sp+ACh] [bp-48h]@5
    RGE_Static_Object *targetDistance; // [sp+B0h] [bp-44h]@0
    float targetDistancea; // [sp+B0h] [bp-44h]@87
    float targetDistanceb; // [sp+B0h] [bp-44h]@89
    float targetDistancec; // [sp+B0h] [bp-44h]@116
    _DWORD *commanderIsPriest; // [sp+B4h] [bp-40h]@3
    float inProgressFactor; // [sp+B8h] [bp-3Ch]@97
    float zoneFactor; // [sp+BCh] [bp-38h]@95
    float targetRandomization; // [sp+C0h] [bp-34h]@92
    RGE_Static_Object *tempObj; // [sp+C4h] [bp-30h]@66
    int v114; // [sp+C8h] [bp-2Ch]@61
    float killsByTarget; // [sp+CCh] [bp-28h]@91
    float timeKillRatio; // [sp+D0h] [bp-24h]@89
    int unobstructibleGroupID; // [sp+D4h] [bp-20h]@0
    int unobstructibleGroupIDa; // [sp+D4h] [bp-20h]@94
    int unobstructibleGroupIDb; // [sp+D4h] [bp-20h]@122
    ManagedArray<int> wallObjects; // [sp+D8h] [bp-1Ch]@14
    int v121; // [sp+F0h] [bp-4h]@30

    v8 = this;
    v9 = TacticalAIGroup::commander(group);
    v10 = MainDecisionAIModule::object((MainDecisionAIModule *)&v8->md->vfptr, v9);
    v11 = v10;
    commanderObj = v10;
    if ( !v10 || !RGE_Static_Object::unitAI(v10) )
    {
        attackState->active = 0;
        return 0;
    }
    commanderZone = RGE_Static_Object::currentZone(v11);
    commanderIsPriest = 0;
    if ( v11->master_obj->object_group == 18 )
        commanderIsPriest = (_DWORD *)1;
    commanderIsBoat = 0;
    if ( TribeInformationAIModule::isBoat(v11) == 1 )
        commanderIsBoat = 1;
    v12 = attackState;
    if ( !attackState->active && group->objectsToDestroyOwnerValue == ownerID )
    {
        v13 = group->numberObjectsToDestroyValue;
        if ( v13 > 0 && group->objectsToDestroyCommanderZoneValue == (unsigned __int8)commanderZone )
        {
            v14 = TacticalAIGroup::objectToDestroy(group, v13 - 1);
            targetDistance = MainDecisionAIModule::object((MainDecisionAIModule *)&v8->md->vfptr, v14);
            if ( targetDistance )
            {
                if ( (*(int (__stdcall **)(_DWORD))&v8->md->player->vfptr->gap4[20])(targetDistance->owner->id) == 1
                    && targetDistance->object_state <= 2u )
                {
                    v15 = group->numberObjectsToDestroyValue;
                    ((void (*)(RGE_Static_Object *, _DWORD, signed int, signed int, signed int))v11->vfptr->weaponRange)(
                        v11,
                        0,
                        1,
                        -1,
                        -1);
                    v16 = a2;
                    v17 = TacticalAIGroup::objectToDestroy(group, (int)wallObjects.value - 1);
                    if ( (*(int (**)(RGE_Static_Object *, int, _DWORD))(unobstructibleGroupID + 404))(
                                 v11,
                                 v17,
                                 LODWORD(v16)) == 1 )
                    {
                        v18 = TacticalAIGroup::objectToDestroy(group, group->numberObjectsToDestroyValue - 1);
                        group->numberObjectsToDestroyValue = 0;
                        TacticalAIGroup::addObjectToDestroy(group, v18);
                        return TribeInformationAIModule::objectMemory(v8, v18);
                    }
                }
            }
            v20 = 0;
            if ( group->numberObjectsToDestroyValue - 1 <= 0 )
                goto LABEL_23;
            while ( 1 )
            {
                v21 = TacticalAIGroup::objectToDestroy(group, v20);
                v22 = MainDecisionAIModule::object((MainDecisionAIModule *)&v8->md->vfptr, v21);
                if ( v22 )
                {
                    if ( (*(int (__stdcall **)(_DWORD))&v8->md->player->vfptr->gap4[20])(v22->owner->id) == 1
                        && v22->object_state <= 2u )
                    {
                        v23 = v11->vfptr;
                        ((void (*)(RGE_Static_Object *, _DWORD, signed int, signed int, signed int))v11->vfptr->weaponRange)(
                            v11,
                            0,
                            1,
                            -1,
                            -1);
                        v24 = a2;
                        v25 = TacticalAIGroup::objectToDestroy(a8, v20);
                        if ( (*((int (**)(RGE_Static_Object *, int, _DWORD))&v23->pause + 1))(v11, v25, LODWORD(v24)) == 1 )
                            break;
                    }
                }
                if ( ++v20 >= group->numberObjectsToDestroyValue - 1 )
                {
                    v12 = attackState;
                    goto LABEL_23;
                }
            }
            v92 = TacticalAIGroup::objectToDestroy(group, v20);
            return TribeInformationAIModule::objectMemory(v8, v92);
        }
    }
LABEL_23:
    if ( v12->active )
    {
LABEL_60:
        v42 = v12->iterationIndex;
        wondera = (ObjectMemory *)v12->iterationIndex;
        if ( v42 < v8->maxImportantObjectMemory )
        {
            v43 = commanderIsBoat;
            v44 = 36 * v42;
            v114 = 36 * v42;
            while ( 1 )
            {
                if ( v42 > attackState->iterationIndex )
                {
                    v45 = v8->md->player->world->availableComputerPlayerUpdateTime;
                    if ( debug_timeGetTime() - startTime >= v45 )
                    {
                        attackState->iterationIndex = (int)wondera;
                        return 0;
                    }
                }
                v46 = (int)&v8->importantObjectMemory->id + v44;
                if ( *(_BYTE *)(v46 + 11) == ownerID )
                {
                    v47 = MainDecisionAIModule::object((MainDecisionAIModule *)&v8->md->vfptr, *(_DWORD *)v46);
                    v48 = v47;
                    tempObj = v47;
                    if ( v47 )
                    {
                        if ( v47->object_state <= 2u && v47->hp != 0.0 && (v43 || TribeInformationAIModule::isBoat(v47) != 1) )
                        {
                            v49 = RGE_Static_Object::lookupZone(
                                            commanderObj,
                                            (signed __int64)v48->world_x,
                                            (signed __int64)v48->world_y);
                            tempZone = v49;
                            if ( v43 || *(__int16 *)((char *)&v8->importantObjectMemory->type + v44) != 45 || commanderZone == v49 )
                            {
                                v50 = attackState->phase;
                                if ( (v50 || *(__int16 *)((char *)&v8->importantObjectMemory->group + v44) != 27)
                                    && (v50 != 1 || *(__int16 *)((char *)&v8->importantObjectMemory->group + v44) == 27) )
                                {
                                    inProgressCounta = (signed __int64)v48->world_x;
                                    v51 = *(&v8->importantObjectMemory->x + v44) - inProgressCounta;
                                    if ( v51 < 0 )
                                        v51 = -v51;
                                    v52 = v48->world_y;
                                    v53 = *(&v8->importantObjectMemory->y + v44) - (unsigned int)(signed __int64)v52;
                                    if ( v53 < 0 )
                                        v53 = -v53;
                                    if ( v51 <= 5 && v53 <= 5
                                        || RGE_Visible_Map::get_visible(v8->md->player->visible, inProgressCounta, (signed __int64)v52) == 15 )
                                    {
                                        if ( !commanderIsPriest
                                            || (v54 = RGE_Static_Object::unitAI(commanderObj),
                                                    v54->vfptr->canConvert(v54, *(int *)((char *)&v8->importantObjectMemory->id + v44))) )
                                        {
                                            v55 = TribeInformationAIModule::damageInflictedPerSecond(v8, v52, group, v48);
                                            *(float *)&inProgressCountb = v48->hp / v55;
                                            v56 = TribeInformationAIModule::timeToBeKilled(v8, group, v48);
                                            targetDistancea = v56;
                                            if ( !v58 && targetDistancea != 0.0 )
                                            {
                                                v59 = (int)&v8->importantObjectMemory->id + v44;
                                                timeKillRatio = targetDistancea / *(float *)&inProgressCountb;
                                                v60 = *(_BYTE *)(v59 + 8) - (unsigned int)(signed __int64)commanderObj->world_x;
                                                v61 = sqrt((double)(signed int)((*(_BYTE *)(v59 + 9)
                                                                                                             - (unsigned int)(signed __int64)commanderObj->world_y)
                                                                                                            * (*(_BYTE *)(v59 + 9)
                                                                                                             - (unsigned int)(signed __int64)commanderObj->world_y)
                                                                                                            + v60 * v60));
                                                targetDistanceb = v61;
                                                if ( v61 < 1.0 )
                                                    targetDistanceb = 1.0;
                                                killsByTarget = (double)*(_BYTE *)(v59 + 20);
                                                if ( TribeTacticalAIModule::strategicNumber(&v8->md->tacticalAI, 83) <= 0 )
                                                {
                                                    targetRandomization = 0.0;
                                                }
                                                else
                                                {
                                                    v62 = TribeTacticalAIModule::strategicNumber(&v8->md->tacticalAI, 83);
                                                    targetRandomization = (double)(debug_rand(aCMsdevWorkA_52, 4053) % v62);
                                                }
                                                *(float *)&unobstructibleGroupIDa = (double)TribeTacticalAIModule::strategicNumber(
                                                                                                                                            &v8->md->tacticalAI,
                                                                                                                                            89)
                                                                                                                    * (double)*(int *)((char *)&v8->importantObjectMemory->attackAttempts
                                                                                                                                                     + v44);
                                                if ( commanderZone == tempZone )
                                                    zoneFactor = (double)TribeTacticalAIModule::strategicNumber(&v8->md->tacticalAI, 122);
                                                else
                                                    zoneFactor = 0.0;
                                                inProgressFactor = 0.0;
                                                if ( TribeTacticalAIModule::strategicNumber(&v8->md->tacticalAI, 185) > 0 )
                                                {
                                                    v63 = 0;
                                                    for ( inProgressCountc = 0; v63 < TacticalAIGroup::numberUnits(group); ++v63 )
                                                    {
                                                        v64 = TacticalAIGroup::unit(group, v63);
                                                        v65 = MainDecisionAIModule::object((MainDecisionAIModule *)&v8->md->vfptr, v64);
                                                        v66 = v65;
                                                        if ( v65 )
                                                        {
                                                            if ( RGE_Static_Object::unitAI(v65) )
                                                            {
                                                                v67 = RGE_Static_Object::unitAI(v66);
                                                                if ( UnitAIModule::currentTarget(v67) == *(int *)((char *)&v8->importantObjectMemory->id
                                                                                                                                                                + v44) )
                                                                    ++inProgressCountc;
                                                            }
                                                        }
                                                    }
                                                    inProgressFactor = (double)TribeTacticalAIModule::strategicNumber(&v8->md->tacticalAI, 185)
                                                                                     * (double)inProgressCountc;
                                                }
                                                miscFactor = 0.0;
                                                if ( attackState->phase == 1 && attackState->bestNonWallTargetID != -1 )
                                                {
                                                    v68 = v8->importantObjectMemory;
                                                    v69 = *(&v68->x + v44) - v68[attackState->bestNonWallTargetMemoryIndex].x;
                                                    v70 = *(&v68->y + v44) - v68[attackState->bestNonWallTargetMemoryIndex].y;
                                                    v71 = sqrt((double)(v70 * v70 + v69 * v69));
                                                    if ( v71 >= 1.0 )
                                                        miscFactor = 25000.0 / v71;
                                                    else
                                                        miscFactor = 1000.0;
                                                }
                                                v72 = tempObj;
                                                if ( TribeInformationAIModule::isUnitBuilding(tempObj) == 1 )
                                                {
                                                    v73 = tempObj->master_obj->id;
                                                    if ( v73 == 109 || v73 == 45 )
                                                        v74 = miscFactor - -200.0;
                                                    else
                                                        v74 = miscFactor - -300.0;
                                                    miscFactor = v74;
                                                }
                                                *(float *)&v75 = (double)TribeTacticalAIModule::strategicNumber(&v8->md->tacticalAI, 80)
                                                                             * killsByTarget;
                                                v76 = (double)TribeTacticalAIModule::strategicNumber(&v8->md->tacticalAI, 77) / targetDistanceb
                                                        + *(float *)&v75;
                                                v77 = (double)TribeTacticalAIModule::strategicNumber(&v8->md->tacticalAI, 184) * timeKillRatio
                                                        + v76
                                                        + miscFactor
                                                        + inProgressFactor
                                                        + zoneFactor
                                                        + *(float *)&unobstructibleGroupIDa
                                                        + targetRandomization;
                                                targetDistancec = v77;
                                                if ( attackState->bestTargetID != -1 )
                                                {
                                                    v77 = targetDistancec;
                                                    if ( targetDistancec <= (double)attackState->bestTargetValue )
                                                        goto LABEL_151;
                                                    v72 = tempObj;
                                                }
                                                if ( !attackState->phase )
                                                {
                                                    v72->vfptr->maximumSpeed(v72);
                                                    if ( v77 == 0.0 )
                                                    {
                                                        attackState->bestNonWallTargetID = *(int *)((char *)&v8->importantObjectMemory->id + v44);
                                                        attackState->bestNonWallTargetMemoryIndex = (int)wondera;
                                                        attackState->bestNonWallTargetValue = targetDistancec;
                                                    }
                                                }
                                                v78 = attackState->phase != 0 ? 0xFFFFFFE4 : 0;
                                                wallObjects.value = 0;
                                                wallObjects.numberValue = 0;
                                                unobstructibleGroupIDb = v78 + 27;
                                                wallObjects.desiredNumberValue = 0;
                                                wallObjects.maximumSizeValue = 0;
                                                v121 = 1;
                                                if ( commanderZone != tempZone
                                                    || (v79 = commanderObj->vfptr,
                                                            inProgressCountd = commanderObj->vfptr->weaponRange,
                                                            ((void (*)(RGE_Static_Object *, _DWORD, signed int, signed int, signed int))inProgressCountd)(
                                                                commanderObj,
                                                                0,
                                                                1,
                                                                -1,
                                                                -1),
                                                            v80 = v77,
                                                            (*((int (**)(RGE_Static_Object *, _DWORD, _DWORD))&v79->pause + 1))(
                                                                commanderObj,
                                                                *(int *)((char *)&v8->importantObjectMemory->id + v44),
                                                                LODWORD(v80)) == 1)
                                                    || (((void (*)(RGE_Static_Object *, _DWORD, signed int, int, int, ManagedArray<int> *))inProgressCountd)(
                                                                commanderObj,
                                                                0,
                                                                1,
                                                                ownerID,
                                                                unobstructibleGroupIDb,
                                                                &wallObjects),
                                                            v81 = v77,
                                                            ((int (*)(RGE_Static_Object *, _DWORD, _DWORD))v79->canPathWithObstructions)(
                                                                commanderObj,
                                                                *(int *)((char *)&v8->importantObjectMemory->id + v44),
                                                                LODWORD(v81)) == 1) )
                                                {
                                                    v82 = 0;
                                                    v32 = wallObjects.numberValue == 0;
                                                    v33 = wallObjects.numberValue < 0;
                                                    group->numberObjectsToDestroyValue = 0;
                                                    if ( !v33 && !v32 )
                                                    {
                                                        do
                                                        {
                                                            if ( v82 > wallObjects.maximumSizeValue - 1 )
                                                            {
                                                                v83 = (int *)operator new(4 * v82 + 4);
                                                                if ( v83 )
                                                                {
                                                                    for ( i = 0; i < wallObjects.maximumSizeValue; v83[i - 1] = wallObjects.value[i - 1] )
                                                                    {
                                                                        if ( i >= v82 + 1 )
                                                                            break;
                                                                        ++i;
                                                                    }
                                                                    operator delete(wallObjects.value);
                                                                    wallObjects.value = v83;
                                                                    wallObjects.maximumSizeValue = v82 + 1;
                                                                }
                                                            }
                                                            if ( MainDecisionAIModule::object(
                                                                         (MainDecisionAIModule *)&v8->md->vfptr,
                                                                         wallObjects.value[v82]) )
                                                            {
                                                                if ( v82 > wallObjects.maximumSizeValue - 1 )
                                                                {
                                                                    v85 = (int *)operator new(4 * v82 + 4);
                                                                    if ( v85 )
                                                                    {
                                                                        for ( j = 0; j < wallObjects.maximumSizeValue; v85[j - 1] = wallObjects.value[j - 1] )
                                                                        {
                                                                            if ( j >= v82 + 1 )
                                                                                break;
                                                                            ++j;
                                                                        }
                                                                        operator delete(wallObjects.value);
                                                                        wallObjects.value = v85;
                                                                        wallObjects.maximumSizeValue = v82 + 1;
                                                                    }
                                                                }
                                                                TribeInformationAIModule::addImportantObject(v8, v77, wallObjects.value[v82]);
                                                                if ( v82 > wallObjects.maximumSizeValue - 1 )
                                                                {
                                                                    v87 = (int *)operator new(4 * v82 + 4);
                                                                    if ( v87 )
                                                                    {
                                                                        for ( k = 0; k < wallObjects.maximumSizeValue; v87[k - 1] = wallObjects.value[k - 1] )
                                                                        {
                                                                            if ( k >= v82 + 1 )
                                                                                break;
                                                                            ++k;
                                                                        }
                                                                        operator delete(wallObjects.value);
                                                                        wallObjects.value = v87;
                                                                        wallObjects.maximumSizeValue = v82 + 1;
                                                                    }
                                                                }
                                                                TacticalAIGroup::addObjectToDestroy(group, wallObjects.value[v82]);
                                                            }
                                                            ++v82;
                                                        }
                                                        while ( v82 < wallObjects.numberValue );
                                                    }
                                                    v44 = v114;
                                                    TacticalAIGroup::addObjectToDestroy(
                                                        group,
                                                        *(int *)((char *)&v8->importantObjectMemory->id + v114));
                                                    v89 = *(&v8->importantObjectMemory->owner + v114);
                                                    group->objectsToDestroyCommanderZoneValue = (unsigned __int8)commanderZone;
                                                    group->objectsToDestroyOwnerValue = v89;
                                                    attackState->bestTargetID = *(int *)((char *)&v8->importantObjectMemory->id + v114);
                                                    attackState->bestTargetMemoryIndex = (int)wondera;
                                                    attackState->bestTargetValue = targetDistancec;
                                                }
                                                v121 = -1;
                                                if ( wallObjects.value )
                                                {
                                                    operator delete(wallObjects.value);
                                                    wallObjects.value = 0;
                                                }
                                                wallObjects.numberValue = 0;
                                                wallObjects.desiredNumberValue = 0;
                                                wallObjects.maximumSizeValue = 0;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
LABEL_151:
                v90 = v8->maxImportantObjectMemory;
                v44 += 36;
                v91 = __OFSUB__((char *)&wondera->id + 1, v90);
                v33 = (signed int)&wondera->id + -v90 + 1 < 0;
                wondera = (ObjectMemory *)((char *)wondera + 1);
                v114 = v44;
                if ( !(v33 ^ v91) )
                {
                    v12 = attackState;
                    break;
                }
                v43 = commanderIsBoat;
                v42 = (int)wondera;
            }
        }
        if ( v12->bestTargetID != -1 )
        {
            ++v8->importantObjectMemory[v12->bestTargetMemoryIndex].attackAttempts;
            v12->active = 0;
            v92 = TacticalAIGroup::objectToDestroy(group, 0);
            return TribeInformationAIModule::objectMemory(v8, v92);
        }
        if ( v12->phase )
        {
            v12->active = 0;
        }
        else
        {
            v12->phase = 1;
            v12->iterationIndex = 0;
        }
        return 0;
    }
    v26 = TribeInformationAIModule::wonderToAttack(v8, -1);
    wonder = v26;
    if ( !v26 )
    {
LABEL_59:
        v12->bestTargetID = -1;
        LODWORD(v12->bestTargetValue) = -1082130432;
        v12->bestTargetMemoryIndex = -1;
        v12->iterationIndex = 0;
        v12->attackGroupID = -1;
        v12->playID = -1;
        v12->phase = 0;
        v12->bestNonWallTargetID = -1;
        LODWORD(v12->bestNonWallTargetValue) = -1082130432;
        v12->bestNonWallTargetMemoryIndex = -1;
        v12->active = 1;
        goto LABEL_60;
    }
    if ( RGE_Static_Object::lookupZone(v11, v26->x, v26->y) != commanderZone && !commanderIsBoat )
        return v26;
    v27 = v11->vfptr;
    inProgressCount = v11->vfptr->weaponRange;
    ((void (*)(RGE_Static_Object *, _DWORD, signed int, signed int, signed int))inProgressCount)(
        v11,
        0,
        1,
        -1,
        -1);
    v28 = a2;
    if ( (*((int (**)(RGE_Static_Object *, RGE_Static_ObjectVtbl *, _DWORD))&v27->pause + 1))(
                 v11,
                 targetDistance->vfptr,
                 LODWORD(v28)) == 1 )
    {
        group->numberObjectsToDestroyValue = 0;
        TacticalAIGroup::addObjectToDestroy(group, wonder->id);
        group->objectsToDestroyOwnerValue = wonder->owner;
        group->objectsToDestroyCommanderZoneValue = (unsigned __int8)commanderZone;
        return wonder;
    }
    wallObjects.value = 0;
    wallObjects.numberValue = 0;
    wallObjects.desiredNumberValue = 0;
    wallObjects.maximumSizeValue = 0;
    v121 = 0;
    ((void (*)(RGE_Static_Object *, _DWORD, signed int, int, signed int, ManagedArray<int> *))inProgressCount)(
        v11,
        0,
        1,
        ownerID,
        27,
        &wallObjects);
    v29 = a2;
    if ( ((int (*)(RGE_Static_Object *, _DWORD, _DWORD))v27->canPathWithObstructions)(
                 v11,
                 *commanderIsPriest,
                 LODWORD(v29)) != 1 )
    {
        v121 = -1;
        if ( wallObjects.value )
            operator delete(wallObjects.value);
        goto LABEL_59;
    }
    v30 = group;
    v31 = 0;
    v32 = wallObjects.numberValue == 0;
    v33 = wallObjects.numberValue < 0;
    group->numberObjectsToDestroyValue = 0;
    if ( !v33 && !v32 )
    {
        do
        {
            if ( v31 > wallObjects.maximumSizeValue - 1 )
            {
                v34 = (int *)operator new(4 * v31 + 4);
                if ( v34 )
                {
                    for ( l = 0; l < wallObjects.maximumSizeValue; v34[l - 1] = wallObjects.value[l - 1] )
                    {
                        if ( l >= v31 + 1 )
                            break;
                        ++l;
                    }
                    operator delete(wallObjects.value);
                    wallObjects.value = v34;
                    wallObjects.maximumSizeValue = v31 + 1;
                }
            }
            if ( MainDecisionAIModule::object((MainDecisionAIModule *)&v8->md->vfptr, wallObjects.value[v31]) )
            {
                if ( v31 > wallObjects.maximumSizeValue - 1 )
                {
                    v36 = (int *)operator new(4 * v31 + 4);
                    if ( v36 )
                    {
                        for ( m = 0; m < wallObjects.maximumSizeValue; v36[m - 1] = wallObjects.value[m - 1] )
                        {
                            if ( m >= v31 + 1 )
                                break;
                            ++m;
                        }
                        operator delete(wallObjects.value);
                        wallObjects.value = v36;
                        wallObjects.maximumSizeValue = v31 + 1;
                    }
                }
                TribeInformationAIModule::addImportantObject(v8, a2, wallObjects.value[v31]);
                if ( v31 > wallObjects.maximumSizeValue - 1 )
                {
                    v38 = (int *)operator new(4 * v31 + 4);
                    if ( v38 )
                    {
                        for ( n = 0; n < wallObjects.maximumSizeValue; v38[n - 1] = wallObjects.value[n - 1] )
                        {
                            if ( n >= v31 + 1 )
                                break;
                            ++n;
                        }
                        operator delete(wallObjects.value);
                        wallObjects.value = v38;
                        wallObjects.maximumSizeValue = v31 + 1;
                    }
                }
                TacticalAIGroup::addObjectToDestroy(group, wallObjects.value[v31]);
            }
            ++v31;
        }
        while ( v31 < wallObjects.numberValue );
        v30 = group;
    }
    TacticalAIGroup::addObjectToDestroy(v30, wonder->id);
    v40 = wonder->owner;
    v30->objectsToDestroyCommanderZoneValue = (unsigned __int8)commanderZone;
    v41 = wallObjects.value;
    v32 = wallObjects.value == 0;
    v30->objectsToDestroyOwnerValue = v40;
    v121 = -1;
    if ( !v32 )
        operator delete(v41);
    return wonder;
}
// 4DD62E: inconsistent fpu stack

//----- (004DDD40) --------------------------------------------------------
ObjectMemory *TribeInformationAIModule::objectToAttackByGroup2(int ownerID, int *soldiers, int numberSoldiers)
{
    TribeInformationAIModule *v4; // esi@1
    ObjectMemory *result; // eax@1
    int v6; // ebp@1
    RGE_Static_Object *v7; // eax@3
    RGE_Static_Object *v8; // edi@3
    int v9; // eax@9
    RGE_Static_Object *v10; // eax@10
    RGE_Static_Object *v11; // edi@10
    int v12; // ebp@13
    int v13; // ebx@13
    double v14; // st7@15
    signed int v15; // ecx@15
    UnitAIModule *v16; // eax@21
    float v17; // ST2C_4@22
    int v18; // ebx@24
    unsigned int v19; // ebp@24
    long double v20; // st7@24
    signed int v21; // ebx@27
    int *v22; // ebx@34
    RGE_Static_Object *v23; // eax@35
    RGE_Static_Object *v24; // edi@35
    UnitAIModule *v25; // eax@37
    float v26; // ST4C_4@41
    float v27; // ST4C_4@41
    double v28; // st7@41
    int v29; // ecx@44
    bool v30; // sf@44
    unsigned __int8 v31; // of@44
    char commanderZone; // [sp+13h] [bp-3Dh]@5
    int v33; // [sp+14h] [bp-3Ch]@8
    RGE_Static_Object *commanderObj; // [sp+18h] [bp-38h]@3
    int inProgressCount; // [sp+1Ch] [bp-34h]@22
    int inProgressCounta; // [sp+1Ch] [bp-34h]@33
    int targetDistance; // [sp+20h] [bp-30h]@13
    float targetDistancea; // [sp+20h] [bp-30h]@24
    ObjectMemory *bestObject; // [sp+24h] [bp-2Ch]@7
    int commanderIsPriest; // [sp+28h] [bp-28h]@5
    float inProgressFactor; // [sp+2Ch] [bp-24h]@32
    int inProgressFactora; // [sp+2Ch] [bp-24h]@34
    float zoneFactor; // [sp+30h] [bp-20h]@30
    float targetRandomization; // [sp+34h] [bp-1Ch]@27
    float bestAttackValue; // [sp+38h] [bp-18h]@7
    int i; // [sp+3Ch] [bp-14h]@7
    float timeTK; // [sp+40h] [bp-10h]@22
    float timeKillRatio; // [sp+44h] [bp-Ch]@24
    float killsByTarget; // [sp+48h] [bp-8h]@26
    float attackAttemptFactor; // [sp+4Ch] [bp-4h]@29

    v4 = this;
    result = TribeInformationAIModule::wonderToAttack(this, -1);
    v6 = 0;
    if ( !result )
    {
        if ( numberSoldiers
            && (v7 = MainDecisionAIModule::object((MainDecisionAIModule *)&v4->md->vfptr, *soldiers),
                    v8 = v7,
                    (commanderObj = v7) != 0)
            && RGE_Static_Object::unitAI(v7) )
        {
            commanderZone = RGE_Static_Object::currentZone(v8);
            commanderIsPriest = 0;
            if ( v8->master_obj->object_group == 18 )
                commanderIsPriest = 1;
            bestObject = 0;
            bestAttackValue = -1.0;
            i = 0;
            if ( v4->maxImportantObjectMemory > 0 )
            {
                v33 = 0;
                do
                {
                    v9 = (int)&v4->importantObjectMemory->id + v6;
                    if ( *(_BYTE *)(v9 + 11) == ownerID )
                    {
                        v10 = MainDecisionAIModule::object((MainDecisionAIModule *)&v4->md->vfptr, *(_DWORD *)v9);
                        v11 = v10;
                        if ( v10 )
                        {
                            if ( v10->object_state <= 2u && v10->hp != 0.0 )
                            {
                                v12 = (int)&v4->importantObjectMemory->id + v6;
                                targetDistance = (signed __int64)v10->world_x;
                                v13 = *(_BYTE *)(v12 + 8) - targetDistance;
                                if ( v13 < 0 )
                                    v13 = -v13;
                                v14 = v10->world_y;
                                v15 = *(_BYTE *)(v12 + 9) - (unsigned int)(signed __int64)v14;
                                if ( v15 < 0 )
                                    v15 = -v15;
                                if ( v13 <= 5 && v15 <= 5
                                    || RGE_Visible_Map::get_visible(v4->md->player->visible, targetDistance, (signed __int64)v14) == 15 )
                                {
                                    if ( !commanderIsPriest
                                        || (v16 = RGE_Static_Object::unitAI(commanderObj),
                                                v16->vfptr->canConvert(v16, v4->importantObjectMemory[v33].id)) )
                                    {
                                        v17 = TribeInformationAIModule::damageInflictedPerSecond(v4, v14, soldiers, numberSoldiers, v11);
                                        timeTK = v11->hp / v17;
                                        *(float *)&inProgressCount = TribeInformationAIModule::timeToBeKilled(
                                                                                                     v4,
                                                                                                     soldiers,
                                                                                                     numberSoldiers,
                                                                                                     v11);
                                        if ( v17 != 0.0 && *(float *)&inProgressCount != 0.0 )
                                        {
                                            v18 = (int)&v4->importantObjectMemory[v33].id;
                                            timeKillRatio = *(float *)&inProgressCount / timeTK;
                                            v19 = *(_BYTE *)(v18 + 8) - (unsigned int)(signed __int64)commanderObj->world_x;
                                            v20 = sqrt((double)(signed int)((*(_BYTE *)(v18 + 9)
                                                                                                         - (unsigned int)(signed __int64)commanderObj->world_y)
                                                                                                        * (*(_BYTE *)(v18 + 9)
                                                                                                         - (unsigned int)(signed __int64)commanderObj->world_y)
                                                                                                        + v19 * v19));
                                            targetDistancea = v20;
                                            if ( v20 < 1.0 )
                                                targetDistancea = 1.0;
                                            killsByTarget = (double)*(_BYTE *)(v18 + 20);
                                            if ( TribeTacticalAIModule::strategicNumber(&v4->md->tacticalAI, 83) <= 0 )
                                            {
                                                targetRandomization = 0.0;
                                            }
                                            else
                                            {
                                                v21 = TribeTacticalAIModule::strategicNumber(&v4->md->tacticalAI, 83);
                                                targetRandomization = (double)(debug_rand(aCMsdevWorkA_52, 4363) % v21);
                                            }
                                            attackAttemptFactor = (double)TribeTacticalAIModule::strategicNumber(&v4->md->tacticalAI, 89)
                                                                                    * (double)v4->importantObjectMemory[v33].attackAttempts;
                                            if ( commanderZone == RGE_Static_Object::lookupZone(
                                                                                            commanderObj,
                                                                                            (signed __int64)v11->world_x,
                                                                                            (signed __int64)v11->world_y) )
                                                zoneFactor = (double)TribeTacticalAIModule::strategicNumber(&v4->md->tacticalAI, 122);
                                            else
                                                zoneFactor = 0.0;
                                            inProgressFactor = 0.0;
                                            if ( TribeTacticalAIModule::strategicNumber(&v4->md->tacticalAI, 185) > 0 )
                                            {
                                                inProgressCounta = 0;
                                                if ( numberSoldiers > 0 )
                                                {
                                                    v22 = soldiers;
                                                    inProgressFactora = numberSoldiers;
                                                    do
                                                    {
                                                        v23 = MainDecisionAIModule::object((MainDecisionAIModule *)&v4->md->vfptr, *v22);
                                                        v24 = v23;
                                                        if ( v23 )
                                                        {
                                                            if ( RGE_Static_Object::unitAI(v23) )
                                                            {
                                                                v25 = RGE_Static_Object::unitAI(v24);
                                                                if ( UnitAIModule::currentTarget(v25) == v4->importantObjectMemory[v33].id )
                                                                    ++inProgressCounta;
                                                            }
                                                        }
                                                        ++v22;
                                                        --inProgressFactora;
                                                    }
                                                    while ( inProgressFactora );
                                                }
                                                inProgressFactor = (double)TribeTacticalAIModule::strategicNumber(&v4->md->tacticalAI, 185)
                                                                                 * (double)inProgressCounta;
                                            }
                                            v26 = (double)TribeTacticalAIModule::strategicNumber(&v4->md->tacticalAI, 184) * timeKillRatio;
                                            v27 = (double)TribeTacticalAIModule::strategicNumber(&v4->md->tacticalAI, 77) / targetDistancea
                                                    + v26;
                                            v28 = (double)TribeTacticalAIModule::strategicNumber(&v4->md->tacticalAI, 80) * killsByTarget
                                                    + v27
                                                    + inProgressFactor
                                                    + zoneFactor
                                                    + attackAttemptFactor
                                                    + targetRandomization;
                                            if ( !bestObject || v28 > bestAttackValue )
                                            {
                                                bestAttackValue = v28;
                                                bestObject = &v4->importantObjectMemory[v33];
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    v29 = v4->maxImportantObjectMemory;
                    v6 = v33 * 36 + 36;
                    v31 = __OFSUB__(i + 1, v29);
                    v30 = i++ + 1 - v29 < 0;
                    ++v33;
                }
                while ( v30 ^ v31 );
            }
            result = bestObject;
        }
        else
        {
            result = 0;
        }
    }
    return result;
}
// 4DDEC1: inconsistent fpu stack

//----- (004DE1F0) --------------------------------------------------------
ObjectMemory *TribeInformationAIModule::objectToDefend(int unitID)
{
    TribeInformationAIModule *v2; // esi@1
    int v3; // ebx@1
    ObjectMemory *result; // eax@2
    int v5; // ecx@4
    int v6; // edi@5
    int v7; // eax@5
    int v8; // eax@11
    int v9; // eax@12
    int bestDefendValue; // [sp+8h] [bp-10h]@3
    int i; // [sp+Ch] [bp-Ch]@3
    XYPoint objPoint; // [sp+10h] [bp-8h]@11
    ObjectMemory *unitIDa; // [sp+1Ch] [bp+4h]@3

    v2 = this;
    v3 = 0;
    if ( MainDecisionAIModule::object((MainDecisionAIModule *)&this->md->vfptr, unitID) )
    {
        unitIDa = 0;
        bestDefendValue = -1;
        for ( i = 0; i < v2->maxImportantObjectMemory; ++i )
        {
            v5 = (int)&v2->importantObjectMemory[v3].id;
            if ( *(_DWORD *)v5 != -1 )
            {
                v6 = v2->itemsToDefend.numberValue;
                v7 = 0;
                if ( v6 > 0 )
                {
                    while ( v7 < v2->itemsToDefend.maximumSizeValue )
                    {
                        if ( v2->itemsToDefend.value[v7] == *(_DWORD *)v5 )
                        {
                            if ( *(_DWORD *)(v5 + 16) <= 0 )
                            {
                                objPoint.x = *(_BYTE *)(v5 + 8);
                                objPoint.y = *(_BYTE *)(v5 + 9);
                                v8 = TribeTacticalAIModule::strategicNumber(&v2->md->tacticalAI, 92);
                                if ( !TribeTacticalAIModule::bestGroup(&v2->md->tacticalAI, -1, 4, v8, &objPoint, -1) )
                                {
                                    v9 = TribeInformationAIModule::defendPriority(
                                                 v2,
                                                 v2->importantObjectMemory[v3].type,
                                                 v2->importantObjectMemory[v3].group);
                                    if ( !unitIDa || bestDefendValue > v9 )
                                    {
                                        bestDefendValue = v9;
                                        unitIDa = &v2->importantObjectMemory[v3];
                                    }
                                }
                            }
                            break;
                        }
                        if ( ++v7 >= v6 )
                            break;
                    }
                }
            }
            ++v3;
        }
        result = unitIDa;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (004DE330) --------------------------------------------------------
ObjectMemory *TribeInformationAIModule::higherPriorityObjectToDefend(int unitID, int oType, int oGroup)
{
    TribeInformationAIModule *v4; // esi@1
    RGE_Static_Object *v5; // eax@1
    int v6; // ebp@1
    ObjectMemory *result; // eax@2
    ObjectMemory *v8; // eax@4
    int v9; // ecx@4
    int v10; // edi@4
    int v11; // edx@5
    int v12; // eax@5
    RGE_Static_Object *v13; // eax@11
    RGE_Static_Object *v14; // edi@11
    double v15; // st7@13
    RGE_Static_ObjectVtbl *v16; // edx@13
    float range; // ST04_4@13
    int v18; // eax@14
    ObjectMemory *bestObject; // [sp+18h] [bp-10h]@3
    RGE_Static_Object *unit; // [sp+1Ch] [bp-Ch]@1
    XYPoint point; // [sp+20h] [bp-8h]@13
    char unitIDa; // [sp+2Ch] [bp+4h]@3
    int currentZone; // [sp+30h] [bp+8h]@3
    int i; // [sp+34h] [bp+Ch]@3

    v4 = this;
    v5 = MainDecisionAIModule::object((MainDecisionAIModule *)&this->md->vfptr, unitID);
    v6 = 0;
    unit = v5;
    if ( v5 )
    {
        unitIDa = RGE_Static_Object::currentZone(v5);
        bestObject = 0;
        i = TribeInformationAIModule::defendPriority(v4, oType, oGroup);
        for ( currentZone = 0; currentZone < v4->maxImportantObjectMemory; ++currentZone )
        {
            v8 = v4->importantObjectMemory;
            v9 = v8[v6].id;
            v10 = (int)&v8[v6].id;
            if ( v9 != -1 )
            {
                v11 = v4->itemsToDefend.numberValue;
                v12 = 0;
                if ( v11 > 0 )
                {
                    while ( v12 < v4->itemsToDefend.maximumSizeValue )
                    {
                        if ( v4->itemsToDefend.value[v12] == v9 )
                        {
                            if ( *(_DWORD *)(v10 + 16) <= 0 )
                            {
                                v13 = MainDecisionAIModule::object((MainDecisionAIModule *)&v4->md->vfptr, v9);
                                v14 = v13;
                                if ( v13 )
                                {
                                    if ( unitIDa == RGE_Static_Object::currentZone(v13)
                                        || (point.x = (signed __int64)v14->world_x,
                                                v15 = v14->world_y,
                                                v16 = unit->vfptr,
                                                point.y = (signed __int64)v15,
                                                v16->weaponRange(unit),
                                                range = v15,
                                                RGE_Static_Object::withinRangeOfZoneAtPoint(unit, unitIDa, range, &point) == 1) )
                                    {
                                        v18 = TribeInformationAIModule::defendPriority(
                                                        v4,
                                                        v4->importantObjectMemory[v6].type,
                                                        v4->importantObjectMemory[v6].group);
                                        if ( i > v18 )
                                        {
                                            i = v18;
                                            bestObject = &v4->importantObjectMemory[v6];
                                        }
                                    }
                                }
                            }
                            break;
                        }
                        if ( ++v12 >= v11 )
                            break;
                    }
                }
            }
            ++v6;
        }
        result = bestObject;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (004DE4A0) --------------------------------------------------------
int TribeInformationAIModule::defendPriority(int oType, int oGroup)
{
    int result; // eax@2

    switch ( oType )
    {
        case 109:
            result = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI, 56);
            break;
        case 45:
            result = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI, 70);
            break;
        case 159:
            result = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI, 55);
            break;
        case 158:
        case 163:
            result = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI, 54);
            break;
        default:
            switch ( oGroup )
            {
                case 7:
                    result = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI, 52);
                    break;
                case 8:
                    result = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI, 51);
                    break;
                case 32:
                    result = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI, 50);
                    break;
                default:
                    result = -1;
                    break;
            }
            break;
    }
    return result;
}

//----- (004DE600) --------------------------------------------------------
int TribeInformationAIModule::checkDefend(RGE_Static_Object *o)
{
    RGE_Static_Object *v2; // edi@1
    TribeInformationAIModule *v3; // esi@1
    RGE_Master_Static_Object *v4; // eax@1
    int v5; // ecx@1
    TribeMainDecisionAIModule *v6; // eax@2
    int v7; // ecx@4
    int v8; // edi@4
    ManagedArray<int> *v9; // esi@4
    int v10; // eax@4
    TribeMainDecisionAIModule *v11; // eax@9
    int v12; // eax@11
    int v13; // eax@17
    int v14; // eax@23
    ManagedArray<int> *v16; // esi@34
    int v17; // eax@35
    ManagedArray<int> *v18; // esi@39
    int v19; // eax@40

    v2 = o;
    v3 = this;
    v4 = o->master_obj;
    v5 = o->owner->id;
    switch ( v4->id )
    {
        case 109:
            v6 = v3->md;
            if ( v5 != v6->player->id || TribeTacticalAIModule::strategicNumber(&v6->tacticalAI, 56) <= 0 )
                return 0;
            v7 = v3->itemsToDefend.numberValue;
            v8 = v2->id;
            v9 = &v3->itemsToDefend;
            v10 = 0;
            if ( v7 <= 0 )
                goto LABEL_27;
            while ( 1 )
            {
                if ( v10 >= v9->maximumSizeValue )
                    goto LABEL_27;
                if ( v9->value[v10] == v8 )
                    return 1;
                if ( ++v10 >= v7 )
                    goto LABEL_27;
            }
        case 45:
            v11 = v3->md;
            if ( v5 != v11->player->id || TribeTacticalAIModule::strategicNumber(&v11->tacticalAI, 70) <= 0 )
                return 0;
            v7 = v3->itemsToDefend.numberValue;
            v8 = v2->id;
            v9 = &v3->itemsToDefend;
            v12 = 0;
            if ( v7 <= 0 )
                goto LABEL_27;
            do
            {
                if ( v12 >= v9->maximumSizeValue )
                    break;
                if ( v9->value[v12] == v8 )
                    return 1;
                ++v12;
            }
            while ( v12 < v7 );
            goto LABEL_27;
        case 159:
            if ( TribeTacticalAIModule::strategicNumber(&v3->md->tacticalAI, 55) <= 0 )
                return 0;
            v7 = v3->itemsToDefend.numberValue;
            v8 = v2->id;
            v9 = &v3->itemsToDefend;
            v13 = 0;
            if ( v7 <= 0 )
                goto LABEL_27;
            do
            {
                if ( v13 >= v9->maximumSizeValue )
                    break;
                if ( v9->value[v13] == v8 )
                    return 1;
                ++v13;
            }
            while ( v13 < v7 );
            goto LABEL_27;
        case 158:
        case 163:
            if ( TribeTacticalAIModule::strategicNumber(&v3->md->tacticalAI, 54) <= 0 )
                return 0;
            v7 = v3->itemsToDefend.numberValue;
            v8 = v2->id;
            v9 = &v3->itemsToDefend;
            v14 = 0;
            if ( v7 <= 0 )
                goto LABEL_27;
            do
            {
                if ( v14 >= v9->maximumSizeValue )
                    break;
                if ( v9->value[v14] == v8 )
                    return 1;
                ++v14;
            }
            while ( v14 < v7 );
LABEL_27:
            if ( v7 > v9->maximumSizeValue - 1 )
                ManagedArray<int>::resize(v9, v7 + 1);
            v9->value[v9->numberValue++] = v8;
            return 1;
        default:
            if ( v4->object_group == 7 )
            {
                if ( TribeTacticalAIModule::strategicNumber(&v3->md->tacticalAI, 52) > 0 )
                {
                    ManagedArray<int>::add(&v3->itemsToDefend, v2->id);
                    return 1;
                }
                return 0;
            }
            if ( v4->object_group != 8 )
            {
                if ( v4->object_group == 32 && TribeTacticalAIModule::strategicNumber(&v3->md->tacticalAI, 50) > 0 )
                {
                    v16 = &v3->itemsToDefend;
                    o = (RGE_Static_Object *)v2->id;
                    if ( ManagedArray<int>::contains(v16, (const int *)&o) == 1 )
                        return 1;
                    v17 = v16->numberValue;
                    if ( v17 > v16->maximumSizeValue - 1 )
                        ManagedArray<int>::resize(v16, v17 + 1);
                    v16->value[v16->numberValue++] = (int)o;
                    return 1;
                }
                return 0;
            }
            if ( TribeTacticalAIModule::strategicNumber(&v3->md->tacticalAI, 51) <= 0 )
                return 0;
            v18 = &v3->itemsToDefend;
            o = (RGE_Static_Object *)v2->id;
            if ( ManagedArray<int>::contains(v18, (const int *)&o) == 1 )
                return 1;
            v19 = v18->numberValue;
            if ( v19 > v18->maximumSizeValue - 1 )
                ManagedArray<int>::resize(v18, v19 + 1);
            v18->value[v18->numberValue++] = (int)o;
            return 1;
    }
}

//----- (004DE980) --------------------------------------------------------
int ManagedArray<int>::contains(ManagedArray<int> *this, const int *r)
{
    int v2; // edx@1
    int v3; // eax@1

    v2 = this->numberValue;
    v3 = 0;
    if ( v2 > 0 )
    {
        while ( v3 < this->maximumSizeValue )
        {
            if ( this->value[v3] == *r )
                return 1;
            if ( ++v3 >= v2 )
                return 0;
        }
    }
    return 0;
}

//----- (004DE9D0) --------------------------------------------------------
int ManagedArray<int>::add(ManagedArray<int> *this, int r)
{
    ManagedArray<int> *v2; // esi@1
    int v3; // eax@1
    int v4; // ecx@1
    int v5; // ebx@6
    int *v6; // edi@6
    int i; // eax@7

    v2 = this;
    v3 = 0;
    v4 = this->numberValue;
    if ( v4 > 0 )
    {
        while ( v3 < v2->maximumSizeValue )
        {
            if ( v2->value[v3] == r )
                return 0;
            if ( ++v3 >= v4 )
                break;
        }
    }
    if ( v4 > v2->maximumSizeValue - 1 )
    {
        v5 = v4 + 1;
        v6 = (int *)operator new(4 * (v4 + 1));
        if ( v6 )
        {
            for ( i = 0; i < v2->maximumSizeValue; v6[i - 1] = v2->value[i - 1] )
            {
                if ( i >= v5 )
                    break;
                ++i;
            }
            operator delete(v2->value);
            v2->value = v6;
            v2->maximumSizeValue = v5;
        }
    }
    v2->value[v2->numberValue++] = r;
    return 1;
}

//----- (004DEA70) --------------------------------------------------------
int TribeInformationAIModule::numberItemsToDefend()
{
    return this->itemsToDefend.numberValue;
}

//----- (004DEA80) --------------------------------------------------------
ObjectMemory *TribeInformationAIModule::objectToTradeWith(int unitID)
{
    TribeInformationAIModule *v2; // ebx@1
    int v3; // ebp@1
    ObjectMemory *result; // eax@2
    ObjectMemory *v5; // ecx@4
    int v6; // edx@4
    int v7; // eax@4
    MainDecisionAIModule *v8; // ecx@5
    RGE_Static_Object *v9; // eax@7
    int v10; // edi@9
    unsigned int v11; // esi@9
    unsigned int v12; // edx@9
    RGE_Static_Object *unit; // [sp+8h] [bp-Ch]@1
    int bestDockDistance; // [sp+Ch] [bp-8h]@3
    int i; // [sp+10h] [bp-4h]@3
    ObjectMemory *unitIDa; // [sp+18h] [bp+4h]@3

    v2 = this;
    v3 = 0;
    unit = MainDecisionAIModule::object((MainDecisionAIModule *)&this->md->vfptr, unitID);
    if ( unit )
    {
        unitIDa = 0;
        bestDockDistance = 0;
        for ( i = 0; i < v2->maxImportantObjectMemory; ++i )
        {
            v5 = v2->importantObjectMemory;
            v6 = v5[v3].id;
            v7 = (int)&v5[v3].id;
            if ( v6 != -1 )
            {
                v8 = (MainDecisionAIModule *)&v2->md->vfptr;
                if ( *(_BYTE *)(v7 + 11) != v8->player->id && *(_WORD *)(v7 + 4) == 45 )
                {
                    v9 = MainDecisionAIModule::object(v8, v6);
                    if ( v9 )
                    {
                        if ( v9->owner->attributes[9] > 0.0 )
                        {
                            v10 = (int)&v2->importantObjectMemory[v3].id;
                            v11 = *(_BYTE *)(v10 + 8) - (unsigned int)(signed __int64)unit->world_x;
                            v12 = (*(_BYTE *)(v10 + 9) - (unsigned int)(signed __int64)unit->world_y)
                                    * (*(_BYTE *)(v10 + 9) - (unsigned int)(signed __int64)unit->world_y);
                            if ( !unitIDa || (signed int)(v12 + v11 * v11) < bestDockDistance )
                            {
                                unitIDa = &v2->importantObjectMemory[v3];
                                bestDockDistance = v12 + v11 * v11;
                            }
                        }
                    }
                }
            }
            ++v3;
        }
        result = unitIDa;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (004DEBA0) --------------------------------------------------------
int TribeInformationAIModule::findGatherPosition(XYPoint *centerPoint, int num, int landTroops, int desiredDistance, int maximumDistanceVariation, RGE_Static_Object *testUnit, XYPoint *rPoint)
{
    TribeInformationAIModule *v8; // ebp@1
    int result; // eax@2
    int v10; // eax@3
    int v11; // eax@3
    int v12; // eax@3
    int v13; // ebx@3
    int v14; // edi@4
    int v15; // esi@9
    signed int v16; // ebx@11
    int v17; // ebp@11
    int v18; // eax@12
    int v19; // esi@14
    float v20; // ST10_4@16
    float v21; // ST0C_4@16
    RGE_Static_ObjectVtbl *v22; // edx@21
    signed int v23; // ebp@21
    float v24; // ST0C_4@21
    int v25; // edi@23
    int v26; // eax@24
    int v27; // esi@26
    int v28; // eax@28
    int bestPointValue; // [sp+28h] [bp-54h]@3
    signed int j; // [sp+2Ch] [bp-50h]@14
    signed int i; // [sp+30h] [bp-4Ch]@11
    TribeInformationAIModule *v32; // [sp+34h] [bp-48h]@1
    signed int clearDistance; // [sp+38h] [bp-44h]@3
    XYPoint maxClear; // [sp+3Ch] [bp-40h]@10
    XYPoint max; // [sp+44h] [bp-38h]@3
    XYPoint minClear; // [sp+4Ch] [bp-30h]@9
    XYPoint min; // [sp+54h] [bp-28h]@3
    XYPoint minExclude; // [sp+5Ch] [bp-20h]@3
    XYPoint maxExclude; // [sp+64h] [bp-18h]@3
    XYPoint cPosition; // [sp+6Ch] [bp-10h]@21
    XYPoint lineCollisionPoint; // [sp+74h] [bp-8h]@21
    int numa; // [sp+84h] [bp+8h]@4
    int maximumDistanceVariationa; // [sp+90h] [bp+14h]@3

    v8 = this;
    v32 = this;
    if ( maximumDistanceVariation < desiredDistance )
    {
        v10 = centerPoint->x - desiredDistance - maximumDistanceVariation;
        min.y = centerPoint->y - desiredDistance - maximumDistanceVariation;
        min.x = v10;
        TribeInformationAIModule::mapBound(this, &min);
        v11 = desiredDistance + maximumDistanceVariation + centerPoint->x;
        max.y = centerPoint->y + maximumDistanceVariation + desiredDistance;
        max.x = v11;
        TribeInformationAIModule::mapBound(v8, &max);
        v12 = maximumDistanceVariation + centerPoint->x - desiredDistance;
        minExclude.y = centerPoint->y + maximumDistanceVariation - desiredDistance;
        minExclude.x = v12;
        TribeInformationAIModule::mapBound(v8, &minExclude);
        maxExclude.x = desiredDistance + centerPoint->x - maximumDistanceVariation;
        maxExclude.y = centerPoint->y + desiredDistance - maximumDistanceVariation;
        TribeInformationAIModule::mapBound(v8, &maxExclude);
        TribeInformationAIModule::setupInfluenceMap(v8, (int)centerPoint, 0, -1, centerPoint, &min, &max);
        bestPointValue = -1;
        clearDistance = TribeInformationAIModule::groupInfluenceDimension(num);
        v13 = min.x;
        for ( maximumDistanceVariationa = min.x; v13 <= max.x; maximumDistanceVariationa = v13 )
        {
            v14 = min.y;
            for ( numa = min.y; v14 <= max.y; numa = v14 )
            {
                if ( minExclude.x > v13 || v13 > maxExclude.x || minExclude.y > v14 || v14 > maxExclude.y )
                {
                    v15 = clearDistance / 2;
                    minClear.x = v13 - clearDistance / 2;
                    minClear.y = v14 - clearDistance / 2;
                    if ( TribeInformationAIModule::mapBound(v8, &minClear) != 1 )
                    {
                        maxClear.x = v13 + v15;
                        maxClear.y = v14 + v15;
                        if ( TribeInformationAIModule::mapBound(v8, &maxClear) != 1 )
                        {
                            v16 = 0;
                            v17 = minClear.x;
                            i = minClear.x;
                            if ( minClear.x < maxClear.x )
                            {
                                v18 = maxClear.y;
                                do
                                {
                                    if ( v16 )
                                        break;
                                    v19 = minClear.y;
                                    j = minClear.y;
                                    if ( minClear.y < v18 )
                                    {
                                        do
                                        {
                                            if ( v16 )
                                                break;
                                            v20 = (double)j;
                                            v21 = (double)i;
                                            if ( !((int (__stdcall *)(_DWORD, _DWORD, signed int))testUnit->vfptr->passableTile)(
                                                            LODWORD(v21),
                                                            LODWORD(v20),
                                                            1) )
                                                v16 = 1;
                                            v18 = maxClear.y;
                                            j = ++v19;
                                        }
                                        while ( v19 < maxClear.y );
                                    }
                                    i = ++v17;
                                }
                                while ( v17 < maxClear.x );
                            }
                            if ( v16 != 1 )
                            {
                                v22 = testUnit->vfptr;
                                cPosition.x = maximumDistanceVariationa;
                                v23 = 128;
                                cPosition.y = v14;
                                v24 = (double)desiredDistance;
                                if ( !((int (__stdcall *)(XYPoint *, XYPoint *, _DWORD, XYPoint *, signed int))v22->canLinePath)(
                                                &cPosition,
                                                centerPoint,
                                                LODWORD(v24),
                                                &lineCollisionPoint,
                                                1) )
                                    v23 = 64;
                                v25 = minClear.x;
                                if ( minClear.x <= maxClear.x )
                                {
                                    v26 = maxClear.y;
                                    do
                                    {
                                        if ( v16 )
                                            break;
                                        v27 = minClear.y;
                                        if ( minClear.y <= v26 )
                                        {
                                            do
                                            {
                                                if ( v16 )
                                                    break;
                                                v28 = InfluenceMap::lookupValue(&iMap, v25, v27);
                                                if ( v28 == 255 )
                                                    v16 = 1;
                                                else
                                                    v23 += v28;
                                                v26 = maxClear.y;
                                                ++v27;
                                            }
                                            while ( v27 <= maxClear.y );
                                        }
                                        ++v25;
                                    }
                                    while ( v25 <= maxClear.x );
                                }
                                if ( v16 != 1 && (bestPointValue == -1 || bestPointValue < v23) )
                                {
                                    bestPointValue = v23;
                                    rPoint->x = maximumDistanceVariationa;
                                    rPoint->y = numa;
                                }
                                v14 = numa;
                            }
                            v13 = maximumDistanceVariationa;
                        }
                    }
                }
                v8 = v32;
                ++v14;
            }
            ++v13;
        }
        result = bestPointValue != -1;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (004DEE90) --------------------------------------------------------
void TribeInformationAIModule::setupInfluenceMap(TribeInformationAIModule *this@<ecx>, int a2@<ebx>, int placementType, int buildingType, XYPoint *centerPoint, XYPoint *minArea, XYPoint *maxArea)
{
    TribeInformationAIModule *v7; // esi@1
    int v8; // ebx@1
    int v9; // edx@1
    int v10; // eax@1
    signed int v11; // edi@1
    int v12; // ebp@4
    int v13; // edi@14
    int v14; // ebp@17
    int v15; // ebx@17
    int v16; // eax@20
    RGE_Static_Object *v17; // eax@21
    RGE_Static_Object *v18; // edi@21
    RGE_Master_Static_Object *v19; // eax@22
    int v20; // ST2C_4@22
    __int16 v21; // ax@27
    int v22; // ecx@45
    bool v23; // sf@45
    unsigned __int8 v24; // of@45
    int v25; // ebp@63
    int *v26; // edi@63
    int i; // eax@64
    RGE_Static_Object *v28; // eax@68
    RGE_Static_Object *v29; // edi@68
    int v30; // ecx@69
    RGE_Master_Static_Object *v31; // eax@69
    double v32; // st7@70
    int v33; // ebp@74
    int v34; // ebx@74
    signed __int64 v35; // rax@74
    signed __int64 v36; // rax@79
    signed __int64 v37; // rax@80
    signed __int64 v38; // rax@84
    double v39; // st7@94
    int v40; // edi@96
    signed int v41; // edi@98
    double v42; // st7@99
    int v43; // edi@104
    double v44; // st7@105
    int v45; // edi@109
    int v46; // ecx@115
    int v47; // ebx@118
    XYPoint *v48; // eax@118
    RGE_Map *v49; // ebp@118
    int v50; // edi@120
    int v51; // ebx@131
    int v52; // edi@132
    int v53; // eax@133
    int v54; // eax@135
    int v55; // eax@140
    int j; // edi@143
    int v57; // eax@144
    float bXRadius; // [sp+20h] [bp-70h]@19
    float bXRadiusa; // [sp+20h] [bp-70h]@69
    int buildingCode; // [sp+24h] [bp-6Ch]@69
    int a; // [sp+28h] [bp-68h]@18
    int aa; // [sp+28h] [bp-68h]@59
    int ab; // [sp+28h] [bp-68h]@119
    XYPoint v64; // [sp+2Ch] [bp-64h]@17
    float terrainType; // [sp+34h] [bp-5Ch]@17
    int bMin[4]; // [sp+38h] [bp-58h]@22
    int v67; // [sp+40h] [bp-50h]@22
    int v68; // [sp+44h] [bp-4Ch]@22
    XYPoint v69; // [sp+48h] [bp-48h]@98
    XYPoint bMaxLOS; // [sp+50h] [bp-40h]@109
    XYPoint bMinLOS; // [sp+58h] [bp-38h]@22
    XYPoint v72; // [sp+60h] [bp-30h]@96
    XYPoint p; // [sp+68h] [bp-28h]@96
    int aMin[4]; // [sp+70h] [bp-20h]@104
    int v75; // [sp+78h] [bp-18h]@104
    int v76; // [sp+7Ch] [bp-14h]@4
    XYPoint max; // [sp+80h] [bp-10h]@1
    XYPoint min; // [sp+88h] [bp-8h]@1

    v7 = this;
    InfluenceMap::initialize(&iMap, a2, 20);
    InfluenceMap::setUnchangeableLimit(&iMap, -1);
    v8 = 0;
    BuildAIModule::numberBuiltItemsOfType((BuildAIModule *)&v7->md->buildAI.vfptr, 68, 0);
    BuildAIModule::numberBuiltItemsOfType((BuildAIModule *)&v7->md->buildAI.vfptr, 103, 0);
    v9 = v7->mapXSizeValue;
    v10 = v7->mapYSizeValue;
    v11 = 0;
    min.x = 0;
    min.y = 0;
    max.x = v9;
    max.y = v10;
    if ( placementType == 3 || placementType == 4 || !placementType )
    {
        v12 = v9 - 5;
        v76 = v10 - 5;
        if ( v9 > 0 )
        {
            do
            {
                if ( v11 < v10 )
                {
                    do
                    {
                        if ( v8 < 5 || v8 > v12 || v11 < 5 || v11 > v76 )
                        {
                            InfluenceMap::decrementValue(&iMap, v8, v11, 10);
                            v10 = max.y;
                        }
                        ++v11;
                    }
                    while ( v11 < v10 );
                    v11 = min.y;
                    v9 = max.x;
                }
                ++v8;
            }
            while ( v8 < v9 );
        }
    }
    v13 = placementType;
    if ( placementType != 1 && placementType != 2 && placementType != 9 )
    {
        v15 = 0;
        goto LABEL_50;
    }
    terrainType = COERCE_FLOAT(TribeInformationAIModule::resourceTypeToPlaceDropsiteBy(v7, placementType));
    v14 = (int)v7->resources;
    v64.x = 4;
    v15 = 0;
    do
    {
        a = 0;
        if ( *(_DWORD *)(v14 + 16) <= 0 )
            goto LABEL_47;
        bXRadius = 0.0;
        do
        {
            v16 = *(_DWORD *)v14 + LODWORD(bXRadius);
            if ( *(_BYTE *)(v16 + 13) == 1 )
                goto LABEL_45;
            v17 = MainDecisionAIModule::object((MainDecisionAIModule *)&v7->md->vfptr, *(_DWORD *)v16);
            v18 = v17;
            if ( !v17 )
                goto LABEL_45;
            v19 = v17->master_obj;
            v20 = SLODWORD(v19->radius_y);
            v67 = (signed __int64)(v18->world_x - v19->radius_x - 1.0);
            v68 = (signed __int64)(v18->world_y - *(float *)&v20 - 1.0);
            TribeInformationAIModule::mapBound(v7, (XYPoint *)&v67);
            bMin[0] = (signed __int64)(*(float *)&v20 + v18->world_x - -1.0);
            bMin[1] = (signed __int64)(*(float *)&v20 + v18->world_y - -1.0);
            TribeInformationAIModule::mapBound(v7, (XYPoint *)bMin);
            bMinLOS.x = (signed __int64)v18->world_x;
            bMinLOS.y = (signed __int64)v18->world_y;
            TribeInformationAIModule::mapBound(v7, &bMinLOS);
            if ( placementType == 1 || placementType == 2 )
                InfluenceMap::setValue(&iMap, bMinLOS.x, bMinLOS.y, -1);
            else
                InfluenceMap::setValue(&iMap, v67, v68, bMin[0], bMin[1], -1);
            if ( placementType == 1 )
            {
                v21 = v18->master_obj->object_group;
                if ( v21 != 7 )
                {
                    if ( terrainType == -6.8056469e38/*NaN*/
                        || LODWORD(terrainType) == 3 && v21 == 32
                        || LODWORD(terrainType) == 2 && v21 == 8
                        || LODWORD(terrainType) == 1 && v21 == 15
                        || terrainType == 0.0 && v21 != 32 && v21 != 8 && v21 != 15 )
                    {
                        --v67;
                        --v68;
                        TribeInformationAIModule::mapBound(v7, (XYPoint *)&v67);
                        ++bMin[0];
                        ++bMin[1];
                        TribeInformationAIModule::mapBound(v7, (XYPoint *)bMin);
                        InfluenceMap::incrementValue(&iMap, v67, v68, bMin[0], bMin[1], 8);
                        v67 -= 3;
                        v68 -= 3;
                        TribeInformationAIModule::mapBound(v7, (XYPoint *)&v67);
                        bMin[0] += 3;
                        bMin[1] += 3;
                        TribeInformationAIModule::mapBound(v7, (XYPoint *)bMin);
                        InfluenceMap::incrementValue(&iMap, v67, v68, bMin[0], bMin[1], 4);
                        v67 -= 5;
                        v68 -= 5;
                        TribeInformationAIModule::mapBound(v7, (XYPoint *)&v67);
                        bMin[0] += 5;
                        bMin[1] += 5;
                        TribeInformationAIModule::mapBound(v7, (XYPoint *)bMin);
                        InfluenceMap::incrementValue(&iMap, v67, v68, bMin[0], bMin[1], 2);
                    }
                    goto LABEL_45;
                }
                if ( v18->master_obj->object_group == 7 )
                {
                    v67 -= 5;
                    v68 -= 5;
                    TribeInformationAIModule::mapBound(v7, (XYPoint *)&v67);
                    bMin[0] += 5;
                    bMin[1] += 5;
                    TribeInformationAIModule::mapBound(v7, (XYPoint *)bMin);
                    InfluenceMap::decrementValue(&iMap, v67, v68, bMin[0], bMin[1], -128);
                    goto LABEL_45;
                }
            }
            if ( placementType == 2 && v18->master_obj->object_group == 7 )
            {
                v67 -= 3;
                v68 -= 3;
                TribeInformationAIModule::mapBound(v7, (XYPoint *)&v67);
                bMin[0] += 3;
                bMin[1] += 3;
                TribeInformationAIModule::mapBound(v7, (XYPoint *)bMin);
                InfluenceMap::incrementValue(&iMap, v67, v68, bMin[0], bMin[1], -128);
            }
LABEL_45:
            v22 = *(_DWORD *)(v14 + 16);
            v24 = __OFSUB__(a + 1, v22);
            v23 = a++ + 1 - v22 < 0;
            LODWORD(bXRadius) += 20;
        }
        while ( v23 ^ v24 );
        v13 = placementType;
        v15 = 0;
LABEL_47:
        v14 += 4;
        --v64.x;
    }
    while ( v64.x );
LABEL_50:
    if ( v13 == 1 || v13 == 2 || v13 == 3 || v13 == 4 || !v13 || v13 == 5 || v13 == 6 )
    {
LABEL_59:
        aa = 0;
        if ( v7->playerBuildings.numberValue <= 0 )
            goto LABEL_115;
        while ( 1 )
        {
            if ( v15 > v7->playerBuildings.maximumSizeValue - 1 )
            {
                v25 = v15 + 1;
                v26 = (int *)operator new(4 * v15 + 4);
                if ( v26 )
                {
                    for ( i = 0; i < v7->playerBuildings.maximumSizeValue; v26[i - 1] = v7->playerBuildings.value[i - 1] )
                    {
                        if ( i >= v25 )
                            break;
                        ++i;
                    }
                    operator delete(v7->playerBuildings.value);
                    v7->playerBuildings.value = v26;
                    v7->playerBuildings.maximumSizeValue = v25;
                }
            }
            v28 = MainDecisionAIModule::object((MainDecisionAIModule *)&v7->md->vfptr, v7->playerBuildings.value[v15]);
            v29 = v28;
            if ( v28 )
                break;
LABEL_114:
            if ( ++aa >= v7->playerBuildings.numberValue )
                goto LABEL_115;
            v15 = aa;
        }
        v30 = TribeInformationAIModule::placementCode(v28->master_obj->id);
        v31 = v29->master_obj;
        buildingCode = v30;
        bXRadiusa = v31->radius_x;
        terrainType = v31->radius_y;
        if ( bXRadiusa == 2.5 )
        {
            v32 = v29->world_x;
            goto LABEL_74;
        }
        if ( bXRadiusa == 1.5 )
        {
            if ( v30 != 6 )
            {
                v32 = v29->world_x;
                if ( buildingType != 70 )
                {
                    v33 = (unsigned __int64)(signed __int64)v32 - 2;
                    bMin[0] = (unsigned __int64)(signed __int64)v32 - 2;
                    v35 = (signed __int64)v29->world_y;
                    v34 = v35 - 2;
                    bMin[1] = v35 - 2;
                    v67 = (unsigned __int64)(signed __int64)v29->world_x + 2;
                    LODWORD(v35) = (unsigned __int64)(signed __int64)v29->world_y + 2;
                    goto LABEL_87;
                }
LABEL_74:
                v33 = (unsigned __int64)(signed __int64)v32 - 3;
                bMin[0] = (unsigned __int64)(signed __int64)v32 - 3;
                v35 = (signed __int64)v29->world_y;
                v34 = v35 - 3;
                bMin[1] = v35 - 3;
                v67 = (unsigned __int64)(signed __int64)v29->world_x + 3;
                LODWORD(v35) = (unsigned __int64)(signed __int64)v29->world_y + 3;
LABEL_87:
                v68 = v35;
                if ( v30 == 109 )
                {
                    bMin[0] = v33 - 1;
                    bMin[1] = v34 - 1;
                    ++v67;
                    v68 = v35 + 1;
                }
                TribeInformationAIModule::mapBound(v7, (XYPoint *)bMin);
                TribeInformationAIModule::mapBound(v7, (XYPoint *)&v67);
                InfluenceMap::setValue(&iMap, bMin[0], bMin[1], v67, v68, -1);
                if ( placementType != 3 && placementType )
                {
                    switch ( placementType )
                    {
                        case 1:
                        case 2:
                            v42 = v29->master_obj->los;
                            if ( buildingCode == 109 )
                            {
                                v42 = v42 * 0.5;
                            }
                            else if ( buildingCode == 68 || buildingCode == 103 )
                            {
                                v42 = 5.0;
                            }
                            v43 = (signed __int64)v42;
                            v76 = bMin[1] - v43;
                            v75 = bMin[0] - v43;
                            TribeInformationAIModule::mapBound(v7, (XYPoint *)&v75);
                            aMin[1] = v43 + v68;
                            aMin[0] = v43 + v67;
                            TribeInformationAIModule::mapBound(v7, (XYPoint *)aMin);
                            InfluenceMap::decrementValue(&iMap, v75, v76, aMin[0], aMin[1], 10);
                            break;
                        case 5:
                            v39 = v29->master_obj->los;
                            if ( buildingCode == 109 )
                                v39 = v39 * 0.25;
                            v40 = 2 * (unsigned __int64)(signed __int64)v39;
                            p.x = bMin[0] - v40;
                            p.y = bMin[1] - v40;
                            TribeInformationAIModule::mapBound(v7, &p);
                            v72.x = v40 + v67;
                            v72.y = v40 + v68;
                            TribeInformationAIModule::mapBound(v7, &v72);
                            InfluenceMap::decrementValue(&iMap, p.x, p.y, v72.x, v72.y, 20);
                            break;
                        case 8:
                            v41 = (signed __int64)v29->master_obj->los;
                            v69.x = bMin[0] - v41;
                            v69.y = bMin[1] - v41;
                            TribeInformationAIModule::mapBound(v7, &v69);
                            v64.x = v41 + v67;
                            v64.y = v41 + v68;
                            TribeInformationAIModule::mapBound(v7, &v64);
                            InfluenceMap::incrementValue(&iMap, v69.x, v69.y, v64.x, v64.y, 20);
                            v69.x = bMin[0] - v41 / 2;
                            v69.y = bMin[1] - v41 / 2;
                            TribeInformationAIModule::mapBound(v7, &v69);
                            v64.x = v41 / 2 + v67;
                            v64.y = v41 / 2 + v68;
                            TribeInformationAIModule::mapBound(v7, &v64);
                            InfluenceMap::incrementValue(&iMap, v69.x, v69.y, v64.x, v64.y, 20);
                            v41 /= 3;
                            v69.x = bMin[0] - v41;
                            v69.y = bMin[1] - v41;
                            TribeInformationAIModule::mapBound(v7, &v69);
                            v64.x = v41 + v67;
                            v64.y = v41 + v68;
                            TribeInformationAIModule::mapBound(v7, &v64);
                            InfluenceMap::incrementValue(&iMap, v69.x, v69.y, v64.x, v64.y, 20);
                            break;
                    }
                }
                else
                {
                    v44 = v29->master_obj->los;
                    if ( placementType )
                        v44 = v44 * 0.5;
                    if ( buildingCode == 109 )
                        v44 = v44 * 0.5;
                    v45 = (signed __int64)v44;
                    bMinLOS.x = bMin[0] - v45;
                    bMinLOS.y = bMin[1] - v45;
                    TribeInformationAIModule::mapBound(v7, &bMinLOS);
                    bMaxLOS.x = v45 + v67;
                    bMaxLOS.y = v45 + v68;
                    TribeInformationAIModule::mapBound(v7, &bMaxLOS);
                    if ( placementType || buildingCode != 3 )
                        InfluenceMap::decrementValue(&iMap, bMinLOS.x, bMinLOS.y, bMaxLOS.x, bMaxLOS.y, 10);
                    else
                        InfluenceMap::incrementValue(&iMap, bMinLOS.x, bMinLOS.y, bMaxLOS.x, bMaxLOS.y, 10);
                }
                goto LABEL_114;
            }
LABEL_84:
            v38 = (signed __int64)v29->world_x;
            v33 = v38 - 1;
            bMin[0] = v38 - 1;
            v35 = (signed __int64)v29->world_y;
            v34 = v35 - 1;
            bMin[1] = v35 - 1;
            v67 = (unsigned __int64)(signed __int64)v29->world_x + 1;
            LODWORD(v35) = (unsigned __int64)(signed __int64)v29->world_y + 1;
            goto LABEL_87;
        }
        if ( bXRadiusa == 1.0 )
        {
            if ( v30 != 6 && v30 != 3 )
            {
                v36 = (signed __int64)v29->world_x;
                v33 = v36 - 2;
                bMin[0] = v36 - 2;
                v35 = (signed __int64)v29->world_y;
                v34 = v35 - 2;
                bMin[1] = v35 - 2;
                v67 = (unsigned __int64)(signed __int64)v29->world_x + 1;
                LODWORD(v35) = (unsigned __int64)(signed __int64)v29->world_y + 1;
                goto LABEL_87;
            }
            v37 = (signed __int64)v29->world_x;
            v33 = v37 - 1;
            bMin[0] = v37 - 1;
            v34 = (unsigned __int64)(signed __int64)v29->world_y - 1;
        }
        else
        {
            if ( bXRadiusa != 0.5 )
            {
                AIModule::logCommonHistory(
                    (AIModule *)&v7->vfptr,
                    aUnsupportedB_1,
                    bXRadiusa + bXRadiusa,
                    terrainType + terrainType);
                goto LABEL_114;
            }
            if ( v30 != 6 && v30 != 4 )
                goto LABEL_84;
            v33 = (signed __int64)v29->world_x;
            bMin[0] = (signed __int64)v29->world_x;
            v34 = (signed __int64)v29->world_y;
        }
        bMin[1] = v34;
        v67 = (signed __int64)v29->world_x;
        v35 = (signed __int64)v29->world_y;
        goto LABEL_87;
    }
    if ( v13 == 8 )
    {
        v15 = 0;
        goto LABEL_59;
    }
LABEL_115:
    v46 = placementType;
    if ( placementType == 3 || placementType == 4 || !placementType )
    {
        v47 = minArea->x;
        v48 = maxArea;
        v49 = v7->md->player->world->map;
        if ( minArea->x <= maxArea->x )
        {
            ab = v47;
            do
            {
                v50 = minArea->y;
                if ( v50 <= v48->y )
                {
                    do
                    {
                        LOBYTE(terrainType) = RGE_Map::get_terrain(v49, v47, v50);
                        if ( LOBYTE(terrainType) == 1 )
                        {
                            aMin[1] = v50 - 2;
                            v76 = v50 - 2;
                            aMin[0] = v47 - 2;
                            v75 = v47 - 2;
                            TribeInformationAIModule::mapBound(v7, (XYPoint *)aMin);
                            TribeInformationAIModule::mapBound(v7, (XYPoint *)&v75);
                            InfluenceMap::setValue(&iMap, v47, v50, -1);
                            InfluenceMap::decrementValue(&iMap, aMin[0], aMin[1], v75, v76, 10);
                        }
                        InfluenceMap::incrementValue(&iMap, v47, v50, 5 * (*((_BYTE *)&v49->map_row_offset[v50][ab] + 5) >> 5));
                        v48 = maxArea;
                        ++v50;
                    }
                    while ( v50 <= maxArea->y );
                }
                ++v47;
                ++ab;
            }
            while ( v47 <= v48->x );
            v46 = placementType;
        }
    }
    if ( v46 == 3 || v46 == 4 || !v46 || v46 == 6 || v46 == 5 )
    {
        v51 = 0;
        if ( v7->maxAttackMemories > 0 )
        {
            v52 = 0;
            do
            {
                v53 = (int)&v7->attackMemories[v52].id;
                if ( *(_DWORD *)v53 != -1 && *(_BYTE *)(v53 + 10) == v7->md->player->id )
                {
                    aMin[0] = *(_BYTE *)(v53 + 5) - 4;
                    aMin[1] = *(_BYTE *)(v53 + 6) - 4;
                    TribeInformationAIModule::mapBound(v7, (XYPoint *)aMin);
                    v54 = (int)&v7->attackMemories[v52].id;
                    v75 = *(_BYTE *)(v54 + 7) + 4;
                    v76 = *(_BYTE *)(v54 + 8) + 4;
                    TribeInformationAIModule::mapBound(v7, (XYPoint *)&v75);
                    InfluenceMap::incrementValue(&iMap, aMin[0], aMin[1], v75, v76, 16);
                }
                ++v51;
                ++v52;
            }
            while ( v51 < v7->maxAttackMemories );
            v46 = placementType;
        }
    }
    if ( !v46 )
        TribeTacticalAIModule::setGroupInfluences(&v7->md->tacticalAI, &iMap);
    v55 = 1;
    if ( placementType == 4 )
        v55 = 0;
    InfluenceMap::setConnectionCount(&iMap, &min, &max, 255, 1, v55, 1);
    if ( placementType )
    {
        for ( j = 0; j < v7->maxBuildingLots; ++j )
        {
            v57 = (int)&v7->buildingLots[j].typeID;
            if ( *(_DWORD *)v57 == buildingType && *(_BYTE *)(v57 + 4) == 2 )
                InfluenceMap::setValue(&iMap, *(_BYTE *)(v57 + 5), *(_BYTE *)(v57 + 6), -1);
        }
    }
}

//----- (004DFCE0) --------------------------------------------------------
int TribeInformationAIModule::mapBound(XYPoint *p)
{
    int result; // eax@1
    int v3; // edi@3
    int v4; // esi@6
    int v5; // ecx@8

    result = 0;
    if ( p->x >= 0 )
    {
        v3 = this->mapXSizeValue;
        if ( p->x < v3 )
            goto LABEL_6;
        p->x = v3 - 1;
    }
    else
    {
        p->x = 0;
    }
    result = 1;
LABEL_6:
    v4 = p->y;
    if ( v4 >= 0 )
    {
        v5 = this->mapYSizeValue;
        if ( v4 >= v5 )
        {
            result = 1;
            p->y = v5 - 1;
        }
    }
    else
    {
        p->y = 0;
        result = 1;
    }
    return result;
}

//----- (004DFD40) --------------------------------------------------------
int __stdcall TribeInformationAIModule::groupInfluenceDimension(int num)
{
    int result; // eax@2

    if ( num > 1 )
        result = num * num;
    else
        result = 2;
    return result;
}

//----- (004DFD60) --------------------------------------------------------
ObjectMemory *TribeInformationAIModule::findObjectMemoryLimits(ObjectMemory *result, int __$ReturnUdt, int ownerID, int *unitID, int *numberNonSiegeTargets)
{
    TribeInformationAIModule *v6; // esi@1
    int v7; // ebx@1
    TribeMainDecisionAIModule *v8; // ecx@1
    RGE_Static_Object *v9; // eax@1
    RGE_Static_Object *v10; // ebp@1
    int v11; // eax@4
    RGE_Static_Object *v12; // eax@5
    RGE_Static_Object *v13; // edi@5
    double v14; // st7@7
    RGE_Static_ObjectVtbl *v15; // edx@7
    float range; // ST04_4@7
    RGE_Static_Object *v17; // ebp@8
    int v18; // ebx@9
    int v19; // edi@9
    signed __int64 v20; // rax@11
    int v21; // ecx@11
    int v22; // eax@16
    ObjectMemory *v23; // eax@19
    int v24; // ecx@19
    int v25; // eax@19
    ObjectMemory *v26; // ecx@25
    float z; // ST08_4@25
    float v28; // ST04_4@25
    float x; // ST00_4@25
    long double v30; // st7@25
    ObjectMemory *v31; // eax@27
    int v32; // ecx@27
    __int16 v33; // ax@27
    unsigned __int8 v34; // al@31
    int v35; // ecx@41
    bool v36; // sf@41
    unsigned __int8 v37; // of@41
    ObjectMemory *v38; // eax@42
    int v39; // [sp+1Ch] [bp-3Ch]@3
    char currentZone; // [sp+20h] [bp-38h]@2
    int i; // [sp+24h] [bp-34h]@2
    int map_col; // [sp+28h] [bp-30h]@9
    XYPoint point; // [sp+2Ch] [bp-2Ch]@7
    ObjectMemory rVal; // [sp+34h] [bp-24h]@1
    RGE_Static_Object *unitIDa; // [sp+64h] [bp+Ch]@1

    v6 = this;
    v7 = 0;
    *unitID = 0;
    *numberNonSiegeTargets = 0;
    v8 = this->md;
    rVal.id = 0;
    rVal.hitPoints = 0;
    rVal.attackAttempts = 0;
    rVal.kills = 0;
    LODWORD(rVal.damageCapability) = 0;
    LODWORD(rVal.rateOfFire) = 0;
    LODWORD(rVal.range) = 0;
    v9 = MainDecisionAIModule::object((MainDecisionAIModule *)&v8->vfptr, ownerID);
    v10 = v9;
    unitIDa = v9;
    if ( v9 )
    {
        currentZone = RGE_Static_Object::currentZone(v9);
        i = 0;
        if ( v6->maxImportantObjectMemory > 0 )
        {
            v39 = 0;
            do
            {
                v11 = (int)&v6->importantObjectMemory->id + v7;
                if ( *(_BYTE *)(v11 + 11) == __$ReturnUdt )
                {
                    v12 = MainDecisionAIModule::object((MainDecisionAIModule *)&v6->md->vfptr, *(_DWORD *)v11);
                    v13 = v12;
                    if ( v12 )
                    {
                        if ( currentZone == RGE_Static_Object::currentZone(v12)
                            || (point.x = (signed __int64)v13->world_x,
                                    v14 = v13->world_y,
                                    v15 = v10->vfptr,
                                    point.y = (signed __int64)v14,
                                    v15->weaponRange(v10),
                                    range = v14,
                                    RGE_Static_Object::withinRangeOfZoneAtPoint(v10, currentZone, range, &point) == 1) )
                        {
                            v17 = MainDecisionAIModule::object(
                                            (MainDecisionAIModule *)&v6->md->vfptr,
                                            *(int *)((char *)&v6->importantObjectMemory->id + v7));
                            if ( v17 )
                            {
                                v18 = (int)&v6->importantObjectMemory->id + v7;
                                map_col = (signed __int64)v17->world_x;
                                v19 = *(_BYTE *)(v18 + 8) - map_col;
                                if ( v19 < 0 )
                                    v19 = -v19;
                                v20 = (signed __int64)v17->world_y;
                                v21 = *(_BYTE *)(v18 + 9) - (_DWORD)v20;
                                if ( v21 < 0 )
                                    v21 = -v21;
                                if ( v19 <= 5 && v21 <= 5 || RGE_Visible_Map::get_visible(v6->md->player->visible, map_col, v20) == 15 )
                                {
                                    v22 = *(__int16 *)((char *)&v6->importantObjectMemory->group + v39);
                                    if ( v22 != 3 && v22 != 27 )
                                        ++*unitID;
                                    v23 = v6->importantObjectMemory;
                                    v24 = (int)&v23->id + v39;
                                    v25 = *(__int16 *)((char *)&v23->group + v39);
                                    if ( v25 != 2 && v25 != 21 && v25 != 22 && v25 != 20 && *(_WORD *)(v24 + 4) != 45 )
                                        ++*numberNonSiegeTargets;
                                    v26 = v6->importantObjectMemory;
                                    z = (double)*(&v26->z + v39);
                                    v28 = (double)*(&v26->y + v39);
                                    x = (double)*(&v26->x + v39);
                                    v30 = RGE_Static_Object::distance_to_position(unitIDa, x, v28, z);
                                    if ( v30 > (double)rVal.id )
                                        rVal.id = (signed __int64)v30;
                                    v31 = v6->importantObjectMemory;
                                    v32 = (int)&v31->id + v39;
                                    v33 = *(__int16 *)((char *)&v31->hitPoints + v39);
                                    if ( v33 > rVal.hitPoints )
                                        rVal.hitPoints = v33;
                                    if ( *(_DWORD *)(v32 + 16) > 0 )
                                        rVal.hitPoints = *(_WORD *)(v32 + 16);
                                    v34 = *(_BYTE *)(v32 + 20);
                                    if ( v34 )
                                        rVal.hitPoints = v34;
                                    if ( *(float *)(v32 + 24) > (double)rVal.damageCapability )
                                        rVal.damageCapability = *(float *)(v32 + 24);
                                    if ( *(float *)(v32 + 28) > (double)rVal.rateOfFire )
                                        rVal.rateOfFire = *(float *)(v32 + 28);
                                    if ( *(float *)(v32 + 32) > (double)rVal.range )
                                        rVal.range = *(float *)(v32 + 32);
                                }
                                v7 = v39;
                            }
                            v10 = unitIDa;
                        }
                    }
                }
                v35 = v6->maxImportantObjectMemory;
                v7 += 36;
                v37 = __OFSUB__(i + 1, v35);
                v36 = i++ + 1 - v35 < 0;
                v39 = v7;
            }
            while ( v36 ^ v37 );
        }
    }
    v38 = result;
    qmemcpy(result, &rVal, sizeof(ObjectMemory));
    return v38;
}

//----- (004E0040) --------------------------------------------------------
int __stdcall TribeInformationAIModule::isNextTo(XYPoint *one, XYPoint *two, int countDiagonal)
{
    int v4; // eax@1
    int result; // eax@3

    v4 = (two->y - one->y) * (two->y - one->y) + (two->x - one->x) * (two->x - one->x);
    if ( countDiagonal || v4 <= 1 )
        result = countDiagonal != 1 || v4 <= 2;
    else
        result = 0;
    return result;
}

//----- (004E0090) --------------------------------------------------------
int __stdcall TribeInformationAIModule::facetTo(XYPoint *one, XYPoint *two)
{
    int v3; // eax@1
    int v4; // ecx@1
    int v5; // eax@2
    int result; // eax@2
    int v7; // eax@6
    int v8; // eax@7

    v3 = two->x - one->x;
    v4 = two->y - one->y;
    if ( two->x == one->x )
    {
        LOBYTE(v3) = v4 >= 0;
        v5 = v3 - 1;
        LOBYTE(v5) = v5 & 0xFC;
        result = v5 + 5;
    }
    else if ( two->y == one->y )
    {
        result = v3 >= 0 ? 3 : 7;
    }
    else if ( v3 >= 0 )
    {
        v8 = v4 < 0;
        LOBYTE(v8) = v4 >= 0;
        --v8;
        LOBYTE(v8) = v8 & 0xFE;
        result = v8 + 4;
    }
    else
    {
        v7 = v4 < 0;
        LOBYTE(v7) = v4 >= 0;
        --v7;
        LOBYTE(v7) = v7 & 0xFA;
        result = v7 + 6;
    }
    return result;
}

//----- (004E0100) --------------------------------------------------------
int __stdcall TribeInformationAIModule::placementCode(int typeID)
{
    int result; // eax@2

    switch ( typeID )
    {
        case 69:
        case 79:
        case 199:
            result = 3;
            break;
        case 72:
        case 117:
        case 155:
            result = 4;
            break;
        case 68:
            result = 2;
            break;
        case 103:
            result = 1;
            break;
        case 70:
        case 82:
        case 84:
        case 110:
        case 276:
            result = 6;
            break;
        case 45:
            result = 7;
            break;
        case 50:
            result = 8;
            break;
        case 109:
            result = 9;
            break;
        default:
            result = 5;
            break;
    }
    return result;
}

//----- (004E02A0) --------------------------------------------------------
void TribeInformationAIModule::storeLot(int typeID, char x, char y, char status)
{
    TribeInformationAIModule *v5; // esi@1
    signed int v6; // edx@1
    signed int v7; // ecx@1
    int v8; // ebp@1
    BuildingLot *v9; // eax@2
    char *v10; // edi@11
    int v11; // ecx@12
    int v12; // eax@13
    char *v13; // eax@16
    int v14; // ecx@18
    int v15; // eax@19

    v5 = this;
    v6 = -1;
    v7 = 0;
    v8 = v5->maxBuildingLots;
    if ( v8 <= 0 )
    {
LABEL_10:
        if ( v6 == -1 )
        {
            v10 = (char *)operator new(16 * v8);
            if ( v10 )
            {
                v11 = 0;
                if ( v5->maxBuildingLots > 0 )
                {
                    v12 = (int)(v10 + 6);
                    do
                    {
                        ++v11;
                        v12 += 8;
                        *(_DWORD *)(v12 - 14) = v5->buildingLots[v11 - 1].typeID;
                        *(_BYTE *)(v12 - 9) = *((_BYTE *)&v5->buildingLots[v11] - 3);
                        *(_BYTE *)(v12 - 8) = *((_BYTE *)&v5->buildingLots[v11] - 2);
                        *(_BYTE *)(v12 - 10) = *((_BYTE *)&v5->buildingLots[v11] - 4);
                    }
                    while ( v11 < v5->maxBuildingLots );
                }
                if ( v11 < 2 * v5->maxBuildingLots )
                {
                    v13 = &v10[8 * v11 + 6];
                    do
                    {
                        *(_DWORD *)(v13 - 6) = -1;
                        *(v13 - 1) = 0;
                        *v13 = 0;
                        *(v13 - 2) = status;
                        ++v11;
                        v13 += 8;
                    }
                    while ( v11 < 2 * v5->maxBuildingLots );
                }
                operator delete(v5->buildingLots);
                v14 = v5->maxBuildingLots;
                v5->buildingLots = (BuildingLot *)v10;
                *(_DWORD *)&v10[8 * v14] = typeID;
                v5->buildingLots[v5->maxBuildingLots].x = x;
                v5->buildingLots[v5->maxBuildingLots].y = y;
                v5->buildingLots[v5->maxBuildingLots].status = status;
                v5->maxBuildingLots *= 2;
            }
        }
        else
        {
            v15 = v6;
            v5->buildingLots[v15].typeID = typeID;
            v5->buildingLots[v15].x = x;
            v5->buildingLots[v15].y = y;
            v5->buildingLots[v15].status = status;
        }
    }
    else
    {
        v9 = v5->buildingLots;
        while ( v9->typeID != typeID || v9->x != x || v9->y != y )
        {
            if ( v6 == -1 && v9->typeID == -1 )
                v6 = v7;
            ++v7;
            ++v9;
            if ( v7 >= v8 )
                goto LABEL_10;
        }
        v5->buildingLots[v7].status = status;
    }
}

//----- (004E0470) --------------------------------------------------------
void TribeInformationAIModule::removeLot(int typeID, char x, char y, char newStatus)
{
    int v5; // edx@1
    int v6; // esi@1
    BuildingLot *v7; // eax@2
    int v8; // eax@10
    BuildingLot *v9; // [sp+10h] [bp-4h]@2

    v5 = 0;
    v6 = this->maxBuildingLots;
    if ( v6 > 0 )
    {
        v7 = this->buildingLots;
        v9 = this->buildingLots;
        while ( v7->typeID != typeID || v7->x != x || v7->y != y )
        {
            ++v5;
            ++v7;
            if ( v5 >= v6 )
                return;
        }
        if ( newStatus == 3 )
        {
            v8 = v5;
            v9[v8].typeID = -1;
            this->buildingLots[v8].x = 0;
            this->buildingLots[v8].y = 0;
            this->buildingLots[v8].status = 3;
        }
        else
        {
            v9[v5].status = newStatus;
        }
    }
}

//----- (004E0510) --------------------------------------------------------
BuildingLot *TribeInformationAIModule::availableLot(int typeID)
{
    int v2; // esi@1
    int v3; // edx@1
    BuildingLot *v4; // ecx@2
    BuildingLot *v5; // eax@2
    BuildingLot *result; // eax@6

    v2 = this->maxBuildingLots;
    v3 = 0;
    if ( v2 <= 0 )
    {
        result = 0;
    }
    else
    {
        v4 = this->buildingLots;
        v5 = v4;
        while ( v5->typeID != typeID || v5->status )
        {
            ++v3;
            ++v5;
            if ( v3 >= v2 )
                return 0;
        }
        result = &v4[v3];
    }
    return result;
}

//----- (004E0560) --------------------------------------------------------
int TribeInformationAIModule::invalidLot(int typeID, char x, char y)
{
    int v4; // esi@1
    int v5; // edx@1
    BuildingLot *v6; // eax@2
    int result; // eax@8

    v4 = this->maxBuildingLots;
    v5 = 0;
    if ( v4 <= 0 )
    {
        result = 0;
    }
    else
    {
        v6 = this->buildingLots;
        while ( v6->typeID != typeID || v6->status != 2 || v6->x != x || v6->y != y )
        {
            ++v5;
            ++v6;
            if ( v5 >= v4 )
                return 0;
        }
        result = 1;
    }
    return result;
}

//----- (004E05C0) --------------------------------------------------------
int TribeInformationAIModule::undesirableLot(int typeID, char x, char y, int overlapSize)
{
    int v5; // eax@1
    BuildingLot *v6; // ebx@2
    int v7; // ecx@5
    int v8; // esi@5
    int i; // [sp+10h] [bp-8h]@1
    int v11; // [sp+14h] [bp-4h]@1

    v5 = this->maxBuildingLots;
    i = 0;
    v11 = this->maxBuildingLots;
    if ( v5 > 0 )
    {
        v6 = this->buildingLots;
        while ( 1 )
        {
            if ( v6->typeID == typeID && v6->status == 1 )
            {
                v7 = v6->x;
                v8 = v6->y;
                if ( v7 - overlapSize <= (unsigned __int8)x
                    && overlapSize + v7 >= (unsigned __int8)x
                    && v8 - overlapSize <= (unsigned __int8)y
                    && overlapSize + v8 >= (unsigned __int8)y )
                {
                    return 1;
                }
                v5 = v11;
            }
            ++v6;
            if ( ++i >= v5 )
                return 0;
        }
    }
    return 0;
}

//----- (004E0670) --------------------------------------------------------
void TribeInformationAIModule::setupWalls(int x, int y, int minDistance, int maxDistance, int pattern, int numberGates, int gateSize, int townWalls)
{
    int v9; // ebx@1
    int v10; // edi@1
    TribeInformationAIModule *v11; // esi@1
    int v12; // eax@3
    int v13; // ecx@3
    int v14; // eax@3
    int v15; // ecx@3
    int v16; // eax@3
    int v17; // eax@3
    XYPoint *v18; // ebp@4
    int v19; // edx@6
    int v20; // eax@9
    unsigned int v21; // edi@10
    int v22; // ebx@10
    int v23; // ebx@11
    int i; // edi@11
    bool v25; // zf@27
    int v26; // eax@30
    int v27; // ebx@31
    int v28; // ecx@31
    int v29; // ebp@31
    int v30; // edi@33
    int v31; // ebx@33
    int v32; // ebp@34
    int v33; // eax@38
    int v34; // ebp@39
    int v35; // ebp@60
    int v36; // ebp@65
    bool v37; // sf@69
    int v38; // ebp@70
    int v39; // ebp@76
    int v40; // ebp@81
    int v41; // ebp@86
    int v42; // ebp@91
    int v43; // eax@98
    int v44; // ecx@99
    int v45; // ebx@100
    int j; // edi@100
    int v47; // [sp+10h] [bp-34h]@39
    int v48; // [sp+10h] [bp-34h]@45
    int v49; // [sp+10h] [bp-34h]@50
    int v50; // [sp+10h] [bp-34h]@55
    XYPoint max; // [sp+14h] [bp-30h]@11
    XYPoint min; // [sp+1Ch] [bp-28h]@11
    XYPoint p; // [sp+24h] [bp-20h]@33
    XYPoint realMin; // [sp+2Ch] [bp-18h]@33
    XYPoint realMax; // [sp+34h] [bp-10h]@33
    XYPoint v56; // [sp+3Ch] [bp-8h]@33
    int xa; // [sp+48h] [bp+4h]@31
    int xb; // [sp+48h] [bp+4h]@99
    int ya; // [sp+4Ch] [bp+8h]@10
    int yb; // [sp+4Ch] [bp+8h]@99
    int minDistancea; // [sp+50h] [bp+Ch]@10
    int minDistanceb; // [sp+50h] [bp+Ch]@31
    int minDistancec; // [sp+50h] [bp+Ch]@99
    int maxDistancea; // [sp+54h] [bp+10h]@10
    int maxDistanceb; // [sp+54h] [bp+10h]@31
    int maxDistancec; // [sp+54h] [bp+10h]@99
    int patterna; // [sp+58h] [bp+14h]@31
    int gateSizea; // [sp+60h] [bp+1Ch]@31
    int gateSizeb; // [sp+60h] [bp+1Ch]@99
    int townWallsa; // [sp+64h] [bp+20h]@4
    int townWallsb; // [sp+64h] [bp+20h]@10
    int townWallsc; // [sp+64h] [bp+20h]@30
    int townWallsd; // [sp+64h] [bp+20h]@99

    v9 = x;
    v10 = maxDistance;
    v11 = this;
    if ( townWalls == 1 && numberGates > 0 )
    {
        this->numberGatesValue = numberGates;
        v12 = debug_rand(aCMsdevWorkA_52, 5937);
        v13 = (((unsigned __int64)v12 >> 32) ^ abs(v12) & 3) - ((unsigned __int64)v12 >> 32);
        v11->minGatePosition[v13].x = x - gateSize / 2;
        v11->minGatePosition[v13].y = y - 2 * maxDistance;
        v11->maxGatePosition[v13].x = x + gateSize / 2;
        v11->maxGatePosition[v13].y = y;
        v14 = (((unsigned __int64)(v13 + 1) >> 32) ^ abs(v13 + 1) & 3) - ((unsigned __int64)(v13 + 1) >> 32);
        v11->minGatePosition[v14].x = x - gateSize / 2;
        v11->minGatePosition[v14].y = y;
        v11->maxGatePosition[v14].x = x + gateSize / 2;
        v11->maxGatePosition[v14].y = y + 2 * maxDistance;
        v15 = y - gateSize / 2;
        v16 = (((unsigned __int64)(v14 + 1) >> 32) ^ abs(v14 + 1) & 3) - ((unsigned __int64)(v14 + 1) >> 32);
        v11->minGatePosition[v16].x = x;
        v11->minGatePosition[v16].y = v15;
        v11->maxGatePosition[v16].x = x + 2 * maxDistance;
        v11->maxGatePosition[v16].y = y + gateSize / 2;
        v17 = (((unsigned __int64)(v16 + 1) >> 32) ^ abs(v16 + 1) & 3) - ((unsigned __int64)(v16 + 1) >> 32);
        v11->minGatePosition[v17].x = x - 2 * maxDistance;
        v11->minGatePosition[v17].y = v15;
        v11->maxGatePosition[v17].x = x;
        v11->maxGatePosition[v17].y = y + gateSize / 2;
        if ( numberGates > 0 )
        {
            v18 = v11->maxGatePosition;
            townWallsa = numberGates;
            do
            {
                TribeInformationAIModule::mapBound(v11, v18 - 4);
                TribeInformationAIModule::mapBound(v11, v18);
                ++v18;
                --townWallsa;
            }
            while ( townWallsa );
        }
    }
    v19 = pattern;
    if ( !pattern )
        v19 = debug_rand(aCMsdevWorkA_52, 5994) % 3;
    switch ( v19 )
    {
        case 1:
            v20 = minDistance;
            if ( minDistance <= maxDistance )
            {
                v21 = maxDistance - minDistance + 3;
                v22 = x - y;
                minDistancea = minDistance + y;
                ya = y - v20;
                maxDistancea = v22;
                townWallsb = v21 / 3;
                do
                {
                    min.y = ya;
                    min.x = maxDistancea + ya;
                    TribeInformationAIModule::mapBound(v11, &min);
                    max.y = minDistancea;
                    max.x = minDistancea + maxDistancea;
                    TribeInformationAIModule::mapBound(v11, &max);
                    v23 = min.x;
                    for ( i = min.y; v23 < max.x; ++v23 )
                    {
                        if ( !TribeInformationAIModule::insideGate(v11, numberGates, v23, i) )
                            TribeInformationAIModule::storeLot(v11, 72, v23, i, 0);
                    }
                    for ( ; i < max.y; ++i )
                    {
                        if ( !TribeInformationAIModule::insideGate(v11, numberGates, v23, i) )
                            TribeInformationAIModule::storeLot(v11, 72, v23, i, 0);
                    }
                    for ( ; v23 > min.x; --v23 )
                    {
                        if ( !TribeInformationAIModule::insideGate(v11, numberGates, v23, i) )
                            TribeInformationAIModule::storeLot(v11, 72, v23, i, 0);
                    }
                    for ( ; i > min.y; --i )
                    {
                        if ( !TribeInformationAIModule::insideGate(v11, numberGates, v23, i) )
                            TribeInformationAIModule::storeLot(v11, 72, v23, i, 0);
                    }
                    ya -= 3;
                    v25 = townWallsb == 1;
                    minDistancea += 3;
                    --townWallsb;
                }
                while ( !v25 );
            }
            break;
        case 2:
            v26 = minDistance;
            townWallsc = minDistance;
            if ( minDistance <= maxDistance )
            {
                minDistanceb = 2 * minDistance;
                v27 = x - y;
                gateSizea = v26 + y;
                v28 = y - v26;
                v29 = y - v26;
                patterna = y - v26;
                xa = y - v26;
                maxDistanceb = v27;
                min.x = v10 - v26 + 1;
                while ( 1 )
                {
                    realMin.y = v28;
                    realMin.x = v28 + v27;
                    TribeInformationAIModule::mapBound(v11, &realMin);
                    max.x = townWallsc + 1;
                    realMax.y = y + townWallsc + 1 - 1;
                    realMax.x = realMax.y + v27;
                    TribeInformationAIModule::mapBound(v11, &realMax);
                    p.x = v29 + v27;
                    p.y = v29;
                    TribeInformationAIModule::mapBound(v11, &p);
                    v56.y = gateSizea;
                    v56.x = gateSizea + v27;
                    TribeInformationAIModule::mapBound(v11, &v56);
                    v30 = p.x;
                    v31 = p.y;
                    if ( minDistanceb > 0 )
                    {
                        v32 = townWallsc;
                        do
                        {
                            if ( !TribeInformationAIModule::insideGate(v11, numberGates, v30, v31) )
                                TribeInformationAIModule::storeLot(v11, 72, v30, v31, 0);
                            --v31;
                            --v32;
                        }
                        while ( v32 );
                    }
                    v33 = minDistanceb;
                    if ( minDistanceb <= 0 )
                    {
                        v34 = numberGates;
                    }
                    else
                    {
                        v34 = numberGates;
                        v47 = minDistanceb;
                        do
                        {
                            if ( !TribeInformationAIModule::insideGate(v11, numberGates, v30, v31) )
                                TribeInformationAIModule::storeLot(v11, 72, v30, v31, 0);
                            ++v30;
                            --v47;
                        }
                        while ( v47 );
                        v33 = minDistanceb;
                    }
                    if ( v33 > 0 )
                    {
                        v48 = townWallsc;
                        do
                        {
                            if ( !TribeInformationAIModule::insideGate(v11, v34, v30, v31) )
                                TribeInformationAIModule::storeLot(v11, 72, v30, v31, 0);
                            ++v31;
                            --v48;
                        }
                        while ( v48 );
                        if ( minDistanceb > 0 )
                        {
                            v49 = townWallsc;
                            do
                            {
                                if ( !TribeInformationAIModule::insideGate(v11, v34, v30, v31) )
                                    TribeInformationAIModule::storeLot(v11, 72, v30, v31, 0);
                                ++v30;
                                --v49;
                            }
                            while ( v49 );
                            if ( minDistanceb > 0 )
                            {
                                v50 = minDistanceb;
                                do
                                {
                                    if ( !TribeInformationAIModule::insideGate(v11, v34, v30, v31) )
                                        TribeInformationAIModule::storeLot(v11, 72, v30, v31, 0);
                                    ++v31;
                                    --v50;
                                }
                                while ( v50 );
                                if ( minDistanceb > 0 )
                                {
                                    v35 = townWallsc;
                                    do
                                    {
                                        if ( !TribeInformationAIModule::insideGate(v11, numberGates, v30, v31) )
                                            TribeInformationAIModule::storeLot(v11, 72, v30, v31, 0);
                                        --v30;
                                        --v35;
                                    }
                                    while ( v35 );
                                }
                            }
                        }
                    }
                    if ( minDistanceb >= 0 )
                    {
                        v36 = max.x;
                        do
                        {
                            if ( !TribeInformationAIModule::insideGate(v11, numberGates, v30, v31) )
                                TribeInformationAIModule::storeLot(v11, 72, v30, v31, 0);
                            ++v31;
                            --v36;
                        }
                        while ( v36 );
                        v37 = minDistanceb < 0;
                        if ( minDistanceb > 0 )
                        {
                            v38 = minDistanceb;
                            do
                            {
                                if ( !TribeInformationAIModule::insideGate(v11, numberGates, v30, v31) )
                                    TribeInformationAIModule::storeLot(v11, 72, v30, v31, 0);
                                --v30;
                                --v38;
                            }
                            while ( v38 );
                            v37 = minDistanceb < 0;
                        }
                        if ( !v37 )
                        {
                            v39 = max.x;
                            do
                            {
                                if ( !TribeInformationAIModule::insideGate(v11, numberGates, v30, v31) )
                                    TribeInformationAIModule::storeLot(v11, 72, v30, v31, 0);
                                --v31;
                                --v39;
                            }
                            while ( v39 );
                            if ( minDistanceb > 0 )
                            {
                                v40 = townWallsc;
                                do
                                {
                                    if ( !TribeInformationAIModule::insideGate(v11, numberGates, v30, v31) )
                                        TribeInformationAIModule::storeLot(v11, 72, v30, v31, 0);
                                    --v30;
                                    --v40;
                                }
                                while ( v40 );
                                if ( minDistanceb > 0 )
                                {
                                    v41 = minDistanceb;
                                    do
                                    {
                                        if ( !TribeInformationAIModule::insideGate(v11, numberGates, v30, v31) )
                                            TribeInformationAIModule::storeLot(v11, 72, v30, v31, 0);
                                        --v31;
                                        --v41;
                                    }
                                    while ( v41 );
                                    if ( minDistanceb > 0 )
                                    {
                                        v42 = townWallsc;
                                        do
                                        {
                                            if ( !TribeInformationAIModule::insideGate(v11, numberGates, v30, v31) )
                                                TribeInformationAIModule::storeLot(v11, 72, v30, v31, 0);
                                            ++v30;
                                            --v42;
                                        }
                                        while ( v42 );
                                    }
                                }
                            }
                        }
                    }
                    v25 = min.x == 1;
                    --xa;
                    ++gateSizea;
                    townWallsc += 2;
                    patterna -= 2;
                    minDistanceb += 4;
                    --min.x;
                    if ( v25 )
                        break;
                    v29 = xa;
                    v28 = patterna;
                    v27 = maxDistanceb;
                }
            }
            break;
        case 3:
            v43 = minDistance / 2;
            if ( minDistance / 2 <= maxDistance )
            {
                v44 = y;
                xb = y + minDistance;
                townWallsd = v43 + y;
                maxDistancec = v9 - y;
                yb = y - v43;
                minDistancec = v44 - minDistance;
                gateSizeb = v10 - v43 + 1;
                do
                {
                    p.y = minDistancec;
                    p.x = minDistancec + maxDistancec;
                    TribeInformationAIModule::mapBound(v11, &p);
                    v56.y = xb;
                    v56.x = xb + maxDistancec;
                    TribeInformationAIModule::mapBound(v11, &v56);
                    min.y = yb;
                    min.x = yb + maxDistancec;
                    TribeInformationAIModule::mapBound(v11, &min);
                    max.y = townWallsd;
                    max.x = townWallsd + maxDistancec;
                    TribeInformationAIModule::mapBound(v11, &max);
                    v45 = p.x;
                    for ( j = min.y; v45 < min.x; --j )
                    {
                        if ( !TribeInformationAIModule::insideGate(v11, numberGates, v45, j) )
                            TribeInformationAIModule::storeLot(v11, 72, v45, j, 0);
                        ++v45;
                    }
                    for ( ; v45 < max.x; ++v45 )
                    {
                        if ( !TribeInformationAIModule::insideGate(v11, numberGates, v45, j) )
                            TribeInformationAIModule::storeLot(v11, 72, v45, j, 0);
                    }
                    for ( ; j < min.y; ++j )
                    {
                        if ( !TribeInformationAIModule::insideGate(v11, numberGates, v45, j) )
                            TribeInformationAIModule::storeLot(v11, 72, v45, j, 0);
                        ++v45;
                    }
                    for ( ; j < max.y; ++j )
                    {
                        if ( !TribeInformationAIModule::insideGate(v11, numberGates, v45, j) )
                            TribeInformationAIModule::storeLot(v11, 72, v45, j, 0);
                    }
                    for ( ; v45 > max.x; ++j )
                    {
                        if ( !TribeInformationAIModule::insideGate(v11, numberGates, v45, j) )
                            TribeInformationAIModule::storeLot(v11, 72, v45, j, 0);
                        --v45;
                    }
                    for ( ; v45 > min.x; --v45 )
                    {
                        if ( !TribeInformationAIModule::insideGate(v11, numberGates, v45, j) )
                            TribeInformationAIModule::storeLot(v11, 72, v45, j, 0);
                    }
                    for ( ; j > max.y; --j )
                    {
                        if ( !TribeInformationAIModule::insideGate(v11, numberGates, v45, j) )
                            TribeInformationAIModule::storeLot(v11, 72, v45, j, 0);
                        --v45;
                    }
                    for ( ; j > min.y; --j )
                    {
                        if ( !TribeInformationAIModule::insideGate(v11, numberGates, v45, j) )
                            TribeInformationAIModule::storeLot(v11, 72, v45, j, 0);
                    }
                    v25 = gateSizeb == 1;
                    --yb;
                    ++townWallsd;
                    minDistancec -= 2;
                    xb += 2;
                    --gateSizeb;
                }
                while ( !v25 );
            }
            break;
    }
}

//----- (004E0F40) --------------------------------------------------------
int TribeInformationAIModule::insideGate(int numGates, int x, int y)
{
    int v4; // edx@1
    char *v5; // eax@2
    int result; // eax@8

    v4 = 0;
    if ( numGates <= 0 )
    {
        result = 0;
    }
    else
    {
        v5 = (char *)&this->minGatePosition[0].y;
        while ( *((_DWORD *)v5 - 1) > x || *(_DWORD *)v5 > y || x > *((_DWORD *)v5 + 7) || y > *((_DWORD *)v5 + 8) )
        {
            ++v4;
            v5 += 8;
            if ( v4 >= numGates )
                return 0;
        }
        result = 1;
    }
    return result;
}

//----- (004E0F90) --------------------------------------------------------
int TribeInformationAIModule::storeAttackMemory(char type, char x1, char y1, char attackingOwner, char targetOwner, __int16 kills, char success, unsigned int timeStamp, int play)
{
    return TribeInformationAIModule::storeAttackMemory(
                     this,
                     type,
                     x1,
                     y1,
                     x1,
                     y1,
                     attackingOwner,
                     targetOwner,
                     kills,
                     success,
                     timeStamp,
                     play);
}

//----- (004E0FD0) --------------------------------------------------------
int TribeInformationAIModule::storeAttackMemory(char type, char x1, char y1, char x2, char y2, char attackingOwner, char targetOwner, __int16 kills, char success, unsigned int timeStamp, int play)
{
    int v12; // edi@1
    int v13; // ebx@2
    __int64 v14; // rax@3
    int v15; // edi@3
    __int64 v16; // rax@3
    int v17; // eax@3
    __int16 v18; // si@7
    char *v19; // eax@8
    signed int v20; // edi@12
    int v21; // esi@12
    AttackMemory *v22; // ebx@13
    int v23; // edx@13
    unsigned int *v24; // eax@13
    signed int v25; // edx@22
    signed int v27; // [sp+10h] [bp-4h]@13

    v12 = this->mapXSizeValue;
    if ( v12 > 0 )
    {
        v13 = this->mapYSizeValue;
        if ( v13 > 0 )
        {
            v14 = 4 * ((unsigned __int8)x1 + (unsigned __int8)x2) / v12;
            v15 = ((signed int)v14 - HIDWORD(v14)) >> 1;
            v16 = 4 * ((unsigned __int8)x1 + (unsigned __int8)x2) / v13;
            v17 = ((signed int)v16 - HIDWORD(v16)) >> 1;
            if ( v15 > 4 )
                v15 = 3;
            if ( v17 > 4 )
                v17 = 3;
            v18 = this->md->player->id;
            if ( (unsigned __int8)targetOwner == v18 )
            {
                v19 = (char *)&this->quadrantLog[0][v17 + 4 * v15].numberAttacksOnUs;
            }
            else
            {
                if ( (unsigned __int8)attackingOwner != v18 )
                    goto LABEL_12;
                v19 = (char *)&this->quadrantLog[0][v17 + 4 * v15].numberAttacksByUs;
            }
            ++*(_DWORD *)v19;
        }
    }
LABEL_12:
    v20 = -1;
    v21 = 0;
    if ( this->maxAttackMemories > 0 )
    {
        v22 = this->attackMemories;
        v27 = -24;
        v23 = 0;
        v24 = &v22->timeStamp;
        while ( v22[v23].id != -1 )
        {
            if ( v20 == -1 || *(unsigned int *)((char *)&v22->timeStamp + v27) < *v24 )
            {
                v20 = v21;
                v27 = v23 * 24;
            }
            ++v21;
            ++v23;
            v24 += 6;
            if ( v21 >= this->maxAttackMemories )
                goto LABEL_21;
        }
        v20 = v21;
    }
LABEL_21:
    if ( v20 != -1 )
    {
        v25 = v20;
        this->attackMemories[v25].id = v21;
        this->attackMemories[v25].type = type;
        this->attackMemories[v25].minX = x1;
        this->attackMemories[v25].minY = y1;
        this->attackMemories[v25].maxX = x2;
        this->attackMemories[v25].maxY = y2;
        this->attackMemories[v25].attackingOwner = attackingOwner;
        this->attackMemories[v25].targetOwner = targetOwner;
        this->attackMemories[v25].kills = kills;
        this->attackMemories[v25].success = success;
        this->attackMemories[v25].timeStamp = timeStamp;
        this->attackMemories[v25].play = play;
    }
    return v20;
}

//----- (004E1190) --------------------------------------------------------
void TribeInformationAIModule::removeAttackMemory(int id)
{
    int v2; // eax@3

    if ( id >= 0 && id < this->maxAttackMemories )
    {
        v2 = id;
        this->attackMemories[v2].id = -1;
        this->attackMemories[v2].type = 0;
        this->attackMemories[v2].minX = 0;
        this->attackMemories[v2].minY = 0;
        this->attackMemories[v2].maxX = 0;
        this->attackMemories[v2].maxY = 0;
        this->attackMemories[v2].attackingOwner = -1;
        this->attackMemories[v2].targetOwner = -1;
        this->attackMemories[v2].kills = 0;
        this->attackMemories[v2].success = 0;
        this->attackMemories[v2].play = -1;
    }
}

//----- (004E1230) --------------------------------------------------------
AttackMemory *TribeInformationAIModule::attackMemory(int id)
{
    AttackMemory *result; // eax@3

    if ( id < 0 || id >= this->maxAttackMemories )
        result = 0;
    else
        result = &this->attackMemories[id];
    return result;
}

//----- (004E1260) --------------------------------------------------------
void TribeInformationAIModule::loadLearnInfo(char *name)
{
    TribeInformationAIModule *v2; // esi@1
    char *v3; // edi@1
    RGE_Person_Info *v4; // eax@3
    int v5; // eax@4
    int v6; // ebp@4
    void *v7; // edi@5
    int v8; // ecx@8
    int v9; // eax@8
    int v10; // ebx@14
    int i; // eax@15
    int *v12; // edi@21
    signed int v13; // ebx@21
    void *v14; // eax@22
    int v15; // ecx@24
    int v16; // eax@24
    int v17; // ebx@30
    int j; // eax@31
    int v19; // ecx@38
    int v20; // eax@38
    int v21; // ebx@44
    int k; // eax@45
    int v23; // [sp-4h] [bp-48h]@1
    int numMemoriesToLoad; // [sp+10h] [bp-34h]@5
    int numToLoad; // [sp+14h] [bp-30h]@23
    int tempInt; // [sp+18h] [bp-2Ch]@24
    int v27; // [sp+1Ch] [bp-28h]@8
    ObjectMemory temp; // [sp+20h] [bp-24h]@6
    char *namea; // [sp+48h] [bp+4h]@7
    char *nameb; // [sp+48h] [bp+4h]@23
    char *namec; // [sp+48h] [bp+4h]@37

    v2 = this;
    v3 = this->learnFileName;
    v23 = this->md->player->id;
    if ( name )
    {
        v4 = RGE_Game_Info::get_current_player_name(rge_base_game->player_game_info);
        sprintf(v3, aLearnSS_D, name, v4, v23);
    }
    else
    {
        sprintf(v3, aLearnDefault_D, v23);
    }
    v5 = rge_open(v3, 0x8000);
    v6 = v5;
    if ( v5 != -1 )
    {
        rge_read(v5, (int)v3, v5, &v2->mapXSizeValue, 4);
        rge_read(v6, (int)v3, v6, &v2->mapYSizeValue, 4);
        rge_read(v6, (int)v3, v6, &numMemoriesToLoad, 4);
        v7 = 0;
        if ( numMemoriesToLoad > 0 )
        {
            do
            {
                rge_read(v6, (int)v7, v6, &temp, 24);
                TribeInformationAIModule::storeAttackMemory(
                    v2,
                    temp.type,
                    SHIBYTE(temp.type),
                    temp.group,
                    SHIBYTE(temp.group),
                    temp.x,
                    temp.y,
                    temp.z,
                    temp.hitPoints,
                    *((char *)&temp.hitPoints + 2),
                    temp.attackAttempts,
                    *(int *)&temp.kills);
                v7 = (char *)v7 + 1;
            }
            while ( (signed int)v7 < numMemoriesToLoad );
        }
        rge_read(v6, (int)v7, v6, &numMemoriesToLoad, 4);
        namea = 0;
        if ( numMemoriesToLoad > 0 )
        {
            do
            {
                rge_read(v6, (int)v7, v6, &temp, 36);
                TribeInformationAIModule::addObjectMemory(
                    v2,
                    temp.id,
                    temp.type,
                    temp.group,
                    temp.x,
                    temp.y,
                    temp.z,
                    temp.owner,
                    temp.hitPoints,
                    temp.attackAttempts,
                    temp.kills,
                    temp.damageCapability,
                    temp.rateOfFire,
                    temp.range,
                    0);
                v8 = v2->importantUnits.numberValue;
                v9 = 0;
                v27 = temp.id;
                if ( v8 > 0 )
                {
                    v7 = (void *)v2->importantUnits.maximumSizeValue;
                    do
                    {
                        if ( v9 >= (signed int)v7 )
                            break;
                        if ( v2->importantUnits.value[v9] == temp.id )
                            goto LABEL_20;
                        ++v9;
                    }
                    while ( v9 < v8 );
                }
                if ( v8 > v2->importantUnits.maximumSizeValue - 1 )
                {
                    v10 = v8 + 1;
                    v7 = operator new(4 * (v8 + 1));
                    if ( v7 )
                    {
                        for ( i = 0; i < v2->importantUnits.maximumSizeValue; *((_DWORD *)v7 + i - 1) = v2->importantUnits.value[i - 1] )
                        {
                            if ( i >= v10 )
                                break;
                            ++i;
                        }
                        operator delete(v2->importantUnits.value);
                        v2->importantUnits.value = (int *)v7;
                        v2->importantUnits.maximumSizeValue = v10;
                    }
                }
                v2->importantUnits.value[v2->importantUnits.numberValue++] = v27;
LABEL_20:
                ++namea;
            }
            while ( (signed int)namea < numMemoriesToLoad );
        }
        v12 = v2->maxResources;
        v13 = 4;
        do
        {
            rge_read(v6, (int)v12, v6, v12, 4);
            rge_read(v6, (int)v12, v6, v12 - 4, 4);
            v14 = operator new(20 * *v12);
            *(v12 - 8) = (int)v14;
            rge_read(v6, (int)v12, v6, v14, 20 * *v12);
            ++v12;
            --v13;
        }
        while ( v13 );
        rge_read(v6, (int)v12, v6, &numToLoad, 4);
        nameb = 0;
        if ( numToLoad > 0 )
        {
            do
            {
                rge_read(v6, (int)v12, v6, &tempInt, 4);
                v15 = v2->importantMiscs.numberValue;
                v16 = 0;
                v27 = tempInt;
                if ( v15 > 0 )
                {
                    v12 = (int *)v2->importantMiscs.maximumSizeValue;
                    do
                    {
                        if ( v16 >= (signed int)v12 )
                            break;
                        if ( v2->importantMiscs.value[v16] == tempInt )
                            goto LABEL_36;
                        ++v16;
                    }
                    while ( v16 < v15 );
                }
                if ( v15 > v2->importantMiscs.maximumSizeValue - 1 )
                {
                    v17 = v15 + 1;
                    v12 = (int *)operator new(4 * (v15 + 1));
                    if ( v12 )
                    {
                        for ( j = 0; j < v2->importantMiscs.maximumSizeValue; v12[j - 1] = v2->importantMiscs.value[j - 1] )
                        {
                            if ( j >= v17 )
                                break;
                            ++j;
                        }
                        operator delete(v2->importantMiscs.value);
                        v2->importantMiscs.value = v12;
                        v2->importantMiscs.maximumSizeValue = v17;
                    }
                }
                v2->importantMiscs.value[v2->importantMiscs.numberValue++] = v27;
LABEL_36:
                ++nameb;
            }
            while ( (signed int)nameb < numToLoad );
        }
        rge_read(v6, (int)v12, v6, &numToLoad, 4);
        namec = 0;
        if ( numToLoad > 0 )
        {
            do
            {
                rge_read(v6, (int)v12, v6, &tempInt, 4);
                v19 = v2->itemsToDefend.numberValue;
                v20 = 0;
                v27 = tempInt;
                if ( v19 > 0 )
                {
                    v12 = (int *)v2->itemsToDefend.maximumSizeValue;
                    do
                    {
                        if ( v20 >= (signed int)v12 )
                            break;
                        if ( v2->itemsToDefend.value[v20] == tempInt )
                            goto LABEL_50;
                        ++v20;
                    }
                    while ( v20 < v19 );
                }
                if ( v19 > v2->itemsToDefend.maximumSizeValue - 1 )
                {
                    v21 = v19 + 1;
                    v12 = (int *)operator new(4 * (v19 + 1));
                    if ( v12 )
                    {
                        for ( k = 0; k < v2->itemsToDefend.maximumSizeValue; v12[k - 1] = v2->itemsToDefend.value[k - 1] )
                        {
                            if ( k >= v21 )
                                break;
                            ++k;
                        }
                        operator delete(v2->itemsToDefend.value);
                        v2->itemsToDefend.value = v12;
                        v2->itemsToDefend.maximumSizeValue = v21;
                    }
                }
                v2->itemsToDefend.value[v2->itemsToDefend.numberValue++] = v27;
LABEL_50:
                ++namec;
            }
            while ( (signed int)namec < numToLoad );
        }
        rge_close(v6);
    }
}

//----- (004E1720) --------------------------------------------------------
void TribeInformationAIModule::setSaveLearnInformation(int v)
{
    this->saveLearnInformationValue = v;
}

//----- (004E1730) --------------------------------------------------------
int TribeInformationAIModule::unexploredPlayerLocation(int uID, XYPoint *rPoint)
{
    int v3; // edi@1
    TribeInformationAIModule *v4; // esi@1
    RGE_Static_Object *v5; // eax@1
    RGE_Static_Object *v6; // ebx@1
    int v7; // edi@2
    int v8; // ebp@2
    int v9; // eax@3
    char v10; // al@7
    int v11; // eax@8
    float z; // ST20_4@8
    float y; // ST1C_4@8
    float x; // ST18_4@8
    signed __int64 v15; // rax@8
    XYPoint *v16; // edi@13
    int v17; // ebp@13
    float v18; // ST0C_4@13
    int result; // eax@14
    int bestDistance; // [sp+28h] [bp-18h]@2
    int i; // [sp+2Ch] [bp-14h]@2

    v3 = uID;
    v4 = this;
    v5 = MainDecisionAIModule::object((MainDecisionAIModule *)&this->md->vfptr, uID);
    v6 = v5;
    if ( !v3 )
        goto LABEL_19;
    LOBYTE(uID) = RGE_Static_Object::currentZone(v5);
    v7 = 0;
    v8 = 0;
    bestDistance = -1;
    for ( i = 0; i < v4->maxImportantObjectMemory; ++i )
    {
        v9 = (int)&v4->importantObjectMemory[v7].id;
        if ( *(_DWORD *)v9 != -1 && *(_BYTE *)(v9 + 11) != v4->md->player->id )
        {
            if ( *(_BYTE *)(v9 + 11) )
            {
                if ( TribeInformationAIModule::tileUncovered(v4, *(_BYTE *)(v9 + 8), *(_BYTE *)(v9 + 9)) != 1 )
                {
                    v10 = RGE_Static_Object::lookupZone(v6, v4->importantObjectMemory[v7].x, v4->importantObjectMemory[v7].y);
                    if ( v10 == (_BYTE)uID )
                    {
                        v11 = (int)&v4->importantObjectMemory[v7].id;
                        z = (double)*(_BYTE *)(v11 + 10);
                        y = (double)*(_BYTE *)(v11 + 9);
                        x = (double)*(_BYTE *)(v11 + 8);
                        v15 = (signed __int64)RGE_Static_Object::distance_to_position(v6, x, y, z);
                        if ( !v8 || bestDistance > (signed int)v15 )
                        {
                            v8 = (int)&v4->importantObjectMemory[v7].id;
                            bestDistance = v15;
                        }
                    }
                }
            }
        }
        ++v7;
    }
    if ( v8 )
    {
        v16 = rPoint;
        rPoint->x = *(_BYTE *)(v8 + 8);
        v17 = *(_BYTE *)(v8 + 9);
        v16->y = v17;
        v18 = v6->master_obj->los - 1.0;
        if ( ((int (*)(RGE_Static_Object *, int, int, _DWORD, _DWORD, signed int, int *, signed int, signed int, signed int))v6->vfptr->canPath)(
                     v6,
                     v16->x,
                     v17,
                     (signed __int64)v6->world_z,
                     LODWORD(v18),
                     -1,
                     &uID,
                     1,
                     -1,
                     -1) )
        {
            InfluenceMap::setValue(&v4->pathMap, v16->x, v16->y, 0);
            result = 1;
        }
        else
        {
            InfluenceMap::setValue(&v4->pathMap, v16->x, v16->y, 1);
            result = 0;
        }
    }
    else
    {
LABEL_19:
        result = 0;
    }
    return result;
}

//----- (004E1930) --------------------------------------------------------
int TribeInformationAIModule::numberUnitsWithinXTiles(int playerID, int x, int y, int numTiles)
{
    TribeInformationAIModule *v5; // esi@1
    int v6; // edi@1
    int v7; // ebp@1
    int v8; // edx@2
    int v9; // eax@6
    int i; // [sp+Ch] [bp-4h]@1
    int numTilesa; // [sp+20h] [bp+10h]@1

    v5 = this;
    v6 = 0;
    v7 = numTiles * numTiles;
    numTilesa = 0;
    i = 0;
    if ( this->maxImportantObjectMemory > 0 )
    {
        v8 = playerID;
        do
        {
            if ( v8 != -1 )
            {
                if ( v5->importantObjectMemory[v6].owner != v8 )
                    goto LABEL_9;
                if ( v8 != -1 )
                    goto LABEL_7;
            }
            v9 = (*(int (__stdcall **)(_DWORD))&v5->md->player->vfptr->gap4[20])(v5->importantObjectMemory[v6].owner);
            v8 = playerID;
            if ( v9 )
            {
LABEL_7:
                if ( (v5->importantObjectMemory[v6].y - y) * (v5->importantObjectMemory[v6].y - y)
                     + (v5->importantObjectMemory[v6].x - x) * (v5->importantObjectMemory[v6].x - x) <= v7 )
                    ++numTilesa;
            }
LABEL_9:
            ++v6;
            ++i;
        }
        while ( i < v5->maxImportantObjectMemory );
    }
    return numTilesa;
}

//----- (004E1A00) --------------------------------------------------------
int TribeInformationAIModule::withinXTilesOfAttackOnPlayer(RGE_Static_Object *obj, int numTiles, int victimID)
{
    int v4; // ebp@1
    int v5; // ebx@1
    int v6; // edi@1
    AttackMemory *v7; // edx@2
    int v8; // edi@6
    int v9; // ecx@6
    int v10; // esi@7
    int v11; // ecx@8
    int v13; // [sp+10h] [bp-4h]@1
    RGE_Static_Object *obja; // [sp+18h] [bp+4h]@1
    int i; // [sp+1Ch] [bp+8h]@1

    v4 = numTiles * numTiles;
    v5 = (signed __int64)obj->world_x;
    v6 = this->maxAttackMemories;
    i = (signed __int64)obj->world_y;
    obja = 0;
    v13 = this->maxAttackMemories;
    if ( v6 > 0 )
    {
        v7 = this->attackMemories;
        while ( 1 )
        {
            if ( v7->id != -1 && v7->attackingOwner && v7->targetOwner == victimID )
            {
                v8 = v7->minY - i;
                v9 = (v7->minX - v5) * (v7->minX - v5);
                if ( v9 + v8 * v8 <= v4 )
                    return 1;
                v10 = (v7->maxY - i) * (v7->maxY - i);
                if ( v10 + v9 <= v4 )
                    return 1;
                v11 = (v7->maxX - v5) * (v7->maxX - v5);
                if ( v11 + v10 <= v4 || v11 + v8 * v8 <= v4 )
                    return 1;
                v6 = v13;
            }
            ++v7;
            obja = (RGE_Static_Object *)((char *)obja + 1);
            if ( (signed int)obja >= v6 )
                return 0;
        }
    }
    return 0;
}

//----- (004E1AF0) --------------------------------------------------------
int TribeInformationAIModule::withinXTilesOfEnemyTowncenter(RGE_Static_Object *obj, int distance)
{
    TribeInformationAIModule *v3; // esi@1
    int v4; // ebp@1
    double v5; // st7@1
    int v6; // edi@1
    int v7; // eax@2
    ObjectMemory *v8; // eax@4
    int v9; // edx@4
    int v10; // eax@4
    int result; // eax@6
    RGE_Static_Object *obja; // [sp+18h] [bp+4h]@1
    int x; // [sp+1Ch] [bp+8h]@1

    v3 = this;
    v4 = distance * distance;
    v5 = obj->world_y;
    obja = (RGE_Static_Object *)(signed __int64)obj->world_x;
    v6 = 0;
    x = 0;
    if ( this->maxImportantObjectMemory <= 0 )
    {
        result = 0;
    }
    else
    {
        while ( 1 )
        {
            v7 = (int)&v3->importantObjectMemory[v6].id;
            if ( *(_WORD *)(v7 + 4) == 109 )
            {
                if ( (*(int (__stdcall **)(_DWORD))&v3->md->player->vfptr->gap4[20])(*(_BYTE *)(v7 + 11)) )
                {
                    v8 = v3->importantObjectMemory;
                    v9 = v8[v6].y;
                    v10 = v8[v6].x - (_DWORD)obja;
                    if ( (signed int)((v9 - (unsigned __int64)(signed __int64)v5) * (v9 - (unsigned __int64)(signed __int64)v5)
                                                    + v10 * v10) <= v4 )
                        break;
                }
            }
            ++v6;
            if ( ++x >= v3->maxImportantObjectMemory )
                return 0;
        }
        result = 1;
    }
    return result;
}

//----- (004E1BD0) --------------------------------------------------------
int TribeInformationAIModule::withinXTilesOfObject(RGE_Static_Object *obj, int distance, int oT1, int oT2, int oT3, int oT4)
{
    TribeInformationAIModule *v7; // esi@1
    int v8; // ebp@1
    int v9; // edi@1
    RGE_Static_Object *v10; // eax@2
    int v11; // edx@5
    int v12; // eax@5
    int v13; // edx@10
    int v14; // eax@10
    int i; // [sp+Ch] [bp-Ch]@1
    int x; // [sp+10h] [bp-8h]@1
    int y; // [sp+14h] [bp-4h]@1
    RGE_Static_Object *obja; // [sp+1Ch] [bp+4h]@1
    int rDistance; // [sp+20h] [bp+8h]@1

    v7 = this;
    v8 = distance * distance;
    x = (signed __int64)obj->world_x;
    y = (signed __int64)obj->world_y;
    rDistance = -1;
    obja = (RGE_Static_Object *)-1;
    v9 = 0;
    for ( i = 0; i < v7->maxImportantObjectMemory; ++i )
    {
        v10 = MainDecisionAIModule::object((MainDecisionAIModule *)&v7->md->vfptr, v7->importantObjectMemory[v9].id);
        if ( v10 )
        {
            if ( v10->object_state <= 2u && v10->hp != 0.0 )
            {
                v11 = (int)&v7->importantObjectMemory[v9].id;
                v12 = *(_WORD *)(v11 + 4);
                if ( v12 == oT1 || v12 == oT2 || v12 == oT3 || v12 == oT4 )
                {
                    if ( (*(int (__stdcall **)(_DWORD))&v7->md->player->vfptr->gap4[20])(*(_BYTE *)(v11 + 11)) )
                    {
                        v13 = (int)&v7->importantObjectMemory[v9].id;
                        v14 = (*(_BYTE *)(v13 + 9) - y) * (*(_BYTE *)(v13 + 9) - y)
                                + (*(_BYTE *)(v13 + 8) - x) * (*(_BYTE *)(v13 + 8) - x);
                        if ( v14 <= v8 && (v14 < (signed int)obja || rDistance == -1) )
                        {
                            obja = (RGE_Static_Object *)((*(_BYTE *)(v13 + 9) - y) * (*(_BYTE *)(v13 + 9) - y)
                                                                                 + (*(_BYTE *)(v13 + 8) - x) * (*(_BYTE *)(v13 + 8) - x));
                            rDistance = *(_DWORD *)v13;
                        }
                    }
                }
            }
        }
        ++v9;
    }
    return rDistance;
}

//----- (004E1D10) --------------------------------------------------------
RGE_Static_Object *TribeInformationAIModule::findStagingPoint(XYPoint startPoint, XYPoint *rPoint, int useTransport, int landTerrainRequired, int targetID, int stageDistance, int unitID)
{
    TribeInformationAIModule *v8; // ebx@1
    RGE_Static_Object *result; // eax@1
    RGE_Static_Object *v10; // edi@1
    RGE_Static_Object *v11; // ebp@2
    int v12; // edx@5
    int v13; // esi@5
    TribeMainDecisionAIModule *v14; // eax@7
    int v15; // edi@7
    int v16; // ebp@8
    int v17; // ecx@8
    int v18; // eax@8
    char v19; // bl@12
    signed int v20; // ebx@24
    int v21; // esi@27
    char v22; // al@29
    float v23; // ST10_4@31
    float v24; // ST0C_4@31
    bool v25; // zf@34
    bool v26; // sf@34
    unsigned __int8 v27; // of@34
    int v28; // ebx@36
    signed int v29; // eax@36
    int v30; // esi@36
    int v31; // edi@37
    int v32; // eax@40
    int v33; // eax@42
    int v34; // [sp+1Ch] [bp-6Ch]@25
    RGE_Static_Object *unit; // [sp+20h] [bp-68h]@2
    int v36; // [sp+24h] [bp-64h]@8
    int bestValue; // [sp+28h] [bp-60h]@7
    RGE_Map *gMap; // [sp+2Ch] [bp-5Ch]@7
    signed int b; // [sp+30h] [bp-58h]@27
    signed int maxLOSValue; // [sp+34h] [bp-54h]@7
    signed int maxAttackValue; // [sp+38h] [bp-50h]@7
    RGE_Visible_Map *vMap; // [sp+3Ch] [bp-4Ch]@7
    TribeInformationAIModule *v43; // [sp+40h] [bp-48h]@1
    ObjectMemory *target; // [sp+44h] [bp-44h]@1
    XYPoint passableMax; // [sp+48h] [bp-40h]@24
    XYPoint max; // [sp+50h] [bp-38h]@7
    XYPoint min; // [sp+58h] [bp-30h]@7
    XYPoint zoneRefPoint; // [sp+60h] [bp-28h]@7
    XYPoint passableMin; // [sp+68h] [bp-20h]@24
    XYPoint targetPoint; // [sp+70h] [bp-18h]@7
    XYPoint temp; // [sp+78h] [bp-10h]@36
    XYPoint temp2; // [sp+80h] [bp-8h]@36
    int randomization; // [sp+8Ch] [bp+4h]@24
    int randomizationa; // [sp+8Ch] [bp+4h]@36
    char targetIDa; // [sp+A0h] [bp+18h]@7
    int unitIDa; // [sp+A8h] [bp+20h]@7

    v8 = this;
    v43 = this;
    result = (RGE_Static_Object *)TribeInformationAIModule::objectMemory(this, targetID);
    v10 = result;
    target = (ObjectMemory *)result;
    if ( result )
    {
        result = MainDecisionAIModule::object((MainDecisionAIModule *)&v8->md->vfptr, unitID);
        v11 = result;
        unit = result;
        if ( result )
        {
            if ( TribeInformationAIModule::isBoat(result) != 1 || useTransport )
            {
                v12 = 2;
                v13 = 0;
            }
            else
            {
                v12 = 1;
                v13 = 22;
            }
            zoneRefPoint = startPoint;
            RGE_Static_Object::findClosestPointInTerrainType(v11, startPoint, &zoneRefPoint, v12, v13, 4);
            targetIDa = RGE_Static_Object::lookupZone(v11, zoneRefPoint.x, zoneRefPoint.y);
            maxLOSValue = TribeInformationAIModule::setupLOSMap(
                                            v8,
                                            (int)v8,
                                            BYTE3(v10->master_obj),
                                            LOBYTE(v10->master_obj),
                                            BYTE1(v10->master_obj));
            maxAttackValue = TribeInformationAIModule::setupAttackMap(
                                                 v8,
                                                 (int)v8,
                                                 BYTE3(v10->master_obj),
                                                 LOBYTE(v10->master_obj),
                                                 BYTE1(v10->master_obj));
            min.x = LOBYTE(v10->master_obj) - stageDistance;
            min.y = BYTE1(v10->master_obj) - stageDistance;
            TribeInformationAIModule::mapBound(v8, &min);
            max.x = LOBYTE(v10->master_obj) + stageDistance;
            max.y = BYTE1(v10->master_obj) + stageDistance;
            TribeInformationAIModule::mapBound(v8, &max);
            targetPoint.x = LOBYTE(v10->master_obj);
            targetPoint.y = BYTE1(v10->master_obj);
            TribeInformationAIModule::mapBound(v8, &targetPoint);
            v14 = v8->md;
            v15 = min.x;
            bestValue = -1;
            vMap = v14->player->visible;
            gMap = v14->aiPlayer->world->map;
            unitIDa = min.x;
            if ( min.x > max.x )
                return (RGE_Static_Object *)(bestValue != -1);
            v16 = min.y;
            v17 = max.y;
            v18 = 24 * min.x;
            v36 = 24 * min.x;
            while ( 1 )
            {
                if ( v16 > v17 )
                    goto LABEL_48;
                while ( 1 )
                {
                    v19 = *((_BYTE *)gMap->map_row_offset[v16] + v18 + 5) & 0x1F;
                    RGE_Visible_Map::get_visible(vMap, v15, v16);
                    if ( useTransport == 1 )
                    {
                        if ( v19 != 2 )
                            goto LABEL_46;
                    }
                    else if ( landTerrainRequired == 1 )
                    {
                        if ( v19 == 1 || v19 == 22 )
                            goto LABEL_46;
                    }
                    else if ( !landTerrainRequired && v19 != 1 && v19 != 22 )
                    {
                        goto LABEL_46;
                    }
                    if ( RGE_Static_Object::lookupZone(unit, v15, v16) != targetIDa )
                        goto LABEL_46;
                    if ( useTransport != 1 )
                        goto LABEL_36;
                    passableMin.x = v15 - 2;
                    passableMin.y = v16 - 2;
                    TribeInformationAIModule::mapBound(v43, &passableMin);
                    passableMax.x = v15 + 2;
                    passableMax.y = v16 + 2;
                    TribeInformationAIModule::mapBound(v43, &passableMax);
                    v20 = 1;
                    randomization = passableMin.x;
                    if ( passableMin.x > passableMax.x )
                    {
LABEL_35:
                        if ( !v20 )
                            goto LABEL_46;
LABEL_36:
                        v28 = (signed __int64)sqrt((double)((target->y - v16) * (target->y - v16)
                                                                                            + (target->x - v15) * (target->x - v15)));
                        v29 = debug_rand(aCMsdevWorkA_52, 6975);
                        temp.x = v15;
                        temp.y = v16;
                        randomizationa = v29 % (3 * stageDistance);
                        v30 = ((int (__stdcall *)(XYPoint *, XYPoint *, signed int, XYPoint *, signed int))unit->vfptr->canLinePath)(
                                        &temp,
                                        &targetPoint,
                                        1065353216,
                                        &temp2,
                                        1) == 1 ? stageDistance : 0;
                        if ( maxLOSValue <= 0 )
                            v31 = 0;
                        else
                            v31 = -(stageDistance * InfluenceMap::lookupValue(&losMap, v15, v16) / maxLOSValue);
                        if ( maxAttackValue <= 0 )
                            v32 = 0;
                        else
                            v32 = -(stageDistance * InfluenceMap::lookupValue(&attackMap, unitIDa, v16) / maxAttackValue);
                        v33 = v28 + randomizationa + v30 + v31 + v32;
                        if ( bestValue == -1 || bestValue < v33 )
                        {
                            bestValue = v33;
                            rPoint->x = unitIDa;
                            rPoint->y = v16;
                        }
                        v15 = unitIDa;
                        goto LABEL_46;
                    }
                    v34 = passableMin.x;
                    while ( v20 )
                    {
                        v21 = passableMin.y;
                        for ( b = passableMin.y; v21 <= passableMax.y; b = ++v21 )
                        {
                            if ( !v20 )
                                break;
                            v22 = *((_BYTE *)&gMap->map_row_offset[v21][v34] + 5) & 0x1F;
                            if ( v22 != 1 && v22 != 22 )
                            {
                                v23 = (double)b;
                                v24 = (double)randomization;
                                if ( !((int (__stdcall *)(_DWORD, _DWORD, signed int))unit->vfptr->passableTile)(
                                                LODWORD(v24),
                                                LODWORD(v23),
                                                1) )
                                    v20 = 0;
                            }
                        }
                        v27 = __OFSUB__(randomization + 1, passableMax.x);
                        v25 = randomization + 1 == passableMax.x;
                        v26 = randomization++ + 1 - passableMax.x < 0;
                        ++v34;
                        if ( !((unsigned __int8)(v26 ^ v27) | v25) )
                            goto LABEL_35;
                    }
LABEL_46:
                    v17 = max.y;
                    if ( ++v16 > max.y )
                        break;
                    v18 = v36;
                }
                v16 = min.y;
                v18 = v36;
LABEL_48:
                ++v15;
                v18 += 24;
                unitIDa = v15;
                v36 = v18;
                if ( v15 > max.x )
                    return (RGE_Static_Object *)(bestValue != -1);
            }
        }
    }
    return result;
}

//----- (004E21E0) --------------------------------------------------------
int TribeInformationAIModule::setupLOSMap@<eax>(TribeInformationAIModule *this@<ecx>, int a2@<ebx>, int ownerID, int x, int y)
{
    TribeInformationAIModule *v5; // edi@1
    int v6; // eax@3
    RGE_Static_Object *v7; // eax@4
    RGE_Static_Object *v8; // esi@4
    int v9; // edi@5
    signed __int64 v10; // rax@5
    double v11; // st7@5
    int v12; // ebx@5
    int v13; // ebp@5
    int v14; // edi@5
    char v15; // al@5
    int v16; // ecx@8
    bool v17; // sf@8
    unsigned __int8 v18; // of@8
    int maxX; // [sp+8h] [bp-8h]@5
    TribeInformationAIModule *v21; // [sp+Ch] [bp-4h]@1
    int xa; // [sp+18h] [bp+8h]@1
    int i; // [sp+1Ch] [bp+Ch]@2

    v5 = this;
    v21 = this;
    InfluenceMap::initialize(&losMap, a2, 0);
    InfluenceMap::setReferencePoint(&losMap, x, y);
    xa = 0;
    if ( v5->maxImportantObjectMemory > 0 )
    {
        i = 0;
        do
        {
            v6 = (int)&v5->importantObjectMemory[i].id;
            if ( *(_BYTE *)(v6 + 11) == ownerID )
            {
                v7 = MainDecisionAIModule::object((MainDecisionAIModule *)&v5->md->vfptr, *(_DWORD *)v6);
                v8 = v7;
                if ( v7 )
                {
                    v9 = (signed __int64)v7->master_obj->los;
                    v10 = (signed __int64)v7->world_x;
                    v11 = v8->world_y;
                    v12 = v10 - v9;
                    maxX = v9 + v10;
                    v13 = (unsigned __int64)(signed __int64)v11 - v9;
                    v14 = (unsigned __int64)(signed __int64)v11 + v9;
                    ((void (*)(RGE_Static_Object *))v8->vfptr->damageCapability)(v8);
                    v15 = 5;
                    if ( v11 <= 0.0 )
                        v15 = 1;
                    InfluenceMap::incrementValue(&losMap, v12, v13, maxX, v14, v15);
                    v5 = v21;
                }
            }
            v16 = v5->maxImportantObjectMemory;
            v18 = __OFSUB__(xa + 1, v16);
            v17 = xa++ + 1 - v16 < 0;
            ++i;
        }
        while ( v17 ^ v18 );
    }
    return InfluenceMap::maxValue(&losMap);
}

//----- (004E22F0) --------------------------------------------------------
int TribeInformationAIModule::setupAttackMap@<eax>(TribeInformationAIModule *this@<ecx>, int a2@<ebx>, int ownerID, int x, int y)
{
    TribeInformationAIModule *v5; // esi@1
    int v6; // ebx@1
    int v7; // edi@2
    int v8; // eax@3

    v5 = this;
    InfluenceMap::initialize(&attackMap, a2, 0);
    InfluenceMap::setReferencePoint(&attackMap, x, y);
    v6 = 0;
    if ( v5->maxAttackMemories > 0 )
    {
        v7 = 0;
        do
        {
            v8 = (int)&v5->attackMemories[v7].id;
            if ( *(_BYTE *)(v8 + 10) == ownerID && *(_BYTE *)(v8 + 9) == v5->md->player->id )
                InfluenceMap::incrementValue(
                    &attackMap,
                    *(_BYTE *)(v8 + 5),
                    *(_BYTE *)(v8 + 6),
                    *(_BYTE *)(v8 + 7),
                    *(_BYTE *)(v8 + 8),
                    1);
            ++v6;
            ++v7;
        }
        while ( v6 < v5->maxAttackMemories );
    }
    return InfluenceMap::maxValue(&attackMap);
}

//----- (004E23A0) --------------------------------------------------------
void TribeInformationAIModule::addResourceType(int r, int t)
{
    TribeInformationAIModule *v3; // esi@1
    int v4; // edi@1
    int *v5; // ebx@1
    int i; // eax@1

    v3 = this;
    v4 = r;
    v5 = (int *)operator new(4 * this->numberResourceTypesValue[r] + 4);
    for ( i = 0; i < v3->numberResourceTypesValue[v4]; v5[i - 1] = v3->resourceTypesValue[v4][i - 1] )
        ++i;
    v5[i] = t;
    if ( v3->resourceTypesValue[v4] )
        operator delete(v3->resourceTypesValue[v4]);
    v3->resourceTypesValue[v4] = v5;
    ++v3->numberResourceTypesValue[v4];
}

//----- (004E2440) --------------------------------------------------------
int TribeInformationAIModule::resourceType(int r, int t)
{
    int v3; // eax@1
    int v4; // edx@1
    int *v5; // ecx@2
    int result; // eax@5

    v3 = 0;
    v4 = this->numberResourceTypesValue[r];
    if ( v4 <= 0 )
    {
        result = 0;
    }
    else
    {
        v5 = this->resourceTypesValue[r];
        while ( *v5 != t )
        {
            ++v3;
            ++v5;
            if ( v3 >= v4 )
                return 0;
        }
        result = 1;
    }
    return result;
}

//----- (004E2490) --------------------------------------------------------
ResourceMemory *TribeInformationAIModule::addResourceObject(RGE_Static_Object *obj)
{
    RGE_Static_Object *v2; // edi@1
    TribeInformationAIModule *v3; // esi@1
    __int16 v4; // ax@1
    signed int v5; // ebx@2
    int v6; // eax@6
    int v7; // eax@9
    ResourceMemory *result; // eax@11
    int v9; // edx@11
    ResourceMemory *v10; // ecx@12
    int v11; // ebp@12
    int v12; // eax@13
    int v13; // edi@13
    char v14; // cl@15
    int v15; // ecx@18
    int v16; // eax@18
    int v17; // ecx@24
    int v18; // ebp@24
    int *v19; // eax@25
    double v20; // st7@28
    int v21; // eax@28
    signed int v22; // ecx@29
    signed __int64 v23; // rax@33
    signed int v24; // ecx@33
    signed __int64 v25; // rax@37
    signed int v26; // ecx@37
    signed __int64 v27; // rax@41
    signed int v28; // ecx@41
    double v29; // st7@45
    int v30; // ebp@45
    int v31; // eax@45
    signed __int64 v32; // rax@46
    signed int v33; // ecx@46
    signed __int64 v34; // rax@50
    signed int v35; // ecx@50
    signed __int64 v36; // rax@54
    signed int v37; // ecx@54
    signed __int64 v38; // rax@58
    signed int v39; // ecx@58
    int newSize; // [sp+10h] [bp-Ch]@9
    ResourceMemory *temp; // [sp+14h] [bp-8h]@11
    int dropsiteID; // [sp+18h] [bp-4h]@28

    v2 = obj;
    v3 = this;
    v4 = obj->master_obj->object_group;
    if ( v4 == 15 )
    {
        v5 = 1;
    }
    else if ( v4 == 8 )
    {
        v5 = 2;
    }
    else
    {
        v5 = v4 != 32 ? 0 : 3;
    }
    v6 = this->maxResources[v5];
    if ( this->numResources[v5] == v6 || !this->resources[v5] )
    {
        if ( v6 )
        {
            newSize = 2 * v6;
            v7 = 2 * v6;
        }
        else
        {
            v7 = 100;
            newSize = 100;
        }
        result = (ResourceMemory *)operator new(20 * v7);
        v9 = (int)result;
        temp = result;
        if ( !result )
            return result;
        v10 = v3->resources[v5];
        v11 = 0;
        if ( v10 )
        {
            v12 = 0;
            v13 = v9 + 5;
            do
            {
                if ( v11 >= v3->maxResources[v5] )
                    break;
                ++v11;
                *(_DWORD *)(v13 - 5) = v10[v12].id;
                v13 += 20;
                v14 = v3->resources[v5][v12].x;
                ++v12;
                *(_BYTE *)(v13 - 21) = v14;
                *(_BYTE *)(v13 - 20) = *((_BYTE *)&v3->resources[v5][v12] - 15);
                *(_BYTE *)(v13 - 19) = *((_BYTE *)&v3->resources[v5][v12] - 14);
                *(_DWORD *)(v13 - 17) = *((_DWORD *)&v3->resources[v5][v12] - 3);
                *(_BYTE *)(v13 - 13) = *((_BYTE *)&v3->resources[v5][v12] - 8);
                *(_BYTE *)(v13 - 12) = *((_BYTE *)&v3->resources[v5][v12] - 7);
                *(_BYTE *)(v13 - 11) = *((_BYTE *)&v3->resources[v5][v12] - 6);
                *(_BYTE *)(v13 - 10) = *((_BYTE *)&v3->resources[v5][v12] - 5);
                *(_DWORD *)(v13 - 9) = *((_DWORD *)&v3->resources[v5][v12] - 1);
                v10 = v3->resources[v5];
            }
            while ( v10 );
            v2 = obj;
        }
        if ( v11 < newSize )
        {
            v15 = newSize - v11;
            v16 = v9 + 20 * v11 + 5;
            do
            {
                *(_DWORD *)(v16 - 5) = -1;
                *(_BYTE *)(v16 - 1) = 0;
                *(_BYTE *)v16 = 0;
                *(_BYTE *)(v16 + 1) = 0;
                *(_DWORD *)(v16 + 3) = 255;
                *(_BYTE *)(v16 + 7) = 0;
                *(_BYTE *)(v16 + 8) = 0;
                *(_BYTE *)(v16 + 9) = -1;
                *(_BYTE *)(v16 + 10) = -1;
                *(_DWORD *)(v16 + 11) = -1;
                v16 += 20;
                --v15;
            }
            while ( v15 );
            v9 = (int)temp;
        }
        if ( v3->resources[v5] )
        {
            operator delete(v3->resources[v5]);
            v9 = (int)temp;
        }
        v3->resources[v5] = (ResourceMemory *)v9;
        v3->maxResources[v5] = newSize;
    }
    v17 = v3->maxResources[v5];
    v18 = 0;
    if ( v17 <= 0 )
    {
LABEL_28:
        v3->resources[v5][v3->numResources[v5]].id = v2->id;
        v3->resources[v5][v3->numResources[v5]].x = (signed __int64)v2->world_x;
        v3->resources[v5][v3->numResources[v5]].y = (signed __int64)v2->world_y;
        v3->resources[v5][v3->numResources[v5]].gatherAttempts = 0;
        v3->resources[v5][v3->numResources[v5]].valid = 0;
        v3->resources[v5][v3->numResources[v5]].gone = 0;
        v3->resources[v5][v3->numResources[v5]].resourceType = v5;
        dropsiteID = -1;
        v20 = TribeInformationAIModule::findClosestDropsite(v3, v2, 1, &dropsiteID);
        v3->resources[v5][v3->numResources[v5]].dropDistance = (signed __int64)v20;
        v3->resources[v5][v3->numResources[v5]].dropsiteID = dropsiteID;
        v3->resources[v5][v3->numResources[v5]++].gatherValue = (signed __int64)(10.0 - v20 * -2.0);
        v21 = v2->master_obj->object_group;
        switch ( v21 )
        {
            case 15:
                v22 = v3->closestDropsiteValue[1];
                if ( (signed int)(signed __int64)v20 < v22 || v22 == -1 )
                {
                    v3->closestDropsiteValue[1] = (signed __int64)v20;
                    v3->closestDropsiteResourceID[1] = v2->id;
                    return (ResourceMemory *)1;
                }
                break;
            case 32:
                v23 = (signed __int64)v20;
                v24 = v3->closestDropsiteValue[3];
                if ( (signed int)(signed __int64)v20 < v24 || v24 == -1 )
                {
                    v3->closestDropsiteValue[3] = v23;
                    v3->closestDropsiteResourceID[3] = v2->id;
                    return (ResourceMemory *)1;
                }
                break;
            case 8:
                v25 = (signed __int64)v20;
                v26 = v3->closestDropsiteValue[2];
                if ( (signed int)(signed __int64)v20 < v26 || v26 == -1 )
                {
                    v3->closestDropsiteValue[2] = v25;
                    v3->closestDropsiteResourceID[2] = v2->id;
                    return (ResourceMemory *)1;
                }
                break;
            case 7:
                v27 = (signed __int64)v20;
                v28 = v3->closestDropsiteValue[0];
                if ( (signed int)(signed __int64)v20 < v28 || v28 == -1 )
                {
                    v3->closestDropsiteValue[0] = v27;
                    v3->closestDropsiteResourceID[0] = v2->id;
                    return (ResourceMemory *)1;
                }
                break;
        }
        return (ResourceMemory *)1;
    }
    v19 = &v3->resources[v5]->id;
    while ( *v19 != v2->id )
    {
        ++v18;
        v19 += 5;
        if ( v18 >= v17 )
            goto LABEL_28;
    }
    obj = (RGE_Static_Object *)-1;
    v29 = TribeInformationAIModule::findClosestDropsite(v3, v2, 1, (int *)&obj);
    v30 = v18;
    v3->resources[v5][v30].gatherValue = (signed __int64)(10.0 - v29 * -2.0);
    v3->resources[v5][v30].dropsiteID = (int)obj;
    v31 = v2->master_obj->object_group;
    if ( v31 == 15 )
    {
        v32 = (signed __int64)v29;
        v33 = v3->closestDropsiteValue[1];
        if ( (signed int)(signed __int64)v29 < v33 || v33 == -1 )
        {
            v3->closestDropsiteValue[1] = v32;
            v3->closestDropsiteResourceID[1] = v3->resources[v5][v30].id;
            return (ResourceMemory *)1;
        }
        return (ResourceMemory *)1;
    }
    if ( v31 == 32 )
    {
        v34 = (signed __int64)v29;
        v35 = v3->closestDropsiteValue[3];
        if ( (signed int)(signed __int64)v29 >= v35 && v35 != -1 )
            return (ResourceMemory *)1;
        v3->closestDropsiteValue[3] = v34;
        result = (ResourceMemory *)1;
        v3->closestDropsiteResourceID[3] = v3->resources[v5][v30].id;
    }
    else if ( v31 == 8 )
    {
        v36 = (signed __int64)v29;
        v37 = v3->closestDropsiteValue[2];
        if ( (signed int)(signed __int64)v29 >= v37 && v37 != -1 )
            return (ResourceMemory *)1;
        v3->closestDropsiteValue[2] = v36;
        result = (ResourceMemory *)1;
        v3->closestDropsiteResourceID[2] = v3->resources[v5][v30].id;
    }
    else
    {
        if ( v31 != 7 )
            return (ResourceMemory *)1;
        v38 = (signed __int64)v29;
        v39 = v3->closestDropsiteValue[0];
        if ( (signed int)(signed __int64)v29 >= v39 && v39 != -1 )
            return (ResourceMemory *)1;
        v3->closestDropsiteValue[0] = v38;
        v3->closestDropsiteResourceID[0] = v3->resources[v5][v30].id;
        result = (ResourceMemory *)1;
    }
    return result;
}

//----- (004E2A00) --------------------------------------------------------
double TribeInformationAIModule::findClosestDropsite(RGE_Static_Object *resourceObj, int countTownCenter, int *dropsiteID)
{
    RGE_Static_Object *v4; // ebp@1
    TribeInformationAIModule *v5; // esi@1
    int v6; // ebx@1
    int v7; // ebp@3
    int *v8; // edi@3
    int i; // eax@4
    RGE_Static_Object *v10; // eax@9
    RGE_Static_Object *v11; // edi@9
    int v12; // ecx@11
    __int16 v13; // ax@14
    __int16 v14; // ax@17
    double v15; // st6@19
    double v16; // st7@19
    float xDiff; // ST20_4@19
    long double v19; // st6@19
    char v20; // c3@19
    char resourceZone; // [sp+Fh] [bp-9h]@1
    float dropDistance; // [sp+10h] [bp-8h]@1

    v4 = resourceObj;
    v5 = this;
    dropDistance = 1000.0;
    resourceZone = RGE_Static_Object::currentZone(resourceObj);
    v6 = 0;
    for ( *dropsiteID = -1; v6 < v5->playerBuildings.numberValue; ++v6 )
    {
        if ( v6 > v5->playerBuildings.maximumSizeValue - 1 )
        {
            v7 = v6 + 1;
            v8 = (int *)operator new(4 * v6 + 4);
            if ( v8 )
            {
                for ( i = 0; i < v5->playerBuildings.maximumSizeValue; v8[i - 1] = v5->playerBuildings.value[i - 1] )
                {
                    if ( i >= v7 )
                        break;
                    ++i;
                }
                operator delete(v5->playerBuildings.value);
                v5->playerBuildings.value = v8;
                v5->playerBuildings.maximumSizeValue = v7;
            }
            v4 = resourceObj;
        }
        v10 = MainDecisionAIModule::object((MainDecisionAIModule *)&v5->md->vfptr, v5->playerBuildings.value[v6]);
        v11 = v10;
        if ( v10
            && RGE_Static_Object::lookupZone(v4, (signed __int64)v10->world_x, (signed __int64)v10->world_y) == resourceZone )
        {
            if ( (v12 = v11->master_obj->id, v12 == 109) && countTownCenter
                || v12 == 103 && (v13 = v4->master_obj->id, v13 != 59) && v13 != 50
                || v12 == 68 && ((v14 = v4->master_obj->id, v14 == 59) || v14 == 50) )
            {
                v15 = v11->world_x - v4->world_x;
                v16 = v11->world_y - v4->world_y;
                xDiff = v15;
                v19 = sqrt(v15 * xDiff + v16 * v16);
                if ( v20 || v19 < dropDistance )
                {
                    dropDistance = v19;
                    *dropsiteID = v11->id;
                }
            }
        }
    }
    return dropDistance;
}

//----- (004E2BA0) --------------------------------------------------------
RGE_Static_Object *TribeInformationAIModule::findClosestReturnDropsite(RGE_Static_Object *unitObj)
{
    RGE_Static_Object *v2; // ebp@1
    TribeInformationAIModule *v3; // esi@1
    int v4; // ebx@1
    int v5; // ebp@3
    int *v6; // edi@3
    int i; // eax@4
    RGE_Static_Object *v8; // eax@9
    RGE_Static_Object *v9; // edi@9
    int v10; // eax@11
    double v11; // st6@16
    double v12; // st7@16
    float xDiff; // ST20_4@16
    long double v14; // st6@16
    char unitZone; // [sp+Fh] [bp-Dh]@1
    RGE_Static_Object *rVal; // [sp+10h] [bp-Ch]@1
    float dropDistance; // [sp+18h] [bp-4h]@1

    v2 = unitObj;
    v3 = this;
    v4 = 0;
    rVal = 0;
    dropDistance = 1000.0;
    for ( unitZone = RGE_Static_Object::currentZone(unitObj); v4 < v3->playerBuildings.numberValue; ++v4 )
    {
        if ( v4 > v3->playerBuildings.maximumSizeValue - 1 )
        {
            v5 = v4 + 1;
            v6 = (int *)operator new(4 * v4 + 4);
            if ( v6 )
            {
                for ( i = 0; i < v3->playerBuildings.maximumSizeValue; v6[i - 1] = v3->playerBuildings.value[i - 1] )
                {
                    if ( i >= v5 )
                        break;
                    ++i;
                }
                operator delete(v3->playerBuildings.value);
                v3->playerBuildings.value = v6;
                v3->playerBuildings.maximumSizeValue = v5;
            }
            v2 = unitObj;
        }
        v8 = MainDecisionAIModule::object((MainDecisionAIModule *)&v3->md->vfptr, v3->playerBuildings.value[v4]);
        v9 = v8;
        if ( v8 && RGE_Static_Object::lookupZone(v2, (signed __int64)v8->world_x, (signed __int64)v8->world_y) == unitZone )
        {
            if ( (v10 = v9->master_obj->id, v10 == 109)
                || v10 == 103 && v2->attribute_type_held != 16
                || v10 == 68 && v2->attribute_type_held == 16 )
            {
                v11 = v9->world_x - v2->world_x;
                v12 = v9->world_y - v2->world_y;
                xDiff = v11;
                v14 = sqrt(v11 * xDiff + v12 * v12);
                if ( !rVal || v14 < dropDistance )
                {
                    dropDistance = v14;
                    rVal = v9;
                }
            }
        }
    }
    return rVal;
}

//----- (004E2D10) --------------------------------------------------------
void TribeInformationAIModule::updateAllResourceDropsites()
{
    TribeInformationAIModule *v1; // esi@1
    char *v2; // ebx@1
    int v3; // ebp@2
    int v4; // eax@2
    RGE_Static_Object *v5; // eax@3
    RGE_Static_Object *v6; // edi@3
    double v7; // st7@4
    int v8; // eax@4
    signed __int64 v9; // rax@5
    signed int v10; // ecx@5
    signed __int64 v11; // rax@9
    signed int v12; // ecx@9
    signed __int64 v13; // rax@13
    signed int v14; // ecx@13
    signed __int64 v15; // rax@17
    signed int v16; // ecx@17
    int v17; // ecx@20
    int dropsiteID; // [sp+10h] [bp-Ch]@4
    int a; // [sp+14h] [bp-8h]@2
    int v20; // [sp+18h] [bp-4h]@1

    v1 = this;
    v20 = 4;
    v2 = (char *)this->resources;
    do
    {
        v3 = 0;
        *((_DWORD *)v2 + 28) = -1;
        *((_DWORD *)v2 + 32) = -1;
        v4 = *((_DWORD *)v2 + 4);
        a = 0;
        if ( v4 > 0 )
        {
            do
            {
                v5 = MainDecisionAIModule::object((MainDecisionAIModule *)&v1->md->vfptr, *(_DWORD *)(*(_DWORD *)v2 + v3));
                v6 = v5;
                if ( v5 )
                {
                    dropsiteID = -1;
                    v7 = TribeInformationAIModule::findClosestDropsite(v1, v5, 1, &dropsiteID);
                    *(_DWORD *)(*(_DWORD *)v2 + v3 + 8) = (signed __int64)(10.0 - v7 * -2.0);
                    *(_BYTE *)(*(_DWORD *)v2 + v3 + 14) = (signed __int64)v7;
                    *(_DWORD *)(*(_DWORD *)v2 + v3 + 16) = dropsiteID;
                    v8 = v6->master_obj->object_group;
                    switch ( v8 )
                    {
                        case 15:
                            v9 = (signed __int64)v7;
                            v10 = v1->closestDropsiteValue[1];
                            if ( (signed int)(signed __int64)v7 < v10 || v10 == -1 )
                            {
                                v1->closestDropsiteValue[1] = v9;
                                v1->closestDropsiteResourceID[1] = v6->id;
                            }
                            break;
                        case 32:
                            v11 = (signed __int64)v7;
                            v12 = v1->closestDropsiteValue[3];
                            if ( (signed int)(signed __int64)v7 < v12 || v12 == -1 )
                            {
                                v1->closestDropsiteValue[3] = v11;
                                v1->closestDropsiteResourceID[3] = v6->id;
                            }
                            break;
                        case 8:
                            v13 = (signed __int64)v7;
                            v14 = v1->closestDropsiteValue[2];
                            if ( (signed int)(signed __int64)v7 < v14 || v14 == -1 )
                            {
                                v1->closestDropsiteValue[2] = v13;
                                v1->closestDropsiteResourceID[2] = v6->id;
                            }
                            break;
                        case 7:
                            v15 = (signed __int64)v7;
                            v16 = v1->closestDropsiteValue[0];
                            if ( (signed int)(signed __int64)v7 < v16 || v16 == -1 )
                            {
                                v1->closestDropsiteValue[0] = v15;
                                v1->closestDropsiteResourceID[0] = v6->id;
                            }
                            break;
                    }
                }
                v17 = *((_DWORD *)v2 + 4);
                v3 += 20;
                ++a;
            }
            while ( a < v17 );
        }
        v2 += 4;
        --v20;
    }
    while ( v20 );
}

//----- (004E2E90) --------------------------------------------------------
void TribeInformationAIModule::updateResourceDropsites(int rType)
{
    int v2; // ebp@1
    TribeInformationAIModule *v3; // esi@1
    int v4; // ebx@1
    int v5; // eax@2
    RGE_Static_Object *v6; // eax@3
    RGE_Static_Object *v7; // edi@3
    double v8; // st7@4
    int v9; // eax@4
    signed __int64 v10; // rax@5
    signed int v11; // ecx@5
    signed __int64 v12; // rax@9
    signed int v13; // ecx@9
    signed __int64 v14; // rax@13
    signed int v15; // ecx@13
    signed __int64 v16; // rax@17
    signed int v17; // ecx@17
    int a; // [sp+Ch] [bp-4h]@1

    v2 = rType;
    v3 = this;
    v4 = 0;
    this->closestDropsiteValue[rType] = -1;
    this->closestDropsiteResourceID[v2] = -1;
    for ( a = 0; a < v3->numResources[v2]; ++a )
    {
        v5 = (int)&v3->resources[v2][v4].id;
        if ( *(_BYTE *)(v5 + 13) != 1 )
        {
            v6 = MainDecisionAIModule::object((MainDecisionAIModule *)&v3->md->vfptr, *(_DWORD *)v5);
            v7 = v6;
            if ( v6 )
            {
                rType = -1;
                v8 = TribeInformationAIModule::findClosestDropsite(v3, v6, 1, &rType);
                v3->resources[v2][v4].gatherValue = (signed __int64)(10.0 - v8 * -2.0);
                v3->resources[v2][v4].dropDistance = (signed __int64)v8;
                v3->resources[v2][v4].dropsiteID = rType;
                v9 = v7->master_obj->object_group;
                switch ( v9 )
                {
                    case 15:
                        v10 = (signed __int64)v8;
                        v11 = v3->closestDropsiteValue[1];
                        if ( (signed int)(signed __int64)v8 < v11 || v11 == -1 )
                        {
                            v3->closestDropsiteValue[1] = v10;
                            v3->closestDropsiteResourceID[1] = v7->id;
                        }
                        break;
                    case 32:
                        v12 = (signed __int64)v8;
                        v13 = v3->closestDropsiteValue[3];
                        if ( (signed int)(signed __int64)v8 < v13 || v13 == -1 )
                        {
                            v3->closestDropsiteValue[3] = v12;
                            v3->closestDropsiteResourceID[3] = v7->id;
                        }
                        break;
                    case 8:
                        v14 = (signed __int64)v8;
                        v15 = v3->closestDropsiteValue[2];
                        if ( (signed int)(signed __int64)v8 < v15 || v15 == -1 )
                        {
                            v3->closestDropsiteValue[2] = v14;
                            v3->closestDropsiteResourceID[2] = v7->id;
                        }
                        break;
                    case 7:
                        v16 = (signed __int64)v8;
                        v17 = v3->closestDropsiteValue[0];
                        if ( (signed int)(signed __int64)v8 < v17 || v17 == -1 )
                        {
                            v3->closestDropsiteValue[0] = v16;
                            v3->closestDropsiteResourceID[0] = v7->id;
                        }
                        break;
                }
            }
        }
        ++v4;
    }
}

//----- (004E3020) --------------------------------------------------------
int TribeInformationAIModule::setResourceObjectValid(int rType, int id, int newValid)
{
    int v4; // eax@1
    int v5; // edx@1
    ResourceMemory *v6; // esi@2
    ResourceMemory *v7; // ecx@2
    int result; // eax@5

    v4 = 0;
    v5 = this->numResources[rType];
    if ( v5 <= 0 )
    {
        result = 0;
    }
    else
    {
        v6 = this->resources[rType];
        v7 = this->resources[rType];
        while ( v7->id != id )
        {
            ++v4;
            ++v7;
            if ( v4 >= v5 )
                return 0;
        }
        v6[v4].valid = newValid;
        result = 1;
    }
    return result;
}

//----- (004E3070) --------------------------------------------------------
int TribeInformationAIModule::numberStoragePits()
{
    TribeInformationAIModule *v1; // esi@1
    int v2; // ebx@1
    int v3; // ebp@3
    int *v4; // edi@3
    int i; // eax@4
    RGE_Static_Object *v6; // eax@8
    int count; // [sp+8h] [bp-4h]@1

    v1 = this;
    v2 = 0;
    for ( count = 0; v2 < v1->playerBuildings.numberValue; ++v2 )
    {
        if ( v2 > v1->playerBuildings.maximumSizeValue - 1 )
        {
            v3 = v2 + 1;
            v4 = (int *)operator new(4 * v2 + 4);
            if ( v4 )
            {
                for ( i = 0; i < v1->playerBuildings.maximumSizeValue; v4[i - 1] = v1->playerBuildings.value[i - 1] )
                {
                    if ( i >= v3 )
                        break;
                    ++i;
                }
                operator delete(v1->playerBuildings.value);
                v1->playerBuildings.value = v4;
                v1->playerBuildings.maximumSizeValue = v3;
            }
        }
        v6 = MainDecisionAIModule::object((MainDecisionAIModule *)&v1->md->vfptr, v1->playerBuildings.value[v2]);
        if ( v6 && v6->master_obj->id == 103 )
            ++count;
    }
    return count;
}

//----- (004E3140) --------------------------------------------------------
int TribeInformationAIModule::numberGranaries()
{
    TribeInformationAIModule *v1; // esi@1
    int v2; // ebx@1
    int v3; // ebp@3
    int *v4; // edi@3
    int i; // eax@4
    RGE_Static_Object *v6; // eax@8
    int count; // [sp+8h] [bp-4h]@1

    v1 = this;
    v2 = 0;
    for ( count = 0; v2 < v1->playerBuildings.numberValue; ++v2 )
    {
        if ( v2 > v1->playerBuildings.maximumSizeValue - 1 )
        {
            v3 = v2 + 1;
            v4 = (int *)operator new(4 * v2 + 4);
            if ( v4 )
            {
                for ( i = 0; i < v1->playerBuildings.maximumSizeValue; v4[i - 1] = v1->playerBuildings.value[i - 1] )
                {
                    if ( i >= v3 )
                        break;
                    ++i;
                }
                operator delete(v1->playerBuildings.value);
                v1->playerBuildings.value = v4;
                v1->playerBuildings.maximumSizeValue = v3;
            }
        }
        v6 = MainDecisionAIModule::object((MainDecisionAIModule *)&v1->md->vfptr, v1->playerBuildings.value[v2]);
        if ( v6 && v6->master_obj->id == 68 )
            ++count;
    }
    return count;
}

//----- (004E3210) --------------------------------------------------------
signed __int64 TribeInformationAIModule::amountForageBushesInXTiles(int x, int y, int distance)
{
    TribeInformationAIModule *v4; // edi@1
    int v5; // ebx@1
    int v6; // ebp@2
    int v7; // eax@3
    RGE_Static_Object *v8; // eax@4
    double v9; // st6@6
    double v10; // st7@6
    float v11; // ST18_4@6
    float count; // [sp+8h] [bp-8h]@1

    v4 = this;
    v5 = 0;
    count = 0.0;
    if ( this->numResources[0] > 0 )
    {
        v6 = 0;
        do
        {
            v7 = (int)&v4->resources[0][v6].id;
            if ( *(_BYTE *)(v7 + 13) != 1 )
            {
                v8 = MainDecisionAIModule::object((MainDecisionAIModule *)&v4->md->vfptr, *(_DWORD *)v7);
                if ( v8 )
                {
                    if ( v8->master_obj->id == 59 )
                    {
                        v9 = v8->world_x - (double)x;
                        v10 = v8->world_y - (double)y;
                        v11 = v9;
                        if ( (signed int)(signed __int64)sqrt(v9 * v11 + v10 * v10) <= distance )
                            count = v8->attribute_amount_held + count;
                    }
                }
            }
            ++v5;
            ++v6;
        }
        while ( v5 < v4->numResources[0] );
    }
    return (signed __int64)count;
}

//----- (004E32C0) --------------------------------------------------------
signed __int64 TribeInformationAIModule::amountResourceTypesInXTiles(int type, int x, int y, int distance)
{
    int v5; // ebp@1
    TribeInformationAIModule *v6; // edi@1
    int v7; // ebx@1
    int v8; // eax@2
    RGE_Static_Object *v9; // eax@3
    double v10; // st6@6
    double v11; // st7@6
    float count; // [sp+Ch] [bp-8h]@1
    int i; // [sp+10h] [bp-4h]@1
    int typea; // [sp+18h] [bp+4h]@6

    v5 = type;
    v6 = this;
    v7 = 0;
    count = 0.0;
    for ( i = 0; i < v6->numResources[v5]; ++i )
    {
        v8 = (int)&v6->resources[v5][v7].id;
        if ( *(_BYTE *)(v8 + 13) != 1 )
        {
            v9 = MainDecisionAIModule::object((MainDecisionAIModule *)&v6->md->vfptr, *(_DWORD *)v8);
            if ( v9 )
            {
                if ( v5 || v9->master_obj->id != 59 )
                {
                    v10 = v9->world_x - (double)x;
                    v11 = v9->world_y - (double)y;
                    *(float *)&typea = v10;
                    if ( (signed int)(signed __int64)sqrt(v10 * *(float *)&typea + v11 * v11) <= distance )
                        count = v9->attribute_amount_held + count;
                }
            }
        }
        ++v7;
    }
    return (signed __int64)count;
}

//----- (004E3390) --------------------------------------------------------
double TribeInformationAIModule::damagePerSecond(int id, int x, int y)
{
    TribeInformationAIModule *v4; // edi@1
    double result; // st7@2
    int v6; // ebx@3
    int v7; // ebp@4
    RGE_Static_Object *v8; // eax@6
    RGE_Static_Object *v9; // esi@6
    float v10; // ST08_4@8
    float v11; // ST04_4@8
    long double v12; // st7@8
    float rateOfFire; // ST24_4@11
    float rVal; // [sp+20h] [bp-Ch]@1
    RGE_Static_Object *unit; // [sp+28h] [bp-4h]@1
    int ida; // [sp+30h] [bp+4h]@9

    v4 = this;
    rVal = 0.0;
    unit = MainDecisionAIModule::object((MainDecisionAIModule *)&this->md->vfptr, id);
    if ( unit )
    {
        v6 = 0;
        if ( v4->maxImportantObjectMemory > 0 )
        {
            v7 = 0;
            do
            {
                if ( (*(int (__stdcall **)(_DWORD))&v4->md->player->vfptr->gap4[20])(v4->importantObjectMemory[v7].owner) )
                {
                    v8 = MainDecisionAIModule::object((MainDecisionAIModule *)&v4->md->vfptr, v4->importantObjectMemory[v7].id);
                    v9 = v8;
                    if ( v8 )
                    {
                        if ( v8->object_state <= 2u )
                        {
                            v10 = (double)y;
                            v11 = (double)x;
                            v12 = RGE_Static_Object::distance_to_position(v8, v11, v10, v8->world_z);
                            if ( v12 <= v9->master_obj->los )
                            {
                                (*((void (__stdcall **)(_DWORD))&unit->vfptr->rateOfFire + 1))(v9);
                                *(float *)&ida = v12;
                                v9->vfptr->rateOfFire(v9);
                                if ( v12 != 0.0 && *(float *)&ida != 0.0 )
                                {
                                    rateOfFire = v12;
                                    rVal = *(float *)&ida / rateOfFire + rVal;
                                }
                            }
                        }
                    }
                }
                ++v6;
                ++v7;
            }
            while ( v6 < v4->maxImportantObjectMemory );
        }
        result = rVal;
    }
    else
    {
        result = 0.0;
    }
    return result;
}

//----- (004E34C0) --------------------------------------------------------
int TribeInformationAIModule::costToLoseUnit(int id)
{
    TribeInformationAIModule *v2; // esi@1
    RGE_Static_Object *v3; // eax@1
    int result; // eax@2

    v2 = this;
    v3 = MainDecisionAIModule::object((MainDecisionAIModule *)&this->md->vfptr, id);
    if ( v3 )
        result = ((int (__stdcall *)(_DWORD))v2->md->player->vfptr->objectCostByType)(v3->master_obj->id);
    else
        result = -1;
    return result;
}

//----- (004E3500) --------------------------------------------------------
int TribeInformationAIModule::benefitToKillUnit(int id)
{
    RGE_Static_Object *v2; // eax@1
    int result; // eax@2

    v2 = MainDecisionAIModule::object((MainDecisionAIModule *)&this->md->vfptr, id);
    if ( v2 )
        result = ((int (__stdcall *)(_DWORD))v2->owner->vfptr->objectCostByType)(v2->master_obj->id);
    else
        result = -1;
    return result;
}

//----- (004E3530) --------------------------------------------------------
int TribeInformationAIModule::inRangeOfUnits(int playerID, int x, int y, int useJustRange)
{
    TribeInformationAIModule *v5; // edi@1
    int v6; // ebp@1
    int v7; // ebx@2
    RGE_Static_Object *v8; // eax@7
    RGE_Static_Object *v9; // esi@7
    float v10; // ST08_4@9
    float v11; // ST04_4@9
    long double v12; // st7@9
    RGE_Master_Static_Object *v13; // esi@10
    int i; // [sp+20h] [bp-4h]@1
    int playerIDa; // [sp+28h] [bp+4h]@9

    v5 = this;
    v6 = 0;
    i = 0;
    if ( this->maxImportantObjectMemory > 0 )
    {
        v7 = playerID;
        while ( 1 )
        {
            if ( v7 == -1 )
                goto LABEL_19;
            if ( v5->importantObjectMemory[v6].owner != v7 )
                goto LABEL_13;
            if ( v7 == -1 )
            {
LABEL_19:
                if ( !(*(int (__stdcall **)(_DWORD))&v5->md->player->vfptr->gap4[20])(v5->importantObjectMemory[v6].owner) )
                    goto LABEL_13;
            }
            v8 = MainDecisionAIModule::object((MainDecisionAIModule *)&v5->md->vfptr, v5->importantObjectMemory[v6].id);
            v9 = v8;
            if ( v8 && v8->object_state <= 2u )
            {
                v10 = (double)y;
                v11 = (double)x;
                v12 = RGE_Static_Object::distance_to_position(v8, v11, v10, v8->world_z);
                *(float *)&playerIDa = v12;
                v9->vfptr->weaponRange(v9);
                if ( !useJustRange )
                {
                    v13 = v9->master_obj;
                    if ( v13->los > (double)*(float *)&playerIDa )
                        v12 = v13->los;
                }
                if ( *(float *)&playerIDa <= v12 )
                    return 1;
            }
LABEL_13:
            ++v6;
            if ( ++i >= v5->maxImportantObjectMemory )
                return 0;
        }
    }
    return 0;
}

//----- (004E3640) --------------------------------------------------------
ObjectMemory *TribeInformationAIModule::wonderToAttack(int playerID)
{
    TribeInformationAIModule *v2; // ebx@1
    int v3; // ebp@1
    int v4; // esi@1
    int v5; // eax@3
    RGE_Static_Object *v6; // eax@8
    RGE_Static_Object *v7; // edi@8
    RGE_Action *v8; // eax@11
    int v9; // ebp@12
    RGE_Action *v10; // eax@12
    int v11; // ecx@27
    bool v12; // sf@27
    unsigned __int8 v13; // of@27
    int v15; // [sp+Ch] [bp-18h]@2
    int bestState; // [sp+10h] [bp-14h]@1
    float bestTimer; // [sp+14h] [bp-10h]@1
    float bestHitpoints; // [sp+1Ch] [bp-8h]@1
    int i; // [sp+20h] [bp-4h]@1

    v2 = this;
    v3 = 0;
    v4 = 0;
    bestState = -1;
    bestTimer = 0.0;
    bestHitpoints = 0.0;
    i = 0;
    if ( this->maxImportantObjectMemory > 0 )
    {
        v15 = 0;
        do
        {
            v5 = (int)&v2->importantObjectMemory->id + v3;
            if ( *(_WORD *)(v5 + 4) == 276 )
            {
                if ( playerID != -1 )
                {
                    if ( *(_BYTE *)(v5 + 11) != playerID )
                        goto LABEL_27;
                    if ( playerID != -1 )
                        goto LABEL_8;
                }
                if ( (*(int (__stdcall **)(_DWORD))&v2->md->player->vfptr->gap4[20])(*(_BYTE *)(v5 + 11)) )
                {
LABEL_8:
                    v6 = MainDecisionAIModule::object(
                                 (MainDecisionAIModule *)&v2->md->vfptr,
                                 *(int *)((char *)&v2->importantObjectMemory->id + v3));
                    v7 = v6;
                    if ( v6 )
                    {
                        if ( v6->object_state <= 2u && RGE_Action_List::have_action((RGE_Action_List *)v6[2].unitAIValue) )
                        {
                            v8 = RGE_Action_List::get_action((RGE_Action_List *)v7[2].unitAIValue);
                            if ( v8->vfptr->type(v8) == 120 )
                            {
                                v9 = RGE_Action_List::get_action((RGE_Action_List *)v7[2].unitAIValue)->state;
                                v10 = RGE_Action_List::get_action((RGE_Action_List *)v7[2].unitAIValue);
                                if ( v4 )
                                {
                                    if ( bestState != 6 || v9 != 2 )
                                    {
                                        if ( bestState != 2 || v9 != 6 )
                                        {
                                            if ( bestState == v9 )
                                            {
                                                if ( bestState != 2 || bestHitpoints >= (double)v7->hp )
                                                {
                                                    if ( bestState == v9 && bestState == 6 && bestTimer > (double)v10->timer )
                                                    {
                                                        bestTimer = v10->timer;
                                                        v4 = (int)&v2->importantObjectMemory[v15].id;
                                                        bestState = v9;
                                                        bestHitpoints = v7->hp;
                                                    }
                                                }
                                                else
                                                {
                                                    v4 = (int)&v2->importantObjectMemory[v15].id;
                                                    bestTimer = v10->timer;
                                                    bestState = v9;
                                                    bestHitpoints = v7->hp;
                                                }
                                            }
                                        }
                                        else
                                        {
                                            v4 = (int)&v2->importantObjectMemory[v15].id;
                                            bestTimer = v10->timer;
                                            bestState = 6;
                                            bestHitpoints = v7->hp;
                                        }
                                    }
                                }
                                else
                                {
                                    bestTimer = v10->timer;
                                    v4 = (int)&v2->importantObjectMemory[v15].id;
                                    bestState = v9;
                                    bestHitpoints = v7->hp;
                                }
                            }
                        }
                    }
                    goto LABEL_27;
                }
            }
LABEL_27:
            v11 = v2->maxImportantObjectMemory;
            v3 = v15 * 36 + 36;
            v13 = __OFSUB__(i + 1, v11);
            v12 = i++ + 1 - v11 < 0;
            ++v15;
        }
        while ( v12 ^ v13 );
    }
    return (ObjectMemory *)v4;
}

//----- (004E3840) --------------------------------------------------------
ObjectMemory *TribeInformationAIModule::ruinToCapture(int playerID)
{
    TribeInformationAIModule *v2; // esi@1
    RGE_Static_Object *v3; // ebx@1
    int v4; // ebp@1
    int v5; // eax@2
    __int16 v6; // cx@2
    int v7; // edi@4
    RGE_Static_Object *v8; // eax@9
    int v9; // edi@11
    int v10; // eax@12
    float z; // ST20_4@12
    float y; // ST1C_4@12
    float x; // ST18_4@12
    ObjectMemory *bestMem; // [sp+20h] [bp-10h]@1
    int bestValue; // [sp+24h] [bp-Ch]@1
    int i; // [sp+28h] [bp-8h]@1

    v2 = this;
    v3 = MainDecisionAIModule::object((MainDecisionAIModule *)&this->md->vfptr, -1, 109, -1, -1, -1, -1, -1, -1, -1, -1);
    v4 = 0;
    bestValue = -1;
    bestMem = 0;
    for ( i = 0; i < v2->maxImportantObjectMemory; ++i )
    {
        v5 = (int)&v2->importantObjectMemory[v4].id;
        v6 = *(_WORD *)(v5 + 4);
        if ( v6 != 158 && v6 != 163 )
            goto LABEL_16;
        v7 = playerID;
        if ( playerID != -1 )
        {
            if ( *(_BYTE *)(v5 + 11) != playerID )
                goto LABEL_16;
            if ( playerID != -1 )
                goto LABEL_9;
        }
        if ( (*(int (__stdcall **)(_DWORD))&v2->md->player->vfptr->gap4[20])(*(_BYTE *)(v5 + 11)) )
        {
            v7 = playerID;
LABEL_9:
            v8 = MainDecisionAIModule::object((MainDecisionAIModule *)&v2->md->vfptr, v2->importantObjectMemory[v4].id);
            if ( v8 && v8->object_state <= 2u )
            {
                v9 = TribeInformationAIModule::numberUnitsWithinXTiles(
                             v2,
                             v7,
                             v2->importantObjectMemory[v4].x,
                             v2->importantObjectMemory[v4].y,
                             5);
                if ( v3 )
                {
                    v10 = (int)&v2->importantObjectMemory[v4].id;
                    z = (double)*(_BYTE *)(v10 + 10);
                    y = (double)*(_BYTE *)(v10 + 9);
                    x = (double)*(_BYTE *)(v10 + 8);
                    v9 *= (unsigned int)(signed __int64)RGE_Static_Object::distance_to_position(v3, x, y, z);
                }
                if ( !bestMem || v9 < bestValue )
                {
                    bestValue = v9;
                    bestMem = &v2->importantObjectMemory[v4];
                }
            }
        }
LABEL_16:
        ++v4;
    }
    return bestMem;
}

//----- (004E39D0) --------------------------------------------------------
ObjectMemory *TribeInformationAIModule::artifactToCapture(int playerID)
{
    TribeInformationAIModule *v2; // esi@1
    int v3; // ebp@1
    int v4; // eax@2
    RGE_Static_Object *v5; // eax@7
    RGE_Static_Object *v6; // edi@7
    int v7; // ebx@9
    int v8; // eax@10
    int v9; // ebx@10
    ObjectMemory *bestMem; // [sp+8h] [bp-18h]@1
    int bestValue; // [sp+Ch] [bp-14h]@1
    int i; // [sp+10h] [bp-10h]@1
    RGE_Visible_Map *vMap; // [sp+14h] [bp-Ch]@1
    int artifactY; // [sp+18h] [bp-8h]@9
    RGE_Static_Object *townCenter; // [sp+1Ch] [bp-4h]@1

    v2 = this;
    townCenter = MainDecisionAIModule::object(
                                 (MainDecisionAIModule *)&this->md->vfptr,
                                 -1,
                                 109,
                                 -1,
                                 -1,
                                 -1,
                                 -1,
                                 -1,
                                 -1,
                                 -1,
                                 -1);
    v3 = 0;
    bestValue = -1;
    bestMem = 0;
    i = 0;
    for ( vMap = v2->md->player->visible; i < v2->maxImportantObjectMemory; ++i )
    {
        v4 = (int)&v2->importantObjectMemory[v3].id;
        if ( *(_WORD *)(v4 + 4) == 159 )
        {
            if ( playerID != -1 )
            {
                if ( *(_BYTE *)(v4 + 11) != playerID )
                    goto LABEL_15;
                if ( playerID != -1 )
                    goto LABEL_7;
            }
            if ( (*(int (__stdcall **)(_DWORD))&v2->md->player->vfptr->gap4[20])(*(_BYTE *)(v4 + 11)) )
            {
LABEL_7:
                v5 = MainDecisionAIModule::object((MainDecisionAIModule *)&v2->md->vfptr, v2->importantObjectMemory[v3].id);
                v6 = v5;
                if ( v5 )
                {
                    if ( v5->object_state <= 2u )
                    {
                        v7 = (signed __int64)v5->world_x;
                        artifactY = (signed __int64)v5->world_y;
                        if ( RGE_Visible_Map::get_visible(vMap, v7, artifactY) )
                        {
                            v2->importantObjectMemory[v3].x = (signed __int64)v6->world_x;
                            v2->importantObjectMemory[v3].y = (signed __int64)v6->world_y;
                            v2->importantObjectMemory[v3].z = (signed __int64)v6->world_z;
                            v8 = TribeInformationAIModule::numberUnitsWithinXTiles(v2, playerID, v7, artifactY, 5);
                            v9 = v8;
                            if ( townCenter )
                                v9 = v8 * (unsigned __int64)(signed __int64)RGE_Static_Object::distance_to_object(townCenter, v6);
                            if ( !bestMem || v9 < bestValue )
                            {
                                bestValue = v9;
                                bestMem = &v2->importantObjectMemory[v3];
                            }
                        }
                    }
                }
                goto LABEL_15;
            }
        }
LABEL_15:
        ++v3;
    }
    return bestMem;
}

//----- (004E3B80) --------------------------------------------------------
int TribeInformationAIModule::resourceTypeToPlaceDropsiteBy(int dropsiteType)
{
    TribeInformationAIModule *v2; // esi@1
    int result; // eax@2
    signed int v4; // eax@13

    v2 = this;
    if ( dropsiteType == 2 )
        return 0;
    if ( !((int (*)(TribeBuildAIModule *, signed int, _DWORD))this->md->buildAI.vfptr[1].toggleLogHistory)(
                    &this->md->buildAI,
                    103,
                    0)
        && v2->closestDropsiteValue[1] != -1 )
    {
        return 1;
    }
    if ( dropsiteType != 1 )
        goto LABEL_22;
    if ( v2->closestDropsiteValue[1] != -1
        && v2->closestDropsiteValue[1] > TribeTacticalAIModule::strategicNumber(&v2->md->tacticalAI, 164) )
    {
        return 1;
    }
    if ( v2->closestDropsiteValue[3] != -1
        && v2->closestDropsiteValue[3] > TribeTacticalAIModule::strategicNumber(&v2->md->tacticalAI, 166) )
    {
        return 3;
    }
    v4 = v2->closestDropsiteValue[0];
    if ( v4 != -1 && v4 > 15 )
        return 2;
    if ( v2->closestDropsiteValue[2] == -1
        || v2->closestDropsiteValue[2] <= TribeTacticalAIModule::strategicNumber(&v2->md->tacticalAI, 165) )
    {
LABEL_22:
        result = -1;
    }
    else
    {
        result = 2;
    }
    return result;
}

//----- (004E3C90) --------------------------------------------------------
int TribeInformationAIModule::dropsitesWithinRequiredDistance(int *numDS, int rType, int maxDistance)
{
    int v4; // edi@1
    TribeInformationAIModule *v5; // ebx@1
    char *v6; // eax@1
    int v7; // esi@1
    int v8; // ebp@2
    int v9; // eax@3
    int v10; // edx@5
    int v11; // eax@6
    char *v12; // ecx@7
    int v13; // edx@11
    int v14; // eax@11
    char *v15; // ecx@12
    int v16; // ebp@12
    char *v17; // esi@19
    int v18; // ecx@20
    char *v19; // eax@21
    int v20; // ecx@27
    bool v21; // sf@27
    unsigned __int8 v22; // of@27
    int result; // eax@32
    int v24; // [sp+10h] [bp-30h]@2
    int numApplicableResources; // [sp+14h] [bp-2Ch]@1
    TribeInformationAIModule *v26; // [sp+18h] [bp-28h]@1
    int v27; // [sp+1Ch] [bp-24h]@11
    int a; // [sp+20h] [bp-20h]@1
    char *dropsites; // [sp+24h] [bp-1Ch]@1
    int dropsites_12; // [sp+30h] [bp-10h]@1

    v4 = 0;
    *numDS = 0;
    v5 = this;
    v6 = 0;
    v26 = this;
    numApplicableResources = 0;
    dropsites = 0;
    dropsites_12 = 0;
    v7 = rType;
    a = 0;
    if ( this->numResources[rType] > 0 )
    {
        v8 = 0;
        v24 = 0;
        do
        {
            v9 = (int)&v5->resources[v7]->id + v8;
            if ( *(_BYTE *)(v9 + 13) != 1 )
            {
                if ( MainDecisionAIModule::object((MainDecisionAIModule *)&v5->md->vfptr, *(_DWORD *)v9) )
                {
                    ++numApplicableResources;
                    v10 = (int)&v5->resources[v7]->id + v8;
                    if ( *(_BYTE *)(v10 + 14) <= maxDistance )
                    {
                        v11 = 0;
                        if ( v4 > 0 )
                        {
                            v12 = dropsites;
                            do
                            {
                                if ( v11 >= dropsites_12 )
                                    break;
                                if ( *(_DWORD *)v12 == *(_DWORD *)(v10 + 16) )
                                    goto LABEL_27;
                                ++v11;
                                v12 += 4;
                            }
                            while ( v11 < v4 );
                        }
                        ++*numDS;
                        v13 = v5->resources[v7][v24].dropsiteID;
                        v14 = 0;
                        v27 = v5->resources[v7][v24].dropsiteID;
                        if ( v4 <= 0 )
                        {
                            v16 = dropsites_12;
                        }
                        else
                        {
                            v15 = dropsites;
                            v16 = dropsites_12;
                            do
                            {
                                if ( v14 >= dropsites_12 )
                                    break;
                                if ( *(_DWORD *)v15 == v13 )
                                    goto LABEL_27;
                                ++v14;
                                v15 += 4;
                            }
                            while ( v14 < v4 );
                        }
                        if ( v4 > v16 - 1 )
                        {
                            v17 = (char *)operator new(4 * (v4 + 1));
                            if ( v17 )
                            {
                                v18 = 0;
                                if ( dropsites_12 > 0 )
                                {
                                    v19 = v17;
                                    do
                                    {
                                        if ( v18 >= v4 + 1 )
                                            break;
                                        ++v18;
                                        *(_DWORD *)v19 = *(_DWORD *)&v19[dropsites - v17];
                                        v19 += 4;
                                        v5 = v26;
                                    }
                                    while ( v18 < dropsites_12 );
                                }
                                operator delete(dropsites);
                                dropsites = v17;
                                dropsites_12 = v4 + 1;
                            }
                            v13 = v27;
                            v7 = rType;
                        }
                        *(_DWORD *)&dropsites[4 * ++v4 - 4] = v13;
                    }
                }
            }
LABEL_27:
            v20 = v5->numResources[v7];
            v8 = v24 * 20 + 20;
            v22 = __OFSUB__(a + 1, v20);
            v21 = a++ + 1 - v20 < 0;
            ++v24;
        }
        while ( v21 ^ v22 );
        v6 = dropsites;
    }
    if ( numApplicableResources <= 0 )
    {
        if ( v6 )
            operator delete(v6);
        result = 0;
    }
    else
    {
        if ( v6 )
            operator delete(v6);
        result = 1;
    }
    return result;
}

//----- (004E3E90) --------------------------------------------------------
int TribeInformationAIModule::numberAvailableStoragePits(int rType)
{
    TribeInformationAIModule *v2; // edi@1
    TribeMainDecisionAIModule *v3; // esi@1
    signed int v4; // eax@1
    int v5; // ebp@5
    RGE_Static_Object *v7; // ebx@7
    RGE_Static_Object *v8; // esi@8
    int v9; // ebp@9

    v2 = this;
    v3 = this->md;
    v4 = (unsigned __int64)(signed __int64)v3->player->attributes[6] - 1;
    if ( v4 >= 0 )
    {
        if ( v4 > 3 )
            v4 = 3;
    }
    else
    {
        v4 = 0;
    }
    v5 = rType;
    if ( !*((_DWORD *)&this->vfptr + v4 + 4 * rType + 320) )
        return 0;
    v7 = MainDecisionAIModule::object((MainDecisionAIModule *)&v3->vfptr, -1, 109, -1, -1, -1, -1, -1, -1, -1, -1);
    if ( v7 )
    {
        v8 = MainDecisionAIModule::object((MainDecisionAIModule *)&v2->md->vfptr, v2->closestDropsiteResourceID[rType]);
        if ( v8 )
        {
            v9 = (unsigned __int8)RGE_Static_Object::currentZone(v7);
            if ( v9 != (unsigned __int8)RGE_Static_Object::lookupZone(
                                                                        v7,
                                                                        (signed __int64)v8->world_x,
                                                                        (signed __int64)v8->world_y) )
                return 0;
            v5 = rType;
        }
    }
    return v2->closestDropsiteValue[v5] > TribeTacticalAIModule::strategicNumber(&v2->md->tacticalAI, v5 + 163);
}

//----- (004E3F80) --------------------------------------------------------
int TribeInformationAIModule::numberAvailableGranaries()
{
    TribeInformationAIModule *v1; // ebx@1
    int result; // eax@2
    RGE_Static_Object *v3; // esi@3
    RGE_Static_Object *v4; // edi@4
    int v5; // ebp@5

    v1 = this;
    if ( this->closestDropsiteValue[0] == -1 )
    {
        result = 0;
    }
    else
    {
        v3 = MainDecisionAIModule::object((MainDecisionAIModule *)&this->md->vfptr, -1, 109, -1, -1, -1, -1, -1, -1, -1, -1);
        if ( v3
            && (v4 = MainDecisionAIModule::object((MainDecisionAIModule *)&v1->md->vfptr, v1->closestDropsiteResourceID[0])) != 0
            && (v5 = (unsigned __int8)RGE_Static_Object::currentZone(v3),
                    v5 != (unsigned __int8)RGE_Static_Object::lookupZone(
                                                                     v3,
                                                                     (signed __int64)v4->world_x,
                                                                     (signed __int64)v4->world_y)) )
        {
            result = 0;
        }
        else
        {
            result = TribeTacticalAIModule::strategicNumber(&v1->md->tacticalAI, 163) < v1->closestDropsiteValue[0];
        }
    }
    return result;
}

//----- (004E4040) --------------------------------------------------------
void __usercall TribeInformationAIModule::lookAtMap(TribeInformationAIModule *this@<ecx>, double a2@<st0>)
{
    TribeInformationAIModule *v2; // edi@1
    signed int v3; // esi@3
    int v4; // ebp@3
    signed int v5; // ebx@4
    signed int v6; // ecx@5
    RGE_Object_Node *v7; // esi@7
    RGE_Static_Object *v8; // ebx@8
    int v9; // ebp@8
    int v10; // ecx@21
    bool v11; // sf@21
    unsigned __int8 v12; // of@21
    int v13; // [sp+4h] [bp-20h]@2
    int numberTreesOnTile; // [sp+8h] [bp-1Ch]@7
    int x; // [sp+Ch] [bp-18h]@1
    signed int v16; // [sp+10h] [bp-14h]@2
    RGE_Map *gMap; // [sp+14h] [bp-10h]@1
    int y; // [sp+18h] [bp-Ch]@3
    signed int v19; // [sp+1Ch] [bp-8h]@4
    int tileType; // [sp+20h] [bp-4h]@5

    v2 = this;
    gMap = this->md->player->world->map;
    x = 0;
    if ( this->mapXSizeValue > 0 )
    {
        v16 = 0;
        v13 = 0;
        do
        {
            v3 = v2->mapYSizeValue;
            v4 = 0;
            y = 0;
            if ( v3 > 0 )
            {
                v5 = 0;
                v19 = 0;
                do
                {
                    v6 = v2->mapXSizeValue;
                    tileType = *((_BYTE *)&(*(RGE_Tile **)((char *)gMap->map_row_offset + v5))[v13] + 5) & 0x1F;
                    if ( v6 != -1 )
                        ++*((_DWORD *)&v2->vfptr + 3 * (v5 / v3 + 4 * (v16 / v6) + 86));
                    InfluenceMap::setValue(&v2->pathMap, x, v4, 0);
                    numberTreesOnTile = 0;
                    v7 = (*(RGE_Tile **)((char *)gMap->map_row_offset + v5))[v13].objects.list;
                    if ( v7 )
                    {
                        do
                        {
                            v8 = v7->node;
                            v9 = v7->node->master_obj->object_group;
                            if ( TribeInformationAIModule::importantObject(v9) == 1 )
                                TribeInformationAIModule::addImportantObject(v2, a2, v8, 0);
                            if ( v9 == 15 )
                                ++numberTreesOnTile;
                            v7 = v7->next;
                        }
                        while ( v7 );
                        v5 = v19;
                        v4 = y;
                    }
                    if ( numberTreesOnTile > 0 && (tileType == 10 || tileType == 19 || tileType == 13 || tileType == 20) )
                        ++v2->numberFoundForestTilesValue;
                    v3 = v2->mapYSizeValue;
                    ++v4;
                    v5 += 4;
                    y = v4;
                    v19 = v5;
                }
                while ( v4 < v3 );
            }
            v10 = v2->mapXSizeValue;
            v12 = __OFSUB__(x + 1, v10);
            v11 = x++ + 1 - v10 < 0;
            ++v13;
            v16 += 4;
        }
        while ( v11 ^ v12 );
    }
}

//----- (004E41C0) --------------------------------------------------------
double TribeInformationAIModule::damageInflictedPerSecond@<st0>(TribeInformationAIModule *this@<ecx>, double a2@<st0>, TacticalAIGroup *group, RGE_Static_Object *obj)
{
    TacticalAIGroup *v4; // ebx@1
    TribeInformationAIModule *v5; // ebp@1
    int i; // edi@1
    int v7; // eax@2
    RGE_Static_Object *v8; // eax@2
    RGE_Static_Object *v9; // esi@2
    float rVal; // [sp+Ch] [bp-4h]@1
    TacticalAIGroup *groupa; // [sp+14h] [bp+4h]@3

    v4 = group;
    v5 = this;
    rVal = 0.0;
    for ( i = 0; i < TacticalAIGroup::numberUnits(v4); ++i )
    {
        v7 = TacticalAIGroup::unit(v4, i);
        v8 = MainDecisionAIModule::object((MainDecisionAIModule *)&v5->md->vfptr, v7);
        v9 = v8;
        if ( v8 )
        {
            (*((void (__stdcall **)(_DWORD))&obj->vfptr->rateOfFire + 1))(v8);
            *(float *)&groupa = a2;
            v9->vfptr->rateOfFire(v9);
            a2 = *(float *)&groupa / a2 + rVal;
            rVal = a2;
        }
    }
    return rVal;
}

//----- (004E4240) --------------------------------------------------------
double TribeInformationAIModule::damageInflictedPerSecond@<st0>(TribeInformationAIModule *this@<ecx>, double a2@<st0>, int *group, int groupSize, RGE_Static_Object *obj)
{
    TribeInformationAIModule *v5; // ebx@1
    int *v6; // edi@2
    int v7; // ebp@2
    RGE_Static_Object *v8; // eax@3
    RGE_Static_Object *v9; // esi@3
    float rVal; // [sp+4h] [bp-4h]@1
    int groupSizea; // [sp+10h] [bp+8h]@4

    v5 = this;
    rVal = 0.0;
    if ( groupSize > 0 )
    {
        v6 = group;
        v7 = groupSize;
        do
        {
            v8 = MainDecisionAIModule::object((MainDecisionAIModule *)&v5->md->vfptr, *v6);
            v9 = v8;
            if ( v8 )
            {
                (*((void (__stdcall **)(_DWORD))&obj->vfptr->rateOfFire + 1))(v8);
                *(float *)&groupSizea = a2;
                v9->vfptr->rateOfFire(v9);
                a2 = *(float *)&groupSizea / a2 + rVal;
                rVal = a2;
            }
            ++v6;
            --v7;
        }
        while ( v7 );
    }
    return rVal;
}

//----- (004E42B0) --------------------------------------------------------
double TribeInformationAIModule::timeToBeKilled(TacticalAIGroup *group, RGE_Static_Object *obj)
{
    TribeInformationAIModule *v3; // ebp@1
    int i; // esi@1
    int v5; // eax@2
    RGE_Static_Object *v6; // ebx@2
    int v7; // ST08_4@3
    int v8; // ST04_4@3
    int v9; // eax@3
    double v10; // st7@3
    double v11; // st7@4
    float rVal; // [sp+Ch] [bp-4h]@1

    v3 = this;
    rVal = 0.0;
    for ( i = 0; i < TacticalAIGroup::numberUnits(group); ++i )
    {
        v5 = TacticalAIGroup::unit(group, i);
        v6 = MainDecisionAIModule::object((MainDecisionAIModule *)&v3->md->vfptr, v5);
        if ( v6 )
        {
            v7 = (signed __int64)obj->world_y;
            v8 = (signed __int64)obj->world_x;
            v9 = TacticalAIGroup::unit(group, i);
            v10 = TribeInformationAIModule::damagePerSecond(v3, v9, v8, v7);
            if ( v10 == 0.0 )
                v11 = 600.0;
            else
                v11 = v6->hp / v10;
            rVal = v11 + rVal;
        }
    }
    return rVal;
}

//----- (004E4350) --------------------------------------------------------
double TribeInformationAIModule::timeToBeKilled(int *group, int groupSize, RGE_Static_Object *obj)
{
    TribeInformationAIModule *v4; // ebx@1
    int *v5; // esi@2
    RGE_Static_Object *v6; // edi@3
    double v7; // st7@4
    double v8; // st7@5
    float rVal; // [sp+4h] [bp-4h]@1

    v4 = this;
    rVal = 0.0;
    if ( groupSize > 0 )
    {
        v5 = group;
        do
        {
            v6 = MainDecisionAIModule::object((MainDecisionAIModule *)&v4->md->vfptr, *v5);
            if ( v6 )
            {
                v7 = TribeInformationAIModule::damagePerSecond(
                             v4,
                             *v5,
                             (signed __int64)obj->world_x,
                             (signed __int64)obj->world_y);
                if ( v7 == 0.0 )
                    v8 = 600.0;
                else
                    v8 = v6->hp / v7;
                rVal = v8 + rVal;
            }
            ++v5;
            --groupSize;
        }
        while ( groupSize );
    }
    return rVal;
}

//----- (004E43E0) --------------------------------------------------------
int TribeInformationAIModule::closestDropsiteResID(int rType)
{
    int result; // eax@3

    if ( rType < 0 || rType > 3 )
        result = -1;
    else
        result = this->closestDropsiteResourceID[rType];
    return result;
}

//----- (004E4400) --------------------------------------------------------
int TribeInformationAIModule::calculatePlayVariation(int playID)
{
    signed int v2; // eax@1
    char *v3; // edx@1
    signed int v4; // esi@1
    int v5; // edi@2

    v2 = 0;
    v3 = (char *)this->playHistory;
    v4 = 16000;
    do
    {
        v5 = *(_DWORD *)v3;
        v3 += 4;
        v2 += v5;
        --v4;
    }
    while ( v4 );
    return 100 - (unsigned __int64)(signed __int64)((double)this->unitHistory[0] / (double)v2 * 100.0);
}

//----- (004E4450) --------------------------------------------------------
int __stdcall TribeInformationAIModule::convertUnitToIntType(RGE_Static_Object *obj)
{
    RGE_Master_Static_Object *v2; // ecx@1
    int v3; // eax@1
    int v4; // ecx@1
    int result; // eax@2
    int v6; // eax@22

    v2 = obj->master_obj;
    v3 = v2->object_group;
    v4 = v2->id;
    switch ( v3 )
    {
        case 18:
            result = 5;
            break;
        case 28:
            result = 3;
            break;
        case 13:
            result = 4;
            break;
        case 12:
            result = 2;
            break;
        case 35:
            result = 7;
            break;
        default:
            switch ( v4 )
            {
                case 73:
                    result = 0;
                    break;
                case 75:
                    result = 1;
                    break;
                case 4:
                case 5:
                case 39:
                    result = 6;
                    break;
                case 41:
                    result = 10;
                    break;
                case 46:
                case 25:
                    result = 9;
                    break;
                default:
                    v6 = -(v3 != 22);
                    LOBYTE(v6) = v6 & 0xF7;
                    result = v6 + 8;
                    break;
            }
            break;
    }
    return result;
}

//----- (004E4500) --------------------------------------------------------
void __usercall TribeInformationAIModule::loadUnitHistory(TribeInformationAIModule *this@<ecx>, int a2@<ebp>, int a3@<edi>)
{
    TribeInformationAIModule *v3; // ebx@1
    RGE_Game_Info *v4; // ecx@1
    RGE_Person_Info *v5; // eax@2
    unsigned int v6; // ecx@3
    char v7; // al@3
    char *v8; // edi@3
    char *v9; // esi@3
    int v10; // ecx@3
    int v11; // eax@4
    int v12; // esi@4
    char historyFileName[256]; // [sp+Ch] [bp-100h]@2

    v3 = this;
    v4 = rge_base_game->player_game_info;
    if ( v4 )
    {
        v5 = RGE_Game_Info::get_current_player_name(v4);
        sprintf(historyFileName, aLearnS_uh, v5);
    }
    else
    {
        v6 = strlen(aLearnDefault_u) + 1;
        v7 = v6;
        v6 >>= 2;
        qmemcpy(historyFileName, aLearnDefault_u, 4 * v6);
        v9 = &aLearnDefault_u[4 * v6];
        v8 = &historyFileName[4 * v6];
        v10 = v7 & 3;
        qmemcpy(v8, v9, v10);
        a3 = (int)&v8[v10];
    }
    v11 = rge_open(historyFileName, 0x8000);
    v12 = v11;
    if ( v11 != -1 )
    {
        rge_read(a2, a3, v11, v3->unitHistory, 44);
        rge_close(v12);
    }
}

//----- (004E45A0) --------------------------------------------------------
void TribeInformationAIModule::unitsThatAreMostBuilt(int *rVal1, int *rVal2)
{
    char *v3; // edi@1
    signed int v4; // edx@1
    int v5; // eax@1
    char *v6; // ecx@1
    signed int v7; // edx@6
    int v8; // eax@6
    signed int *v9; // ecx@6

    v3 = (char *)this->unitHistory;
    v4 = -1;
    *rVal1 = -1;
    v5 = 0;
    v6 = (char *)this->unitHistory;
    do
    {
        if ( v4 == -1 || v4 < *(_DWORD *)v6 )
        {
            *rVal1 = v5;
            v4 = *(_DWORD *)v6;
        }
        ++v5;
        v6 += 4;
    }
    while ( v5 < 11 );
    v7 = -1;
    v8 = 0;
    v9 = (signed int *)v3;
    *rVal2 = -1;
    do
    {
        if ( v8 != *rVal1 && (v7 == -1 || v7 < *v9) )
        {
            *rVal2 = v8;
            v7 = *v9;
        }
        ++v8;
        ++v9;
    }
    while ( v8 < 11 );
}

//----- (004E4610) --------------------------------------------------------
void TribeInformationAIModule::unitsThatAreLeastBuilt(int *rVal1, int *rVal2)
{
    char *v3; // edi@1
    signed int v4; // edx@1
    int v5; // eax@1
    char *v6; // ecx@1
    signed int v7; // edx@6
    int v8; // eax@6
    signed int *v9; // ecx@6

    v3 = (char *)this->unitHistory;
    v4 = -1;
    *rVal1 = 0x7FFFFFFF;
    v5 = 0;
    v6 = (char *)this->unitHistory;
    do
    {
        if ( v4 == -1 || v4 > *(_DWORD *)v6 )
        {
            *rVal1 = v5;
            v4 = *(_DWORD *)v6;
        }
        ++v5;
        v6 += 4;
    }
    while ( v5 < 11 );
    v7 = -1;
    v8 = 0;
    v9 = (signed int *)v3;
    *rVal2 = 0x7FFFFFFF;
    do
    {
        if ( v8 != *rVal1 && (v7 == -1 || v7 > *v9) )
        {
            *rVal2 = v8;
            v7 = *v9;
        }
        ++v8;
        ++v9;
    }
    while ( v8 < 11 );
}

//----- (004E4680) --------------------------------------------------------
int TribeInformationAIModule::acceptablePotentialDropsiteArea(int x, int y)
{
    TribeInformationAIModule *v3; // esi@1
    int v4; // ebp@1
    int v5; // ebp@1
    int v6; // edi@1
    int v7; // ecx@3
    __int16 v8; // ax@3
    int result; // eax@11
    int i; // [sp+10h] [bp-4h]@1

    v3 = this;
    v4 = TribeTacticalAIModule::strategicNumber(&this->md->tacticalAI, 202);
    v5 = TribeTacticalAIModule::strategicNumber(&v3->md->tacticalAI, 202) * v4;
    v6 = 0;
    i = 0;
    if ( v3->maxImportantObjectMemory <= 0 )
    {
        result = 1;
    }
    else
    {
        while ( 1 )
        {
            if ( (*(int (__stdcall **)(_DWORD))&v3->md->player->vfptr->gap4[20])(v3->importantObjectMemory[v6].owner) )
            {
                v7 = (int)&v3->importantObjectMemory[v6].id;
                v8 = *(_WORD *)(v7 + 4);
                if ( (v8 == 109 || v8 == 103 || v8 == 68 || v8 == 79 || v8 == 199 || v8 == 69)
                    && (*(_BYTE *)(v7 + 9) - y) * (*(_BYTE *)(v7 + 9) - y) + (*(_BYTE *)(v7 + 8) - x) * (*(_BYTE *)(v7 + 8) - x) <= v5 )
                {
                    break;
                }
            }
            ++v6;
            if ( ++i >= v3->maxImportantObjectMemory )
                return 1;
        }
        result = 0;
    }
    return result;
}

//----- (004E4790) --------------------------------------------------------
int TribeInformationAIModule::percentTilesExploredInPositionQuadrant(int x, int y)
{
    int v3; // esi@1
    int result; // eax@2

    v3 = this->mapXSizeValue;
    if ( v3 == -1 )
        result = 0;
    else
        result = 100
                     * *((_DWORD *)&this->vfptr + 3 * (4 * y / this->mapYSizeValue + 4 * (4 * x / v3) + 86))
                     / (this->mapYSizeValue
                        * (v3
                         / 4)
                        / 4);
    return result;
}

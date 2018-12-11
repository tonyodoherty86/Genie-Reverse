#pragma once

/**
 * @file    Engine\Fractal.hpp
 * @author  Yvan Burrie
 * @date    2018/06/26
 * @version 1.0
 */

struct PrimaryPt
{
    int x, y;
};

struct PtToPt
{
    int x, y;
};

class PointMaker
{
public:

    PrimaryPt Prime;

    PtToPt Point[500];

    char *Mask_2x2,
         *Mask_3x3,
         *Mask_4x4,
         *Mask_5x5;

    int x, y;

    int NumSplitsPerBranch;
    int NumberOfSatellites;
    int ChanceOfNextNode;
    int MaxNumberOfBranches;
    int MaxBranchFlag;

    int Width,
        Height;

    int MinimumNumTiles;
    int NumNodes;
    int NumTilesActuallyChosen;
    int CurrentPoint;
    int ProbabilityTiles;
    int TargetProbabilityCount;
    int ProbabilityAdd;
    int BranchRadius;
    int SatelliteRadius;
    int PrimaryRadius;
    int SizeArrays;
    int SatelliteDistance;
    int BranchDistance;

    int DirX,
        DirY;

    int MaxNumberOfBranchLevels;
    int CurrentNumberOfBranchLevels;
    char *ExternalArray;
    char *ProbArray;
    char *PlacementArray;
    char *WritableExternalArray;
    int DoNotDrawOnFlag;
    int DrawOnOnlyFlag;
    int DrawOnlyInExternalArrayFlag;
    int DrawToOneArrayFlag;
    int BorderDepthPercentage;

    int LeftLimit,
        RightLimit,
        TopLimit,
        BottomLimit;

    char SpecialLandType;

    PointMaker();

    ~PointMaker();

    void CreateMasks();
    void DeleteMasks();
    void DrawMask(int x, int y, int size);
    void ClearArrays();
    void DeleteArrays();
    void MakeArrays();
    int CreateShape();
    int CreateShape(int xt, int yt);
    void Branch(const int which);
    int MakeFirstLink();
    int MakeNewLink();
    int MakeSatelliteLink();
    void DrawPrimaryIntoProbabilityArray();
    void DrawCurrentBranchIntoProbArray(int which);
    void DrawCurrentSatelliteIntoProbArray(int which);
    void AddingRect(int x1, int y1, int x2, int y2);
    void AddingCircle(int x1, int y1, int radius);
    void CreateMapBasedOnProbabilityArray();
    void SetDefaultValues();
    void SetPoint(int x1, int y1);
    void SetMaxNumberOfBranches(int num);
    void SetChanceOfNextNode(int num);
    void SetNumberOfSatellites(int num);
    void SetSplitsPerBranch(int num);
    void SetWidthAndHeight(int w, int h);
    void SetStartPositionRadius(int num);
    void SetBranchsRadius(int num);
    void SetSatelliteRadius(int num);
    void SetMaxNumberOfBranchLevels(int num);
    void SetSatelliteDistance(int num);
    void SetBranchDistance(int num);
    void SetMinimumNumberOfTiles(int num);
    void SetDrawToOneArray();
    void SetBorderDepthPercentage(int num);
    char *RetrieveMap();
    char *RetrieveProbMap();
    void ErrorCheckingAndCorrection();
    void PrepareLimits();
    void MapCleanUpEliminatingSinglesOnly();
};

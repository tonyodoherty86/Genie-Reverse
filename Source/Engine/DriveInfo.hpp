#pragma once

/**
 * @file    Engine\DriveInfo.hpp
 * @author  Yvan Burrie
 * @date    2018/06/29
 * @version 1.0
 */

class DriveInformation
{
public:

    int initialDriveValue;
    char initialDirectoryValue[256];
    int currentDriveValue;
    char currentDirectoryValue[256];
    int driveValues[27];

    DriveInformation();

    int initialDrive();
    int initialDriveAsLetter();
    char *initialDirectory();

    int currentDrive();
    int currentDriveAsLetter();
    char *currentDirectory();

    int numberDrives();

    int validDrive(int v);

    void checkDrives();

    int numberOfFilesWithFilename(char *n);
    int numberOfFilesWithAttribute(int a);
    int numberOfFilesWithFilenameOrAttribute(char *n, int a);

    int resetCurrentDriveAndDirectory();
    int resetCurrentDrive();
    int resetCurrentDirectory();

    int changeDrive(int d);
    int changeDirectory(char *d);

    void updateDirectory();
};

# Genie-Reverse
*The reverse engineering of the Genie-Engine.*

## Introduction
Reversing the Genie-Engine involves:
 * Daunting research with timely analysis, by observing huge amounts of pseudocode.
 * Renaming vast amounts of procedures, identifying variables, and eliminating libraries.
 * Mapping memory allocated structures, and backtracing entire programming interfaces.
 * Performing trial-error testing, and verifying whether properties match playability.

## Acknowledgements
Many individuals across communities over the past years have been involved in reversing the Genie-Engine.
This particular repository contains the involvements of the following individuals:
 * **Yvan Burrie** *Author of Genie-Studio, researched the scenario format and other structures.*
 * **JustTesting1234** *Special thanks to him for researching; the database, scenario triggers, and many other structures.*
 * **[Piruzzolo](https://github.com/Piruzzolo)**.

## Glance
The Genie-Engine is reasonably well architectured:
 * It holds various database files (DAT) to load all data corresponding to the scheme of the game.
 * It uses external files, mostly organized in file-mapping (DRS) storage, allowing customized modifications.
However, the Genie-Engine obtained certain issues:
 * The engine contains certain bugs left out.
 * The engine contains hard-coded data converged to the database, for example:
    * Fixed number of terrains and borders.
    * Many IDs of structures related to the database are left embeded.

## History
 * The *Genie Engine* began in early 1995 by *Ensemble Studios* using their prototype *Dawn of Man*.
 * By early 1996, the engine was fully working with 10,000 lines of ASM coding, using the *Tribe* protoype.
 * By early 1997, the engine was nicely refined, and the *Age of Empires* prototype was finally used.
 * In 2001, *Lucas Art* licensed the engine for *Star Wars Gallactic Battlegrounds*.

## Engines Analyzed
The following prototypes (ticked) have been decompiled:
 - [x] Age of Empires, 1.0 (Alpha 1). *00.04.03.0113 (??/01/1997).*
 - [x] Age of Empires, 1.0 (Alpha 2). *00.04.04.0125 (??/01/1997).*
 - [x] Age of Empires, 1.0 (Alpha 3). *00.04.05.0130 (??/01/1997).*
 - [x] Age of Empires, 1.0 (Alpha 4). *00.04.05.0202 (??/02/1997).*
 - [x] Age of Empires, 1.0 (Alpha 5). *00.05.01.0203 (??/02/1997).*
 - [x] Age of Empires, 1.0 (Alpha 6). *00.05.01.0204 (??/02/1997).*
 - [ ] Age of Empires, 1.0 (Beta 1). *00.07.14.0604 (04/06/1997).*
 - [ ] Age of Empires, 1.0 (Beta 2). *00.08.04.0703 (03/07/1997).*
 - [x] Age of Empires, 1.0 (Official Beta). *00.08.09.0716 (16/07/1997).*
 - [ ] Age of Empires, 1.0 (Trial CGWM). *00.08.29.0811 (1997/08/11).*
 - [x] Age of Empires, 1.0 (Retail). *00.08.68.0917 (17/09/1997).*
 - [x] Age of Empires, 1.0 (Trial). *00.08.69.0922 (22/09/1997).*
 - [x] Age of Empires, 1.0a (Retail). *00.09.12.1215 (03/12/1997).*
 - [x] Age of Empires, 1.0b (Retail). *00.09.13.0409 (23/04/1998).*
 - [x] Age of Empires, 1.0c (Retail). *00.09.13.1115 (01/12/1999).*
 - [ ] Rise of Rome, 1.0 (Alpha). *00.02.02.0703 (03/07/1998).*
 - [x] Rise of Rome, 1.0 (Beta). *00.03.05.0803 (03/08/1998).*
 - [ ] Rise of Rome, 1.0 (Unused). *00.04.01.0828. (28/08/1998)*
 - [ ] Rise Of Rome, 1.0 (Retail). *00.04.02.0901 (01/09/1998).*
 - [x] Rise Of Rome, 1.0a (Retail). *00.01.06.1115 (01/12/1999).*
 - [x] Age of Kings, 1.0 Beta 1. *00.09.07.0222 (22/02/1999).*
 - [ ] Age of Kings, 1.0 Beta 2. *00.11.23.0622 (22/06/1999).*
 - [ ] Age of Kings, 1.0 Beta 3. *00.11.26.0701 (01/07/1999).*
 - [ ] Age of Kings, 2.0. *00.14.14.0914 (14/09/1999 & 24/08/2001).*
 - [ ] Age of Kings, 2.0 Computer Gaming World Magazine. *00.1?.??.???? (??/??/1999).*
 - [x] Age of Kings, 2.0 Trial. *00.14.19.1018 (18/10/1999).*
 - [ ] Age of Kings, 2.0a. *00.14.22.0712 (28/07/2000 & 25/01/2001).*
 - [ ] Conquerors, 2.1a. *00.07.22.0627 (27/06/2000).*
 - [ ] Conquerors, 2.1b. *00.07.25.0614 (07/07/2000).*
 - [x] Conquerors, 2.1 Demo. *00.07.22.0627 (20/07/2000).*
 - [x] Conquerors, 2.1c (Patch 1.0c). *00.07.26.0809 (09/08/2001).*
 - [ ] Conquerors, User-Patch 1.0.
 - [ ] Conquerors, User-Patch 1.1.
 - [ ] Conquerors, User-Patch 1.2.
 - [ ] Conquerors, User-Patch 1.3.
 - [ ] Conquerors, User-Patch 1.4.
 - [ ] HD Edition, Patch 3.0. *03.00.1521.00 (??/??/2013).*
 - [ ] HD Edition, Patch 3.1. *03.01.????.00 (??/??/2013).*
 - [ ] HD Edition, Patch 3.2. *03.02.1686.00 (??/??/2013).*
 - [ ] HD Edition, Patch 3.3. *03.03.????.00 (??/??/2013).*
 - [ ] HD Edition, Patch 3.4. *03.04.????.00 (??/??/????).*
 - [ ] HD Edition, Patch 3.5. *03.05.2209.00 (??/??/????).*
 - [ ] HD Edition, Patch 3.6. *03.06.2435.00 (??/??/2014).*
 - [ ] HD Edition, Patch 3.7. *03.07.????.00 (??/07/2014).*
 - [ ] HD Edition, Patch 3.8. *03.08.????.00 (??/09/2014).*
 - [ ] HD Edition, Patch 3.9. *03.09.2684.00 (02/04/2015).*
 - [ ] HD Edition, Patch 4.0.
 - [ ] HD Edition, Patch 4.1.
 - [ ] HD Edition, Patch 4.2. *04.02.1748.4400 & 04.02.1748.4401 (??/??/????)*
 - [x] HD Edition, Patch 4.3. *04.03.00.00 (18/08/2015).*
 - [x] Star Wars, Gallactic Battlegrounds.
 - [x] Star Wars, Clones Campaigns.
 - [x] Star Wars, Clones Campaigns, Demo.

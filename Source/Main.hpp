#pragma once

/**
 * @file    Main.hpp
 * @author  Yvan Burrie
 * @date    2018/06/28
 * @version 1.0
 */

#include <stdio.h>
#include <iostream>
#ifdef WINDOWS
#include <io.h>

/* Include Windows components: */
#include <windows.h>
#include <wingdi.h>

/* Include Direct-X components: */
#include <directx.h>
#include <dplay.h>
#include <dplobby.h>
#endif

#include "Compress.h"

#include "IDA.h"

#include "Engine.hpp"

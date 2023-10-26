/*
 * Copyright (C) 2018 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

 /******************************************************************************
 *
 *  Copyright 2022 NXP
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 ******************************************************************************/
#define LOG_TAG "nfc_hidl_hal_test"
#include "common.h"

static int eprom_91_area_default_val[] = 
            { 0x40, 0x03, 0x7D, 0x00, 0x01, 0xA0, 0x0D, 0x78, 0x43, 0x07, 0xE4,
              0x00, 0x00, 0x33, 0xF4, 0x00, 0x00, 0x00, 0x35, 0x3E, 0x89, 0x44,
              0x00, 0x38, 0x20, 0x48, 0x02, 0x00, 0x39, 0xC0, 0x0F, 0x00, 0x00,
              0x3A, 0x39, 0x39, 0xD0, 0x00, 0x36, 0x08, 0x00, 0x00, 0x01, 0x1F,
              0x02, 0x02, 0x0A, 0x00, 0x21, 0x7F, 0x30, 0xBC, 0x09, 0x1D, 0xB0,
              0x00, 0x08, 0x50, 0x23, 0x55, 0x21, 0x08, 0x0C, 0x24, 0x00, 0x00,
              0x00, 0x00, 0x27, 0xFF, 0x3F, 0x00, 0x00, 0x48, 0x00, 0x00, 0x20,
              0x1F, 0x29, 0x3F, 0x20, 0x10, 0x08, 0x2A, 0x08, 0x08, 0x08, 0x00,
              0x2B, 0x38, 0x91, 0x88, 0x00, 0x2C, 0x00, 0x34, 0xE6, 0x00, 0x2D,
              0xA4, 0x24, 0x4D, 0xED, 0x2E, 0xF0, 0xC1, 0xF7, 0xC0, 0x2F, 0xFF,
              0xFF, 0x75, 0x7B, 0x30, 0xAA, 0x51, 0x3F, 0x31, 0x22, 0xAF, 0x60,
              0x8B, 0x4A, 0x37, 0x01, 0x00, 0xE0, 0x1F };

static int size1 = sizeof(eprom_91_area_default_val)/sizeof(eprom_91_area_default_val[0]);

static int eprom_91_area_invalid_val[] =
            { 0x40, 0x03, 0x7D, 0x00, 0x01, 0xA0, 0x0D, 0x78, 0x43, 0x5A, 0xA5,
              0x5A, 0xA5, 0x33, 0x5A, 0xA5, 0x5A, 0xA5, 0x35, 0x5A, 0xA5, 0x5A,
              0xA5, 0x38, 0x5A, 0xA5, 0x5A, 0xA5, 0x39, 0x5A, 0xA5, 0x5A, 0xA5,
              0x3A, 0x5A, 0xA5, 0x5A, 0xA5, 0x36, 0x5A, 0xA5, 0x5A, 0xA5, 0x1F,
              0x5A, 0xA5, 0x5A, 0xA5, 0x21, 0x5A, 0xA5, 0x5A, 0xA5, 0x1D, 0x5A,
              0xA5, 0x5A, 0xA5, 0x23, 0x5A, 0xA5, 0x5A, 0xA5, 0x24, 0x5A, 0xA5,
              0x5A, 0xA5, 0x27, 0x5A, 0xA5, 0x5A, 0xA5, 0x48, 0x5A, 0xA5, 0x5A,
              0xA5, 0x29, 0x5A, 0xA5, 0x5A, 0xA5, 0x2A, 0x5A, 0xA5, 0x5A, 0xA5,
              0x2B, 0x5A, 0xA5, 0x5A, 0xA5, 0x2C, 0x5A, 0xA5, 0x5A, 0xA5, 0x2D,
              0x5A, 0xA5, 0x5A, 0xA5, 0x2E, 0x5A, 0xA5, 0x5A, 0xA5, 0x2F, 0x5A,
              0xA5, 0x5A, 0xA5, 0x30, 0x5A, 0xA5, 0x5A, 0xA5, 0x22, 0x5A, 0xA5,
              0x5A, 0xA5, 0x37, 0x5A, 0xA5, 0x5A, 0xA5 };

static int size2 = sizeof(eprom_91_area_invalid_val)/sizeof(eprom_91_area_invalid_val[0]);

static int eprom_92_area_default_val[] =
            { 0x40 , 0x03 , 0x7D , 0x00 , 0x01 , 0xA0 , 0x0D , 0x78 , 0x43 ,
              0x07 , 0xE4 , 0x00 , 0x00 , 0x33 , 0xF4 , 0x00 , 0x00 , 0x00 ,
              0x35 , 0x3E , 0x89 , 0x44 , 0x00 , 0x38 , 0x20 , 0x48 , 0x02 ,
              0x00 , 0x39 , 0xC0 , 0x0F , 0x00 , 0x00 , 0x3A , 0x39 , 0x39 ,
              0xD0 , 0x00 , 0x36 , 0x08 , 0x00 , 0x00 , 0x01 , 0x1F , 0x48 ,
              0x02 , 0x38 , 0x3E , 0x21 , 0x45 , 0x00 , 0x00 , 0x00 , 0x1D ,
              0xB6 , 0x00 , 0x00 , 0x40 , 0x23 , 0x55 , 0x21 , 0x08 , 0x0C ,
              0x24 , 0x00 , 0x00 , 0x00 , 0x00 , 0x27 , 0xFF , 0x3F , 0x00 ,
              0x00 , 0x48 , 0x00 , 0x00 , 0x20 , 0x1F , 0x29 , 0x8E , 0x61 ,
              0xB0 , 0x01 , 0x2A , 0xCC , 0x85 , 0x0A , 0x00 , 0x2B , 0x38 ,
              0x92 , 0x88 , 0x00 , 0x2C , 0x00 , 0x34 , 0xD2 , 0x00 , 0x2D ,
              0xA4 , 0x64 , 0x4C , 0xED , 0x2E , 0xF0 , 0xC1 , 0xF7 , 0xC0 ,
              0x2F , 0xFF , 0xFF , 0x8F , 0x2A , 0x30 , 0x8A , 0x51 , 0x3F ,
              0x39 , 0x22 , 0x50 , 0x62 , 0x08 , 0x95 , 0x37 , 0x01 , 0x00 ,
              0xE0 , 0x1F };

static int size3 = sizeof(eprom_92_area_default_val)/sizeof(eprom_92_area_default_val[0]);

static int eprom_92_area_invalid_val[] =
            { 0x40, 0x03, 0x7D, 0x00, 0x01, 0xA0, 0x0D, 0x78, 0x43, 0x5A, 0xA5,
              0x5A, 0xA5, 0x33, 0x5A, 0xA5, 0x5A, 0xA5, 0x35, 0x5A, 0xA5, 0x5A,
              0xA5, 0x38, 0x5A, 0xA5, 0x5A, 0xA5, 0x39, 0x5A, 0xA5, 0x5A, 0xA5,
              0x3A, 0x5A, 0xA5, 0x5A, 0xA5, 0x36, 0x5A, 0xA5, 0x5A, 0xA5, 0x1F,
              0x5A, 0xA5, 0x5A, 0xA5, 0x21, 0x5A, 0xA5, 0x5A, 0xA5, 0x1D, 0x5A,
              0xA5, 0x5A, 0xA5, 0x23, 0x5A, 0xA5, 0x5A, 0xA5, 0x24, 0x5A, 0xA5,
              0x5A, 0xA5, 0x27, 0x5A, 0xA5, 0x5A, 0xA5, 0x48, 0x5A, 0xA5, 0x5A,
              0xA5, 0x29, 0x5A, 0xA5, 0x5A, 0xA5, 0x2A, 0x5A, 0xA5, 0x5A, 0xA5,
              0x2B, 0x5A, 0xA5, 0x5A, 0xA5, 0x2C, 0x5A, 0xA5, 0x5A, 0xA5, 0x2D,
              0x5A, 0xA5, 0x5A, 0xA5, 0x2E, 0x5A, 0xA5, 0x5A, 0xA5, 0x2F, 0x5A,
              0xA5, 0x5A, 0xA5, 0x30, 0x5A, 0xA5, 0x5A, 0xA5, 0x22, 0x5A, 0xA5,
              0x5A, 0xA5, 0x37, 0x5A, 0xA5, 0x5A, 0xA5 };

static int size4 = sizeof(eprom_92_area_invalid_val)/sizeof(eprom_92_area_invalid_val[0]);

static uint8_t invalid_91_eeprom_data[][13] =
{
   {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x43, 0x5A, 0xA5, 0x5A, 0xA5},
   {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x33, 0x5A, 0xA5, 0x5A, 0xA5},
   {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x35, 0x5A, 0xA5, 0x5A, 0xA5},
   {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x38, 0x5A, 0xA5, 0x5A, 0xA5},
   {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x39, 0x5A, 0xA5, 0x5A, 0xA5},
   {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x3A, 0x5A, 0xA5, 0x5A, 0xA5},
   {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x36, 0x5A, 0xA5, 0x5A, 0xA5},
   {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x1F, 0x5A, 0xA5, 0x5A, 0xA5},
   {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x21, 0x5A, 0xA5, 0x5A, 0xA5},
   {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x1D, 0x5A, 0xA5, 0x5A, 0xA5},
   {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x23, 0x5A, 0xA5, 0x5A, 0xA5},
   {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x24, 0x5A, 0xA5, 0x5A, 0xA5},
   {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x27, 0x5A, 0xA5, 0x5A, 0xA5},
   {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x48, 0x5A, 0xA5, 0x5A, 0xA5},
   {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x29, 0x5A, 0xA5, 0x5A, 0xA5},
   {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x2A, 0x5A, 0xA5, 0x5A, 0xA5},
   {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x2B, 0x5A, 0xA5, 0x5A, 0xA5},
   {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x2C, 0x5A, 0xA5, 0x5A, 0xA5},
   {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x2D, 0x5A, 0xA5, 0x5A, 0xA5},
   {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x2E, 0x5A, 0xA5, 0x5A, 0xA5},
   {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x2F, 0x5A, 0xA5, 0x5A, 0xA5},
   {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x30, 0x5A, 0xA5, 0x5A, 0xA5},
   {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x22, 0x5A, 0xA5, 0x5A, 0xA5},
   {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x37, 0x5A, 0xA5, 0x5A, 0xA5}
};


static uint8_t no_of_91_invalid_cmd = sizeof(invalid_91_eeprom_data)/sizeof(invalid_91_eeprom_data[0]);
static uint8_t no_of_91_invalid_ele = sizeof(invalid_91_eeprom_data[0])/sizeof(invalid_91_eeprom_data[0][0]);

static uint8_t valid_91_eeprom_data[][13] =
{
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x43, 0x07, 0xE4, 0x00, 0x00},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x33, 0xF4, 0x00, 0x00, 0x00},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x35, 0x3E, 0x89, 0x44, 0x00},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x38, 0x20, 0x48, 0x02, 0x00},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x39, 0xC0, 0x0F, 0x00, 0x00},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x3A, 0x39, 0x39, 0xD0, 0x00},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x36, 0x08, 0x00, 0x00, 0x01},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x1F, 0x02, 0x02, 0x0A, 0x00},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x21, 0x7F, 0x30, 0xBC, 0x09},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x1D, 0xB0, 0x00, 0x08, 0x50},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x23, 0x55, 0x21, 0x08, 0x0C},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x24, 0x00, 0x00, 0x00, 0x00},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x27, 0xFF, 0x3F, 0x00, 0x00},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x48, 0x00, 0x00, 0x20, 0x1F},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x29, 0x3F, 0x20, 0x10, 0x08},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x2A, 0x08, 0x08, 0x08, 0x00},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x2B, 0x38, 0x91, 0x88, 0x00},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x2C, 0x00, 0x34, 0xE6, 0x00},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x2D, 0xA4, 0x24, 0x4D, 0xED},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x2E, 0xF0, 0xC1, 0xF7, 0xC0},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x2F, 0xFF, 0xFF, 0x75, 0x7B},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x30, 0xAA, 0x51, 0x3F, 0x31},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x22, 0xAF, 0x60, 0x8B, 0x4A},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x91, 0x37, 0x01, 0x00, 0xE0, 0x1F}
};

static uint8_t no_of_91_valid_cmd = sizeof(valid_91_eeprom_data)/sizeof(valid_91_eeprom_data[0]);
static uint8_t no_of_91_valid_ele = sizeof(valid_91_eeprom_data[0])/sizeof(valid_91_eeprom_data[0][0]);

static uint8_t invalid_92_eeprom_data[][13] =
{
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x43, 0x5A, 0xA5, 0x5A, 0xA5},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x33, 0x5A, 0xA5, 0x5A, 0xA5},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x35, 0x5A, 0xA5, 0x5A, 0xA5},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x38, 0x5A, 0xA5, 0x5A, 0xA5},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x39, 0x5A, 0xA5, 0x5A, 0xA5},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x3A, 0x5A, 0xA5, 0x5A, 0xA5},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x36, 0x5A, 0xA5, 0x5A, 0xA5},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x1F, 0x5A, 0xA5, 0x5A, 0xA5},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x21, 0x5A, 0xA5, 0x5A, 0xA5},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x1D, 0x5A, 0xA5, 0x5A, 0xA5},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x23, 0x5A, 0xA5, 0x5A, 0xA5},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x24, 0x5A, 0xA5, 0x5A, 0xA5},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x27, 0x5A, 0xA5, 0x5A, 0xA5},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x48, 0x5A, 0xA5, 0x5A, 0xA5},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x29, 0x5A, 0xA5, 0x5A, 0xA5},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x2A, 0x5A, 0xA5, 0x5A, 0xA5},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x2B, 0x5A, 0xA5, 0x5A, 0xA5},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x2C, 0x5A, 0xA5, 0x5A, 0xA5},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x2D, 0x5A, 0xA5, 0x5A, 0xA5},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x2E, 0x5A, 0xA5, 0x5A, 0xA5},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x2F, 0x5A, 0xA5, 0x5A, 0xA5},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x30, 0x5A, 0xA5, 0x5A, 0xA5},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x22, 0x5A, 0xA5, 0x5A, 0xA5},
    {0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x37, 0x5A, 0xA5, 0x5A, 0xA5}
};

static uint8_t no_of_92_invalid_cmd = sizeof(invalid_92_eeprom_data)/sizeof(invalid_92_eeprom_data[0]);
static uint8_t no_of_92_invalid_ele = sizeof(invalid_92_eeprom_data[0])/sizeof(invalid_92_eeprom_data[0][0]);


static uint8_t valid_92_eeprom_data[][13] =
{
    { 0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x43, 0x07, 0xE4, 0x00, 0x00 },
    { 0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x33, 0xF4, 0x00, 0x00, 0x00 },
    { 0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x35, 0x3E, 0x89, 0x44, 0x00 },
    { 0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x38, 0x20, 0x48, 0x02, 0x00 },
    { 0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x39, 0xC0, 0x0F, 0x00, 0x00 },
    { 0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x3A, 0x39, 0x39, 0xD0, 0x00 },
    { 0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x36, 0x08, 0x00, 0x00, 0x01 },
    { 0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x1F, 0x48, 0x02, 0x38, 0x3E },
    { 0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x21, 0x45, 0x00, 0x00, 0x00 },
    { 0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x1D, 0xB6, 0x00, 0x00, 0x40 },
    { 0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x23, 0x55, 0x21, 0x08, 0x0C },
    { 0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x24, 0x00, 0x00, 0x00, 0x00 },
    { 0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x27, 0xFF, 0x3F, 0x00, 0x00 },
    { 0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x48, 0x00, 0x00, 0x20, 0x1F },
    { 0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x29, 0x8E, 0x61, 0xB0, 0x01 },
    { 0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x2A, 0xCC, 0x85, 0x0A, 0x00 },
    { 0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x2B, 0x38, 0x92, 0x88, 0x00 },
    { 0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x2C, 0x00, 0x34, 0xD2, 0x00 },
    { 0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x2D, 0xA4, 0x64, 0x4C, 0xED },
    { 0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x2E, 0xF0, 0xC1, 0xF7, 0xC0 },
    { 0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x2F, 0xFF, 0xFF, 0x8F, 0x2A },
    { 0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x30, 0x8A, 0x51, 0x3F, 0x39 },
    { 0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x22, 0x50, 0x62, 0x08, 0x95 },
    { 0x20, 0x02, 0x0A, 0x01, 0xA0, 0x0D, 0x06, 0x92, 0x37, 0x01, 0x00, 0xE0, 0x1F }
};

static uint8_t no_of_92_valid_cmd = sizeof(valid_92_eeprom_data)/sizeof(valid_92_eeprom_data[0]);
static uint8_t no_of_92_valid_ele = sizeof(valid_92_eeprom_data[0])/sizeof(valid_92_eeprom_data[0][0]);


/*********************************************************************
**       Self TESTS: Read Write test on EE                            **
*********************************************************************/
/*
 * phNci_Write_ReadEE_Test
 * Sends CORE_RESET_CMD_CONFIG_RESET,
 *       CORE_INIT_CMD_NCI20,
 *       NCI_GET_EPROM_91_DATA_CMD,
 *       NCI_SET_INVALID_EMPROM_DATA_CMD_01,
 *       NCI_GET_EPROM_91_DATA_CMD,
 * Waits for respective Response and Notifications. Validate the same.
 *
 */

TEST_P(NfcSelfTestTest, phNci_Write_ReadEE_Test) {
  LOG(INFO) << "Enter phNci_Write_ReadEE_Test :: SetGetProtocol_P003";

  std::vector<uint8_t> core_reset_cmd = CORE_RESET_CMD_CONFIG_RESET;
  std::vector<uint8_t> core_init_cmd = CORE_INIT_CMD_NCI20;
  std::vector<uint8_t> get_eprom_data_cmd = NCI_GET_EPROM_91_DATA_CMD;

  // CORE_RESET_CMD
  NfcData data = core_reset_cmd;
  EXPECT_EQ(data.size(), nfc_->write(data));
  // Wait for CORE_RESET_RSP
  auto res = nfc_cb_->WaitForCallback(kCallbackNameSendData);
  EXPECT_TRUE(res.no_timeout);
  EXPECT_EQ(4ul, res.args->last_data_.size());
  EXPECT_EQ((int)NfcStatus::OK, res.args->last_data_[3]);
  // Wait for CORE_RESET_NTF
  res = nfc_cb_->WaitForCallback(kCallbackNameSendData);
  EXPECT_TRUE(res.no_timeout);
  // Check if reset trigger was due to CORE_RESET_CMD
  EXPECT_LE(8ul, res.args->last_data_.size());
  EXPECT_EQ(2ul, res.args->last_data_[3]);
  EXPECT_GE(1ul, res.args->last_data_[4]);

  // CORE_INIT_CMD_NCI20
  NfcData data1 = core_init_cmd;
  EXPECT_EQ(data1.size(), nfc_->write(data1));
  // Wait for CORE_INIT_RSP_NCI20
  res = nfc_cb_->WaitForCallback(kCallbackNameSendData);
  EXPECT_TRUE(res.no_timeout);
  EXPECT_LE(4ul, res.args->last_data_.size());
  EXPECT_EQ((int)(res.args->last_data_.size() - 3), res.args->last_data_[2]);
  EXPECT_EQ((int)NfcStatus::OK, res.args->last_data_[3]);

  // NCI_GET_EPROM_91_DATA_CMD
  NfcData data4 = get_eprom_data_cmd;
  EXPECT_EQ(data4.size(), nfc_->write(data4));
  // Wait for NCI_GET_EPROM_DATA_RSP
  res = nfc_cb_->WaitForCallback(kCallbackNameSendData);
  EXPECT_TRUE(res.no_timeout);

  /* Check for expected resp */
  for(int i = 0 ; i < size1 ; i++ )
  {
      if(eprom_91_area_default_val[i] != res.args->last_data_[i])
      {
          EXPECT_EQ(eprom_91_area_default_val[i], res.args->last_data_[i]);
          LOG(INFO) << "Error : SetGetProtocol_P003 Failed to get the default value\n";
          break;
      }
  }
  // Setting invalid data at 91 EEPROM
  for(uint8_t num = 0; num < no_of_91_invalid_cmd; num++ )
  {
    NfcData cmd(invalid_91_eeprom_data[num], invalid_91_eeprom_data[num] + no_of_91_invalid_ele );
    EXPECT_EQ(cmd.size(), nfc_->write(cmd));
    // Wait for NCI_SET_INVALID_EMPROM_DATA_RSP_01
    res = nfc_cb_->WaitForCallback(kCallbackNameSendData);
    EXPECT_TRUE(res.no_timeout);
    EXPECT_EQ(5ul, res.args->last_data_.size());
    // RSP must be 0x40 0x02 0x02 0x00 0x00
    EXPECT_EQ((int)0x40, res.args->last_data_[0]);
    EXPECT_EQ((int)0x02, res.args->last_data_[1]);
    EXPECT_EQ((int)0x02, res.args->last_data_[2]);
    EXPECT_EQ((int)0x00, res.args->last_data_[3]);
    EXPECT_EQ((int)0x00, res.args->last_data_[4]);
  }

  // NCI_GET_EPROM_91_DATA_CMD
  NfcData data5 = get_eprom_data_cmd;
  EXPECT_EQ(data5.size(), nfc_->write(data5));
  // Wait for NCI_GET_EPROM_DATA_RSP
  res = nfc_cb_->WaitForCallback(kCallbackNameSendData);
  EXPECT_TRUE(res.no_timeout);

  /* Check for expected resp */
  for(int i = 0 ; i < size2 ; i++ )
  {
      if(eprom_91_area_invalid_val[i] != res.args->last_data_[i])
      {
          EXPECT_EQ(eprom_91_area_invalid_val[i], res.args->last_data_[i]);
          LOG(INFO) << "Error : SetGetProtocol_P003 Failed to get the invalid dump data\n";
          break;
      }
  }

  // Setting valid 92 EEPROM data
  for(uint8_t num = 0; num < no_of_91_valid_cmd; num++ )
  {
    NfcData cmd(valid_91_eeprom_data[num], valid_91_eeprom_data[num] + no_of_91_valid_ele );
    EXPECT_EQ(cmd.size(), nfc_->write(cmd));
    // Wait for NCI_SET_INVALID_EMPROM_DATA_RSP_01
    res = nfc_cb_->WaitForCallback(kCallbackNameSendData);
    EXPECT_TRUE(res.no_timeout);
    EXPECT_EQ(5ul, res.args->last_data_.size());
    // RSP must be 0x40 0x02 0x02 0x00 0x00
    EXPECT_EQ((int)0x40, res.args->last_data_[0]);
    EXPECT_EQ((int)0x02, res.args->last_data_[1]);
    EXPECT_EQ((int)0x02, res.args->last_data_[2]);
    EXPECT_EQ((int)0x00, res.args->last_data_[3]);
    EXPECT_EQ((int)0x00, res.args->last_data_[4]);
  }

  // NCI_GET_EPROM_91_DATA_CMD
  NfcData data6 = get_eprom_data_cmd;
  EXPECT_EQ(data6.size(), nfc_->write(data6));
  // Wait for NCI_GET_EPROM_DATA_RSP
  res = nfc_cb_->WaitForCallback(kCallbackNameSendData);
  EXPECT_TRUE(res.no_timeout);

  /* Check for expected resp */
  for(int i = 0 ; i < size1 ; i++ )
  {
      if(eprom_91_area_default_val[i] != res.args->last_data_[i])
      {
          EXPECT_EQ(eprom_91_area_default_val[i], res.args->last_data_[i]);
          LOG(INFO) << "Error : SetGetProtocol_P003 Failed to get the default value\n";
          break;
      }
  }

  LOG(INFO) << "Exit phNci_Write_ReadEE_Test :: SetGetProtocol_P003";
}


/*********************************************************************
**       Self TESTS: Read Write test on EE                            **
*********************************************************************/
/*
 * phNci_Write_ReadEE_Test2
 * Sends CORE_RESET_CMD_CONFIG_RESET,
 *       CORE_INIT_CMD_NCI20,
 *       NCI_GET_EPROM_92_DATA_CMD
 *       NCI_SET_INVALID_92_EMPROM_DATA_CMD_01,
 *       NCI_GET_EPROM_92_DATA_CMD,
 * Waits for respective Response and Notifications. Validate the same.
 *
 */

TEST_P(NfcSelfTestTest, phNci_Write_ReadEE_Test2) {
  LOG(INFO) << "Enter phNci_Write_ReadEE_Test2 :: SetGetProtocol_P004";
  std::vector<uint8_t> core_reset_cmd = CORE_RESET_CMD_CONFIG_RESET;
  std::vector<uint8_t> core_init_cmd = CORE_INIT_CMD_NCI20;
  std::vector<uint8_t> get_eprom_data_cmd = NCI_GET_EPROM_92_DATA_CMD;

  // CORE_RESET_CMD
  NfcData data = core_reset_cmd;
  EXPECT_EQ(data.size(), nfc_->write(data));
  // Wait for CORE_RESET_RSP
  auto res = nfc_cb_->WaitForCallback(kCallbackNameSendData);
  EXPECT_TRUE(res.no_timeout);
  EXPECT_EQ(4ul, res.args->last_data_.size());
  EXPECT_EQ((int)NfcStatus::OK, res.args->last_data_[3]);
  // Wait for CORE_RESET_NTF
  res = nfc_cb_->WaitForCallback(kCallbackNameSendData);
  EXPECT_TRUE(res.no_timeout);
  // Check if reset trigger was due to CORE_RESET_CMD
  EXPECT_LE(8ul, res.args->last_data_.size());
  EXPECT_EQ(2ul, res.args->last_data_[3]);
  EXPECT_GE(1ul, res.args->last_data_[4]);

  // CORE_INIT_CMD_NCI20
  NfcData data1 = core_init_cmd;
  EXPECT_EQ(data1.size(), nfc_->write(data1));
  // Wait for CORE_INIT_RSP_NCI20
  res = nfc_cb_->WaitForCallback(kCallbackNameSendData);
  EXPECT_TRUE(res.no_timeout);
  EXPECT_LE(4ul, res.args->last_data_.size());
  EXPECT_EQ((int)(res.args->last_data_.size() - 3), res.args->last_data_[2]);
  EXPECT_EQ((int)NfcStatus::OK, res.args->last_data_[3]);

  // NCI_GET_EPROM_92_DATA_CMD
  NfcData data4 = get_eprom_data_cmd;
  EXPECT_EQ(data4.size(), nfc_->write(data4));
  // Wait for NCI_GET_EPROM_92_DATA_RSP
  res = nfc_cb_->WaitForCallback(kCallbackNameSendData);
  EXPECT_TRUE(res.no_timeout);

  /* Check for expected resp */
  for(int i = 0 ; i < size3 ; i++ )
  {
      if(eprom_92_area_default_val[i] != res.args->last_data_[i])
      {
          EXPECT_EQ(eprom_92_area_default_val[i], res.args->last_data_[i]);
          LOG(INFO) << "Error : SetGetProtocol_P004 Failed to get the default value\n";
          break;
      }
  }

  // Setting invalid data at 92 EEPROM
  for(uint8_t num = 0; num < no_of_92_invalid_cmd; num++ )
  {
    NfcData cmd(invalid_92_eeprom_data[num], invalid_92_eeprom_data[num] + no_of_92_invalid_ele );
    EXPECT_EQ(cmd.size(), nfc_->write(cmd));
    // Wait for NCI_SET_INVALID_EMPROM_DATA_RSP_01
    res = nfc_cb_->WaitForCallback(kCallbackNameSendData);
    EXPECT_TRUE(res.no_timeout);
    EXPECT_EQ(5ul, res.args->last_data_.size());
    // RSP must be 0x40 0x02 0x02 0x00 0x00
    EXPECT_EQ((int)0x40, res.args->last_data_[0]);
    EXPECT_EQ((int)0x02, res.args->last_data_[1]);
    EXPECT_EQ((int)0x02, res.args->last_data_[2]);
    EXPECT_EQ((int)0x00, res.args->last_data_[3]);
    EXPECT_EQ((int)0x00, res.args->last_data_[4]);
  }

  // NCI_GET_EPROM_92_DATA_CMD
  NfcData data5 = get_eprom_data_cmd;
  EXPECT_EQ(data5.size(), nfc_->write(data5));
  // Wait for NCI_GET_EPROM_92_DATA_RSP
  res = nfc_cb_->WaitForCallback(kCallbackNameSendData);
  EXPECT_TRUE(res.no_timeout);

  /* Check for expected resp */
  for(int i = 0 ; i < size4 ; i++ )
  {
      if(eprom_92_area_invalid_val[i] != res.args->last_data_[i])
      {
          EXPECT_EQ(eprom_92_area_invalid_val[i], res.args->last_data_[i]);
          LOG(INFO) << "Error : SetGetProtocol_P004 Failed to get the invalid dump data\n";
          break;
      }
  }

  // Setting 92 EEPROM valid data
  for(uint8_t num = 0; num < no_of_92_valid_cmd; num++ )
  {
    NfcData cmd(valid_92_eeprom_data[num], valid_92_eeprom_data[num] + no_of_92_valid_ele );
    EXPECT_EQ(cmd.size(), nfc_->write(cmd));
    // Wait for NCI_SET_INVALID_EMPROM_DATA_RSP_01
    res = nfc_cb_->WaitForCallback(kCallbackNameSendData);
    EXPECT_TRUE(res.no_timeout);
    EXPECT_EQ(5ul, res.args->last_data_.size());
    // RSP must be 0x40 0x02 0x02 0x00 0x00
    EXPECT_EQ((int)0x40, res.args->last_data_[0]);
    EXPECT_EQ((int)0x02, res.args->last_data_[1]);
    EXPECT_EQ((int)0x02, res.args->last_data_[2]);
    EXPECT_EQ((int)0x00, res.args->last_data_[3]);
    EXPECT_EQ((int)0x00, res.args->last_data_[4]);
  }

  // NCI_GET_EPROM_92_DATA_CMD
  NfcData data6 = get_eprom_data_cmd;
  EXPECT_EQ(data6.size(), nfc_->write(data6));
  // Wait for NCI_GET_EPROM_92_DATA_RSP
  res = nfc_cb_->WaitForCallback(kCallbackNameSendData);
  EXPECT_TRUE(res.no_timeout);

  /* Check for expected resp */
  for(int i = 0;i < size3;i++)
  {
      if(eprom_92_area_default_val[i] != res.args->last_data_[i])
      {
          EXPECT_EQ(eprom_92_area_default_val[i], res.args->last_data_[i]);
          LOG(INFO) << "Error : SetGetProtocol_P004 Failed to get the default value\n";
          break;
      }
  }

  LOG(INFO) << "Exit phNci_Write_ReadEE_Test :: SetGetProtocol_P004";
}

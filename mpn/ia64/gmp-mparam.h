/* gmp-mparam.h -- Compiler/machine parameter header file.

Copyright 2000, 2001, 2002, 2003, 2004, 2005, 2009 Free Software Foundation,
Inc.

This file is part of the GNU MP Library.

The GNU MP Library is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or (at your
option) any later version.

The GNU MP Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
License for more details.

You should have received a copy of the GNU Lesser General Public License
along with the GNU MP Library.  If not, see http://www.gnu.org/licenses/.  */

#define GMP_LIMB_BITS 64
#define BYTES_PER_MP_LIMB 8

/* 1300MHz Itanium2 (babe.fsffrance.org) */

/* Generated by tuneup.c, 2009-11-29, gcc 4.2 */

#define MUL_TOOM22_THRESHOLD             44
#define MUL_TOOM33_THRESHOLD             89
#define MUL_TOOM44_THRESHOLD            232

#define SQR_BASECASE_THRESHOLD           26
#define SQR_TOOM2_THRESHOLD             119
#define SQR_TOOM3_THRESHOLD             141
#define SQR_TOOM4_THRESHOLD             284

#define MUL_FFT_TABLE  { 528, 1120, 1856, 3840, 11264, 28672, 114688, 327680, 0 }
#define MUL_FFT_MODF_THRESHOLD          624
#define MUL_FFT_THRESHOLD              7680

#define SQR_FFT_TABLE  { 592, 1248, 2368, 3840, 11264, 28672, 81920, 327680, 0 }
#define SQR_FFT_MODF_THRESHOLD          608
#define SQR_FFT_THRESHOLD              4992

#define MULLOW_BASECASE_THRESHOLD        17
#define MULLOW_DC_THRESHOLD              88
#define MULLOW_MUL_N_THRESHOLD        15280

#define MULMOD_BNM1_THRESHOLD            24

#define DC_DIV_QR_THRESHOLD              64
#define REDC_1_TO_REDC_2_THRESHOLD       10
#define REDC_2_TO_REDC_N_THRESHOLD      172

#define MATRIX22_STRASSEN_THRESHOLD      23
#define HGCD_THRESHOLD                  116
#define GCD_DC_THRESHOLD                501
#define GCDEXT_DC_THRESHOLD             584
#define JACOBI_BASE_METHOD                2

#define MOD_1_NORM_THRESHOLD              0  /* always */
#define MOD_1_UNNORM_THRESHOLD            0  /* always */
#define MOD_1_1_THRESHOLD                 9
#define MOD_1_2_THRESHOLD                10
#define MOD_1_4_THRESHOLD                16
#define USE_PREINV_DIVREM_1               1  /* native */
#define USE_PREINV_MOD_1                  1  /* preinv always */
#define DIVEXACT_1_THRESHOLD              0  /* always (native) */
#define MODEXACT_1_ODD_THRESHOLD          0  /* always */

#define GET_STR_DC_THRESHOLD             15
#define GET_STR_PRECOMPUTE_THRESHOLD     21
#define SET_STR_DC_THRESHOLD           1339
#define SET_STR_PRECOMPUTE_THRESHOLD   3565

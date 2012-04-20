/* mpz_setbit -- set a specified bit.

Copyright 1991, 1993, 1994, 1995, 1997, 1999, 2001, 2002 Free Software
Foundation, Inc.

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

#include "gmp.h"
#include "gmp-impl.h"

void
mpz_setbit (mpz_ptr d, mp_bitcnt_t bit_index)
{
  mp_size_t dsize = SIZ (d);
  mp_ptr dp = PTR (d);
  mp_size_t limb_index;
  mp_limb_t mask;

  limb_index = bit_index / GMP_NUMB_BITS;
  mask = CNST_LIMB(1) << (bit_index % GMP_NUMB_BITS);
  if (dsize >= 0)
    {
      if (limb_index < dsize)
	{
	  dp[limb_index] |= mask;
	}
      else
	{
	  /* Ugh.  The bit should be set outside of the end of the
	     number.  We have to increase the size of the number.  */
	  dp = MPZ_REALLOC (d, limb_index + 1);
	  SIZ (d) = limb_index + 1;
	  MPN_ZERO (dp + dsize, limb_index - dsize);
	  dp[limb_index] = mask;
	}
    }
  else
    {
      mp_size_t zero_bound;

      /* Simulate two's complement arithmetic, i.e. simulate
	 1. Set OP = ~(OP - 1) [with infinitely many leading ones].
	 2. Set the bit.
	 3. Set OP = ~OP + 1.  */

      dsize = -dsize;

      /* No upper bound on this loop, we're sure there's a non-zero limb
	 sooner or later.  */
      zero_bound = 0;
      while (dp[zero_bound] == 0)
	zero_bound++;

      if (limb_index > zero_bound)
	{
	  if (limb_index < dsize)
	    {
	      mp_limb_t	 dlimb;
	      dlimb = dp[limb_index] & ~mask;
	      dp[limb_index] = dlimb;

	      if (UNLIKELY (dlimb == 0 && limb_index == dsize-1))
		{
		  /* high limb became zero, must normalize */
		  do {
		    dsize--;
		  } while (dsize > 0 && dp[dsize-1] == 0);
		  SIZ (d) = -dsize;
		}
	    }
	}
      else if (limb_index == zero_bound)
	{
	  dp[limb_index] = ((dp[limb_index] - 1) & ~mask) + 1;
	  ASSERT (dp[limb_index] != 0);
	}
      else
	{
	  MPN_DECR_U (dp + limb_index, dsize - limb_index, mask);
	  dsize -= dp[dsize - 1] == 0;
	  SIZ (d) = -dsize;
	}
    }
}

/*
Copyright (c) 2010 Alberto Fajardo

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

The tweaks and modifications for Java:
Copyright (c) 2010, Werner Dittmann. 

The same permissions granted.
*/

package org.bouncycastle.crypto.engines;

/*
 * Use the following commad (on Linux for example) to generate the real
 * Java file:
 *    gcc -E Threefish256.java.c | sed -e '/^#/d' > Threefish256.java
 *
 * The mix.h contains Mix and UnMix macros that replace the Mix/UnMix calls
 * below with the real code. This produces unrolled loops. This technique
 * saves a lot of error prone editing.
 * sed just removes some lines that gcc -E inserted.
 */
#include "mix.h"

public class Threefish256 extends ThreefishCipher {

  final int CipherSize = 256;
  final int CipherQwords = CipherSize / 64;
  final int ExpandedKeySize = CipherQwords + 1;

  public Threefish256()
  {
    // Create the expanded key array
    ExpandedKey = new long[ExpandedKeySize];
    ExpandedKey[ExpandedKeySize - 1] = KeyScheduleConst;
  }

  public void Encrypt(long[] input, long[] output)
  {
    // Cache the block, key, and tweak
    long b0 = input[0], b1 = input[1],
      b2 = input[2], b3 = input[3];
    long k0 = ExpandedKey[0], k1 = ExpandedKey[1],
      k2 = ExpandedKey[2], k3 = ExpandedKey[3],
      k4 = ExpandedKey[4];
    long t0 = ExpandedTweak[0], t1 = ExpandedTweak[1],
      t2 = ExpandedTweak[2];

    Mix5( b0,  b1, 14, k0, k1 + t0);
    Mix5( b2,  b3, 16, k2 + t1, k3);
    Mix( b0,  b3, 52);
    Mix( b2,  b1, 57);
    Mix( b0,  b1, 23);
    Mix( b2,  b3, 40);
    Mix( b0,  b3, 5);
    Mix( b2,  b1, 37);
    Mix5( b0,  b1, 25, k1, k2 + t1);
    Mix5( b2,  b3, 33, k3 + t2, k4 + 1);
    Mix( b0,  b3, 46);
    Mix( b2,  b1, 12);
    Mix( b0,  b1, 58);
    Mix( b2,  b3, 22);
    Mix( b0,  b3, 32);
    Mix( b2,  b1, 32);
    Mix5( b0,  b1, 14, k2, k3 + t2);
    Mix5( b2,  b3, 16, k4 + t0, k0 + 2);
    Mix( b0,  b3, 52);
    Mix( b2,  b1, 57);
    Mix( b0,  b1, 23);
    Mix( b2,  b3, 40);
    Mix( b0,  b3, 5);
    Mix( b2,  b1, 37);
    Mix5( b0,  b1, 25, k3, k4 + t0);
    Mix5( b2,  b3, 33, k0 + t1, k1 + 3);
    Mix( b0,  b3, 46);
    Mix( b2,  b1, 12);
    Mix( b0,  b1, 58);
    Mix( b2,  b3, 22);
    Mix( b0,  b3, 32);
    Mix( b2,  b1, 32);
    Mix5( b0,  b1, 14, k4, k0 + t1);
    Mix5( b2,  b3, 16, k1 + t2, k2 + 4);
    Mix( b0,  b3, 52);
    Mix( b2,  b1, 57);
    Mix( b0,  b1, 23);
    Mix( b2,  b3, 40);
    Mix( b0,  b3, 5);
    Mix( b2,  b1, 37);
    Mix5( b0,  b1, 25, k0, k1 + t2);
    Mix5( b2,  b3, 33, k2 + t0, k3 + 5);
    Mix( b0,  b3, 46);
    Mix( b2,  b1, 12);
    Mix( b0,  b1, 58);
    Mix( b2,  b3, 22);
    Mix( b0,  b3, 32);
    Mix( b2,  b1, 32);
    Mix5( b0,  b1, 14, k1, k2 + t0);
    Mix5( b2,  b3, 16, k3 + t1, k4 + 6);
    Mix( b0,  b3, 52);
    Mix( b2,  b1, 57);
    Mix( b0,  b1, 23);
    Mix( b2,  b3, 40);
    Mix( b0,  b3, 5);
    Mix( b2,  b1, 37);
    Mix5( b0,  b1, 25, k2, k3 + t1);
    Mix5( b2,  b3, 33, k4 + t2, k0 + 7);
    Mix( b0,  b3, 46);
    Mix( b2,  b1, 12);
    Mix( b0,  b1, 58);
    Mix( b2,  b3, 22);
    Mix( b0,  b3, 32);
    Mix( b2,  b1, 32);
    Mix5( b0,  b1, 14, k3, k4 + t2);
    Mix5( b2,  b3, 16, k0 + t0, k1 + 8);
    Mix( b0,  b3, 52);
    Mix( b2,  b1, 57);
    Mix( b0,  b1, 23);
    Mix( b2,  b3, 40);
    Mix( b0,  b3, 5);
    Mix( b2,  b1, 37);
    Mix5( b0,  b1, 25, k4, k0 + t0);
    Mix5( b2,  b3, 33, k1 + t1, k2 + 9);
    Mix( b0,  b3, 46);
    Mix( b2,  b1, 12);
    Mix( b0,  b1, 58);
    Mix( b2,  b3, 22);
    Mix( b0,  b3, 32);
    Mix( b2,  b1, 32);
    Mix5( b0,  b1, 14, k0, k1 + t1);
    Mix5( b2,  b3, 16, k2 + t2, k3 + 10);
    Mix( b0,  b3, 52);
    Mix( b2,  b1, 57);
    Mix( b0,  b1, 23);
    Mix( b2,  b3, 40);
    Mix( b0,  b3, 5);
    Mix( b2,  b1, 37);
    Mix5( b0,  b1, 25, k1, k2 + t2);
    Mix5( b2,  b3, 33, k3 + t0, k4 + 11);
    Mix( b0,  b3, 46);
    Mix( b2,  b1, 12);
    Mix( b0,  b1, 58);
    Mix( b2,  b3, 22);
    Mix( b0,  b3, 32);
    Mix( b2,  b1, 32);
    Mix5( b0,  b1, 14, k2, k3 + t0);
    Mix5( b2,  b3, 16, k4 + t1, k0 + 12);
    Mix( b0,  b3, 52);
    Mix( b2,  b1, 57);
    Mix( b0,  b1, 23);
    Mix( b2,  b3, 40);
    Mix( b0,  b3, 5);
    Mix( b2,  b1, 37);
    Mix5( b0,  b1, 25, k3, k4 + t1);
    Mix5( b2,  b3, 33, k0 + t2, k1 + 13);
    Mix( b0,  b3, 46);
    Mix( b2,  b1, 12);
    Mix( b0,  b1, 58);
    Mix( b2,  b3, 22);
    Mix( b0,  b3, 32);
    Mix( b2,  b1, 32);
    Mix5( b0,  b1, 14, k4, k0 + t2);
    Mix5( b2,  b3, 16, k1 + t0, k2 + 14);
    Mix( b0,  b3, 52);
    Mix( b2,  b1, 57);
    Mix( b0,  b1, 23);
    Mix( b2,  b3, 40);
    Mix( b0,  b3, 5);
    Mix( b2,  b1, 37);
    Mix5( b0,  b1, 25, k0, k1 + t0);
    Mix5( b2,  b3, 33, k2 + t1, k3 + 15);
    Mix( b0,  b3, 46);
    Mix( b2,  b1, 12);
    Mix( b0,  b1, 58);
    Mix( b2,  b3, 22);
    Mix( b0,  b3, 32);
    Mix( b2,  b1, 32);
    Mix5( b0,  b1, 14, k1, k2 + t1);
    Mix5( b2,  b3, 16, k3 + t2, k4 + 16);
    Mix( b0,  b3, 52);
    Mix( b2,  b1, 57);
    Mix( b0,  b1, 23);
    Mix( b2,  b3, 40);
    Mix( b0,  b3, 5);
    Mix( b2,  b1, 37);
    Mix5( b0,  b1, 25, k2, k3 + t2);
    Mix5( b2,  b3, 33, k4 + t0, k0 + 17);
    Mix( b0,  b3, 46);
    Mix( b2,  b1, 12);
    Mix( b0,  b1, 58);
    Mix( b2,  b3, 22);
    Mix( b0,  b3, 32);
    Mix( b2,  b1, 32);

    output[0] = b0 + k3;
    output[1] = b1 + k4 + t0;
    output[2] = b2 + k0 + t1;
    output[3] = b3 + k1 + 18;
  }

  public void Decrypt(long[] input, long[] output)
  {
    // Cache the block, key, and tweak
    long b0 = input[0], b1 = input[1],
      b2 = input[2], b3 = input[3];
    long k0 = ExpandedKey[0], k1 = ExpandedKey[1],
      k2 = ExpandedKey[2], k3 = ExpandedKey[3],
      k4 = ExpandedKey[4];
    long t0 = ExpandedTweak[0], t1 = ExpandedTweak[1],
      t2 = ExpandedTweak[2];
    long tmp;

    b0 -= k3;
    b1 -= k4 + t0;
    b2 -= k0 + t1;
    b3 -= k1 + 18;
    UnMix( b0,  b3, 32);
    UnMix( b2,  b1, 32);
    UnMix( b0,  b1, 58);
    UnMix( b2,  b3, 22);
    UnMix( b0,  b3, 46);
    UnMix( b2,  b1, 12);
    UnMix5( b0,  b1, 25, k2, k3 + t2);
    UnMix5( b2,  b3, 33, k4 + t0, k0 + 17);
    UnMix( b0,  b3, 5);
    UnMix( b2,  b1, 37);
    UnMix( b0,  b1, 23);
    UnMix( b2,  b3, 40);
    UnMix( b0,  b3, 52);
    UnMix( b2,  b1, 57);
    UnMix5( b0,  b1, 14, k1, k2 + t1);
    UnMix5( b2,  b3, 16, k3 + t2, k4 + 16);
    UnMix( b0,  b3, 32);
    UnMix( b2,  b1, 32);
    UnMix( b0,  b1, 58);
    UnMix( b2,  b3, 22);
    UnMix( b0,  b3, 46);
    UnMix( b2,  b1, 12);
    UnMix5( b0,  b1, 25, k0, k1 + t0);
    UnMix5( b2,  b3, 33, k2 + t1, k3 + 15);
    UnMix( b0,  b3, 5);
    UnMix( b2,  b1, 37);
    UnMix( b0,  b1, 23);
    UnMix( b2,  b3, 40);
    UnMix( b0,  b3, 52);
    UnMix( b2,  b1, 57);
    UnMix5( b0,  b1, 14, k4, k0 + t2);
    UnMix5( b2,  b3, 16, k1 + t0, k2 + 14);
    UnMix( b0,  b3, 32);
    UnMix( b2,  b1, 32);
    UnMix( b0,  b1, 58);
    UnMix( b2,  b3, 22);
    UnMix( b0,  b3, 46);
    UnMix( b2,  b1, 12);
    UnMix5( b0,  b1, 25, k3, k4 + t1);
    UnMix5( b2,  b3, 33, k0 + t2, k1 + 13);
    UnMix( b0,  b3, 5);
    UnMix( b2,  b1, 37);
    UnMix( b0,  b1, 23);
    UnMix( b2,  b3, 40);
    UnMix( b0,  b3, 52);
    UnMix( b2,  b1, 57);
    UnMix5( b0,  b1, 14, k2, k3 + t0);
    UnMix5( b2,  b3, 16, k4 + t1, k0 + 12);
    UnMix( b0,  b3, 32);
    UnMix( b2,  b1, 32);
    UnMix( b0,  b1, 58);
    UnMix( b2,  b3, 22);
    UnMix( b0,  b3, 46);
    UnMix( b2,  b1, 12);
    UnMix5( b0,  b1, 25, k1, k2 + t2);
    UnMix5( b2,  b3, 33, k3 + t0, k4 + 11);
    UnMix( b0,  b3, 5);
    UnMix( b2,  b1, 37);
    UnMix( b0,  b1, 23);
    UnMix( b2,  b3, 40);
    UnMix( b0,  b3, 52);
    UnMix( b2,  b1, 57);
    UnMix5( b0,  b1, 14, k0, k1 + t1);
    UnMix5( b2,  b3, 16, k2 + t2, k3 + 10);
    UnMix( b0,  b3, 32);
    UnMix( b2,  b1, 32);
    UnMix( b0,  b1, 58);
    UnMix( b2,  b3, 22);
    UnMix( b0,  b3, 46);
    UnMix( b2,  b1, 12);
    UnMix5( b0,  b1, 25, k4, k0 + t0);
    UnMix5( b2,  b3, 33, k1 + t1, k2 + 9);
    UnMix( b0,  b3, 5);
    UnMix( b2,  b1, 37);
    UnMix( b0,  b1, 23);
    UnMix( b2,  b3, 40);
    UnMix( b0,  b3, 52);
    UnMix( b2,  b1, 57);
    UnMix5( b0,  b1, 14, k3, k4 + t2);
    UnMix5( b2,  b3, 16, k0 + t0, k1 + 8);
    UnMix( b0,  b3, 32);
    UnMix( b2,  b1, 32);
    UnMix( b0,  b1, 58);
    UnMix( b2,  b3, 22);
    UnMix( b0,  b3, 46);
    UnMix( b2,  b1, 12);
    UnMix5( b0,  b1, 25, k2, k3 + t1);
    UnMix5( b2,  b3, 33, k4 + t2, k0 + 7);
    UnMix( b0,  b3, 5);
    UnMix( b2,  b1, 37);
    UnMix( b0,  b1, 23);
    UnMix( b2,  b3, 40);
    UnMix( b0,  b3, 52);
    UnMix( b2,  b1, 57);
    UnMix5( b0,  b1, 14, k1, k2 + t0);
    UnMix5( b2,  b3, 16, k3 + t1, k4 + 6);
    UnMix( b0,  b3, 32);
    UnMix( b2,  b1, 32);
    UnMix( b0,  b1, 58);
    UnMix( b2,  b3, 22);
    UnMix( b0,  b3, 46);
    UnMix( b2,  b1, 12);
    UnMix5( b0,  b1, 25, k0, k1 + t2);
    UnMix5( b2,  b3, 33, k2 + t0, k3 + 5);
    UnMix( b0,  b3, 5);
    UnMix( b2,  b1, 37);
    UnMix( b0,  b1, 23);
    UnMix( b2,  b3, 40);
    UnMix( b0,  b3, 52);
    UnMix( b2,  b1, 57);
    UnMix5( b0,  b1, 14, k4, k0 + t1);
    UnMix5( b2,  b3, 16, k1 + t2, k2 + 4);
    UnMix( b0,  b3, 32);
    UnMix( b2,  b1, 32);
    UnMix( b0,  b1, 58);
    UnMix( b2,  b3, 22);
    UnMix( b0,  b3, 46);
    UnMix( b2,  b1, 12);
    UnMix5( b0,  b1, 25, k3, k4 + t0);
    UnMix5( b2,  b3, 33, k0 + t1, k1 + 3);
    UnMix( b0,  b3, 5);
    UnMix( b2,  b1, 37);
    UnMix( b0,  b1, 23);
    UnMix( b2,  b3, 40);
    UnMix( b0,  b3, 52);
    UnMix( b2,  b1, 57);
    UnMix5( b0,  b1, 14, k2, k3 + t2);
    UnMix5( b2,  b3, 16, k4 + t0, k0 + 2);
    UnMix( b0,  b3, 32);
    UnMix( b2,  b1, 32);
    UnMix( b0,  b1, 58);
    UnMix( b2,  b3, 22);
    UnMix( b0,  b3, 46);
    UnMix( b2,  b1, 12);
    UnMix5( b0,  b1, 25, k1, k2 + t1);
    UnMix5( b2,  b3, 33, k3 + t2, k4 + 1);
    UnMix( b0,  b3, 5);
    UnMix( b2,  b1, 37);
    UnMix( b0,  b1, 23);
    UnMix( b2,  b3, 40);
    UnMix( b0,  b3, 52);
    UnMix( b2,  b1, 57);
    UnMix5( b0,  b1, 14, k0, k1 + t0);
    UnMix5( b2,  b3, 16, k2 + t1, k3);

    output[0] = b0;
    output[1] = b1;
    output[2] = b2;
    output[3] = b3;
  }
}


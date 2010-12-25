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
 *    gcc -E Threefish512.java.c | sed -e '/^#/d' > Threefish512.java
 *
 * The mix.h contains Mix and UnMix macros that replace the Mix/UnMix calls
 * below with the real code. This produces unrolled loops. This technique
 * saves a lot of error prone editing.
 * sed just removes some lines that gcc -E inserted.
 */
#include "mix.h"

public class Threefish512  extends ThreefishCipher {

    private final int CipherSize = 512;
    private final int CipherQwords = CipherSize / 64;
    private final int ExpandedKeySize = CipherQwords + 1;

    public Threefish512()
    {
        // Create the expanded key array
        ExpandedKey = new long[ExpandedKeySize];
        ExpandedKey[ExpandedKeySize - 1] = KeyScheduleConst;
    }

    public void Encrypt(long[] input, long[] output)
    {
        // Cache the block, key, and tweak
        long b0 = input[0], b1 = input[1],
        b2 = input[2], b3 = input[3],
        b4 = input[4], b5 = input[5],
        b6 = input[6], b7 = input[7];
        long k0 = ExpandedKey[0], k1 = ExpandedKey[1],
        k2 = ExpandedKey[2], k3 = ExpandedKey[3],
        k4 = ExpandedKey[4], k5 = ExpandedKey[5],
        k6 = ExpandedKey[6], k7 = ExpandedKey[7],
        k8 = ExpandedKey[8];
        long t0 = ExpandedTweak[0], t1 = ExpandedTweak[1],
        t2 = ExpandedTweak[2];

        Mix5( b0,  b1, 46, k0, k1);
        Mix5( b2,  b3, 36, k2, k3);
        Mix5( b4,  b5, 19, k4, k5 + t0);
        Mix5( b6,  b7, 37, k6 + t1, k7);
        Mix( b2,  b1, 33);
        Mix( b4,  b7, 27);
        Mix( b6,  b5, 14);
        Mix( b0,  b3, 42);
        Mix( b4,  b1, 17);
        Mix( b6,  b3, 49);
        Mix( b0,  b5, 36);
        Mix( b2,  b7, 39);
        Mix( b6,  b1, 44);
        Mix( b0,  b7, 9);
        Mix( b2,  b5, 54);
        Mix( b4,  b3, 56);
        Mix5( b0,  b1, 39, k1, k2);
        Mix5( b2,  b3, 30, k3, k4);
        Mix5( b4,  b5, 34, k5, k6 + t1);
        Mix5( b6,  b7, 24, k7 + t2, k8 + 1);
        Mix( b2,  b1, 13);
        Mix( b4,  b7, 50);
        Mix( b6,  b5, 10);
        Mix( b0,  b3, 17);
        Mix( b4,  b1, 25);
        Mix( b6,  b3, 29);
        Mix( b0,  b5, 39);
        Mix( b2,  b7, 43);
        Mix( b6,  b1, 8);
        Mix( b0,  b7, 35);
        Mix( b2,  b5, 56);
        Mix( b4,  b3, 22);
        Mix5( b0,  b1, 46, k2, k3);
        Mix5( b2,  b3, 36, k4, k5);
        Mix5( b4,  b5, 19, k6, k7 + t2);
        Mix5( b6,  b7, 37, k8 + t0, k0 + 2);
        Mix( b2,  b1, 33);
        Mix( b4,  b7, 27);
        Mix( b6,  b5, 14);
        Mix( b0,  b3, 42);
        Mix( b4,  b1, 17);
        Mix( b6,  b3, 49);
        Mix( b0,  b5, 36);
        Mix( b2,  b7, 39);
        Mix( b6,  b1, 44);
        Mix( b0,  b7, 9);
        Mix( b2,  b5, 54);
        Mix( b4,  b3, 56);
        Mix5( b0,  b1, 39, k3, k4);
        Mix5( b2,  b3, 30, k5, k6);
        Mix5( b4,  b5, 34, k7, k8 + t0);
        Mix5( b6,  b7, 24, k0 + t1, k1 + 3);
        Mix( b2,  b1, 13);
        Mix( b4,  b7, 50);
        Mix( b6,  b5, 10);
        Mix( b0,  b3, 17);
        Mix( b4,  b1, 25);
        Mix( b6,  b3, 29);
        Mix( b0,  b5, 39);
        Mix( b2,  b7, 43);
        Mix( b6,  b1, 8);
        Mix( b0,  b7, 35);
        Mix( b2,  b5, 56);
        Mix( b4,  b3, 22);
        Mix5( b0,  b1, 46, k4, k5);
        Mix5( b2,  b3, 36, k6, k7);
        Mix5( b4,  b5, 19, k8, k0 + t1);
        Mix5( b6,  b7, 37, k1 + t2, k2 + 4);
        Mix( b2,  b1, 33);
        Mix( b4,  b7, 27);
        Mix( b6,  b5, 14);
        Mix( b0,  b3, 42);
        Mix( b4,  b1, 17);
        Mix( b6,  b3, 49);
        Mix( b0,  b5, 36);
        Mix( b2,  b7, 39);
        Mix( b6,  b1, 44);
        Mix( b0,  b7, 9);
        Mix( b2,  b5, 54);
        Mix( b4,  b3, 56);
        Mix5( b0,  b1, 39, k5, k6);
        Mix5( b2,  b3, 30, k7, k8);
        Mix5( b4,  b5, 34, k0, k1 + t2);
        Mix5( b6,  b7, 24, k2 + t0, k3 + 5);
        Mix( b2,  b1, 13);
        Mix( b4,  b7, 50);
        Mix( b6,  b5, 10);
        Mix( b0,  b3, 17);
        Mix( b4,  b1, 25);
        Mix( b6,  b3, 29);
        Mix( b0,  b5, 39);
        Mix( b2,  b7, 43);
        Mix( b6,  b1, 8);
        Mix( b0,  b7, 35);
        Mix( b2,  b5, 56);
        Mix( b4,  b3, 22);
        Mix5( b0,  b1, 46, k6, k7);
        Mix5( b2,  b3, 36, k8, k0);
        Mix5( b4,  b5, 19, k1, k2 + t0);
        Mix5( b6,  b7, 37, k3 + t1, k4 + 6);
        Mix( b2,  b1, 33);
        Mix( b4,  b7, 27);
        Mix( b6,  b5, 14);
        Mix( b0,  b3, 42);
        Mix( b4,  b1, 17);
        Mix( b6,  b3, 49);
        Mix( b0,  b5, 36);
        Mix( b2,  b7, 39);
        Mix( b6,  b1, 44);
        Mix( b0,  b7, 9);
        Mix( b2,  b5, 54);
        Mix( b4,  b3, 56);
        Mix5( b0,  b1, 39, k7, k8);
        Mix5( b2,  b3, 30, k0, k1);
        Mix5( b4,  b5, 34, k2, k3 + t1);
        Mix5( b6,  b7, 24, k4 + t2, k5 + 7);
        Mix( b2,  b1, 13);
        Mix( b4,  b7, 50);
        Mix( b6,  b5, 10);
        Mix( b0,  b3, 17);
        Mix( b4,  b1, 25);
        Mix( b6,  b3, 29);
        Mix( b0,  b5, 39);
        Mix( b2,  b7, 43);
        Mix( b6,  b1, 8);
        Mix( b0,  b7, 35);
        Mix( b2,  b5, 56);
        Mix( b4,  b3, 22);
        Mix5( b0,  b1, 46, k8, k0);
        Mix5( b2,  b3, 36, k1, k2);
        Mix5( b4,  b5, 19, k3, k4 + t2);
        Mix5( b6,  b7, 37, k5 + t0, k6 + 8);
        Mix( b2,  b1, 33);
        Mix( b4,  b7, 27);
        Mix( b6,  b5, 14);
        Mix( b0,  b3, 42);
        Mix( b4,  b1, 17);
        Mix( b6,  b3, 49);
        Mix( b0,  b5, 36);
        Mix( b2,  b7, 39);
        Mix( b6,  b1, 44);
        Mix( b0,  b7, 9);
        Mix( b2,  b5, 54);
        Mix( b4,  b3, 56);
        Mix5( b0,  b1, 39, k0, k1);
        Mix5( b2,  b3, 30, k2, k3);
        Mix5( b4,  b5, 34, k4, k5 + t0);
        Mix5( b6,  b7, 24, k6 + t1, k7 + 9);
        Mix( b2,  b1, 13);
        Mix( b4,  b7, 50);
        Mix( b6,  b5, 10);
        Mix( b0,  b3, 17);
        Mix( b4,  b1, 25);
        Mix( b6,  b3, 29);
        Mix( b0,  b5, 39);
        Mix( b2,  b7, 43);
        Mix( b6,  b1, 8);
        Mix( b0,  b7, 35);
        Mix( b2,  b5, 56);
        Mix( b4,  b3, 22);
        Mix5( b0,  b1, 46, k1, k2);
        Mix5( b2,  b3, 36, k3, k4);
        Mix5( b4,  b5, 19, k5, k6 + t1);
        Mix5( b6,  b7, 37, k7 + t2, k8 + 10);
        Mix( b2,  b1, 33);
        Mix( b4,  b7, 27);
        Mix( b6,  b5, 14);
        Mix( b0,  b3, 42);
        Mix( b4,  b1, 17);
        Mix( b6,  b3, 49);
        Mix( b0,  b5, 36);
        Mix( b2,  b7, 39);
        Mix( b6,  b1, 44);
        Mix( b0,  b7, 9);
        Mix( b2,  b5, 54);
        Mix( b4,  b3, 56);
        Mix5( b0,  b1, 39, k2, k3);
        Mix5( b2,  b3, 30, k4, k5);
        Mix5( b4,  b5, 34, k6, k7 + t2);
        Mix5( b6,  b7, 24, k8 + t0, k0 + 11);
        Mix( b2,  b1, 13);
        Mix( b4,  b7, 50);
        Mix( b6,  b5, 10);
        Mix( b0,  b3, 17);
        Mix( b4,  b1, 25);
        Mix( b6,  b3, 29);
        Mix( b0,  b5, 39);
        Mix( b2,  b7, 43);
        Mix( b6,  b1, 8);
        Mix( b0,  b7, 35);
        Mix( b2,  b5, 56);
        Mix( b4,  b3, 22);
        Mix5( b0,  b1, 46, k3, k4);
        Mix5( b2,  b3, 36, k5, k6);
        Mix5( b4,  b5, 19, k7, k8 + t0);
        Mix5( b6,  b7, 37, k0 + t1, k1 + 12);
        Mix( b2,  b1, 33);
        Mix( b4,  b7, 27);
        Mix( b6,  b5, 14);
        Mix( b0,  b3, 42);
        Mix( b4,  b1, 17);
        Mix( b6,  b3, 49);
        Mix( b0,  b5, 36);
        Mix( b2,  b7, 39);
        Mix( b6,  b1, 44);
        Mix( b0,  b7, 9);
        Mix( b2,  b5, 54);
        Mix( b4,  b3, 56);
        Mix5( b0,  b1, 39, k4, k5);
        Mix5( b2,  b3, 30, k6, k7);
        Mix5( b4,  b5, 34, k8, k0 + t1);
        Mix5( b6,  b7, 24, k1 + t2, k2 + 13);
        Mix( b2,  b1, 13);
        Mix( b4,  b7, 50);
        Mix( b6,  b5, 10);
        Mix( b0,  b3, 17);
        Mix( b4,  b1, 25);
        Mix( b6,  b3, 29);
        Mix( b0,  b5, 39);
        Mix( b2,  b7, 43);
        Mix( b6,  b1, 8);
        Mix( b0,  b7, 35);
        Mix( b2,  b5, 56);
        Mix( b4,  b3, 22);
        Mix5( b0,  b1, 46, k5, k6);
        Mix5( b2,  b3, 36, k7, k8);
        Mix5( b4,  b5, 19, k0, k1 + t2);
        Mix5( b6,  b7, 37, k2 + t0, k3 + 14);
        Mix( b2,  b1, 33);
        Mix( b4,  b7, 27);
        Mix( b6,  b5, 14);
        Mix( b0,  b3, 42);
        Mix( b4,  b1, 17);
        Mix( b6,  b3, 49);
        Mix( b0,  b5, 36);
        Mix( b2,  b7, 39);
        Mix( b6,  b1, 44);
        Mix( b0,  b7, 9);
        Mix( b2,  b5, 54);
        Mix( b4,  b3, 56);
        Mix5( b0,  b1, 39, k6, k7);
        Mix5( b2,  b3, 30, k8, k0);
        Mix5( b4,  b5, 34, k1, k2 + t0);
        Mix5( b6,  b7, 24, k3 + t1, k4 + 15);
        Mix( b2,  b1, 13);
        Mix( b4,  b7, 50);
        Mix( b6,  b5, 10);
        Mix( b0,  b3, 17);
        Mix( b4,  b1, 25);
        Mix( b6,  b3, 29);
        Mix( b0,  b5, 39);
        Mix( b2,  b7, 43);
        Mix( b6,  b1, 8);
        Mix( b0,  b7, 35);
        Mix( b2,  b5, 56);
        Mix( b4,  b3, 22);
        Mix5( b0,  b1, 46, k7, k8);
        Mix5( b2,  b3, 36, k0, k1);
        Mix5( b4,  b5, 19, k2, k3 + t1);
        Mix5( b6,  b7, 37, k4 + t2, k5 + 16);
        Mix( b2,  b1, 33);
        Mix( b4,  b7, 27);
        Mix( b6,  b5, 14);
        Mix( b0,  b3, 42);
        Mix( b4,  b1, 17);
        Mix( b6,  b3, 49);
        Mix( b0,  b5, 36);
        Mix( b2,  b7, 39);
        Mix( b6,  b1, 44);
        Mix( b0,  b7, 9);
        Mix( b2,  b5, 54);
        Mix( b4,  b3, 56);
        Mix5( b0,  b1, 39, k8, k0);
        Mix5( b2,  b3, 30, k1, k2);
        Mix5( b4,  b5, 34, k3, k4 + t2);
        Mix5( b6,  b7, 24, k5 + t0, k6 + 17);
        Mix( b2,  b1, 13);
        Mix( b4,  b7, 50);
        Mix( b6,  b5, 10);
        Mix( b0,  b3, 17);
        Mix( b4,  b1, 25);
        Mix( b6,  b3, 29);
        Mix( b0,  b5, 39);
        Mix( b2,  b7, 43);
        Mix( b6,  b1, 8);
        Mix( b0,  b7, 35);
        Mix( b2,  b5, 56);
        Mix( b4,  b3, 22);

        // Final key schedule
        output[0] = b0 + k0;
        output[1] = b1 + k1;
        output[2] = b2 + k2;
        output[3] = b3 + k3;
        output[4] = b4 + k4;
        output[5] = b5 + k5 + t0;
        output[6] = b6 + k6 + t1;
        output[7] = b7 + k7 + 18;
    }

    public void Decrypt(long[] input, long[] output)
    {
        // Cache the block, key, and tweak
        long b0 = input[0], b1 = input[1],
        b2 = input[2], b3 = input[3],
        b4 = input[4], b5 = input[5],
        b6 = input[6], b7 = input[7];
        long k0 = ExpandedKey[0], k1 = ExpandedKey[1],
        k2 = ExpandedKey[2], k3 = ExpandedKey[3],
        k4 = ExpandedKey[4], k5 = ExpandedKey[5],
        k6 = ExpandedKey[6], k7 = ExpandedKey[7],
        k8 = ExpandedKey[8];
        long t0 = ExpandedTweak[0], t1 = ExpandedTweak[1],
        t2 = ExpandedTweak[2];
	long tmp;

        b0 -= k0;
        b1 -= k1;
        b2 -= k2;
        b3 -= k3;
        b4 -= k4;
        b5 -= k5 + t0;
        b6 -= k6 + t1;
        b7 -= k7 + 18;
        UnMix( b4,  b3, 22);
        UnMix( b2,  b5, 56);
        UnMix( b0,  b7, 35);
        UnMix( b6,  b1, 8);
        UnMix( b2,  b7, 43);
        UnMix( b0,  b5, 39);
        UnMix( b6,  b3, 29);
        UnMix( b4,  b1, 25);
        UnMix( b0,  b3, 17);
        UnMix( b6,  b5, 10);
        UnMix( b4,  b7, 50);
        UnMix( b2,  b1, 13);
        UnMix5( b6,  b7, 24, k5 + t0, k6 + 17);
        UnMix5( b4,  b5, 34, k3, k4 + t2);
        UnMix5( b2,  b3, 30, k1, k2);
        UnMix5( b0,  b1, 39, k8, k0);
        UnMix( b4,  b3, 56);
        UnMix( b2,  b5, 54);
        UnMix( b0,  b7, 9);
        UnMix( b6,  b1, 44);
        UnMix( b2,  b7, 39);
        UnMix( b0,  b5, 36);
        UnMix( b6,  b3, 49);
        UnMix( b4,  b1, 17);
        UnMix( b0,  b3, 42);
        UnMix( b6,  b5, 14);
        UnMix( b4,  b7, 27);
        UnMix( b2,  b1, 33);
        UnMix5( b6,  b7, 37, k4 + t2, k5 + 16);
        UnMix5( b4,  b5, 19, k2, k3 + t1);
        UnMix5( b2,  b3, 36, k0, k1);
        UnMix5( b0,  b1, 46, k7, k8);
        UnMix( b4,  b3, 22);
        UnMix( b2,  b5, 56);
        UnMix( b0,  b7, 35);
        UnMix( b6,  b1, 8);
        UnMix( b2,  b7, 43);
        UnMix( b0,  b5, 39);
        UnMix( b6,  b3, 29);
        UnMix( b4,  b1, 25);
        UnMix( b0,  b3, 17);
        UnMix( b6,  b5, 10);
        UnMix( b4,  b7, 50);
        UnMix( b2,  b1, 13);
        UnMix5( b6,  b7, 24, k3 + t1, k4 + 15);
        UnMix5( b4,  b5, 34, k1, k2 + t0);
        UnMix5( b2,  b3, 30, k8, k0);
        UnMix5( b0,  b1, 39, k6, k7);
        UnMix( b4,  b3, 56);
        UnMix( b2,  b5, 54);
        UnMix( b0,  b7, 9);
        UnMix( b6,  b1, 44);
        UnMix( b2,  b7, 39);
        UnMix( b0,  b5, 36);
        UnMix( b6,  b3, 49);
        UnMix( b4,  b1, 17);
        UnMix( b0,  b3, 42);
        UnMix( b6,  b5, 14);
        UnMix( b4,  b7, 27);
        UnMix( b2,  b1, 33);
        UnMix5( b6,  b7, 37, k2 + t0, k3 + 14);
        UnMix5( b4,  b5, 19, k0, k1 + t2);
        UnMix5( b2,  b3, 36, k7, k8);
        UnMix5( b0,  b1, 46, k5, k6);
        UnMix( b4,  b3, 22);
        UnMix( b2,  b5, 56);
        UnMix( b0,  b7, 35);
        UnMix( b6,  b1, 8);
        UnMix( b2,  b7, 43);
        UnMix( b0,  b5, 39);
        UnMix( b6,  b3, 29);
        UnMix( b4,  b1, 25);
        UnMix( b0,  b3, 17);
        UnMix( b6,  b5, 10);
        UnMix( b4,  b7, 50);
        UnMix( b2,  b1, 13);
        UnMix5( b6,  b7, 24, k1 + t2, k2 + 13);
        UnMix5( b4,  b5, 34, k8, k0 + t1);
        UnMix5( b2,  b3, 30, k6, k7);
        UnMix5( b0,  b1, 39, k4, k5);
        UnMix( b4,  b3, 56);
        UnMix( b2,  b5, 54);
        UnMix( b0,  b7, 9);
        UnMix( b6,  b1, 44);
        UnMix( b2,  b7, 39);
        UnMix( b0,  b5, 36);
        UnMix( b6,  b3, 49);
        UnMix( b4,  b1, 17);
        UnMix( b0,  b3, 42);
        UnMix( b6,  b5, 14);
        UnMix( b4,  b7, 27);
        UnMix( b2,  b1, 33);
        UnMix5( b6,  b7, 37, k0 + t1, k1 + 12);
        UnMix5( b4,  b5, 19, k7, k8 + t0);
        UnMix5( b2,  b3, 36, k5, k6);
        UnMix5( b0,  b1, 46, k3, k4);
        UnMix( b4,  b3, 22);
        UnMix( b2,  b5, 56);
        UnMix( b0,  b7, 35);
        UnMix( b6,  b1, 8);
        UnMix( b2,  b7, 43);
        UnMix( b0,  b5, 39);
        UnMix( b6,  b3, 29);
        UnMix( b4,  b1, 25);
        UnMix( b0,  b3, 17);
        UnMix( b6,  b5, 10);
        UnMix( b4,  b7, 50);
        UnMix( b2,  b1, 13);
        UnMix5( b6,  b7, 24, k8 + t0, k0 + 11);
        UnMix5( b4,  b5, 34, k6, k7 + t2);
        UnMix5( b2,  b3, 30, k4, k5);
        UnMix5( b0,  b1, 39, k2, k3);
        UnMix( b4,  b3, 56);
        UnMix( b2,  b5, 54);
        UnMix( b0,  b7, 9);
        UnMix( b6,  b1, 44);
        UnMix( b2,  b7, 39);
        UnMix( b0,  b5, 36);
        UnMix( b6,  b3, 49);
        UnMix( b4,  b1, 17);
        UnMix( b0,  b3, 42);
        UnMix( b6,  b5, 14);
        UnMix( b4,  b7, 27);
        UnMix( b2,  b1, 33);
        UnMix5( b6,  b7, 37, k7 + t2, k8 + 10);
        UnMix5( b4,  b5, 19, k5, k6 + t1);
        UnMix5( b2,  b3, 36, k3, k4);
        UnMix5( b0,  b1, 46, k1, k2);
        UnMix( b4,  b3, 22);
        UnMix( b2,  b5, 56);
        UnMix( b0,  b7, 35);
        UnMix( b6,  b1, 8);
        UnMix( b2,  b7, 43);
        UnMix( b0,  b5, 39);
        UnMix( b6,  b3, 29);
        UnMix( b4,  b1, 25);
        UnMix( b0,  b3, 17);
        UnMix( b6,  b5, 10);
        UnMix( b4,  b7, 50);
        UnMix( b2,  b1, 13);
        UnMix5( b6,  b7, 24, k6 + t1, k7 + 9);
        UnMix5( b4,  b5, 34, k4, k5 + t0);
        UnMix5( b2,  b3, 30, k2, k3);
        UnMix5( b0,  b1, 39, k0, k1);
        UnMix( b4,  b3, 56);
        UnMix( b2,  b5, 54);
        UnMix( b0,  b7, 9);
        UnMix( b6,  b1, 44);
        UnMix( b2,  b7, 39);
        UnMix( b0,  b5, 36);
        UnMix( b6,  b3, 49);
        UnMix( b4,  b1, 17);
        UnMix( b0,  b3, 42);
        UnMix( b6,  b5, 14);
        UnMix( b4,  b7, 27);
        UnMix( b2,  b1, 33);
        UnMix5( b6,  b7, 37, k5 + t0, k6 + 8);
        UnMix5( b4,  b5, 19, k3, k4 + t2);
        UnMix5( b2,  b3, 36, k1, k2);
        UnMix5( b0,  b1, 46, k8, k0);
        UnMix( b4,  b3, 22);
        UnMix( b2,  b5, 56);
        UnMix( b0,  b7, 35);
        UnMix( b6,  b1, 8);
        UnMix( b2,  b7, 43);
        UnMix( b0,  b5, 39);
        UnMix( b6,  b3, 29);
        UnMix( b4,  b1, 25);
        UnMix( b0,  b3, 17);
        UnMix( b6,  b5, 10);
        UnMix( b4,  b7, 50);
        UnMix( b2,  b1, 13);
        UnMix5( b6,  b7, 24, k4 + t2, k5 + 7);
        UnMix5( b4,  b5, 34, k2, k3 + t1);
        UnMix5( b2,  b3, 30, k0, k1);
        UnMix5( b0,  b1, 39, k7, k8);
        UnMix( b4,  b3, 56);
        UnMix( b2,  b5, 54);
        UnMix( b0,  b7, 9);
        UnMix( b6,  b1, 44);
        UnMix( b2,  b7, 39);
        UnMix( b0,  b5, 36);
        UnMix( b6,  b3, 49);
        UnMix( b4,  b1, 17);
        UnMix( b0,  b3, 42);
        UnMix( b6,  b5, 14);
        UnMix( b4,  b7, 27);
        UnMix( b2,  b1, 33);
        UnMix5( b6,  b7, 37, k3 + t1, k4 + 6);
        UnMix5( b4,  b5, 19, k1, k2 + t0);
        UnMix5( b2,  b3, 36, k8, k0);
        UnMix5( b0,  b1, 46, k6, k7);
        UnMix( b4,  b3, 22);
        UnMix( b2,  b5, 56);
        UnMix( b0,  b7, 35);
        UnMix( b6,  b1, 8);
        UnMix( b2,  b7, 43);
        UnMix( b0,  b5, 39);
        UnMix( b6,  b3, 29);
        UnMix( b4,  b1, 25);
        UnMix( b0,  b3, 17);
        UnMix( b6,  b5, 10);
        UnMix( b4,  b7, 50);
        UnMix( b2,  b1, 13);
        UnMix5( b6,  b7, 24, k2 + t0, k3 + 5);
        UnMix5( b4,  b5, 34, k0, k1 + t2);
        UnMix5( b2,  b3, 30, k7, k8);
        UnMix5( b0,  b1, 39, k5, k6);
        UnMix( b4,  b3, 56);
        UnMix( b2,  b5, 54);
        UnMix( b0,  b7, 9);
        UnMix( b6,  b1, 44);
        UnMix( b2,  b7, 39);
        UnMix( b0,  b5, 36);
        UnMix( b6,  b3, 49);
        UnMix( b4,  b1, 17);
        UnMix( b0,  b3, 42);
        UnMix( b6,  b5, 14);
        UnMix( b4,  b7, 27);
        UnMix( b2,  b1, 33);
        UnMix5( b6,  b7, 37, k1 + t2, k2 + 4);
        UnMix5( b4,  b5, 19, k8, k0 + t1);
        UnMix5( b2,  b3, 36, k6, k7);
        UnMix5( b0,  b1, 46, k4, k5);
        UnMix( b4,  b3, 22);
        UnMix( b2,  b5, 56);
        UnMix( b0,  b7, 35);
        UnMix( b6,  b1, 8);
        UnMix( b2,  b7, 43);
        UnMix( b0,  b5, 39);
        UnMix( b6,  b3, 29);
        UnMix( b4,  b1, 25);
        UnMix( b0,  b3, 17);
        UnMix( b6,  b5, 10);
        UnMix( b4,  b7, 50);
        UnMix( b2,  b1, 13);
        UnMix5( b6,  b7, 24, k0 + t1, k1 + 3);
        UnMix5( b4,  b5, 34, k7, k8 + t0);
        UnMix5( b2,  b3, 30, k5, k6);
        UnMix5( b0,  b1, 39, k3, k4);
        UnMix( b4,  b3, 56);
        UnMix( b2,  b5, 54);
        UnMix( b0,  b7, 9);
        UnMix( b6,  b1, 44);
        UnMix( b2,  b7, 39);
        UnMix( b0,  b5, 36);
        UnMix( b6,  b3, 49);
        UnMix( b4,  b1, 17);
        UnMix( b0,  b3, 42);
        UnMix( b6,  b5, 14);
        UnMix( b4,  b7, 27);
        UnMix( b2,  b1, 33);
        UnMix5( b6,  b7, 37, k8 + t0, k0 + 2);
        UnMix5( b4,  b5, 19, k6, k7 + t2);
        UnMix5( b2,  b3, 36, k4, k5);
        UnMix5( b0,  b1, 46, k2, k3);
        UnMix( b4,  b3, 22);
        UnMix( b2,  b5, 56);
        UnMix( b0,  b7, 35);
        UnMix( b6,  b1, 8);
        UnMix( b2,  b7, 43);
        UnMix( b0,  b5, 39);
        UnMix( b6,  b3, 29);
        UnMix( b4,  b1, 25);
        UnMix( b0,  b3, 17);
        UnMix( b6,  b5, 10);
        UnMix( b4,  b7, 50);
        UnMix( b2,  b1, 13);
        UnMix5( b6,  b7, 24, k7 + t2, k8 + 1);
        UnMix5( b4,  b5, 34, k5, k6 + t1);
        UnMix5( b2,  b3, 30, k3, k4);
        UnMix5( b0,  b1, 39, k1, k2);
        UnMix( b4,  b3, 56);
        UnMix( b2,  b5, 54);
        UnMix( b0,  b7, 9);
        UnMix( b6,  b1, 44);
        UnMix( b2,  b7, 39);
        UnMix( b0,  b5, 36);
        UnMix( b6,  b3, 49);
        UnMix( b4,  b1, 17);
        UnMix( b0,  b3, 42);
        UnMix( b6,  b5, 14);
        UnMix( b4,  b7, 27);
        UnMix( b2,  b1, 33);
        UnMix5( b6,  b7, 37, k6 + t1, k7);
        UnMix5( b4,  b5, 19, k4, k5 + t0);
        UnMix5( b2,  b3, 36, k2, k3);
        UnMix5( b0,  b1, 46, k0, k1);

        output[7] = b7;
        output[6] = b6;
        output[5] = b5;
        output[4] = b4;
        output[3] = b3;
        output[2] = b2;
        output[1] = b1;
        output[0] = b0;
    }
}

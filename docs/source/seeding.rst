.. Copyright (c) 2011-2023 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

RNG Seeding
===========

Random number generator seeding is available in two forms: seed values and random number engines.

- Seed values are passed as unsigned integers. For example, to generate a draw from a normal distribution N(1,2) with seed value 1776:

.. code:: cpp

    stats::rnorm(1,2,1776);

- Random engines in StatsLib use the 64-bit Mersenne-Twister generator (``std::mt19937_64``) by default, and are passed by reference. For example:

.. code:: cpp

    std::mt19937_64 engine(1776);
    stats::rnorm(1,2,engine);

Notes:

- To use a different random engine type with StatsLib, define ``STATS_RNG_ENGINE_TYPE`` before including the StatsLib header files. (For example, ``#define STATS_RNG_ENGINE_TYPE std::mt19937_64``.)

- Random number generators should be the preferred option over seed values; passing seed values requires generating a new random engine with each function call, which can be computationally intensive if repeated many times.

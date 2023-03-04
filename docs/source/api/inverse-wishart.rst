.. Copyright (c) 2011-2023 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Inverse-Wishart Distribution
============================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the inverse-Wishart distribution:

.. math::

   f(\mathbf{X}; \boldsymbol{\Psi}, \nu) = \dfrac{|\boldsymbol{\Psi}|^{\frac{\nu}{2}}}{2^{\frac{\nu p}{2}} \Gamma_p\left( \frac{\nu}{2} \right)} | \mathbf{X} |^{-\frac{\nu + p + 1}{2}} \exp \left( - \frac{1}{2} \text{tr} (\boldsymbol{\Psi} \mathbf{X}^{-1}) \right)

where :math:`\Gamma_p` is the Multivariate Gamma function, :math:`| \cdot |` denotes the matrix determinant, and :math:`\text{tr}(\cdot)` denotes the matrix trace.

.. _dinvwish-func-ref1:
.. doxygenfunction:: dinvwish(const mT& X, const mT& Psi_par, const pT nu_par, const bool log_form)
   :project: statslib

----

Random Sampling
---------------

Random sampling for the inverse-Wishart distribution is achieved via the method of Feiveson and Odell (1966).

.. _rinvwish-func-ref1:
.. doxygenfunction:: rinvwish(const mT&, const pT, rand_engine_t&, const bool)
   :project: statslib

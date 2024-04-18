RASPA2/GC-TMMC
======

This is a modified RASPA2 software for transition matrix Monte Carlo simulations in grand canonical ensemble (GC-TMMC). 

GC-TMMC method is based on the computation of the density of states using biased Monte Carlo simulation (with non-Boltzmann distribution). The goal is to sample states characterized by some collective variable with uniform probability to obtain macrostate probabilities. 

Modification of the original code contains introduction of ghost insertion moves (invoked by using the command 'GhostSwapProbability'), which are done in the same way as in classical swap moves, however these moves are never accepted. The unbiased acceptance probabilites of such moves are computed as in GCMC and are accumulated during simulation time using equations:  

```
For insertion:
C(N,N+1)=C(N,N+1)+acc(N→N+1)
C(N,N)=C(N,N)+[1-acc(N→N+1)]

For deletion:
C(N,N-1)=C(N,N-1)+acc(N→N-1)
C(N,N)=C(N,N)+[1-acc(N→N-1)]
```

To calculate density of states at given P and T you have to perform separate simulations for each falue of N ∈ \[0, N<sub>max</sub>\]. See an [example input file](https://github.com/b-mazur/asaf/blob/main/example/raspa_input/MOF-303/simulation.input). 

Current probabilities and potential energy are printed to separate output file. To better understand GC-TMMC method see for example:

* A. Datar, M. Witman, and L. Lin, "Improving Computational Assessment of Porous Materials for Water Adsorption Applications via Flat Histogram Methods", J. Phys. Chem. C 2021, 125, 7, 4253–4266
[link to article](https://doi.org/10.1021/acs.jpcc.0c11082)
* D. W. Siderius and V. K. Shen, "Use of the Grand Canonical Transition-Matrix Monte Carlo Method to Model Gas Adsorption in Porous Materials", J. Phys. Chem. C 2013, 117, 11, 5861–5872
[link to article](https://doi.org/10.1021/jp400480q)

As the code is still being developed unforeseen bugs may occur. 

Installation
============

Installation of this software is done in a similar way to the installation of the original version.

```
rm -rf autom4te.cache  
mkdir m4  
aclocal  
autoreconf -i  
automake --add-missing  
autoconf  

./configure --prefix=${RASPA_DIR}  
# or ./scripts/CompileScript/make-gcc-local  

make  
make install  
```


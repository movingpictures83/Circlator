# Circlator
# Language: C++
# Input: txt
# Output: DIR
# Tested with: PluMA 1.1, GCC 4.8.4
# Dependencies:  circlator 1.5.5

PluMA plugin to circularize a genome using Circlator (Hunt et al, 2015).

The plugin accepts as input a TXT file of keyword, value pairs:
scaffolds: FASTA file of genome scaffolds
reads: FASTA file of all reads, to use for circularizing

All output is sent to the provided output directory


